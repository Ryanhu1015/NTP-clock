void ntpServer(char *NTP)
{
  //get a random server from the pool
  WiFi.hostByName(NTP, timeServerIP); 

  sendNTPpacket(timeServerIP); // send an NTP packet to a time server
  // wait to see if a reply is available
  delay(100);
  
  int alreadyConnected = udp.parsePacket();//return true or false
  if (!alreadyConnected) {
    Serial.println("no packet yet");
    epoch = 0;
    Serial.println("epcoh clear!");
  }
  else {
    Serial.print("packet received, length= ");
    Serial.println(alreadyConnected);
    // We've received a packet, read the data from it
    udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

    //the timestamp starts at byte 40 of the received packet and is four bytes,
    // or two words, long. First, esxtract the two words:

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    // combine the four bytes (two words) into a long integer
    // this is NTP time (seconds since Jan 1 1900):
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    //Serial.print("Seconds since Jan 1 1900 = " );
    //Serial.println(secsSince1900);

    // now convert NTP time into everyday time:
    //Serial.print("Unix time = ");
    // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
    const unsigned long seventyYears = 2208988800UL;
    // subtract seventy years:
    epoch = secsSince1900 - seventyYears;
    // print Unix time:
    //Serial.println(epoch);

    hourForUTC = (epoch % 86400L) / 3600;
      
    if (hourForUTC + 8 >= 24)
      hours = (hourForUTC + 8) - 24;
    else
      hours = hourForUTC + 8;
    minutes = (epoch % 3600) / 60;
    seconds = epoch % 60;

    // print the hour, minute and second:
    Serial.print("epoch: ");
    Serial.println(epoch);
    
    Serial.print("The UTC time is ");       // UTC is the time at Greenwich Meridian (GMT)
    Serial.print(hours); // print the hour (UTC+8) (86400 equals secs per day)
    Serial.print(':');
    if (minutes < 10 ) {
      // In the first 10 minutes of each hour, we'll want a leading '0'
      Serial.print('0');
    }
    Serial.print(minutes); // print the minute (3600 equals secs per minute)
    Serial.print(':');
    if (seconds < 10 ) {
      // In the first 10 seconds of each minute, we'll want a leading '0'
      Serial.print('0');
    }
    Serial.println(seconds); // print the second
  }
}
