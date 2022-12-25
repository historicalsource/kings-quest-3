[logics for room 55 -- outside the Abominable snowman's cave 

%include	"rm55.msg"
%include	"gamedefs.reh"



[	The snowman's cave is here. If he is here, or if he catches you, use same
[messages as in room 54.  No objects in this room. west is room 54.  east is 
[room 56.  the path to the cave takes you to room 60.



[%define	no.snowman			0
[%define	lgc.snowman.loaded		1
[%define	make.snowman.come		2
[%define	snowman.init.done		3
[%define	snowman.after.ego		4
[%define	snowman.at.ego			5
[%define	snowman.dragging.ego	6
[%define	snowman.off.screen		7



%define	lcl.snowman.arrived		lf0


%define	snowman.location 		lv0



if (init.log)
	{
	if ((storm.minutes || storm.seconds) && previous.room == 60)
		{
		pre.previous.room = previous.room;
		new.room( 87);
		}

	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.mountains;
	set( beenIn55);
	landing.x = 30;
	landing.y = 95;

	set.horizon( 76);

	random( 1, 2, work);
	if (previous.room == 60)
		{
		work = 0;
		}

	if (handsOff){
		work = 0;
	}

	if (work == 1)
		{
		load.logics( lgc.snowman);
		snowman.script = lgc.snowman.loaded;
		reset( snowman.on.screen);
		}
	else
		{
		snowman.script = no.snowman;
		}


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		if (previous.room == 60)
			{
			release.priority( ego);
			position( ego, 118, 112);
			}
		else
			{
			if (previous.room == 56)
				{
				release.priority( ego);
				position( ego, 152, 142);
				}
			else
				{
				position( ego, 0, 99);
				set.priority( ego, 14);
				}
			}
		}


	observe.blocks( ego);
	if (drawEgo)
		{
		draw( ego);
		}


	if (snowman.script == lgc.snowman.loaded)
		{
		call( lgc.snowman);
		release.priority( a.snowman);
		set.loop( a.snowman, facing.left);
		position( a.snowman, 130, 106);
		ignore.blocks( a.snowman);
		}

	show.pic();
	return();

	}


[*****
:handle.input
[*****

if (!have.input)				{goto no.input;}

if ((said( look, mountain) ||
	said( look, up, mountain) ||
	said( look, up) ||
	said( look) ||
	said( look, room) ||
	said( look, down)))
	{
	print( 1);
	}

if (said( look, path))
   	{
	print( 2);
	}

if ((said( look, cave) ||
	said( look$in, cave) ||
	said( look, inside, cave)))
	{
	print( 3);
	}

if ((said( look, plants) ||
	said( look, tree) ||
	said( pick, flowers) ||
	said( get, flowers) ||
	said( look, flowers)))
	{
	print( 13);
	}

if (said( look, ground))
	{
	print( 4);
	}

if (said( look, sky))
	{
	print( 5);
	}


if (said( look, snow))
	{
	print( 7);
	}

if (said( play, snow))
	{
	print( 9);
	}


[*****
:no.input
[*****

if (current.status == normal.ego)
	{
	if (ego.x > 113)
		{
		release.priority( ego);
		}
	else
		{
		set.priority( ego, 13);
		}
 	}


[*****
:snowman.stuff
[*****

if  (ego.x > 62 && 
	!snowman.on.screen &&
	snowman.script == lgc.snowman.loaded)
	{
	++snowman.script; 				[	now ss = make.snowman.come;
	}


if (snowman.on.screen)
	{
	if (snowman.script == snowman.init.done)
		{
		++snowman.script;			[	now ss = snowman.after.ego;
		snowman.location = 0;
		move.obj( a.snowman, 100, 106, snowman.step.size, lcl.snowman.arrived);
		ignore.blocks( a.snowman);
		}

	if (snowman.script == snowman.after.ego &&
		lcl.snowman.arrived)
		{
		reset( lcl.snowman.arrived);
		++snowman.location;

		if (snowman.location == 1)
			{
			set.priority( a.snowman, 10);
		   	move.obj( a.snowman, 100, 85, snowman.step.size, lcl.snowman.arrived);
			}

		if (snowman.location == 2)
			{
			set.priority( a.snowman, 13);
		   	move.obj( a.snowman, 74, 96, snowman.step.size, lcl.snowman.arrived);
			if (ego.x > 84)
				{
				snowman.location = 3;
				}
			}

		if (snowman.location == 3)
			{
			follow.ego( a.snowman, snowman.grab.distance, snowman.arrived);
			snowman.location = 0;
			snowman.x = 106;
			snowman.y = 96;		[	where ego is dragged to
			}
		}
	}



[*****
:exit							[	test for leaving the room
[*****

if (snowman.script)
	{
	call( lgc.snowman);
	}

if (!handsOff &&
	current.ego == normal.ego &&
	posn( ego, 112, 110, 120, 111))	{new.room( 60);}
if (edge.ego.hit == left)			{new.room( 54);}
if (edge.ego.hit == right)			{new.room( 56);}
