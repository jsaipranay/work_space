obj-m:=i2c_client.o

#KDIR:=/home/prasannakumar/bbb_new/linux-4.14.24
#CROSS_COMPILE=/home/prasannakumar/cross_compiler_tools/bin/arm-linux-gnueabihf-
KDIR:=/home/juluri/linux
#CROSS_COMPIL=/home/juluri/tools/arm-linux-gnueabihf-
#KDIR:=/home/venkata/raspi/linux
#ARCH=arm

PWD:=$(shell pwd)
#PWD:=$(shell pwd)
#all:
#	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE)  -C $(KDIR) M=$(PWD) modules

all:
	$(MAKE) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_kmod
