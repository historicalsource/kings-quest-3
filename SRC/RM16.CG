[logics for room 16 -- desert.mid.north

%include "gamedefs.al"





%define	medusa.loaded			lf0



if (init.log)
	{
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	load.view( v.ego);
	map.area = map.llewdor;
	set( beenIn16);
	set.horizon( 56);
	wiz.x = 130;
	if (medusa.stone)
		{
		wiz.y = 90;
		}

	random( 1, 3, work);
	if (work ==1)
		{
		landing.x = 140;
		landing.y = 75;
		}
	else
		{
		if (work == 2)
			{
			landing.x = 90;
			landing.y = 140;
			}
		else
			{
			landing.x = 10;
			landing.y = 70;
			}
		}


	load.logics( lgc.desert);
	load.logics( lgc.medusa);


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


[	if (positionEgo)
[		{
[		}

	if (drawEgo)
		{
		draw( ego);
		}


	call( lgc.desert);
	call( lgc.medusa);

	show.pic();

	return();
	
	}



[*****
:exit							[	test for leaving the room
[*****

call( lgc.desert);
call( lgc.medusa);

if (edge.ego.hit == bottom)		{new.room( 21);}
if (edge.ego.hit == top)			{new.room( 11);}
if (edge.ego.hit == left)		{new.room( 32);}
if (edge.ego.hit == right)		{new.room( 17);}

