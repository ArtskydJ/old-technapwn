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


int initializeAutonomousArray()
{
	int AutoNumber = -1;  // AutoName will increment this in order to start with Autonomous 0
	int StepNumber = 1;   // Start with Step 1 (Step 0 contains the Autonomous name)

	//       Step                Lift  Intake Drive              Drive       Time- Gyro    Encoder Jump                 Jump
	//       Name                Power Power  Type               Power       out   Degrees Ticks   Condition            ToStep
#ifdef DOWNLOADAUTONOMOUSROUTINES
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

AutoName("Blue Isolation");
AutoStep("FetchBall",        0,    0,     STRAIGHT,          FORWARD,    1100, 0,      0,      NOCONDITION,         0 );
AutoStep("BackUp",           0,    0,     STRAIGHT,          BACKWARD,   250,  0,      0,      NOCONDITION,         0 );
AutoStep("Lift",             620,  0,     STRAIGHT,          0,          2300, 0,      0,      NOCONDITION,         0 );
AutoStep("StrafeLeft",       621,  0,     STRAFESIDEWAYS,    LEFT,       220,  0,      0,      NOCONDITION,         0 );
AutoStep("OneWheelTurn",     622,  0,     RIGHTONEWHEELTURN, FORWARD,    600,  0,      0,      NOCONDITION,         0 );
AutoStep("DriveIntoGoal",    623,  0,     STRAIGHT,          127,        650,  0,      0,      NOCONDITION,         0 );
AutoStep("ReleaseTines",     0,    0,     TINES,             EXTENDED,   0,    0,      0,      NOCONDITION,         0 );
AutoStep("ReleaseTheMffins", 0,    OUT,   STRAIGHT,          0,          2100, 0,      0,      NOCONDITION,         0 );
AutoStep("RetractTines",     0,    0,     TINES,             RETRACTED,  0,    0,      0,      NOCONDITION,         0 );
AutoStep("BackUpStopIntake", 0,    STOP,  STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
AutoStep("StopAndOuttake",   0,    OUT,   STRAIGHT,          0,          800,  0,      0,      NOCONDITION,         0 );
AutoStep("BackUpOuttake",    0,    0,     STRAIGHT,          BACKWARD,   120,  0,      0,      NOCONDITION,         0 );
AutoStep("StrafeRight",      0,    0,     STRAFESIDEWAYS,    RIGHT,      700,  0,      0,      NOCONDITION,         0 );
AutoStep("TurnLeft",         0,    STOP,  BOTHWHEELTURN,     LEFT,       350,  0,      0,      NOCONDITION,         0 );
AutoStep("BackUp",           0,    0,     STRAIGHT,          BACKWARD,   0,    0,      0,      NOCONDITION,         0 );
AutoStep("StrafBrlIntoCrnr", 100,  0,     STRAFESIDEWAYS,    LEFT,       3000, 0,      0,      NOCONDITION,         0 );
AutoStep("StrafeBack",       0,    0,     STRAFESIDEWAYS,    RIGHT,      1700, 0,      0,      NOCONDITION,         0 );
AutoStep("BackToStartTile",  1,    0,     STRAIGHT,          BACKWARD,   800,  0,      0,      NOCONDITION,         0 );
AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      ANYDISPLAYBUTTON,    21);
AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         19);
AutoStep("FetchBall",        0,    IN,    STRAIGHT,          100,        3500, 0,      0,      NOCONDITION,         0 );
AutoStep("BackUpIntake",     0,    IN,    STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
AutoStep("BackUpIntakeLift", 600,  IN,    STRAIGHT,          BACKWARD,   500,  0,      0,      NOCONDITION,         0 );
AutoStep("BackUpLift",       600,  STOP,  STRAIGHT,          BACKWARD,   1000, 0,      0,      NOCONDITION,         0 );
AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      ANYDISPLAYBUTTON,    27);
AutoStep("HitABtnToGoAgain", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         25);
AutoStep("Outtake",          600,  IN,    STRAIGHT,          0,          5000, 0,      0,      NOCONDITION,         0 );
AutoStep("Done!",            0,    STOP,  STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );

AutoName("Inter Tall Short");
AutoStep("Raise Lift",       660,  0,     STRAIGHT,          0,          1000, 0,      0,      NOCONDITION,         0 );
AutoStep("DriveToGoal+Lift", 660,  0,     STRAIGHT,          BACKWARD,   1300, 0,      0,      NOCONDITION,         0 );
AutoStep("Release Elements", 0,    IN,    STRAIGHT,          0,          3500, 0,      0,      NOCONDITION,         0 );
AutoStep("BackToStartTile",  0,    STOP,  STRAIGHT,          FORWARD,    1300, 0,      0,      NOCONDITION,         0 );
AutoStep("Low         High", 0,    0,     STRAIGHT,          0,          0,    0,      0,      LEFTDISPLAYBUTTON,   11);
AutoStep("Low         High", 0,    0,     STRAIGHT,          0,          0,    0,      0,      RIGHTDISPLAYBUTTON,  8 );
AutoStep("Low         High", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         5 );
AutoStep("DriveToGoal",      0,    0,     STRAIGHT,          BACKWARD,   1000, 0,      0,      NOCONDITION,         0 );
AutoStep("Release Elements", 0,    IN,    STRAIGHT,          0,          3500, 0,      0,      NOCONDITION,         0 );
AutoStep("BackToStartTile",  0,    STOP,  STRAIGHT,          FORWARD,    1300, 0,      0,      NOCONDITION,         5 );
AutoStep("LowerLift",        80,   0,     STRAIGHT,          0,          1100, 0,      0,      NOCONDITION,         0 );
AutoStep("DriveToLowGoal",   0,    0,     STRAIGHT,          BACKWARD,   200,  0,      0,      NOCONDITION,         0 );
AutoStep("Release Elements", 0,    IN,    STRAIGHT,          0,          3500, 0,      0,      NOCONDITION,         0 );
AutoStep("BackToStartTile",  0,    STOP,  STRAIGHT,          FORWARD,    300,  0,      0,      NOCONDITION,         5 );
AutoStep("Low         High", 0,    0,     STRAIGHT,          0,          0,    0,      0,      LEFTDISPLAYBUTTON,   12);
AutoStep("Low         High", 0,    0,     STRAIGHT,          0,          0,    0,      0,      RIGHTDISPLAYBUTTON,  1 );
AutoStep("Low         High", 0,    0,     STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         15);
AutoStep("Finished!",        0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );

AutoName("IsolationHigh");
AutoStep("Lift",             620,  0,     STRAIGHT,          0,          2500, 0,      0,      NOCONDITION,         0 );
AutoStep("ScoreFromBack",    0,    IN,    STRAIGHT,          0,          2500, 0,      0,      NOCONDITION,         0 );
AutoStep("Pause",            0,    STOP,  STRAIGHT,          0,          500,  0,      0,      NOCONDITION,         0 );
AutoStep("LowerLift",        2,    0,     STRAIGHT,          0,          2300, 0,      0,      NOCONDITION,         0 );
AutoStep("Pause",            0,    0,     STRAIGHT,          0,          1500, 0,      0,      NOCONDITION,         0 );
AutoStep("DriveToBarrel",    0,    0,     STRAIGHT,          FORWARD,    150,  0,      0,      NOCONDITION,         0 );
AutoStep("IntakeBarrel",     0,    IN,    STRAIGHT,          40,         1200, 0,      0,      NOCONDITION,         0 );
AutoStep("DriveToBall",      0,    STOP,  STRAIGHT,          FORWARD,    150,  0,      0,      NOCONDITION,         0 );
AutoStep("IntakeBall",       0,    IN,    STRAIGHT,          40,         1200, 0,      0,      NOCONDITION,         0 );
AutoStep("FinishIntaking",   0,    0,     STRAIGHT,          0,          800,  0,      0,      NOCONDITION,         0 );
AutoStep("Raise Lift",       780,  STOP,  STRAIGHT,          0,          1000, 0,      0,      NOCONDITION,         0 );
AutoStep("BackToStartTile",  0,    STOP,  STRAIGHT,          0,          0,    0,      0,      NOCONDITION,         0 );
AutoStep("Done!",            0,    STOP,  STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );

	AutoName("No Autonomous");
	AutoStep("Ready to PWN!",    0,    0,     STRAIGHT,          0,          -1,   0,      0,      NOCONDITION,         0 );
#endif
	return 0;
}
