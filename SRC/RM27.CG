[logics for room 27 -- Transitional Forest

%include "gamedefs.al"



%define	bandits.loaded		lf0



if (init.log)
	{
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	map.area = map.llewdor;
	set( beenIn27);
	set.horizon( 56);	  
	wiz.x = 87;
	wiz.y = 130;

	random( 1, 3, work);
	if (work ==1)
		{
		landing.x = 14;
		landing.y = 70;
		}
	else
		{
		if (work == 2)
			{
			landing.x = 76;
			landing.y = 85;
			}
		else
			{
			landing.x = 143;
			landing.y = 109;
			}
		}
	

	load.logics( lgc.near.desert);
	load.logics( lgc.forest);
 
	if (!ego.been.robbed)
		{
		random( 1, 3, work);
		if (work == 1)
			{
			set( bandits.loaded);
			load.logics( lgc.bandits.exterior);
			wiz.y = 0;
			}
		}


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		if (previous.room == 26)
			{
			if (ego.y > 117 && ego.y < 122)
				{
				ego.y = 117;
				}
			}
		position.v( ego, ego.x, ego.y);
		}


	if (drawEgo)
		{
		draw( ego);
		}

	ignore.obj( ego);


	call( lgc.forest);
	if (bandits.loaded)
		{
		call( lgc.bandits.exterior);
		}


	show.pic();			


	return();

	}


reset( near.cactus);
if (posn( ego, 7, 98, 20, 135))
	{
	set( near.cactus);
	}


[*****
[exit							[	test for leaving the room
[*****

call( lgc.near.desert);
call( lgc.forest);
if (bandits.loaded)
	{
	call( lgc.bandits.exterior);
	}

if (edge.ego.hit == bottom)			{new.room( 12);}
if (edge.ego.hit == top)				{new.room( 22);}
if (edge.ego.hit == left)			{new.room( 26);}
if (edge.ego.hit == right)			{new.room( 28);}
