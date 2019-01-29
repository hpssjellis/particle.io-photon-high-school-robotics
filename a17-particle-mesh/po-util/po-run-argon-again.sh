#!/bin/bash

myFolderName=${PWD##*/}
echo $myFolderName

po clean
MODULAR=n po argon build
ls

## dfu mode flashing yellow hold mode button tap reset, about 5 seconds past flashing purple safe mode.
echo particle flash --usb  $myFolderName.firmware.bin

