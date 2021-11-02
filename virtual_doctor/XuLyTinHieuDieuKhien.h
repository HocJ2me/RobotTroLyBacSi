

void DieuKhienRobot()
{
  if(ROBOT_STATUS == ROBOT_ON)
  {
    switch(ROBOT_CONTROL)
    {
      case ROBOT_AHEAD:   DC_Ahead(); break;
      case ROBOT_BACK:   DC_Back(); break;
      case ROBOT_LEFT:   DC_Left(); break;
      case ROBOT_RIGHT:   DC_Right(); break;
      default: DC_Stop(); break;
    }
  }
}
