// btn = Button (Input), stk = Stick (Input), pneu = Pneumatics (Output), motor = Motor (Output)

//Inputs

//Joystick inputs
float stkDriveX;                      								//Current X value of drive stick (-127 to 127)
float stkDriveY;							 		                    //Current Y value of drive stick (-127 to 127)
float stkDriveS;
int stkLift1;
int stkLift2;

//Button inputs
int btnLiftTopUp2;
int btnLiftTopDown2;
int btnLiftBottomUp2;
int btnLiftBottomDown2;
int btnLiftUp1;
int btnLiftDown1;
int btnOldNewDrive;							                      	//Old/New-Drive Joystick Button
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
int btnTines;

//Sensor inputs
int gyrGyroscope;
int LeftDisplayButton;
int CenterDisplayButton;
int RightDisplayButton;
/*int LeftLiftEncoder;
int RightLiftEncoder;*/
/*int LeftDriveEncoder;
int RightDriveEncoder;*/
int LiftEncoder;
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
int motorRampedLeftFrontDrive;
int motorRampedLeftBackDrive;
int motorRampedRightFrontDrive;
int motorRampedRightBackDrive;
int LiftUp;
int LiftDown;
int DriveMaxSlewStep = DRIVEMAXSLEWSTEPCONSTANT;
int LiftMaxSlewStep = LIFTMAXSLEWSTEPCONSTANT;
int IntakeMaxSlewStep = INTAKEMAXSLEWSTEPCONSTANT;
int pneuTines;

//Computational
float JoystickMax;
float JoystickPower;
float MainBatteryVoltageAverage;
float MainBatteryVoltageLevel;
int LiftPower;
int ButtonBitMap;
int btnOldNewDrivePressed;							//Old/New-Drive Joystick Button Pressed Variable
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
string MainMenu[7] = {"Run Autonomous", "Pick Autonomous", "Motor Test", "Show Variables", "Settings", "Edit Autonomous", "Make Autonomous"};
string AutonomousMenu[5] = {"Red Isolation", "Blue Isolation", "Interaction", "No Autonomous", "GyroTest"};
TPidSystem PIDLift;
TPidSystem PIDGyro;
int ReadyForNextAutonomousStep = 1;
int NumOfAutonomusRoutines = 5;
int AutonomousStep = 0;
int AutonomousRoutine = 2;
int LockInAutonomous = 0;
int EnableOutput = 1;
TAutonomousAdvanceMode AutonomousAdvanceMode = AUTOADVANCE;
TAutonomousState AutonomousState = SETUPSTEP;
TDisplayState DisplayState = DISPLAYMENU;
TTinesPosition TinesPosition = RETRACTED;
