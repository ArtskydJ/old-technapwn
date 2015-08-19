#define DOWNLOADAUTONOMOUSROUTINES	// AUTONOMOUS SWITCH - FOR COMPETITION THIS SHOULD NOT BE COMMENTED OUT!

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

TAutonomous AutonomousArray[6][32];
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
//#define FIELD11 OtherTripCondition

#define AutoName(V1) AutoNumber++;          \
AutonomousArray[AutoNumber][0].FIELD1 = V1; \
StepNumber = 1

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

int initializeAutonomousArrays();
int initializeAutonomousArray_1();
int initializeAutonomousArray_2();
int initializeAutonomousArray_3();
int initializeAutonomousArray_4();
int initializeAutonomousArray_5();
int initializeAutonomousArray_6();

int AutoNumber = -1;  // AutoName will increment this in order to start with Autonomous 0
int StepNumber = 1;   // Start with Step 1 (Step 0 contains the Autonomous name)


task main()
{
  initializeAutonomousArrays();
}

int initializeAutonomousArrays()
{
	initializeAutonomousArray_1();
	initializeAutonomousArray_2();
	initializeAutonomousArray_3();
	initializeAutonomousArray_4();
	initializeAutonomousArray_5();
	initializeAutonomousArray_6();
	return 0;
}

int initializeAutonomousArray_1()
{
	//       Step                Lift  Intake Drive              Drive       Time- Gyro    Encoder Jump                 Jump
	//       Name                Power Power  Type               Power       out   Degrees Ticks   Condition            ToStep

	AutoName("Red Isolation");
	AutoStep("FetchBall",        0,    0,     STRAIGHT,          FORWARD,    1100, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackUp",           0,    0,     STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
	AutoStep("Lift",             930,  0,     STRAIGHT,          0,          1800, 0,      0,      NOCONDITION,         0 );
	AutoStep("StrafeRight",      930,  0,     STRAFESIDEWAYS,    RIGHT,      200,  0,      0,      NOCONDITION,         0 );
	AutoStep("OneWheelTurn",     930,  0,     LEFTONEWHEELTURN,  FORWARD,    600,  0,      0,      NOCONDITION,         0 );
	AutoStep("DriveIntoGoal",    930,  0,     STRAIGHT,          127,        600,  0,      0,      NOCONDITION,         0 );
	AutoStep("BackUpForOurGoal", 930,  0,     STRAIGHT,          BACKWARD,   290,  0,      0,      NOCONDITION,         0 );
	AutoStep("ReleaseTheMffins", 930,  OUT,   STRAIGHT,          0,          2500, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackUp",           930,  0,     STRAIGHT,          BACKWARD,   150,  0,      0,      NOCONDITION,         0 );
	AutoStep("StrafeLeft",       930,  0,     STRAFESIDEWAYS,    LEFT,       700,  0,      0,      NOCONDITION,         0 );
	AutoStep("TurnRight",        930,  STOP,  BOTHWHEELTURN,     RIGHT,      350,  0,      0,      NOCONDITION,         0 );
	AutoStep("BackUp",           930,  0,     STRAIGHT,          BACKWARD,   0,    0,      0,      NOCONDITION,         0 );
	AutoStep("StrafBrlIntoCrnr", 100,  0,     STRAFESIDEWAYS,    RIGHT,      3100, 0,      0,      NOCONDITION,         0 );
	AutoStep("StrafeBack",       0,    0,     STRAFESIDEWAYS,    LEFT,       1600, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackToStartTile",  -200, 0,     STRAIGHT,          BACKWARD,   800,  0,      0,      NOCONDITION,         0 );
	AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      ANYDISPLAYBUTTON,    18);
	AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         16);
	AutoStep("FetchBall",        0,    IN,    STRAIGHT,          100,        2250, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackUpIntake",     0,    IN,    STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
	AutoStep("BackUpIntakeLift", 950,  IN,    STRAIGHT,          BACKWARD,   1000, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackUpLift",       950,  STOP,  STRAIGHT,          BACKWARD,   2000, 0,      0,      NOCONDITION,         0 );
	AutoStep("HitABtnToGoAgain", 950,  0,     STRAIGHT,          0,          0,    0,      0,      ANYDISPLAYBUTTON,    24);
	AutoStep("HitABtnToGoAgain", 950,  0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         22);
	AutoStep("Outtake",          950,  IN,    STRAIGHT,          0,          5000, 0,      0,      NOCONDITION,         0 );
	AutoStep("Done!",            0,    STOP,  STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	return 0;
}

int initializeAutonomousArray_2()
{
	AutoName("Blue Isolation");
	AutoStep("FetchBall",        0,    0,     STRAIGHT,          FORWARD,    1100, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackUp",           0,    0,     STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
	AutoStep("Lift",             500,  0,     STRAIGHT,          0,          1800, 0,      0,      NOCONDITION,         0 );
	AutoStep("StrafeLeft",       500,  0,     STRAFESIDEWAYS,    LEFT,       200,  0,      0,      NOCONDITION,         0 );
	AutoStep("OneWheelTurn",     500,  0,     RIGHTONEWHEELTURN, FORWARD,    600,  0,      0,      NOCONDITION,         0 );
	AutoStep("DriveIntoGoal",    500,  0,     STRAIGHT,          127,        600,  0,      0,      NOCONDITION,         0 );
	AutoStep("BackUpForOurGoal", 0,    0,     STRAIGHT,          BACKWARD,   290,  0,      0,      NOCONDITION,         0 );
	AutoStep("ReleaseTheMffins", 0,    OUT,   STRAIGHT,          0,          2500, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackUp",           0,    0,     STRAIGHT,          BACKWARD,   150,  0,      0,      NOCONDITION,         0 );
	AutoStep("StrafeRight",      0,    0,     STRAFESIDEWAYS,    RIGHT,      700,  0,      0,      NOCONDITION,         0 );
	AutoStep("TurnLeft",         0,    STOP,  BOTHWHEELTURN,     LEFT,       350,  0,      0,      NOCONDITION,         0 );
	AutoStep("BackUp",           0,    0,     STRAIGHT,          BACKWARD,   0,    0,      0,      NOCONDITION,         0 );
	AutoStep("StrafBrlIntoCrnr", 100,  0,     STRAFESIDEWAYS,    LEFT,       3400, 0,      0,      NOCONDITION,         0 );
	AutoStep("StrafeBack",       0,    0,     STRAFESIDEWAYS,    RIGHT,      1600, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackToStartTile",  -200, 0,     STRAIGHT,          BACKWARD,   800,  0,      0,      NOCONDITION,         0 );
	AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      ANYDISPLAYBUTTON,    18);
	AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         16);
	AutoStep("FetchBall",        0,    IN,    STRAIGHT,          100,        3500, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackUpIntake",     0,    IN,    STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
	AutoStep("BackUpIntakeLift", 500,  IN,    STRAIGHT,          BACKWARD,   1000, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackUpLift",       500,  STOP,  STRAIGHT,          BACKWARD,   2000, 0,      0,      NOCONDITION,         0 );
	AutoStep("HitABtnToGoAgain", 500,  0,     STRAIGHT,          0,          0,    0,      0,      ANYDISPLAYBUTTON,    24);
	AutoStep("HitABtnToGoAgain", 500,  0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         22);
	AutoStep("Outtake",          500,  IN,    STRAIGHT,          0,          5000, 0,      0,      NOCONDITION,         0 );
	AutoStep("Done!",            0,    STOP,  STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	return 0;
}

int initializeAutonomousArray_3()
{
	AutoName("Red Interaction");
	AutoStep("DriveToGoal+Lift", HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    850,  0,      0,      NOCONDITION,         0 );
	AutoStep("Wait",             0,    0,     STRAIGHT,          0,          3000, 0,      0,      NOCONDITION,         0 );
	AutoStep("StrafeAway",       0,    0,     STRAFESIDEWAYS,    LEFT,       100,  0,      0,      NOCONDITION,         0 );
	AutoStep("Rotate 90 Degrees",HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     LEFT,       1200, -650,   0,      NOCONDITION,         0 );
	AutoStep("DriveToGoal",      HIGHGOALHEIGHT,0,     STRAIGHT,          BACKWARD,   1000, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackFromGoal",     HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    200,  0,      0,      NOCONDITION,         0 );
	AutoStep("Outtake",          HIGHGOALHEIGHT,IN,    STRAIGHT,          0,          2750, 0,      0,      NOCONDITION,         0 );
	AutoStep("DriveBackward",    HIGHGOALHEIGHT,0,     STRAIGHT,          BACKWARD,   100,  0,      0,      NOCONDITION,         0 );
	AutoStep("Rotate Back",      HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     LEFT,       1200, -600,   0,      NOCONDITION,         0 );
	AutoStep("DriveToStart",     0,    STOP,  STRAIGHT,          FORWARD,    1500, 0,      0,      NOCONDITION,         0 );
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      LEFTDISPLAYBUTTON,   1 );
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      CENTERDISPLAYBUTTON, 15);
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      RIGHTDISPLAYBUTTON,  22);
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         11);
	AutoStep("Raise Lift",       HIGHGOALHEIGHT,0,     STRAIGHT,          0,          200,  0,      0,      NOCONDITION,         0 );
	AutoStep("DriveToGoal+Lift", HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    1130, 0,      0,      NOCONDITION,         0 );
	AutoStep("WaitForStableBot", HIGHGOALHEIGHT,0,     STRAIGHT,          0,          250,  0,      0,      NOCONDITION,         0 );
	AutoStep("Release Elements", HIGHGOALHEIGHT,OUT,   STRAIGHT,          0,          2750, 0,      0,      NOCONDITION,         0 );
	AutoStep("StopIntake+Pause", HIGHGOALHEIGHT,STOP,  STRAIGHT,          0,          250,  0,      0,      NOCONDITION,         0 );
	AutoStep("BackToStartTile",  HIGHGOALHEIGHT,0,     STRAIGHT,          BACKWARD,   1700, 0,      0,      NOCONDITION,         0 );
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         11);
	AutoStep("DriveToGoal+Lift", 475,  0,     STRAIGHT,          FORWARD,    300,  0,      0,      NOCONDITION,         0 );
	AutoStep("Lift",             475,  0,     STRAIGHT,          0,          800,  0,      0,      NOCONDITION,         0 );
	AutoStep("Outtake",          475,  OUT,   STRAIGHT,          0,          2250, 0,      0,      NOCONDITION,         0 );
	AutoStep("Rotate",           0,    0,     BOTHWHEELTURN,     LEFT,       200,  0,      0,      NOCONDITION,         0 );
	AutoStep("BackToStartTile",  0,    0,     STRAIGHT,          BACKWARD,   500,  0,      0,      NOCONDITION,         0 );
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         11);
	AutoStep("Finished!",        0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	return 0;
}

int initializeAutonomousArray_4()
{

	AutoName("Blue Interaction");
	AutoStep("DriveToGoal+Lift", HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    850,  0,      0,      NOCONDITION,         0 );
	AutoStep("Wait",             0,    0,     STRAIGHT,          0,          3000, 0,      0,      NOCONDITION,         0 );
	AutoStep("StrafeAway",       0,    0,     STRAFESIDEWAYS,    RIGHT,      100,  0,      0,      NOCONDITION,         0 );
	AutoStep("Rotate 90 Degrees",HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     RIGHT,      1200, 650,    0,      NOCONDITION,         0 );
	AutoStep("DriveToGoal",      HIGHGOALHEIGHT,0,     STRAIGHT,          BACKWARD,   1000, 0,      0,      NOCONDITION,         0 );
	AutoStep("BackFromGoal",     HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    200,  0,      0,      NOCONDITION,         0 );
	AutoStep("Outtake",          HIGHGOALHEIGHT,IN,    STRAIGHT,          0,          2750, 0,      0,      NOCONDITION,         0 );
	AutoStep("DriveBackward",    HIGHGOALHEIGHT,0,     STRAIGHT,          BACKWARD,   500,  0,      0,      NOCONDITION,         0 );
	AutoStep("Rotate Back",      HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     RIGHT,      1200, 600,    0,      NOCONDITION,         0 );
	AutoStep("DriveToStart",     0,    STOP,  STRAIGHT,          FORWARD,    1500, 0,      0,      NOCONDITION,         0 );
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      LEFTDISPLAYBUTTON,   1 );
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      CENTERDISPLAYBUTTON, 15);
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      RIGHTDISPLAYBUTTON,  22);
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         11);
	AutoStep("Raise Lift",       HIGHGOALHEIGHT,0,     STRAIGHT,          0,          200,  0,      0,      NOCONDITION,         0 );
	AutoStep("DriveToGoal+Lift", HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    1130, 0,      0,      NOCONDITION,         0 );
	AutoStep("WaitForStableBot", HIGHGOALHEIGHT,0,     STRAIGHT,          0,          250,  0,      0,      NOCONDITION,         0 );
	AutoStep("Release Elements", HIGHGOALHEIGHT,OUT,   STRAIGHT,          0,          2750, 0,      0,      NOCONDITION,         0 );
	AutoStep("StopIntake+Pause", HIGHGOALHEIGHT,STOP,  STRAIGHT,          0,          250,  0,      0,      NOCONDITION,         0 );
	AutoStep("BackToStartTile",  HIGHGOALHEIGHT,0,     STRAIGHT,          BACKWARD,   1700, 0,      0,      NOCONDITION,         0 );
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         11);
	AutoStep("DriveToGoal+Lift", 475,  0,     STRAIGHT,          FORWARD,    300,  0,      0,      NOCONDITION,         0 );
	AutoStep("Lift",             475,  0,     STRAIGHT,          0,          800,  0,      0,      NOCONDITION,         0 );
	AutoStep("Outtake",          475,  OUT,   STRAIGHT,          0,          2250, 0,      0,      NOCONDITION,         0 );
	AutoStep("Rotate",           0,    0,     BOTHWHEELTURN,     RIGHT,      200,  0,      0,      NOCONDITION,         0 );
	AutoStep("BackToStartTile",  0,    0,     STRAIGHT,          BACKWARD,   500,  0,      0,      NOCONDITION,         0 );
	AutoStep("Straf Strait Low", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         11);
	AutoStep("Finished!",        0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	return 0;
}

int initializeAutonomousArray_5()
{
	AutoName("Red InrActn Wait");
	AutoStep("DriveToGoal+Lift", HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    1300, 0,      0,      NOCONDITION,         0 );
	AutoStep("Wait",             0,    0,     STRAIGHT,          0,          3000, 0,      0,      NOCONDITION,         0 );
	AutoStep("StrafeAway",       0,    0,     STRAFESIDEWAYS,    LEFT,       400,  0,      0,      NOCONDITION,         0 );
	AutoStep("Rotate 90 Degrees",HIGHGOALHEIGHT,0,     BOTHWHEELTURN,     RIGHT,      1200, 750,    0,      NOCONDITION,         0 );
	AutoStep("DriveToGoal",      HIGHGOALHEIGHT,0,     STRAIGHT,          FORWARD,    700,  0,      0,      NOCONDITION,         0 );
	AutoStep("Finished!",        0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	return 0;
}

int initializeAutonomousArray_6()
{
	AutoName("No Autonomous");
	AutoStep("Ready to PWN!",    0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
	return 0;
}
