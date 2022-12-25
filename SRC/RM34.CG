[logics for Room 34 -- Top of mountain, outside of wizard's house

%include	"rm34.msg"
%include	"gamedefs.al"



[	Front door opens and closes.  If "open door", go to room 7.  If walks 
[down path, go into room 33. if fall off rear edge, he dies. If falls off 
[front edge, continue falling through rm33 & die in rm18.

[	2 chickens wander inside the pen.  Randomly they stop and eat.
[chicken feed is outside the fence, near rear cliff.  if "feed chickens", 
[ego throws feed to chickens, chickens walk to ego, eat a while, then wander 
[again.

[	you can get a feather from a chicken. if "get chicken" show ego holding
[chicken.  Ego can't leave the pen while carrying a chick.

[	gate opens and closes. if "open gate", open the gate, move ego so he can
[walk through, close it behind him.



%define	l.front.door			0	[	door view defines
%define	l.chicken.gate			1

%define	l.ego.throwing			0	[	ego.feeding.chickens defines
%define	l.corn.in.air			1
%define	l.corn.on.ground		2

%define	chicken.feeding.time	17
%define	chick.2.wander.count	44
%define	chick.1.wander.count	33
%define	chick.1.stop.count		22
%define	chick.2.stop.count		15

%define	pen					1	[	ego.location values
%define	feed.bag				2
%define	door					3
%define	inside.gate			4
%define	outside.gate			5


%define	goto.rm7				lf0
%define	drop.chicken			lf1
%define	door.open.done			lf2
%define	chick.1.arrived		lf3
%define	chick.2.arrived		lf4
%define	chick.1.eating			lf5
%define	chick.2.eating			lf6
%define	inside.pen			lf7
%define	feed.arrived			lf8


%define	feed.script			lv0
%define	chick.2.wander			lv1
%define	chick.1.wander			lv2
%define	chicken.feed.timer		lv3
%define	ego.script			lv4
%define	chick.in.hand			lv5
%define	talk.seconds			lv6
%define	chick.x				lv7
%define	chick.y				lv8
%define	animal.start			lv9
%define	animal.stop			lv10
%define	chicken.eating.timer	lv11
%define	flag.to.set			lv12
%define	gate.source.x			lv13
%define	gate.source.y			lv14
%define	gate.target.x			lv15
%define	gate.target.y			lv16


%object	a.chick.1				1
%object	a.chick.2				2
%object	a.door				3
%object	a.gate				4
%object	a.feed				5



if (init.log)
	{
	if ((storm.minutes || storm.seconds) && previous.room == 7)
		{
		pre.previous.room = previous.room;
		new.room( 87);
		}

	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.wiz.house;
	landing.x = 108;
	landing.y = 121;
	wiz.y = 0;

	cat.y = 0;
	load.logics( lgc.wiz.house);
	load.logics( lgc.climbing);
	room.bottom = 166;
	
	set.horizon( 93);


	random( 1, animal.talk.odds, work);
	if  (has( i.dough.balls) &&
		work == 1 &&
	    (!heardC1 ||
		!heardC2 ||
		!heardC3 ||
		!heardC4))
		{

		:which.chicken.message

		random( 1, 4, work);
		if (work == 1)
			{
			if (heardC1)
				{
				goto which.chicken.message;
				}
			else
				{
				flag.to.set  = 135;
				animal.start = 33;
				animal.stop  = 35;
				}
			}

		if (work == 2)
			{
			if (heardC2)
				{
				goto which.chicken.message;
				}
			else
				{
				flag.to.set  = 136;
				animal.start = 36;
				animal.stop  = 37;
				}
			}

		if (work == 3)
			{
			if (heardC3)
				{
				goto which.chicken.message;
				}
			else
				{
				flag.to.set  = 137;
				animal.start = 38;
				animal.stop  = 39;
				}
			}

		if (work == 4)
			{
			if (heardC4)
				{
				goto which.chicken.message;
				}
			else
				{
				flag.to.set  = 138;
				animal.start = 40;
				animal.stop  = 43;
				}
			}

		random( 3, 10, talk.seconds);
		}



	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	load.view( v.doors.rm34);			[	loop 0 = door; loop 1 = gate
	load.view( v.ego.falling);
	load.view( v.chicken);
	load.view( v.chicken.eating);
	load.view( v.ego.feeding.chickens);
	load.view( v.ego.with.chicken);


	animate.obj( a.door);
	position( a.door, 38, 129);
	set.view( a.door, v.doors.rm34);
	set.loop( a.door, l.front.door);
	set.cel( a.door, 0);
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

	animate.obj( a.feed);
	set.view( a.feed, v.ego.feeding.chickens);
	set.loop( a.feed, l.corn.in.air);
	set.cel( a.feed, 0);
	set.priority( a.feed, 10);
	position( a.feed, 97, 114);
	ignore.objs( a.feed);
	ignore.block( a.feed);


	if (current.status == deferred.entry)
		{
		set( positionEgo);
		}

	if (positionEgo)
		{
		if (previous.room == 7)
			{
			position( ego, 39, 131);
			}
		else
			{
			if (previous.room == 33)
				{
				position( ego, 57, 167);
				}
			else
				{
				position.v( ego, landing.x, landing.y);
				}
			}
		}

	if (drawEgo)
		{
		draw( ego);
		}

	observe.blocks( ego);

	call( lgc.wiz.house);
	reset(interiorRoom);

	call( lgc.climbing);

	show.pic();
	return();

	}							[	end INIT.LOG


[*****
:wear.da.fahgahwee
[*****

ego.location = 0;
if (posn( ego, 32, 130, 47, 137))
	{
	ego.location = door;
	}
else
	{
	if (posn( ego, 87, 101, 98, 106))
		{
		ego.location = feed.bag;
		}
	else
		{
		if (posn( ego, 93, 116, 100, 135))
			{
			ego.location = inside.gate;
			}
		else
			{
			if (posn( ego, 81, 116, 87, 135))
				{
				ego.location = outside.gate;
				}
			}
		}
	}

	
[*****
:handle.input
[*****

if (!have.input)			{goto no.input;}

if ((said( look, mountain) ||
	said( look) ||
	said( look, room) ||
	said( look, around)))
	{
	print( 2);
	}

if ((said( look, path) ||
	said( look, down, path)))
	{
	print( 3);
	}

if ((said( look, trees) ||
	said( look, flowers) ||
	said( pick, flowers) ||
	said( climb, trees) ||
	said( look, plants)))
	{
	print( 4);
	}

if ((said( look, sky) ||
	said( look, up, sky)))
	{
	print( 5);
	}

if ((said( look, clouds) ||
	said( look, up, clouds) ||
	said( look, sky) ||
	said( look, clouds, sky) ||
	said( look, up, clouds, sky)))
	{
 	print( 6);
	}

if ((said( climb, mountain) ||
	said( climb, down, mountain)))
	{
	print( 7);
	}

if (said( look, ground))
	{
	print( 8);
	}

if ((said( look, house) ||
	said( look, window) ||
	said( look$in, window) ||
	said( look, window, house)))
	{
	print( 9);
	}

if ((said( look, door) ||
	said( look, door, house)))
	{
	print( 11);
	}

if ((said( knock, door) ||
	said( knock, door, house) ||
	said( knock, on, door) ||
	said( knock, on, house, door)))
	{
	print( 12);
	}

if ((said( open, door) ||
	said( open, door, house)))
	{
	if (ego.location == door)
		{
		if (!handsOff)
			{
			set( handsOff);
			start.update( a.door);
			end.of.loop( a.door, door.open.done);
			}
		else
			{
			print( 1);
			}
		}
	else
		{
		print( 13);
		}
	}

if ((said( look, chickens) ||
	said( look, chickens, pen) ||
	said( look, pen) ||
	said( look$in, pen) ||
	said( look$in, chicken, pen) ||
	said( look, inside, pen)))
	{
	if (!chick.in.hand)
		{
		print( 14);
		}
	else
		{
		print( 23);
		}
	}

if (said( talk, chickens))
	{
	print( 30);
	}

if (said( kill, chicken))
	{
	print( 31);
	}

if (has( i.dough.balls) &&
	said( listen, bird))
	{
	print( 16);
	}

if ((said( look, gate) ||
	said( look, gate, pen)))
	{
	print( 15);					[	gate is ALWAYS closed
	}

if ((said( open, gate) ||
	said( open, gate, pen)))
	{
	if  (ego.location != outside.gate &&
		ego.location != inside.gate)
		{
		print( 13);
		}
	else
		{
		if (chick.in.hand)
			{
			set( drop.chicken);
			print( 20);
			}
		set( ego.arrived);
		ego.script = 0;
		}
	}

if ((said( get, chicken) ||
	said( catch, chicken)))
	{
	if (!inside.pen)
		{
		print( 17);
		}
	else
		{
		if (chick.in.hand)
			{
			print( 29);
			}
		else
			{
			distance( a.chick.1, ego, work);
			if (work < 10)
				{
				get.posn( a.chick.1, chick.x, chick.y);
				chick.in.hand = 1;
				erase( a.chick.1);
				}
	
			if (!chick.in.hand)		[	ok, try another
				{
				distance( a.chick.2, ego, work);
				if (work < 10)
					{
					get.posn( a.chick.2, chick.x, chick.y);
					chick.in.hand = 2;
					erase( a.chick.2);
					}
				}
	
			if (!chick.in.hand)		[	still none
				{
				print( 18);
				}
			else
				{
				set( handsOff);
				set.view( ego, v.ego.with.chicken);
				print( 19);
				}
			}
		}
	}
	

if (chick.in.hand &&
    (said( drop, chicken) ||
	said( put, chicken, down) ||
	said( throw, chicken)))
	{
	set( drop.chicken);
	}


if ((said( get, feather) ||
	said( get, feather, from, chicken) ||
	said( get, chicken, feather) ||
	said( pluck, chicken) ||
	said( pluck, feather) ||
	said( pluck, chicken, feather) ||
	said( pluck, feather, from, chicken) ||
	said( pull, feather) ||
	said( pull, chicken, feather) ||
	said( pull, feather, from, chicken)))
	{
	if (!obj.in.room( i.chicken.feather, current.room))
		{
		print( 24);
		}
	else
		{
		if (!chick.in.hand)
			{
			print( 21);
			}
		else
			{
			get( i.chicken.feather);
			score += 1;
			set( drop.chicken);
			print( 22);
			}
		}
	}

if ((said( look, bag) ||
	said( look$in, bag) ||
	said( look, feed, bag) ||
	said( look$in, feed, bag) ||
	said( look, bag, feed) ||
	said( look$in, bag, feed) ||
	said( look, chicken, feed, bag) ||
	said( look$in, chicken, feed, bag) ||
	said( look, bag, chicken, feed) ||
	said( look$in, bag, chicken, feed)))
	{
	if (ego.location != feed.bag)
		{
		print( 25);
		}
	else
		{
		print( 26);
		}
	}

if (said( eat, chicken))
	{
	print( 32);
	}

if ((said( get, feed) ||
	said( get, feed, bag) ||
	said( get, feed, from, bag) ||
	said( get, grain) ||
	said( get, grain, bag) ||
	said( get, grain, from, bag) ||
	said( get, chicken, feed) ||
	said( get, chicken, feed, bag) ||
	said( get, chicken, feed, from, bag)))
	{
	print( 27);
	}

if ((said( feed, chickens) ||
	said( get, feed, feed, chickens) ||
	said( get, chicken, feed, feed, chickens) ||
	said( feed, chickens, feed) ||
	said( give, feed, chickens) ||
	said( get, feed, throw, chickens) ||
	said( throw, feed, chickens) ||
	said( give, feed) ||
	said( throw, feed) ||
	said( get, chicken, feed, feed, chickens) ||
	said( feed, chickens, chicken, feed) ||
	said( give, chicken, feed, chickens) ||
	said( get, chicken, feed, throw, chickens) ||
	said( throw, chicken, feed, chickens) ||
	said( give, chicken, feed) ||
	said( throw, chicken, feed)))
	{
	if (ego.location != feed.bag)
		{
		print( 10);
		}
	else
		{
		if (handsOff)
			{
			print( 1);
			}
		else
			{
			set( handsOff);
			program.control();
			stop.motion( ego);
			reposition.to( ego, 95, 104);
			feed.script = 0;
			set( feed.arrived);
	
			set( keep.cycling);
			set.view( ego, v.ego.feeding.chickens);
			set.loop( ego, l.ego.throwing);
			work = 2;
			cycle.time( ego, work);
	
			chick.1.wander = 0;
			chick.2.wander = 0;
			follow.ego( a.chick.1, 8, chick.1.arrived);
			follow.ego( a.chick.2, 10, chick.2.arrived);
			ignore.objs( a.chick.2);
			chicken.feed.timer = chicken.feeding.time;
	
			if (chore.to.do == feed.chickens)
				{
				chore.to.do = 0;
				chore.minutes = 0;
				chore.seconds = 0;
				}
			}
		}
	}


[*****
:no.input
[*****

if (aSecondPassed)
	{
	--chicken.feed.timer;
	if (chicken.feed.timer == 1)
		{
		chicken.feed.timer = 0;
		chicken.eating.timer = 11;
		set.view( ego, v.ego);
		start.motion( ego);
		reset( keep.cycling);
		player.control();
		reset( handsOff);
		cycle.time( ego, ego.cycle.time);
		reset( feed.arrived);
		feed.script = 0;
		reset( no.script);
		erase( a.feed);
		}

	--chicken.eating.timer;
	if (chicken.eating.timer == 1)
		{
		reset( chick.1.eating);
		reset( chick.2.eating);
		observe.objs( a.chick.1);
		observe.objs( a.chick.2);
		chick.1.wander = 2;
		chick.2.wander = 2;
		}
	}

if (chicken.feed.timer)
	{
	if (feed.arrived)
		{
		reset( feed.arrived);
		++feed.script;

		if (feed.script == 1)
			{
			set.cel( ego, 0);
			set( keep.cycling);
			end.of.loop( ego, feed.arrived);
			}

		if (feed.script == 2)
			{
			reset( keep.cycling);
			set.cel( a.feed, 0);
			draw( a.feed);
			end.of.loop( a.feed, feed.arrived);
			}

		if (feed.script == 3)
			{
			[	add a little corn to the ground
			view = 21;
			loop = 2;
			cell = 0;
			random( 93, 99, x);
			random( 111, 116, y);
			priority = 10;
			work = 4;
			add.to.pic.v( view, loop, cell, x, y, priority, work);
			feed.script = 0;
			set( feed.arrived);
			set( no.script);
			}
		}
	}


if (chick.1.arrived)
	{
	reset( chick.1.arrived);
	stop.motion( a.chick.1);
	set( chick.1.eating);
	set.view( a.chick.1, v.chicken.eating);
	}

if (chick.2.arrived)
	{
	reset( chick.2.arrived);
	stop.motion( a.chick.2);
	set( chick.2.eating);
	set.view( a.chick.2, v.chicken.eating);
	observe.objs( a.chick.2);
	}


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


if (aSecondPassed && 
	animal.start &&
	current.status == normal.ego &&
	seconds.in.room == talk.seconds)	[	start jabbering
	{
	talk.seconds = 0;
	set.v( flag.to.set);

	:animal.talk
	print.v( animal.start);
	if (animal.start < animal.stop)
		{
		++animal.start;
		goto animal.talk;
		}
	}


if (ego.arrived)					[	walk ego through the gate
	{
	reset( ego.arrived);
	++ego.script;
	program.control();

	if (ego.script == 1)
		{
		start.update( a.gate);
		end.of.loop( a.gate, done);
		ignore.blocks( ego);
		set( handsOff);

		if (ego.location == outside.gate)
			{
			gate.source.x = 84;
			gate.source.y = 125;
			gate.target.x = 96;
			gate.target.y = 125;
			set( inside.pen);
			}
		else
			{
			if (ego.location == inside.gate)
				{
				gate.source.x = 96;
				gate.source.y = 125;
				gate.target.x = 84;
				gate.target.y = 125;
				reset( inside.pen);
				}
			}

		step = 1;
		move.obj.v( ego, gate.source.x, gate.source.y, step, ego.arrived);
		}
	
	if (ego.script == 2)
		{
		move.obj.v( ego, gate.target.x, gate.target.y, step, ego.arrived);
		}
	
	if (ego.script == 3)
		{
		observe.blocks( ego);
		beginning.of.loop( a.gate, ego.arrived);
		}
	
	if (ego.script == 4)
		{
		reset( handsOff);
		player.control();
		ego.script = 0;
		}
	}		
	

if (door.open.done)
	{
	reset( door.open.done);
	reset( handsOff);
	set( goto.rm7);
	}


if (hit.special)
	{
	start.climbing = falling;
	if (ego.y < 138)
		{
		set.priority( ego, 5);
		room.bottom = 146;			[	fall off backside
		}
	else
		{
		set.priority( ego, 14);
		room.bottom = 166;
		}
	call( lgc.climbing);
	}

if (drop.chicken)
	{
	reset( drop.chicken);
	reset( handsOff);
	set.view( ego, v.ego);
	force.update( ego);
	if (chick.in.hand == 1)
		{
		position.v( a.chick.1, chick.x, chick.y);
		draw( a.chick.1);
		}
	else
		{
		position.v( a.chick.2, chick.x, chick.y);
		draw( a.chick.2);
		}
	chick.in.hand = 0;
	}


if (ego.poofing.done)
	{
	set( inside.pen);
	}


[*****
:exit							[	test for leaving the room
[*****

call( lgc.wiz.house);
call( lgc.climbing);

if (goto.rm7)						{new.room( 7);}
if (edge.ego.hit == bottom)			{new.room( 33);}

