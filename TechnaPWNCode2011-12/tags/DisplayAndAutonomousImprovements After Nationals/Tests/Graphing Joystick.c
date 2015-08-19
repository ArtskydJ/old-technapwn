int x1, y1;
int x2, y2;
int h1, h2;
task main()
{
	writeDebugStream("X1,   Y1,   H1,   X2,   Y2,   H2\n");
	while(true)
	{
		x1 = vexRT[Ch4];
		y1 = vexRT[Ch3];
		h1 = sqrt(x1*x1 + y1*y1);

		x2 = vexRT[Ch1];
		y2 = vexRT[Ch2];
		h2 = sqrt(x2*x2 + y2*y2);

		writeDebugStream("%d, %d, ", x1, y1);
		writeDebugStream("%d,        ", h1);
		writeDebugStream("%d, %d, ", x2, y2);
		writeDebugStream("%d\n", h2);
		wait1Msec(12);
	}
}
