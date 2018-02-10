void timerCallback(void *pArg)
{
  if (!buttonState)
  {
    timeNow++;
    if (timeNow - timeLast == 5)
    {
      timeLast = timeNow;
      seconds++;
      /*if (initialSecond)
      {
        seconds = initialSecond;
        initialSecond = 0;
      }*/
      //-------the section for "seconds"--------
      if (seconds == 60)
      {
        seconds = 0;
        minutes = minutes + 1;
      }

      //-------the section for "minutes"--------
      if (minutes == 60)
      {
        minutes = 0;
        hours = hours + 1;
      }

      //-------the section for "hours"
      if (hours == 24)
      {
        hours = 0;
        days = days + 1;
      }

      time_first = seconds % 10;
      time_second = seconds / 10;
      time_third = minutes % 10;
      time_forth = minutes / 10;
      time_fifth = hours % 10;
      time_sixth = hours / 10;
      
      sendDataToColorduino();// function to send data to show on those colorduino board
      
      //calibrateTime();// function to calibrate Time through getting ntp server time again at every specific time i set
    }
  }
}
