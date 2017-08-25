# particle.io-photon-high-school-robotics
Most of the important files from my High School Robotics course using the particle.io photon a wifi out of the box arduino.


For advanced students in my High School beginner robotics class to proceed quickly through the course so they can start making prototypes or for beginner students in my advanced Robotics Construction class to go at their own pace through some of the harder assignments.

Hopefully this repository will stay reasonably static so that it matches the video series at

https://www.youtube.com/playlist?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr




[![particle.io photon high school robotics](http://img.youtube.com/vi/zRZJHMFL0p4/0.jpg)](https://www.youtube.com/playlist?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr)




.




.
## Good References



[Photon.io](https://www.particle.io/) 

[Particle Community](https://community.particle.io/) Great help when you are stuck

[Photon Firmware Documentation](https://docs.particle.io/reference/firmware/photon/) Learn about the firmware (The software that runs the Photon).




## List of Videos

1. [a01-console:](https://youtu.be/chaqZgd_6Vs?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr)  A simple console program to get things started. No webpage needed. outputs A0 to the console. Then uses a GND (black), 3V3 (red) , SIG (yellow) sensor in this case a [slide potentiometer](https://www.seeedstudio.com/Grove-Slide-Potentiometer-p-1196.html) (variable resitor).

1. [a02-voltage-divider:](https://youtu.be/ARvSD5UfkQE?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr)  Using a voltage divider to better control the output of a 2 prong sensor in this case a [SNAP circuit photoresistor](http://www.elenco.com/product/productdetails/snap_circuits&amp%3Breg_parts=MTAw/photosensitive_resistor=ODE4)

1. [a03-DAC-to-ADC:](https://youtu.be/lFoDp0gJv_g?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr) This program shows how to change a digital signal into and anlog signal and then what happens when that analog signal is read by the analog pin A0 and the digital pin D6 

1. [a04-SOS-programming](https://youtu.be/ZnaCcftdiR0?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr) A short look at programming the particle.io photon by making students control the D7 LED to flash SOS

1. [a05-tinker](https://youtu.be/o0E6YIIJ4_Y?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr) A quick look at the tinker program that is part of the Particle android or IOs Apps

1. [a06-web-app](https://youtu.be/NocvWycfz2o?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr) A web page replacement for the Tinker App. You can edit the web page to look and control any pins on the Photon

1. [A07-mobile-App](https://youtu.be/nR8pwlmnSJU?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr). Once you have a working web page you can then convert the web page into a Free Android (or IOS for $100 per year !) That can be installed on your android phone using [Phonegap Build](https://build.phonegap.com)

1. [A08-IFTTT](https://youtu.be/DOlYkTn84Bs?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr) Have your Photon control other devices on the web using https://ifttt.com. Today we just use a button to turn on D7 but using IFTTT


1. [a09-servo](https://youtu.be/IlVX7E-KEmY?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr) Get a 6V servo working. Never run a 6V servo off the photon. It may work for a few seconds but my students have fried too many photons doing that. Challenge: How to get the servo working with the web-app? 

1. [a10-transistor](https://youtu.be/S6xwStw-t1U?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr). Using a PNP transistor to protect the Photon while controlling a more powerful circuit

1. [a11-DC-motor-drivers](https://youtu.be/-LZL-XpIsHs?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr) For DC motors I would like you to use the web-app.ino and web-app.html to control both the dual motor driver and the big motor driver. I have included some check programs to make sure your connections are working.

1. [a12-stepper-motor-driver](https://youtu.be/7wl20CeagmU?list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr) Just proving that a [Pololu stepper motor](https://www.pololu.com/product/1204) with [stepper driver](https://www.pololu.com/product/2134) works. You should try to program it to do more fancy things.

1.

1.

1.

1. Advanced Rasperry PI [video at](https://www.youtube.com/watch?v=h5NnSbo351I&index=1&list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr&t=25s) has it's own github site at https://github.com/hpssjellis/particle-photon-raspberry-pi-iot





1. Advanced websockets [video at](https://www.youtube.com/watch?v=zRZJHMFL0p4&index=2&list=PL57Dnr1H_egsL0r4RXPA4PY2yZhOJk5Nr&t=24s) has it's own github site at https://github.com/hpssjellis/Particle-Spark-Core-Photon-Websocket-Hack



.




.




.





.









My main github location
https://github.com/hpssjellis?tab=repositories


The normal particle cloud communication repository
https://github.com/hpssjellis/particle-photon-raspberry-pi-iot

The older version of the above
https://github.com/hpssjellis/spark-core-web-page-html-control

Fast websocket node js communication
https://github.com/hpssjellis/Particle-Spark-Core-Photon-Websocket-Hack






updates: May 20, 2017





