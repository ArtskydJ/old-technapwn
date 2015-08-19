//This portion of the code is intended to contain all of our variable declarations and definitions from the rest of our code.

//Definitions
	//#define BEEP
	#define LIFTCLICK
	#ifdef COMPETITION
		#define IsRobotInAutonomousMode bIfiAutonomousMode
		#define IsRobotDisabled bIfiRobotDisabled
	#else
		#define IsRobotInAutonomousMode bSimulatedAutonomousMode
		#define IsRobotDisabled bSimulatedRobotDisabled
	#endif

	#define CapValue(Min,Value,Max) Value = (Value<Min)? Min:Value; Value = (Value>Max)? Max:Value
	#define PotPosition(Max) (SenAutoPot/(4096/Max))

	//#define autonomous(n) auto##n
	/*
	#define SlopeFilter(Mtr,LMtr,Limit) \
	do{\
		if (Mtr-LMtr>Limit) Mtr= Limit;\
		if (Mtr-LMtr<Limit) Mtr=-Limit;\
	}while(0)
	*/
	/*
	#define SlopeFilter(LastValue,Value,Slew) \
		CapValue(LastValue-Slew,Value,LastValue+Slew)
	*/
	#define GYROSTRAFEP 2
	#define MinLoopMS 5
	#define NumOfAutoRoutines 9
	#define NumOfMenuItems 7
	#define NmOfAutNmStrs 3
	#define NumOfTimeRecords 100
	#define LowLiftKillTimeoutMS 6000
	#define JoystickDZ 20
	#define LineEdge 1800
	#define LeftLineFolTile  1280 //Low
	#define LeftLineFolLine  2400 //High
	#define RightLineFolTile 1460
	#define RightLineFolLine 3600
	//#define SenLeftLineHa 1290
	//#define SenRightLineHa 3000
	/*
	How our scaled values work:
		H = High = LINE
		L = Low  = TILE
		I = Input = SENSOR
	(2000*((I-L)/(H-L)))-1000
	{ 2000*(I-L)/(H-L) } -1000
	*/
	#define LeftLineFolScaled  ((2000*(SenLeftLine  - LeftLineFolTile))   / (LeftLineFolLine  - LeftLineFolTile)-1000)
	#define RightLineFolScaled ((2000*(SenRightLine - RightLineFolTile))  / (RightLineFolLine - RightLineFolTile)-1000)
	float IntLeftLineFolScaled = 1;
	float IntRightLineFolScaled = 1;
	#define FloorEdgeLineup 2700
	/* Dark	Light
	1400 - 2500
	1950 - middle */
//Directional definitions for the motors
	#define Up 127
	#define Down -127
	#define Fwd 127
	#define Rev -127
	#define Right 127
	#define Left -127
	//Autonomous definitions for easy creation of automomous code
	#define Start 0
	#define Finish 1
#ifndef ET
	#define RESETAUTO 0  // Autonomous Done (End of array)
	#define TIMELIMIT 1  // Time limit
	#define LIFTPOTEN 2  // Lift Potentiometer
	#define RELTRNGYR 3  // Turn Relative Gyroscope
	#define ENCODSTRA 4  // Encoder Straight
	#define ENCODTURN 5  // Encoder Turn
	#define SPATPOTEN 6  // Spatula Potentiometer
	#define	WHITELINE 7  // Until white Line
	#define SCREENBTN 8  // Screen Button
	#define PIDSTRAIG 9  // PID Straight
	#define CONVSWICH 10 // Conveyer switch
	#define GYRSTRAFE 11 // Gyro Strafe
	//#define TURNAGYRO 12 // Turn Absolute Gyroscope
	//#define RUSRSTRAF 13 // Right Ultrasonic Relative Strafe
	//#define BCKULTSTR 14 // Drive to PID Back Ultra
	#define LEFTULGYR 15 // Strafe until Ultrasonic Left with Gyro
	#define RIGTULGYR 16 // Strafe until Ultrasonic Right with Gyro
	#define BACKULSTR 17 // Straight until Ultrasonic Back
	#define ABSTRNGYR 18 // Absolute gyro turn
	#define SQUAREUPG 19 // Square up Gyro
	#define WALL_L	128
	#define WALL_R	129
	#define LINE	130
#else
//END TYPES
	#define ResetAuto	00	// Autonomous Done (End/Start of array)
	#define TimeLimit	01	// Time limit
	//#define DriveType	02	// Use the end type (RelGyrTrn)
	#define EncodStra	03	// Straight Encoder
	#define EncodTurn	04	// Turn     Encoder
	#define LiftPoten	05	// Lift    Potentiometer
	#define SpatPoten	06	// Spatula Potentiometer
	#define ScreenBtn	07	// Screen   Button
	#define ConvSwich	08	// Conveyer Button
	#define AbsLeftUS	09	// Absolute Left  Ultrasonic
	#define AbsRigtUS	10	// Absolute Right Ultrasonic
	#define AbsBackUS	11	// Absolute Back  Ultrasonic
	#define RelLeftUS	12	// Relative Left  Ultrasonic
	#define RelRigtUS	13	// Relative Right Ultrasonic
	#define RelBackUS	14	// Relative Back  Ultrasonic
	#define AbsGyrosc	15	// Turn Absolute Gyroscope
	#define RelGyrosc	16	// Turn Relative Gyroscope
	#define	LineUpWhi	17	// Line up on white line
//DRIVE TYPES
	#define NoDriving	00	// No Driving
	#define DriveNorm	01	// Drive
	#define PIDStraig	02	// PID Straight
	#define PIDGyrosc	03	// PID Gyroscope
	#define GyrSqreUp	04	// Gyro Square up
	#define GyrStrafe	05	// Gyro Strafe
	#define FllwWallL	06	// Follow the Left  Wall
	#define FllwWallR	07	// Follow the Right Wall
	#define FllwLineC   08	// Follow the Center Line
#endif

/*-------------Cheat Sheet-------------*\
|*  ResetAuto =	NoDriving,	ResetAuto  *|
|*  TimeLimit =	DriveNorm,	TimeLimit  *|
|*  EncodStra =	DriveNorm,	EncodStra  *|
|*  EncodTurn =	DriveNorm,	EncodTurn  *|
|*  ScreenBtn =	NoDriving,	ScreenBtn  *|
|*  AbsLeftUS =	GyrStrafe,	AbsLeftUS  *|
|*  RelGyrosc =	PIDGyrosc,	RelGyrosc  *|
\*-------------------------------------*/

	/*
	#define TL 1 // Time limit
	#define LP 2 // Lift Potentiometer
	#define DG 3 // Drive Gyroscope
	#define ES 4 // Encoder Straight
	#define ET 5 // Encoder Turn
	#define SP 6 // Spatula Potentiometer
	#define	WL 7 // Until white Line
	#define SB 8 // Screen Button
	#define PS 9 // PID Straight
	*/
//Preset lift heights
	#define GLPos 1100 //600 //270 //330
	#define MLPos 1745 //1539 //1235
	#define TLPos 2690 //2425 //3000 //3200
	#define ULPos 2866 //2600 //3000 //3200

	#define DriverGLPos 1130 //700 //270 //330
	#define DriverMLPos 1150 //820 //1235
	#define DriverTLPos 2689 //2400 //3000 //3200
	#define DriverULPos 2866 //2600 //3000 //3200

	#define LiftCatchPos 2700
	#define LiftHighSpatUp ((TLPos+MLPos)/2)
//Preset spatula heights
	#define LSPos 450 //2325 //2265 //720  //1510
	#define MSPos 1025 //2900 //2500 //1500 //2200
	#define HSPos 1895 //3770 //3580 //2480 //3921

//Preset decorer heights
	/*#define HDPos 3503 //2585
	#define TDPos 2300 //1200
	#define LDPos 1232 //479 */
//Wait Times
	#define FailsafeMS 4000
	#define NextMessageCharMS 250
	#define Cc 2

//Enums
typedef enum
{
	LiftUp,
	LiftDown
} TLiftDirection;

typedef enum
{
	Center,
	Left0,
	Left1
} TLCDPos;

typedef enum
{
	DispDriverMode,
	DispDisabledMode,
	DispAutonomousMode,
} TDisplayMode;

typedef enum
{
	DriverJoystickControl,
	DriverMotorTest,
	DriverSubPyramid,
	DriverSubDescore
} TDriverMode;

//Structs
typedef struct
{
	float Kp;
	float Ki;
	float Kd;
	int Error;
	int Integral;
	int Derivative;
	int LastError;
	int Output;
}	TPID;
/*
typedef struct //Setting means power setting if between -127 and 127, or else Potentiometer PID Target.
{
	int LiftSetting;
	int ConveyorPower;
	int SpatulaSetting;
	int DescorerSetting;
	int LeftDrivePower;
	int RightDrivePower;
	int StrafeDrivePower;
	int TriggerValue;
	int TriggerCondition;
	int TimeOut;
}	TAutonomousStep;
*/
TLiftDirection LastLiftDirection = LiftDown;
TLCDPos DisplayPosition = Left0;
TDriverMode DriverMode = DriverJoystickControl;

TPID PIDLineFollower;
TPID PIDDescorer;
TPID PIDWallFollower;
TPID PIDLift;
TPID PIDSpatula;
TPID PIDDriveStraight;
TPID PIDDriveGyro;

//Integer variables
//Controller 1
	int StkDrvX;
	int StkDrvY;
	int StkDrvZ;
	int StkMtrTest;
//Sensors
	int SenLiftPot;
	int SenAutoPot;
	int SenGyro;
	int SenDriveEncoderBackLeft = 0;
	int SenDriveEncoderBackRight = 0;
	int SenDrivenMotorEncoderBackLeft = 0;
	int SenDrivenMotorEncoderBackRight = 0;
	int SenDriveEncoderAvg;
	int SenDriveEncoderDif;
	int SenSpatPot;
	//int SenDescPot;
	int SenLeftLine  = 0;
	int SenRightLine = 0;
	int SenLeftEdge  = 0;
	int SenRightEdge = 0;
	int SenLeftUltrasonic; //SenLeftUSDistance;
	int SenRightUltrasonic; //SenRightUSDistance;
	int SenBackUltrasonic;
	int SenConveyerSwitch;
//Motors
	int MtrDrvFL;
	int MtrDrvBL;
	int MtrDrvFR;
	int MtrDrvBR;
	int MtrLift;
	int MtrSpatula;
	int MtrConveyor;
	int MtrDescorer;
//Computational
	int LastBtnDriveStyle;
	int AutonomousStep = 0;
	int LastAutonomousRoutine = 0; //Different
	int AutonomousRoutine = 1;
	int LiftTarget = 0;
	int SpatulaTarget = 0;
	int DescorerTarget;
	int DriveEncoderError;
	int DriveEncoderErrorLast;
	int DriveEncoderStartAvg;
	int DriveEncoderStartDif;
	int StepStartGyro = 0;
	int ScrollStringIndex = 0;
	int ScrollCharIndex = 0;
	int LastMenuItem=0;
	int MenuItem=0;
	int LastMotorSlewTime = nSysTime;
	int DeltaMotorSlewTime = 0;
	int MainLoopTime = 0;
	int MainNonDelayedLoopTime = 0;
	int LastGyro = 0;
	int AbsoluteGyro = 0;
	int AddToAbsGyro = 0;
	int StartTimeLiftLow = nSysTime;
//Float variables
//Computational
	float StkPower;
	float StkSin;
	float StkCos1;
	float StkCos2;
	float StkEstPower;
	float StkTheta;
	float AutonTimer = 0;
	float DriveSlewConstant    = 3;		//2; // 0.1; //2
	float LiftSlewConstant     = 10;	//1; //0.1; //1
	float SpatulaSlewConstant  = 10;	//3; //0.1; //3
	float ConveyorSlewConstant = 5;		//3; //0.1; //3
	float DescorerSlewConstant = 3;		//3; //0.1; //3
	float AutonDriveSlewConstant    = 3;	//2; // 0.1; //2
	float AutonLiftSlewConstant     = 10;	//1; //0.1; //1
	float AutonSpatulaSlewConstant  = 40;	//3; //0.1; //3
	float AutonConveyorSlewConstant = 5;	//3; //0.1; //3
	float AutonDescorerSlewConstant = 5;	//3; //0.1; //3
	/*float AutoDriveSlewConstant = 2;		//0.1; //2
	float AutoLiftSlewConstant = 1;			//0.1; //1
	float AutoSpatulaSlewConstant = 3;		//0.1; //3
	float AutoConveyorSlewConstant = 3;		//0.1; //3
	float AutoDescorerSlewConstant = 3;		//0.1; //3*/

//Boolean variables
//Controller 1
	bool BtnConveyorFwd;
	bool BtnConveyorRev;
	bool BtnDriveStyle = 0;
	bool BtnLiftHigh;
	bool BtnSubroutineSelect;
	bool BtnLiftUp;
	bool BtnLiftDown;
	bool LastBtnLiftUp;
	bool LastBtnLiftDown;
	bool BtnSpatulaUp;
	bool BtnSpatulaDown;
	bool BtnDescorerUp;
	bool BtnDescorerDown;
	bool BtnDisablePots;
	bool BtnAutonFromDriver;
	bool BtnHalfSpeed;
	//bool BtnLiftMidDescoreLow;
//Controller 2
	bool BtnConveyorFwd2;
	bool BtnConveyorRev2;
	bool BtnLiftUp2;
	bool BtnLiftDown2;
	bool LastBtnLiftUp2;
	bool LastBtnLiftDown2;
	bool BtnSpatulaUp2;
	bool BtnSpatulaDown2;
	bool BtnLiftHigh2;
	bool BtnLiftGround2;
	bool BtnDescorerUp2;
	bool BtnDescorerDown2;
//Screen buttons
	bool BtnScreenLeft = 0;
	bool LastBtnScreenLeft = 0;
	bool BtnScreenCenter = 0;
	bool LastBtnScreenCenter = 0;
	bool BtnScreenRight = 0;
	bool LastBtnScreenRight = 0;
//Computational
	bool bSimulatedAutonomousMode = true;
	bool bSimulatedRobotDisabled = true;
	bool LastRobotInAutonomousMode;
	bool LastRobotDisabled;
	//bool RefreshTopLCDLine = true;
	//bool RefreshBottomLCDLine = true;
	bool DriveStyle;
	bool MotorsAreEnabled = true;
	bool AutonIsOnTheClock = false;
	bool HaveFoundLeftEdge = false;
	bool HaveFoundRightEdge = false;
	bool bItemActivated = false;
	bool bSpatDownPressed = false;
	bool IsRobotInVirtualAutonomousMode = false;
	/*bool StartAutonFromDriver = false;
	bool AutonIsDone = true;
	bool DescoreSubroutine = false;
	bool PyramidSubroutine = false;
	bool TestMotorsSubroutine = false;*/
	//bool IsGoingUnderTrough = false;
//String variables
	string TopLCDLine = "";
	string LastTopLCDLine = "";
	string BottomLCDLine = "";
	string LastBottomLCDLine = "";

//ARRAYS
	//int AutoStep[9];
	int AutoTimeRecord[NumOfTimeRecords];
	float SlewedMotor[10];
	int TestMotorEnabled[10]={0,0,0,0,0,0,0,0,0,0};
	string BatteryLevel[2];
const string AutoName[NumOfAutoRoutines][NmOfAutNmStrs]={
	//Names of each of our Autonomous routines
	"Left--Under trou","gh in it; 2 wall"," on tile-27   ",		//1
	"Right-Pyramid & ","yellow in trough","-40   ",				//2
	"Left--8 Wall & u","nder trough in t","rough-65   ",		//3
	"Right-Pyramid & ","under trough in ","trough-45   ",		//4
	"TESTS   TESTS   ","TESTS   TESTS   ","TESTS   TESTS   ",	//5
	"Right-Pyramid & ","under trough in ","it, descore-45   ",	//6
	"Test--PID Straig","ht"				 ,"   ",				//7
	"Right-Autonomous","/Programming"," Skills-240   ",			//8
	"Right-Autonomous","/Programming Ski","lls-185   "};		//9
const string MenuItemName[NumOfMenuItems]={
	"Autonomous: ",		//1 (case 0:)
	"Dis/Enable Mtrs",
	"Battery Levels:",
	"Motor Test:",
	"Motor Test:",
	"Analog Value:",
	"Digital Value:"};
