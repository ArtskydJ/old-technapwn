#pragma config(Motor,  port1,           m1,            tmotorNormal, openLoop)
#pragma config(Motor,  port2,           m2,            tmotorNormal, openLoop)
#pragma config(Motor,  port3,           m3,            tmotorNormal, openLoop)
#pragma config(Motor,  port4,           m4,            tmotorNormal, openLoop)
#pragma config(Motor,  port5,           m5,            tmotorNormal, openLoop)
#pragma config(Motor,  port6,           m6,            tmotorNormal, openLoop)
#pragma config(Motor,  port7,           m7,            tmotorNormal, openLoop)
#pragma config(Motor,  port8,           m8,            tmotorNormal, openLoop)
#pragma config(Motor,  port9,           m9,            tmotorNormal, openLoop)
#pragma config(Motor,  port10,          m10,           tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int WasPressedOnce(int CurrentButtonState, int &WasAlreadyPressed)
{
  int Pressed = 0;
	if (CurrentButtonState && !WasAlreadyPressed)
		Pressed = 1;
	WasAlreadyPressed = CurrentButtonState;
	return Pressed;
}


task main()
{
	int MotorNumber1 = 4;
	int ButtonBitMap = nLCDButtons;
	int LeftDisplayButton1;
  int RightDisplayButton1;
  int LeftJoystickButton1;
  int RightJoystickButton1;
  int LeftDisplayButton2;
  int RightDisplayButton2;
  int LeftJoystickButton2;
  int RightJoystickButton2;
  int LeftDisplayButtonPressed1;
  int RightDisplayButtonPressed1;
  int LeftJoystickButtonPressed1;
  int RightJoystickButtonPressed1;
  int LeftDisplayButtonPressed2;
  int RightDisplayButtonPressed2;
  int LeftJoystickButtonPressed2;
  int RightJoystickButtonPressed2;
  displayLCDString(0, 0, "Motor           ");
  displayLCDNumber(1, 0, MotorNumber1);
  while (true)
	{
		ButtonBitMap = nLCDButtons;
	  LeftDisplayButton = (ButtonBitMap & 1) && 1;
	  RightDisplayButton = (ButtonBitMap & 4) && 1;
	  LeftJoystickButton = vexRT[Btn8L];
	  RightJoystickButton = vexRT[Btn8R];

		if ((WasPressedOnce(LeftJoystickButton1, LeftJoystickButtonPressed1) || WasPressedOnce(LeftDisplayButton1, LeftDisplayButtonPressed1)) && MotorNumber1 > 1)
		{
		  MotorNumber1--;
		  clearLCDLine(1);
		  displayLCDNumber(1, 0, MotorNumber1);
		}
		if ((WasPressedOnce(RightJoystickButton1, RightJoystickButtonPressed1) || WasPressedOnce(RightDisplayButton1, RightDisplayButtonPressed1)) && MotorNumber1 < 10)
		{
		  MotorNumber1++;
		  clearLCDLine(1);
		  displayLCDNumber(1, 0, MotorNumber1);
		}
		if (vexRT[Btn5U])
			motor[MotorNumber - 1] = 127;
		else if (vexRT[Btn5D])
			motor[MotorNumber - 1] = -127;
		else
			motor[MotorNumber - 1] = 0;
	}
}
