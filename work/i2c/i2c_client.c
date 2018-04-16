/*
 *i2c_client program
 */
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/types.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/i2c.h>
#include<linux/bcd.h>
#include<asm/uaccess.h>
#include<linux/sched.h>
#include<linux/slab.h>
#include <linux/uaccess.h>

#define RTC_SECONDS_REG 0x00
#define RTC_BIT_CH	0x80
#define RTC_MINUTES_REG 0x01
#define RTC_HOURS_REG   0x02
#define RTC_WDAY_REG    0x03
#define RTC_MDAY_REG    0x04
#define RTC_MONTH_REG   0x05
#define RTC_YEAR_REG    0x06
#define RTC_CONTROL_REG 0x07

/*
 *Time structure
 */

struct time
{
	unsigned char second;
	unsigned char minute;
	unsigned char hour;
	unsigned char day;
	unsigned char date;
	unsigned char month;
	unsigned char year;
};

/*
 *my structure
 */
struct my_rtc{
	struct i2c_client * client;
	unsigned int addr;
	unsigned int buf[8];
	struct time rtc_time;
}my_rtc;


/*Initialization functions*/
static int myInit(void);
static void myExit(void);
static void my_setup(void);

int my_probe(struct i2c_client *, const struct i2c_device_id *);
int my_remove(struct i2c_client *);

int my_open(struct inode* , struct file*);
int my_release(struct inode* , struct file*);
ssize_t my_read(struct file * , char __user*, size_t,loff_t *);
ssize_t my_write(struct file * , const char __user*,size_t,loff_t *);

/*Global variables*/
static char* devname = "my_rtc";
static unsigned int count = 1;
static unsigned int first_minor = 0;
static dev_t dev;
static struct cdev* my_cdev;
static struct class * my_class;
static struct device * my_device;

/*File operations*/
struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_open,
	.release = my_release,
	.write = my_write,
	.read = my_read,
};

static const struct i2c_device_id my_id[] = {
	{"my_rtc",0},
	{}
};

MODULE_DEVICE_TABLE(i2c ,my_id);

/*i2c-driver structure*/
static struct i2c_driver my_i2c_driver = {
	.driver = {
			.name = "my_rtc",
			.owner = THIS_MODULE,
		},
	.probe = my_probe,
	.remove = my_remove,
	.id_table = my_id,
};


/*
 *my_open function
 */
int my_open(struct inode* my_inode,struct file* filep)
{
	printk(KERN_INFO "In open function\n");
	printk(KERN_INFO "File opened successfully\n");

	return 0;
}


/*
 *my_release function
 */
int my_release(struct inode* my_inode,struct file* filep)
{
	printk(KERN_INFO "In closing function\n");
	return 0;
}


/*
 *my_read function
 */

ssize_t my_read(struct file * filep,char __user *buf,size_t count,loff_t *f_pos)
{

	unsigned char read_buf[9];
	unsigned char copy_buf[9];
	struct i2c_msg my_msg[2];
        unsigned char offset = 0x00;
	int tmp;
	char * day[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturaday"};
	char *am_pm[]  = { "AM", "PM"};

	printk(KERN_INFO "In read function");
	my_msg[0].addr = my_rtc.addr;
	my_msg[0].flags = 0;
	my_msg[0].buf = &offset;
	my_msg[0].len = 1;

	
	my_msg[1].addr = my_rtc.addr;
        my_msg[1].flags = I2C_M_RD;
        my_msg[1].buf = read_buf;
	my_msg[1].len = 7;
	
	tmp = i2c_transfer((my_rtc.client)->adapter,my_msg,2);
	if(tmp < 0)
	{
		pr_debug("read error %d\n",tmp);
	}

	my_rtc.rtc_time.second = bcd2bin(read_buf[RTC_SECONDS_REG] & 0x7f);
	my_rtc.rtc_time.minute = bcd2bin(read_buf[RTC_MINUTES_REG] & 0x7f);
	my_rtc.rtc_time.hour   = bcd2bin(read_buf[RTC_HOURS_REG]& 0x1f);
	my_rtc.rtc_time.day    = bcd2bin(read_buf[RTC_WDAY_REG]&0x07);
	my_rtc.rtc_time.date   = bcd2bin(read_buf[RTC_MDAY_REG]& 0x3F);
	my_rtc.rtc_time.month  = bcd2bin(read_buf[RTC_MONTH_REG] & 0x1F);
        my_rtc.rtc_time.year   = bcd2bin(read_buf[RTC_YEAR_REG]);

	copy_buf[0] = bcd2bin(read_buf[RTC_SECONDS_REG] & 0x7f);
        copy_buf[1] = bcd2bin(read_buf[RTC_MINUTES_REG] & 0x7f);
        copy_buf[2] = bcd2bin(read_buf[RTC_HOURS_REG]& 0x1f);
        copy_buf[3] = bcd2bin(read_buf[RTC_WDAY_REG]&0x07);
        copy_buf[4] = bcd2bin(read_buf[RTC_MDAY_REG]& 0x3F);
        copy_buf[5] = bcd2bin(read_buf[RTC_MONTH_REG] & 0x1F);
        copy_buf[6] = bcd2bin(read_buf[RTC_YEAR_REG]);
        copy_buf[7] = (read_buf[RTC_HOURS_REG]>>5)&1;


	printk(KERN_INFO "Seconds = %d",my_rtc.rtc_time.second);
	printk(KERN_INFO "Minutes = %d",my_rtc.rtc_time.minute);	
	printk(KERN_INFO "Hour = %d",my_rtc.rtc_time.hour);
	printk(KERN_INFO "Day  = %s",day[my_rtc.rtc_time.day]);
	printk(KERN_INFO "Date = %d",my_rtc.rtc_time.date);
	printk(KERN_INFO "Month = %d",my_rtc.rtc_time.month);
	printk(KERN_INFO "Year = %d",my_rtc.rtc_time.year);

	if(copy_to_user(buf,copy_buf,8))
		printk(KERN_INFO "Copy to user failed\n");
	else	
		printk(KERN_INFO "Copy to user success\n");
	
	printk(KERN_INFO "----------------------\n\n");
	printk(KERN_INFO "Time is : %d:%d:%d %s\n",my_rtc.rtc_time.hour,my_rtc.rtc_time.minute,my_rtc.rtc_time.second,am_pm[(read_buf[RTC_HOURS_REG] >> 5)& 1]);
	printk(KERN_INFO "Date is :%s %d/%d/20%d\n",day[my_rtc.rtc_time.day],my_rtc.rtc_time.date,my_rtc.rtc_time.month,my_rtc.rtc_time.year);
	
	return 0;

}

ssize_t my_write (struct file *filp, const char __user *buf, size_t count, 
				loff_t *f_pos)
{
	struct i2c_msg my_msg[2];
	struct i2c_msg my_msg1;
	static unsigned char my_buff[8];

        unsigned char offset = 0x00;
	int tmp;
	int i ;
	int ret;


	printk(KERN_INFO "In write function\n");
	my_msg[0].addr = my_rtc.addr;
	my_msg[0].flags = 0;
	my_msg[0].buf = &offset;
	my_msg[0].len = 1;

	
	my_msg[1].addr = my_rtc.addr;
     	my_msg[1].flags = I2C_M_RD;
     	my_msg[1].buf = my_buff;
	my_msg[1].len = 7;
	
	tmp = i2c_transfer((my_rtc.client)->adapter,my_msg,2);
	if(tmp < 0)
	{
		pr_debug("read error %d\n",tmp);
	}

		printk (KERN_ERR "after i2c transfer\n");          
     
	/*To test the values*/
//	printk(KERN_INFO "%d %d %d\n",buf[0],buf[1],buf[2]);

	for (i = 0 ; i <= 7; i++)
		my_buff[i] = bin2bcd(buf[i]);

	my_msg1.addr= my_rtc.addr;
	my_msg1.flags = 0;
	my_msg1.len = 8;
	my_msg1.buf = my_buff;
		
	if ((ret = (i2c_transfer (((my_rtc.client) -> adapter),&my_msg1, 1))) < 0) {                 
		printk (KERN_ERR "i2c_test: i2c_transfer failed = %d\n", ret);          
		return ret;
	}   
	return 0;
}


void my_setup()
{
	unsigned char buff[9];
	unsigned char offset = 0x00;
	struct i2c_msg my_msg[2];
	struct i2c_msg my_msg1;
	int tmp;
	
	printk(KERN_INFO "In setup function\n");	
	
	my_msg[0].addr = my_rtc.addr;
	my_msg[0].flags = 0;
	my_msg[0].buf = &offset;
	my_msg[0].len = 1;

	
	my_msg[1].addr = my_rtc.addr;
        my_msg[1].flags = I2C_M_RD;
        my_msg[1].buf = buff;
	my_msg[1].len = 8;
	
	tmp = i2c_transfer((my_rtc.client)->adapter,my_msg,2);
	if(tmp < 0)
	{
		pr_debug("read error %d\n",tmp);
	}


	buff[RTC_SECONDS_REG ] 		 =  RTC_SECONDS_REG;
	buff[RTC_SECONDS_REG + 1] 	&=  0x7F;
	buff[RTC_MINUTES_REG + 1] 	&=  0x7F;
	buff[RTC_HOURS_REG + 1] 	|=  0x40;
	buff[RTC_WDAY_REG + 1]	 	&=  0x07;
	buff[RTC_MDAY_REG + 1]	 	&=  0x3F;
	buff[RTC_MONTH_REG + 1] 	&=  0x1F;
	buff[RTC_YEAR_REG + 1] 		&=  0xFF;
	buff[RTC_CONTROL_REG + 1] 	=   0x10;

	my_msg1.addr = my_rtc.addr;
	my_msg1.flags = 0;
	my_msg1.buf = buff;
	my_msg1.len = 9;

	tmp = i2c_transfer((my_rtc.client)->adapter,&my_msg1,1);
	if(tmp < 0)
	{
		pr_debug("write error %d\n",tmp);
	}
	
	
	printk(KERN_INFO "Exiting setup function\n");	
	
	
}

/*
 *Probe function
 */
int my_probe(struct i2c_client * my_client,const struct i2c_device_id * my_id)
{
//	struct my_rtc *my_rtc;
	int status;

	printk(KERN_INFO "In probe function\n");
	status = alloc_chrdev_region(&dev,first_minor,count,devname);

	if(status < 0)
	{
		printk(KERN_ERR "Allocation failed\n");	

	}

	printk(KERN_INFO "Allocated major number is : %d\n", MAJOR(dev));
	printk(KERN_INFO "Allocated minor number is : %d\n", MINOR(dev));
	
	my_cdev = cdev_alloc();
	if(my_cdev == NULL)
	{
		printk(KERN_ERR "cdev_alloc failed\n");
	}	
	
	cdev_init(my_cdev,&fops);
	my_cdev->owner = THIS_MODULE;

	status = cdev_add(my_cdev,dev,count);
	if(status)
	{
		printk(KERN_ERR "cdev add failed\n");
	}

	my_class = class_create(THIS_MODULE,devname);
	if(IS_ERR(my_class))
	{
		printk(KERN_ERR "class create failed\n");
	}
	
	my_device = device_create(my_class , NULL , dev, NULL,devname);
	if(IS_ERR(my_device))
        {
                printk(KERN_ERR "device create failed\n");
        }


	my_rtc.client = my_client;

	my_rtc.addr =my_client->addr;

	printk("client device name = %s\n",my_client->name);
	printk("client device address = 0x%x\n",my_client->addr);

	if(!i2c_check_functionality(my_client->adapter,I2C_FUNC_I2C | I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
	{
		printk(KERN_ERR "i2c_check_functionality failed\n");
	}

	status = i2c_smbus_write_byte_data(my_client, RTC_SECONDS_REG, 0);
	if(status == 0)
	{
		printk(KERN_INFO "Clock is ticking\n");
	}

	
	my_setup();
	
	printk(KERN_INFO "Exiting probe function");
	return 0;
	
}

/*
 *remove function
 */
int my_remove(struct i2c_client * my_client)
{
	class_destroy(my_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(dev,count);
	printk(KERN_INFO "In the remove function");
	return 0;
}


/*
 *Init module
 */

static int __init myInit(void)
{
	printk(KERN_INFO "In init function");
	return i2c_add_driver(&my_i2c_driver);
}


/*
 *Cleanup module
 */

static void __exit myExit(void)
{
	printk(KERN_INFO "In exit function");
	i2c_del_driver(&my_i2c_driver);
}

module_init(myInit);
module_exit(myExit);


MODULE_AUTHOR("prasanna kumar");
MODULE_DESCRIPTION("i2c client driver");
MODULE_LICENSE("GPL");
MODULE_INFO(intree, "Y");
