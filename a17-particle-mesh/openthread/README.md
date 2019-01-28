

***OpenThread Installation instructions [here](https://hpssjellis.github.io/particle.io-photon-high-school-robotics/a17-particle-mesh/openthread/install-openthread.html)***


OpenThread by Google Nest is the networking protocol the Particle Mesh devices are loosely based on.
You can purchase the nrf52840 USB Dongle fully installed with the ncp (firmware needed for it to run OpenThreadd) from [seedstudio-nrf52840-mdk-usb-dongle](https://www.robotshop.com/ca/en/seeedstudio-nrf52840-mdk-usb-dongle.html) 

and the firmware for these dongles if you brick them is at https://github.com/makerdiary/nrf52840-mdk-usb-dongle/tree/master/firmware

**Here is what I have found out about OpenThread.**

The Github is at: https://github.com/openthread

What took a while to find out:

[Openthread](https://github.com/openthread/openthread) makes the firmware using c++ that is installed on devices like the nrf52840 USB Dongle. The two main things to install are the ncp and the cli. See this site https://github.com/makerdiary/nrf52840-mdk-usb-dongle/tree/master/firmware. 

[Border Router](https://github.com/openthread/borderrouter) is the software that runs on a linux, Mac or Raspberry Pi 3B  and helps connect the Thread network to the internet

[Wpantund](https://github.com/openthread/wpantund) is the software that runs on a linux, Mac or Raspberry Pi 3B which helps connect different nrf52840 USB Dongle's to each other

[PySpinel](https://github.com/openthread/pyspinel) seems to be a python program that either makes Drivers or does kind of what wpantund does but in python.

You will also need [nrf-Connect for desktop](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Connect-for-desktop) (Look for the pull down on the right that says "platform" looks like an Ad.) for windows, Linux or Mac to transfer the openthread .hex files to your nrf52840 usb dongle

You might need for more advanced programming [nrfutil]() For windows grab the top laatest release from https://github.com/NordicSemiconductor/pc-nrfutil/releases 


**Tutorials about openthread**

https://wiki.makerdiary.com/nrf52840-mdk-usb-dongle/OTBR/  

https://codelabs.developers.google.com/codelabs/openthread-hardware/#0

https://openthread.io/guides/border-router


**Installing all of them on 64 bit Linux (I am using Ubuntu 18.04)**

Follow this link [https://hpssjellis.github.io/particle.io-photon-high-school-robotics/a17-particle-mesh/openthread/install-openthread.html](https://hpssjellis.github.io/particle.io-photon-high-school-robotics/a17-particle-mesh/openthread/install-openthread.html)



```
