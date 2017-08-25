** A11 DC Motor Drivers



Now it is your turn to make two working circuit diagrams from the images below and to get them running using the Photon and the Web-app. 



Good luck.


![](a-dual-motor-driver2.png)
[The Dual Motor Driver Pololu link](https://www.pololu.com/product/2135)



.



.




![](big-motor-driver2.png)
[The Big Motor Driver link](https://www.pololu.com/product/1451)



The dual motor driver (Max 11 V and 1.2 Amps for each motor) can control two motors (you only have to get one motor working :>), the big motor driver can only control one motor but it can run a larger current (30 Amps Max) and voltage (41 Volts Max). To prove that your motors work you can just use any 6V brushed DC motor. Sorry I don't have a good understanding yet of brushless motor drivers, but I will include a diagram when I can (The setup is easy it is the programming of the motor driver that seems confusing). 

The big motor driver has strange left and right digital pins. For many motors if both left and right are LOW (0) then the motor will coast. But if both left and right are HIGH (1) then the motor applies a brake! only if left is HIGH and right is low does it turn to the left (counterclockwise)

P.S. If the motor does not turn the way you want just switch the motor connected wires.
