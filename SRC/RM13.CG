[logics for Room 13 -- Forest land with stream. 

%include "gamedefs.al"
%include "rm13.msg"



%define	stun.time				50
%define	ego.falling			11
%define	ego.stunned			35


%define	sound.done			lf0
%define	above.water			lf1


%define	stunned.seconds		lv0


%object	a.falls.1				1
%object	a.falls.2				2
%object	a.splash				3
%object	a.cascade				4



if (init.log)
	{
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	load.view( v.ego);
	load.view( v.ego.wading.shallow);
	map.area = map.llewdor;
	wiz.x = 27;
	wiz.y = 103;
	landing.x = 20;
	landing.y = 85;
	set( beenIn13);
	set.horizon( 52);

	load.logics( lgc.forest);
	load.logics( lgc.stream.mud);
	load.logics( lgc.eagle.feather);


	if (current.status == stunned)
		{
		load.view( v.ego.stunned);
		load.sound( s.ego.stunned);
		}


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	load.view( v.water.rm13);

	animate.obj( a.falls.1);
	position( a.falls.1, 101, 61);
	set.view( a.falls.1, v.water.rm13);
	set.loop( a.falls.1, 0);
	ignore.blocks( a.falls.1);
	ignore.objs( a.falls.1);
	set.priority( a.falls.1, 15);
	draw( a.falls.1);

	animate.obj( a.falls.2);
	position( a.falls.2, 103, 118);
	set.view( a.falls.2, v.water.rm13);
	set.loop( a.falls.2, 0);
	set.cel( a.falls.2, 1);
	set.priority( a.falls.2, 15);
	ignore.blocks( a.falls.2);
	ignore.objs( a.falls.2);
	draw( a.falls.2);


	animate.obj( a.splash);
	position( a.splash, 96, 126);
	set.view( a.splash, v.water.rm13);
	set.loop( a.splash, 1);
	set.priority( a.splash, 15);
	ignore.blocks( a.splash);
	ignore.objs( a.splash);
	work = 2;
	cycle.time( a.splash, work);
	draw( a.splash);

	animate.obj( a.cascade);
	position( a.cascade, 130, 147);
	set.view( a.cascade, v.water.rm13);
	set.loop( a.cascade, 2);
	set.priority( a.cascade, 15);
	ignore.blocks( a.cascade);
	ignore.objs( a.cascade);
	draw( a.cascade);


	if (positionEgo)
		{
		if (previous.room == 12)
			{
			if (ego.y > 103 && ego.y < 108)
				{
				ego.y = 108;
				}

			if (ego.y > 114 && ego.y < 121)
				{
				ego.y = 121;
				}

			if (ego.y > 57 && ego.y < 61)
				{
				ego.y = 61;
				}
			}

		if (previous.room == 14)
			{
			if (ego.y > 80 && ego.y < 85)
				{
				ego.y = 85;
				}

			if (ego.y > 126 && ego.y < 133)
				{
				ego.y = 133;
				}

			if (ego.y > 144)
				{
				ego.y = 144;
				}
			}

		if  (previous.room == 28 &&
			current.status == stunned)
			{
			set( handsOff);
			program.control();
			prevent.input();
			stop.motion( ego);
			set.view( ego, v.ego.stunned);
			set( keep.cycling);
			stunned.seconds = ego.stunned.time;
			set( sound.done);
			}

		position.v( ego, ego.x, ego.y);
		}

	if (drawEgo)
		{
		draw( ego);
		}


	call( lgc.stream.mud);
	call( lgc.forest);
	call( lgc.eagle.feather);

	show.pic();

	return();

	}




reset( near.water);
if ((posn( ego,  88,  58, 152, 115) ||
	posn( ego,  59,  48,  88,  58) ||
	posn( ego,  99,  69, 114,  74) ||
	posn( ego,  92,  61, 107,  69) ||
	posn( ego,  64,  50,  94,  62) ||
	posn( ego, 125, 116, 155, 141)))
	{
	set( near.water);
	}

reset( near.mud);
if ((posn( ego,  93, 0, 143, 76) ||
	posn( ego, 103, 77, 145, 167) ||
	on.water))
	{
	set( near.mud);
	set( near.water);
	}

if ((posn( ego, 107,  74, 127,  75) ||
	posn( ego, 112,  90, 116,  97) ||
	posn( ego, 115,  95, 119,  97) ||
	posn( ego, 116,  98, 126, 106) ||
	posn( ego, 124, 107, 133, 110) ||
	posn( ego, 127, 111, 138, 115) ||
	posn( ego, 135, 116, 144, 120) ||
	posn( ego, 140, 121, 149, 123) ||
	posn( ego, 142, 124, 152, 126) ||
	posn( ego, 133, 126, 144, 127) ||
	posn( ego, 133, 128, 159, 144)))
	{
	set( on.water);
	}


reset( above.water);
if (ego.y < 74)
	{
	reset( on.water);
	if (near.water)
		{
		reset( near.water);
		set( above.water);
		}
	}


if (posn( ego, 35, 100, 66, 166) &&
	said( anyword, flowers))
	{
	print( 1);
	}

call( lgc.eagle.feather);

if ((said( look) || 
	said( look, trees)))
	{
	print( 2);
	}

if (said( look, mountain))
	{
	print( 3);
	}


if  (above.water &&
    (said( get, mud) || 
	said( get, mud, stream) || 
	said( get, mud, from, stream) || 
	said( get, mud, from, stream, with, spoon) || 
	said( get, mud, with, spoon) ||
	said( get, water, stream) ||
	said( get, water) ||
	said( get, water, cup) ||
	said( get, drink, water, stream) ||
	said( stream, get, drink, water) ||
	said( get, drink, water) ||
	said( get, drink) ||
	said( drink, water) ||
	said( drink)))
	{
	print( 5);
	}



if (aSecondPassed)
	{
	--stunned.seconds;
	if (stunned.seconds == 1)
		{
		player.control();
		accept.input();
		reset( handsOff);
		reset( keep.cycling);
		reset( sound.done);
		stop.sound();
		start.motion( ego);
		current.status = normal.ego;
		set.view( ego, v.ego);
		}
	}

if (sound.done && current.status == stunned)
	{
	sound( s.ego.stunned, sound.done);
	}


[*****
:exit							[	test for leaving the room
[*****

call( lgc.stream.mud);
call( lgc.forest);

if (edge.ego.hit == top)			{new.room( 28);}
if (edge.ego.hit == left)		{new.room( 12);}
if (edge.ego.hit == right)		{new.room( 14);}
