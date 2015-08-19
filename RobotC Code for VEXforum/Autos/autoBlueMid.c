void autoBlueMiddleZone(void)
	{
	autoResetStart(false);
	//  Left Right Strafe LiftIntake Type       Target
	auto(FWD,	FWD,	OFF,	UP, 			IN,		TIME,		3000); //Intake + Drive
	auto(FWD,	FWD,	OFF,	OFF,			OFF,	DRIV_READY,	1400); //Drive
	auto(FWD,	REV,	OFF,	DOWN,			OUT,	DRIV_READY,	900);  //Lift, Turn, + Outtake
	autoResetEnd();
	}
