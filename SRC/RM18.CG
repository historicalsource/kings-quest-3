[logics for room 18 -- Bottom of wizard's hill

%include "gamedefs.al"
%include "rm18.msg"



%define	ego.splat				lf0
%define	ego.falling			lf1
%define	feather.lgc.loaded		lf2


%define	splat.x				lv0
%define	splat.y				lv1
%define	fall.rate				lv2



if (init.log)
	{
	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	load.view( v.ego);
	map.area = map.llewdor;
	set( beenIn18);
	wiz.x = 131;
	wiz.y = 104;
	set.horizon( 40);

	random( 1, 3, work);
	if (work ==1)
		{
		landing.x = 145;
		landing.y = 145;
		}
	else
		{
		if (work == 2)
			{
			landing.x = 70;
			landing.y = 140;
			}
		else
			{
			landing.x = 5;
			landing.y = 130;
			}
		}


	load.logics( lgc.forest);
	load.logics( lgc.eagle.feather);
	load.logics( lgc.climbing);
	reset( survivable.fall);
	room.bottom = 164;

	load.view( v.ego.falling);

	
	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		if (previous.room == 33)
			{
			start.motion( ego);
			ego.x = 14;
			ego.y = 44;
			}

		if (previous.room == 17)
			{
			if (ego.y < 114)
				{
				ego.y = 114;
				}
			}

		if (previous.room == 19)
			{
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


	call( lgc.eagle.feather);
	call( lgc.climbing);

	show.pic();

	return();

	}



[*****
:handle.input
[*****
call( lgc.eagle.feather);

if (have.input)
	{
	if ((said( look, mountain) ||
	     said( look, top, mountain) ||
		said( look)))
		{
		print( 3);
		}

	if ((said( look, path) ||
		said( look, path, mountain) ||
		said( look, mountain, path)))
		{
		print( 4);
		}

	if ((said( climb) || said( climb, mountain)))
		{
		print( 5);
		}
	}	



[****
:no.input
[****

if (hit.special && !ego.falling)
	{
	get.priority( ego, work);
	set.priority.v( ego, work);
	ego.location = 0;				[	unknown!

	[	Handle special fall zones:

	if (posn( ego, 27, 48, 75, 57))
		{
		ego.location = 1;
		}

	if (posn( ego, 75, 58, 87, 69))
		{
		ego.location = 2;
		ego.x -= 8;
		reposition.to.v( ego, ego.x, ego.y);
		start.climbing = falling;
		}

	if (posn( ego, 89, 71, 97, 81))
		{
		ego.location = 3;
		ego.x -= 8;
		reposition.to.v( ego, ego.x, ego.y);
		start.climbing = falling;
		}

	if (posn( ego, 98, 83, 112, 94))
		{
		ego.location = 4;
		}

	if (posn( ego, 112, 95, 123, 109))
		{
		ego.location = 5;
		ego.x -= 8;
		reposition.to.v( ego, ego.x, ego.y);
		start.climbing = falling;
		}

	if (posn( ego, 67, 96, 104, 108))
		{
		ego.location = 6;
		get.priority( ego, work);
		--work;
		set.priority.v( ego, work);
		}

	if (posn( ego, 40, 102, 53, 122))
		{
		ego.location = 7;
		ego.x -= 8;
		reposition.to.v( ego, ego.x, ego.y);
		start.climbing = falling;
		}

	if (posn( ego, 16, 113, 25, 119))
		{
		ego.location = 8;
		ego.x += 8;
		reposition.to.v( ego, ego.x, ego.y);
		start.climbing = falling;
		}

	if (posn( ego, 133, 95, 139, 111))
		{
		ego.location = 9;
		set.priority( ego, 10);
		ego.x += 8;
		reposition.to.v( ego, ego.x, ego.y);
		start.climbing = falling;
		}

	if (posn( ego, 57, 112, 67, 125))
		{
		ego.location = 10;
		set.priority( ego, 10);
		ego.x += 8;
		reposition.to.v( ego, ego.x, ego.y);
		start.climbing = falling;
		}

	if (posn( ego, 68, 111, 146, 118))
		{
		ego.location = 11;
		}

	if (posn( ego, 106, 127, 126, 130))
		{
		ego.location = 12;
		get.priority( ego, work);
		--work;
		set.priority.v( ego, work);
		}

	}



[*****
[exit							[	test for leaving the room
[*****

call( lgc.climbing);
call( lgc.forest);

if (edge.ego.hit == bottom)			{new.room( 23);}
if (edge.ego.hit == left)			{new.room( 17);}
if (edge.ego.hit == right)			{new.room( 19);}
if (posn( ego, 0, 41, 10, 47))		{new.room( 33);}

