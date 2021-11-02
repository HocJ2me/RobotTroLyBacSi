//=================      Thư viện hỗ trợ      ==============
#include <Arduino_FreeRTOS.h>
#include <Wire.h> 
#include <ArduinoJson.h>
#include "BTS7960.h"
//================= file cài đặt các thông số ==============
#include "config.h"
//=================   Thư viện hoạt động      ==============
#ifdef ENABLE_BLUETOOTH
#include "HC05_Remote_Control.h"
#define DocDuLieu() DocDuLieuBluetooth()
#endif

#ifdef ENABLE_WIFI
#include "ESP8266_Remote_Control.h"
#define DocDuLieu() DocDuLieuWifi()
#endif

#ifdef ENABLE_PI
#include "RASPBERRY_Remote_Control.h"
#define DocDuLieu() DocDuLieuRaspberry()
#endif

#include "DieuKhienHuongDi.h"
#include "XuLyTinHieuDieuKhien.h"
#include "DieuKhienManHinh.h"

void setup() {
  Serial.begin(9600); 
  Serial1.begin(9600); 
  Serial2.begin(9600);
  LCD_Setup();
  
  xTaskCreate(TaskDocDuLieu, "Task1", 1000, NULL, 1, NULL);
  xTaskCreate(TaskDieuKhienRobot, "Task2", 1000, NULL, 2, NULL);
  xTaskCreate(TaskHienThiLCD, "IdleTask", 1000, NULL, 0, NULL);
}

void loop() 
{
  //Khong lam gi
}
/* Đọc dữ liệu uart */
static void TaskDocDuLieu(void* pvParameters)
{
  while(1)
  {
    DocDuLieu();
    vTaskDelay(20/portTICK_PERIOD_MS);
  }
}


/* điều khiển robot */
static void TaskDieuKhienRobot(void* pvParameters)
{
  while(1)
  {    
    DieuKhienRobot();
    vTaskDelay(20/portTICK_PERIOD_MS);
  }
}


/* thay đổi lcd */ 
static void TaskHienThiLCD(void* pvParameters)
{
  while(1)
  {  HienThiManHinh();
    vTaskDelay(150/portTICK_PERIOD_MS);
  }
}
