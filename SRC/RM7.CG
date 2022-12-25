[logics for room 7 -- rm.entry

%include	"rm7.msg"
%include	"gamedefs.al"
%include	"rm-names.h"



[	This is the game's opening scene, and the restart room.  Ego gets his
[aerobics punishment here, but not much else happens.  There are no objects 
[to get, and nothing to do.  It is just a room to pass through to get to other 
[rooms.  The wizard can appear here.  He just poofs in and poofs out, 
[assigning the opening chore, if it's not already assigned.



%define	aerobics.x			97
%define	aerobics.y			131


%define	door.open				lf0
%define	on.upper.stairs		lf1
%define	workout.music.done		lf2
%define	house.wiz.init'd		lf3


%define	loop.timer			lv0
%define	lcl.wiz.seconds		lv1


%object	a.candle.1			1
%object	a.candle.2			2



if (init.log)
	{
	if (demo)
		{
		reset( demo);
		reset( keep.cycling);
		reset( no.cycling);
		reset( handsOff);
		set( positionEgo);

		if (monitor.type != mono)
			{
			clear.lines( 22, 24, bg.color);
			}
		current.ego = normal.ego;
		animation.interval = normal;
		player.control();
		accept.input();
		wiz.minutes = wiz.init.minutes;
		wiz.away.asleep = home.after.bed;
		if (openingChoreAssigned)
			{
			chore.minutes = chore.init.minutes;
			chore.seconds = 0;
			}
		}


	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.wiz.house;
	landing.x = 96;
	landing.y = 137;
	wiz.x = 39;
	wiz.y = 92;

	cat.x = 81;
	cat.y = 123;
	load.logics( lgc.wiz.house);
	observe.blocks( a.cat);


	load.view( v.candle.flame);


	if (current.status == doing.aerobics)
		{
		set( handsOff);
		reset( keep.cycling);
		reset( no.cycling);
		reset( ignore.special);
		reset( ignore.water);

		load.view( v.poof);
		load.view( v.ego.fonda);
		load.sound( m.workout);
		load.sound( s.ego.poofing);
		}
	else
		{
		if ((wiz.away.asleep == home.after.bed ||
			wiz.away.asleep == home.after.town) &&
		    !chore.to.do &&
			wiz.status != dead)
			{
			random( 1, 4, work);
			if (!openingChoreAssigned)
				{
				work = 1;			[	Force wiz if they skipped cartoon
				}

			if (work == 1)
				{
				load.logics( lgc.house.wiz);
				set( lgc.house.wiz.loaded);
				random( 6, 12, wiz.entrance.time);	[	he's coming later
				if (!openingChoreAssigned)
					{
					wiz.entrance.time = 6;		[	Hurry up, wizzie!
					}
				}
			}
		}


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	animate.obj( a.candle.1);
	ignore.objs( a.candle.1);
	position( a.candle.1, 86, 84);
	set.view( a.candle.1, v.candle.flame);
	draw( a.candle.1);

	animate.obj( a.candle.2);
	ignore.objs( a.candle.2);
	position( a.candle.2, 114, 85);
	set.view( a.candle.2, v.candle.flame);
	set.cel( a.candle.2, 1);
	draw( a.candle.2);


	if (current.status == fly)
		{
		set( positionEgo);
		}

	if (positionEgo)
		{
		if (previous.room == rm.hallway)
			{
			set( on.upper.stairs);
			set.priority( ego, 14);
			ego.x = 95;
			ego.y = 46;
			}
		else
			{
			if (previous.room == rm.wiz.office)
				{
				ego.x = 97;
				ego.y = 121;
				}
			else
				{
				if (previous.room == rm.dining)
					{
					ego.x = 128;
					ego.y = 140;
					}
				else
					{
					if (previous.room == rm.wiz.yard)
						{
						ego.x = 95;
						ego.y = 165;
						}
					else
						{
						ego.x = landing.x;
						ego.y = landing.y;
						}
					}
				}
			}

		position.v( ego, ego.x, ego.y);
		}


	if (current.status == deferred.entry)
		{
		position.v( ego, landing.x, landing.y);
		set( positionEgo);
		}

	if (current.status == doing.aerobics)
		{
		reset( drawEgo);
		set( positionEgo);
		start.a.poof = poof.in;
		set.view( ego, v.ego.fonda);
		position( ego, aerobics.x, aerobics.y);

		ego.cycle.time = 1;
		ego.step.time = 1;
		ego.step.size = 1;

		program.control();
		stop.motion( ego);
		random( 5, 15, loop.timer);
		}
	

	if (drawEgo)
		{
		draw( ego);
		}

	if (current.status == doing.aerobics)
		{
		set( drawEgo);				[	this fools rm0 into !drawing him
		}

	call( lgc.wiz.house);

	if (lgc.house.wiz.loaded)
		{
		call( lgc.house.wiz);
		}


	show.pic();

	return();

	}



[*****
:handle.input
[*****

if (!have.input)				{goto no.input;}


if (current.status == doing.aerobics)
	{
	print( 2);
	set( have.match);
	}

if ((said( look, room) ||
	said( look, house) ||
	said( look) ||
	said( look, hall)))
	{
	print( 1);
	}

if (said( look, stairs))
	{
	print( 4);
	}

if (said( look, door))
	{
	print( 5);
	}

if ((said( open, anyword, door) ||
	said( open, door) ||
	said( open, door, room) ||
	said( open, anyword, door, room)))
	{
	if (posn( ego, 86, 163, 109, 167))
		{
		print( 6);
		new.room( 34);
		}
	else
		{
		print( 7);
		}
	}

if ((said( close, anyword, door) ||
	said( close, door) ||
	said( close, door, room) ||
	said( close, anyword, door, room)))
	{
	print( 8);
	}

if ((said( look, candle) ||
	said( look, wall) ||
	said( look, candle, on, wall) ||
	said( look, candle, wall)))
	{
 	print( 10);
	}

if ((said( get, light) ||
	said( get, light, off, wall) ||
	said( get, light, from, wall) ||
	said( get, light, wall)))
	{
	print( 11);
	}


[*****
:no.input
[*****

[	HANDLE THE DAMN STAIRCASE.

if (on.water)
	{
	if ((ego.dir == ego.up ||
		ego.dir == ego.up.left ||
		ego.dir == ego.up.right))
		{
		reset( on.upper.stairs);
		}

	if ((ego.dir == ego.down ||
		ego.dir == ego.down.left ||
		ego.dir == ego.down.right))
		{
		set( on.upper.stairs);
		}
	}

if (on.upper.stairs)
	{
	ignore.block( ego);
	set.priority( ego, 13);
	}
else
	{
	release.priority( ego);
	observe.block( ego);
	}

if  (on.upper.stairs && 
	hit.special &&
	posn( ego, 45, 87, 62, 107))
	{
	ego.dir = 0;
	start.motion( ego);
	reposition.to.v( ego, old.ego.x, old.ego.y);
	}



[	HANDLE THE AEROBICS CLASS.

if (aSecondPassed)
	{
	--loop.timer;
	if (loop.timer == 1)
		{
		random( 5, 15, loop.timer);
		random( 0, 3, work);
		set.loop.v( ego, work);
		}
	}

if (current.status == doing.aerobics)
	{
	if (ego.poofing.done)
		{
	
		[	DON'T reset( ego.poofing.done); -- RM0 will get it.
	
		set( workout.music.done);
		set( handsOff);
		program.control();
		accept.input();
		stop.motion( ego);
		set( keep.cycling);
		reset( on.upper.stairs);
		print( 3);
		old.animation.interval = animation.interval;
		animation.interval = fastest;
		work = 5;
		cycle.time( a.candle.1, work);
		cycle.time( a.candle.2, work);
		}
	
	if (punishment.done)
		{
		reset( punishment.done);
		reset( handsOff);
		current.status = normal.ego;
		accept.input();
		player.control();
		start.motion( ego);
		reset( keep.cycling);
		set.view( ego, v.ego);
		loop.timer = 0;
		stop.sound();
		reset( workout.music.done);
		animation.interval = old.animation.interval;
		work = 1;
		cycle.time( a.candle.1, work);
		cycle.time( a.candle.2, work);
		print( 9);
		}

	if (workout.music.done)
		{
		sound( m.workout, workout.music.done);
		}
	}



[*****
:exit
[*****

if (current.status != fly.landing)
	{
	if (posn( ego,  93, 116, 110, 118))	{new.room( rm.wiz.office);}
	if (posn( ego, 131, 134, 140, 144))	{new.room( rm.dining);}
	if (posn( ego,  93,  42, 109,  44))	{new.room( rm.hallway);}

	if (edge.ego.hit == bottom &&
		current.status != snail &&
		current.status != fly)
		{
		print( 6);
		new.room( rm.wiz.yard);
		}
	}


call( lgc.wiz.house);

if (lgc.house.wiz.loaded)
	{
	call( lgc.house.wiz);
	}

