[logics for room 21 -- desert mid.south

%include "gamedefs.al"
%include "rm21.msg"



%define	medusa.loaded			lf0


%object	a.cactus				2



if (init.log)
	{
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	load.view( v.ego);
	map.area = map.llewdor;
	set( beenIn21);
	set.horizon( 56);
	wiz.x = 34;
	if (medusa.stone)
		{
		wiz.y = 123;
		}

	random( 1, 3, work);
	if (work ==1)
		{
		landing.x = 95;
		landing.y = 76;
		}
	else
		{
		if (work == 2)
			{
			landing.x = 132;
			landing.y = 110;
			}
		else
			{
			landing.x = 24;
			landing.y = 122;
			}
		}


	if (obj.in.room( i.cactus, current.room))
		{
		load.view( v.cactii);
		}


	load.logics( lgc.desert);
	load.logics( lgc.medusa);


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		if (previous.room == 31)
			{
			if (ego.y > 80 && ego.y < 85)
				{
				ego.y = 85;
				}
			}

		if (previous.room == 22)
			{
			if (ego.y > 91 && ego.y < 99)
				{
				ego.y = 99;
				}
			}
		
		position.v( ego, ego.x, ego.y);
		}

	if (drawEgo)
		{
		draw( ego);
		}


	if (obj.in.room( i.cactus, current.room))
		{
		animate.obj( a.cactus);
		position( a.cactus, 40, 86);
		set.view( a.cactus, v.cactii);
		set.cel( a.cactus, 0);
		draw( a.cactus);
		stop.update( a.cactus);
		}


	call( lgc.desert);
	call( lgc.medusa);


	show.pic();

	return();

	}



if (have.input)
	{
	if (said( look, rock))
		{
		print( 4);

		if (obj.in.room( i.cactus, current.room))
			{
			print( 2);
			}
		}

	if (obj.in.room( i.cactus, current.room))
		{
		if ((said( look) ||
			said( look, plants) || 
			said( look, cactus) ||
			said( look, ground)))
			{
			print( 2);
			}

		if ((said( use, knife, cut, cactus) ||
			said( cut, cactus, with, knife)))
			{
			print( 5);
			}

 		if ((said( get, cactus) || 
			said( get, cactus, from, ground) ||
			said( pick, cactus) ||
			said( pick, cactus, from, ground)))
			{
			distance( ego, a.cactus, work);
			if (work > 20)
				{	
				print( 3);	    
				}
			else
				{
				print( 1);
				get( i.cactus);
				score += 1;
				start.update( a.cactus);
				erase( a.cactus);
				}
			}
		}
	}



[*****
[exit							[	test for leaving the room
[*****

call( lgc.desert);
call( lgc.medusa);

if (edge.ego.hit == bottom)		{new.room( 26);}
if (edge.ego.hit == top)			{new.room( 16);}
if (edge.ego.hit == left)		{new.room( 32);}
if (edge.ego.hit == right)		{new.room( 22);}

