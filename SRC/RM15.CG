[logics for room 15 -- Northern beach

%include "gamedefs.al"



%define	horizon				64



if (init.log)
	{
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	load.view( v.ego);
	map.area = map.llewdor;
	set( beenIn15);
	set.horizon( horizon);

	wiz.x = 16;
	wiz.y = 161;
	landing.x = 143;
	landing.y = 102;

	load.logics( lgc.seagulls);
	load.logics( lgc.beach);
	load.logics( lgc.swim);
	

	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);
	

	if (positionEgo)
		{
		if (previous.room == 29)
			{
			ego.x = 4;
			}

		if (previous.room == 30)
			{
			ego.x = 89;
			
			if ((waterView == wadingShallow ||
				current.status == wading))
				{
				ego.x = 117;
				}
			
			if (waterView == wadingDeep)
				{
				ego.x = 125;
				}
			
			if ((waterView == swimmingEgo ||
				current.status == swimming))
				{
				ego.x = 142;
				}
			}

		if (previous.room == 20)
			{
			if (ego.x > 49 && ego.x < 68)
				{
				ego.x = 49;
				}
			
			if ((waterView == wadingShallow ||
				current.status == wading))
				{
				ego.x = 123;
				}
			
			if (waterView == wadingDeep)
				{
				ego.x = 136;
				}
			
			if ((waterView == swimmingEgo ||
				current.status == swimming))
				{
				ego.x = 148;
				}
			}

		if (previous.room == 14)
			{
			if (ego.y > 140 && ego.y < 147)
				{
				ego.y = 147;
				}
			}

		position.f( ego, ego.x, ego.y);
		}


	if (drawEgo)
		{
		draw( ego);
		}

	work = smallGull;					
	call( lgc.seagulls);
	reposition.to( aGull1,  99, 19);
	reposition.to( aGull2, 111, 11);

	call( lgc.beach);
	call( lgc.swim);


	show.pic();

	return();

	}



[*****
:no.input
[*****

waterView = 0;
if (on.water)
	{
	waterView = wadingShallow;
	}

if ((posn( ego, 124,   0, 132,  89)	||
	posn( ego, 133,  90, 141, 143)	||
	posn( ego, 136, 144, 141, 167)))
	{
	waterView = wadingDeep;
	}

if ((posn( ego, 133,   0, 159,  89)	||
	posn( ego, 142,  90, 159, 167)))
	{
	waterView = swimmingEgo;
	}

if (hit.special)
	{
	if (posn( ego, 40, 98, 58, 101))
		{
		x = 0;
		y = 7;
		reposition( ego, x, y);
		}
	
	if (posn( ego, 59, 100, 70, 103))
		{
		x = 0;
		y = 15;
		reposition( ego, x, y);
		}

	if (posn( ego, 71, 96, 80, 105))
		{
		reposition.to( ego, 78, 116);
		}

	if (posn( ego, 50, 133, 60, 167))
		{
		x = 72;
		reposition.to.v( ego, x, ego.y);
		}
	}


[*****
[exit							[	test for leaving the room
[*****

call( lgc.seagulls);
call( lgc.beach);
call( lgc.swim);

if (edge.ego.hit == bottom)			{new.room( 20);}
if (edge.ego.hit == left)			{new.room( 14);}
if (edge.ego.hit == right)			{new.room( 31);}
if (edge.ego.hit == top)
	{
	if (ego.x > 25)				{new.room( 30);}
	else							{new.room( 29);}
	}

