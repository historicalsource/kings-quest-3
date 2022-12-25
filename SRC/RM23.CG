[logics for room 23 -- forest

%include "gamedefs.al"
%include "rm23.msg"



%define 	bandits.loaded			lf0



if (init.log)
	{
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	map.area = map.llewdor;
	set( beenIn23);
	set.horizon( 56);
	wiz.x = 124;
	wiz.y = 129;

	random( 1, 3, work)
	if (work == 1)
		{
		landing.x = 18;
		landing.y = 76;
		}
	else
		{
		if (work == 2)
			{
			landing.x = 74;
			landing.y = 56;
			}
		else
			{
			landing.x = 135;
			landing.y = 131;
			}
		}


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
		if (previous.room == 18)
			{
			if (ego.x > 24 && ego.x < 70)
				{
				ego.x = 62;
				}
			}

		if (previous.room == 22)
			{
			if (ego.y > 139 && ego.y < 147)
				{
				ego.y = 139;
				}
			}
		position.v( ego, ego.x, ego.y);
		}

	if (drawEgo)
		{
		draw( ego);
		}

		
	call( lgc.forest);
	if (bandits.loaded)
		{
		call( lgc.bandits.exterior);
		}

	show.pic();
	
	return();

	}



[*****
:handle.input
[*****

if (have.input)
	{
	if ((said (look, plants) || 
		said( look, ground)))						{print( 1);}

	if ((said( look, mountain) ||
	     said( look, top, mountain)))					{print( 3);}

	if ((said( look, path) ||
		said( look, path, mountain) ||
		said( look, mountain, path)))					{print( 4);}

	if ((said( climb) || said( climb, mountain)))		{print( 5);}
	}	



[*****
[exit							[	test for leaving the room
[*****

call( lgc.forest);	
if (bandits.loaded)
	{
	call( lgc.bandits.exterior);
	}

if (edge.ego.hit == bottom)			{new.room( 28);}
if (edge.ego.hit == top)				{new.room( 18);}
if (edge.ego.hit == left)			{new.room( 22);}
if (edge.ego.hit == right)			{new.room( 24);}
