[logics for room 104 -- lgc.wiz.house

%include	"rm104.msg"
%include	"gamedefs.al"
%include	"rm-names.h"



[	This is stuff about the house itself, and the cat logics.  If cat.y = 0, 
[the calling room is telling us the cat can't show up in this room.


%define	cat.still.time			250	[	cycles, not seconds.
%define	cat.moving.time		 19	[	lies still 95% of the time
%define	cat.scared.time		 88	[	after dropping, etc.
%define	tail.still.time		150	[	cycles, not seconds.
%define	tail.moving.time		 19	[	wags tail part of his sit time 


%define	ego.has.cat			df0	[	This room gets 0-5.
%define	drop.cat				df1
%define	make.cat.wander		df2
%define	cat.moving			df3


%define	cat.timer				dv0
%define	tail.timer			dv1



if (init.log)
	{
	set( interiorRoom);
	cat.timer = 0;

	if (current.room == rm.dining &&
		chore.to.do == fix.meal)
		{
		return();
		}

	random( 1, 3, work);
	if (work == 1 && 
		cat.y &&
		!pussy.on.screen &&			[	left over from last room's pussy
		!lgc.house.wiz.loaded)
		{
		load.view( v.cat);
		load.view( v.cat.wagging.tail);
		load.view( v.ego.with.cat);
		load.sound( s.screech);

		animate.obj( a.cat);
		set.view( a.cat, v.cat.wagging.tail);
		set.cel( a.cat, 0);
		position.v( a.cat, cat.x, cat.y);
		draw( a.cat);
		stop.motion( a.cat);
		work = 3;
		cycle.time( a.cat, work);
		set( pussy.on.screen);

		if ((current.room == rm.lab.stairs ||
			current.room == rm.wiz.office ||
			current.room == rm.kitchen))
			{
			object.on.water( a.cat);
			}
		else
			{
			object.on.anything( a.cat);
			}

		cat.timer = cat.still.time;
		tail.timer = 2;
		}
	else
		{
		reset( pussy.on.screen);		[	Perhaps we'll get a little pussy
		}						[		in the next room?
	}							[	end INIT.LOG



if ((said( break, window) ||
	said( break, open, window)))
	{
	print( 1);
	}

if ((said( look, out, window) ||
	said( look, window) ||
	said( look, outside) ||
	said( look$in, window)))
	{
	if ((storm.minutes || storm.seconds))
		{
		print( 6);
		}
	else
		{
		if (current.room < 9)
			{
			print( 20);
			}
		else
			{
			print( 21);
			}
		}
	}

if (said( open, window))
	{
	if (current.room < 9)
		{
		print( 22);
		}
	else
		{
		print( 21);
		}
	}


if (!pussy.on.screen)			{goto no.input;}


if (said( look, cat))
	{
	print( 2);
	}

if (said( talk, cat))
	{
	if (has( i.dough.balls))
		{
		print( 14);
		}
	else
		{
		random( 16, 18, work);
		print.v( work);
		}
	}

if ((said( kiss, cat) ||
	said( pet, cat)))
	{
	print( 3);
	set( make.cat.wander);
	cat.timer = cat.scared.time;
	}


if (said( kick, cat))
	{
	distance( ego, a.cat, work);
	if (work > 11)
		{
		if (has( i.dough.balls))
			{
			print( 23);
			}
		else
			{
			print( 4);
			}
		}
	else
		{
		sound( s.screech, done);
		if (has( i.dough.balls))
			{
			random( 24, 26, work);
			print.v( work);
			}
		else
			{
			print( 12);
			}
		print( 13);
		set( make.cat.wander);
		cat.timer = cat.scared.time;
		}
	}


if (said( kill, cat))
	{
	print( 7);
	set( make.cat.wander);
	cat.timer = cat.scared.time;
	}


if (current.status != normal.ego)		{goto no.input;}


if (!handsOff && 
    (said( get, cat) ||
	said( grab, cat) ||
	said( catch, cat)))
	{
	distance( ego, a.cat, work);
	if (work > 8)
		{
		if (has( i.dough.balls))
			{
			print( 15);
			}
		else
			{
			print( 4);
			}
		}
	else
		{
		random( 1, 4, work);
		if (work > 1)
			{
			print( 5);
			set( make.cat.wander);
			cat.timer = cat.scared.time;
			}
		else
			{
			set( handsOff);
			erase( a.cat);
			cat.timer = 0;
			tail.timer = 0;
			set.view( ego, v.ego.with.cat);
			start.motion( ego);
			ego.dir = 0;
			set( ego.has.cat);
			set( keep.cycling);
			print( 8);
			}
		}
	}

if (said( drop, cat))
	{
	if (!ego.has.cat)
		{
		print( 9);
		}
	else
		{
		set( drop.cat);
		}
	}

if ((said( get, fur, cat) ||
	said( get, cat, fur) ||
	said( get, fur) ||
	said( pull, fur) ||
	said( pull, cat, fur) ||
	said( pull, fur, cat) ||
	said( get, cat, fur, from, cat) ||
	said( get, fur, from, cat) ||
	said( pull, fur, from, cat) ||
	said( pull, cat, fur, from, cat) ||
	said( pull, fur, cat, from, cat)))
	{
	if (!ego.has.cat)
		{
		print( 11);
		}
	else
		{
		get( i.cat.hair);
		sound( s.screech, done);
		print( 12);
		print( 13);
		if (has( i.dough.balls))
			{
			random( 24, 27, work);
			print.v( work);
			}

		if ( !got.cat.hair)
			{
			set( got.cat.hair);
			score += 1;
			print( 19);
			}
		
		set( drop.cat);
		}
	}


[*****
:no.input
[*****

if (!ego.has.cat && pussy.on.screen)
	{
	--cat.timer;
	if (!cat.moving)
		{
		--tail.timer;			[tail.timer only works if cat not moving
		if (tail.timer < tail.moving.time)
			{
			start.cycling( a.cat);
			}
		if (tail.timer == 1)
			{
			tail.timer = tail.still.time;
			stop.cycling( a.cat);
			}
		}
	
	if (cat.timer == cat.moving.time)
		{
		set( make.cat.wander);
		}
	
	if (cat.timer == 1)
		{
		reset( cat.moving);
		cat.timer = cat.still.time;
	
		normal.motion( a.cat);
		stop.motion( a.cat);
		stop.cycling( a.cat);
		set.view( a.cat, v.cat.wagging.tail);
		set.cel( a.cat, 0);
		work = 3;
		cycle.time( a.cat, work);
		}
	}

	
if (ego.has.cat && ego.dir)
	{
	set( drop.cat);
	}

if (drop.cat)
	{
	reset( drop.cat);
	reset( ego.has.cat);
	reset( keep.cycling);
	reset( handsOff);
	set.view( ego, v.ego);
	force.update( ego);
	draw( a.cat);
	set( make.cat.wander);
	cat.timer = cat.scared.time;
	print( 10);
	}

if (make.cat.wander && !ego.has.cat && pussy.on.screen)
	{
	reset( make.cat.wander);
	set( cat.moving);
	set.view( a.cat, v.cat);
	work = 1;
	cycle.time( a.cat, work);
	start.cycling( a.cat);
	start.motion( a.cat);
	wander( a.cat);
	}


[*****
:exit
[*****

