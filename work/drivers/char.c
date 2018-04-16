module_init(mydev_init) and module_exit(mydev_cleanup):

mydev_init:
**********
devno=mkdev(major,minor);
register your driver:

res=register_chardev_region(devno,mydev_no devices,mydev_name);
or alloc_chardev_region(&devno,0,no of devices,"name");

1.

return value or /proc/devices-->used to see registerd sucessfully or not.
after reistrtion initialise with hardwrae



request_region() 


************************
