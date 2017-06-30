# NTP-clock
this is a project about NTP clock, and i share all the code to everyone who needs or want to build their own NTP clock. the core of this project is that i use I2C protocol to make esp8266 (master) and colorduino (slave) to communicate.

### ESP8266
As a master, esp8266 sends data to colorduino to do something. cause i need the function of WiFi to grab the information from NTP server, and also i need to design user interface, a webpage for user to set time, choose other NTP servers and additional functions. Those functions can be carry out through esp8266 webserver function.

### Colorduino
As a slave, colorduino here is just for reading the data sent from esp8266 and showing those data on boards. No matter number, animation, or color, are all depends on esp8266 not colorduino.

## Appendix
this readme file is just brief about this project, the detailed information like what kinds of library you need to download, and troubles i had during the process, almost all of these things will be share on my blog: https://makeryan.wordpress.com/

hope everyone who wants to build your own NTP clock can make it, and also hope that the code i share will be helpful! have fun!
