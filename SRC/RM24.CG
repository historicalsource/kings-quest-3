[logics for room 24 -- on the Town

%include "gamedefs.al"
%include "rm24.msg"



%define	inside.store			1
%define	near.store			2
%define	near.tavern			3
%define	on.the.brink			4

%define	stun.time				50
%define	l.tavern.sign			0
%define	l.store.sign			1


%define	cliff.done			lf1
%define	poked.eye				lf2
%define	sound.done			lf3

%define	open.store.door		lf4
%define	store.door.open.done	lf5
%define	store.door.open		lf6
%define	enter.store			lf7
%define	close.store.door		lf8
%define	store.door.close.done	lf9

%define	open.tavern.door		lf10
%define	tavern.door.open.done	lf11
%define	tavern.door.open		lf12
%define	enter.tavern			lf13
%define	close.tavern.door		lf14
%define	tavern.door.close.done	lf15
%define	near.window			lf16


%define	tavern.timer			lv0


%object	a.smoke				1
%object	a.tavern.door			2
%object	a.store.door			3



if (init.log)
	{
	if ((storm.minutes || storm.seconds) && 
		(previous.room == 39 || previous.room == 40))
		{
		pre.previous.room = previous.room;
		new.room( 87);
		}

	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	map.area = map.llewdor;
	set( beenIn24);
	set.horizon( 56);
	wiz.x = 137;
	wiz.y = 100;

	random( 2, 3, work);
	if (work == 2)
		{
		landing.x = 117;
		landing.y = 100;
		}
	else
		{
		landing.x = 28;
		landing.y = 151;
		}


	load.view( v.ego);
	load.view( v.smoke);	
	load.view( v.door.rm24);
	load.logics( lgc.forest);
	load.logics( lgc.climbing);

	[	DON'T MUCK WITH THIS BLOCK, BECAUSE OF DISCARD.VIEW'S.

	load.view( v.signs.rm24);
	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);
	add.to.pic( v.signs.rm24, l.tavern.sign, 0, 112, 37, 14, 4);
	add.to.pic( v.signs.rm24, l.store.sign, 0, 82, 71, 14, 5);
	discard.view( v.signs.rm24);


	animate.obj( a.tavern.door);
	set.view( a.tavern.door, v.door.rm24);
	set.loop( a.tavern.door, 0);
	set.cel( a.tavern.door, 0);
	set.priority( a.tavern.door, 8);
	position( a.tavern.door, 117, 81);
	draw( a.tavern.door);
	stop.update( a.tavern.door);


	animate.obj( a.store.door);
	set.view( a.store.door, v.door.rm24);
	set.loop( a.store.door, 1);
	set.cel( a.store.door, 0);
	set.priority( a.store.door, 11);
	stop.cycling( a.store.door);
	ignore.objs( a.store.door);
	position( a.store.door, 75, 129);
	draw( a.store.door);


	animate.obj( a.smoke);
	ignore.horizon( a.smoke);
	set.priority( a.smoke, 14);
	set.view( a.smoke, v.smoke);
	set.loop( a.smoke, 1);
	work = 5;
	cycle.time( a.smoke, work);
	position( a.smoke, 32, 15);
	draw( a.smoke);


	if ((previous.room == 39 ||
		previous.room == 40))
		{
		set( positionEgo);
		}

	if (positionEgo)
		{
		if (previous.room == 39)		[	from the store
			{
			ego.x = 80;
			ego.y = 129;
			start.cycling( a.store.door);
			last.cel( a.store.door, work);
			set.cel.f( a.store.door, work);
			beginning.of.loop( a.store.door, store.door.close.done);
			}

		if (previous.room == 40)		[	from the tavern
			{
			ego.x = 119;
			ego.y = 84;
			start.update( a.tavern.door);
			last.cel( a.tavern.door, work);
			set.cel.f( a.tavern.door, work);
			start.update( a.tavern.door);
			beginning.of.loop( a.tavern.door, tavern.door.close.done);
			}

		if (previous.room == 23)
			{
			if (ego.y > 57 && ego.y < 61)
				{
				ego.y = 61;
				}
			}

		if (previous.room == 25)
			{
			if (ego.y < 91)
				{
				ego.y = 91;
				}
			}

		if (previous.room == 20)
			{
			ego.x = 90;
			ego.y = 66;
			}

		position.v( ego, ego.x, ego.y);
		}


	if (drawEgo)
		{
		draw( ego);
		}
					   
	call( lgc.climbing);
	call( lgc.forest);

	show.pic();

	return();

	}


reset( near.window);
if ((posn( ego,  98,  84, 108,  91) ||
	posn( ego, 127,  84, 141,  91) ||
	posn( ego,  84, 110,  99, 123) ||
	posn( ego,  38, 139,  53, 152) ||
	posn( ego,  11, 132,  37, 144)))
	{
	set( near.window);
	}


if ((posn( ego, 109,  84, 131,  96) ||	[	in front of tavern door.
	posn( ego,  80, 106,  96, 110)) &&	[	behind the store.
	current.ego != eagle &&
	current.ego != fly)
	{
	set.priority( ego, 9);
	}
else
	{
	release.priority( ego);
	}


if  (posn( ego, 111, 114, 141, 118) &&
	current.status != eagle &&
	current.status != fly &&
    (ego.dir == ego.right || 
	ego.dir == ego.down.right || 
	ego.dir == ego.down.left || 		[	Ego is walking on the side of 
	ego.dir == ego.left))			[the boardwalk, and defying gravity...
	{
	y = 119;
	reposition.to.f( ego, ego.x, y);	[... so slip him off the edge.
	}


ego.location = nowhere;				[NOTE: sequence dependent:
if (posn( ego, 64, 123, 82, 131))		{ego.location = near.store;}
if (posn( ego, 68, 124, 70, 130))		{ego.location = inside.store;}
if (posn( ego, 108, 83, 126, 86))		{ego.location = near.tavern;}
if (posn( ego, 145, 131, 158, 167))	{ego.location = on.the.brink;}

if (current.status == fly)
	{
	if  (posn( ego, 115, 76, 126, 82) &&
		tavern.door.open)
		{
		set( enter.tavern);
		}

	if  (posn( ego, 68, 116, 73, 131) &&
		store.door.open)
		{
		set( enter.store);
		}
	}

if (!poked.eye &&
	ego.dir == ego.right &&
	ego.x == 30 &&
	ego.y == 151)
	{
	set( poked.eye);
	print( 10);
	}


observe.blocks( ego);
if (store.door.open && 
	posn( ego, 60, 124, 86, 131))
	{
	ignore.block( ego);
	}


[*****
:handle.input
[*****

if (have.input)
	{
	if (said( look, ground))
		{
		print( 16);
		}

	if ((said( look) ||
		said( look, town) ||
		said( look, buildings)))
		{
		print( 1);
		}

	if (said( look, store))
		{
		print( 2);
		}
	if (said( look, trees))
		{
		print( 18);
		}
	
	
	if (said( look, tavern))
		{
		print( 3);
		}

	if (said( look, door))
		{
		print( 14);
		}

	if (said( look, pier))
		{
		if (shipShape == inPort)
			{
			print( 4);
			}
		else
			{
			print( 5);
			}
		}

	if (said( look, under, pier))
		{
		print( 6);
		}

	if ((said( look, anchor) ||
		said( get, anchor)))
		{
		print( 7);
		}

	if ((said( look, window) ||
		said( look$in, window) ||
		said( look, window, anyword)))
		{
		if (near.window)
			{
			print( 8);
			}
		else
			{
			print( 15);
			}
		}

	if ((said( open, window) ||
		said( break, window)))
		{
		print( 9);
		}

	if ((said( knock, anyword, door) ||
		said( knock, door, anyword) ||
		said( knock, door) ||
		said( knock)))
		{
		if ((ego.location == near.tavern ||
			ego.location == near.store))
			{
			print( 13);
			}
		else
			{
			print( 12);
			}
		}
	

	if ((said( open, tavern, door) ||
		said( open, door) ||
		said( open, door, tavern)))
		{
		if (ego.location == near.tavern)
			{
			if (tavern.door.open)
				{
				print( 11);
				}
			else
				{
				set( open.tavern.door);
				}
			}
		else
			{
			reset( have.match);
			if (ego.location != near.store &&
				said( open, door))
				{
				print( 12);
				}
			}
		}

	if ((said( open, store, door) ||
		said( open, door) ||
		said( open, door, store)))
		{
		if (ego.location != near.store)
			{
			print( 12);
			}
		else
			{
			if (store.door.open)
				{
				print( 11);
				}
			else
				{
				set( open.store.door);
				}
			}
		}


	if ((said( close, tavern, door) ||
		said( close, door) ||
		said( close, door, tavern)))
		{
		if (ego.location == near.tavern)
			{
			if (!tavern.door.open)
				{
				print( 17);
				}
			else
				{
				set( close.tavern.door);
				}
			}
		else
			{
			reset( have.match);
			if (ego.location != near.store &&
				said( close, door))
				{
				print( 12);
				}
			}
		}

	if ((said( close, store, door) ||
		said( close, door) ||
		said( close, door, store)))
		{
		if (ego.location != near.store)
			{
			print( 12);
			}
		else
			{
			if (!store.door.open)
				{
				print( 11);
				}
			else
				{
				set( close.store.door);
				}
			}
		}
	}							[	end have.input


[*****
:no.input
[*****

if (open.tavern.door)
	{
	reset( open.tavern.door);
	set.priority( ego, 9);
	start.update( a.tavern.door);
	end.of.loop( a.tavern.door, tavern.door.open.done);
	}

if (tavern.door.open.done)
	{
	reset( tavern.door.open.done);
	set( tavern.door.open);
	stop.update( a.tavern.door);
	release.priority( ego);
	}

if (close.tavern.door)
	{
	reset( close.tavern.door);
	set.priority( ego, 9);
	start.update( a.tavern.door);
	beginning.of.loop( a.tavern.door, tavern.door.close.done);
	}

if (tavern.door.close.done)
	{
	reset( tavern.door.close.done);
	reset( tavern.door.open);
	stop.update( a.tavern.door);
	release.priority( ego);
	}


if (open.store.door)
	{
	reset( open.store.door);
	start.cycling( a.store.door);
	end.of.loop( a.store.door, store.door.open.done);
	}

if (store.door.open.done)
	{
	reset( store.door.open.done);
	set( store.door.open);
	stop.cycling( a.store.door);
	}

if (close.store.door)
	{
	reset( close.store.door);
	start.cycling( a.store.door);
	beginning.of.loop( a.store.door, store.door.close.done);
	}

if (store.door.close.done)
	{
	reset( store.door.close.done);
	reset( store.door.open);
	stop.cycling( a.store.door);
	}


if (ego.location == near.tavern &&
	tavern.door.open &&
	current.status != eagle &&
    (ego.dir == ego.up ||
	ego.dir == ego.up.right ||
	ego.dir == ego.up.left))
	{
	set( enter.tavern);
	}


if (ego.location == inside.store &&
	current.status != eagle &&
	store.door.open)
	{
	set( enter.store);
	}

if  (hit.special &&
	ego.location == on.the.brink)		[	fall down cliff
	{
	ego.x = ego.falling.limit;
	reposition.to.v( ego, ego.x, ego.y);
	start.climbing = falling;
	}
	
if (cliff.done)
	{
	new.room( 30);
	}


[*****
:exit							[	test for leaving the room
[*****

if (enter.store)					{new.room( 39);}
if (enter.tavern)					{new.room( 40);}
if (edge.ego.hit == top)				{new.room( 19);}
if (edge.ego.hit == left)			{new.room( 23);}
if (edge.ego.hit == right)			{new.room( 25);}
if (edge.ego.hit == bottom)
	{
	if (current.status == falling)
		{
		new.room( 30);
		}
	else
		{
		new.room( 29);
		}
	}
call( lgc.climbing);
call( lgc.forest);

