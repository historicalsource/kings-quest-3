[logics for room 3 -- rm.hallway

%include	"rm3.msg"
%include	"gamedefs.al"
%include	"rm-names.h"



[	No objects to get here.  Wiz might poof in.



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.wiz.house;
	landing.x = 43;
	landing.y = 135;
	wiz.x = 125;
	wiz.y = 140;

	cat.x = 72;
	cat.y = 118;
	load.logics( lgc.wiz.house);


	if ((wiz.away.asleep == home.after.bed ||	[	If we're home, and he's
		wiz.away.asleep == home.after.town) &&
		current.status != snail &&
	    !chore.to.do &&
		wiz.status != dead)
		{
		random( 1, 2, work);
		if (work == 1)						[	home, he may drop in.
			{
			load.logics( lgc.house.wiz);
			set( lgc.house.wiz.loaded);
			random( 6, 12, wiz.entrance.time);	[	he's coming later
			}
		}
		

	if (current.status == snail)
		{
		set( handsOff);
		load.view( v.ego.snail);
		}


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (current.status == fly)
		{
		set( positionEgo);
		}

	if (positionEgo)
		{
		if (previous.room == rm.entry)
			{
			release.priority( ego);
			ego.x = 90;
			ego.y = 167;
			}
		else
			{
			if (previous.room == rm.wiz.bedroom)
				{
				ego.x = 40;
				ego.y = 120;
				}
			else
				{
				if (previous.room == rm.tower)
					{
					ego.x = 133;
					ego.y = 54;
					}
			  	else
					{
					if (previous.room == rm.ego.bedroom)
						{
						ego.x = 133;
						if (ego.y < 133)
							{
							ego.y = 133;
							}
						}
					else
						{
						ego.x = landing.x;
						ego.y = landing.y;
						}
					}
				}
			}

		position.v( ego, ego.x, ego.y);
		}
	

	if (current.status == snail)
		{
		set.view( ego, v.ego.snail);
		ego.cycle.time = snail.step.time;
		cycle.time( ego, ego.cycle.time);
		ego.step.time = snail.step.time;
		step.time( ego, ego.step.time);

		if (previous.room == lgc.PO'd.wiz)
			{
			reset( drawEgo);
			set( positionEgo);
			set( handsOff);
			start.a.poof = poof.in;
			position.v( ego, landing.x, landing.y);
			}
		}

	observe.block( ego);
	observe.objs( ego);

	if (drawEgo)
		{
		draw( ego);
		}

	if (current.status == snail)
		{
		set( drawEgo);				[	to fool rm0 into !drawing him
		}

	call( lgc.wiz.house);

	if (lgc.house.wiz.loaded)
		{
		call( lgc.house.wiz);
		}


	show.pic();
	return();

	}


[*****
:handle.input
[*****

if (!have.input)			{goto no.input;}


if ((said( look, room) || 
	said( look, house) ||
	said( look) || 
	said( look, hall)))
	{
	print( 1);
	}

if ((said( look, stairs) ||
	said( look, up, stairs) ||
	said( look, down, stairs)))
	{
	print( 2);
	}

if (said( look, door))
	{
	print( 6);
	}


[*****
:no.input
[*****

if (ego.poofing.done && current.status == snail)
	{
	[don't reset( ego.poofing.done);
	player.control();
	start.motion( ego);
	reset( keep.cycling);
	reset( no.cycling);
	reset( ignore.special);
	reset( ignore.water);
	print( 8);
	}




[*****
:exit							[	test for leaving the room
[*****

if (current.status != fly.landing)
	{
	if (edge.ego.hit == bottom &&
		ego.x > 84 && ego.x < 105)		{new.room( rm.entry);}
	if (posn( ego,  38,  90,  53, 118))	{new.room( rm.wiz.bedroom);}
	if (posn( ego, 120,  50, 139,  52))	{new.room( rm.tower);}
	if (posn( ego, 139, 133, 159, 166))	{new.room( rm.ego.bedroom);}
	}
	
call( lgc.wiz.house);

if (lgc.house.wiz.loaded)
	{
	call( lgc.house.wiz);
	}

