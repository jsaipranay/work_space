/*Application for interfacing RTC(DS1308) using I2C*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>


unsigned char bcd2bin (unsigned char bcdByte)                                              
{                                                                               
		return (((bcdByte & 0xF0) >> 4) * 10) + (bcdByte & 0x0F);               
}                                                                               

unsigned char  bin2bcd (unsigned char decimalByte)                                          
{                                                                               
		return (((decimalByte / 10) << 4) | (decimalByte % 10));                
}  


/*get_input():To get the input from the user*/
unsigned char get_input(void)
{
	unsigned char data[4];

	if (fgets(data,sizeof(data),stdin) == NULL) 
	{
		perror("Reading data:\n");
		exit (EXIT_FAILURE);
	}

	return (((char)(atoi(data))));
}

/*read_data():To read the data from the RTC(DS1307) registers*/
void read_data(int fd)
{
	unsigned char read_buff[7];
	int i=0;
	char *am_pm []= { "AM" , "PM"};
	if (-1 == read (fd,read_buff,sizeof(read_buff)))
	{
		perror("Reading:\n");
		exit(EXIT_FAILURE);	
	}

	printf("--------------------------TIME---------------------------\n");
	printf("\t\tSeconds = %d\n",read_buff[0]);
	printf("\t\tMinutes = %d\n",read_buff[1]);
	printf("\t\tHour    = %d\n",read_buff[2]);
	
	printf("--------------------------DATE---------------------------\n");
	printf("\t\tDate    = %d\n",read_buff[4]);
	printf("\t\tMonth   = %d\n",read_buff[5]);
	printf("\t\tYear    = %d\n",read_buff[6]);


	printf("---------------------------------------------------------\n");
	printf("\t\tTime is : %d:%d:%d %s\n",read_buff[2],read_buff[1],read_buff[0],am_pm[read_buff[7]]);
	printf("\t\tDate is : %d/%d/20%d\n",read_buff[4],read_buff[5],read_buff[6]);
	printf("---------------------------------------------------------\n");

}

/*set_data():To write the data(i.e, date and time) to the RTC registers*/
void set_data(int fd)
{
	unsigned char time_buff[10] = {0};
	unsigned char time_period; 
	unsigned char data;
	

	memset(time_buff, '\0', sizeof(time_buff));

	printf ("Enter the hour(12 hour format)\n");
	data = get_input();
	if ((data < 1) || (data > 12)) {
		printf ("Invalid hour format");
		exit (EXIT_FAILURE);
	}
	time_buff[3] = data;
	
	printf ("Enter the mintues\n");
	data = get_input();
	if ((data < 0) || (data > 59)) {
		printf ("Invalid minutes");
		exit (EXIT_FAILURE);
	}
	time_buff[2] = data;
	
	printf ("Enter the seconds :\n");
	data = get_input();
	if ((data < 0) || (data > 59)) {
		printf ("Invalid seconds");
		exit (EXIT_FAILURE);
	}
	time_buff[1] = data;

	printf ("Enter the time period(for AM press 0 / for PM press 1)\n");
	data = get_input();
	if ((data != 0) && (data != 1)){
		printf ("Invalid time format");
		exit (EXIT_FAILURE);
	}

	if (data)
		time_buff[3] = bcd2bin ((bin2bcd (time_buff[3])) | bin2bcd (60));
	else
		time_buff[3] = bcd2bin (((bin2bcd (time_buff[3])) & (~bin2bcd(20))) 	| bin2bcd (40));

	printf ("Enter day of the week:\nSunday-0\nMonday-1\nTuesday-2\nWednesday-3\nThursday-4\nFriday-5\nSaturday-6\n");
        data = get_input();

        if ((data < 1) || (data > 7)) {
           printf ("Invalid day");
           exit (EXIT_FAILURE);
        }
        time_buff[4] = data;
	
	printf ("Enter date of the month:\n");
	data = get_input();

	if ((data < 1) || (data > 31)) {
	   printf ("Invalid date");
	   exit (EXIT_FAILURE);
	}
	time_buff[5] = data;

	printf ("Enter the month:\n");
	data = get_input();

	if ((data < 1) || (data > 12)) {
	   printf ("Invalid month");
	   exit (EXIT_FAILURE);
	}
	time_buff[6] = data ;

	printf ("Enter the year:\n(e.g: 20--");
	data = get_input();

	if ((data < 0) || (data > 99)) {
	   printf ("Invalid year");
	   exit (EXIT_FAILURE);
	}
	time_buff[7] = data;


	if (-1 == write (fd, time_buff, sizeof (time_buff)))
	{
		perror ("write failed");
		exit (EXIT_FAILURE);
	}
	read_data(fd);

}


int main (void)
{
	int fd;
	int choice;
	int i;

	fd = open ("/dev/my_rtc", O_RDWR);
	if (fd < 0) 
	{
		perror ("Open\n");
		exit (EXIT_FAILURE);
	}
	
	else 
		printf ("File opened successfully\n and file descriptor is %d\n", fd);
	
	printf ("Enter the choice:\n"
			"1. read_data \n"
			"2. set_data\n"
			"3. Quit\n");
	
	choice = get_input();

	switch (choice) 
    	{
		
		case 1  :	read_data(fd);
				break;

		case 2  :	set_data(fd);
				break;

		case 3  :	break;

		default :	printf ("Enter valid choice\n");
				break;
	}
	for(i=0;i<10;i++)
	{
		sleep(1);
		read_data(fd);	
	}

	if(close (fd)== -1) 
     	{
		perror ("Close\n");
		exit (EXIT_FAILURE);
	}

	return 0;	
}

