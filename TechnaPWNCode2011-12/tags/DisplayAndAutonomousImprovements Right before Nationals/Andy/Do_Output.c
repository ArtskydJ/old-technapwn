int doOutput()
{
	int ErrorCode = 0;

	if (FrontBackDrive == NORMAL)
	{
		physical_motorLeftFrontDrive = motorLeftFrontDrive;
		physical_motorLeftBackDrive = motorLeftBackDrive;
		physical_motorRightFrontDrive = motorRightFrontDrive;
		physical_motorRightBackDrive = motorRightBackDrive;

		physical_motorIntakeFront = motorIntakeFront;
		physical_motorIntakeBack = motorIntakeFront;
	}
	else
	{
		physical_motorRightBackDrive = 0 - motorLeftFrontDrive;
		physical_motorRightFrontDrive = 0 - motorLeftBackDrive ;
		physical_motorLeftBackDrive = 0 - motorRightFrontDrive;
		physical_motorLeftFrontDrive = 0 - motorRightBackDrive;

		physical_motorIntakeFront = 0 - motorIntakeFront;
		physical_motorIntakeBack = 0 - motorIntakeBack;

	}
	physical_motorLiftLeftTop = motorLiftLeftTop;
	physical_motorLiftLeftBottom = motorLiftLeftBottom;
	physical_motorLiftRightTop = motorLiftRightTop;
	physical_motorLiftRightBottom = motorLiftRightBottom;

	RawMotor[DriveFL] += SlopeLimiter(RawMotor[DriveFL], physical_motorLeftFrontDrive, DriveMaxSlewStep);
  RawMotor[DriveBL] += SlopeLimiter(RawMotor[DriveBL], physical_motorLeftBackDrive, DriveMaxSlewStep);
	RawMotor[DriveFR] += SlopeLimiter(RawMotor[DriveFR], physical_motorRightFrontDrive, DriveMaxSlewStep);
	RawMotor[DriveBR] += SlopeLimiter(RawMotor[DriveBR], physical_motorRightBackDrive, DriveMaxSlewStep);

	RawMotor[LiftFL] += SlopeLimiter(RawMotor[LiftFL], physical_motorLiftLeftTop, LiftMaxSlewStep);
  RawMotor[LiftBL] += SlopeLimiter(RawMotor[LiftBL], physical_motorLiftLeftBottom, LiftMaxSlewStep);
	RawMotor[LiftFR] += SlopeLimiter(RawMotor[LiftFR], physical_motorLiftRightTop, LiftMaxSlewStep);
	RawMotor[LiftBR] += SlopeLimiter(RawMotor[LiftBR], physical_motorLiftRightBottom, LiftMaxSlewStep);

	RawMotor[IntakeL] += SlopeLimiter(RawMotor[IntakeL], physical_motorIntakeFront, IntakeMaxSlewStep);
  RawMotor[IntakeR] += SlopeLimiter(RawMotor[IntakeR], physical_motorIntakeBack, IntakeMaxSlewStep);

	for (int i = 0; i < 10; i++)
	{
	  motor[i] = RawMotor[i];
	}
  SensorValue[TinesPort] = TinesPosition
	return ErrorCode;
}
