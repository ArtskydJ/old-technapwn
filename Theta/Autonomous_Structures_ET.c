#ifdef ET
void AutonomousStructure(int *INAutoStep)
{
	int INlift			= INAutoStep[0]; //Lift height or power
	int INconveyor		= INAutoStep[1]; //Conveyor power (no rotation sensor on it)
	int INspatula		= INAutoStep[2]; //Spatula height or power
	int INdescorer		= INAutoStep[3]; //Descorer power (no rotation sensor on it)
	int INdl			= INAutoStep[4]; //Left  side drive power
	int INdr			= INAutoStep[5]; //Right side drive power
	int INstrafe		= INAutoStep[6]; //Strafe power
	int INtarget		= INAutoStep[7]; //Target value (time, encoder, or other sensor)
	int INdriveType		= INAutoStep[8]; //Drive type (normal,
	int INendType		= INAutoStep[9];

	if(INdriveType == EncodStra || INdriveType == PIDStraig)	  DriveEncoderError = SenDriveEncoderAvg - DriveEncoderStartAvg;
	else if(INdriveType == EncodTurn || INdriveType == GyrStrafe) DriveEncoderError = SenDriveEncoderDif - DriveEncoderStartDif;
	if (INdriveType==FllwLineC) //LINE FOLLOWING, Center Sensors
	{
		if(SenLeftLine > SenRightLine+5)SenRightLine = FloorLine;
		PIDLineFollower.Output = UpdatePIDController(PIDLineFollower,((SenLeftLine + SenRightLine)/2 - LineEdge));
		MtrDrvFL = INdl - PIDLineFollower.Output;
		MtrDrvBL = INdl - PIDLineFollower.Output;
		MtrDrvFR = INdr + PIDLineFollower.Output;
		MtrDrvBR = INdr + PIDLineFollower.Output;
	}
	else if (INdriveType==FllwWallL || INdriveType==FllwWallR) //WALL FOLLOWING
	{
		if      (INdriveType==FllwWallL) PIDWallFollower.Error = (SenLeftUltrasonic  - INtarget);
		else if (INdriveType==FllwWallR) PIDWallFollower.Error = (SenRightUltrasonic - INtarget);
		PIDWallFollower.Output = UpdatePIDController(PIDWallFollower, PIDWallFollower.Error);
		MtrDrvFL = INdl - PIDWallFollower.Output;
		MtrDrvBL = INdl - PIDWallFollower.Output;
		MtrDrvFR = INdr + PIDWallFollower.Output;
		MtrDrvBR = INdr + PIDWallFollower.Output;
	}
	else if (INdriveType == PIDStraig)
	{
		PIDDriveStraight.Output = UpdatePIDController(PIDDriveStraight, INtarget - DriveEncoderError);
		MtrDrvFL = PIDDriveStraight.Output;
		MtrDrvBL = PIDDriveStraight.Output;
		MtrDrvFR = PIDDriveStraight.Output;
		MtrDrvBR = PIDDriveStraight.Output;
		//if (PIDDriveStraight.Output <= 0) PlayTone(440,10); //Debugging beep
	}
	else if (INdriveType == RelGyrosc || INdriveType == AbsGyrosc || INdriveType == GyrSqreUp)
	{
		if      (INdriveType == RelGyrosc)
			PIDDriveGyro.Output = UpdatePIDController(PIDDriveGyro, INtarget - (SenGyro - StepStartGyro));
		else if (INdriveType == AbsGyrosc)
			PIDDriveGyro.Output = UpdatePIDController(PIDDriveGyro, INtarget - AbsoluteGyro);
		/*else if (INdriveType == GyrSqreUp)
			PIDDriveGyro.Output = 0;*/
		MtrDrvFL = PIDDriveGyro.Output;
		MtrDrvBL = PIDDriveGyro.Output;
		MtrDrvFR = -PIDDriveGyro.Output;
		MtrDrvBR = -PIDDriveGyro.Output;
	}
	else if (INdriveType == GyrStrafe) //STRAFE AND STAY SQUARE WITH THE GYRO
	{
		MtrDrvFL = INdl+INstrafe-SenGyro*GYROSTRAFEP;
		MtrDrvBL = INdl-INstrafe-SenGyro*GYROSTRAFEP;
		MtrDrvFR = INdr-INstrafe+SenGyro*GYROSTRAFEP;
		MtrDrvBR = INdr+INstrafe+SenGyro*GYROSTRAFEP;
	}
	else //NORMAL DRIVING
	{
		MtrDrvFL = INdl+INstrafe;
		MtrDrvBL = INdl-INstrafe;
		MtrDrvFR = INdr-INstrafe;
		MtrDrvBR = INdr+INstrafe;
	}

	if (abs(INlift) <= 127) MtrLift = INlift;										//Lift
	else MtrLift	 = UpdatePIDController(PIDLift,		INlift	   - SenLiftPot);	//||||
	MtrConveyor = INconveyor;														//Conveyor
	PIDSpatula.Kp = 0.2;															//Spatula
	if(abs(INspatula) <= 127) MtrSpatula = INspatula;								//|||||||
	else MtrSpatula  = UpdatePIDController(PIDSpatula,  INspatula  - SenSpatPot);	//|||||||
	if(abs(INdescorer) <= 127) MtrDescorer = INdescorer;							//Descorer
	//else MtrDescorer = UpdatePIDController(PIDDescorer, INdescorer - SenDescPot);	//|||||||| //no pot

	if  (INendType == LineUpWhi) // If we're wanting to end up square with a white line
	{
		if (SenLeftEdge  > LineEdge) HaveFoundLeftEdge  = true; // Have we found the left edge?
		if (SenRightEdge > LineEdge) HaveFoundRightEdge = true; // Have we found the right edge?
		if (HaveFoundLeftEdge)	// If we have found the left  edge
		{
			MtrDrvFL = 0; //Make the left  motors stop
			MtrDrvBL = 0;
			MtrDrvFR /= 3; //Make the right motors slow down
			MtrDrvBR /= 3;
		}
		if (HaveFoundRightEdge) // If we have found the right edge
		{
			MtrDrvFL /= 3; //Make the left Motors slow down
			MtrDrvBL /= 3;
			MtrDrvFR = 0; //Make the right motors stop
			MtrDrvBR = 0;
		}
	}
	switch(INendType) // This code asks what type of target condition are we looking for? Have we met it?
	{
		case ResetAuto: AutonomousReset(AutonomousStep); break;
		case TimeLimit:	if(time1(T1) >= INtarget && INtarget != 0)													AutoNextStep();break;
		case EncodStra: if ((INdr > 0) ? (DriveEncoderError > INtarget) : (DriveEncoderError < INtarget))		AutoNextStep();break;
		case EncodTurn: if ((INdr < 0) ? (DriveEncoderError > INtarget) : (DriveEncoderError < INtarget))		AutoNextStep();break;
		//case EncodTurn: if((DriveEncoderError < INtarget)!=(DriveEncoderErrorLast < INtarget))					AutoNextStep();break;
		case LiftPoten: if((PIDLift.Error < INlift-100)!=(PIDLift.LastError < INlift-100))							AutoNextStep();break;
		case SpatPoten: if(abs(SenSpatPot-INtarget) <= 5)															AutoNextStep();break;
		case ScreenBtn: if(nLCDButtons>0		&& (time1(T1) >= INtarget && INtarget != 0))						AutoNextStep();break;
		case ConvSwich:	if(SenConveyerSwitch	&& (time1(T1) >= INtarget && INtarget != 0))						AutoNextStep();break;
		case AbsLeftUS: if((INstrafe > 0) ? (SenLeftUltrasonic  >= INtarget) : (SenLeftUltrasonic  <= INtarget))	AutoNextStep();break;
		case AbsRigtUS: if((INstrafe < 0) ? (SenRightUltrasonic >= INtarget) : (SenRightUltrasonic <= INtarget))	AutoNextStep();break;
		case AbsBackUS: if((INstrafe < 0) ? (SenBackUltrasonic  >= INtarget) : (SenBackUltrasonic  <= INtarget))	AutoNextStep();break;
		case AbsGyrosc: if((INtarget > 0) ? ((SenGyro % 3600) > INtarget) : ((SenGyro % 3600) < INtarget))			AutoNextStep();break;
		case RelGyrosc: if((INtarget > 0) ? ((SenGyro - StepStartGyro) > INtarget) : ((SenGyro - StepStartGyro) < INtarget)) AutoNextStep();break;
		case LineUpWhi: if(HaveFoundLeftEdge && HaveFoundRightEdge)													AutoNextStep();break;
		default://nothing
	}
	if( time1(T1) >= FailsafeMS && INendType != ResetAuto)															AutoNextStep();
	DriveEncoderErrorLast = DriveEncoderError;
}
#endif
