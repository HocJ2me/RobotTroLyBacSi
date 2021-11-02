/*
 * Các chân robot
 * 
 *        đầu robot
 * bánh 3: DC3           bánh 2: DC2
 * 
 * 
 * 
 * Bánh 4: DC4           bánh 1: DC1
 * 
 */

int currentSpeed = 80;
BTS7960 DC1(DC1_EN, DC1_L_PWM, DC1_R_PWM);
BTS7960 DC2(DC2_EN, DC2_L_PWM, DC2_R_PWM);
BTS7960 DC3(DC3_EN, DC3_L_PWM, DC3_R_PWM);
BTS7960 DC4(DC4_EN, DC4_L_PWM, DC4_R_PWM);

int DC_Speed()
{
  return currentSpeed;
}
void DC_setSpeed(int speed)
{
  currentSpeed = speed;
}
void DC_Enable()
{
  DC1.Enable();
  DC2.Enable();
  DC3.Enable();
  DC4.Enable();
}

void DC_Disable()
{
  DC1.Disable();
  DC2.Disable();
  DC3.Disable();
  DC4.Disable();
}

void DC_Stop()
{
  DC_Enable();
  DC1.Stop();
  DC2.Stop();
  DC3.Stop();
  DC4.Stop();
}

void DC_Ahead()
{
  DC_Enable();
  DC1.TurnLeft(currentSpeed);
  DC2.TurnLeft(currentSpeed);
  DC3.TurnRight(currentSpeed);
  DC4.TurnRight(currentSpeed);  
}
void DC_Back()
{
  DC_Enable();
  DC1.TurnRight(currentSpeed);
  DC2.TurnRight(currentSpeed);
  DC3.TurnLeft(currentSpeed);
  DC4.TurnLeft(currentSpeed);  
}
void DC_Left()
{
  DC_Enable();
  DC1.TurnLeft(currentSpeed);
  DC2.TurnRight(currentSpeed);
  DC3.TurnLeft(currentSpeed);
  DC4.TurnRight(currentSpeed);  
}
void DC_Right()
{
  DC_Enable();
  DC1.TurnRight(currentSpeed);
  DC2.TurnLeft(currentSpeed);
  DC3.TurnRight(currentSpeed);
  DC4.TurnLeft(currentSpeed);  
}
