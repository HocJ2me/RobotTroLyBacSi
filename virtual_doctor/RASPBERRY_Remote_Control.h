/*
 * Dữ liệu đọc từ RASPBERRY
 * 
 * ROBOT_CONTROL
 */
 void DocDuLieuRaspberry()
{
  int dataRx = 5;
  while (Serial.available())
  {
      dataRx = Serial.read();
      switch(dataRx)
      {
        case 49:   ROBOT_CONTROL = ROBOT_AHEAD; break;
        case 50:   ROBOT_CONTROL = ROBOT_BACK; break;
        case 51:   ROBOT_CONTROL = ROBOT_LEFT ;break;
        case 52:   ROBOT_CONTROL = ROBOT_RIGHT; break;
        case 53:   ROBOT_CONTROL = ROBOT_STOP; break;
      }
      String tmp = Serial.readString();
  }
}
