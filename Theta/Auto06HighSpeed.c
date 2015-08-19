const int auto06[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},		//Reset
{GLPos,	0,		HSPos,	Up,		110,	110,	Left,	700,	TIMELIMIT},	//strafe left and drive forward
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		600,	ENCODSTRA},	//drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 1
{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		-100,	ENCODSTRA},	//back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		100,	ENCODSTRA},	//drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	-250,	GYRSTRAFE},	//strafe
{GLPos,	0,		MSPos,	0,		0,		0,		0,		200,	TIMELIMIT},	//pause for motor slew to rest
{GLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		180,	TIMELIMIT},	//back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		50,		ENCODSTRA},	//drive forward to trough           maybe make this longer
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	TIMELIMIT},	//scoop up bags
{GLPos,	0,		MSPos,	0,		0,		0,		0,		200,	TIMELIMIT},	//back up, start lifting
{TLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		-125,	ENCODSTRA},	//back up, start lifting
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2400,	TIMELIMIT},	//keep lifting
{TLPos,	0,		MSPos,	0,		100,	100,	0,		600,	TIMELIMIT},	//drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		20,		20,		0,		1800,	TIMELIMIT},	//dump sacks

{0,		Fwd,	2800,	0,		-40,	-40,	0,		-300,	ENCODSTRA},	//output bags and backing up

{GLPos,	0,		MSPos,	0,		0,		0,		0,		800,	RELTRNGYR},	//Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		1000,	ENCODSTRA},	//drive forward
{GLPos,	0,		LSPos,	0,		0,		0,		0,		200,	TIMELIMIT},	//Wait
{GLPos,	0,		LSPos,	0,		0,		0,		0,		-880,	RELTRNGYR},	//Gyro Spin

//{GLPos,	0,		LSPos,	0,		0,		0,		0,		600,	TIMELIMIT},	//wait for lift
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		500,	ENCODSTRA},	//drive forward
{GLPos,	0,		Up,		Down,	0,		0,		0,		700,	TIMELIMIT},	//scoop up bags in pyramid part 2
{GLPos,	0,		MSPos,	0,		-90,	-90,		0,		1000,	TIMELIMIT},	//back up, start lifting

{    0,	0,		     0,	0,	      0,      0,	0,	       0,	RESETAUTO}};	//Autonomous is done
