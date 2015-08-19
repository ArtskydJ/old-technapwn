const int auto03[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},		//Reset
//{-100,	0,		Up,		127,	0,		0,		Left,	-001,	ENCODTURN},	//strafe right, lower spatula
{-100,	0,		LSPos,	127,	0,		0,		0,		0200,	TIMELIMIT},	//Descorer Up
{GLPos,	0,		LSPos,	HDPos,	100,	127,	0,		0800,	ENCODSTRA},	//drive forward, spatula down
{GLPos,	0,		Up,		HDPos,	0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		-150,	ENCODSTRA},	//drive backward
{GLPos,	Rev,	LSPos,	0,		0,		0,		Right,	250,	LEFTULGYR},	//strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		100,	100,	0,		0600,	TIMELIMIT},	//drive forward
{GLPos,	Rev,		Up, 	0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-150,	ENCODSTRA},	//drive backward
{GLPos,	Rev,	LSPos,	0,		0,		0,		Right,	600,	LEFTULGYR},	//strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		Fwd,	Fwd,	0,		600,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	TIMELIMIT},	//scoop up sacks
//{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-1,		ENCODSTRA},	//drive backward
{GLPos,	Rev,	MSPos,	0,		0,		0,		0,		860,	RELTRNGYR},	//Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		850,	ENCODSTRA},	//drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	TIMELIMIT},	//scoop bags under trough
{0,		50,		LSPos,	0,		Rev,	Rev,	0,		-250,	ENCODSTRA},	//back up and raise lift
{TLPos,	0,		MSPos,	0,		0,		0,		0,		3000,	TIMELIMIT},	//raise lift
{TLPos,	50,		MSPos,	0,		Fwd,	Fwd,	0,		200,	ENCODSTRA},	//drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		0,		2000,	TIMELIMIT},	//Outtake
//{TLPos,	-50,	0,		0,		Fwd,	Fwd,	0,		200,	TIMELIMIT},	//Push in
{TLPos,	Fwd,	LSPos,	0,		Rev,	-70,		0,		-1300,	ENCODSTRA},	//back up
//{GLPos,	Fwd,	LSPos,	0,		0,		0,		Right,	900,	TIMELIMIT},	//strafe onto tile

{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};	//Reset

/*
{GLPos,	0,		Up,		127,	0,		0,		Left,	-001,	ENCODTURN},	//strafe right, lower spatula
{GLPos,	0,		LSPos,	127,	0,		0,		0,		0200,	TIMELIMIT},	//Descorer Up
{GLPos,	0,		LSPos,	HDPos,	Fwd,	Fwd,	0,		0800,	ENCODSTRA},	//drive forward, spatula down
{GLPos,	0,		Up,		HDPos,	0,		0,		0,		0700,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-250,	ENCODSTRA},	//drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	0720,	ENCODTURN},	//strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		Fwd,	Fwd,	0,		0500,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0600,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-300,	ENCODSTRA},	//drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	0500,	ENCODTURN},	//strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		Fwd,	Fwd,	0,		750,	TIMELIMIT},	//drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0700,	TIMELIMIT},	//scoop up sacks
{GLPos,	0,		MSPos,	0,		Fwd,	Rev,	0,		-920,	ENCODTURN},	//turn
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		1050,	ENCODSTRA},	//drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0500,	TIMELIMIT},	//scoop bags under trough
{TLPos,	50,		LSPos,	0,		Rev,	Rev,	0,		-250,	ENCODSTRA},	//back up and raise lift
{TLPos,	0,		LSPos,	0,		0,		0,		0,		2500,	TIMELIMIT},	//raise lift
{TLPos,	50,		LSPos,	0,		Fwd,	Fwd,	0,		200,	ENCODSTRA},	//drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		40,		1900,	TIMELIMIT},	//Outtake
{TLPos,	Rev,	0,		0,		Fwd,	Fwd,	0,		300,	TIMELIMIT},	//Push in
{TLPos,	Fwd,	0,		0,		Rev,	Rev,	0,		800,	TIMELIMIT},	//back up
*/
