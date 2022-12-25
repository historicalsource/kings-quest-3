[logics for room 6 -- rm.kitchen

%include	"rm6.msg"
%include	"gamedefs.al"
%include	"rm-names.h"
%include	"iv-views.h"



%define	seconds.to.sweep		26

%define	c.broom				0	[	cel #'s of v.kitchen.stuff
%define	c.knife				1
%define	c.spoon				2
%define	c.mutton				3
%define	c.bread				4
%define	c.fruit				5
%define	c.bowl				6

%define	table				1	[	"ego.location" values.
%define	shelf				2
%define	rack					3

%define	floor.y				134


%define	get.all.food			lf0
%define	get.bread				lf1
%define	get.fruit				lf2
%define	get.mutton			lf3
%define	sound.done			lf4
%define	ego.hit.floor			lf5
%define	house.wiz.init'd		lf6
%define	start.sweeping			lf7
%define	next.wiz.script		lf8
%define	sweep.done			lf9


%define	ego.stunned.seconds		lv0
%define	sweep.seconds			lv1
%define	moving.timer			lv2
%define	wriggle.timer			lv3
%define	sweeping.timer			lv4
%define	lcl.wiz.seconds		lv5
%define	lcl.wiz.script			lv6


%object	a.broom				1
%object	a.knife				2
%object	a.spoon				3
%object	a.bowl				4
%object	a.bread				5
%object	a.fruit				6
%object	a.mutton				7



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.wiz.house;
	landing.x = 77;
	landing.y = 147;
	wiz.x = 105;
	wiz.y = 147;

	cat.x = 70;
	cat.y = 123;
	load.logics( lgc.wiz.house);
	obj.on.water( a.cat);


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	load.view( v.kitchen.stuff);
	load.view( v.ego.sweeping);


	if (current.status == hanging.in.kitchen)
		{
		load.logics( lgc.inventory.check);	[	just in case of a wizzie!!
		load.view( v.wiz);
		load.sound( s.ego.poofing);
		load.sound( m.wiz);

	
		load.sound( s.ego.falling);
		load.sound( s.ego.stunned);
		load.view( v.poof);
		}
	else
		{
		if ((wiz.away.asleep == home.after.bed ||  [	If we're home, and he's 
			wiz.away.asleep == home.after.town) &&
		    !chore.to.do &&
			wiz.status != dead)
			{
			random( 1, 4, work);
			if (work == 1)					   [	home, he may drop in.
				{
				load.logics( lgc.house.wiz);
				set( lgc.house.wiz.loaded);
				random( 6, 12, wiz.entrance.time);	[	he's coming later
				}
			}	
		}


	animate.obj( a.broom);
	position( a.broom, 63, 119);
	set.view( a.broom, v.kitchen.stuff);
	set.cel( a.broom, c.broom);
	stop.cycling( a.broom);
	ignore.blocks( a.broom);
	draw( a.broom);
	stop.update( a.broom);

	if (obj.in.room( i.knife, current.room))
		{
		animate.obj( a.knife);
		position( a.knife, 62, 92);
		set.view( a.knife, v.kitchen.stuff);
		set.cel( a.knife, c.knife);
		stop.cycling( a.knife);
		draw( a.knife);
		stop.update( a.knife);
		}

	if (obj.in.room( i.spoon, current.room))
		{
		animate.obj( a.spoon);
		position( a.spoon, 65, 93);
		set.view( a.spoon, v.kitchen.stuff);
		set.cel( a.spoon, c.spoon);
		stop.cycling( a.spoon);
		draw( a.spoon);
		stop.update( a.spoon);
		}
	
	if (obj.in.room( i.mutton, current.room))
		{
		animate.obj( a.mutton);
		position( a.mutton, 125, 105);
		set.view( a.mutton, v.kitchen.stuff);
		set.cel( a.mutton, c.mutton);
		stop.cycling( a.mutton);
		draw( a.mutton);
		stop.update( a.mutton);
		}
	
	if (obj.in.room( i.bread, current.room))
		{
		animate.obj( a.bread);
		position( a.bread, 127, 112);
		set.view( a.bread, v.kitchen.stuff);
		set.cel( a.bread, c.bread);
		stop.cycling( a.bread);
		draw( a.bread);
		stop.update( a.bread);
		}
	
	if (obj.in.room( i.fruit, current.room))
		{
		animate.obj( a.fruit);
		position( a.fruit, 131, 122);
		set.view( a.fruit, v.kitchen.stuff);
		set.cel( a.fruit, c.fruit);
		stop.cycling( a.fruit);
		draw( a.fruit);
		stop.update( a.fruit);
		}
	
	if (obj.in.room( i.bowl, current.room))
		{
		animate.obj( a.bowl);
		position( a.bowl, 32, 74);
		set.view( a.bowl, v.kitchen.stuff);
		set.cel( a.bowl, c.bowl);
		stop.cycling( a.bowl);
		draw( a.bowl);
		stop.update( a.bowl);
		}


	if (current.status == fly)
		{
		set( positionEgo);
		}

	if (positionEgo)
		{
		if (previous.room == rm.dining)
			{
			position( ego, 104, 166);
			}
		else
			{
			position.v( ego, landing.x, landing.y);
			}
		}


	call( lgc.wiz.house);

	if (lgc.house.wiz.loaded)
		{
		call( lgc.house.wiz);
		}

	if (current.status == hanging.in.kitchen)
		{
		load.view( v.ego.hanging.in.kitchen);	[	These are discarded at
		load.view( v.ego.falling);	[end of stunned.timer, so they are
		load.view( v.ego.stunned);	[loaded last, after calling house.wiz


		reset( drawEgo);
		set( positionEgo);
		start.a.poof = poof.in;
		set( handsOff);
		set.view( ego, v.ego.hanging.in.kitchen);
		position( ego, 72, 78);
		}

	if (drawEgo)
		{
		draw( ego);
		}
 	
	if (current.status == hanging.in.kitchen)
		{
		set( drawEgo);				[	to fool rm0 into !drawing him
		}

	show.pic();

	return();

	}


if (posn( ego, 111, 124, 159, 150))
	{
	ego.location = table;
	}
else
	{
	if (posn( ego, 55, 123, 70, 133))
		{
		ego.location = rack;
		}
	else
		{
		if (posn( ego, 10, 123, 54, 133))
			{
			ego.location = shelf;
			}
		else
			{
			ego.location = 0;
			}
		}
	}


[*****
:handle.input
[*****

if (!have.input)			{goto no.input;}


if (current.status == hanging.in.kitchen)
	{
	print( 61);
	if (!debugging)
		{
		set( have.match);
		}
	goto no.input;
	}


if (current.status == sweeping)
	{
	print( 62);
	if (!debugging)
		{
		set( have.match);
		}
	goto no.input;
	}



[	HANDLE LOOKING AROUND.

if ((said( look, room) ||
	said( look, house) ||
	said( look) ||
	said( look, kitchen)))
	{
	print( 1);
	}

if ((said( look, fireplace) ||
	said( look$in, fireplace)))
	{
	print( 3);
	}

if ((said( look, barrel) ||
	said( look$in, barrel) ||
	said( get, barrel)))
	{
	print( 36);
	}

if (said( look, table))
	{
	print( 5);

	if  (obj.in.room( i.bread, current.room) &&
		obj.in.room( i.fruit, current.room) &&
		obj.in.room( i.mutton, current.room))
		{
		print( 6);
		}
	else
		{
		if  (obj.in.room( i.bread, current.room) &&
			obj.in.room( i.fruit, current.room))
			{
			print( 15);
			}
		else
			{
			if  (obj.in.room( i.bread, current.room) &&
				obj.in.room( i.mutton, current.room))
				{
				print( 16);
				}
			else
				{
				if  (obj.in.room( i.fruit, current.room) &&
					obj.in.room( i.mutton, current.room))
					{
					print( 17);
					}
				else
					{
					if (obj.in.room( i.bread, current.room))
						{
						print( 10);
						}
					else
						{
						if (obj.in.room( i.fruit, current.room))
							{
							print( 13);
							}
						else
							{
							if (obj.in.room( i.mutton, current.room))
								{
								print( 14);
								}
							}
						}
					}
				}
			}
		}
	}

if (said( look, under, table))
	{
	print( 25);
	}

if ((said( look, shelf) ||
	said( look, kitchen, shelf)))
	{
	if (obj.in.room( i.bowl, current.room))
		{
		print( 18);
		}
	else
		{
		print( 19);
		}
	}

if (said( look, pots))
	{
	print( 20);
	}

if ((said( look, wall) ||
	said( look, rack) ||
	said( look, rack, wall)))
	{
	print( 21);
	if (obj.in.room( i.knife, current.room))
		{
		print( 22);
		}

	if (obj.in.room( i.spoon, current.room))
		{
		print( 23);
		}
	}

if (said( look, basket))
	{
	print( 29);
	}

if ((said( look, churn) ||
	said( look$in, churn)))
	{
	print( 30);
	}

if ((said( look, bucket) ||
	said( look$in, bucket)))
	{
	print( 63);
	}

if ((said( look, ceiling) ||
	said( look, beam)))
	{
	print( 31);
	}

if (said( look, herbs))
	{
	print( 59);
	}



[	HANDLE GETTING STUFF.

if ((said( get, baskets) ||
	said( get, baskets, from, wall)))
	{
	print( 32);
	}

if ((said( get, pots) ||
	said( get, pots, from, wall)))
	{
	print( 33);
	}

if (said( get, churn))
	{
	print( 30);
	}

if ((said( get, rack) ||
	said( get, rack, from, wall)))
	{
	print( 34);
	}

if (said( get, herbs))
	{								
	print( 35);
	}

if ((said( get, all, food, table) ||
	said( get, food, table) ||
	said( get, food) ||
	said( get, all, food, from, table) ||
	said( get, food, from, table) ||
	said( get, all, food)))
	{
	if  (!obj.in.room( i.bread, current.room) &&
		!obj.in.room( i.fruit, current.room) &&
		!obj.in.room( i.mutton, current.room))
		{
		print( 45);
		}
	else
		{
		set( get.all.food);
		}
	}

if ((said( get, bread) ||
	said( get, bread, from, table) ||
	said( get, bread, table)))
	{
	set( get.bread);
	}

if ((said( get, fruit) ||
	said( get, fruit, from, table) ||
	said( get, fruit, table)))
	{
	set( get.fruit);
	}

if ((said( get, mutton) ||
	said( get, mutton, from, table) ||
	said( get, mutton, chop, from, table) ||
	said( get, mutton, chop)))
	{
	set( get.mutton);
	}

if ((said( get, spoon) ||
	said( get, spoon, rack) ||
	said( get, spoon, from, rack)))
	{
	if (!obj.in.room( i.spoon, current.room))
		{
		print( 45);
		}
	else
		{
		if (ego.location != rack)
			{
			print( 58);
			}
		else
			{
			print( 44);
			get( i.spoon);
			score += 1;
			start.update( a.spoon);
			erase( a.spoon);
			}
		}
	}

if ((said( get, knife) ||
	said( get, knife, rack) ||
	said( get, knife, from, rack)))
	{
	if (!obj.in.room( i.knife, current.room))
		{
		print( 45);
		}
	else
		{
		if (ego.location != rack)
			{
			print( 58);
			}
		else
			{
			print( 46);
			get( i.knife);
			score += 1;
			start.update( a.knife);
			erase( a.knife);
			}
		}
	}

if ((said( get, bowl, shelf) || 
	said( get, bowl, from, shelf) ||
	said( get, bowl)))
	{
	if (!obj.in.room( i.bowl, current.room))
		{
		print( 45);
		}
	else
		{
		if (ego.location != shelf)
			{
			print( 58);
			}
		else
			{
			print( 48);
			get( i.bowl);
			score += 1;
			start.update( a.bowl);
			erase( a.bowl);
			}
		}
	}



[	HANDLE DOING STUFF.

if ((said( put, wood, fireplace) ||
	said( get, wood)))
	{
	print( 4);
	}

if ((said( start, fire, fireplace) ||
	said( make, fire, fireplace) ||
	said( start, fire) ||
	said( light, fire) ||
	said( make, fire) ||
	said( light, fire, fireplace)))
	{
	print( 4);
	}

if (!handsOff &&
    (said( clean, floor, with, broom) ||
	said( clean, floor) ||
	said( clean, kitchen) ||
	said( clean, kitchen, with, broom) ||
	said( use, broom, clean, kitchen) ||
	said( use, broom, clean, floor) ||
	said( use, broom, clean, room) ||
	said( clean, kitchen, floor) ||
	said( clean, room) ||
	said( clean, room, with, broom) ||
	said( get, broom)))
	{
	if (ego.location != rack)
		{
		print( 58);
		}
	else
		{
		start.update( a.broom);
		erase( a.broom);

		set( handsOff);
		block( 36, 120, 121, 154);
		get.posn( ego, source.x, source.y);
		sweep.seconds = seconds.to.sweep;
		current.status = sweeping;
		set.view( ego, v.ego.sweeping);
		program.control();
		set( keep.cycling);
		moving.timer = 0;
		sweeping.timer = 22;
		if (chore.to.do == clean.kitchen)
			{
			chore.to.do = 0;
			chore.minutes = 0;
			chore.seconds = 0;
			}
		}
	}


[*****
:no.input
[*****

[	GETTING FOOD.

if ((get.all.food || get.bread))
	{
	reset( get.bread);
	if (obj.in.room( i.bread, current.room))
		{
		if (ego.location != table)
			{
			reset( get.all.food);
			print( 57);
			}
		else
			{
			print( 38);
			get( i.bread);
			score += 1;
			start.update( a.bread);
			erase( a.bread);
			}
		}
	else
		{
		if (!get.all.food)
			{
			print( 45);
			}
		}

	if (get.all.food)
		{
		set( get.fruit);
		}
	}

if ((get.all.food || get.fruit))
	{
	reset( get.fruit);
	if (obj.in.room( i.fruit, current.room))
		{
		if (ego.location != table)
			{
			reset( get.all.food);
			print( 57);
			}
		else
			{
			print( 40);
			get( i.fruit);
			score += 1;
			start.update( a.fruit);
			erase( a.fruit);
			}
		}
	else
		{
		if (!get.all.food)
			{
			print( 45);
			}
		}

	if (get.all.food)
		{
		set( get.mutton);
		}
	}

if ((get.all.food || get.mutton))
	{
	reset( get.mutton);
	if (obj.in.room( i.mutton, current.room))
		{
		if (ego.location != table)
			{
			reset( get.all.food);
			print( 57);
			}
		else
			{
			print( 42);
			get( i.mutton);
			score += 1;
			start.update( a.mutton);
			erase( a.mutton);
			}
		}
	else
		{
		if (!get.all.food)
			{
			print( 45);
			}
		}
	reset( get.all.food);
	}



[	CLEANING UP THE KITCHEN FLOOR.  IS EGO'S WORK NEVER DONE?

if (current.status == sweeping)
	{
	if (aSecondPassed)
		{
		--sweep.seconds;
		if (sweep.seconds == 1)
			{
			sweep.seconds = 0;
			moving.timer = 0;
			sweeping.timer = 0;
			unblock();
			ignore.blocks( ego);
			ignore.objs( ego);
			move.obj( ego, 64, 125, 1, sweep.done);
			}
		}
	
	--moving.timer;
	if (moving.timer == 1)
		{
		start.motion( ego);
		wander( ego);
		random( 11, 33, sweeping.timer);
		}
	
	--sweeping.timer;
	if (sweeping.timer == 1)
		{
		normal.motion( ego);
		stop.motion( ego);
		set.loop( ego, facing.front);
		random( 11, 33, moving.timer);
		}
	}

if (sweep.done)
	{
	reset( sweep.done);
	reset( handsOff);
	player.control();
	observe.blocks( ego);
	observe.objs( ego);
	set.view( ego, v.ego);
	reset( keep.cycling);
	normal.motion( ego);
	current.status = normal.ego;
	draw( a.broom);
	}

[	PUNISHMENT STUFF.
	
if (ego.poofing.done)
	{
	accept.input();
	reset( no.cycling);
	reset( ignore.special);
	reset( ignore.water);
	if (current.status == hanging.in.kitchen)
		{
		program.control();
		stop.motion( ego);
		print( 54);
		ego.cycle.time = 2;
		cycle.time( ego, ego.cycle.time);
		wriggle.timer = 23;
		}
	}

if (current.status == hanging.in.kitchen)
	{
	--wriggle.timer;
	if (wriggle.timer == 12)
		{
		set( keep.cycling);
		}
	
	if (wriggle.timer == 1)
		{
		reset( keep.cycling);
		wriggle.timer = 44;
		}
	}	

if (punishment.done)
	{
	reset( punishment.done);
	ignore.blocks( ego);
	ignore.objs( ego);
	set.priority( ego, 15);
	current.status = falling;
	prevent.input();
	program.control();
	set.view( ego, v.ego.falling);
	x = 4;
	y = 0;
	reposition( ego, x, y);
	set( keep.cycling);
	wriggle.timer = 0;
	ego.cycle.time = 1;
	cycle.time( ego, ego.cycle.time);
	y = floor.y;
	step = 3;
	sound( s.ego.falling, done);
	move.obj.v( ego, ego.x, y, step, ego.hit.floor);
	}

if (ego.hit.floor)
	{
	reset( ego.hit.floor);
	current.status = stunned;
	set.view( ego, v.ego.stunned);
	release.priority( ego);
	stop.motion( ego);
	prevent.input();
	program.control();
	set( keep.cycling);
	ego.stunned.seconds = ego.stunned.time;
	set( sound.done);
	}

if (aSecondPassed)
	{
	--lcl.wiz.seconds;
	if (lcl.wiz.seconds == 1)
		{
		set( next.wiz.script);
		}

	--ego.stunned.seconds;
	if (ego.stunned.seconds == 1)
		{
		current.status = normal.ego;
		player.control();
		accept.input();
		reset( handsOff);
		reset( keep.cycling);
		reset( sound.done);
		stop.sound();
		start.motion( ego);
		set.view( ego, v.ego);

		discard.view( v.ego.stunned);
		discard.view( v.ego.falling);
		discard.view( v.ego.hanging.in.kitchen);

		print( 60);

		observe.blocks( ego);
		observe.objs( ego);
		}
	}
	
if (sound.done && current.status == stunned)
	{
	sound( s.ego.stunned, sound.done);
	}


[*****
:exit							[	test for leaving the room
[*****

if (!moving.timer &&
    !sweep.seconds &&
	edge.ego.hit == bottom &&
	current.status != fly.landing &&
	ego.x > 99 && ego.x < 113)
	{
	new.room( rm.dining);
	}

call( lgc.wiz.house);

if (lgc.house.wiz.loaded)
	{
	call( lgc.house.wiz);
	}

