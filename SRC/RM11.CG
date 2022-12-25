[logics for room 11 -- desert north

%include "gamedefs.al"
%include "rm11.msg"



%define	medusa.loaded			lf0
%define	near.snakeskin			lf1
%define	near.shrub			lf2


%object	a.snakeskin			1



if (init.log)
	{
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	load.view( v.ego);
	map.area = map.llewdor;
	set( beenIn11);
	set.horizon( 52);
	wiz.x = 50;
	if (medusa.stone)
		{
		wiz.y = 112;
		}

	landing.x = 21;
	landing.y = 69;


	load.logics( lgc.desert);
	load.logics( lgc.medusa);


	if (obj.in.room( i.snakeskin, current.room))
		{
		load.view( v.snakeskin);
		}

	
	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		[ accept interpreter position
		}

	if (drawEgo)
		{
		draw( ego);
		}

	if (obj.in.room( i.snakeskin, current.room))
		{
		animate.obj( a.snakeskin);
		position( a.snakeskin, 88, 99);
		set.view( a.snakeskin, v.snakeskin);
		draw( a.snakeskin);
		stop.update( a.snakeskin);
		}
						
	call( lgc.desert);

	call( lgc.medusa);

	show.pic();

	return();

	}

[*****
[wear.da.fugawhee;
[*****

reset( near.shrub);
if ((posn( ego, 45, 100, 75, 110) ||
	posn( ego, 15, 125, 40, 140) ||
	posn( ego, 15, 60, 40, 65))) 
	{
	set( near.shrub);
	}

reset(near.snakeskin);
if (obj.in.room( i.snakeskin, current.room))
	{
	distance( ego, a.snakeskin, work);
	if (work < 20)
		{
		set(near.snakeskin);
		}

	if ((said( look, snakeskin) ||
		said( look, ground)))
		{
		print( 2);
		}

	if ((said( get, snakeskin) ||
		said( get, snake)))
		{
		if (near.snakeskin)
			{
			erase( a.snakeskin);
			get( i.snakeskin);
			score += 1;
			print( 1);
			}
		else
			{
			print( 10);
			}
		}
	}


if ((said( look, desert) ||
	said( look)))
	{
	print( 11);
	}

if (said( look, plants))
	{
	if (near.shrub)
		{
		print( 4);
		}
	else
		{
		print( 7);
		}
	}

if ((said( get, plants) ||
	said( pick, plants)))
	{
	if (near.shrub)
		{
		print( 7);
		}
	else
		{
		print( 10);
		}
	}
	

[*****
[exit							[	test for leaving the room
[*****

call( lgc.desert);
call( lgc.medusa);

if (edge.ego.hit == bottom)
	{
	new.room( 16);
	}

if (edge.ego.hit == top)	
	{
	new.room( 26);
	}

if (edge.ego.hit == left)
	{
	new.room( 32);
	}

if (edge.ego.hit == right)
	{
	new.room( 12);
	}

