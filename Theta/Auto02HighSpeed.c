const int auto02[][]={ //New Two (not used, not working after picking up wall)
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},		//Reset
//{-100,	0,		Up,		127,	0,		0,		Left,	-001,	ENCODTURN},	//strafe right, lower spatula
{-100,	0,		LSPos,	Up,		0,		0,		0,		0200,	TIMELIMIT},	//Descorer Up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0700,	ENCODSTRA},	//drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		-100,	ENCODSTRA},	//drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	250,	RIGTULGYR},	//strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0600,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-80,	ENCODSTRA},	//drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	600,	RIGTULGYR},	//strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		550,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-100,	ENCODSTRA},	//drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		-1760,	RELTRNGYR},	//Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		850,	ENCODSTRA},	//drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	TIMELIMIT},	//scoop bags under trough
{0,		50,		LSPos,	0,		Rev,	Rev,	0,		-250,	ENCODSTRA},	//back up and raise lift
{ULPos,	0,		MSPos,	0,		0,		0,		0,		3000,	TIMELIMIT},	//raise lift
{TLPos,	50,		MSPos,	0,		Fwd,	Fwd,	0,		200,	ENCODSTRA},	//drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		0,		2000,	TIMELIMIT},	//Outtake
{TLPos,	Fwd,	0,		0,		Rev,	Fwd,	0,		100,	TIMELIMIT},	//back up
//{TLPos,-50,	0,		0,		Fwd,	Fwd,	0,		200,	TIMELIMIT},	//Push in
{GLPos,	Fwd,	LSPos,	0,		Rev,	Rev,		0,		-1100,	ENCODSTRA},	//back up
//{GLPos,Fwd,	LSPos,	0,		0,		0,		Right,	900,	TIMELIMIT},	//strafe onto tile
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};	//Reset
