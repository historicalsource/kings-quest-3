[logics for room 20 -- Middle beach

%include "gamedefs.al"
%include "rm20.msg"



%define	rock.x				68


%define	near.brackish			lf0


%object	a.water				1



if (init.log)
	{
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	load.view( v.ego);
	map.area = map.llewdor;
	set( beenIn20);
	wiz.x = 20;
	wiz.y = 140;
	
	random( 1, 3, work);
	if (work == 1)
		{
		landing.x = 100;
		landing.y = 83;
		}
	else
		{
		if (work == 2)
			{
			landing.x = 102;
			landing.y = 149;
			}
		else
			{
			landing.x = 18;
			landing.y = 89;
			}
		}


	load.view( v.water.rm20);

	load.logics( lgc.seagulls);
	load.logics( lgc.stream.mud);
	load.logics( lgc.beach);
	load.logics( lgc.swim);


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	animate.obj( a.water);
	position( a.water, 51, 122);
	set.view( a.water, v.water.rm20);
	set.priority( a.water, 3);
	ignore.objs( a.water);
	draw( a.water);


	if (positionEgo)
		{
		if (previous.room == 25)
			{
			ego.x = 121;
			if (current.status == swimming)
				{
				ego.x = 153;
				ego.y = 87;
				}

			if (current.status == wading)
				{
				ego.x = 150;
				ego.y = 120;
				}
			}

		if (previous.room == 15)
			{
			if (ego.x > 69)		[	default to regular walkin' guy
				{
				ego.x = 90;
				}
			else
				{
				ego.x = 52;
				}

			if ((current.status == swimming ||
				waterView == swimmingEgo))
				{
				ego.x = 147;
				}

			if (waterView == wadingDeep)
				{
				ego.x = 134;
				}

			if ((current.status == wading ||
				waterView == wadingShallow))
				{
				ego.x = 126;
				}
			}

		position.v( ego, ego.x, ego.y);
		}


	if (ego.x < 70)
		{
		set.horizon( 62);
		}
	else
		{
		set.horizon( 74);
		}


	if (drawEgo)
		{
		draw( ego);
		}


	work = smallGull;					
	call( lgc.seagulls);
	reposition.to( aGull1,  99, 19);
	reposition.to( aGull2, 111, 11);

	call( lgc.stream.mud);
	call( lgc.beach);
	call( lgc.swim);


	show.pic();

	return();

	}



if (ego.x < 70)
	{
	set.horizon( 62);
	}
else
	{
	set.horizon( 74);
	}


reset( near.water);
if ((posn( ego, 84, 138,  94, 141) ||
	posn( ego, 53, 107,  62, 108) ||
	posn( ego, 82, 124,  85, 130) ||
	posn( ego, 83, 124,  85, 128) ||
	posn( ego, 47, 109,  68, 118) ||
	posn( ego, 93, 102, 111, 110)))
	{
	set( on.water);
	set( near.water);
	}

if (posn( ego, 0, 105, 45, 140))
	{
	set( near.water);
	}


reset( near.brackish);
if (posn( ego, 71, 101, 159, 147))
	{
	set( near.brackish);
	}


reset( near.mud);
if ((posn( ego, 0, 105, 36, 116) ||
	posn( ego, 0, 124, 27, 134)))
	{
	set( near.mud);
	}


waterView = 0;
if (on.water)
	{
	waterView = wadingShallow;
	}

if (posn( ego, 134, 63, 140, 86))
	{
	waterView = wadingDeep;
	}

if (posn( ego, 141, 63, 159, 88))
	{
	waterView = swimmingEgo;
	}


[*****
[handle.input
[*****

if ((said( look) ||
	said( look, ground)))
	{
	print( 1);
	}

if (near.brackish)
	{
	if ((said( look, water) ||
		said( look, creek)))
		{
		print( 3);
		}

	if ((said( drink, water) ||
		said( drink, ocean, water) ||
		said( drink, water, ocean) ||
		said( drink, water, cup) ||
		said( drink, ocean, water, cup) ||
		said( drink, salt, water, cup) ||
		said( drink, salt, water) ||
		said( get, water, stream) ||
		said( get, water) ||
		said( get, water, cup) ||
		said( get, drink, water, stream) ||
		said( stream, get, drink, water) ||
		said( get, drink, water) ||
		said( get, drink) ||
		said( drink)))
		{
		print( 3);
		}
	}

if ((said( look, water) ||
	said( look, creek)))
	{
	print( 2);
	}



[****
[stumble off the bank
[****

if (hit.special)
	{
	if (posn( ego, 50, 58, 79, 98))
		{
		x = 8;
		y = 9;
		reposition( ego, x, y);
		}

	if (posn( ego, 32, 99, 67, 109))
		{
		ego.y = 110;
		reposition.to.v( ego, ego.x, ego.y);
		}
	}


[*****
[exit							[	test for leaving the room
[*****

call( lgc.seagulls);
if (ego.x < rock.x)
	{
	call( lgc.stream.mud);			[this must be called before lgc.beach
	}
call( lgc.beach);
call( lgc.swim);	

if (edge.ego.hit == top)
	{
	new.room( 15);
	}

if (edge.ego.hit == left)
	{
	new.room( 19);
	}

if (edge.ego.hit == right)
	{
	new.room( 31);
	}

if (edge.ego.hit == bottom)
	{
	if (ego.x < 87)
		{
		new.room( 24);
		}
	else
		{
		new.room( 25);
		}
	}

