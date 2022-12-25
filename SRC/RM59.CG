[logics for room 59 -- Further down the mountains. 

%include	"rm59.msg"
%include	"gamedefs.reh"



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.mountains;
	set( beenIn59);
	landing.x = 150;
	landing.y = 126;

	set.horizon( 1);

	load.logics( lgc.climbing);
	room.bottom = 166;


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		if (previous.room == 58)
			{
			position( ego, 0, 49);
			}
		}

	if (drawEgo)					{draw( ego);}

	call( lgc.climbing);

	show.pic();
	return();

	}


[*****
:handle.input
[*****

if (!have.input)		{goto no.input;}

if ((said( look, mountain) ||
	said( look, up, mountain) ||
	said( look, up) ||
	said( look) ||
	said( look, room) ||
	said( look, down)))							{print( 1);}

if (said( look, path))							{print( 2);}

if ((said( look, plants) ||
	said( look, tree)))							{print( 3);}

if (said( look, ground))							{print( 4);}

if (said( look, sky))							{print( 5);}

if ((said( climb, trees) ||
	said( climb, up, trees)))					{print( 6);}

if ((said( pick, flowers) ||
	said( get, flowers) ||
	said( look, flowers)))						{print( 7);}


[*****
:no.input
[*****

ego.location = 0;

if (hit.special)
	{
	start.climbing = falling;

	if ((posn( ego, 0, 37, 44, 51) ||	[	the far side of the mountain
		posn( ego, 39, 51, 108, 64) ||
		posn( ego, 108, 61, 159, 71)))
		{
		ego.location = 1;
		set.priority( ego, 4);
		}
	else
		{
		set.priority( ego, 7);

		if (posn( ego, 90, 79, 130, 94)) [	in the "crotch" of the corner
			{
			ego.location = 2;
			ego.x = 90;
			reposition.to.v( ego, ego.x, ego.y);
			}
		else
			{
			ego.location = 3;		[	everywhere else is easy
			}
		}
	}


[*****
:exit							[	test for leaving the room
[*****

call( lgc.climbing);

if (edge.ego.hit == bottom)		{new.room( 61);}
if (edge.ego.hit == left)		{new.room( 58);}

