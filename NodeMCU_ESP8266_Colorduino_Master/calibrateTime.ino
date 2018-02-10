void calibrateTime(void)
{
  /*if (hours == startingHour + 2)// 50 is just the random number i choose for testing
    correctedToday = 1;*/

  if (hours == 10 && correctedToday == 0)
  //if (minutes == 30 && correctedToday == 0)
  //if (seconds == 30 && correctedToday == 0)
  {
     correctedToday = 1;
     Serial.println("correctedToday is 1 now!");
  }
  /*if (hours == startingHour && correctedToday == 1)// 10 is just the random number i choose for testing
  {
    ntpServer(ntpServerName)
    hours = ((epoch % 86400L) / 3600) + 8;
    minutes = (epoch % 3600) / 60;
    seconds = epoch % 60 + 4;
    correctedToday = 0;
  }*/

  if (hours == 8 && correctedToday == 1)
  //if (minutes == 50 && correctedToday == 1)
  //if (seconds == 50 && correctedToday == 1)
  {
    //if (WiFi.status() != WL_CONNECTED) Serial.println("WiFi crash!");
    ntpServer(ntpServerName);
    //hours = ((epoch % 86400L) / 3600) + 8;
    //minutes = (epoch % 3600) / 60;
    //seconds = epoch % 60 + 4;
    correctedToday = 0;
    //Serial.print("RAM: ");
    //Serial.println(ESP.getFreeHeap());
  }
}
