[logics for room 52 -- A little higher up the mountains. 

%include	"rm52.msg"
%include	"gamedefs.reh"


if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.mountains;
	set( beenIn52);
	landing.x = 50;
	landing.y = 93;

	set.horizon( 35);

	load.logics( lgc.climbing);
	room.bottom = 166;


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		if (previous.room == 53)
			{
			if (ego.y < 82)
				{
				ego.y = 82;
				}
			if (ego.y > 90)
				{
				ego.y = 90;
				}
			}
		else
			{
			if (previous.room == 51)
				{
				ego.x = 42;
				ego.y = 167;
				}
			else
				{
				ego.x = landing.x;
				ego.y = landing.y;
				}
			}
		position.v( ego, ego.x, ego.y);
		}
		
	if (drawEgo)					{draw( ego);}

	call( lgc.climbing);

	show.pic();
	return();

	}

		
[*****
:handle.input
[*****

if (!have.input)				{goto no.input;}

if ((said( look, mountain) ||
	said( look, top, mountain) ||
	said( look, up, mountain) ||
	said( look) ||
	said( look, down) ||
	said( look, room) ||
	said( look, up)))
	{
	print( 1);
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


[*****
:no.input
[*****

ego.location = 1;
room.bottom = 166;

if (posn( ego, 0, 0, 48, 106))			[	left rear little special
	{
	ego.location = 2;
	room.bottom = 156;
	if (hit.special)
		{
		set.priority( ego, 4);
		start.climbing = falling;
		}
	}
else
	{
	if (posn( ego, 55, 0, 84, 90))		[	right rear little special
		{
		ego.location = 3;
		if (hit.special)
			{
			set.priority( ego, 4);
			start.climbing = falling;
			if (ego.x > 76)
				{
				ego.location = 4;
				ego.x = 76;
				reposition.to.v( ego, ego.x, ego.y);
				}
			}
		}
	else
		{
		ego.location = 5;			[	front edge, anywhere else
		if (hit.special)
			{
			set.priority( ego, 11);
			start.climbing = falling;

			if (ego.x < 33)
				{
				ego.x = 33;
				reposition.to.v( ego, ego.x, ego.y);
				room.bottom = 163;
				}
			}
		}
	}


[*****
:exit							[	test for leaving the room
[*****

call( lgc.climbing);

if (edge.ego.hit == bottom)		{new.room( 51);}
if (edge.ego.hit == right)		{new.room( 53);}

