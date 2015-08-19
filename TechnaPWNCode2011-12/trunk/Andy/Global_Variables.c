// btn = Button (Input), stk = Stick (Input), pneu = Pneumatics (Output), motor = Motor (Output)

//Inputs

//Joystick inputs
float stkDriveX;                      								//Current X value of drive stick (-127 to 127)
float stkDriveY;							 		                    //Current Y value of drive stick (-127 to 127)
float stkDriveS;
int stkLift1;
int stkLift2;

//Button inputs
int btnLiftUp1;
int btnLiftDown1;
//int btnOldNewDrive;							                      	//Old/New-Drive Joystick Button
int btnFrontBackDrive;
int btnIntakeIn1;
int btnIntakeOut1;
int btnIntakeIn2;
int btnIntakeOut2;
int btnLiftEncoderReset1;
int btnLiftEncoderReset2;
int btnLiftLowGoal1;
int btnLiftMiddleGoal1;
int btnLiftHighGoal1;
int btnLiftLowGoal2;
int btnLiftMiddleGoal2;
int btnLiftHighGoal2;
int btnStepThroughAutonomous;
int btnLiftStallBypass;
int btnTines;

//Sensor inputs
int gyrGyroscope;
int LeftLineFollower;
int RightLineFollower;
int LeftDisplayButton;
int CenterDisplayButton;
int RightDisplayButton;
/*int LeftLiftEncoder;
int RightLiftEncoder;*/
/*int LeftDriveEncoder;
int RightDriveEncoder;*/
int LiftEncoder;
int VariableEncoder;
int LeftDriveIntegratedEncoder;
int RightDriveIntegratedEncoder;
int LiftIntegratedEncoder;
int BottomLeftLiftLimitSwitch;
int BottomRightLiftLimitSwitch;

//Outputs
int RawMotor[10];
int motorLeftFrontDrive;
int motorLeftBackDrive;
int motorRightFrontDrive;
int motorRightBackDrive;
int motorLiftLeftTop;
int motorLiftLeftBottom;
int motorLiftRightTop;
int motorLiftRightBottom;
int motorIntakeFront;
int motorIntakeBack;
int physical_motorLeftFrontDrive;
int physical_motorLeftBackDrive;
int physical_motorRightFrontDrive;
int physical_motorRightBackDrive;
int physical_motorLiftLeftTop;
int physical_motorLiftLeftBottom;
int physical_motorLiftRightTop;
int physical_motorLiftRightBottom;
int physical_motorIntakeFront;
int physical_motorIntakeBack;
int old_motorLeftFrontDrive;
int old_motorLeftBackDrive;
int old_motorRightFrontDrive;
int old_motorRightBackDrive;
int old_motorLiftLeftTop;
int old_motorLiftLeftBottom;
int old_motorLiftRightTop;
int old_motorLiftRightBottom;
int old_motorIntakeFront;
int old_motorIntakeBack;
int DriveMaxSlewStep = DRIVEMAXSLEWSTEPCONSTANT;
int LiftMaxSlewStep = LIFTMAXSLEWSTEPCONSTANT;
int IntakeMaxSlewStep = INTAKEMAXSLEWSTEPCONSTANT;

//Computational
float JoystickMax;
float JoystickPower;
float MainBatteryVoltageAverage;
float MainBatteryVoltageLevel;
int LiftPower;
int ButtonBitMap;
//int btnOldNewDrivePressed;							//Old/New-Drive Joystick Button Pressed Variable
TDriveAlgorithm OldNewDrive = PLAIN;
int btnFrontBackDrivePressed;
TRobotDirection FrontBackDrive = NORMAL;
int btnLiftLowGoal1Pressed;
int btnLiftMiddleGoal1Pressed;
int btnLiftHighGoal1Pressed;
int btnLiftLowGoal2Pressed;
int btnLiftMiddleGoal2Pressed;
int btnLiftHighGoal2Pressed;
int btnTinesPressed;
TGoalHeightButton LastGoalHeightButton1;
TGoalHeightButton LastGoalHeightButton2;
int LiftTargetHeight;
int LiftToPresetHeight;
int LeftDisplayButtonPressed;
int CenterDisplayButtonPressed;
int RightDisplayButtonPressed;
int ActivateMenuItem = 0;
int DisplayNeedsRefreshing = 1;
int CurrentMenu = 0;
int CurrentMenuItem = 0;
int TotalMenuItems;
//int MenuStack[64];
const int NumOfAutonomusRoutines = 6;
string MainMenu[7] = {"Run Autonomous", "Pick Autonomous", "Motor Test", "Show Variables", "Settings", "Edit Autonomous", "Make Autonomous"};
string AutonomousMenu[NumOfAutonomusRoutines] = {"Red Isolation", "Blue Isolation", "Red Interaction", "BlueIntrStraight", "Red InrActn Wait", "RedIsolatioTines"};
TPidSystem PIDLift;
TPidSystem PIDGyro;
int AutonomousStep = 0;
int AutonomousRoutine = DEFAULTAUTOROUTINE;
int LockInAutonomous = 0;
int EnableOutput = 1;
TAutonomousAdvanceMode AutonomousAdvanceMode = AUTOADVANCE; //MANUALADVANCE; //AUTOADVANCE;
TAutonomousState AutonomousState = SETUPSTEP;
TDisplayState DisplayState = DISPLAYMENU;
TTinesPosition TinesPosition = RETRACTED;
bool LiftStallDetectorIsEnabled = false;
int LiftStallDetectorTimeLastRun100Msec = 0;
int LiftMotorDuration100Msec = 0;
int LiftMotorBreakPeriod100Msec = LIFTMOTORBREAKPERIOD100MSECCONSTANT;
int LiftMotorCoolDownStart100Msec = 0 - LIFTMOTORCOOLDOWNPERIOD100MSECCONSTANT;
int LiftMotorCoolDownPeriod100Msec = LIFTMOTORCOOLDOWNPERIOD100MSECCONSTANT;
TDisplayBacklightState DisplayBacklightState = BACKLIGHTON;
int LastBacklightBlink100Msec = 0;
int OldLiftEncoder = 0;
