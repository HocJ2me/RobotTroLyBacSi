/*
 * Dữ liệu đọc từ module wifi ESP-12E
 * 
 * ROBOT_CONTROL
 */
 
 void DocDuLieuBluetooth()
{
  int dataRx = "";
  while (Serial1.available())
  {
      dataRx = Serial1.read();
      switch(dataRx)
      {
        case 49:   ROBOT_CONTROL = ROBOT_AHEAD; break;
        case 50:   ROBOT_CONTROL = ROBOT_BACK; break;
        case 51:   ROBOT_CONTROL = ROBOT_LEFT ;break;
        case 52:   ROBOT_CONTROL = ROBOT_RIGHT; break;
        case 53:   ROBOT_CONTROL = ROBOT_STOP; break;
      }
      Serial1.println(dataRx);
      Serial1.println(ROBOT_CONTROL);
  }
}
