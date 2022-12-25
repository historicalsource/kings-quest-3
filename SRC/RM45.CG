[Logics for room 45 -- title, credits

%include	"rm45.msg"
%include	"gamedefs.al"
%include	"rm-names.h"



[	This room shows the title screen, switches to the credits screen, and
[then when credits are done, calls room.46, the opening cartoon.
[Player.control starts in room 7.

[	Note:  using the standard "frame" pic, first line to print on is y = 3,
[lowest is y = 19.  X = 4 leaves 1 character blank at left edge.


[	Note 2:  the floating names are computed in the following manner, 
[where column #1 is width of name; #2 is value #1 divided in half; #3 is 
[center of exploding box (54) minus the value in #2; #4 is height of the 
[names; #5 is value #4 divided by 2; #6 is the center y of the exploding 
[box (70) plus the value in #5.

[	LOOP NAME		#1	#2	#3		#4	#5	#6
[	l.berta		70	35	19		19	10	80
[	l.programmers	68	34	20		41	20	90
[	l.developers	74	37	17		44	22	92
[	l.artists		47	29	25		33	16	86
[	l.composer	59	30	24		32	16	86



[%view	v.title.stuff.1			60
	%define	l.berta			0		[	60a	written by Roberta 
	%define	l.programmers		1		[	60b	programmed by
	%define	l.developers		2		[	60c	Development System by

[%view	v.title.stuff.2			61
	%define	l.artists			0		[	61a	graphics by				
	%define	l.music.programmer	1		[	61b	music programmed by
	%define	l.composer		2		[	61c	music composed by

[%view	v.title.stuff.3			62
	%define	l.numbers			0		[	62a	
	%define	l.bolt			1		[	62b	
	%define	l.letter.sparkles	2		[	62c	
	%define	l.ray			3		[	62d

[%view	v.wiz.head.credit.screen		64
[%view	v.wiz.hand.credit.screen		65
	%define	l.handjob			0
	%define	l.eyeballs		1


%define	copyright.delay		10
%define	credits.delay			9	[	all times are real seconds
%define	qa.credits.delay		40
%define	rm46.delay			22

%define	numbers.y				148


%define	rmScriptDone			lf0
%define	aSparkle1Done			lf1
%define	aSparkle2Done			lf2
%define	aSparkle3Done			lf3
%define	aSparkle4Done			lf4
%define	boltDone				lf5
%define	nameDone				lf6
%define	aRayDone				lf7
%define	eyesDone				lf8
%define	musicDone				lf9


%define	creditsPic			lv0
%define	aSparkle1Timer			lv1
%define	aSparkle2Timer			lv2
%define	aSparkle3Timer			lv3
%define	aSparkle4Timer			lv4
%define	scriptTimer			lv5
%define	rmScript				lv6
%define	framePic				lv7
%define	nameCount				lv8
%define	eyeDelay				lv9


%object	aSparkle1				1
%object	aSparkle2				2
%object	aSparkle3				3
%object	aSparkle4				4

%object	aHand				5
%object	aBolt				6
%object	aName				7

%object	aRay1				8
%object	aRay2				9
%object	aRay3				10
%object	aRay4				11
%object	aRay5				12
%object	aRay6				13
%object	aRay7				14
%object	aRay8				15



if (init.log)
	{
	set.horizon( 1);
	prevent.input();
	program.control();
	status.line.off();
	set( demo);
	animation.interval = fast;

	load.sound( m.title);
	load.sound( m.credits);

	load.view( v.title.stuff.1);
	load.view( v.title.stuff.2);
	load.view( v.title.stuff.3);
	load.view( v.wiz.head.credit.screen);
	load.view( v.wiz.hand.credit.screen);

	framePic = 47;					[	the traditional blue box
	load.pic( framePic);

	creditsPic = 46;				[	the credits page
	load.pic( creditsPic);

	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	sound( m.title, musicDone);


	add.to.pic( v.title.stuff.3, 0, 0, 59, numbers.y, 4, 4);	[	the 1
	add.to.pic( v.title.stuff.3, 0, 1, 75, numbers.y, 4, 4);	[	the 2
	add.to.pic( v.title.stuff.3, 0, 2, 87, numbers.y, 4, 4);	[	the 3


	rmScript = 0;
	aSparkle1Timer = 2;
	aSparkle2Timer = 3;
	aSparkle3Timer = 4;
	aSparkle4Timer = 5;
	scriptTimer = copyright.delay;


	set.view( ego, v.wiz.hand.credit.screen);
	set.loop( ego, l.eyeballs);
	set.cel( ego, 0);
	position( ego, 122, 77);
	work = 4;
	cycle.time( ego, work);
	reset( keep.cycling);


	animate.obj( aSparkle1);
	ignore.obj( aSparkle1);
	set.view( aSparkle1, v.title.stuff.3);
	set.loop( aSparkle1, 2);
	set.priority( aSparkle1, 15);

	animate.obj( aSparkle2);
	ignore.obj( aSparkle2);
	set.view( aSparkle2, v.title.stuff.3);
	set.loop( aSparkle2, 2);
	set.priority( aSparkle2, 15);

	animate.obj( aSparkle3);
	ignore.obj( aSparkle3);
	set.view( aSparkle3, v.title.stuff.3);
	set.loop( aSparkle3, 2);
	set.priority( aSparkle3, 15);

	animate.obj( aSparkle4);
	ignore.obj( aSparkle4);
	set.view( aSparkle4, v.title.stuff.3);
	set.loop( aSparkle4, 2);
	set.priority( aSparkle4, 15);


	animate.obj( aHand);
	set.view( aHand, v.wiz.hand.credit.screen);
	set.cel( aHand, 0);
	position( aHand, 93, 154);

	animate.obj( aBolt);
	set.view( aBolt, v.title.stuff.3);
	set.loop( aBolt, l.bolt);
	fix.loop( aBolt);

	animate.obj( aName);

	animate.obj( aRay1);
	set.view( aRay1, v.title.stuff.3);
	set.loop( aRay1, l.ray);
	fix.loop( aRay1);
	ignore.obj( aRay1);
	set.priority( aRay1, 15);

	animate.obj( aRay2);
	set.view( aRay2, v.title.stuff.3);
	set.loop( aRay2, l.ray);
	fix.loop( aRay2);
	ignore.obj( aRay2);
	set.priority( aRay2, 15);

	animate.obj( aRay3);
	set.view( aRay3, v.title.stuff.3);
	set.loop( aRay3, l.ray);
	fix.loop( aRay3);
	ignore.obj( aRay3);
	set.priority( aRay3, 15);

	animate.obj( aRay4);
	set.view( aRay4, v.title.stuff.3);
	set.loop( aRay4, l.ray);
	fix.loop( aRay4);
	ignore.obj( aRay4);
	set.priority( aRay4, 15);

	animate.obj( aRay5);
	set.view( aRay5, v.title.stuff.3);
	set.loop( aRay5, l.ray);
	fix.loop( aRay5);
	ignore.obj( aRay5);
	set.priority( aRay5, 15);

	animate.obj( aRay6);
	set.view( aRay6, v.title.stuff.3);
	set.loop( aRay6, l.ray);
	fix.loop( aRay6);
	ignore.obj( aRay6);
	set.priority( aRay6, 15);

	animate.obj( aRay7);
	set.view( aRay7, v.title.stuff.3);
	set.loop( aRay7, l.ray);
	fix.loop( aRay7);
	ignore.obj( aRay7);
	set.priority( aRay7, 15);

	animate.obj( aRay8);
	set.view( aRay8, v.title.stuff.3);
	set.loop( aRay8, l.ray);
	fix.loop( aRay8);
	ignore.obj( aRay8);
	set.priority( aRay8, 15);

	show.pic();
	
	reset( handsOff);

	return();

	}							[	end INIT.LOG


set( handsOff);

[*****
:no.input
[*****

if (musicDone)
	{
	if  (sound.on && 
	    (rmScript == 1 || rmScript == 3))
		{
		reset( rmScriptDone);
		scriptTimer = 2;
		}

	if (rmScript != 3)
		{
		sound( m.credits, musicDone);
		}
	}

if (aSecondPassed)
	{
	--scriptTimer;
	if (scriptTimer == 1)
		{
		set( rmScriptDone);
		}
	}


if (rmScriptDone)
	{
	reset( rmScriptDone);
	++rmScript;

	if (rmScript == 1)
		{
		if (monitor.type != mono)
			{
			display( 22, 13, 1);
			display( 23,  3, 2);
			display( 24,  4, 3);
			}
		scriptTimer = credits.delay;
		}

	if (rmScript == 2)
		{
		scriptTimer = qa.credits.delay;
		if (monitor.type != mono)
			{
			clear.lines( 22, 24, bg.color);
			}

		reset( aSparkle1Done);
		reset( aSparkle2Done);
		reset( aSparkle3Done);
		reset( aSparkle4Done);

		erase( aSparkle1);
		erase( aSparkle2);
		erase( aSparkle3);
		erase( aSparkle4);

		aSparkle1Timer = 0;
		aSparkle2Timer = 0;
		aSparkle3Timer = 0;
		aSparkle4Timer = 0;


		draw.pic( creditsPic);
		add.to.pic( v.wiz.head.credit.screen, 0, 0, 112, 160, 4, 4);
		
		draw( aHand);
		end.of.loop( aHand, done);

		draw( ego);
		set( keep.cycling);
		end.of.loop( ego, eyesDone);

		show.pic();
		}



[	AT THIS POINT, we interrupt the rmScript to do the many hand flipping,
[lightning bolt flying, raysExploding, nameDrawing, nameFloating off screen
[things.  When that's done, it triggers rmScript again.  (Not elegant, but
[why bother?



	if (rmScript == 3)
		{
		draw.pic( framePic);
[			erase( aHand);
[			erase( ego);
		unanimate.all();
		show.pic();

		display(  3, 4, 11);
		display(  4, 9, 12);

		display(  6, 4, 21);
		display(  7, 9, 22);
		display(  8, 9, 23);
		display(  9, 9, 24);
		display( 10, 9, 25);
		display( 11, 9, 26);
		display( 12, 9, 27);

		display( 14, 4, 31);
		display( 15, 9, 32);
		display( 16, 9, 33);

		display( 18, 4, 41);
		display( 19, 9, 42);

		if (monitor.type == mono)
			{
			display( 22, 13, 1);
			display( 23,  3, 2);
			display( 24,  4, 3);
			}

		scriptTimer = rm46.delay;
		}

	if (rmScript == 4)
		{
		new.room( rm.opening.cartoon);
		}
	}



--aSparkle1Timer;
if (aSparkle1Timer == 1)
	{
	random( 1, 13, work);
	if (work == 1)			{x =  39; y =  77;}		[	top right K
	if (work == 2)			{x =  48; y = 107;}		[	lower left G
	if (work == 3)			{x =  68; y =  73;}		[	apostrophe
	if (work == 4)			{x =  92; y =  79;}		[	top Q
	if (work == 5)			{x = 105; y = 106;}		[	bottom Q
	if (work == 6)			{x = 126; y =  88;}		[	top s
	if (work == 7)			{x = 132; y = 106;}		[	bottom t
	if (work == 8)			{x =  55; y =  57;}		[	top 1
	if (work == 9)			{x =  99; y =  46;}		[	top 3
	if (work == 10)		{x =  55; y = 150;}		[	bottom 1
	if (work == 11)		{x = 100; y = 153;}		[	bottom 3
	if (work == 12)		{x =  94; y = 136;}		[	middle lower 3
	if (work == 13)		{x =  72; y =  63;}		[	top 2

	position.v( aSparkle1, x, y);
	set.cel( aSparkle1, 0);
	draw( aSparkle1);
	end.of.loop( aSparkle1, aSparkle1Done);
	}

if (aSparkle1Done)
	{
	reset( aSparkle1Done);
	erase( aSparkle1);
	random( 4, 10, aSparkle1Timer);
	}


--aSparkle2Timer;
if (aSparkle2Timer == 1)
	{
	random( 1, 13, work);
	if (work == 1)			{x =  39; y =  77;}		[	top right K
	if (work == 2)			{x =  48; y = 107;}		[	lower left G
	if (work == 3)			{x =  68; y =  73;}		[	apostrophe
	if (work == 4)			{x =  92; y =  79;}		[	top Q
	if (work == 5)			{x = 105; y = 106;}		[	bottom Q
	if (work == 6)			{x = 126; y =  88;}		[	top s
	if (work == 7)			{x = 132; y = 106;}		[	bottom t
	if (work == 8)			{x =  55; y =  57;}		[	top 1
	if (work == 9)			{x =  99; y =  46;}		[	top 3
	if (work == 10)		{x =  55; y = 150;}		[	bottom 1
	if (work == 11)		{x = 100; y = 153;}		[	bottom 3
	if (work == 12)		{x =  94; y = 136;}		[	middle lower 3
	if (work == 13)		{x =  72; y =  63;}		[	top 2

	position.v( aSparkle2, x, y);
	draw( aSparkle2);
	set.cel( aSparkle2, 0);
	end.of.loop( aSparkle2, aSparkle2Done);
	}

if (aSparkle2Done)
	{
	reset( aSparkle2Done);
	erase( aSparkle2);
	random( 4, 10, aSparkle2Timer);
	}


--aSparkle3Timer;
if (aSparkle3Timer == 1)
	{
	random( 1, 13, work);
	if (work == 1)			{x =  39; y =  77;}		[	top right K
	if (work == 2)			{x =  48; y = 107;}		[	lower left G
	if (work == 3)			{x =  68; y =  73;}		[	apostrophe
	if (work == 4)			{x =  92; y =  79;}		[	top Q
	if (work == 5)			{x = 105; y = 106;}		[	bottom Q
	if (work == 6)			{x = 126; y =  88;}		[	top s
	if (work == 7)			{x = 132; y = 106;}		[	bottom t
	if (work == 8)			{x =  55; y =  57;}		[	top 1
	if (work == 9)			{x =  99; y =  46;}		[	top 3
	if (work == 10)		{x =  55; y = 150;}		[	bottom 1
	if (work == 11)		{x = 100; y = 153;}		[	bottom 3
	if (work == 12)		{x =  94; y = 136;}		[	middle lower 3
	if (work == 13)		{x =  72; y =  63;}		[	top 2

	position.v( aSparkle3, x, y);
	set.cel( aSparkle3, 0);
	draw( aSparkle3);
	end.of.loop( aSparkle3, aSparkle3Done);
	}

if (aSparkle3Done)
	{
	reset( aSparkle3Done);
	erase( aSparkle3);
	random( 4, 10, aSparkle3Timer);
	}


--aSparkle4Timer;
if (aSparkle4Timer == 1)
	{
	random( 1, 13, work);
	if (work == 1)			{x =  39; y =  77;}		[	top right K
	if (work == 2)			{x =  48; y = 107;}		[	lower left G
	if (work == 3)			{x =  68; y =  73;}		[	apostrophe
	if (work == 4)			{x =  92; y =  79;}		[	top Q
	if (work == 5)			{x = 105; y = 106;}		[	bottom Q
	if (work == 6)			{x = 126; y =  88;}		[	top s
	if (work == 7)			{x = 132; y = 106;}		[	bottom t
	if (work == 8)			{x =  55; y =  57;}		[	top 1
	if (work == 9)			{x =  99; y =  46;}		[	top 3
	if (work == 10)		{x =  55; y = 150;}		[	bottom 1
	if (work == 11)		{x = 100; y = 153;}		[	bottom 3
	if (work == 12)		{x =  94; y = 136;}		[	middle lower 3
	if (work == 13)		{x =  72; y =  63;}		[	top 2

	position.v( aSparkle4, x, y);
	set.cel( aSparkle4, 0);
	draw( aSparkle4);
	end.of.loop( aSparkle4, aSparkle4Done);
	}

if (aSparkle4Done)
	{
	reset( aSparkle4Done);
	erase( aSparkle4);
	random( 4, 10, aSparkle4Timer);
	}



work = 0;
current.cel( aHand, work);
if (work == 2)
	{
	position( aBolt, 90, 120);
	draw( aBolt);
	move.obj( aBolt, 54, 84, 5, boltDone);
	}

if (boltDone)
	{
	reset( boltDone);
	erase( aBolt);

	position( aRay1, 54, 70);
	position( aRay2, 54, 70);
	position( aRay3, 54, 70);
	position( aRay4, 54, 70);
	position( aRay5, 54, 70);
	position( aRay6, 54, 70);
	position( aRay7, 54, 70);
	position( aRay8, 54, 70);

	draw( aRay1);
	draw( aRay2);
	draw( aRay3);
	draw( aRay4);
	draw( aRay5);
	draw( aRay6);
	draw( aRay7);
	draw( aRay8);

	move.obj( aRay1, 54,  30, 5, aRayDone);
	move.obj( aRay2, 84,  30, 5, aRayDone);
	move.obj( aRay3, 84,  70, 5, aRayDone);
	move.obj( aRay4, 84, 110, 5, aRayDone);
	move.obj( aRay5, 54, 110, 5, aRayDone);
	move.obj( aRay6, 14, 110, 5, aRayDone);
	move.obj( aRay7, 14,  70, 5, aRayDone);
	move.obj( aRay8, 14,  30, 5, aRayDone);
	}

if (aRayDone)
	{
	reset( aRayDone);
	erase( aRay1);
	erase( aRay2);
	erase( aRay3);
	erase( aRay4);
	erase( aRay5);
	erase( aRay6);
	erase( aRay7);
	erase( aRay8);


	++nameCount;

	if (nameCount == 1)
		{
		set.view( aName, v.title.stuff.1);
		set.loop( aName, l.berta);
		x = 19;
		y = 80;
		target.y = 31;
		}

	if (nameCount == 2)
		{
		set.view( aName, v.title.stuff.1);
		set.loop( aName, l.programmers);
		x = 20;
		y = 90;
		target.y = 40;
		}

	if (nameCount == 3)
		{
		set.view( aName, v.title.stuff.1);
		set.loop( aName, l.developers);
		x = 17;
		y = 92;
		target.y = 43;
		}

	if (nameCount == 4)
		{
		set.view( aName, v.title.stuff.2);
		set.loop( aName, l.artists);
		x = 25;
		y = 86;
		target.y = 32;
		}

	if (nameCount == 5)
		{
		set.view( aName, v.title.stuff.2);
		set.loop( aName, l.composer);
		x = 24;
		y = 86;
		target.y = 33;
		}


	fix.loop( aName);
	position.v( aName, x, y);
	step = 2;
	draw( aName);
	move.obj.v( aName, x, target.y, step, nameDone);

	set.cel( ego, 0);
	}

if (nameDone)
	{
	reset( nameDone);
	erase( aName);

	if (nameCount < 5)
		{
		set.cel( aHand, 0);
		end.of.loop( aHand, done);

		set( keep.cycling);
		end.of.loop( ego, eyesDone);
		}
	else
		{
		reset( rmScriptDone);
		scriptTimer = 2;
		}
	}

if (eyesDone)
	{
	reset( eyesDone);
	reset( keep.cycling);
	eyeDelay = 14;
	}

--eyeDelay;
if (eyeDelay == 1)
	{
	set.cel( ego, 0);
	}

[*****
:exit
[*****

