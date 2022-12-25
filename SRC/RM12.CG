[logics for room 12 -- Transitional Forest

%include "gamedefs.al"



if (init.log)
	{
	load.view.f( current.ego);
	load.view( v.ego);
	set.view.f( ego, current.ego);
	map.area = map.llewdor;
	set( beenIn12);
	set.horizon( 60);
	wiz.x = 89;
	wiz.y = 138;
	landing.x = 137;
	landing.y = 128;

	
	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	load.logics( lgc.near.desert);
	load.logics( lgc.forest);
	load.logics( lgc.eagle.feather);


	if (positionEgo)
		{
		if (previous.room == 17)
			{
			if (ego.x > 136)
				{
				ego.x = 136;
				}
			}

		if (previous.room == 13)
			{
			if (ego.y > 130 && ego.y < 109)
				{
				ego.y = 109;
				}
			
			if (ego.y > 127 && ego.y < 133)
				{
				ego.y = 127;
				}

			if (ego.y > 155)
				{
				ego.y = 155;
				}
			}
		position.v( ego, ego.x, ego.y);
		}

	if (drawEgo)
		{
		draw( ego);
		}


	call( lgc.forest);
	call( lgc.eagle.feather);


	show.pic();

	return();

	}


reset( near.cactus);
if (posn( ego, 0, 0, 27, 80))
	{
	set( near.cactus);
	}



[	NOT MUCH HERE, IS THERE?



[*****
[exit							[	test for leaving the room
[*****

call( lgc.eagle.feather);
call( lgc.near.desert);
call( lgc.forest);

if (edge.ego.hit == bottom)		{new.room( 17);}
if (edge.ego.hit == top)			{new.room( 27);}
if (edge.ego.hit == left)		{new.room( 11);}
if (edge.ego.hit == right)		{new.room( 13);}
