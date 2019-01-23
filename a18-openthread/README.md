

OpenThread by Google Nest is the networking protocol the Particle Mesh devices are lossely based on.
You can purchase the nrf52840 USB Dongle fully installed wiht the ncp from [seedstudio-nrf52840-mdk-usb-dongle](https://www.robotshop.com/ca/en/seeedstudio-nrf52840-mdk-usb-dongle.html) 

Here is what I have found out about OpenThread.

The Github is at: https://github.com/openthread

What took a while to find out:

[Openthread](https://github.com/openthread/openthread) makes the firmware using c++ that is installed on devices like the nrf52840 USB Dongle. The two main things to install are the ncp and the cli. See this site https://github.com/makerdiary/nrf52840-mdk-usb-dongle/tree/master/firmware. 

[Border Router](https://github.com/openthread/borderrouter) is the software that runs on a linux, Mac or Raspberry Pi 3B  and helps connect the Thread network to the internet

[Wpantund](https://github.com/openthread/wpantund) is the software that runs on a linux, Mac or Raspberry Pi 3B which helps connect different nrf52840 USB Dongle's to each other

[PySpinel](https://github.com/openthread/pyspinel) seems to be a python program that either makes Drivers or does kind of what wpantund does but in python.


Tutorials about the above:

https://wiki.makerdiary.com/nrf52840-mdk-usb-dongle/OTBR/  

https://codelabs.developers.google.com/codelabs/openthread-hardware/#0

https://openthread.io/guides/border-router



See this githubs folders for more information.

