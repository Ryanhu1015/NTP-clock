void show(void)
{
  time_first = seconds % 10;
  time_second = seconds / 10;
  time_third = minutes % 10;
  time_forth = minutes / 10;
  time_fifth = hours % 10;
  time_sixth = hours / 10;

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

