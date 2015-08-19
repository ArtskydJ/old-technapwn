//This part of the code is a funtion that takes inputs for all the mechanisms for the autonomous routines for unform execution.
//This allows code to be created easily and quickly.
void AutoNextStep()
{
	if (AutonomousStep < NumOfTimeRecords)
	{
		AutoTimeRecord[AutonomousStep] = time1[T1];
		writeDebugStreamLine("%d, %d.",AutonomousStep, AutoTimeRecord[AutonomousStep]);
	}
	else writeDebugStreamLine("AutoStep is too big");
	//writeDebugStreamLine("FL:%d, FR:%d, BL:%d, BR:%d",MtrDrvFL,MtrDrvFR,MtrDrvBL,MtrDrvBR);
	//nMotorEncoder[DriveBL] = 0;
	//nMotorEncoder[DriveBR] = 0;
	//SensorValue[BackRightQuad] = 0;
	DriveEncoderStartAvg = SenDriveEncoderAvg;
	DriveEncoderStartDif = SenDriveEncoderDif;
	HaveFoundLeftEdge = false;
	HaveFoundRightEdge = false;
	AddToAbsGyro += SensorValue(Gyro);
	SensorValue(Gyro) = 0;
	StepStartGyro = SensorValue(Gyro);
	AutonomousStep++;
	ClearTimer(T1);
	#ifdef BEEP
		if (AutonomousStep % 3 == 0) //Every third step...
			PlayTone(880,10);		// Make a higher tone
		else
			PlayTone(440,10);
	#endif

}

//This is a function that resets all the motors and will either start the code execution or exits autonomous mode all together.
void AutonomousReset(int StepNumber)
{
	MtrLift = 0;
	MtrDrvFL = 0;
	MtrDrvBL = 0;
	MtrDrvFR = 0;
	MtrDrvBR = 0;
	MtrSpatula = 0;
	MtrConveyor = 0;
	//for (int i=0; i<9; i++) AutoStep[i]=0;
	//writeDebugStreamLine("Start Or Done");
	if(StepNumber == 0) //Runs at start of Autonomous
	{
		AutoNextStep();
		AutonIsOnTheClock = true;
		ClearTimer(T2);
	}
	else //Runs at end of Autonomous
	{
		DriverMode = DriverJoystickControl;
		AutonIsOnTheClock = false;
	}
}

#ifdef ET
#include "Autonomous_Structures_ET.c"
#else
void AutonomousStructure(int *INAutoStep)
{
	int INlift			= INAutoStep[0];
	int INconveyor		= INAutoStep[1];
	int INspatula		= INAutoStep[2];
	int INdescorer		= INAutoStep[3];
	int INdl			= INAutoStep[4];
	int INdr			= INAutoStep[5];
	int INstrafe		= INAutoStep[6]; //Also used for Line and Wall following trigger
	int INtarget		= INAutoStep[7];
	int INdurationType	= INAutoStep[8];

	if      (INdurationType == ENCODSTRA || INdurationType == PIDSTRAIG) DriveEncoderError = SenDriveEncoderAvg - DriveEncoderStartAvg;
	else if (INdurationType == ENCODTURN || INdurationType == GYRSTRAFE) DriveEncoderError = SenDriveEncoderDif - DriveEncoderStartDif;

	if (INstrafe==LINE && INdurationType!=RELTRNGYR && INdurationType!=ENCODTURN && INdurationType!=PIDSTRAIG) //LINE FOLLOWING...Don't allow: drivegyro encodturn pidstraig
	{
		//if(SenLeftLine > SenRightLine+5)SenRightLine = FloorLine;
		//if (SenRightLine > LineEdge) PIDLineFollower.Kp = 0.12;
		//else PIDLineFollower.Kp = 0.06;
		PIDLineFollower.Output = UpdatePIDController(PIDLineFollower,(RightLineFolScaled - LeftLineFolScaled));
		MtrDrvFL = INdl + PIDLineFollower.Output;
		MtrDrvBL = INdl + PIDLineFollower.Output;
		MtrDrvFR = INdr - PIDLineFollower.Output;
		MtrDrvBR = INdr - PIDLineFollower.Output;
	}
	else if ((INstrafe==WALL_L || INstrafe==WALL_R)
		&& (INdurationType!=RELTRNGYR && INdurationType!=ENCODTURN && INdurationType!=PIDSTRAIG)) //WALL FOLLOWING...Don't allow: drivegyro encodturn pidstraig
	{
		if (INstrafe==WALL_L) PIDWallFollower.Error = (SenLeftUltrasonic  - INtarget);
		if (INstrafe==WALL_R) PIDWallFollower.Error = (SenRightUltrasonic - INtarget);
		PIDWallFollower.Output = UpdatePIDController(PIDWallFollower, PIDWallFollower.Error);
		MtrDrvFL = 75 - PIDWallFollower.Output;
		MtrDrvBL = 75 - PIDWallFollower.Output;
		MtrDrvFR = 75 + PIDWallFollower.Output;
		MtrDrvBR = 75 + PIDWallFollower.Output;
	}
	else //NORMAL DRIVING
	{
		CapValue(-127,INstrafe,127);
		MtrDrvFL = INdl+INstrafe;
		MtrDrvBL = INdl-INstrafe;
		MtrDrvFR = INdr-INstrafe;
		MtrDrvBR = INdr+INstrafe;
	}
	//Drive
	if (INdurationType == WHITELINE) // If we're wanting to line up with a white line
	{
		if (SenLeftEdge  > FloorEdgeLineup) HaveFoundLeftEdge  = true; // Have we found the left edge?
		if (SenRightEdge > FloorEdgeLineup) HaveFoundRightEdge = true; // Have we found the right edge?
		if (HaveFoundLeftEdge)	// If we have found the left  edge
		{
			MtrDrvFL /= -6; //Make the left  motors stop
			MtrDrvBL /= -6;
			//MtrDrvFR /= 3; //Make the right motors slow down
			//MtrDrvBR /= 3;
		}
		if (HaveFoundRightEdge) // If we have found the right edge
		{
			MtrDrvFR /= -6; //Make the right motors stop
			MtrDrvBR /= -6;
			//MtrDrvFL /= 3; //Make the right motors slow down
			//MtrDrvBL /= 3;
		}
		/*int errorLeft=(SenLeftEdge -FloorEdgeLineup);
		CapValue(-127,errorLeft,127);
		int errorRight=(SenRightEdge-FloorEdgeLineup);
		CapValue(-254,errorRight,254);
		MtrDrvFL = (errorLeft/4);
		MtrDrvBL = (errorLeft/4);
		MtrDrvFR = (errorRight/4);
		MtrDrvBR = (errorRight/4);*/
	}
	else if (INdurationType == PIDSTRAIG)
	{
		PIDDriveStraight.Output = UpdatePIDController(PIDDriveStraight, INtarget - DriveEncoderError);
		MtrDrvFL = PIDDriveStraight.Output;
		MtrDrvBL = PIDDriveStraight.Output;
		MtrDrvFR = PIDDriveStraight.Output;
		MtrDrvBR = PIDDriveStraight.Output;
		if (PIDDriveStraight.Output <= 0) PlayTone(440,10);
	}
	else if (INdurationType == RELTRNGYR)
	{
		PIDDriveGyro.Output = UpdatePIDController(PIDDriveGyro, INtarget - (SenGyro - StepStartGyro));
		MtrDrvFL = PIDDriveGyro.Output;
		MtrDrvBL = PIDDriveGyro.Output;
		MtrDrvFR = 0 - PIDDriveGyro.Output;
		MtrDrvBR = 0 - PIDDriveGyro.Output;
	}
	else if (INdurationType == ABSTRNGYR)
	{
		PIDDriveGyro.Output = UpdatePIDController(PIDDriveGyro, INtarget - (AbsoluteGyro));
		MtrDrvFL = PIDDriveGyro.Output;
		MtrDrvBL = PIDDriveGyro.Output;
		MtrDrvFR = 0 - PIDDriveGyro.Output;
		MtrDrvBR = 0 - PIDDriveGyro.Output;
	}
	else if (INdurationType == SQUAREUPG)
	{
		PIDDriveGyro.Output = UpdatePIDController(PIDDriveGyro, (INtarget - (SenGyro % 3600))*2);
		MtrDrvFL = PIDDriveGyro.Output;
		MtrDrvBL = PIDDriveGyro.Output;
		MtrDrvFR = 0 - PIDDriveGyro.Output;
		MtrDrvBR = 0 - PIDDriveGyro.Output;
	}

	else if (INdurationType == GYRSTRAFE)
	{
		MtrDrvFL = (INdl+INstrafe-SenGyro*GYROSTRAFEP)*.9;
		MtrDrvBL = INdl-INstrafe-SenGyro*GYROSTRAFEP;
		MtrDrvFR = (INdr-INstrafe+SenGyro*GYROSTRAFEP)*.9;
		MtrDrvBR = INdr+INstrafe+SenGyro*GYROSTRAFEP;
	}
	else if (INdurationType == LEFTULGYR || INdurationType == RIGTULGYR)
	{
		MtrDrvFL = INdl+INstrafe-SenGyro*GYROSTRAFEP;
		MtrDrvBL = INdl-INstrafe-SenGyro*GYROSTRAFEP;
		MtrDrvFR = INdr-INstrafe+SenGyro*GYROSTRAFEP;
		MtrDrvBR = INdr+INstrafe+SenGyro*GYROSTRAFEP;
	}

	if (abs(INlift) <= 127) MtrLift = INlift;
	else MtrLift	 = UpdatePIDController(PIDLift,		INlift	   - SenLiftPot); //Lift
	MtrConveyor = INconveyor;													  //Conveyor
	PIDSpatula.Kp = 0.2;
	if(abs(INspatula) <= 127) MtrSpatula = INspatula;
	else MtrSpatula  = UpdatePIDController(PIDSpatula,  INspatula  - SenSpatPot); //Spatula
	if(abs(INdescorer) <= 127) MtrDescorer = INdescorer;
	//else MtrDescorer = UpdatePIDController(PIDDescorer, INdescorer - SenDescPot); //Descorer //No pot

	switch(INdurationType) // This code asks what type of target condition are we looking for? Have we met it?
	{
		case RESETAUTO: AutonomousReset(AutonomousStep);																		   break;
		case TIMELIMIT: if(time1(T1) >= INtarget)																				AutoNextStep();break;
		case LIFTPOTEN: if((PIDLift.Error < INlift-100)!=(PIDLift.LastError < INlift-100))										AutoNextStep();break;
		case RELTRNGYR: if((INtarget > 0) ? ((SenGyro - StepStartGyro) > INtarget) : ((SenGyro - StepStartGyro) < INtarget))	AutoNextStep();break;
		case ENCODSTRA: if((INdr > 0) ? (DriveEncoderError > INtarget) : (DriveEncoderError < INtarget))			AutoNextStep();break;
		case ENCODTURN: if((DriveEncoderError < INtarget)!=(DriveEncoderErrorLast < INtarget))						AutoNextStep();break;
		case SPATPOTEN: if(abs(SenSpatPot-INtarget) <= 5)															AutoNextStep();break;
//		case WHITELINE: if(abs((SenLeftLine+SenRightLine)/2-LineEdge) <=5)											AutoNextStep();break;
		case WHITELINE: if(HaveFoundLeftEdge && HaveFoundRightEdge)													AutoNextStep();break;
		case SCREENBTN: if(nLCDButtons || (INtarget != 0 && (time1(T1) >= INtarget)))								AutoNextStep();break;
		case PIDSTRAIG: if((DriveEncoderError < INtarget)!=(DriveEncoderErrorLast < INtarget))						AutoNextStep();break;
		case CONVSWICH:	if(SenConveyerSwitch || time1(T1) >= INtarget)												AutoNextStep();break;
		case GYRSTRAFE: if((DriveEncoderError < INtarget)!=(DriveEncoderErrorLast < INtarget))						AutoNextStep();break;
		case LEFTULGYR: if((INstrafe > 0) ? (SenLeftUltrasonic  >= INtarget) : (SenLeftUltrasonic  <= INtarget))	AutoNextStep();break;
		case RIGTULGYR: if((INstrafe < 0) ? (SenRightUltrasonic >= INtarget) : (SenRightUltrasonic <= INtarget))	AutoNextStep();break;
		case BACKULSTR: if((INdr     > 0) ? (SenBackUltrasonic  >= INtarget) : (SenBackUltrasonic  <= INtarget))	AutoNextStep();break;
		case ABSTRNGYR: if((INtarget > 0) ? ((SenGyro % 3600) > INtarget) : ((SenGyro % 3600) < INtarget))			AutoNextStep();break;
		case SQUAREUPG: if(time1(T1) >= INstrafe && INstrafe != 0)																	AutoNextStep();break;
		default://nothing
	}
	if( time1(T1) >= FailsafeMS && INdurationType != RESETAUTO)								AutoNextStep();
	DriveEncoderErrorLast = DriveEncoderError;
}
#endif





/*
void AutonomousControl() //Errors with this one :(
{
	if      (DriverMode == DriverSubPyramid && !IsRobotInAutonomousMode)
		AutonomousStructure(AutoPyramid[AutonomousStep]);
	else if (DriverMode == DriverSubDescore && !IsRobotInAutonomousMode)
		AutonomousStructure(AutoDescore[AutonomousStep]);
	else switch (AutonomousRoutine)
	{
		case 1: AutonomousStructure(auto01[AutonomousStep]); break; // Left Autonomous (scores 21 or 22 (two greens, one yellow in trough))
		case 2: AutonomousStructure(auto02[AutonomousStep]); break; // Right Autonomous gets pyrimid plus the bonus(scores 40 ideally)
		case 3: AutonomousStructure(auto03[AutonomousStep]); break; // Position 3
		case 4: AutonomousStructure(auto04[AutonomousStep]); break; // Right Autonomous gets three green plus pyramid and preload (scores 45 ideally))
//		case 5: AutonomousStructure(auto05[AutonomousStep]); break; // Descorer test???
		case 6: AutonomousStructure(auto06[AutonomousStep]); break;
//		case 7: AutonomousStructure(auto07[AutonomousStep]); break;
		case 8: AutonomousStructure(auto08[AutonomousStep]); break;
		case 9: AutonomousStructure(auto09[AutonomousStep]); break; // Right Autonomous Skills (Scores 130 ideally)
		default: //nothing
	}
}
*/


void AutonomousControl() //No errors with this one :)
{
#ifdef ET
	#define n 10
#else
	#define n 9
#endif
	int tempArray[n];
	if      (DriverMode == DriverSubPyramid && !IsRobotInAutonomousMode)
		for (int j=0; j<n; j++) {tempArray[j] = AutoPyramid[AutonomousStep][j];}
	else if (DriverMode == DriverSubDescore && !IsRobotInAutonomousMode)
		for (int j=0; j<n; j++) {tempArray[j] = AutoDescore[AutonomousStep][j];}
	else switch (AutonomousRoutine)
	{
		case 1: for (int j=0; j<n; j++) {tempArray[j] = auto01[AutonomousStep][j];} break; // Left Autonomous  bite with yellow								(scores 022 ideally)
		case 2: for (int j=0; j<n; j++) {tempArray[j] = auto02[AutonomousStep][j];} break; // Right Autonomous gets pyrimid and a yellow						(scores 040 ideally)
		case 3: for (int j=0; j<n; j++) {tempArray[j] = auto03[AutonomousStep][j];} break; // Left Autonomous  Scoop up wall, and bite with yellow			(scores 060 ideally)
		case 4: for (int j=0; j<n; j++) {tempArray[j] = auto04[AutonomousStep][j];} break; // Right Autonomous gets pyramid, bite and preload				(scores 045 ideally)
		case 5: for (int j=0; j<n; j++) {tempArray[j] = auto05[AutonomousStep][j];} break;
		case 6: for (int j=0; j<n; j++) {tempArray[j] = auto06[AutonomousStep][j];} break; // Right Autonomous gets pyramid, bite and preload, then descores	(scores 045  ideally)
		case 7: for (int j=0; j<n; j++) {tempArray[j] = auto07[AutonomousStep][j];} break;
		case 8: for (int j=0; j<n; j++) {tempArray[j] = auto08[AutonomousStep][j];} break; // Right Autonomous Skills										(Scores 240 ideally)
		case 9: for (int j=0; j<n; j++) {tempArray[j] = auto09[AutonomousStep][j];} break; // Right Autonomous Skills										(Scores 175 ideally)
		default: //nothing
	}
	AutonomousStructure(tempArray);
}

/*int CheckForDriverSubroutine()
{
	if		(AutonomousSubroutine && JoystickCheck(true)) //AutonomousStructure();
	else if (DescoreSubroutine    && JoystickCheck(true)) AutonomousStructure();
	else if	(PyramidSubroutine    && JoystickCheck(true)) AutonomousStructure();
	else return true;
	return false;
}*/
