#pragma config(Motor,  port3,           ,              tmotorNormal, openLoop)
#pragma config(Motor,  port4,           ,              tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int x;
	int y;
	while (true)
	{
		x = vexRT[Btn5U] * 127;
		y = vexRT[Btn5D] * -127;
		if (x)
		{
			motor[port3] = x;
			motor[port4] = 0 - x;
		}
		else if (y)
		{
			motor[port3] = y;
			motor[port4] = 0 - y;
		}
		else
		{
			motor[port3] = 0;
			motor[port4] = 0;
		}
	}
}
