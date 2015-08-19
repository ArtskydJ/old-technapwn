//////////////////////
//  Globals.c       //
//  Joseph Dykstra  //
//  VRC team 3018   //
//////////////////////

//Preprocessor Definitions
// *Flags

//X-drive or Mecanum
//Can be modified for H-drive: Output.c -> void output(void)
//To change controls, go to Operator.c -> void operator(void)
#define ENABLE_STRAFING //Comment out if your robot can not strafe
#define ARCADE_DRIVE    //Comment out if you want to use tank drive

// *Functions
#define straight(n)   (n),  (n)
#define turn2(n)      (n),  -(n)
#define turnL(n)      (n),  0
#define turnR(n)      0,    (n)
#define GYRO_P        (float)0.4
#define gyro2(n)      ((n)*10-senGyro)*GYRO_P, (-(n)*10+senGyro)*GYRO_P
#define strafe(n)     0,    0,    (n)
#define strafeEnc(n)	((n)-senLeftEnc)*ENCODER_P
#define stopped()     0,    0,    0
#define ENCODER_P     (float)1.0
#define enc(n,m)      ((n)-senLeftEnc)*ENCODER_P, ((m)-senRightEnc)*ENCODER_P

//Type Definitions
typedef enum
	{
	DISABLED,
	AUTONOMOUS,
	OPERATOR
	} T_MODE;

typedef enum
	{
	AUTO_SELECT,
	DISABLE_MTRS,
	SET_MODE,
	BATT_VALUES,
	ANALOG_SENSORS,
	DIGITAL_SENSORS,
	NO_MENU_ITEMS
	} T_MENU_ITEMS;

typedef enum
	{
	TIME,
	LIFT_READY,
	DRIV_READY,
	FULL_READY,
	LCD_BTN
	} T_END;

typedef enum
	{
	NOT_HIT,
	HIT_NEXT,
	HIT_PID
	} T_HIT;

typedef struct
	{
	float kp;
	float ki;
	float kd;
	int error;
	int errorLast;
	int integral;
	int derivative;
	int output;
	} T_PID;


//Function prototypes
void zeroMotors(void);
void autoResetStart(int INjumpToStep);
void auto(int INleft, int INright, int INstrafe, int INlift, int INintake, T_END INendType, int INtarget);
void autoResetEnd(void);


//Constants
const int FWD = 127;
const int REV = -127;
const int UP = 127;
const int DOWN = -127;
const int IN = 127;
const int OUT = -127;
const int HALF = 64;
const int OFF = 0;

const int NO_AUTOS = 5; //NO = Number Of
int NO_ITEM_SELECTIONS[NO_MENU_ITEMS];

const int L_GRND = FWD+1;
const int L_BUMP = FWD+2;
const int L_STSH = FWD+3;
const int NO_L_PRES =  3; //Num Of Lift Presets
const int L_PRE[NO_L_PRES]={1000,2000,3000}; //Lift Presets

//Variables
T_MODE sysCurrentMode;
bool sysDisabledMode = false;
bool sysAutonomousMode = false;
bool sysMotorsEnabled = true;
int senLiftPot;
int senAutoPot;
int senGyro;
int senLeftEnc;
int senRightEnc;
int targetLeft;
int targetRight;
int targetStrafe;
//int targetForward;
//int targetTurn;
int targetLift;
int targetIntake;
bool senLeftLCDBtn;
bool senCenterLCDBtn;
bool senRightLCDBtn;
bool senLeftLCDBtnLast;
bool senCenterLCDBtnLast;
bool senRightLCDBtnLast;
int joyLXStk;
int joyLYStk;
int joyRXStk;
int joyRYStk;

bool joyLiftUpBtn;
bool joyLiftDownBtn;
bool joyIntakeInBtn;
bool joyIntakeOutBtn;

bool joyLiftUpBtn2;
bool joyLiftDownBtn2;
bool joyIntakeInBtn2;
bool joyIntakeOutBtn2;

int autoRoutine;

string menuItemStrings[NO_MENU_ITEMS];
string menuModeStrings[NO_MENU_ITEMS];
int noItemSelections[NO_MENU_ITEMS];

int timerAuto;
