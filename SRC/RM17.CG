[logics for room 17 -- Transitional Forest

%include	"gamedefs.al"



%define	bandits.loaded		lf0



if (init.log)
	{
	load.view( v.ego);
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	map.area = map.llewdor;
	set( beenIn17);
	set.horizon( 60);
	wiz.x = 12;
	wiz.y = 142;			

	random( 1, 3, work);
	if (work == 1)
		{
		landing.x = 80;
		landing.y = 150;
		}
	else
		{
		if (work == 2)
			{
			landing.x = 20;
			landing.y = 110;
			}
		else
			{
			landing.x = 110;
			landing.y = 85;
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


	ignore.obj( ego);
	if (positionEgo)
		{
		if (previous.room == 12)
			{
			if (ego.x > 87)
				{
				ego.x = 87;
				}
			}

		if (previous.room == 16)
			{
			if (ego.y > 117 && ego.y < 121)
				{
				ego.y = 121;
				}
			}

		if (previous.room == 18)
			{
			if (ego.y < 115)
				{
				ego.y = 115;
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


reset( near.cactus);
if (posn( ego, 0, 94, 20, 143))
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

if (edge.ego.hit == bottom)			{new.room( 22);}
if (edge.ego.hit == top)				{new.room( 12);}
if (edge.ego.hit == left)			{new.room( 16);}
if (edge.ego.hit == right)			{new.room( 18);}
