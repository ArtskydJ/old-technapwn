void SubroutineCheck()
{
	if (BtnSubroutineSelect && BtnConveyorFwd)		DriverMode = DriverSubPyramid;//old code moved from below
	if (BtnSubroutineSelect && BtnDescorerUp)		DriverMode = DriverSubDescore;
	if (BtnSubroutineSelect && BtnAutonFromDriver)	IsRobotInVirtualAutonomousMode = true;
	//if (!JoystickCheck(true)){}
}

void DriveControl()
{
	StkCos1 = (float) StkDrvX/127.0;
	StkSin = (float) StkDrvY/127.0;
	StkCos2	= (float) StkDrvZ/127.0;
	StkTheta = radiansToDegrees(atan2(StkSin, StkCos1));
	StkEstPower = 137-(cos(StkTheta*4)*10);
	StkPower = sqrt((StkCos1*StkCos1)+(StkCos2*StkCos2)+(StkSin*StkSin))*(16129/StkEstPower);
	if (StkPower   <= JoystickDZ) StkPower = 0;

	if(DriveStyle) //Normal (Robot faces away from driver)
	{
		MtrDrvFL = -((StkSin*abs(StkSin))-(StkCos2*abs(StkCos2))+(StkCos1*abs(StkCos1)))*StkPower;
		MtrDrvBL = -((StkSin*abs(StkSin))-(StkCos2*abs(StkCos2))-(StkCos1*abs(StkCos1)))*StkPower;
		MtrDrvFR = -((StkSin*abs(StkSin))+(StkCos2*abs(StkCos2))-(StkCos1*abs(StkCos1)))*StkPower;
		MtrDrvBR = -((StkSin*abs(StkSin))+(StkCos2*abs(StkCos2))+(StkCos1*abs(StkCos1)))*StkPower;
	}
	else //Inverted (Robot faces driver)
	{
		MtrDrvFL = ((StkSin*abs(StkSin))+(StkCos2*abs(StkCos2))+(StkCos1*abs(StkCos1)))*StkPower;
		MtrDrvBL = ((StkSin*abs(StkSin))+(StkCos2*abs(StkCos2))-(StkCos1*abs(StkCos1)))*StkPower;
		MtrDrvFR = ((StkSin*abs(StkSin))-(StkCos2*abs(StkCos2))-(StkCos1*abs(StkCos1)))*StkPower;
		MtrDrvBR = ((StkSin*abs(StkSin))-(StkCos2*abs(StkCos2))+(StkCos1*abs(StkCos1)))*StkPower;
	}
	if(BtnDriveStyle==1 && LastBtnDriveStyle == 0) DriveStyle = !DriveStyle;//Toggle
	LastBtnDriveStyle = BtnDriveStyle;
}

void LiftControl()
{
	if (BtnDisablePots)
	{
		LiftTarget = 0;
		if		(BtnLiftUp == BtnLiftDown && BtnLiftUp2 == BtnLiftDown2)	MtrLift = 0;
		else if	(BtnLiftUp   || (BtnLiftUp2   && BtnLiftUp == BtnLiftDown))	MtrLift = Up;
		else if	(BtnLiftDown || (BtnLiftDown2 && BtnLiftUp == BtnLiftDown))	MtrLift = Down;
	}
	else
	{
		if ((BtnLiftUp  && !LastBtnLiftUp) ||			//UP
			(BtnLiftUp2 && !LastBtnLiftUp2 && BtnLiftUp == BtnLiftDown))
		{
			if (LastLiftDirection == LiftUp)	//If was at high (or ultra high) position...
			{
				LiftTarget = DriverULPos;			//then go to ultra high position.
				LastLiftDirection = LiftUp;			//Note the last lift direction.
			}
			else if (LiftTarget<DriverMLPos && SenSpatPot <= MSPos)	//If was at ground position (target might be 0), and if spatula is low enough
			{
				LiftTarget = DriverTLPos;			//then go to trough position.
				LastLiftDirection = LiftUp;			//Note the last lift direction.
			}
			else								//If the spatula is in the way
				if (bSoundActive==false)
					PlaySoundFile("Aah.wav");
		}
		else if ((BtnLiftDown  && !LastBtnLiftDown) ||	//DOWN
				 (BtnLiftDown2 && !LastBtnLiftDown2 && BtnLiftUp == BtnLiftDown))
		{
			if (LiftTarget>DriverTLPos)		//If was at ultra high position...
			{
				LiftTarget = DriverTLPos; 		//then go to trough position.
				LastLiftDirection = LiftDown; 	//and note the last lift direction.
			}
			else if (SenSpatPot<HSPos)		//If was at trough (or ground, or 0) position and the spatula is probably not in the way
			{
				LiftTarget = DriverGLPos;		//then go to ground position.
				LastLiftDirection = LiftDown; 	//and note the last lift direction.
			}
			if (SenSpatPot>=MSPos)			//If the spatula might be in the way
				if (bSoundActive==false)
					PlaySoundFile("Aah.wav");
		}
		if ((SenLiftPot<DriverMLPos && LiftTarget==DriverGLPos) || LiftTarget==0) MtrLift = 0;	// If Lift is low enough and target is ground position then stop motors
		else MtrLift = UpdatePIDController(PIDLift, LiftTarget-SenLiftPot);						// Otherwise, use the PID controller
	}
	LastBtnLiftUp	= BtnLiftUp;
	LastBtnLiftDown	= BtnLiftDown;
	LastBtnLiftUp2	= BtnLiftUp2;
	LastBtnLiftDown2= BtnLiftDown2;
}


void IntakeControl()
{
	if((BtnConveyorFwd == BtnConveyorRev)&&(BtnConveyorFwd2 == BtnConveyorRev2)) MtrConveyor = 0; //If no button is pressed
	else if(BtnConveyorFwd || BtnConveyorFwd2 && (BtnConveyorFwd == BtnConveyorRev)) MtrConveyor = Fwd;//Defaults to driver 1
	else if(BtnConveyorRev || BtnConveyorRev2 && (BtnConveyorFwd == BtnConveyorRev)) MtrConveyor = Rev;//Defaults to driver 1

	//if (BtnDisablePots)
	if (true)
	{
		if(BtnSpatulaUp == BtnSpatulaDown) MtrSpatula = 0;
		else if(BtnSpatulaUp) MtrSpatula = Up;
		else if(BtnSpatulaDown) MtrSpatula = Down;
	}
	else
	{
		if((BtnSpatulaUp == BtnSpatulaDown && BtnSpatulaUp2 == BtnSpatulaDown2) || (BtnSpatulaDown && SenSpatPot < LSPos)) //If both or neither
		{
			if(SenLiftPot <= 2000) {MtrSpatula = 0; bSpatDownPressed=false;}
			else
			{
				PIDSpatula.Kp = 0.1;
				if((SenLiftPot > LiftHighSpatUp) && (bSpatDownPressed == false)) SpatulaTarget = MSPos;
				else if((SenLiftPot <= LiftHighSpatUp) && (BtnLiftDown || BtnLiftDown2)) SpatulaTarget = LSPos;
				UpdatePIDController(PIDSpatula, SpatulaTarget-SenSpatPot);
			}
		}
		else if(BtnSpatulaUp   ||(BtnSpatulaUp2   && (BtnSpatulaUp == BtnSpatulaDown))) MtrSpatula = Up; //Defaults to driver 1
		else if((BtnSpatulaDown||(BtnSpatulaDown2 && (BtnSpatulaUp == BtnSpatulaDown))) && (SenSpatPot > LSPos)) {MtrSpatula = Down; bSpatDownPressed=true;}
	}
}

void DescorerControl()
{
	//if (BtnDescorerHighTrough || BtnDescorerHighTrough2)	DescorerTarget = HDPos;
	if (BtnDescorerUp == BtnDescorerDown && BtnDescorerUp2 == BtnDescorerDown2)
		MtrDescorer = 0;											// No descorer button pressed
	else if	(BtnDescorerUp || (BtnDescorerUp2 && BtnDescorerUp == BtnDescorerDown))
		{ MtrDescorer = Down;	DescorerTarget = 0; }				// Up descorer button pressed, defaults to driver 1
	else if	(BtnDescorerDown || (BtnDescorerDown2 && BtnDescorerUp == BtnDescorerDown))
		{ MtrDescorer = Up;		DescorerTarget = 0;	}				// Down descorer button pressed, defaults to driver 1
}


/*
void DriveControl()
{
	StkCos1 = (float) StkDrvX/127.0; //Forward
	StkSin = (float) StkDrvY/127.0;  //Strafe
	StkCos2	= (float) StkDrvZ/127.0; //Turn
	StkTheta = radiansToDegrees(atan2(StkSin, StkCos1));
	StkEstPower = 137-(cos(StkTheta*4)*10);
	StkPower = sqrt((pow(StkCos1,2))+(pow(StkCos2,2))+(pow(StkSin,2)))*(16129/StkEstPower);
	StkPower = (pow(StkPower,1.7)/28);
	if (StkPower   <= JoystickDZ) StkPower = 0;

	int tempForward = (StkSin* abs(StkSin));
	int tempStrafe =  (StkCos1*abs(StkCos1));
	int tempTurn =    (StkCos2*abs(StkCos2));
	if(DriveStyle) //Normal (Robot faces away from driver)
	{
		MtrDrvFL = -(tempForward-tempTurn+tempStrafe)*StkPower;
		MtrDrvBL = -(tempForward-tempTurn-tempStrafe)*StkPower;
		MtrDrvFR = -(tempForward+tempTurn-tempStrafe)*StkPower;
		MtrDrvBR = -(tempForward+tempTurn+tempStrafe)*StkPower;
	}
	else //Inverted (Robot faces driver)
	{
		MtrDrvFL = (tempForward+tempTurn+tempStrafe)*StkPower;
		MtrDrvBL = (tempForward+tempTurn-tempStrafe)*StkPower;
		MtrDrvFR = (tempForward-tempTurn-tempStrafe)*StkPower;
		MtrDrvBR = (tempForward-tempTurn+tempStrafe)*StkPower;
	}
	if(BtnDriveStyle==1 && LastBtnDriveStyle == 0) DriveStyle = !DriveStyle;//Toggle
	LastBtnDriveStyle = BtnDriveStyle;
}
//*/
