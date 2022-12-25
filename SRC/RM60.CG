[logics for room 60 -- Inside the abominable snowman's cave. 

%include	"rm60.msg"
%include	"gamedefs.reh"



[	Ego can only enter this room if the snowman wasn't in room 55, or ego
[invisible. Otherwise, snowman would get you before you got here. 1 in 2 times 
[he enters. If snowman catches ego, he grabs ego, and we end with print( 6).

[%define	no.snowman			0
[%define	lgc.snowman.loaded		1
[%define	make.snowman.come		2
[%define	snowman.init.done		3
[%define	snowman.after.ego		4
[%define	snowman.at.ego			5
[%define	snowman.dragging.ego	6
[%define	snowman.off.screen		7



%define	lcl.snowman.arrived		lf0
%define	snowman.in.cave		lf1


%define	snowman.location 		lv0



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.mountains;
	landing.x = 62;
	landing.y = 122;

	set.horizon( 1);
	set(interiorRoom);

	random( 1, 4, work);
	if (force.a.test)
		{
		work = 2;
		}

	if (work > 2)
		{
		snowman.script = no.snowman;
		}
	else
		{
		load.logics( lgc.snowman);
		snowman.script = lgc.snowman.loaded;
		reset( snowman.on.screen);
		if (work == 1)
			{
			set( snowman.in.cave);
			}
		}

	
	[	DON'T MUCK WITH THIS BLOCK, TO PREVENT DISCARD PROBLEMS:

	load.view( v.snowman.bones);
	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);
	[		view, loop, cel, x pos, y pos, object priority, box priority.
	add.to.pic( v.snowman.bones, 0, 0, 122, 157, 14, 0);
	add.to.pic( v.snowman.bones, 0, 1,  74, 132, 12, 0);
	add.to.pic( v.snowman.bones, 0, 2,  83, 144, 13, 0);
	add.to.pic( v.snowman.bones, 0, 3,  87, 120, 11, 0);
	discard.view( v.snowman.bones);


	if (positionEgo)
		{
		if (previous.room == 55)
			{
			position( ego, 17, 167);
			}
		}

	observe.block( ego);

	if (drawEgo)					{draw( ego);}

	if (snowman.script == lgc.snowman.loaded)	[	He's coming
		{
		snowman.x = 0;
		snowman.y = 0;				[	where ego is dragged to

		if (!snowman.in.cave)				[	He's coming later!
			{
			call( lgc.snowman);
			set.loop( a.snowman, facing.front);
			set.priority( a.snowman, 4);
			position( a.snowman, 1, 82);
			}
		else								[	Oh, God!! He's here!!!
			{
			position( a.snowman, 37, 132);
			++snowman.script;		[	ss = make.snowman.come
			call( lgc.snowman);
								[	now ss = snowman.init.done
			set.loop( a.snowman, facing.left);
			release.priority( a.snowman);
			observe.blocks( a.snowman);
			follow.ego( a.snowman, snowman.grab.distance, snowman.arrived);
			snowman.x = 0;
			snowman.y = 0;			[	where ego is dragged to
			++snowman.script;		[	now ss = snowman.after.ego;
			}
		}


	show.pic();

	return();

	}							[	end INIT.LOG


[*****
:handle.input
[*****

if (!have.input)			{goto no.input;}

if ((said( look, cave) ||
	said(look$in, cave) || 
	said( look) ||
	said( look, room)))							{print( 1);}

if ((said( look, bones) ||
	said( get, bones)))							{print( 2);}

if ((said( look, outside) ||
	said( look, outside, cave) ||
	said( look, out)))							{print( 3);}


[*****
:no.input
[*****

[*****
:snowman.stuff
[*****

if (snowman.on.screen)
	{
	if (snowman.script == snowman.init.done)
		{
		++snowman.script;			[	now ss = snowman.after.ego;
		snowman.location = 0;
		move.obj( a.snowman, 1, 43, snowman.step.size, lcl.snowman.arrived);
		ignore.blocks( a.snowman);
		}

	if (snowman.script == snowman.after.ego &&
		lcl.snowman.arrived)
		{
		reset( lcl.snowman.arrived);
		++snowman.location;

		if (snowman.location == 1)
			{
			set.priority( a.snowman, 8);
			move.obj( a.snowman, 1, 124, snowman.step.size, lcl.snowman.arrived);
			}
	
		if (snowman.location == 2)
			{
			move.obj( a.snowman, 24, 147, snowman.step.size, lcl.snowman.arrived);
			}

		if (snowman.location == 3)
			{
			observe.blocks( a.snowman);
			release.priority( a.snowman);
			follow.ego( a.snowman, snowman.grab.distance, snowman.arrived);
			snowman.location = 0;
			}
		}
	}	


if (spell.cast == sc.fly)
	{
	spell.cast = 0;
	if (handsOff)
		{
		print( 16);
		}
	else
		{
		print( 17);
		}
	}


[*****
:exit							[	test for leaving the room
[*****

if (snowman.script)
	{
	call( lgc.snowman);
	}

if (edge.ego.hit == bottom)		{new.room( 55);}

