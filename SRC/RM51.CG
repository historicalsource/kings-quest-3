[logics for room 51 -- The other half of the Cliff Mays.

%include	"rm51.msg"
%include	"gamedefs.reh"


if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.mountains;
	set( beenIn51);
	landing.x = 132;
	landing.y = 110;

	set.horizon( 34);

	set( survivable.fall);
	load.logics( lgc.climbing);
	room.bottom = 105;


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		if (previous.room == 49)
			{
			if (ego.x > 144)
				{
				ego.x = 144;
				}
			}
		else
			{
			if (previous.room == 50)
				{
				if (ego.y < 48)			[	on upper ramp
					{
					ego.y = 48;
					}
				}
			else
				{
				if (previous.room == 52)
					{
					ego.x = 69;
					ego.y = 36;
					}
				else
					{
					ego.x = landing.x;
					ego.y = landing.y;
					}
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
	said( look, trees) ||
	said( pick, flowers) ||
	said( get, flowers) ||
	said( look, flowers)))
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

if (has( i.shovel))
	{
	if ((said( dig, hole) ||
		said( dig) ||
		said( dig, hole, ground) ||
		said( dig, with, shovel)))
		{
		print( 7);
		}
	}



[*****
:no.input
[*****

if (hit.special)
	{
	ego.location = 0;
	room.bottom = 102;
	set( survivable.fall);
	
	if (posn( ego, 0, 94, 65, 114))	[	lower left foreground ramp
		{
		ego.location = 2;
		room.bottom = 134;
		}
	
	if (posn( ego, 0, 38, 71, 62))	[	upper ramp, left & middle 
		{
		ego.location = 3;
		room.bottom = 96;
		}
	
	if (posn( ego, 72, 38, 89, 50))	[	upper ramp, right
		{
		ego.location = 4;
		room.bottom = 71;
		}
	
	if (posn( ego, 32, 75, 70, 88))	[	center deadend ramp, left end
		{
		ego.location = 5;
		room.bottom = 99;
		}
	
	if (posn( ego, 71, 71, 110, 87))	[	center deadend ramp, middle
		{
		ego.location = 6;
		room.bottom = 106;
		}
	
	if (posn( ego, 111, 66, 119, 75))	[	center deadend ramp, middle right
		{
		ego.location = 7;
		room.bottom = 115;
		ego.x = 119;
		reposition.to.v( ego, ego.x, ego.y);
		start.climbing = falling;
		}
	
	if (posn( ego, 120, 66, 159, 75))	[	center deadend ramp, far right
		{
		ego.location = 8;
		room.bottom = 117;
		}

	if ((posn( ego, 0, 0, 90, 37) ||	[	top of ramp; near rm52
		posn( ego, 86, 0, 122, 53)))
		{
		reset( survivable.fall);
		ego.location = 1;
		room.bottom = 106;
		if (ego.x < 97)
			{
			ego.x = 97;
			}
		reposition.to.v( ego, ego.x, ego.y);
		set.priority( ego, 4);
		start.climbing = falling;
		}
	}
	

[*****
:exit							[	test for leaving the room
[*****

call( lgc.climbing);

if (edge.ego.hit == bottom)		{new.room( 49);}
if (edge.ego.hit == top)			{new.room( 52);}
if (edge.ego.hit == left)		{new.room( 50);}
