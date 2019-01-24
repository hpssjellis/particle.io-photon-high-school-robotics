#!/bin/bash

cd ~
mkdir openthread-all
cd ~/openthread-all

git clone https://github.com/openthread/wpantund.git
git clone https://github.com/openthread/borderrouter.git
git clone https://github.com/openthread/openthread.git
git clone https://github.com/openthread/pyspinel.git


cd ~/openthread-all/wpantund
sudo apt-get update
sudo apt-get install dbus libreadline
sudo apt-get install gcc g++ libdbus-1-dev libboost-dev libreadline-dev
git checkout full/latest-release
sudo apt-get install libtool autoconf autoconf-archive
./bootstrap.sh 
./configure --sysconfdir=/etc
make
sudo make install


cd ~/openthread-all/borderrouter
./script/bootstrap
./script/setup


