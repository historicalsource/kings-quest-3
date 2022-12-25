[logics for Room 33 -- Path up the wiz's peak. 

%include	"rm33.msg"
%include	"gamedefs.al"



[	In case of fall, they die here, NOT in room 18, to prevent disk
[change just to die!



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.wiz.house;
	landing.x = 12;
	landing.y = 92;
	wiz.x = 137;
	wiz.y = 69;

	set.horizon( 49);

	load.logics( lgc.climbing);
	reset( survivable.fall);
	room.bottom = 166;


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		if (previous.room == 34)
			{
			position( ego, 17, 51);
			}
		else
			{
			if (previous.room == 18)
				{
				position( ego, 22, 167);
				start.motion( ego);
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

	reset( ignore.special);
	
	call( lgc.climbing);

	show.pic();
	return();

	}							[	end INIT.LOG


[*****
:handle.input
[*****

if (!have.input)				{goto no.input;}

if ((said( look, path) ||
	said( look, up, path) ||
	said( look) ||
	said( look, down, path)))
	{
	print( 1);
	}

if ((said( look, sky) ||
	said( look, up, sky)))
	{
	print( 2);
	}

if ((said( look, clouds) ||
	said( look, up, clouds) ||
	said( look, sky) ||
	said( look, clouds, sky) ||
	said( look, up, clouds, sky)))
	{
	print( 3);
	}

if ((said( look, mountain) ||
	said( look, around)))
	{
	print( 4);
	}

if ((said( look, trees) ||
	said( look, flowers) ||
	said( pick, flowers) ||
	said( climb, trees) ||
	said( look, plants)))
	{
	print( 5);
	}

if ((said( look, room) ||
	said( look, house)))
	{
	print( 6);
	}


[*****
:no.input
[*****

[*****
:wear.da.fahgawee
[*****

ego.location = 0;

if (hit.special)
	{
	start.climbing = falling;

	if (posn( ego, 9, 60, 18, 78))
		{
		ego.location = 1;
		ego.x += 6;
		reposition.to.v( ego, ego.x, ego.y);
		set.priority( ego, 6);
		}

	if (!ego.location &&
	    (posn( ego, 0, 0, 21, 59) ||
		posn( ego, 0, 60, 8, 68)))
		{
		ego.location = 2;
		set.priority( ego, 4);
		}

	if (!ego.location &&
		posn( ego, 7, 79, 31, 87))
		{
		ego.location = 3;
		set.priority( ego, 6);
		}

	if (!ego.location &&
		posn( ego, 0, 89, 53, 100))
		{
		ego.location = 4;
		set.priority( ego, 8);
		}

	if (!ego.location &&
	    (posn( ego, 47, 75, 72,  80) ||
		posn( ego, 46, 81, 56, 88)))
		{
		ego.location = 5;
		set.priority( ego, 7);
		}

	if (!ego.location &&
		posn( ego, 54, 65, 59, 74))	[	formerly included in area 15
		{
		ego.location = 6;
		ego.x += 6;
		reposition.to.v( ego, ego.x, ego.y);
		set.priority( ego, 6);
		}

	if (!ego.location &&
		posn( ego, 140, 64, 154, 71))
		{
		ego.location = 7;
		set.priority( ego, 5);
		ego.x = ego.falling.limit;
		reposition.to.v( ego, ego.x, ego.y);
		}

	if (!ego.location &&
		posn( ego, 62, 84, 115, 89))
		{
		ego.location = 8;
		set.priority( ego, 7);
		}

	if (!ego.location &&
		posn( ego, 54, 87, 62, 130))
		{
		ego.location = 9;
		ego.x -= 8;
		reposition.to.v( ego, ego.x, ego.y);
		set.priority( ego, 8);
		}

	if (!ego.location &&
		posn( ego, 77, 95, 132, 131))
		{
		ego.location = 10;
		set.priority( ego, 8);
		}

	if (!ego.location &&
	    (posn( ego, 65, 132, 123, 157) ||
		posn( ego, 29, 153, 65, 167)))
		{
		ego.location = 11;
		set.priority( ego, 13);
		}

	if (!ego.location &&
		posn( ego, 12, 145, 29, 167))
		{
		ego.location = 12;
		ego.x -= 8;
		reposition.to.v( ego, ego.x, ego.y);
		set.priority( ego, 11);
		}

	if (!ego.location &&
		posn( ego, 29, 141, 49, 147))
		{
		ego.location = 13;
		set.priority( ego, 11);
		}

	if (!ego.location &&
		posn( ego, 49, 130, 63, 146))
		{
		ego.location = 14;
		ego.x -= 8;
		reposition.to.v( ego, ego.x, ego.y);
		set.priority( ego, 12);
		}

	if (!ego.location &&
		posn( ego, 32, 65, 120, 74))	[	includes area 6, above
		{
		ego.location = 15;
		set.priority( ego, 6);
		}
	}


[*****
:exit							[	test for leaving the room
[*****

if (edge.ego.hit == bottom)			{new.room( 18);}
if (edge.ego.hit == top)				{new.room( 34);}

call( lgc.climbing);
