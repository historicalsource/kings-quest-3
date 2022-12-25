[logics for room 14 -- outside Oracle's cave 

%include	"gamedefs.al"
%include	"rm14.msg"



%define	rm.oracle.cave			36

%define	web.priority			8
%define	spider.priority		8
%define	c.web.ok				0
%define	c.web.broken			1
%define	spider.chew.time		5

%define	spider.x.offset		8
%define	spider.y.offset		9


%define	next.spider.move		lf0
%define	spider.here			lf1
%define	local.control			lf2
%define	in.cave				lf3
%define	eagle.script.done		lf4
%define	near.cave				lf5


%define	eagle.script			lv0
%define	spider.script			lv1
%define	spider.seconds			lv3


%object	a.spider				1
%object	a.water				2



if (init.log)
	{
	if ((storm.minutes || storm.seconds) && previous.room == 36)
		{
		pre.previous.room = previous.room;
		new.room( 87);
		}

	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	map.area = map.llewdor;
	set( beenIn14);
	set.horizon( 52);
	landing.x = 42;
	landing.y = 124;


	load.view( v.ego);
	load.view( v.ego.wading.shallow);
	load.view( v.water.rm14)
	load.view( v.spider.web);

	if (!spider.dead)
		{
		load.view( v.spider);
		load.view( v.spider.eating.ego);
		}

	load.logics( lgc.forest);
	load.logics( lgc.stream.mud);


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);
		

	animate.obj( a.water);
	position( a.water, 40, 154);
	set.view( a.water, v.water.rm14);
	work = 3;
	cycle.time( a.water, work);
	ignore.objs( a.water);
	set.priority( a.water, 4);
	draw( a.water);

	if (spider.dead)
		{
		add.to.pic( v.spider.web, 0, c.web.broken, 83, 79, web.priority, 4);
		}
	else							[	"Hi, spider!"
		{
		add.to.pic( v.spider.web, 0, c.web.ok, 83, 79, web.priority, 4);

		animate.obj( a.spider);
		set.view( a.spider, v.spider);
		position( a.spider, 87, 20);
		ignore.horizon( a.spider);
		work = 3;
		cycle.time( a.spider, work);
		set.priority( a.spider, spider.priority);
		}

 
	if (positionEgo)
		{
		if (previous.room == 13)
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

		if (previous.room == 15)
			{
			if (ego.y > 69 && ego.y < 88)
				{
				ego.y = 88;
				}
			}

		if (previous.room == 19)
			{
			if (ego.x < 56)
				{
				ego.x = 56;
				}
			}

		if (previous.room == 36)
			{
			ego.x = 92;
			ego.y = 86;
			}

		position.v( ego, ego.x, ego.y);
		}

	if (drawEgo)
		{
		draw( ego);
		}


 	call( lgc.stream.mud);
	call( lgc.forest);

	show.pic();
	return();

	}



[****
[Where is Ego?
[****

if ((posn(ego, 0, 133, 35, 149) ||
	posn(ego, 48, 156, 61, 167)))
	{
	set( on.water);
	}

reset( near.mud);
reset( near.water);
if ((posn( ego, 35, 133, 74, 167) ||
	posn( ego, 75, 146, 95, 167) ||
	posn( ego, 35, 125, 55, 132)))
	{
	set( near.mud);
	set( near.water);
	}

if (on.water)
	{
	set( near.water);
	reset( near.mud);
	}

reset( near.cave);
if (posn( ego, 76, 88, 114, 96))
	{
	set( near.cave);
	}



[*****
[handle.input
[*****

if (local.control && spell.cast == sc.stop.flying)
	{
	spell.cast = 0;
	print( 16);
	}


if (have.input)
	{
	if (said( look))
		{
		print( 7);
		}

	if (said( look, tree))
		{
		print( 10);
		}

	if (said( look$in, cave))
		{
		print( 6);
		}

	if ((said( cut, web) ||
		said( tear, web) ||
		said( tear, web, with, knife) ||
		said( cut, web, use, knife)))
		{
		print( 5);
		}

	if ((said( look, cave) ||
		said( look, hole)))
		{
		if (!spider.dead)
			{
			print( 1);
			}
		else
			{
			print( 2);
			}
		}	 
											
	if ((said( look, web) ||
		said( look, spider, web) ||
		said( look$in, spider, web) ||
		said( look$in, web)))
		{
		if (!spider.dead)
			{
			print( 3);
			}
		else
			{
			print( 12);
			}
		}

	if (said( look, spider))
		{
		print( 4);
		}

	if  (has( i.knife) &&
	    (said( throw, knife) ||
		said( throw, knife, spider) ||
		said( kill, spider, knife) ||
		said( throw, knife, spider, web) ||
		said( throw, knife, web)))
		{
		work = rm.oracle.cave;
		put( i.knife, work);
		print( 8);			[You throw the knife with true aim
		print( 9);			[it dissappears into the cave and clatters on the floor.
		}
	}


[*****
:no.input
[*****

if  (current.status != eagle &&
    !handsOff && 
	hit.special)
	{
	if (spider.dead)
		{
		set( in.cave);				[	new room to oracle
		}
	else
		{
		if (!spider.script)
			{
			set( next.spider.move);
			spider.script = 0;
			}
		}
	}

if  (current.status == fly && 
    !spider.dead &&
    !spider.script &&	
	posn( ego, 85, 31, 107, 85))
	{
	set( next.spider.move);
	spider.script = 100;
	}


if (aSecondPassed)
	{
	--spider.seconds;
	if (spider.seconds == 1)
		{
		set( next.spider.move);
		}
	}
	

if (next.spider.move)
	{
	reset( next.spider.move);
	++spider.script;

	set( handsOff);
	program.control();
	step = 1;

			
	if (spider.script == 1)			[	THIS SCRIPT FOR NORMAL EGO.
		{
		stop.motion( ego);
		prevent.input();

		draw( a.spider);
		move.obj( a.spider, 87, 48, 1, next.spider.move);
		print.at( 14, 14, 2, 37);
		}

	if (spider.script == 2)
		{
		x = ego.x;
		x -= 7;
		y = 62;
		move.obj.v( a.spider, x, y, step, next.spider.move);
		}

	if (spider.script == 3)
		{
		work = spider.chew.time;
		cycle.time( a.spider, work);
		set.view( a.spider, v.spider.eating.ego);
		x = 0
		y = 20;
		reposition( a.spider, x, y);
		set.cel( a.spider, 0);
		end.of.loop( a.spider, next.spider.move);
		erase( ego);
		}

	if (spider.script == 4)
		{
		spider.seconds = 4;
		set.view( a.spider, v.spider);
		x = 0;
		y = -20;
		reposition( a.spider, x, y);
		start.cycling( a.spider);
		}

	if (spider.script == 5)
		{
		block( 83, 53, 95, 70);
		observe.block( a.spider);
		normal.motion( a.spider);
		start.motion( a.spider);
		wander( a.spider);
	  	set( certain.death);
		}



	if (spider.script == 101)		[	THIS SCRIPT FOR EGO AS FLY.
		{
		stop.motion( ego);
		prevent.input();

		draw( a.spider);
		move.obj( a.spider, 87, 48, 1, next.spider.move);
		print.at( 14, 14, 2, 37);
		erase( ego);
		}

	if (spider.script == 102)
		{
		x = ego.x;
		x -= 7;
		y = 62;
		move.obj.v( a.spider, x, y, step, next.spider.move);
		}

	if (spider.script == 103)
		{
		print( 11);
		move.obj( a.spider, 87, 62, 1, next.spider.move);
		}

	if (spider.script == 104)
		{
		spider.seconds = 4;
		}

	if (spider.script == 105)
		{
		block( 83, 53, 95, 70);
		observe.block( a.spider);
		normal.motion( a.spider);
		start.motion( a.spider);
		wander( a.spider);
	  	set( certain.death);
		}
	}	



[*****
[Eagle 1, Spider 0
[*****

if  (eagle.script &&
	eagle.script < 4)				[	carry the spider along		
	{
	x = ego.x;
	y = ego.y;
	x += spider.x.offset;
	y += spider.y.offset;
	reposition.to.v( a.spider, x, y);
	}


if (current.status == eagle)
	{
	if  (posn( ego, 32,  0, 159, 96) &&	[	mouth of cave
    	    !eagle.script &&   
	    !spider.here &&	
	    !spider.dead)
		{
		set( spider.here);
		set.loop( a.spider, 0);
		position( a.spider, 88, 52);
		set.priority( a.spider, 15);
		draw( a.spider);
		}

	if (spider.here && !spider.dead)
		{
		if (posn( ego, 60, 38, 79, 78))
			{
			set( local.control);
			program.control();
			set( spider.dead);
			score += 4;
			move.obj( ego, 79, 43, 2, eagle.script.done);
			}
		else
			{
			if (posn( ego, 80, 38, 120, 78))
				{
				program.control();
				set( spider.dead);
				score += 4;
				move.obj( ego, 98, 43, 2, eagle.script.done);
				}
			}
		}
	}

if (aSecondPassed && eagle.script)
	{
	magic.seconds = 6;				[	force timer not to end flight
	magic.minutes = 0;
	}

if (eagle.script.done)
	{
	reset( eagle.script.done);
	++eagle.script;
	program.control();
	prevent.input();
	set.priority( ego, 15);

	if (eagle.script == 1)			[	draw spider
		{
		set( handsOff);
		start.cycling( a.spider);
		add.to.pic( v.spider.web, 0, c.web.broken, 83, 79, web.priority, 4);
		print.at( 15, 4, 2, 37);
		move.obj( ego, 132, 35, 2, eagle.script.done);
		}

	if (eagle.script == 2)
		{
		work = 15;
		load.pic( work);
		draw.pic( work);
		discard.pic( work);

		x = 2;
		y = 30;
		reposition.to.v( ego, x, y);
		x += spider.x.offset;
		y += spider.y.offset;
		reposition.to.v( a.spider, x, y);
		erase( a.water);
		show.pic();

		move.obj( ego, 132, 35, 2, eagle.script.done);
		}

	if (eagle.script == 3)
		{
		load.view( v.splash);
		load.sound( s.splash);
		work = 31;
		load.pic( work);
		draw.pic( work);
		discard.pic( work);

		x = 2;
		y = 30;
		reposition.to.v( ego, x, y);
		x += spider.x.offset;
		y += spider.y.offset;
		reposition.to.v( a.spider, x, y);
		show.pic();

		move.obj( ego, 50, 35, 2, eagle.script.done);
		}

	if (eagle.script == 4)
		{
		move.obj( a.spider, 90, 80, 2, eagle.script.done);
		}

	if (eagle.script == 5)
		{
		set.view( a.spider, v.splash);
		set.cel( a.spider, 0);
		work = 2;
		cycle.time( a.spider, work);
		end.of.loop( a.spider, eagle.script.done);
		sound( s.splash, done);
		}

	if (eagle.script == 6)
		{
		erase( a.spider);
		move.obj( ego, 2, 35, 2, eagle.script.done);
		}

	if (eagle.script == 7)
		{
		work = 15;
		load.pic( work);
		draw.pic( work);
		discard.pic( work);

		reposition.to( ego, 126, 35);
		show.pic();

		move.obj( ego, 2, 35, 2, eagle.script.done);
		}

	if (eagle.script == 8)
		{
		work = 14;
		load.pic( work);
		draw.pic( work);
		discard.pic( work);

		add.to.pic( v.spider.web, 0, c.web.broken, 83, 79, web.priority, 4);
 
		reposition.to( ego, 126, 35);
		draw( a.water);

		show.pic();
		eagle.script = 0;
		reset( local.control);
		[	Since we'll now no longer reset magic.seconds, the timer will
		[	run out normally, and we'll let room 0 land him!
		}
	}


[*****
[exit							[	test for leaving the room
[*****

call( lgc.stream.mud);
call( lgc.forest);

if (edge.ego.hit == left)			{new.room( 13);}
if (edge.ego.hit == right)			{new.room( 15);}
if (edge.ego.hit == bottom)			{new.room( 19);}
if (edge.ego.hit == top)				{new.room( 29);}
if (in.cave)						{new.room( 36);}

