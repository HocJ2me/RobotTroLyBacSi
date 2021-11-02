#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Man hinh chuong ga


void LCD_Setup() 
{
  lcd.init();
  lcd.backlight();
  lcd.display();
  lcd.print("Tro ly bac si");
  lcd.setCursor(0,1);
  lcd.print("Man hinh debug");   
  delay(1500);
  lcd.clear();
}
String TrangThai2String()
{
    switch(ROBOT_CONTROL)
    {
      case ROBOT_AHEAD:   return "Tien";
      case ROBOT_BACK:    return "Lui";
      case ROBOT_LEFT:    return "Trai";
      case ROBOT_RIGHT:   return "Phai";
      default: return "Dung";
    }
}

void HienThiManHinh()
{
  lcd.setCursor(0,0);
  lcd.print("Toc Do: " + String(currentSpeed) +"         ");
  lcd.setCursor(0,1);
  lcd.print("Trang thai: " + TrangThai2String() +"           ");   
}
