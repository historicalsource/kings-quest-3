[logics for room 74 -- The throne room of Daventry Castle
[	February 19, 1988

%include	"gamedefs.reh"
%include	"rm74.msg"



[	This is it.  The big finish!  (thank God).



[%view	v.hugging				 69
[%view	v.king				 71
[%view	v.queen				 72
[%view	v.princess			 73
[%view	v.catching.venture.cap	 75
[%view	v.cartoon.stuff		187


%define	l.ego.catching			0
%define	l.princess.catching		1

%define	l.king.hugging.ego		0
%define	l.queen.hugging.ego		1
%define	l.king.hugging.girl		2
%define	l.queen.hugging.girl	3

%define	l.mirror.clearing		0
%define	l.mirror.sparkling		1
%define	l.venture.cap			2


%define	nextScript			lf0
%define	soundDone				lf1
%define	stopKing				lf2
%define	stopQueen				lf3
%define	stopPrincess			lf4
%define	stopEgo				lf5


%define	roomScript			lv0
%define	scriptTimer			lv1


%object	aRosella				1
%object	aKing				2
%object	aQueen				3
%object	aMirror				4
%object	aCap					5



if (init.log)
	{
	set.horizon( 34);
	prevent.input();
	program.control();

	load.sound( m.winner);
	load.view( v.ego);
	load.view( v.princess);
	load.view( v.king);
	load.view( v.queen);
	load.view( v.princess);
	load.view( v.cartoon.stuff);
	load.view( v.catching.venture.cap);
	load.view( v.hugging);			[	regardless of the number

	
	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	set.view( ego, v.ego);
	position( ego, 149, 122);
	draw( ego);
	move.obj( ego, 82, 122, 1, done);


	animate.obj( aRosella);
	position( aRosella, 152, 109);
	set.view( aRosella, v.princess);
	set.loop( aRosella, facing.left);
	ignore.objs( aRosella);
	draw( aRosella);
	move.obj( aRosella, 82, 109, 1, nextScript);

	animate.obj( aKing);
	position( aKing, 38, 91);
	set.view( aKing, v.king);
	set.loop( aKing, facing.right);
	set.cel( aKing, 3);
	stop.cycling( aKing);
	ignore.block( aKing);
	ignore.obj( aKing);
	draw( aKing);

	animate.obj( aQueen);
	position( aQueen, 42, 85);
	set.view( aQueen, v.queen);
	set.loop( aQueen, facing.right);
	set.cel( aQueen, 3);
	stop.cycling( aQueen);
	draw( aQueen);
	ignore.block( aQueen);
	ignore.obj( aQueen);

	animate.obj( aMirror);
	position( aMirror, 63, 54);
	set.view( aMirror, v.cartoon.stuff);
	set.loop( aMirror, l.mirror.clearing);
	set.cel( aMirror, 0);
	stop.cycling( aMirror);
	work = 4;
	cycle.time( aMirror, work);
	draw( aMirror);
	stop.update( aMirror);

	animate.obj( aCap);
	position( aCap, 16, 89);
	set.view( aCap, v.cartoon.stuff);
	set.loop( aCap, l.venture.cap);
	fix.loop( aCap);
	set.cel( aCap, 0);
	ignore.block( aCap);
	ignore.obj( aCap);
	draw( aCap);
	stop.update( aCap);

	scriptTimer = 2;

	set( soundDone);

	show.pic();

	return();
	
	}							[	end INIT.LOG


prevent.input();
program.control();

if (spell.cast)					[ don't let magic work
	{
	print( 16);
	spell.cast = 0;
	}


[*****
:no.input
[*****

if (aSecondPassed)
	{
	--scriptTimer;
	if (scriptTimer == 1)
		{
		set( nextScript);
		}
	}


if (nextScript)
	{
	reset( nextScript);
	++roomScript;

	if (roomScript == 1)
		{
		print(1);
		scriptTimer = 3;
		}

	if (roomScript == 2)
		{
		print(2);
		}

	if (roomScript == 3)
		{
		start.cycling( aKing);
		start.cycling( aQueen);
		start.cycling( aRosella);
		start.cycling( ego);
		move.obj(    aQueen, 45,  85, 1,   nextScript);	[	3 pixel move
		move.obj(  aRosella, 66,  93, 1, stopPrincess);	[	16
		move.obj(     aKing, 50, 103, 1,     stopKing);	[	12 pixel move
		move.obj(       ego, 63, 103, 1,   nextScript);	[	19
		}

	if (roomScript == 4)
		{
		start.cycling( aQueen);
		move.obj(    aQueen, 53,  93, 1,    stopQueen);	[	8 pixel move
		}

	if (roomScript == 5)
		{
		start.cycling( aKing);
		start.cycling( aQueen);
		start.cycling( aRosella);
		start.cycling( ego);
		move.obj( aRosella, 63,  93, 1, stopPrincess);	[	3
		move.obj(   aQueen, 57,  93, 1,   nextScript);	[	4 pixel move
		move.obj(    aKing, 54, 103, 1,     stopKing);	[	4 pixel move
		move.obj(      ego, 60, 103, 1,      stopEgo);	[	3
		}

	if (roomScript == 6)
		{
		stop.cycling( aQueen);
		print(3);
		scriptTimer = 3;
		}

	if (roomScript == 7)
		{
		start.cycling( aQueen);
		work = 3;
		cycle.time( aQueen, work);
		set.view( aQueen, v.hugging);
		set.loop( aQueen, l.queen.hugging.girl);
		set.cel( aQueen, 2);
		erase( aRosella);

		start.cycling( aKing);
		work = 4;
		cycle.time( aKing, work);
		set.view( aKing, v.hugging);
		set.loop( aKing, l.king.hugging.ego);
		erase( ego);

		scriptTimer = 4;
		}

	if (roomScript == 8)
		{
		set.view( aKing, v.king);
		set.view( aQueen, v.queen);
		set.loop( aQueen, facing.right);
		stop.cycling( aKing);
		stop.cycling( aQueen);

		draw( aRosella);
		draw( ego);
		start.cycling( aRosella);
		start.cycling( ego);
		move.obj( aRosella, 57,  98, 1,   nextScript);	[	3
		move.obj(      ego, 66,  98, 1,         done);	[	3
		}

	if (roomScript == 9)
		{
		move.obj( aRosella, 60, 103, 1,   nextScript);	[	3
		move.obj(      ego, 63,  93, 1,         done);	[	3
		}

	if (roomScript == 10)
		{
		work = 3;
		cycle.time( aQueen, work);
		set.view( aQueen, v.hugging);
		set.loop( aQueen, l.queen.hugging.ego);
		set.cel( aQueen, 2);
		start.cycling( aQueen);
		erase( ego);

		work = 4;
		cycle.time( aKing, work);
		set.view( aKing, v.hugging);
		set.loop( aKing, l.king.hugging.girl);
		start.cycling( aKing);
		erase( aRosella);

		scriptTimer = 4;
		}

	if (roomScript == 11)
		{
		stop.update( aKing);
		stop.update( aQueen);
		set.view( aKing, v.king);
		set.view( aQueen, v.queen);
		set.loop( aQueen, facing.right);
		force.update( aKing);
		force.update( aQueen);

		draw( aRosella);
		draw( ego);
		start.cycling( aRosella);
		start.cycling( ego);
		move.obj( aRosella, 57,  98, 1,   nextScript);	[	3
		move.obj(      ego, 66,  98, 1,         done);	[	3
		print(4);
		}

	if (roomScript == 12)
		{
		move.obj( aRosella, 63,  93, 1, stopPrincess);	[	3
		move.obj(      ego, 60, 103, 1,      stopEgo);	[	3
		scriptTimer = 4;
		}

	if (roomScript == 13)
		{
		start.cycling( ego);
		start.cycling( aRosella);
		move.obj(      ego, 82, 122, 1,   nextScript);	[	3
		move.obj( aRosella, 82, 109, 1, stopPrincess);	[	3
		}

	if (roomScript == 14)
		{
		move.obj(      ego, 87, 122, 1,   nextScript);	[	3
		}

	if (roomScript == 15)
		{
		set.loop( aRosella, facing.left);
		set.loop( ego, facing.left);
		stop.update( aKing);
		stop.update( aRosella);
		stop.update( ego);
		force.update( aRosella);
		force.update( ego);
		force.update( aKing);

		print(5);
		scriptTimer = 5;
		}

	if (roomScript == 16)
		{
		start.update( aMirror);
		start.cycling( aMirror);
		end.of.loop( aMirror, nextScript);
		}

	if (roomScript == 17)
		{
		work = 3;
		cycle.time( aMirror, work);
		start.cycling( aMirror);
		set.loop( aMirror, l.mirror.sparkling);
		scriptTimer = 6;
		}

	if (roomScript == 18)
		{
		print(6);
		scriptTimer = 3;
		}

	if (roomScript == 19)
		{
		start.update( aKing);
		start.cycling( aKing);
		work = 1;
		cycle.time( aKing, work);
		move.obj( aKing, 42, 111, 1, nextScript);
		}

	if (roomScript == 20)
		{
		move.obj( aKing, 19, 111, 1, nextScript);
		}

	if (roomScript == 21)
		{
		start.update( aCap);
		erase( aCap);
		print(7);
		move.obj( aKing, 42, 111, 1, nextScript);
		}

	if (roomScript == 22)
		{
		print(8);
		move.obj( aKing, 50, 103, 1, nextScript);
		}

	if (roomScript == 23)
		{
		stop.cycling( aKing);
		stop.update( aKing);
		set.cel( aKing, 3);
		force.update( aKing);
		position( aCap, 55, 81);
		draw( aCap);
		move.obj( aCap, 72, 64, 1, nextScript);
		}

	if (roomScript == 24)
		{
		print(9);
		start.update( aRosella);
		start.update( ego);
		set.view( aRosella, v.catching.venture.cap);
		set.view(      ego, v.catching.venture.cap);
		set.loop( aRosella,    l.princess.catching);
		set.loop(      ego,         l.ego.catching);
		start.cycling( aRosella);
		start.cycling( ego);
		set( keep.cycling);
		move.obj( aCap, 82, 73, 1, nextScript);
		}

	if (roomScript == 25)
		{
		stop.cycling( aCap);
		stop.motion( aCap);

		stop.cycling( ego);
		reset( keep.cycling);
		stop.cycling( aRosella);
		set.cel( ego, 1);
		set.cel( aRosella, 1);

		scriptTimer = 3;
		}

	if (roomScript == 26)
		{
		print(10);
		scriptTimer = 7;
		}

	if (roomScript == 27)
		{
		print(12);
		print(14);
		}
	}



if (stopKing)
	{
	reset( stopKing);
	stop.cycling( aKing);
	}

if (stopQueen)
	{
	reset( stopQueen);
	stop.cycling( aQueen);
	}

if (stopPrincess)
	{
	reset( stopPrincess);
	stop.cycling( aRosella);
	}

if (stopEgo)
	{
	reset( stopEgo);
	stop.cycling( ego);
	}

if (soundDone)
	{
	sound( m.winner, soundDone);
	}


[*****
:exit							[	test for leaving the room
[*****

