[logics for room 103 -- lgc.climbing

%include  "rm103.msg"
%include  "gamedefs.reh"
%include	"colors.h"



[	In the real room, keep updating "room.bottom" so it's == fall.through, 
[or the Y where ego stops falling, and "ego.location" for debugging purposes.

[	To start a climb, set start.climbing = type of climb, and reposition him. 
[Compare (current.status == type) for conditions.  To change types, 
[reposition, and set start.climbing.  To stop climbing, set start.climbing = 
[done.climbing.

[	Dynamic makes him fall if (current.status != falling && hit.special) or 
[if (start.climbing == falling). Either one moves him to room.bottom.  
[At room.bottom, he dies or is stunned depending on "survivable.fall".  
[If room.bottom == fall.through, he continues falling into the room below.  
[That room's init.logs then restarts his fall, and determines its own 
["survivability".



%define	hit.bottom			df8

%define	stunned.timer			dv9
%define	test.x				dv10
%define	test.y				dv11
%define	test.counter			dv12
%define	display.counter		dv13



if (init.log)
	{
	reset( ignore.special);

	if (survivable.fall)
		{
		load.view( v.ego.stunned);
		load.sound( s.ego.stunned);
		}	

	load.view( v.ego.climbing);
	load.view( v.ego.falling);
	load.sound( s.ego.falling);

	if (current.status == falling)
		{
		start.climbing = falling;
		}
	else
		{
		return();
		}
	}



if (aSecondPassed)
	{
	--stunned.timer;
	if (stunned.timer == 1)
		{
		reset( sound.done);
		print( 2);
		stop.sound();
		stunned.timer = 0;
		start.climbing = walking;
		if (monitor.type != mono)
			{
			clear.lines( 22, 22, bg.color);
			}
		}

	--display.counter;
	if (display.counter == 1)
		{
		if (monitor.type != mono)
			{
			clear.lines( 24, 24, bg.color);
			}
		}
	}

if (stunned.timer && sound.done)
	{
	sound( s.ego.stunned, sound.done);
	}



if  (current.status != falling && 		[	do "accident" detection
    !init.log &&
    !test.counter &&
	hit.special)
	{
	start.climbing = falling;
	}
	

if (start.climbing == walking)
	{
	start.climbing = 0;				[	no start overs
	current.status = normal.ego;
	set.view( ego, v.ego);
	release.priority( ego);
	observe.blocks( ego);
	observe.objs( ego);
	ego.step.size = 1;
	ego.step.time = 1;
	ego.cycle.time = 1;
	step.size( ego, ego.step.size);
	step.time( ego, ego.step.time);
	cycle.time( ego, ego.cycle.time);
	start.motion( ego);
	reset( keep.cycling);
	reset( ignore.water);
	reset( ignore.special);
	reset( handsOff);
	}

if (start.climbing == falling)
	{
	edge.ego.hit = 0;
	start.climbing = 0;				[	no start overs
	current.status = falling;
	test.x = ego.x;
	test.y = ego.y;
	set.view( ego, v.ego.falling);
	set( keep.cycling);
	set( ignore.water);
	set( ignore.special);
	set( handsOff);
	ignore.blocks( ego);
	ignore.objs( ego);

	if (ego.x > ego.falling.limit)
		{
		ego.x = ego.falling.limit;
		reposition.to.v( ego, ego.x, ego.y);
		}

	step = falling.step.size;
	move.obj.v( ego, ego.x, room.bottom, step, hit.bottom);
	sound( s.ego.falling, done);

	if (monitor.type != mono)
		{
		clear.lines( 22, 22, bg.color);
		clear.lines( 24, 24, bg.color);
		}
	set.text.attribute( yellow, bg.color);
	display.counter = 5;
	if (debugging && monitor.type != mono)
		{
		if (ego.location)
			{
			display( 24, 0, 3);
			}
		else
			{
			display( 24, 0, 4);
			}
		}
	set.text.attribute( text.color, bg.color);
	}


if (hit.bottom)
	{
	reset( hit.bottom);
	stop.motion( ego);
	if (monitor.type != mono)
		{
		clear.lines( 22, 22, bg.color);
		}

	if (!survivable.fall)
		{
		if (debugging)
			{
			set( doit);			[	so following paragraph catches.
			}
		else
			{
			erase( ego);
			if (monitor.type != mono)
				{
				clear.lines( 22, 22, bg.color);
				}
			stop.cycling(ego);
			set( certain.death);
			}
		}
	else
		{
		display.counter = 10;
		current.status = stunned;
		sound( s.ego.stunned, sound.done);
		set.view( ego, v.ego.stunned);
		stunned.timer = ego.stunned.time;
		}
	}



if (debugging && doit)
	{
	reset( doit);
	start.climbing = walking;
	stunned.timer = 0;
	test.counter = 33;
	normal.motion( ego);
	reposition.to.v( ego, test.x, test.y);
	}

--test.counter;
if (test.counter)
	{
	set( ignore.special);
	if (test.counter == 1)
		{
		reset( ignore.special);
		}
	}


[*****
:exit 
[*****

