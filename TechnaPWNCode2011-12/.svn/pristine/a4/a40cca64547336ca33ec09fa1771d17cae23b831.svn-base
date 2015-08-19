int getInput()
{
	//input code here
	//Joystick Inputs
	int ErrorCode = 0;
	stkDriveX = vexRT[Ch4];							//Turn Left and Right Drive Joystick Channel
	stkDriveY = vexRT[Ch3];							//Up and Down Drive Joystick Channel
	stkDriveS = vexRT[Ch1];							//Strafe Left and Right Drive Joystick Channel
	//stkLift1 = vexRT[Ch2];						//Lift Joystick Channel
	stkLift2 = vexRT[Ch2Xmtr2];					//Lift Joystick Channel

	//Button Inputs
	btnLiftUp1 = vexRT[Btn5U];
	btnLiftDown1 = vexRT[Btn5D];
	//btnOldNewDrive = vexRT[Btn8D];    //Uncomment to try new drive systems
	btnFrontBackDrive = vexRT[Btn8U];
	btnIntakeIn1 = vexRT[Btn6U];
	btnIntakeOut1 = vexRT[Btn6D];
	btnIntakeIn2 = vexRT[Btn6UXmtr2];
	btnIntakeOut2 = vexRT[Btn6DXmtr2];
	btnLiftEncoderReset1 = vexRT[Btn7U];
	btnLiftEncoderReset2 = vexRT[Btn7UXmtr2];
	//btnLiftFloor1 = vexRT[Btn8];
	btnLiftLowGoal1 = vexRT[Btn8L];
	btnLiftMiddleGoal1 = vexRT[Btn8D];
	btnLiftHighGoal1 = vexRT[Btn8R];
	//btnLiftFloor2 = vexRT[Btn8];
	btnLiftLowGoal2  = vexRT[Btn8LXmtr2];
	btnLiftMiddleGoal2 = vexRT[Btn8DXmtr2];
	btnLiftHighGoal2 = vexRT[Btn8RXmtr2];
	btnStepThroughAutonomous = vexRT[Btn7D];
	btnLiftStallBypass = vexRT[Btn7L];
	btnTines = vexRT[Btn7R];
	//Digital Sensor Inputs
	/*LeftLiftEncoder = SensorValue[LeftLiftEncoderPort] * LIFTENCODERCONSTANT;
	RightLiftEncoder = SensorValue[RightLiftEncoderPort] * LIFTENCODERCONSTANT;
	LeftDriveEncoder = SensorValue[LeftDriveEncoderPort] * DRIVEENCODERCONSTANT;
	RightDriveEncoder = SensorValue[RightDriveEncoderPort] * DRIVEENCODERCONSTANT; */
	/* BottomLeftLiftLimitSwitch = SensorValue[BottomLeftLiftLimitSwitchPort];
	BottomRightLiftLimitSwitch = SensorValue[BottomRightLiftLimitSwitchPort]; */
	//LiftEncoder = SensorValue[LiftEncoderPort] * LIFTENCODERCONSTANT;
	LiftEncoder = LiftIntegratedEncoder = 0 - nMotorEncoder[LiftFL];
	LeftDriveIntegratedEncoder = nMotorEncoder[DriveFL];
	RightDriveIntegratedEncoder = nMotorEncoder[DriveFR];
	MainBatteryVoltageAverage = nAvgBatteryLevel;
	MainBatteryVoltageLevel = nImmediateBatteryLevel;
	ButtonBitMap = nLCDButtons;
	LeftDisplayButton = (ButtonBitMap & 1) && 1;
	CenterDisplayButton = (ButtonBitMap & 2) && 1;
	RightDisplayButton = (ButtonBitMap & 4) && 1;
	//btnStepThroughAutonomous = CenterDisplayButton; //For Debugging purposes

	//Analog Sensor Inputs
	gyrGyroscope = 0 - SensorValue[Gyro];
	LeftLineFollower = SensorValue[LeftLineFollowerPort];
	RightLineFollower = SensorValue[RightLineFollowerPort];
	return ErrorCode;
}
