[logics for room 56 -- More abominable snowman territory. 

%include	"rm56.msg"
%include	"gamedefs.reh"


[	If he's made it this far, there's a 100% chance of the snowman coming.
[He'd better not be himself!!

[%define	no.snowman			0
[%define	lgc.snowman.loaded		1
[%define	make.snowman.come		2
[%define	snowman.init.done		3
[%define	snowman.after.ego		4
[%define	snowman.at.ego			5
[%define	snowman.dragging.ego	6
[%define	snowman.off.screen		7



%define	coming.in.for.a.landing	lf0



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.mountains;
	set( beenIn56);
	landing.x = 44;
	landing.y = 154;
	set.horizon( 114);


	load.logics( lgc.climbing);
	room.bottom = 166;


	if (previous.room == 55)
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
		if (previous.room == 57)
			{
			position( ego, 40, 167);
			if (current.status == climbing)
				{
				current.status = normal.ego;
				set.view( ego, v.ego);
				}
			}
		else
			{
			if (previous.room == 55)
				{
				position( ego, 0, 139);
				}
			}
		}


	observe.blocks( ego);
	if (drawEgo)					{draw( ego);}

	call( lgc.climbing);

	if (snowman.script == lgc.snowman.loaded)
		{
		call( lgc.snowman);
		set.priority( a.snowman, 10);
		set.loop( a.snowman, facing.right);
		position( a.snowman, 0, 135);
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

if ((said( look, plants) ||
	said( look, tree) ||
	said( pick, flowers) ||
	said( get, flowers) ||
	said( look, flowers)))
	{
	print( 3);
	}

if (said( look, ground))
	{
	print( 4);
	}

if (said( look, sky))
	{
	print( 5);
	}

if ((said( climb, trees) ||
	said( climb, up, trees)))
	{
	print( 6);
	}

if (said( look, snow))
	{
	print( 7);
	}

if (said( play, snow))
	{
	print( 9);
	}

if (said( look, valley))
	{
	print( 15);
	print( 16);
	print( 17);
	}


[*****
:no.input
[*****

if (ego.poofing.done){
	if (current.status == normal.ego){
		reset( coming.in.for.a.landing);	[ bottom of room trip wire
	}
}
		


ego.location = 0;
if (hit.special)
	{
	if (ego.x < 114)				[	avoid the P0 around that rock!
		{
		ego.location = 1;
		ego.x = 114;
		reposition.to.v( ego, ego.x, ego.y);
		}
	else
		{
		if (ego.y < 128)
			{
			ego.location = 2;
			set.priority( ego, 4);
			}
		else
			{
			if (posn( ego, 105, 130, 169, 160))
				{
				ego.location = 3;
				set.priority( ego, 11);
				}
			else
				{
				set.priority( ego, 14);
				ego.location = 4;
	
				if  (ego.x > 140 &&
				    (ego.dir == ego.right ||
					ego.dir == ego.up.right ||
					ego.dir == ego.down.right))
					{
					ego.location = 5;
					ego.x += 4;
					reposition.to.v( ego, ego.x, ego.y);
					}
				}
			}
		}	
	}
	

[*****
:snowman.stuff
[*****

if  (ego.x > 30 && 
    !snowman.on.screen &&
	snowman.script == lgc.snowman.loaded)
	{
	++snowman.script; 				[	now ss = make.snowman.come;
	}


if (snowman.on.screen)
	{
	if (snowman.script < snowman.dragging.ego)
		{
		get.posn( a.snowman, x, y);
		if (y > 111)
			{
			release.priority( a.snowman);
			}
		else
			{
			set.priority( a.snowman, 10);
			}
		}

	if (snowman.script == snowman.init.done)
		{
		++snowman.script;			[	now ss = snowman.after.ego;
		follow.ego( a.snowman, snowman.grab.distance, snowman.arrived);
		observe.blocks( a.snowman);
		snowman.x = 1;
		snowman.y = 135;			[	where ego is dragged to
		}
	}
	


[*****
:exit							[	test for leaving the room
[*****

call( lgc.climbing);

if (snowman.script)
	{
	call( lgc.snowman);
	}


[if (invisibleEgo &&
[	!coming.in.for.a.landing &&
[	ego.y > 155)
[	{
[	set( coming.in.for.a.landing);
[	print( 14);
[	spell.cast = sc.visible;
[	}

if (edge.ego.hit == bottom && 
   (current.status == eagle || current.status == fly)){
	{
	edge.ego.hit = 0;
	spell.cast = sc.stop.flying;
	}


if (edge.ego.hit == left)
	{
	new.room( 55);
	}

if (edge.ego.hit == bottom)
	{
	if (!beenIn57)
		{
		print(13);
		}
	set.view( ego, v.ego);
	current.ego = normal.ego;
	new.room( 57);
	}

