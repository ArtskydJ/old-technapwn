task main()
{
	int i;
	displayLCDString(0, 0, "Motor Test");
	displayLCDString(1, 0, "MTR:   PWR:     ");
	for(i = 1; i <= 10; i++)
	{
		displayLCDString(1, 4, "   ");
		displayLCDNumber(1, 5, i, 0);
		displayLCDNumber(1, 12, 127);
		motor[i] = 127;
		wait1Msec(750);
		displayLCDString(1, 12, "    ");
		displayLCDNumber(1, 12, 0, 0);
		motor[i] = 0;
		wait1Msec(250);
		displayLCDString(1, 12, "    ");
		displayLCDNumber(1, 12, -127, 0);
		motor[i] = -127;
		wait1Msec(750);
		displayLCDString(1, 12, "    ");
		displayLCDNumber(1, 12, 0, 0);
		motor[i] = 0;
		wait1Msec(250);
	}
}
