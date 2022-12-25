[logics for room --  32: desert trap

#include "gamedefs.reh"
#include "rm32.msg"



[put in a rock with a scorpion, for old time's sake


[ if first edge hit is right we return to previous.room
[ if wandered once we go to 1 in 15 chance of good random return
[	on right edge hit (only)
[ wander before thirst death is 3 minutes
[ warning preceeds death
[ if eagle, odds are increased


#define	thirsty				2
#define	die					3	[need to be bigger
							
#define	death.watch			lv0
#define	box					lv1
#define	buzzard.x				lv3
#define	buzzard.y				lv4
#define	return.room			lv5
#define	odds					lv6	[ modified by status of ego

#define	snake.here			lf0
#define	ego.dying				lf1
#define	redraw.pic			lf3		[ simulate a new room
#define	buzzard.here			lf4



	
#object	a.buzzards			1



if (init.log){
	map.area = map.llewdor;
	set.horizon(65);

	wiz.x = 90;
	wiz.y = 0;

	landing.x = 21;
	landing.y = 69;

	load.view.f(current.ego);
	set.view.f(ego, current.ego);

	load.view(v.ego);
	load.view(v.ego.collapsing);
	load.view(v.ego.dead);

	load.view(v.buzzards);
	load.view(v.cactii);
	load.view(v.buzzards);
	load.view(v.rocks);
	load.view(v.skulls);
	load.view(v.hills);

	load.logics(lgc.desert);

	load.pic(current.room);
	draw.pic(current.room);

	call(lgc.desert);

	if (previous.room != current.room){	[ first entry
		reset(wandered);
		desert.seconds = 0;
		desert.minutes = 0;
		if (current.status == poofing){
			previous.room = 32;		[ can't get out
		}
		land.room = previous.room;
		mountain.x = 60;			[ centered
	}

	if (drawEgo){
		draw(ego);
	}


	[****
	[Place the props
	[*****	

[
[
	priority = 0;
	box = 0;
[
[ do some random cactii
	
	random(1, 3, work);
	loop = 0;
	view = 243;
:do.cactus		
	if (work){
		--work;
		random( 0, 137, x);
		random( 112, 165, y);
		random(0, 3, cell);
		add.to.pic.f(view, loop, cell, x, y, priority, box);
		goto do.cactus;
	}


[ add some random rocks
	
	random( 1, 6, work);
	view = 244;
	loop = 0;
:do.rock		
	if (work){
		--work;
		random( 0, 148, x);
		random( 86, 160, y);
		random( 0, 2, cell);
		add.to.pic.f(view, loop, cell, x, y, priority, box);
		goto do.rock;
	}

[ Skulls-a-poppin'

	random( 0, 4, cell);
	loop = 0;
	view = 245;

	if (cell < 2)
		{
		random(1, 140, x);
		random(90, 110, y);
		add.to.pic.f(view, loop, cell, x, y, priority, box);
		}

	if (cell == 2)
		{
		random(1, 120, x);
		random(90, 140, y);
		add.to.pic.f(view, loop, cell, x, y, priority, box);
		}

	view = 248;
	random(1, 10, work);
	if (work < 4){			[flying buzzards
		set(buzzard.here);
		animate.obj(a.buzzards);
		load.view(v.buzzards);
		set.view(a.buzzards, v.buzzards);
		y = 4;
		cycle.time(a.buzzards, y);
		ignore.horizon(a.buzzards);
	   	random(20, 100, x);
		y = 20;
		position.f(a.buzzards, x, y);
		set.loop(a.buzzards, 0);
		draw(a.buzzards);
	}
[
[	if (work == 1)			[buzzards on cactus
[		{
[		cell = 3;
[		loop = 0;
[		random (0, 130, x);
[		random(125, 167, y);
[		view = 243;
[		add.to.pic.f(view, loop, cell, x, y, priority, box);
[
[		box = 5;
[		priority = 15;
[		buzzard.x = x;
[		buzzard.y = y;
[		addn(buzzard.x, 8);
[		subn(buzzard.y, 50);
[		cell = 0;
[		loop = 1;
[		view = 248;
[		add.to.pic.f(view, loop, cell, buzzard.x, buzzard.y, priority, box);
[
[		random(1, 2, work);
[		if (work == 1)
[			{
[			buzzard.x = x;
[			buzzard.y = y;
[			subn(buzzard.x, 1);
[			subn(buzzard.y, 36);
[			add.to.pic.f(view, loop, cell, buzzard.x, buzzard.y, priority, box);
[			}
[
[		random(1, 2, work);
[		if (work == 1)
[			{
[			buzzard.x = x;
[			buzzard.y = y;
[			addn(buzzard.x, 17);
[			subn(buzzard.y, 42);
[			add.to.pic.f(view, loop, cell, buzzard.x, buzzard.y, priority, box);
[			}
[
[		priority = 0;
[		box = 0;
[		}
[
[	[*****
[	[hills	Mountain grown Columbian!
[	[*****
[
[ add one mountain

	box = 0;
	priority = 5;
	random(1, 10, work);
	--work;
	loop = 0;
	cell = 0;
	y = 44;		[ 1 line above horizon

	view = 246;
	add.to.pic.f(view, loop, cell, mountain.x, y, priority, box);
		

	show.pic();
	return();
}

[ main(argc, argv)		/* a real structured language would be nice */

if (said(look, ground)){
	print(12);
}



if (said(look, mountain)){
	print(6);
}

if ((said(drink) ||
	said(get, drink) ||
	said(drink, water) ||
	said(drink, ocean, water)))
	{
	if (has(i.ocean.water)) {
		print(2);
		drop(i.ocean.water);
	} else {
		print(3);
	}
}


if ((said(look) || said(look, desert))){
	if (!wandered){
		print(10);
	} else {
		print(1);
	}
}

if ((said(get,bird) || said(look, bird))){
	print(11);
}



call(lgc.desert);


if (aSecondPassed){
	if (desert.seconds < 60){
		++desert.seconds;
	} else {
		desert.seconds = 0;
		++desert.minutes;
	}
}

if (desert.minutes == thirsty && desert.seconds == 0) {
	++desert.seconds;
	print.at(4, 2, 2, 37);
}

if (current.status == normal.ego
   && desert.minutes == die && desert.seconds == 0) {
	++desert.seconds;
	program.control();
	start.motion(ego);
	set(keep.cycling);
	set(handsOff);
	if (!debugging){
		prevent.input();
	}

	set.view(ego, v.ego.collapsing);
	set.cel(ego, 0);
	work = 2;
	cycle.time(ego, work);
	end.of.loop(ego, ego.dying);
}

if (ego.dying) {
	reset(ego.dying);
	set(hands.off);
	set.view(ego, v.ego.dead)
	death.watch = 100;
	print.at(5, 2, 2, 37);
	program.control();
}

-- death.watch;
if (death.watch == 1){
	stop.cycling(ego);
	set(certain.death);
}


[ adjust odds of getting out of room
if (current.status == eagle){
	odds = 6;	
} else {
	odds = 15;
}



[*****
[exit							[	test for leaving the room
[*****
if (edge.ego.hit == left){
	set(wandered);
	mountain.x += 2;	[ move the mountain
	if (mountain.x > 118){
		mountain.x = 118;
	}
	new.room(32);
}

if ((edge.ego.hit == top || edge.ego.hit == bottom)){
	set(wandered);
	new.room(32);
}

if (edge.ego.hit == right){
	if (!wandered){
		new.room.f(land.room);		[ smart move
	} else {
		mountain.x -= 2;
		random(1, 15, work);
		if (work < odds){			[ better odds if you are an eagle
			new.room(32);
		} else {					[ pic a room to go to
			random(1,4,work);
			if (work == 1){
				new.room(11);
			}
			if (work == 2){
				new.room(16);
			}
			if (work == 3){
				new.room(21);
			}
			if (work == 4){
				new.room(26);
			}
		}
	}
}
	
