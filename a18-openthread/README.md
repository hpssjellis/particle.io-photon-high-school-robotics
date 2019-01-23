

OpenThread by Google Nest is the networking protocol the Particle Mesh devices are lossely based on.

Here is what I have found out about OpenThread.

https://github.com/openthread

What to a while to find out:

Openthread makes the firmware using c++ that is installed on devices like the nrf52840 USB Dongle. The two main things to install are the ncp and the cli. See this site https://github.com/makerdiary/nrf52840-mdk-usb-dongle/tree/master/firmware. 

Border Router is the software that runs on a linux, Mac or Raspberry Pi 3B  and helps connect the Thread network to the internet

Wpantund is the software that runs on a linux, Mac or Raspberry Pi 3B which helps connect different nrf52840 USB Dongle's to each other

Spinel seems to be a python program that either makes Drivers or does kind of what wpantund does but in python.

See the folders for morer information.

