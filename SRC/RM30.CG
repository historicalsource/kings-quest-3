[logics for room 30 -- Southern beach

%include "gamedefs.al"
%include "rm30.msg"



%define	stun.time				50	[misc constants
%define	HORIZON				74


%define	fall.done				lf0
%define	ego.falling			lf1
%define	sound.done			lf2


%object	a.pirate.ship			1
%object	a.smoke.1				2
%object	a.smoke.2				3



if (init.log)
	{
	set.horizon( HORIZON);

	load.view.f( current.ego);
	set.view.f( ego, current.ego);
	load.view( v.ego);
	map.area = map.llewdor;
	set( beenIn30);
	wiz.x = 20;
	wiz.y = 110;

	random( 2, 3, work);
	if (work == 2)
		{
		landing.x = 56;
		landing.y = 130;
		}
	else
		{
		landing.x = 142;
		landing.y = 119;
		}
	

	load.logics( lgc.seagulls);
	load.logics( lgc.beach);
	load.logics( lgc.swim);

	load.view( v.smoke);
	load.view( v.ego.falling);
	load.view( v.ego.swimming);
	load.view( v.ego.wading.shallow);
	load.view( v.ego.wading.deep);

	if (current.status == falling)
		{
		load.view( v.ego.dead);
		load.sound( s.ego.falling);
		}

	if (shipShape == inPort)
		{
		load.view( v.pirate.ship);
		}
	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);
	if (shipShape == inPort)
		{
		add.to.pic( v.pirate.ship, 1, 0, 104, 46, 4, 4);
		discard.view( v.pirate.ship);
		}

	
	animate.obj( a.smoke.1);
	set.view( a.smoke.1, v.smoke);
	set.loop( a.smoke.1, 2);
	set.cel( a.smoke.1, 2);
	set.priority( a.smoke.1, 4);
	ignore.horizon( a.smoke.1);
	position( a.smoke.1, 76, 27);
	work = 6;
	cycle.time( a.smoke.1, work);
	draw( a.smoke.1);

	animate.obj( a.smoke.2);
	set.view( a.smoke.2, v.smoke);
	set.loop( a.smoke.2, 2);
	set.priority( a.smoke.2, 4);
	ignore.horizon( a.smoke.2);
	position( a.smoke.2, 89, 27);
	work = 6;
	cycle.time( a.smoke.2, work);
	draw( a.smoke.2);

	if ((previous.room == 29 || 
		previous.room == 24 ||
		current.status == falling))
		{
		set( positionEgo);
		set( drawEgo);
		}

	if (positionEgo)
		{
		if ((previous.room == 29 || 
			previous.room == 24 ||
			current.status == falling))
			{
			prevent.input();
			program.control();
			set( handsOff);
			set( keep.cycling);
			ignore.blocks( ego);
			ignore.horizon( ego);
			ego.x = 43;
			ego.y = 33;
			move.obj( ego, 43, 121, falling.step.size, fall.done);
			sound( s.ego.falling, done);
			}
		else
			{
			if (previous.room == 15)
				{
				ego.x = 60;
				if (waterView == wadingShallow)
					{
					ego.x = 122;
					set.view( ego, v.ego.wading.shallow);
					}

				if (waterView == wadingDeep)
					{
					ego.x = 140;
					set.view( ego, v.ego.wading.deep);
					}

				if (waterView == swimmingEgo)
					{
					ego.x = 153;
					ego.y = 130;
					set.view( ego, v.ego.swimming);
					}
				}
			else
				{
				if (previous.room == 25)
					{
					ego.x = 77;

					if (current.status == wading)
				    		{
						ego.x = 112;
						set.view( ego, v.ego.wading.shallow);
					    	}
					
					if (current.status == swimming)
						{
						ego.x = 144;						set.view( ego, v.ego.swimming);
						}
					}
				else
					{
					if ((previous.room == 31 ||
						previous.room == 75 ||
						previous.room == 76))
						{
						ego.x = 150;
						ego.y = HORIZON;
						set.view( ego, v.ego.swimming);
						}
					}
				}
			}

		position.v( ego, ego.x, ego.y);
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



waterView = 0;
if (on.water)
	{
	waterView = wadingShallow;
	}

if ((posn( ego, 119,   0, 126,  94)	||
	posn( ego, 124,  95, 135, 112)	||
	posn( ego, 125, 113, 140, 130)	||
	posn( ego, 129, 131, 159, 167)))
	{
	waterView = wadingDeep;
	}

if ((posn( ego, 127,   0, 159,  94)	||
	posn( ego, 136,  95, 159, 112)	||
	posn( ego, 141, 113, 159, 130)))
	{
	waterView = swimmingEgo;
	}


[*****
[handle.input
[*****

if (have.input)
	{
	if (shipShape == inPort &&
	    (said( look, pier) ||
		said( look, ship)))
		{
		print( 1);
		}

	if (said ( look, town))
		{
		print( 2);
		}

	if (said( look, cliff))
		{
		print( 3);
		}

	if (said( look, pier))
		{
		print( 4);
		}
	}


if (fall.done)
	{
	reset( fall.done);
	set.view( ego, v.ego.dead);
	y = -9;
	x = 0;
	reposition( ego, x, y);
	current.status = dead;
	set( certain.death);
	stop.cycling( ego);
	}



if  (aSecondPassed &&
	shipShape == inPort &&
    !voyage.minutes &&
	voyage.seconds &&
	voyage.seconds < 30)
	{
	voyage.seconds = 30;
	}


[*****
[exit							[	test for leaving the room
[*****

call( lgc.seagulls);
call( lgc.beach);
call( lgc.swim);	

if (edge.ego.hit == bottom)			{new.room( 15);}
if (edge.ego.hit == top)				{new.room( 25);}
if (edge.ego.hit == right)			{new.room( 31);}

