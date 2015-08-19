//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#ifdef _SIMULATED
	#include "Vex_Techna_PWN_Debug_Includes.c"			//Debug code - enable
#else
	#include "Vex_Competition_Includes.c"				//Main competition background code...do not modify!
#endif

//Constants
#define LIFTENCODERCONSTANT 1
#define DRIVEENCODERCONSTANT 1
#define FLOORHEIGHT -100
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

//Enums
typedef enum
{
	PLAIN,
	EXPERIMENT
} TDriveAlgorithm;

typedef enum
{
	NORMAL,
	REVERSED
} TRobotDirection;

typedef enum
{
	RETRACTED,
	EXTENDED
} TTinesPosition;

typedef enum
{
	NOGOALBUTTON,
	LOWGOALBUTTON,
	MIDDLEGOALBUTTON,
	HIGHGOALBUTTON
} TGoalHeightButton;

typedef enum
{
  AUTOADVANCE,
  MANUALADVANCE
} TAutonomousAdvanceMode;

typedef enum
{
  SETUPSTEP,
  DOSTEP,
  PAUSEMOTORS,
  WAITFORADVANCE
} TAutonomousState;

typedef enum
{
  DISPLAYMENU,
  DISPLAYDISABLED
} TDisplayState;

typedef enum
{
  CHOOSINGSETTING,
  EDITINGSETTING
} TSettingsMenuMode;


//---------------------------------------------< Structs >-----------------------------------------------

typedef struct
{
	float Kp;
	float Ki;
	float Kd;
	float Integral;
	float Derivative;
	float Error;
	float LastError;
	float TargetValue;
	float TargetPower;
	float Output;
} TPidSystem;
