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

	#define GYROSTRAFEP 2
	#define MinLoopMS 5
	#define NumOfAutoRoutines 9
	#define NumOfMenuItems 7
	#define NmOfAutNmStrs 3
	#define NumOfTimeRecords 100
	#define LowLiftKillTimeoutMS 6000
	#define JoystickDZ 20
	#define LineEdge 1800
	#define FloorTile 1400
	#define FloorLine 2500
	/* Dark	Light
	1400 - 2500
	1950 - middle */
//Directional definitions for the motors
	#define Up    127
	#define Down -127
	#define Fwd   127
	#define Rev  -127
	#define Right 127
	#define Left -127
	//Autonomous definitions for easy creation of automomous code
	#define Start 0
	#define Finish 1
////////// - AUTONOMOUS END TYPE NAMES - //////////
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
//Wait Times
#define FailsafeMS 4000
#define NextMessageCharMS 250
#define Cc 2

////////// - ARRAY INDICE NAMES - //////////
//Preset lift heights
#define pLow       0
#define pMedium    1
#define pCutOff    1
#define pHigh      2
#define pTrough    2
#define pUltraHigh 3
#define pAutLift   0
#define pDrvLift   1
#define pSpatula   2
#define pDescorer  3
//Slew constants
#define slDrive 0
#define slLift  1
#define slSpatula 2
#define slConveyor 3
#define slDescorer 4
#define kUser 0
#define kAuto 1
//Joysticks
#define jDrvX    0
#define jDrvY    1
#define jDrvZ    2
#define jMtrTest 3
//Buttons
#define bConveyorFwd        00
#define bConveyorRev        01
#define bDriveStyle         02
#define bLiftHigh           03
#define bSubroutineSelect   04
#define bLiftGround         05
#define bLiftUp             06
#define bLiftDown           07
#define bSpatulaUp          08
#define bSpatulaDown        09
#define bDescorerUp         10
#define bDescorerDown       11
#define bDisablePots        12
#define bAutonFromDriver    13
#define bHalfSpeed          14
//#define bLiftMidDescoreLow  15
//#define bDriveType          16
//Screen buttons
#define sbLeft   0
#define sbCenter 1
#define sbRight  2
//Sensors
#define sLiftPot                      00
#define sAutoPot                      01
#define sGyro                         02
#define sDriveEncoderBackLeft         03
#define sDriveEncoderBackRight        04
#define sDrivenMotorEncoderBackLeft   05
#define sDrivenMotorEncoderBackRight  06
#define sDriveEncoderAvg              07
#define sDriveEncoderDif              08
#define sSpatPot                      09
#define sDescPot                      10
#define sLeftLine                     11
#define sRightLine                    12
#define sLeftEdge                     13
#define sRightEdge                    14
#define sLeftUltrasonic               15
#define sRightUltrasonic              16
#define sBackUltrasonic               17
#define sConveyerSwitch               18
//Motors
#define mDrvFL     0
#define mDrvBL     1
#define mDrvFR     2
#define mDrvBR     3
#define mLift      4
#define mSpatula   5
#define mConveyor  6
#define mDescorer  7
//LCD Strings
#define Top    0
#define Bottom 1
#define Curr   0
#define Last   1

int  Stk[4];
bool Btn[2][14];
bool Btn2[2][14];
bool sBtn[2][3];
int  Sen[18];
int  Mtr[7];
float slewedMtr[7];
string LCD[2][2] = {"", "", "", ""};
int AutoTimeRecord[NumOfTimeRecords];
int TestMotorEnabled[10]={0,0,0,0,0,0,0,0,0,0};
string BatteryLevel[2];

const int preset[4][4] =
	{{600,1539,2425,2600},
	{1130,1150,2689,2866},
	{450, 1025,1895,1895},
	{1232,2300,3503,3503}};

const float Slew[2][5] =
	{{3,10,	10,	5,	1},
	{3,	10,	40,	5,	5}};
	
const string AutoName[NumOfAutoRoutines][NmOfAutNmStrs]={
	//Names of each of our Autonomous routines
	"Left--Under trou","gh in it; 2 wall"," on tile-27   ",		//1
	"Right-Pyramid & ","yellow in trough","-40   ",				//2
	"Left--8 Wall & u","nder trough in t","rough-65   ",		//3
	"Right-Pyramid & ","under trough in ","trough-45   ",		//4
	"TESTS   TESTS   ","TESTS   TESTS   ","TESTS   TESTS   ",	//5
	"Right-Pyramid & ","under trough in ","it, descore-45   ",	//6
	"Test--PID Straig","ht   Test--PID S","traight   ",			//7
	"Right-Autonomous","/Programming Ski","lls-240   ",			//8
	"Right-Autonomous","/Programming Ski","lls-185   "};		//9
const string MenuItemName[NumOfMenuItems]={
	"Autonomous: ",		//1 (case 0)
	"Dis/Enable Mtrs",
	"Battery Levels:",
	"Motor Test:",
	"Motor Test:",
	"Analog Value:",
	"Digital Value:"};

//Computational
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
bool bSimulatedAutonomousMode = false;
bool bSimulatedRobotDisabled = true;
bool LastRobotInAutonomousMode;
bool LastRobotDisabled;
bool DriveStyle;
bool MotorsAreEnabled = true;
bool PotsAreEnabled = true;
bool AutonIsOnTheClock = false;
bool HaveFoundLeftEdge = false;
bool HaveFoundRightEdge = false;
bool bItemActivated = false;
bool bSpatDownPressed = false;
bool IsRobotInVirtualAutonomousMode = false;
bool HasLiftUpBeenReleasedWhileHigh = false;

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