just trying the codelab and including the files here if they actually work. Only trying to get the credentials set. nothing else






## Got main-for-cli.c working but not yet working is main-for-ncp.c 


Got main.c for ncp working by making this change to the makefile-nrf52840

```
#configure_OPTIONS              += --enable-radio-only

```


https://codelabs.developers.google.com/codelabs/openthread-apis/#0

The default-hex folder has pure unchanged openthread nrf52840 files to flash to the usb dongle.

If those work I will then try to make a hard coded setting of the dtaset credentials.


The my-default-hex folder uses my over the top make command

```
        make -f examples/Makefile-nrf52840 USB=1 BOOTLOADER=1 BORDER_AGENT=1 BORDER_ROUTER=1 COMMISSIONER=1 JOINER=1 UDP_PROXY=1 CFLAGS+=-UCONFIG_GPIO_AS_PINRESET 

```



