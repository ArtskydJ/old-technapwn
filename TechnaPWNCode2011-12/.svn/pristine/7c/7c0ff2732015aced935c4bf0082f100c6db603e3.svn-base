void pre_auton()
{
	initializeTimers();
	initializeDisplay();
	initializePID();
	initializeGyro();
	initializeAutonomousArray(AutonomousRoutine);
	StartTask(pick_autonomous);
#ifdef _SIMULATED
	while (bSimulatedRobotDisabled)
#else
	while (bIfiRobotDisabled)						//Keep letting Autonomous be selected while robot is disabled
#endif
  {
    getInput();
  }
	StopTask(pick_autonomous);
	AutonomousRoutine = CurrentMenuItem;
	CurrentMenuItem = 0;
	CurrentMenu = 0;
	DisplayNeedsRefreshing = 1;
	StartTask(display_handler);
}
