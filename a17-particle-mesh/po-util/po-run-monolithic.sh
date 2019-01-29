
echo "Enter a folder name for the argon build"
read myName

po init argon $myName
cd $myName


## monolithic Build of Mesh Devices (full load of firmware to device)
po config mesh-develop

po setup-mesh

MODULAR=n po argon build



## normal building of Mesh Devices
## po config v0.8.0-rc.27 
## po argon build




particle cloud login
particle list
echo "particle flash --usb  $myName.firmware.bin"
particle flash --usb  $myName.firmware.bin

## dfu mode flashing yellow hold mode button tap reset, about 5 seconds past flashing purple safe mode.
