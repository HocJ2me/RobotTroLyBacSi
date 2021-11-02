
//=================                    driver điều khiển                        ==============
//#define ENABLE_BLUETOOTH
//#define ENABLE_WIFI
#define ENABLE_PI


//=================           Cằi đặt chân và các biến điều khiển robot         ==============
const uint8_t DC1_EN    = 2;
const uint8_t DC1_L_PWM = 3;
const uint8_t DC1_R_PWM = 4;

const uint8_t DC2_EN    = 5;
const uint8_t DC2_L_PWM = 6;
const uint8_t DC2_R_PWM = 7;

const uint8_t DC3_EN    = 8;
const uint8_t DC3_L_PWM = 9;
const uint8_t DC3_R_PWM = 10;

const uint8_t DC4_EN    = 11;
const uint8_t DC4_L_PWM = 12;
const uint8_t DC4_R_PWM = 13;

enum ENUMS_STATUS{ROBOT_OFF, ROBOT_ON};
int ROBOT_STATUS = 1; // 0 la tat, 1 la dung, 2 la dang di chuyen
enum ENUMS_CONTROL
{ 
  ROBOT_STOP, 
  ROBOT_LEFT, 
  ROBOT_RIGHT, 
  ROBOT_AHEAD, 
  ROBOT_BACK
};
int ROBOT_CONTROL = 0; //0 dung yen, 1 trai, 2 phai, 3 thang, 4 lui
