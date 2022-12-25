[logics for room 9 -- rm.lab.stairs

%include	"rm9.msg"
%include	"gamedefs.al"
%include	"rm-names.h"



[	If wiz is home, he poofs in when ego gets to the landing, and kills him.
[Cat can trip ego on the landing, and he plummets to his death in rm10.



%define	cat.tripped.ego		lf0



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.wiz.house;
	set.horizon( 33);
	landing.x = 140;
	landing.y = 140;
	wiz.x = 130;
	wiz.y = 0;					[	until we're ready for him.

	cat.x = 122;
	cat.y = 129;
	load.logics( lgc.wiz.house);
	
	load.logics( lgc.climbing);
	room.bottom = fall.through;

	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (current.status == fly)
		{
		set( positionEgo);
		}

	if (positionEgo)
		{
		if (previous.room == rm.wiz.office)
			{
			set.priority( ego, 9);
			position( ego, 107, 35);
			start.motion( ego);
			if (current.status != fly)
				{
				set.loop( ego, facing.front);
				}
			}
		else
			{
			if (previous.room == rm.lab)
				{
				position( ego, 89, 166);
				}
			else
				{
				position.v( ego, landing.x, landing.y);
				}
			}
		}

	if (drawEgo)					{draw( ego);}

	observe.block( ego);

	call( lgc.climbing);

	call( lgc.wiz.house);
	if (pussy.on.screen)
		{
		obj.on.water( a.cat);
		}

	show.pic();
	return();

	}


if ((posn( ego, 92, 31, 122, 97) ||
	posn( ego, 114, 73, 126, 99)))
	{
	set.priority( ego, 9);
	}
else
	{
	release.priority( ego);
	}

[*****
:handle.input
[*****

if (!have.input)			{goto no.input;}


if ((said( look, room) ||
	said( look, house) ||
	said( look) ||
	said( look, passage)))
	{
	print( 1);
	}

if ((said( look, stairs) ||
	said( look, up, stairs) ||
	said( look, down, stairs) ||
	said( look, down) ||
	said( look, up)))
	{
	print( 2);
	}

if ((said( look, trapdoor) ||
	said( look, out, trapdoor)))
	{
	print( 3);
	}

if (said( close, trapdoor))
	{
	print( 4);
	}

if (said( open, trapdoor))
	{
	print( 5);
	}

if ((said( climb, stairs) ||
	said( climb, down, stairs) ||
	said( climb, up, stairs)))
	{
	print( 6);
	}


[*****
:no.input
[*****

if (posn( ego, 90, 100, 150, 150))
	{
	wiz.y = 132;					[	let wiz get him now!!
	}

if  (pussy.on.screen && 
    !cat.tripped.ego &&
	current.status == normal.ego)
	{
	distance( ego, a.cat, work);
	if (work < 12 && work != 0)
		{
		set( hit.special);
		set( cat.tripped.ego);
		}
	}


if (cat.tripped.ego &&
	ego.y > 163)
	{
	reset( cat.tripped.ego);
	print( 7);
	if (has( i.dough.balls))
		{
		print( 8);
		}
	}


[*****
:exit							[	test for leaving the room
[*****

if (current.status != fly.landing)
	{
	if (edge.ego.hit == bottom && ego.x >  74 && ego.x < 146)
		{
		release.priority( ego);
		new.room( rm.lab);
		}
	
	if (edge.ego.hit == top    && ego.x > 104 && ego.x < 118)
		{
		release.priority( ego);
		new.room( rm.wiz.office);
		}
	}

call( lgc.wiz.house);
call( lgc.climbing);

