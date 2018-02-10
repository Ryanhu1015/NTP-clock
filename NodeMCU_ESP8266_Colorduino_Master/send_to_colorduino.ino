void sendDataToColorduino(void)
{
  if (buttonState)//this if statement is for the button pressed or not
  {
    //colorduino board id 9
    numberFirstHalf[ipForButtonPressed[2] % 10][0] = 22;
    transmit_16(9, numberFirstHalf[ipForButtonPressed[2] % 10]);
    
    numberSecondHalf[ipForButtonPressed[2] % 10][0] = 33;
    transmit_16(9, numberSecondHalf[ipForButtonPressed[2] % 10]);

    numberFirstHalf[(ipForButtonPressed[2] / 10) % 10][0] = 44;
    transmit_16(9, numberFirstHalf[(ipForButtonPressed[2] / 10) % 10]);

    numberSecondHalf[(ipForButtonPressed[2] / 10) % 10][0] = 55;
    transmit_16(9, numberSecondHalf[(ipForButtonPressed[2] / 10) % 10]);
    //colorduino board id 8
    if (ipForButtonPressed[2] / 100 > 0)
    {
      numberFirstHalf[ipForButtonPressed[2] / 100][0] = 22;
      transmit_16(8, numberFirstHalf[ipForButtonPressed[2] / 100]);
      numberSecondHalf[ipForButtonPressed[2] / 100][0] = 33;
      transmit_16(8, numberSecondHalf[ipForButtonPressed[2] / 100]);
    } else
    {
      nothing[0] = 22;
      transmit_16(8, nothing);
      nothing[0] = 33;
      transmit_16(8, nothing);
    }
    dotForIP[0] = 44;
    transmit_16(8, dotForIP);

    numberFirstHalf[ipForButtonPressed[1] % 10][0] = 55;
    transmit_16(8, numberFirstHalf[ipForButtonPressed[1] % 10]);
    //colorduino board id 7
    numberSecondHalf[ipForButtonPressed[1] % 10][0] = 22;
    transmit_16(7, numberSecondHalf[ipForButtonPressed[1] % 10]);

    numberFirstHalf[(ipForButtonPressed[1] / 10) % 10][0] = 33;
    transmit_16(7, numberFirstHalf[(ipForButtonPressed[1] / 10) % 10]);

    numberSecondHalf[(ipForButtonPressed[1] / 10) % 10][0] = 44;
    transmit_16(7, numberSecondHalf[(ipForButtonPressed[1] / 10) % 10]);

    if (ipForButtonPressed[1] / 100 > 0)
    {
      numberFirstHalf[ipForButtonPressed[1] / 100][0] = 55;
      transmit_16(7, numberFirstHalf[ipForButtonPressed[1] / 100]);

      numberSecondHalf[ipForButtonPressed[1] / 100][0] = 22;
      transmit_16(6, numberSecondHalf[ipForButtonPressed[1] / 100]);
    } else
    {
      nothing[0] = 55;
      transmit_16(7, nothing);
      nothing[0] = 22;
      transmit_16(6, nothing);
    }
    // colorduino board id 6
    dotForIP[0] = 33;
    transmit_16(6, dotForIP);

    numberFirstHalf[ipForButtonPressed[0] % 10][0] = 44;
    transmit_16(6, numberFirstHalf[ipForButtonPressed[0] % 10]);

    numberSecondHalf[ipForButtonPressed[0] % 10][0] = 55;
    transmit_16(6, numberSecondHalf[ipForButtonPressed[0] % 10]);
    // colorduino board id 5
    numberFirstHalf[(ipForButtonPressed[0] / 10) % 10][0] = 22;
    transmit_16(5, numberFirstHalf[(ipForButtonPressed[0] / 10) % 10]);

    numberSecondHalf[(ipForButtonPressed[0] / 10) % 10][0] = 33;
    transmit_16(5, numberSecondHalf[(ipForButtonPressed[0] / 10) % 10]);
    if (ipForButtonPressed[0] / 100 > 0)
    {
      numberFirstHalf[ipForButtonPressed[0] / 100][0] = 44;
      transmit_16(5, numberFirstHalf[ipForButtonPressed[0] / 100]);

      numberSecondHalf[ipForButtonPressed[0] / 100][0] = 55;
      transmit_16(5, numberSecondHalf[ipForButtonPressed[0] / 100]);
    } else
    {
      nothing[0] = 44;
      transmit_16(5, nothing);
      nothing[0] = 55;
      transmit_16(5, nothing);
    }
    delay(3000);
    for (int i = 9; i > 6; i--)
    {
      for (int k = 22; k <= 55; k += 11)
      {
        nothing[0] = k;
        transmit_16(i, nothing);
      }
    }
    nothing[0] = 22;
    transmit_16(6, nothing);
    
    numberFirstHalf[ipForButtonPressed[3] % 10][0] = 33;
    transmit_16(6, numberFirstHalf[ipForButtonPressed[3] % 10]);

    numberSecondHalf[ipForButtonPressed[3] % 10][0] = 44;
    transmit_16(6, numberSecondHalf[ipForButtonPressed[3] % 10]);

    numberFirstHalf[(ipForButtonPressed[3] / 10) % 10][0] = 55;
    transmit_16(6, numberFirstHalf[(ipForButtonPressed[3] / 10) % 10]);

    numberSecondHalf[(ipForButtonPressed[3] / 10) % 10][0] = 22;
    transmit_16(5, numberSecondHalf[(ipForButtonPressed[3] / 10) % 10]);
    if (ipForButtonPressed[3] / 100 > 0)
    {
      numberFirstHalf[ipForButtonPressed[3] / 100][0] = 33;
      transmit_16(5, numberFirstHalf[ipForButtonPressed[3] / 100]);

      numberSecondHalf[ipForButtonPressed[3] / 100][0] = 44;
      transmit_16(5, numberSecondHalf[ipForButtonPressed[3] / 100]);
    } else
    {
      nothing[0] = 33;
      transmit_16(5, nothing);
      nothing[0] = 44;
      transmit_16(5, nothing);
    }
    dotForIP[0] = 55;
    transmit_16(5, dotForIP);
    delay(3000);

    seconds = 0;
    minutes = 0;
    hours = 0;
    time_first = 0;
    time_second = 0;
    time_third = 0;
    time_forth = 0;
    time_fifth = 0;
    time_sixth = 0;

    nothing[0] = 22;
    transmit_16(9, nothing);

    nothing[0] = 33;
    transmit_16(9, nothing);

    nothing[0] = 44;
    transmit_16(9, nothing);

    numberFirstHalf[time_first][0] = 55;
    transmit_16(9, numberFirstHalf[time_first]);

    numberSecondHalf[time_first][0] = 22;
    transmit_16(8, numberSecondHalf[time_first]);

    numberFirstHalf[time_second][0] = 33;
    transmit_16(8, numberFirstHalf[time_second]);

    numberSecondHalf[time_second][0] = 44;
    transmit_16(8, numberSecondHalf[time_second]);

    dot[0] = 55;
    transmit_16(8, dot);

    numberFirstHalf[time_third][0] = 22;
    transmit_16(7, numberFirstHalf[time_third]);

    numberSecondHalf[time_third][0] = 33;
    transmit_16(7, numberSecondHalf[time_third]);

    numberFirstHalf[time_forth][0] = 44;
    transmit_16(7, numberFirstHalf[time_forth]);

    numberSecondHalf[time_forth][0] = 55;
    transmit_16(7, numberSecondHalf[time_forth]);

    dot[0] = 22;
    transmit_16(6, dot);

    numberFirstHalf[time_fifth][0] = 33;
    transmit_16(6, numberFirstHalf[time_fifth]);

    numberSecondHalf[time_fifth][0] = 44;
    transmit_16(6, numberSecondHalf[time_fifth]);

    numberFirstHalf[time_sixth][0] = 55;
    transmit_16(6, numberFirstHalf[time_sixth]);

    numberSecondHalf[time_sixth][0] = 22;
    transmit_16(5, numberSecondHalf[time_sixth]);

    nothing[0] = 33;
    transmit_16(5, nothing);

    nothing[0] = 44;
    transmit_16(5, nothing);

    nothing[0] = 55;
    transmit_16(5, nothing);
  }
  else// else statement is for doing what it should do as a clock in regular time
  {
    if (time_fifth - currentHour != 0)
    {
      currentHour = time_fifth;
      transmit_16(9, appworks[0]);
      transmit_16(9, appworks[1]);
      transmit_16(9, appworks[2]);
      transmit_16(9, appworks[3]);

      transmit_16(8, appworks[4]);
      transmit_16(8, appworks[5]);
      transmit_16(8, appworks[6]);
      transmit_16(8, appworks[7]);

      transmit_16(7, appworks[8]);
      transmit_16(7, appworks[9]);
      transmit_16(7, appworks[10]);
      transmit_16(7, appworks[11]);

      transmit_16(6, appworks[12]);
      transmit_16(6, appworks[13]);
      transmit_16(6, appworks[14]);
      transmit_16(6, appworks[15]);

      transmit_16(5, appworks[16]);
      transmit_16(5, appworks[17]);
      transmit_16(5, appworks[18]);
      transmit_16(5, appworks[19]);
      delay(5000);
    } else
    {
      /*switch (time_first)
      {
      case 0: default:
          transmit_16(9, animation_first[0]);
          transmit_16(9, animation_first[1]);
          transmit_16(9, animation_first[2]);
          transmit_16(5, animation_first[0]);
          transmit_16(5, animation_first[1]);
          transmit_16(5, animation_first[2]);
          break;
        case 1:
          transmit_16(9, animation_second[0]);
          transmit_16(9, animation_second[1]);
          transmit_16(9, animation_second[2]);
          transmit_16(5, animation_second[0]);
          transmit_16(5, animation_second[1]);
          transmit_16(5, animation_second[2]);
          break;
        case 2:
          transmit_16(9, animation_third[0]);
          transmit_16(9, animation_third[1]);
          transmit_16(9, animation_third[2]);
          transmit_16(5, animation_third[0]);
          transmit_16(5, animation_third[1]);
          transmit_16(5, animation_third[2]);
          break;
        case 3:
          transmit_16(9, animation_forth[0]);
          transmit_16(9, animation_forth[1]);
          transmit_16(9, animation_forth[2]);
          transmit_16(5, animation_forth[0]);
          transmit_16(5, animation_forth[1]);
          transmit_16(5, animation_forth[2]);
          break;
        case 4:
          transmit_16(9, animation_fifth[0]);
          transmit_16(9, animation_fifth[1]);
          transmit_16(9, animation_fifth[2]);
          transmit_16(5, animation_fifth[0]);
          transmit_16(5, animation_fifth[1]);
          transmit_16(5, animation_fifth[2]);
          break;
        case 5:
          transmit_16(9, animation_sixth[0]);
          transmit_16(9, animation_sixth[1]);
          transmit_16(9, animation_sixth[2]);
          transmit_16(5, animation_sixth[0]);
          transmit_16(5, animation_sixth[1]);
          transmit_16(5, animation_sixth[2]);
          break;
        case 6:
          transmit_16(9, animation_seventh[0]);
          transmit_16(9, animation_seventh[1]);
          transmit_16(9, animation_seventh[2]);
          transmit_16(5, animation_seventh[0]);
          transmit_16(5, animation_seventh[1]);
          transmit_16(5, animation_seventh[2]);
          break;
      }*/

      numberSecondHalf[time_sixth][0] = 22;
      transmit_16(5, numberSecondHalf[time_sixth]);
      animation(5, 33, 44, 55);

      
      animation(9, 22, 33, 44);
      numberFirstHalf[time_first][0] = 55;
      transmit_16(9, numberFirstHalf[time_first]);

      /*for(int i = 0; i < 4; i++) // checksum for debugging
        {
        transmit_16(9, test3[i]);
        for (int k = 1; k < 17; k++)
          sum += test3[i][k];
        }

        checksum[1] = sum >> 8;
        checksum[2] = sum & 255;

        transmit_16(9, checksum);
        sum = 0;*/

      //debug through checksum above

      /*numberSecondHalf[time_first][0] = 22;
        transmit_16(9, numberSecondHalf[time_first]);

        numberFirstHalf[time_second][0] = 33;
        transmit_16(9, numberFirstHalf[time_second]);

        numberSecondHalf[time_second][0] = 44;
        transmit_16(9, numberSecondHalf[time_second]);

        dot[0] = 55;
        transmit_16(9, dot);*/

      //debug for testing number is correct or not, above

      numberSecondHalf[time_first][0] = 22;
      transmit_16(8, numberSecondHalf[time_first]);

      numberFirstHalf[time_second][0] = 33;
      transmit_16(8, numberFirstHalf[time_second]);

      numberSecondHalf[time_second][0] = 44;
      transmit_16(8, numberSecondHalf[time_second]);

      dot[0] = 55;
      transmit_16(8, dot);

      numberFirstHalf[time_third][0] = 22;
      transmit_16(7, numberFirstHalf[time_third]);

      numberSecondHalf[time_third][0] = 33;
      transmit_16(7, numberSecondHalf[time_third]);

      numberFirstHalf[time_forth][0] = 44;
      transmit_16(7, numberFirstHalf[time_forth]);

      numberSecondHalf[time_forth][0] = 55;
      transmit_16(7, numberSecondHalf[time_forth]);

      dot[0] = 22;
      transmit_16(6, dot);

      numberFirstHalf[time_fifth][0] = 33;
      transmit_16(6, numberFirstHalf[time_fifth]);

      numberSecondHalf[time_fifth][0] = 44;
      transmit_16(6, numberSecondHalf[time_fifth]);

      numberFirstHalf[time_sixth][0] = 55;
      transmit_16(6, numberFirstHalf[time_sixth]);
    }
  }
}


void animation(int boardID, int a, int b, int c)
{
  switch (time_first)
  {
  case 0: default:
      animation_first[0][0] = a;
      transmit_16(boardID, animation_first[0]);
      animation_first[1][0] = b;
      transmit_16(boardID, animation_first[1]);
      animation_first[2][0] = c;
      transmit_16(boardID, animation_first[2]);
      break;
    case 1:
      animation_second[0][0] = a;
      transmit_16(boardID, animation_second[0]);
      animation_second[1][0] = b;
      transmit_16(boardID, animation_second[1]);
      animation_second[2][0] = c;
      transmit_16(boardID, animation_second[2]);
      break;
    case 2:
      animation_third[0][0] = a;
      transmit_16(boardID, animation_third[0]);
      animation_third[1][0] = b;
      transmit_16(boardID, animation_third[1]);
      animation_third[2][0] = c;
      transmit_16(boardID, animation_third[2]);
      break;
    case 3:
      animation_forth[0][0] = a;
      transmit_16(boardID, animation_forth[0]);
      animation_forth[1][0] = b;
      transmit_16(boardID, animation_forth[1]);
      animation_forth[2][0] = c;
      transmit_16(boardID, animation_forth[2]);
      break;
    case 4:
      animation_fifth[0][0] = a;
      transmit_16(boardID, animation_fifth[0]);
      animation_fifth[1][0] = b;
      transmit_16(boardID, animation_fifth[1]);
      animation_fifth[2][0] = c;
      transmit_16(boardID, animation_fifth[2]);
      break;
    case 5:
      animation_sixth[0][0] = a;
      transmit_16(boardID, animation_sixth[0]);
      animation_sixth[1][0] = b;
      transmit_16(boardID, animation_sixth[1]);
      animation_sixth[2][0] = c;
      transmit_16(boardID, animation_sixth[2]);
      break;
    case 6:
      animation_seventh[0][0] = a;
      transmit_16(boardID, animation_seventh[0]);
      animation_seventh[1][0] = b;
      transmit_16(boardID, animation_seventh[1]);
      animation_seventh[2][0] = c;
      transmit_16(boardID, animation_seventh[2]);
      break;
  }
}

void numShowUp(int boardID, unsigned long numPosition)
{
  transmit_16(boardID, numberFirstHalf[numPosition]);
  transmit_16(boardID, numberSecondHalf[numPosition]);
}
