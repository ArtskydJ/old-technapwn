typedef enum
{
	STRAIGHT,
	LEFTONEWHEELTURN,
	RIGHTONEWHEELTURN,
	BOTHWHEELTURN,
	STRAFESIDEWAYS,
	GYROAIM,
	WHITELINEFOLLOW,
	TINES
} TAutoDriveType;

typedef enum
{
	ANALOG1 = -1,
	NOCONDITION = 0,
	ANALOG2 = 1,
	ANALOG3 = 2,
	ANALOG4 = 3,
	ANALOG5 = 4,
	ANALOG6 = 5,
	ANALOG7 = 6,
	ANALOG8 = 7,
	DIGITAL1 = 8,
	DIGITAL2 = 9,
	DIGITAL3 = 10,
	DIGITAL4 = 11,
	DIGITAL5 = 12,
	DIGITAL6 = 13,
	DIGITAL7 = 14,
	DIGITAL8 = 15,
	DIGITAL9 = 16,
	DIGITAL10 = 17,
	DIGITAL11 = 18,
	DIGITAL12 = 19,
	LEFTDISPLAYBUTTON = 20,
	CENTERDISPLAYBUTTON = 21,
	RIGHTDISPLAYBUTTON = 22,
	ANYDISPLAYBUTTON = 23,
	LIFTREACHESTARGET = 24
} TJumpCondition;

typedef struct
{
	string StepName;
	//Outputs
	//int LiftPower;
	int LiftHeight;
	int IntakePower;
	TAutoDriveType DriveType;
	int DrivePower;
	//Trip values
	int Timeout;
	int GyroDegrees;
	int EncoderTicks;
	//Functions
	TJumpCondition JumpCondition;
	int JumpToStep;
} TAutonomous;

TAutonomous AutonomousArray[6][31];
TAutonomous CurrentStep;

task autonomous()
{
	initializeAutonomous();
	StartTask(UpdatePIDControllers);
	while (true)
	{
		getInput();
		processAutonomous();
		doOutput();
	}
}

int StartGyro = 0;
int StartLiftHeight = 0;

int processAutonomous()
{
	int ErrorCode = 0;
	int WillJump = 0;

	// Autonomous State Machine
	if (AutonomousState == SETUPSTEP) // If we're ready to setup the next step
	{
		if (CurrentStep.JumpToStep != 0)
		{
			if (CurrentStep.JumpCondition == 0)
				WillJump = 1;
			else if ((CurrentStep.JumpCondition >= 8) && CurrentStep.JumpCondition <= 19)
			{
				if (SensorValue[CurrentStep.JumpCondition])
					WillJump = 1;
			}
			else if(CurrentStep.JumpCondition == LEFTDISPLAYBUTTON && LeftDisplayButton)
				WillJump = 1;
			else if(CurrentStep.JumpCondition == CENTERDISPLAYBUTTON && CenterDisplayButton)
				WillJump = 1;
			else if(CurrentStep.JumpCondition == RIGHTDISPLAYBUTTON && RightDisplayButton)
				WillJump = 1;
			else if((CurrentStep.JumpCondition == ANYDISPLAYBUTTON) && (LeftDisplayButton || CenterDisplayButton || RightDisplayButton))
				WillJump = 1;
		} // </if (CurrentStep.JumpToStep != 0)>

		if (WillJump) // If we're jumping, then let that step be the next step
		{
			if (CurrentStep.JumpToStep == -1) //Jump to step '-1' means jump to step '0'
				AutonomousStep = 0;
			else
				AutonomousStep = CurrentStep.JumpToStep;
		}
		else  // Otherwise, go to the next step
		{
			AutonomousStep++;
		} // </if (WillJump)>

		//--------------------------

		if (AutonomousRoutine < NumOfAutonomusRoutines)			//An Autonomous Routine
		{
			//CurrentStep = AutonomousArray[AutonomousStep]; //This doesn't work in ROBOTC
			memcpy(CurrentStep, AutonomousArray[AutonomousRoutine][AutonomousStep], sizeof(CurrentStep)); //This does
		}
		else				                                				//No Autonomous
		{
			CurrentStep.Timeout = -1;
			CurrentStep.StepName = "Preparing to PWN";
		}
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, AutonomousArray[AutonomousRoutine][0].StepName); // Display Routine Name
		displayLCDString(0, 14, "  ");                          // Clear window for step number
		displayLCDNumber(0, 14, AutonomousStep, 1);             // Display step number
		displayLCDString(1, 0, CurrentStep.StepName);           // Display step name

		// Get ready for the 'meat' of the step
		AutonomousState = DOSTEP;
		ClearTimer(T2);
		SensorValue[Gyro] = StartGyro = 0;
		StartLiftHeight = LiftEncoder;
	}
	else if (AutonomousState == DOSTEP)
	{
		//// Motor Outputs

		// Lift Motors
		if (CurrentStep.LiftHeight != 0) //if (CurrentStep.LiftHeight != 0)
		{
			if (abs(StartLiftHeight - CurrentStep.LiftHeight) < LIFTENCODERAUTONOMOUSTARGETDEADBAND)
			{
				motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = 0;
			}
			else
			{
				if (CurrentStep.LiftHeight > StartLiftHeight)  // Going Up
				{
					if (LiftEncoder < CurrentStep.LiftHeight) // Haven't reached target
					{
						motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = UP;
					}
					else
					{
						motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = 0;
					}
				}
				else if (CurrentStep.LiftHeight < StartLiftHeight)  // Going Down
				{
					if (LiftEncoder > CurrentStep.LiftHeight) // Haven't reached target
					{
						motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = DOWN;
					}
					else
					{
						motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = 0;
					}
				}
				// PIDLift.Error = CurrentStep.LiftHeight - LiftEncoder;
				// motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = PIDLift.Output;
			}
		}
		else
		{
			motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = 0;
		}
		// Intake Motors
		if (CurrentStep.IntakePower != 0 && CurrentStep.IntakePower >= -127 && CurrentStep.IntakePower <= 127)
		{
			motorIntakeBack = motorIntakeFront = CurrentStep.IntakePower;
		}
		else if (CurrentStep.IntakePower == 128)
		{
			motorIntakeBack = motorIntakeFront = 0;
		}

		// Drive Motors
		if (CurrentStep.DriveType == STRAIGHT)
		{
			motorLeftFrontDrive = CurrentStep.DrivePower;
			motorLeftBackDrive = CurrentStep.DrivePower;
			motorRightFrontDrive = CurrentStep.DrivePower;
			motorRightBackDrive = CurrentStep.DrivePower;
		}
		else if (CurrentStep.DriveType == LEFTONEWHEELTURN)
		{
			motorLeftFrontDrive = 0;
			motorLeftBackDrive = 0;
			motorRightFrontDrive = CurrentStep.DrivePower;
			motorRightBackDrive = CurrentStep.DrivePower;
		}
		else if (CurrentStep.DriveType == RIGHTONEWHEELTURN)
		{
			motorLeftFrontDrive = CurrentStep.DrivePower;
			motorLeftBackDrive = CurrentStep.DrivePower;
			motorRightFrontDrive = 0;
			motorRightBackDrive = 0;
		}
		else if (CurrentStep.DriveType == BOTHWHEELTURN)
		{
			motorLeftFrontDrive = CurrentStep.DrivePower;
			motorLeftBackDrive = CurrentStep.DrivePower;
			motorRightFrontDrive = 0 - CurrentStep.DrivePower;
			motorRightBackDrive = 0 - CurrentStep.DrivePower;
		}
		else if (CurrentStep.DriveType == STRAFESIDEWAYS)
		{
			motorLeftFrontDrive = CurrentStep.DrivePower;
			motorLeftBackDrive = 0 - CurrentStep.DrivePower;
			motorRightFrontDrive = 0 - CurrentStep.DrivePower;
			motorRightBackDrive = CurrentStep.DrivePower;
		}
		else if (CurrentStep.DriveType == GYROAIM)
		{
			motorLeftFrontDrive = PIDGyro.Output;
		}
		else if (CurrentStep.DriveType == TINES)
		{
			TinesPosition = CurrentStep.DrivePower;
		}
		// Regardless,

		//Check to see if we can move on, or if we're still in the 'Running Stage'
		if (CurrentStep.Timeout != -1) // If this isn't the last step
		{
			if (CurrentStep.Timeout != 0 && ((time1[T2]) >= CurrentStep.Timeout))
				AutonomousState = PAUSEMOTORS;
			if (CurrentStep.GyroDegrees > 0 && (gyrGyroscope - StartGyro >= CurrentStep.GyroDegrees))
				AutonomousState = PAUSEMOTORS;
			if (CurrentStep.GyroDegrees < 0 && (gyrGyroscope - StartGyro <= CurrentStep.GyroDegrees))
				AutonomousState = PAUSEMOTORS;
			/*if (CurrentStep.EncoderTicks != 0 && (RightDriveEncoder >= CurrentStep.EncoderTicks))
			AutonomousState = PAUSEMOTORS;*/
			if (CurrentStep.JumpCondition == LIFTREACHESTARGET)
			{
				if (((LiftEncoder - StartLiftHeight) >= 0) && (LiftEncoder >= CurrentStep.LiftHeight))  //Going Up, and we passed the target
					AutonomousState = PAUSEMOTORS;
				else if (((LiftEncoder - StartLiftHeight) < 0) && (LiftEncoder <= CurrentStep.LiftHeight))  //Going Down, and we passed the target
					AutonomousState = PAUSEMOTORS;
			}
			if (CurrentStep.Timeout == 0)
				AutonomousState = PAUSEMOTORS;
		}
		else // If this is the last step
		{
			motorLiftLeftTop = motorLiftLeftBottom = motorLiftRightTop = motorLiftRightBottom = 0;
			motorIntakeBack = motorIntakeFront = 0;
			motorLeftFrontDrive = 0;
			motorLeftBackDrive = 0;
			motorRightFrontDrive = 0;
			motorRightBackDrive = 0;
		} // </if (CurrentStep.Timeout != -1)>

		// If the any stick has been moved, abort Autonomous and start User Control
		if (CheckJoystick())
		{
			CurrentMenuItem = 0;
			CurrentMenu = 0;
			DisplayState = DISPLAYMENU;
			StartTask(usercontrol);
			StopTask(autonomous);
		}
	}
	else if (AutonomousState == PAUSEMOTORS)
	{
		old_motorLeftFrontDrive  = motorLeftFrontDrive;
		old_motorLeftBackDrive   = motorLeftBackDrive;
		old_motorRightFrontDrive = motorRightFrontDrive;
		old_motorRightBackDrive  = motorRightBackDrive;
		old_motorLiftLeftTop     = motorLiftLeftTop;
		old_motorLiftLeftBottom  = motorLiftLeftBottom;
		old_motorLiftRightTop    = motorLiftRightTop;
		old_motorLiftRightBottom = motorLiftRightBottom;
		old_motorIntakeFront     = motorIntakeFront;
		old_motorIntakeBack      = motorIntakeBack;

		motorLeftFrontDrive      = 0;
		motorLeftBackDrive       = 0;
		motorRightFrontDrive     = 0;
		motorRightBackDrive      = 0;
		motorLiftLeftTop         = 0;
		motorLiftLeftBottom      = 0;
		motorLiftRightTop        = 0;
		motorLiftRightBottom     = 0;
		motorIntakeFront         = 0;
		motorIntakeBack          = 0;

		AutonomousState = WAITFORADVANCE;
	}
	else if (AutonomousState == WAITFORADVANCE)
	{
		if (AutonomousAdvanceMode == AUTOADVANCE || (AutonomousAdvanceMode == MANUALADVANCE && btnStepThroughAutonomous))
		{
			motorLeftFrontDrive  = old_motorLeftFrontDrive;
			motorLeftBackDrive   = old_motorLeftBackDrive;
			motorRightFrontDrive = old_motorRightFrontDrive;
			motorRightBackDrive  = old_motorRightBackDrive;
			motorLiftLeftTop     = old_motorLiftLeftTop;
			motorLiftLeftBottom  = old_motorLiftLeftBottom;
			motorLiftRightTop    = old_motorLiftRightTop;
			motorLiftRightBottom = old_motorLiftRightBottom;
			motorIntakeFront     = old_motorIntakeFront;
			motorIntakeBack      = old_motorIntakeBack;

			AutonomousState = SETUPSTEP;
		}
	}

	return ErrorCode;
}
