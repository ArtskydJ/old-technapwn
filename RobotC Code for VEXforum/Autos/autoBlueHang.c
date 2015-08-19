void autoBlueHangingZone(void)
	{
	autoResetStart(false);
	//  Left Right Strafe Lift       Intake Type       Target
	auto(FWD, FWD, OFF, L_GRND, IN,  TIME,		3000); //Intake + Drive
	auto(FWD, FWD, OFF, OFF,           OFF, DRIV_READY,	1400); //Drive
	auto(FWD, REV, OFF, L_STSH, OUT, DRIV_READY,	900);  //Lift, Turn, + Outtake
	autoResetEnd();
	}
