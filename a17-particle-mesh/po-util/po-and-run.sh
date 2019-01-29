sudo apt install curl
bash <(curl -sL get.po-util.com)

po init argon myProjectName
cd myProjectName


## monolithic Build of Mesh Devices (full load of firmware to device)
po config mesh-develop

po setup-mesh

MODULAR=n po argon build



## normal building of Mesh Devices
## po config v0.8.0-rc.27 
## po argon build


## you do the nest 3 lines without the hashtag

#particle cloud login
#particle list
#particle flash --usb  myArgonName.firmware.bin

## dfu mode flashing yellow hold mode button tap reset about 5 seconds past flashing purple safe mode.
