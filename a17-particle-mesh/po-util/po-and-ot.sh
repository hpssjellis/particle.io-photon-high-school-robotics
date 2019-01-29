#!/bin/bash


## must set /etc/wpantund.conf to the correct /dev/ttyACM0 after install



bash <(curl -sL get.po-util.com)

cd ~
mkdir openthread-all
cd ~/openthread-all

git clone https://github.com/openthread/wpantund.git
git clone https://github.com/openthread/borderrouter.git
git clone https://github.com/openthread/openthread.git
git clone https://github.com/openthread/pyspinel.git






cd ~/openthread-all/wpantund
git checkout full/latest-release
sudo apt-get update

sudo apt-get install dbus libreadline
sudo apt-get install gcc g++ libdbus-1-dev libboost-dev libreadline-dev
sudo apt-get install libtool autoconf autoconf-archive

./bootstrap.sh 
./configure --sysconfdir=/etc
make
sudo make install

# install some extra tools
sudo apt-get install screen





cd ~/openthread-all/openthread
git checkout full/latest-release
sudo apt-get update

./script/bootstrap

./bootstrap

make -f examples/Makefile-nrf52840 clean

make -f examples/Makefile-nrf52840 USB=1 BOOTLOADER=1 BORDER_AGENT=1 BORDER_ROUTER=1 COMMISSIONER=1 JOINER=1 UDP_PROXY=1 CFLAGS+=-UCONFIG_GPIO_AS_PINRESET


arm-none-eabi-objcopy output/nrf52840/bin/ot-ncp-ftd -O ihex output/nrf52840/bin/ncp_app.hex

arm-none-eabi-objcopy output/nrf52840/bin/ot-cli-ftd -O ihex output/nrf52840/bin/ot-cli-ftd.hex


ln -s ~/openthread-all ~/workspace/myOpenthread-all

ln -s ~/.po-util ~/workspace/myPo


