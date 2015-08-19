//////////////////////
//  Input.c         //
//  Joseph Dykstra  //
//  VRC team 3018   //
//////////////////////

//Functions
void input(void)
	{
	//--Decide what state the robot is in--//
	if (nVexRCReceiveState & vrCompetitionSwitch) //If the Competition switch is plugged in...
		{
		if (bIfiRobotDisabled)       sysCurrentMode = DISABLED;   //...then base the state on comp switch settings
		else if (bIfiAutonomousMode) sysCurrentMode = AUTONOMOUS;
		else                         sysCurrentMode = OPERATOR;
		}
	else   //If the Competition switch is not plugged in...
		{
		if (sysDisabledMode)        sysCurrentMode = DISABLED;   //... then base the state on variables
		else if (sysAutonomousMode) sysCurrentMode = AUTONOMOUS;
		else                        sysCurrentMode = OPERATOR;
		}
#ifdef USE_LIFT_POT
	senLiftPot = SensorValue[LIFT_POT];
#endif
#ifdef USE_AUTO_POT
	senAutoPot = SensorValue[AUTO_POT];
#endif
#ifdef USE_GYROSCOPE
	senGyro = SensorValue[GYRO]; //THIS NEEDS TO += DIFF!!!
#endif
#ifdef USE_ENCODERS
	senLeftEnc = nMotorEncoder[LEFT_ENC];
	senRightEnc = nMotorEncoder[RIGHT_ENC];
#endif
#ifdef USE_SCREEN
	senLeftLCDBtnLast   =   senLeftLCDBtn;
	senCenterLCDBtnLast = senCenterLCDBtn;
	senRightLCDBtnLast  =  senRightLCDBtn;
	senLeftLCDBtn =   ((bool)((nLCDButtons & 1)>0));
	senCenterLCDBtn = ((bool)((nLCDButtons & 2)>0));
	senRightLCDBtn =  ((bool)((nLCDButtons & 4)>0));
#endif
	joyLXStk = vexRT[Ch4];
	joyLYStk = vexRT[Ch3];
	joyRXStk = vexRT[Ch1];
	joyRYStk = vexRT[Ch2];


	joyLiftUpBtn =    (bool)vexRT[Btn5U];
	joyLiftDownBtn =  (bool)vexRT[Btn5D];
	joyIntakeInBtn =  (bool)vexRT[Btn6U];
	joyIntakeOutBtn = (bool)vexRT[Btn6D];

	joyLiftUpBtn2 =    (bool)vexRT[Btn5UXmtr2];
	joyLiftDownBtn2 =  (bool)vexRT[Btn5DXmtr2];
	joyIntakeInBtn2 =  (bool)vexRT[Btn6UXmtr2];
	joyIntakeOutBtn2 = (bool)vexRT[Btn6DXmtr2];
	}
