[logics for room 58 -- Further down the mountain.

%include	"rm58.msg"
%include	"gamedefs.reh"



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.mountains;
	set( beenIn58);
	landing.x = 60;
	landing.y = 111;

	set.horizon( 1);

	load.logics( lgc.climbing);
	room.bottom = 166;


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		if (previous.room == 57)
			{
			position( ego, 0, 138);
			}
		else
			{
			if (previous.room == 59)
				{
				position( ego, 152, 155);
				}
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

if (!have.input)				{goto no.input;}

if ((said( look, mountain) ||
	said( look, up, mountain) ||
	said( look) ||
	said( look, up) ||
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
	if (ego.y < 116)
		{
		ego.location = 1;
		set.priority( ego, 4);
		}
	else
		{
		if (posn( ego, 143, 138, 159, 145))
			{
			ego.location = 2;
			set.priority( ego, 9);
			}
		else
			{
			if (posn( ego, 126, 127, 144, 139))
				{
				ego.location = 3;
				set.priority( ego, 9);
				}
			else
				{
				ego.location = 4;
				set.priority( ego, 14);
				}
			}
		}
	}


[*****
:exit							[	test for leaving the room
[*****

call( lgc.climbing);

if (edge.ego.hit == left){
	if ((current.status == fly || current.status == eagle)){
		edge.ego.hit = 0;
		spell.cast = sc.stop.flying;
	} else {
		new.room( 57);
	}
}

if (edge.ego.hit == right){
	new.room( 59);
}

