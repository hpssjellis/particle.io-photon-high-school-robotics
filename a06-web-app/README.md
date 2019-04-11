



## Web page control of the Photon (or Raspberry Pi)

Video [a06-web-app](https://youtu.be/NocvWycfz2o?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr&t=5s) A web page replacement for the Tinker App. You can edit the web page to control any pins on the Photon. View the generic working web app at [https://hpssjellis.github.io/particle.io-photon-high-school-robotics/](https://hpssjellis.github.io/particle.io-photon-high-school-robotics/) Needs your device ID and access token, which is stored locally on the webpage and watch how it can activate D7 to prove web page connectivity.



1. Load web-app.ino on the particle IDE and flash it to your Photon

1. Download to your computer or website the web-app.html file and edit it as needed. (Or work with it on your forked version of github but the page refreshes slower than on your computer or own website!)

1. Then go up a directory and copy index.html to your computer. (Editing on your computer is faster than on github)




1. Load webpage index.html on your browser (best using Google Chrome) For this site it is at 

https://github.com/hpssjellis/particle.io-photon-high-school-robotics/master/a06-web-app/web-app.html

make sure you are using the correct link to your web-app.html page if using your computer or website.


1. Enter your photon's  id and access code. Click the local browser storage save button

1. Check that you can control D7 on your photon



## To make an Android App (Works for IOs and Windows Phone but more complex and costs money)

1. Make sure you have forked this github repository


1. Upload your web-app.html into the index.html file of your forked version (Main folder location) of this github repository 


1. Link to phonegap build


https://build.phonegap.com

1. New App, copy your github URL, Build your app, use the QR-code to download, install and test it on an Android phone (Or pay the $100 to Apple to test an IOs App)





#if (PLATFORM_ID == 31) 
  // only compile following Raspberry PI stuff
#endif  
  
Wifi ARGON 12
Bluetooth BORON 13
Cellular XENON 14
