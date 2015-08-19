//Constants
#define LIFTENCODERCONSTANT 1
#define DRIVEENCODERCONSTANT 1
#define FLOORHEIGHT 0
#define LOWGOALHEIGHT 475
#define MIDDLEGOALHEIGHT 755
#define ISOLATIONGOALHEIGHT 873
#define HIGHGOALHEIGHT 1300 //1145
#define JOYSTICKDRIVEMAX 127
#define MOTORDRIVEMAX 127
#define JOYSTICKDEADZONE 20
#define MOTORRAMPCONSTANT 0.005
#define DISPLAYDELAYMS 50
#define PIDDELAYMS 10
#define DRIVEMAXSLEWSTEPCONSTANT 1
#define LIFTMAXSLEWSTEPCONSTANT 1
#define INTAKEMAXSLEWSTEPCONSTANT 5
#define INTEGRALCAP 10
#define IN 127
#define OUT -127
#define UP 127
#define DOWN -127
#define FORWARD 127
#define BACKWARD -127
#define LEFT -127
#define RIGHT 127
#define STOP 128

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
  ANYDISPLAYBUTTON = 23
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

TAutonomous AutonomousArray[1][25];
TAutonomous CurrentStep;

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
AutoStep("FetchBall",        0,    0,     STRAIGHT,          FORWARD,    900,  0,      0,      NOCONDITION,         0 );
AutoStep("BackUp",           0,    0,     STRAIGHT,          BACKWARD,   90,   0,      0,      NOCONDITION,         0 );
AutoStep("Turn",             0,    0,     BOTHWHEELTURN,     LEFT,       200,  0,      0,      NOCONDITION,         0 );
AutoStep("Lift",             873,  0,     STRAIGHT,          0,          1200, 0,      0,      NOCONDITION,         0 );
AutoStep("StrafeLeft",       873,  0,     STRAFESIDEWAYS,    RIGHT,      400,  0,      0,      NOCONDITION,         0 );
AutoStep("DriveIntoGoal",    873,  0,     STRAIGHT,          127,        1000, 0,      0,      NOCONDITION,         0 );
AutoStep("ReleaseTheMffins", 873,  OUT,   STRAIGHT,          0,          2000, 0,      0,      NOCONDITION,         0 );
AutoStep("BackUp",           873,  0,     STRAIGHT,          BACKWARD,   300,  0,      0,      NOCONDITION,         0 );
AutoStep("StrafeRight",      873,  0,     STRAFESIDEWAYS,    LEFT,       700,  0,      0,      NOCONDITION,         0 );
AutoStep("MoreMuffins",      873,  OUT,   STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         0 );
AutoStep("TurnLeft",         873,  STOP,  BOTHWHEELTURN,     RIGHT,      350,  0,      0,      NOCONDITION,         0 );
AutoStep("BackUp",           873,  0,     STRAIGHT,          BACKWARD,   0,    0,      0,      NOCONDITION,         0 );
AutoStep("StrafBrlIntoCrnr", 1,    0,     STRAFESIDEWAYS,    RIGHT,      3200, 0,      0,      NOCONDITION,         0 );
AutoStep("StrafeBack",       0,    0,     STRAFESIDEWAYS,    LEFT,       2100, 0,      0,      NOCONDITION,         0 );
AutoStep("BackToStartTile",  0,    0,     STRAIGHT,          BACKWARD,   500,  0,      0,      NOCONDITION,         0 );
AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      ANYDISPLAYBUTTON,    18);
AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         16);
AutoStep("FetchBall",        0,    IN,    STRAIGHT,          FORWARD,    2000, 0,      0,      NOCONDITION,         0 );
AutoStep("BackUp",           0,    STOP,  STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
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
AutoName("Red Interaction");
AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      LEFTDISPLAYBUTTON,   6 );
AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      CENTERDISPLAYBUTTON, 17);
AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      RIGHTDISPLAYBUTTON,  0 );
AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         1 );
AutoStep("",                 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         0 );
AutoStep("DriveToGoal+Lift", HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    1300, 0,      0,      NOCONDITION,         0 );
AutoStep("Wait",             0,    0,     STRAIGHT,          0,          3000, 0,      0,      NOCONDITION,         0 );
AutoStep("StrafeAway",       0,    0,     STRAFESIDEWAYS,    LEFT,       400,  0,      0,      NOCONDITION,         0 );
AutoStep("Rotate 90 Degrees",HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     RIGHT,      1200, 750,    0,      NOCONDITION,         0 );
AutoStep("DriveToGoal",      HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    700,  0,      0,      NOCONDITION,         0 );
AutoStep("Outtake",          HIGHGOALHEIGHT,OUT,   STRAIGHT,          0,          2000, 0,      0,      NOCONDITION,         0 );
AutoStep("DriveBackward",    HIGHGOALHEIGHT,0,     STRAIGHT,          BACKWARD,   700,  0,      0,      NOCONDITION,         0 );
AutoStep("Rotate Back",      HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     LEFT,       1200, -750,   0,      NOCONDITION,         0 );
AutoStep("DriveToStartTil",  0,    0,     STRAIGHT,          BACKWARD,   2000, 0,      0,      NOCONDITION,         0 );
AutoStep("",                 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         0 );
AutoStep("Raise Lift",       HIGHGOALHEIGHT,0,     STRAIGHT,          0,          200,  0,      0,      NOCONDITION,         0 );
AutoStep("DriveToGoal+Lift", HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    1130, 0,      0,      NOCONDITION,         0 );
AutoStep("WaitForStableBot", HIGHGOALHEIGHT,0,     STRAIGHT,          0,          250,  0,      0,      NOCONDITION,         0 );
AutoStep("Release Elements", HIGHGOALHEIGHT,OUT,   STRAIGHT,          0,          2750, 0,      0,      NOCONDITION,         0 );
AutoStep("StopIntake+Pause", HIGHGOALHEIGHT,STOP,  STRAIGHT,          0,          250,  0,      0,      NOCONDITION,         0 );
AutoStep("BackToStartTile",  HIGHGOALHEIGHT,0,     STRAIGHT,          BACKWARD,   1700, 0,      0,      NOCONDITION,         0 );
AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         1 );
AutoStep("Finished!",        0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	}

	else if (AutonRoutine == 3)
	{
AutoName("Blue Interaction");
AutoStep("DriveToGoal+Lift", HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    1300, 0,      0,      NOCONDITION,         0 );
AutoStep("Wait",             0,    0,     STRAIGHT,          0,          3000, 0,      0,      NOCONDITION,         0 );
AutoStep("StrafeAway",       0,    0,     STRAFESIDEWAYS,    RIGHT,      400,  0,      0,      NOCONDITION,         0 );
AutoStep("Rotate 90 Degrees",HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     LEFT,       1200, -750,   0,      NOCONDITION,         0 );
AutoStep("DriveToGoal",      HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    700,  0,      0,      NOCONDITION,         0 );
AutoStep("Outtake",          HIGHGOALHEIGHT,OUT,   STRAIGHT,          0,          2000, 0,      0,      NOCONDITION,         0 );
AutoStep("DriveBackward",    HIGHGOALHEIGHT,0,     BACKWARD,          FORWARD,    700,  0,      0,      NOCONDITION,         0 );
AutoStep("Rotate Back",      HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     RIGHT,      1200, 750,    0,      NOCONDITION,         0 );
AutoStep("DriveToStartTil",  0,    0,     STRAIGHT,          BACKWARD,   2000, 0,      0,      NOCONDITION,         0 );
AutoStep("Finished!",        0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	}

	else if (AutonRoutine == 4)
	{
		AutoName("No Autonomous");
		AutoStep("Ready to PWN!",    0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	}

	else if (AutonRoutine == 5)
	{
		AutoName("No Autonomous");
		AutoStep("Ready to PWN!",    0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	}

	else if (AutonRoutine == 6)
	{
		AutoName("Gyro Test");
		AutoStep("Turn 90 Degrees",  0,    0,     BOTHWHEELTURN,     -127,        6000, -900,     0,      NOCONDITION,         0 );
		AutoStep("Done!",            0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	}

	return 0;
}

task main()
{
  initializeAutonomousArray(0);
}
