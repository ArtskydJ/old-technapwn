task usercontrol()
{
  initializeOperator();
  StartTask(UpdatePIDControllers);
	#ifdef _SIMULATED
		while (!bSimulatedAutonomousMode)
	#else
		while (!bIfiAutonomousMode)
	#endif
		{
			getInput();
			processOperator();
			if (EnableOutput)
				doOutput();
		}
}

int processOperator()
{
	//Driver control code here
	int ErrorCode = 0;
	operatorDriveTrain();
	operatorLift();
	operatorIntake();
	operatorTines();
	return ErrorCode;
}


//--------------------------------------------< Drive-train Code >-----------------------------------------------\\

void LiftHeightButtonsCheck(int CurrentButtonState, int &WasAlreadyPressed, TGoalHeightButton &LastGoalHeightButton, TGoalHeightButton LastGoalHeightButtonValue, int GoalHeight)
{
	if (CurrentButtonState && !WasAlreadyPressed) // If this is the first time the current button is being detected as pressed
	{
	  if (LastGoalHeightButton == LastGoalHeightButtonValue) // If we are already at this button's height
	  {
  	  LastGoalHeightButton = NOGOALBUTTON;                // Set the last button for this joystick to none
  	  LiftTargetHeight = FLOORHEIGHT;                     // Move lift to floor
  	}
	  else
	  {
      LastGoalHeightButton = LastGoalHeightButtonValue;   // Set the last button for this joystick to whatever button is pressed
  	  LiftTargetHeight = GoalHeight;                      // Move lift to predefined goal height.
  	}
	  LiftToPresetHeight = 1;                               // Indicate that the preset lift height buttons want control
	}
	WasAlreadyPressed = CurrentButtonState;                 // Trap so that this code only executes once per button press
}

int operatorDriveTrain()
{
  int ErrorCode;

	//ToggleCheck(btnOldNewDrive, btnOldNewDrivePressed, (int) OldNewDrive);
	ToggleCheck(btnFrontBackDrive, btnFrontBackDrivePressed, (int) FrontBackDrive);

	if (OldNewDrive == PLAIN)
	{
	  // Deadband control for each axis.
	  if(!(abs(stkDriveX) > JOYSTICKDEADZONE))     stkDriveX = 0;
	  if(!(abs(stkDriveY) > JOYSTICKDEADZONE))     stkDriveY = 0;
	  if(!(abs(stkDriveS) > JOYSTICKDEADZONE * 2)) stkDriveS = 0;

		JoystickMax = 127+((10)+(0-cos(atan((stkDriveY/stkDriveX)*4)*(10))));
		JoystickPower = sqrt(pow(stkDriveY,2)+pow(stkDriveX,2)+pow(stkDriveS,2));
	  motorLeftFrontDrive = stkDriveY + stkDriveX + stkDriveS;
		motorLeftBackDrive =  stkDriveY + stkDriveX - stkDriveS;
		motorRightFrontDrive = stkDriveY - stkDriveX - stkDriveS;
		motorRightBackDrive =  stkDriveY - stkDriveX + stkDriveS;
	}
	else
	{
		if((abs(stkDriveY) > JOYSTICKDEADZONE) || (abs(stkDriveX) > JOYSTICKDEADZONE))	//If the Joystick has been pushed far enough
		{
		  motorLeftFrontDrive = stkDriveY + stkDriveX;
		  motorLeftBackDrive = stkDriveY + stkDriveX;
		  motorRightFrontDrive = stkDriveY - stkDriveX;
		  motorRightBackDrive = stkDriveY - stkDriveX;
		}
		else
		{
			motorLeftFrontDrive = 0;
			motorLeftBackDrive = 0;
			motorRightFrontDrive = 0;
			motorRightBackDrive = 0;
		}
	}

	// Make sure our values are within the appropriate range
	RangeCheck(0-MOTORDRIVEMAX, motorLeftFrontDrive, MOTORDRIVEMAX);
	RangeCheck(0-MOTORDRIVEMAX, motorLeftBackDrive, MOTORDRIVEMAX);
	RangeCheck(0-MOTORDRIVEMAX, motorRightFrontDrive, MOTORDRIVEMAX);
	RangeCheck(0-MOTORDRIVEMAX, motorRightBackDrive, MOTORDRIVEMAX);

	return ErrorCode;
}

//------------------------------------Lift Code-------------------------------------//

int operatorLift()
{
  int ErrorCode = 0;

	// Preset lift heights
	LiftHeightButtonsCheck(btnLiftLowGoal1,    btnLiftLowGoal1Pressed,    LastGoalHeightButton1, LOWGOALBUTTON,    LOWGOALHEIGHT);
	LiftHeightButtonsCheck(btnLiftMiddleGoal1, btnLiftMiddleGoal1Pressed, LastGoalHeightButton1, MIDDLEGOALBUTTON, MIDDLEGOALHEIGHT);
	LiftHeightButtonsCheck(btnLiftHighGoal1,   btnLiftHighGoal1Pressed,   LastGoalHeightButton1, HIGHGOALBUTTON,   HIGHGOALHEIGHT);
	LiftHeightButtonsCheck(btnLiftLowGoal2,    btnLiftLowGoal2Pressed,    LastGoalHeightButton2, LOWGOALBUTTON,    LOWGOALHEIGHT);
	LiftHeightButtonsCheck(btnLiftMiddleGoal2, btnLiftMiddleGoal2Pressed, LastGoalHeightButton2, MIDDLEGOALBUTTON, MIDDLEGOALHEIGHT);
	LiftHeightButtonsCheck(btnLiftHighGoal2,   btnLiftHighGoal2Pressed,   LastGoalHeightButton2, HIGHGOALBUTTON,   HIGHGOALHEIGHT);

	//if (btnLiftLowGoal1)
	// See if we need to zero out lift encoder
	if (btnLiftEncoderReset1 || btnLiftEncoderReset2)
	{
		SensorValue[LiftEncoderPort] = 0;
		nMotorEncoder[LiftFL] = 0;
	}


	if(btnLiftUp1)
	{
	  LiftPower = 127;
	  LiftToPresetHeight = 0;
	}
	else if (btnLiftDown1)
	{
	  LiftPower = -127;
	  LiftToPresetHeight = 0;
	}
	else if (abs(stkLift1) > JOYSTICKDEADZONE)
	{
		LiftPower = stkLift1;
	  LiftToPresetHeight = 0;
	}
	else if (abs(stkLift2) > JOYSTICKDEADZONE)
	{
		LiftPower = stkLift2;
	  LiftToPresetHeight = 0;
	}
	else if (BottomLeftLiftLimitSwitch && BottomRightLiftLimitSwitch)
	{
	  LiftPower = 0;
	  LiftToPresetHeight = 0;
		/*SensorValue[LeftLiftEncoderPort] = 0;
		SensorValue[RightLiftEncoderPort] = 0;*/
	}
	else if (LiftToPresetHeight != 0)
	{
		PIDLift.Error = LiftTargetHeight - LiftEncoder;
	}
	else			//Joysticks are Centered, the encoder reset buttons and the bottom lift switches are not pressed
	{
		LiftPower = 0;
	}

	//motorLiftLeft = PIDLift.TargetPower + PIDLift.Output;
	//motorLiftRight = PIDLift.TargetPower - PIDLift.Output;
	if (LiftToPresetHeight == 0)
	{
		motorLiftLeftTop = motorLiftRightTop = LiftPower;
		motorLiftLeftBottom = motorLiftRightBottom = LiftPower;
	}
	else
	{
		if (abs(PIDLift.Error) > LIFTENCODERPIDTARGETDEADBAND) // Stop the Jerking behaviour
		{
			motorLiftLeftTop = motorLiftRightTop = PIDLift.Output;
			motorLiftLeftBottom = motorLiftRightBottom = PIDLift.Output;
		}
		else
		{
			motorLiftLeftTop = motorLiftRightTop = 0;
			motorLiftLeftBottom = motorLiftRightBottom = 0;
		}
	}
	/*if ((PIDLift.TargetPower + PIDLift.Output) < 0)   //If Left Lift is going down, slow it down
	{
		motorLiftLeft = (PIDLift.TargetPower + PIDLift.Output)*.5;  //.75
	}
	if ((PIDLift.TargetPower - PIDLift.Output) < 0)   //If Right Lift is going down, slow it down
	{
		motorLiftRight = (PIDLift.TargetPower + PIDLift.Output)*.5;  //.75
	}*/

	return ErrorCode;
}

//------------------------------------Intake Code-------------------------------------//

int operatorIntake()
{
  int ErrorCode = 0;
  	if(btnIntakeIn1 == 1)
    {
      motorIntakeFront = 127;
      motorIntakeBack = 127;
    }
    else if(btnIntakeOut1 == 1)
    {
	  motorIntakeFront = -127;
      motorIntakeBack = -127;
   }
    else if(btnIntakeIn2 == 1)
    {
      motorIntakeFront = 127;
      motorIntakeBack = 127;
    }
    else if(btnIntakeOut2 == 1)
    {
      motorIntakeFront = -127;
      motorIntakeBack = -127;
    }
    else
    {
      motorIntakeFront = 0;
      motorIntakeBack = 0;
    }
  return ErrorCode;
}

int operatorTines()
{
	ToggleCheck(btnTines, btnTinesPressed, (int) TinesPosition);
	return 0;
}
