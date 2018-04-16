download the source code:


Flashing Images to 820:
adb devices (will detect the android devices)
adb reboot bootloader  (getting into fastboot mode)
fastboot devices (to check the device is in fastboot mode) 
fastboot flash boot boot.img
fastboot flash userdata userdata.img
fastboot flash cache cache.img
fastboot flash recovery recovery.img
fastboot flash persist persist.img
fastboot flash system system.img
fastboot reboot

go to the directory


1.make clean

2.source build/envsetuo.sh(set the environmental set up)

3.lunch

4.msm 8916-64-user debug

5.select the board no 24.

6.make -j16


if it compiled ok tje if it get any jack server error go with


For building android source code

1. javac -version
2. sudo mv java-8-openjdk-amd64 /usr/lib/jvm/
3. cd /usr/lib/jvm/
4. ls
5. cd  java-8-openjdk-amd64
6. pwd
7. sudo update-alternatives –install “/usr/bin/java” “java” “/usr/lib/jvm/ java-8-openjdk- amd64/bin/java” 1
8. sudo update-alternatives –install “/usr/bin/java” “java” “/usr/lib/jvm/ java-8-openjdk- amd64/bin/javac” 1
9. sudo update-alternatives –config java
10. sudo update-alternatives –config javac
11. javac -version
12. pwd
13. echo $JAVA_HOME
14. export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64

15. next refer to source.android.com
16. if you got out of memory error then
	in home directory
	cd .jack-server
	vi config.properties
	# 
	#Sat Jun 18 15:53:49 EDT 2016 
	jack.server.max-jars-size=104857600 
	jack.server.max-service=N 
	jack.server.service.port=8072 
	jack.server.max-service.by-mem=1\=2147483648\:2\=3221225472\:3\=4294967296 
	jack.server.admin.port=8073 
	jack.server.config.version=2 
	jack.server.time-out=ZZ 
	
	cd ..
	vi .jack-settings
	# Server settings 
	SERVER=true 
	SERVER_HOST=127.0.0.1 
	SERVER_PORT_SERVICE=8072 
	SERVER_PORT_ADMIN=8073 
	SERVER_NB_COMPILE=1 
	# Internal, do not touch 
	SETTING_VERSION=4 

17. killing jack server
	prebuilts/sdk/tools/ack-admin kill-server
18. starting jack server
	prebuilts/sdk/tools/ack-admin start-server
19. setting $PATH
	export JACK_SERVER_VM_ARGUMENTS=”-Dfile.encoding=UTF-8 XX:+TieredCompilation -Xmx6g” 

20. then set environment veriable
	source build/envsetup.h

	lunch   select option 21
21. make -j8
		
	
