//void pre_auton();
//task autonomous()
//task usercontrol();
task display_handler();
task motor_test();
task pick_autonomous();
task show_variables();
task settings_menu();
task UpdatePIDControllers();

void initializeTimers();
int initializeDisplay();
int initializeGyro();
int initializeAutonomous();
int initializeOperator();
int initializeAutonomousArray(int AutonRoutine);
int getInput();
int processAutonomous();
int processOperator();
void LiftHeightButtonsCheck(int CurrentButtonState, int &WasAlreadyPressed, TGoalHeightButton &LastGoalHeightButton, TGoalHeightButton LastGoalHeightButtonValue, GoalHeight);
int operatorDriveTrain();
int operatorLift();
int operatorIntake();
int operatorTines();
int initializePID();
void PIDController(TPidSystem &PIDObject);
void DisplayMainMenu();
void DisplayMenu(string MenuTitle, string MenuItem);
void DisplayButtonHandling();
int IsMenuItemActivated();
int CheckJoystick();
void ToggleCheck (int CurrentButtonState, int &WasAlreadyPressed, int &ToBeToggled);
void RangeCheck (int LowerLimit, int &Value, int UpperLimit);
int WasPressedOnce(int CurrentButtonState, int &WasAlreadyPressed);
int SlopeLimiter(int OldValue, int NewValue, int MaxStepSize);
int doOutput();
