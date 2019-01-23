

OpenThread by Google Nest is the networking protocol the Particle Mesh devices are lossely based on.
You can purchase the nrf52840 USB Dongle fully installed wiht the ncp from [seedstudio-nrf52840-mdk-usb-dongle](https://www.robotshop.com/ca/en/seeedstudio-nrf52840-mdk-usb-dongle.html) 

**Here is what I have found out about OpenThread.**

The Github is at: https://github.com/openthread

What took a while to find out:

[Openthread](https://github.com/openthread/openthread) makes the firmware using c++ that is installed on devices like the nrf52840 USB Dongle. The two main things to install are the ncp and the cli. See this site https://github.com/makerdiary/nrf52840-mdk-usb-dongle/tree/master/firmware. 

[Border Router](https://github.com/openthread/borderrouter) is the software that runs on a linux, Mac or Raspberry Pi 3B  and helps connect the Thread network to the internet

[Wpantund](https://github.com/openthread/wpantund) is the software that runs on a linux, Mac or Raspberry Pi 3B which helps connect different nrf52840 USB Dongle's to each other

[PySpinel](https://github.com/openthread/pyspinel) seems to be a python program that either makes Drivers or does kind of what wpantund does but in python.

You will also need [nrf-Conect for desktop](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Connect-for-desktop) (Look for the pull down on the right that says "platform" looks like an Ad.) for windows, Linux or Mac to transfer the openthread .hex files to your nrf52840 usb dongle

You might need for more advanced programming [nrfutil]() For windows grab the top laatest release from https://github.com/NordicSemiconductor/pc-nrfutil/releases 


**Tutorials about openthread**

https://wiki.makerdiary.com/nrf52840-mdk-usb-dongle/OTBR/  

https://codelabs.developers.google.com/codelabs/openthread-hardware/#0

https://openthread.io/guides/border-router


**Installing all of them on 64 bit Linux (I am using Ubuntu 18.04)**

(If you know how to do things in other ways, such as making new directories then do what you know)

```bash
cd ~  

mkdir openthread-everything

cd openthread-everything

git clone https://github.com/openthread/openthread.git

git clone https://github.com/openthread/borderrouter.git

git clone https://github.com/openthread/wpantund.git

git clone https://github.com/openthread/pyspinel.git


// Let install wpantund first
cd wpantund



// Lets install the Border Router. Note: This program automatically starts after being rebooted.
cd ~/openthread
cd borderrouter
./script/bootstrap
./script/setup

// plug in your nrf52840 usb dongle
ls /dev/tty*
ls /dev/ttyA*    // should show ttyACM0  or ttyACM1 etc

find -iname wpantund.conf   // should be in /etc/wpantund.conf
sudo nano /etc/wpantund.conf   // edit Config:NCP:SocketPath "/dev/ttyACM0"
^x      // to exit and save the file







```
