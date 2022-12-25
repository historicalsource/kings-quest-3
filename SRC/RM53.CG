[logics for room 53 -- Further along mountain path. 

%include	"rm53.msg"
%include	"gamedefs.reh"



%object	aWater1				1
%object	aWater2				2
%object	aWater3				3
%object	aWater4				4
%object	aWater5				5



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.mountains;
	set( beenIn53);
	landing.x = 111;
	landing.y = 45;

	set.horizon( 35);

	load.logics( lgc.climbing);
	room.bottom = 166;
	load.view( v.water.rm53);


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	animate.obj( aWater1);
	set.view( aWater1, v.water.rm53);
	set.loop( aWater1, 0);
	position( aWater1, 44, 49);
	set.priority( aWater1, 5);
	ignore.objs( aWater1);
	work = 2;
	cycle.time( aWater1, work);
	draw( aWater1);

	animate.obj( aWater2);
	set.view( aWater2, v.water.rm53);
	set.loop( aWater2, 1);
	position( aWater2, 58, 96);
	set.priority( aWater2, 5);
	ignore.objs( aWater2);
	draw( aWater2);

	animate.obj( aWater3);
	set.view( aWater3, v.water.rm53);
	set.loop( aWater3, 1);
	set.cel( aWater3, 2);
	position( aWater3, 65,117);
	set.priority( aWater3, 5);
	ignore.objs( aWater3);
	draw( aWater3);

	animate.obj( aWater4);
	set.view( aWater4, v.water.rm53);
	set.loop( aWater4, 2);
	position( aWater4, 60, 87);
	set.priority( aWater4, 5);
	ignore.objs( aWater4);
	draw( aWater4);

	animate.obj( aWater5);
	set.view( aWater5, v.water.rm53);
	set.loop( aWater5, 3);
	position( aWater5, 68,160);
	set.priority( aWater5, 5);
	ignore.objs( aWater5);
	draw( aWater5);

	call( lgc.climbing);

	if (positionEgo)
		{
		if (previous.room == 52)
			{
			if (ego.y < 71)
				{
				ego.y = 71;
				}

			if (ego.y > 82)
				{
				ego.y = 81;
				}
			}
		else
			{
			if (previous.room == 54)
				{
				set.view( ego, v.ego);
				ego.x = 48;
				}
			else
				{
				ego.x = landing.x;
				ego.y = landing.y;
				}
			}
		position.v( ego, ego.x, ego.y);
		set.priority( ego, 6);
		}

	if (drawEgo)
		{
		draw( ego);
		}


	show.pic();
	return();

	}

		
[*****
:handle.input
[*****

if (!have.input)			{goto no.input;}

if ((said( look, mountain) ||
	said( look, top, mountain) ||
	said( look, up, mountain) ||
	said( look, down) ||
	said( look) ||
	said( look, room) ||
	said( look, up)))
	{
	print( 1);
	}

if (said( look, valley))
	{
	print( 12);
	}
if ((said( look, path) ||
	said( look, up, path)))
	{
	print( 2);
	}

if ((said( look, plants) ||
	said( look, trees)))
	{
	print( 3);
	}

if (said( look, ground))
	{
	print( 4);
	}

if ((said( look, sky) ||
	said( look, up, sky)))
	{
	print( 5);
	}

if ((said( climb, trees) ||
	said( climb, up, trees)))
	{
	print( 6);
	}

if ((said( pick, flowers) ||
	said( get, flowers) ||
	said( look, flowers)))
	{
	print( 7);
	}

if ((said( look, stream) ||
	said( look, water) ||
	said( look$in, stream)))
	{
	print( 8);
	}

if (said( look, snow))
	{
	print( 9);
	}

if ((said( drink, water) ||
	said( drink, water, stream) ||
	said( get, water) ||
	said( get, water, stream) ||
	said( get, drink) ||
	said( get, drink, stream) ||
	said( get, drink, water) ||
	said( get, drink, water, stream) ||
	said( drink, water, from, stream) ||
	said( get, water, from, stream) ||
	said( get, drink, from, stream) ||
	said( get, drink, water, from, stream)))
	{
	if (posn( ego, 41, 50, 66, 70))
		{
	 	print( 10);
		}
	else
		{
		print( 11);
		}
	}



[*****
:no.input
[*****

if (ego.x < 60)
	{
	set.horizon( 44);
	}
else
	{
	set.horizon( 35);
	}


if (current.ego == normal.ego)
	{
	set.priority( ego, 6);
	}
	

if (hit.special)
	{
	ego.location = 1;				[	area 1 is everywhere except:
	start.climbing = falling;

	if (ego.y < 45)
		{
		ego.location = 2;			[	end of trail
		set.priority( ego, 4);
		}
	else
		{
		if (ego.x > 110)
			{
			ego.location = 3;		[	right side of ledge
			ego.x += 4;
			reposition.to.v( ego, ego.x, ego.y);
			}
		}
	}


[*****
:exit							[	test for leaving the room
[*****

call( lgc.climbing);

if (edge.ego.hit == top)
	{
	new.room( 54);
	}

if (edge.ego.hit == left)
	{
	new.room( 52);
	}

