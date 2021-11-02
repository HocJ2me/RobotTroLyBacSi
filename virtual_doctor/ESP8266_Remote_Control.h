/*
 * Dữ liệu đọc từ module wifi ESP-12E
 * 
 * status: Trạng thái robot
 * control: Trạng thái điều khiển từ xa
 */

void DocDuLieuWifi()
{
  while (Serial1.available())
  {
      StaticJsonDocument<200> doc;
      String json = Serial1.readString();
      DeserializationError error = deserializeJson(doc, json);
      if (error) {
        Serial1.print(F("deserializeJson() failed: "));
        Serial1.println(error.c_str());
        return;
      }
      ROBOT_STATUS  = doc["status"];
      ROBOT_CONTROL = doc["control"];
  }
}
