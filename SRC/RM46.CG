[logics for room 46 -- the opening cartoon

%include	"rm46.msg"
%include	"gamedefs.al"



[	This room is a cartoon, using pic.34. Gwydion is standing at the 
[back of the mountain, between the house and the chicken coop, with his back 
[to us. Wait 5 seconds. print( 1); Wait 5 seconds. print( 2); The house door 
[opens, wiz comes out, stops, print( 3); Gwydion goes to the wizard, 
[wiz points the finger, print( 4); wiz enters house, closing the 
[door behind him. Gwydion turns toward us, print( 5); then goes into the house 
[after the wizard. player.control starts in room 7.


%define	message.1.seconds		31	[	half-seconds message is displayed
%define	message.2.seconds		26
%define	message.3.seconds		12
%define	message.4.seconds		42
%define	message.5.seconds		24

%define	print.1.time			10	[	all times are "seconds.in.room"
%define	print.2.time			15
%define	wiz.enters			20
%define	delay.before.ego.walks	 3
%define	delay.before.wiz.walks	 3
%define	delay.before.ego.take	 3
%define	delay.before.ego.leaves	 5

%define	chick.2.wander.count	44	[	cycles, not seconds
%define	chick.1.wander.count	33
%define	chick.1.stop.count		22
%define	chick.2.stop.count		15

%define	l.front.door			0	[	door view defines
%define	l.chicken.gate			1


%define	rm.script.done			lf0
%define	chick.1.eating			lf1
%define	chick.2.eating			lf2
%define	music.done			lf3


%define	rm.script				lv0
%define	chick.2.wander			lv1
%define	chick.1.wander			lv2


%object	a.chick.1				1
%object	a.chick.2				2
%object	a.door				3
%object	a.gate				4



if (init.log)
	{
	prevent.input();
	program.control();
	set( demo);
	set( handsOff);
	animation.interval = normal;

	load.view( v.ego);
	load.view( v.doors.rm34);			[	loop 0 = door; loop 1 = gate
	load.view( v.chicken);
	load.view( v.chicken.eating);
	load.view( v.wiz);
	load.view( v.wiz.pointing);
	load.sound( m.cartoon);


	work = 34;
	load.pic( work);
	draw.pic( work);
	discard.pic( work);


	animate.obj( a.door);
	position( a.door, 38, 129);
	set.view( a.door, v.doors.rm34);
	set.loop( a.door, l.front.door);
	set.cel( a.door, 0);
	work = 3;
	cycle.time( a.door, work);
	draw( a.door);
	stop.update( a.door);

	animate.obj( a.gate);
	ignore.block( a.gate);
	ignore.objs( a.gate);
	position( a.gate, 92, 129);
	set.view( a.gate, v.doors.rm34);
	set.loop( a.gate, l.chicken.gate);
	set.cel( a.gate, 0);
	set.priority( a.gate, 10);
	draw( a.gate);
	stop.update( a.gate);

	animate.obj( a.chick.1);
	position( a.chick.1, 123, 123);
	set.view( a.chick.1, v.chicken);
	draw( a.chick.1);
	wander( a.chick.1);
	chick.1.wander = chick.1.wander.count;

	animate.obj( a.chick.2);
	position( a.chick.2,120,133);
	set.view( a.chick.2,v.chicken);
	draw( a.chick.2);
	wander( a.chick.2);
	chick.2.wander = chick.2.wander.count;

	wiz.x = 0;
	wiz.y = 0;
	animate.obj( a.wiz);
	position( a.wiz, 38, 132);
	set.view( a.wiz, v.wiz);
	set.loop( a.wiz, facing.right);
	work = wiz.cycle.time;
	cycle.time( a.wiz, work);

	set.view( ego, v.ego);
	set.loop( ego, facing.back);
	stop.cycling( ego);
	reset( keep.cycling);
	position( ego, 82, 109);
	draw( ego);

	show.pic();

	sound( m.cartoon, music.done);

	return();

	}							[	end INIT.LOG


[*****
:no.input
[*****

--chick.1.wander;
if (chick.1.wander == chick.1.stop.count)
	{
	normal.motion( a.chick.1);
	stop.motion( a.chick.1);
	set.view( a.chick.1, v.chicken.eating);
	}

if (chick.1.wander == 1)
	{
	chick.1.wander = chick.1.wander.count;
	set.view( a.chick.1, v.chicken);
	wander( a.chick.1);
	}


--chick.2.wander;
if (chick.2.wander == chick.2.stop.count)
	{
	normal.motion( a.chick.2);
	stop.motion( a.chick.2);
	set.view( a.chick.2, v.chicken.eating);
	}

if (chick.2.wander == 1)
	{
	chick.2.wander = chick.2.wander.count;
	set.view( a.chick.2, v.chicken);
	wander( a.chick.2);
	}


if (aSecondPassed)
	{
	--timer.1;
	if ((seconds.in.room == print.1.time ||
		seconds.in.room == print.2.time ||
		seconds.in.room == wiz.enters   ||
		timer.1 == 1))
		{
		set( rm.script.done);
		}
	}


if (rm.script.done)
	{
	reset( rm.script.done);
	++rm.script;

	if (rm.script == 1)
		{
		print.timeout = message.1.seconds;
		print.at( 1, 2, 2, 37);
		}

	if (rm.script == 2)
		{
		print.timeout = message.2.seconds;
		print.at( 2, 2, 2, 37);
		}

	if (rm.script == 3)
		{
		start.update( a.door);
		end.of.loop( a.door, rm.script.done);
		}

	if (rm.script == 4)
		{
		stop.update( a.door);
		draw( a.wiz);
		move.obj( a.wiz, 65, 139, 0, wiz.arrived);
		print.timeout = message.3.seconds;
		print.at( 3, 2, 2, 37);
		timer.1 = delay.before.ego.walks;
		}

	if (rm.script == 5)
		{
		set( keep.cycling);			[	get off your ass, Gwydion!
		move.obj( ego, 82, 138, 1, rm.script.done);
		}

	if (rm.script == 6)
		{
		move.obj( ego, 80, 138, 1, rm.script.done);
		}

	if (rm.script == 7)
		{
		reset( keep.cycling);
		stop.cycling( ego);
		print.timeout = message.4.seconds;
		print.at( 4, 2, 2, 37);
		set( openingChoreAssigned);
		chore.to.do = clean.kitchen;
		chore.minutes = chore.init.minutes;
		timer.1 = delay.before.wiz.walks;
		}

	if (rm.script == 8)
		{
		set.loop( a.wiz, facing.left);
		start.cycling( a.wiz);
		move.obj( a.wiz, 38, 132, 1, rm.script.done);
		}

	if (rm.script == 9)
		{
		erase( a.wiz);
		start.update( a.door);
		beginning.of.loop( a.door, rm.script.done);
		}

	if (rm.script == 10)
		{
		stop.update( a.door);
		timer.1 = delay.before.ego.take;
		}

	if (rm.script == 11)
		{
		stop.cycling( ego);
		set.loop( ego, facing.front);
		set.cel( ego, 0);
		timer.1 = delay.before.ego.leaves;
		}

	if (rm.script == 12)
		{
		start.cycling( ego);
		set( keep.cycling);
		move.obj( ego, 39, 132, 1, rm.script.done);
		print.timeout = message.5.seconds;
		print.at( 5, 2, 2, 37);
		}

	if (rm.script == 13)
		{
		reset( keep.cycling);
		stop.cycling( ego);
		start.update( a.door);
		end.of.loop( a.door, rm.script.done);
		}

	if (rm.script == 14)
		{
		new.room( 45);
		}
	}


if (wiz.arrived)
	{
	reset( wiz.arrived);
	stop.cycling( a.wiz);
	}

if (music.done)
	{
	sound( m.cartoon, music.done);
	}

