[logics for Room 19.  Forest land with stream. 

%include "gamedefs.al"
%include "rm19.msg"



%object	a.water				1



if (init.log)
	{
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	map.area = map.llewdor;
	set( beenIn19);
	set.horizon( 52);
	wiz.x = 65;
	wiz.y = 101;
	
	random( 1, 3, work);
	if (work ==1)
		{
		landing.x = 80;
		landing.y = 75;
		}
	else
		{
		if (work == 2)
			{
			landing.x = 140;
			landing.y = 75;
			}
		else
			{
			landing.x = 35;
			landing.y = 155;
			}
		}
	

	load.logics( lgc.forest);
	load.logics( lgc.stream.mud);
	load.logics( lgc.eagle.feather);

	
	load.view( v.water.rm19)
	load.view( v.ego);
	load.view( v.ego.wading.shallow);


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	animate.obj( a.water);
	ignore.objs( a.water);
	position( a.water, 53, 82);
	set.view( a.water, v.water.rm19);
	set.priority( a.water, 4);
	draw( a.water);

	
	if (positionEgo)
		{
		if (previous.room == 18)
			{
			if (ego.y > 150 && ego.y < 162)
				{
				ego.y = 162;
				}

			if (ego.y < 139)
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



	call( lgc.stream.mud);
	call( lgc.forest);
	call( lgc.eagle.feather);


	show.pic();

	return();

	}



ego.location = nowhere;
reset( near.water);
if ((posn( ego, 41, 40, 88, 78) ||
	posn( ego, 41, 78, 102, 107) ||
	posn( ego, 102, 88, 159, 142)))
	{
	set( near.mud);
	set( near.water);
	}

if ((posn( ego,  57,  61,  62,  80) ||
	posn( ego,  63,  50,  70,  63) ||
	posn( ego, 101, 104, 107, 105) ||
	posn( ego, 119, 113, 159, 126)))
	{
	set( on.water);
	}

call( lgc.eagle.feather);


if (have.input)
	{
	if (said( look, plants))
		{
		print( 1);
		}

	if ((said( look) || 
		said( look, trees)))
		{
		print( 2);
		}

	if ((said( look, cave) ||
		said( look, hole)))
		{
		print( 3);
		}
	}


	
[*****
[exit							[	test for leaving the room
[*****

call( lgc.stream.mud);
call( lgc.forest);

if (edge.ego.hit == top)			{new.room( 14);}
if (edge.ego.hit == left)		{new.room( 18);}
if (edge.ego.hit == right)		{new.room( 20);}
if (edge.ego.hit == bottom)		{new.room( 24);}

