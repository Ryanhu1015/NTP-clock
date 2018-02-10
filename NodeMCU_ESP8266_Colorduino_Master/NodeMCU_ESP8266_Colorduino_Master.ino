#include <Wire.h>
#include <DNSServer.h> //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>
#include "index.h"
//#define RESET 2

/*char test[4][16] = 
{ {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
  {17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32},
  {33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48},
  {49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64}
};

char test2[4][16] = 
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,20},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,30},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,40},
};

char test3[4][17] =
{
   {22, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 0, 0, 224, 0},
   {33, 224, 0, 0, 224, 0, 0, 224, 0, 224, 0, 0, 224, 224, 224, 224, 0},
   {44, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 0},
   {55, 224, 0, 0, 224, 0, 0, 224, 0, 224, 224, 224, 224, 224, 224, 224, 0}
};

int N_value = 0, P_value = 0;
unsigned long sum = 0;
char checksum[17] = {66};*/

// extern things from "C" for using ISR
extern "C"
{
#include "user_interface.h"
}

const char ssid[] = "AWV2-6F-RA";
const char pass[] = "connectme";


//all the components for setting NTP server
unsigned int localPort = 2390;      // local port to listen for UDP packets

//IPAddress timeServer(129, 6, 15, 28); // time.nist.gov NTP server
IPAddress timeServerIP; // time.nist.gov NTP server address
char *ntpServerName = "tick.stdtime.gov.tw";
char *ntpServerName2 = "clock.stdtime.gov.tw";
char *ntpServerName3 = "time.stdtime.gov.tw";

const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;
// esp8266 WiFi server port 80
ESP8266WebServer server(80);
IPAddress ipForButtonPressed;
// the things in esp8266 web server
int calibration; // the color receive from webpage request and this variable gonna change the data sending to colorduino

//--------variable initialized for software RTC--------
unsigned long timeNow = 0;
unsigned long timeLast = 0;

int startingHour = 8; // set your starting hour here, not below at int hour. This ensures accurate daily correction of time
int seconds = 0;
int initialSecond = 0;
int minutes = 0;
int hours = 0;
int hourForUTC = 0;
int hourForUTC_last = 0;
int days = 0;

//Accuracy settings

//int dailyErrorFast = 0; // set the average number of milliseconds your microcontroller's time is fast on a daily basis
//int dailyErrorBehind = 0; // set the average number of milliseconds your microcontroller's time is behind on a daily basis
int correctedToday = 1; // do not change this variable, one means that the time has already been corrected today for the error in your boards crystal. This is true for the first day because you just set the time when you uploaded the sketch.

//--------variable for the number showing on colorduino board--------
unsigned long time_first = 0;
unsigned long time_second = 0;
unsigned long time_third = 0;
unsigned long time_forth = 0;
unsigned long time_fifth = 0;
unsigned long time_sixth = 0;
// calculate the last hour
int currentHour = time_fifth;

// variable store the time (seconds since 1970) grabed from NTP server
unsigned long epoch;

//the boolean variable for grasp time from NTP server whenever the computer bootup
boolean bootup = true;

//button pin as a trigger or an interface for reseting the time if user wants to
const int buttonPin = 12;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;
unsigned long currentTime = 0;
boolean buttonState = false;
boolean firstPressed = true;
boolean secondPressed = false;

char numberFirstHalf[10][17] =//all the first element 1 is the flag for colorduino addr 5-9 board to change its flag of order (maybe 22, 33, 44, 55)
{
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 0}, //number zero
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 0}, //number one
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 0, 0, 224, 0}, //number two
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 0}, //number three
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 0}, //number four
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0, 224, 224, 224, 224, 0}, //number five
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0, 224, 224, 224, 224, 0}, //number six
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 0}, //number seven
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 0}, //number eight
  {1 ,0, 0, 0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 0} //number nine
};
char numberSecondHalf[10][17] =
{
  {1, 224, 0, 0, 0, 0, 0, 224, 0, 224, 224, 224, 224, 224, 224, 224, 0}, //number zero
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //number one
  {1, 224, 0, 0, 224, 0, 0, 224, 0, 224, 0, 0, 224, 224, 224, 224, 0}, //number two
  {1, 224, 0, 0, 224, 0, 0, 224, 0, 224, 0, 0, 224, 0, 0, 224, 0}, //number three
  {1, 0, 0, 0, 224, 0, 0, 0, 0, 224, 224, 224, 224, 0, 0, 0, 0}, //number four
  {1, 224, 0, 0, 224, 0, 0, 224, 0, 224, 224, 224, 224, 0, 0, 224, 0}, //number five
  {1, 224, 0, 0, 224, 0, 0, 224, 0, 224, 224, 224, 224, 224, 224, 224, 0}, //number six
  {1, 224, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0, 0, 0, 0, 0, 0}, //number seven
  {1, 224, 0, 0, 224, 0, 0, 224, 0, 224, 224, 224, 224, 224, 224, 224, 0}, //number eight
  {1, 224, 0, 0, 224, 0, 0, 0, 0, 224, 224, 224, 224, 0, 0, 0, 0} //number nine
};

char appworks[20][17] =
{
  {22, 232, 232, 232, 232, 232, 0, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {33, 232, 232, 232, 232, 232, 0, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {44, 232, 232, 0, 232, 232, 232, 232, 0, 232, 0, 0, 232, 0, 0, 232, 0},
  {55, 232, 232, 232, 232, 0, 232, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  
  {22, 232, 0, 0, 0, 0, 0, 232, 0, 0, 232, 0, 0, 232, 232, 232, 0},
  {33, 0, 0, 232, 232, 0, 0, 0, 0, 232, 232, 232, 232, 232, 232, 232, 0},
  {44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0},
  {55, 232, 232, 232, 232, 0, 232, 232, 0, 232, 0, 0, 232, 232, 0, 0, 0},
  
  {22, 232, 232, 232, 232, 232, 232, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {33, 232, 232, 232, 232, 232, 232, 232, 0, 232, 0, 0, 0, 0, 0, 232, 0},
  {44, 232, 232, 232, 232, 232, 232, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {55, 232, 232, 232, 232, 232, 232, 0, 0, 0, 0, 0, 0, 0, 232, 232, 0},
  
  {22, 0, 0, 0, 232, 232, 232, 0, 0, 0, 0, 0, 0, 0, 232, 232, 0},
  {33, 232, 232, 232, 232, 232, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {44, 232, 232, 232, 232, 0, 0, 0, 0, 232, 0, 0, 232, 0, 0, 0, 0},
  {55, 232, 232, 232, 232, 232, 232, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  
  {22, 232, 232, 232, 232, 0, 0, 0, 0, 232, 0, 0, 232, 0, 0, 0, 0},
  {33, 232, 232, 232, 232, 232, 232, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {44, 232, 232, 232, 232, 232, 232, 232, 0, 232, 0, 0, 232, 0, 0, 0, 0},
  {55, 232, 232, 232, 232, 232, 232, 232, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

char dot[17] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 224, 0, 0, 0};

//dot for showing IP address on colorduino board
char dotForIP[17] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0};
//all nothing for some circumstance
char nothing[17] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

char animation_first[3][17] =
{
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0},
  {1, 0, 244, 244, 244, 244, 244, 244, 0, 244, 244, 0, 244, 244, 244, 0, 0},
  {1, 0, 244, 244, 244, 244, 244, 244, 0, 0, 0, 0, 0, 0, 244, 0, 0}
};

char animation_second[3][17] =
{
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0},
  {1, 244, 244, 244, 244, 244, 244, 0, 0, 244, 0, 244, 244, 244, 0, 0, 0},
  {1, 244, 244, 244, 244, 244, 244, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0}
};

char animation_third[3][17] =
{
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0, 0},
  {1, 244, 244, 244, 244, 244, 0, 0, 0, 0, 244, 244, 244, 0, 0, 0, 0},
  {1, 244, 244, 244, 244, 244, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0, 0}
};

char animation_forth[3][17] =
{
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0, 0, 0},
  {1, 244, 244, 244, 244, 0, 0, 0, 0, 244, 244, 244, 0, 0, 0, 0, 0},
  {1, 244, 244, 244, 244, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0, 0, 0}
};

char animation_fifth[3][17] =
{
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0, 0, 0, 0},
  {1, 244, 244, 244, 0, 0, 0, 0, 0, 244, 244, 0, 0, 0, 0, 0, 0},
  {1, 244, 244, 244, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0, 0, 0, 0}
};

char animation_sixth[3][17] =
{
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0, 0, 0, 0, 0},
  {1, 244, 244, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0, 0, 0, 0, 0},
  {1, 244, 244, 0, 0, 0, 0, 0, 0, 244, 0, 0, 0, 0, 0, 0, 0}
};

char animation_seventh[3][17] =
{
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

//-----------timer varible for ISR--------------
os_timer_t myTimer;

void user_init(void) // the function will be set in setup to trigger the ISR function
{
  os_timer_setfn(&myTimer, timerCallback, NULL);
  os_timer_arm(&myTimer, 200, true);
}

int numberOfDots = 0;

void setup()
{
  // ------setup for I2C master------
  Wire.begin(4, 5); // use esp8266 pin 4 as SDA and pin 5 as SCL
  Serial.begin(115200);
  Wire.setClockStretchLimit(1500000);    // in µs,
  // ------setup for buttonPin--------
  pinMode(buttonPin, INPUT_PULLUP);

  // ------setup for WiFi connection and NTP server------
  Serial.println();
  //connect to local WiFi network
  if (ssid && pass)
  {
    Serial.print("Connecting to: ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      numberOfDots ++;
      if (numberOfDots > 20)
      {
        Serial.println("connect another WiFi through your mobile!");
        WiFiManager wifiManager;
        wifiManager.setAPCallback(configModeCallback);
        wifiManager.autoConnect("RTANNTP", "1234");
        //break;
      }
    }
    Serial.println("");

    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  } else
  {
    // WiFi manager for user to choose another wifi if the first one doesn't work.
    WiFiManager wifiManager;
    wifiManager.autoConnect("RyanEspTest", "1234");//first parameter is name of access point, second is the password
  }
  //----------starting esp8266 server-------------
  server.begin();
  Serial.println("Server started");

  server.on("/", []()
  {
    server.send(1000, "text/html", page);// change 200 to 1000 to test if anything will go wrong
  });

  server.on("/timeSet", []()
  {
    int hoursFromWeb = server.arg("msg1").toInt();
    int minutesFromWeb = server.arg("msg2").toInt();
    int secondsFromWeb = server.arg("msg3").toInt();
    if (hoursFromWeb < 24 && minutesFromWeb < 60 && secondsFromWeb < 60)
    {
      hours = hoursFromWeb;
      minutes = minutesFromWeb;
      seconds = secondsFromWeb;
      show();
    }
    server.send(1000, "text/html", page);
  });

  server.on("/NTP", []()
  {
    ntpServer(ntpServerName);
    //hours = ((epoch % 86400L) / 3600) + 8;
    //minutes = (epoch % 3600) / 60;
    //seconds = epoch % 60 + 4;
    show();
    server.send(1000, "text/html", page);
  });

  server.on("/NTP2", []()
  {
    ntpServer(ntpServerName2);
    //hours = ((epoch % 86400L) / 3600) + 8;
    //minutes = (epoch % 3600) / 60;
    //seconds = epoch % 60 + 4;
    show();
    server.send(1000, "text/html", page);
  });

  server.on("/NTP3", []()
  {
    ntpServer(ntpServerName3);
    //hours = ((epoch % 86400L) / 3600) + 8;
    //minutes = (epoch % 3600) / 60;
    //seconds = epoch % 60 + 4;
    show();
    server.send(1000, "text/html", page);
  });

  server.on("/ColorPicker", []() {
    int red = server.arg("r").toInt();
    int green = server.arg("g").toInt();
    int blue = server.arg("b").toInt();
    calibration = (red >> 5 << 5) | (green << 3 >> 5 << 2) | (blue & 3);
    for (int i = 0; i < 10; i++)
    {
      for (int k = 1; k < 17; k++)
      {
        if (numberFirstHalf[i][k] != 0)
          numberFirstHalf[i][k] = calibration;
        if (numberSecondHalf[i][k] != 0)
          numberSecondHalf[i][k] = calibration;
      }
    }
    for (int i = 1; i < 17; i++)
    {
      if (dot[i] != 0)
        dot[i] = calibration;
    }
    server.send(1000, "text/html", page);
  });

  //----------starting UDP connect-------------
  Serial.println("Starting UDP");
  udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(udp.localPort());

  //-----------for the ISR function------------
  user_init(); //to spark the ISR function
}

void loop()
{
  if (bootup) // when first time boot up, get accurate time from NTP server
  {
    bootup = false;
    ntpServer(ntpServerName);
    //hours = ((epoch % 86400L) / 3600) + 8;
    //minutes = (epoch % 3600) / 60;
    //initialSecond = epoch % 60 + 4;//5 is for compensating the delay happened between esp8266 gets time from ntp server and showing on the colorduino board
  }

  calibrateTime();// function to calibrate Time through getting ntp server time again at every specific time i set

  
  //this is the section for button state,
  //if button pressed, as a trigger,
  //user can visit the webpage to change time showing on colorduino
  server.handleClient();// for running esp8266 server
  int reading = digitalRead(buttonPin);
  currentTime = millis();
  if (reading == LOW && firstPressed)
  {
    if ((currentTime - lastDebounceTime) > debounceDelay)
    {
      lastDebounceTime = currentTime;
      buttonState = true;
      ipForButtonPressed = WiFi.localIP();
      sendDataToColorduino();
      firstPressed = false;
      secondPressed = true;
    }
  }
  if (reading == LOW && secondPressed)
  {
    if ((currentTime - lastDebounceTime) > debounceDelay)
    {
      lastDebounceTime = currentTime;
      buttonState = false;
      firstPressed = true;
      secondPressed = false;
    }
  }
}

// this is the main function for master to transmit data through I2C to all of the slave
void transmit_16(byte addr, char* differentB)
{
  Wire.beginTransmission(addr);
  Wire.write(differentB, 17);// change from 16 bytes to 17 bytes!!!!!!!
  Wire.endTransmission();
}

void configModeCallback (WiFiManager * myWiFiManager)
{
  Serial.println("Entered config mode");
  //Serial.println(WiFi.softAPIP());
  //MarqueeForWiFimanager();
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

