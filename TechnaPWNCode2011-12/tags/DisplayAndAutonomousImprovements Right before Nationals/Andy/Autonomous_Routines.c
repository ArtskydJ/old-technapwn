#define ARRAYNAME AutonomousArray
#define FIELD1  StepName
#define FIELD2  LiftHeight
#define FIELD3  IntakePower
#define FIELD4  DriveType
#define FIELD5  DrivePower
#define FIELD6  Timeout
#define FIELD7  GyroDegrees
#define FIELD8  EncoderTicks
#define FIELD9  JumpCondition
#define FIELD10 JumpToStep
#define AutoName(V1) AutonomousArray[AutoNumber][0].FIELD1 = V1

#define AutoStep(V1, V2, V3, V4, V5, V6, V7, V8, V9, V10) \
AutonomousArray[AutoNumber][StepNumber].FIELD1  = V1;     \
AutonomousArray[AutoNumber][StepNumber].FIELD2  = V2;     \
AutonomousArray[AutoNumber][StepNumber].FIELD3  = V3;     \
AutonomousArray[AutoNumber][StepNumber].FIELD4  = V4;     \
AutonomousArray[AutoNumber][StepNumber].FIELD5  = V5;     \
AutonomousArray[AutoNumber][StepNumber].FIELD6  = V6;     \
AutonomousArray[AutoNumber][StepNumber].FIELD7  = V7;     \
AutonomousArray[AutoNumber][StepNumber].FIELD8  = V8;     \
AutonomousArray[AutoNumber][StepNumber].FIELD9  = V9;     \
AutonomousArray[AutoNumber][StepNumber].FIELD10 = V10;    \
StepNumber++


int initializeAutonomousArray(int AutonRoutine)
{
  int AutoNumber = 0;   // Start with Autonomous 0 Note: We only use AutoNumber 0
  int StepNumber = 1;   // Start with Step 1 (Step 0 contains the Autonomous name)

  //         Step                Lift  Intake Drive              Drive       Time- Gyro    Encoder Jump                 Jump
  //         Name                Power Power  Type               Power       out   Degrees Ticks   Condition            ToStep
 	if (AutonRoutine == 0)
	{
		AutoName("Red Isolation");
		AutoStep("FetchBall",        0,    0,     STRAIGHT,          FORWARD,    1300, 0,      0,      NOCONDITION,         0 );
		AutoStep("BackUp",           0,    0,     RIGHTONEWHEELTURN, BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
		AutoStep("Lift",             873,  0,     STRAIGHT,          0,          4500, 0,      0,      NOCONDITION,         0 );
		AutoStep("StrafeRight",      873,  0,     STRAFESIDEWAYS,    RIGHT,      300,  0,      0,      NOCONDITION,         0 );
		AutoStep("DriveIntoGoal",    873,  0,     STRAIGHT,          127,        1500, 0,      0,      NOCONDITION,         0 );
		AutoStep("LiftMore",         873,  0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         0 );
		AutoStep("ReleaseTheMffins", 873,  OUT,   STRAIGHT,          0,          1200, 0,      0,      NOCONDITION,         0 );
		AutoStep("BackUp",           873,  0,     STRAIGHT,          BACKWARD,   500,  0,      0,      NOCONDITION,         0 );
		AutoStep("StrafeLeft",       873,  0,     STRAFESIDEWAYS,    LEFT,       400,  0,      0,      NOCONDITION,         0 );
		AutoStep("MoreMuffins",      873,  OUT,   STRAIGHT,          0,          500,  0,      0,      NOCONDITION,         0 );
		AutoStep("TurnRight",        873,  STOP,  BOTHWHEELTURN,     RIGHT,      700,  0,      0,      NOCONDITION,         0 );
		AutoStep("BackUp",           873,  0,     STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
		AutoStep("StrafBrlIntoCrnr", 0,    0,     STRAFESIDEWAYS,    RIGHT,      3500, 0,      0,      NOCONDITION,         0 );
		AutoStep("Pause",            0,    0,     STRAIGHT,          0,          200,  0,      0,      NOCONDITION,         0 );
		AutoStep("Rotate",           0,    0,     BOTHWHEELTURN,     LEFT,       100,  0,      0,      NOCONDITION,         0 );
		AutoStep("StrafeBack",       0,    0,     STRAFESIDEWAYS,    LEFT,       2300, 0,      0,      NOCONDITION,         0 );
		AutoStep("RotateMore",       0,    0,     BOTHWHEELTURN,     RIGHT,      0,    0,      0,      NOCONDITION,         0 );
		AutoStep("IntakeBall",       STOP, IN,    STRAIGHT,          FORWARD,    700,  0,      0,      NOCONDITION,         0 );
		AutoStep("IntakeBarrel",     0,    0,     STRAIGHT,          FORWARD,    1000, 0,      0,      NOCONDITION,         0 );
		AutoStep("Done!",            0,    STOP,  STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	}

	else if (AutonRoutine == 1)
	{
AutoName("Blue Isolation");
AutoStep("FetchBall",        0,    0,     STRAIGHT,          FORWARD,    900,  0,      0,      NOCONDITION,         0 );
AutoStep("BackUp",           0,    0,     STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
AutoStep("Lift",             873,  0,     STRAIGHT,          0,          1600, 0,      0,      NOCONDITION,         0 );
AutoStep("StrafeLeft",       873,  0,     STRAFESIDEWAYS,    LEFT,       200,  0,      0,      NOCONDITION,         0 );
AutoStep("OneWheelTurn",     873,  0,     RIGHTONEWHEELTURN, FORWARD,    600,  0,      0,      NOCONDITION,         0 );
AutoStep("DriveIntoGoal",    873,  0,     STRAIGHT,          127,        600,  0,      0,      NOCONDITION,         0 );
AutoStep("ReleaseTheMffins", 873,  OUT,   STRAIGHT,          0,          2200, 0,      0,      NOCONDITION,         0 );
AutoStep("BackUp",           873,  0,     STRAIGHT,          BACKWARD,   300,  0,      0,      NOCONDITION,         0 );
AutoStep("StrafeRight",      873,  0,     STRAFESIDEWAYS,    RIGHT,      700,  0,      0,      NOCONDITION,         0 );
AutoStep("MoreMuffins",      873,  OUT,   STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         0 );
AutoStep("TurnLeft",         873,  STOP,  BOTHWHEELTURN,     LEFT,       350,  0,      0,      NOCONDITION,         0 );
AutoStep("BackUp",           873,  0,     STRAIGHT,          BACKWARD,   0,    0,      0,      NOCONDITION,         0 );
AutoStep("StrafBrlIntoCrnr", 1,    0,     STRAFESIDEWAYS,    LEFT,       2700, 0,      0,      NOCONDITION,         0 );
AutoStep("StrafeBack",       0,    0,     STRAFESIDEWAYS,    RIGHT,      5000, 0,      0,      NOCONDITION,         0 );
AutoStep("BackToStartTile",  0,    0,     STRAIGHT,          BACKWARD,   800,  0,      0,      NOCONDITION,         0 );
AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      ANYDISPLAYBUTTON,    19);
AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         17);
AutoStep("FetchBall",        0,    IN,    STRAIGHT,          FORWARD,    2000, 0,      0,      NOCONDITION,         0 );
AutoStep("BackUp",           0,    STOP,  STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
AutoStep("Done!",            0,    STOP,  STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	}

	else if (AutonRoutine == 2)
	{
AutoName("Interaction");
AutoStep("DriveToGoal+Lift", HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    1500, 0,      0,      NOCONDITION,         0 );
AutoStep("Wait",             0,    0,     STRAIGHT,          0,          3000, 0,      0,      NOCONDITION,         0 );
AutoStep("StrafeAway",       0,    0,     STRAFESIDEWAYS,    RIGHT,      1000, 0,      0,      NOCONDITION,         0 );
AutoStep("Rotate 90 Degrees",HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     LEFT,       0,    -900,   0,      NOCONDITION,         0 );
AutoStep("DriveToGoal",      HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    300,  0,      0,      NOCONDITION,         0 );
AutoStep("Outtake",          HIGHGOALHEIGHT,0,     STRAIGHT,          0,          1500, 0,      0,      NOCONDITION,         0 );
AutoStep("DriveBackward",    HIGHGOALHEIGHT,0,     BACKWARD,          FORWARD,    300,  0,      0,      NOCONDITION,         0 );
AutoStep("Rotate Back",      HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     RIGHT,      400,  0,      0,      NOCONDITION,         0 );
AutoStep("DriveToStartTil",  0,    0,     STRAIGHT,          BACKWARD,   2000, 0,      0,      NOCONDITION,         0 );
AutoStep("Finished!",        0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	}

	else if (AutonRoutine == 3)
	{
		AutoName("No Autonomous");
		AutoStep("Ready to PWN!",    0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	}

	else if (AutonRoutine == 4)
	{
		AutoName("Gyro Test");
		AutoStep("StrafBrlIntoCrnr", 1,    0,     STRAFESIDEWAYS,    LEFT,       2700, 0,      0,      NOCONDITION,         0 );
		AutoStep("StrafeBack",       0,    0,     STRAFESIDEWAYS,    RIGHT,      5000, 0,      0,      NOCONDITION,         0 );
		AutoStep("Done!",            0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
		AutoStep("Turn 90 Degrees",  0,    0,     BOTHWHEELTURN,     127,        6000, 90,     0,      NOCONDITION,         0 );
	}

	return 0;
}
