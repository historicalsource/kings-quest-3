[logics for room 22 -- below bandit's tree

%include "gamedefs.al"
%include "rm22.msg"



%define	l.looking.right		0		[rm4		VIEW.LOOKING.UNDER
%define	l.looking.rear			1		[rm22

%define	dead.time				40
%define 	ground.y.1			115
%define 	ground.y.2			124

%define	ladder.bottom			1	[	on.ladder values
%define	ladder.middle			2
%define	ladder.top			3


%define	sound.done			lf0
%define	next.kneel.script		lf1
%define	ego.dead				lf2
%define	near.hole				lf3
%define	lower.ladder			lf4
%define	pull.rope				lf5
%define	fell.from.treehouse		lf6
%define	in.hole				lf7
%define	near.tree				lf8
%define	near.acorn			lf9
%define	hit.ground			lf10
%define	bandits.loaded			lf11
%define	rope.ladder.down		lf12


%define	on.ladder				lv0
%define	stunned.seconds		lv1
%define	kneel.script			lv2
%define	rope.pic				lv3
%define	kneel.seconds			lv4
%define	fall					lv5



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	map.area = map.llewdor;
	set( beenIn22);
	set.horizon( 56);
	wiz.y = 0; 					[	lock the wiz out

	random( 1, 3, work)
	if (work == 1)
		{
		landing.x = 27;
		landing.y = 70;
		}
	else
		{
		if (work == 2)
			{
			landing.x = 69;
			landing.y = 150;
			}
		else
			{
			landing.x = 139;
			landing.y = 82;
			}
		}
	

	if (current.status == falling)
		{
		set( handsOff);
		load.view( v.ego.dead);
		load.view( v.ego.falling);
		load.sound( s.ego.falling);
		}
	else
		{
		load.view( v.ego);
		load.view( v.ego.looking.under);

		if (!ego.been.robbed)
			{
			random( 1, 3, work);
			if (work == 1)
				{
				set( bandits.loaded);
				load.logics( lgc.bandits.exterior);
				}
			}
		}

	if ((previous.room == 37 ||
		previous.room == 38))
		{
		set( rope.ladder.down);
		}

	[	Don't muck with this next section; it's sequence dependent:
	rope.pic = 122;
	if (rope.ladder.down)
		{
		load.sound( s.ego.falling);
		load.view( v.ego.falling);
		load.view( v.ego.climbing.ladder);
		load.view( v.ego.dead);

		load.pic( rope.pic);
		}
	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);
	if (rope.ladder.down)
		{
		overlay.pic( rope.pic);
		discard.pic( rope.pic);
		}

	load.view( v.ego.stunned);
	load.sound( s.ego.stunned);

	load.logics( lgc.near.desert);
	load.logics( lgc.forest);


	if ((positionEgo || previous.room == 35))
		{
		if (previous.room == 35)		[	inside tree
			{
			set( positionEgo);
			ego.x = 113;
			ego.y = 135;
			}

		if (previous.room == 37)
			{
			if (current.status == falling)
				{
				if (ego.x > 92)
					{
					ego.x = 139;
					}
				else
					{
					ego.x = 124;
					}
				ego.y = 36;
				set.priority( ego, 11);
				ignore.blocks( ego);
				ignore.horizon( ego);
				step = falling.step.size;
				y = ground.y.2;
				move.obj.v( ego, ego.x, y, step, fell.from.treehouse);
				on.ladder = ladder.top;
				sound( s.ego.falling, done);
				}
			else
				{
				ignore.horizon( ego);	[	current.status == climbing
				ignore.blocks( ego);
				on.ladder = ladder.top;
				ego.x = 131;
				ego.y = 57;			[	top of ladder
				set.loop( ego, 0);
				fix.loop( ego);
			     set.priority( ego, 11);
				}
			}
			
		position.v( ego, ego.x, ego.y);
		}


	if (drawEgo)
		{
		draw( ego);
		}

	call( lgc.forest);

	if (bandits.loaded)
		{
		call( lgc.bandits.exterior);
		}

	show.pic();

	return();

	}



if (current.status == falling)
	{
	ignore.blocks( ego);
	ignore.objs( ego);
	ignore.horizon( ego);
	}



reset( near.tree);
if (posn( ego, 72, 106, 159, 151))
	{
	set( near.tree);
	}

reset( near.acorn);
if (posn( ego, 99, 129, 131, 140))
	{
	set( near.acorn);
	}

reset( near.hole);
if (posn( ego, 82, 121, 150, 141))
	{
	set( near.hole);
	}

reset( in.hole);
if (posn(ego, 115, 129, 119, 142))
	{
	set( in.hole);
	}



[*****
[handle.input
[*****

if (have.input)
	{
	if ((said( look, room) || said( look)))
		{
		print( 1);
		}

	if ((said( look, tree) || 
		said( look, up, tree)))
		{
		print( 2);
		}

	if (posn( ego, 53, 90, 72, 135) &&
		said( anyword, flowers))
		{
		print( 19);
		}

	if (said( climb, tree))
		{
		if (near.tree)
			{
			print( 3);
			}
		else
			{
			print( 14);
			}
		}
	
	if (!handsOff &&
	    (said( look, hole) ||
		said( look$in, hole) ||
		said( look$in, tree)))
		{
		if (!near.hole)
			{
			print( 16);
			}
		else
			{
			kneel.script = 0;
			set( next.kneel.script);
			message = 4;
			}
		}


	if (!handsOff && 
		found.rope && 
		said( pull, rope))
		{
		set( pull.rope);
		}

	if (!handsOff &&
	    (pull.rope ||
		said( reach, hole) ||
		said( put, hand, hole) ||
		said( put, hand, tree) ||
		said( pull, rope, hole) ||
		said( feel, inside, hole) ||
		said( feel, inside, tree) ||
		said( reach, inside, hole) ||
		said( reach, inside, tree) ||
		said( put, hand, inside, tree) ||
		said( reach, hole, pull, rope) ||
		said( reach, hand, hole, pull, rope)))
		{
		reset( pull.rope);
		if (!near.hole)
			{
			print( 16);
			}
		else
			{
			kneel.script = 0;
			set( next.kneel.script);
			if (rope.ladder.down)
				{
				message = 7;
				}
			else	
				{
				message = 5;
				set( lower.ladder);
				}
			}
	    }


	if ((said( look, ladder) 	 ||
		said( look, rope, ladder) ||
		said( look, ladder, tree)))
		{
		if (rope.ladder.down)
			{
			print( 8);
			}
		else
			{
			print( 15);
			}
		}

	if ((said( get, ladder) ||
		said( get, rope, ladder) ||
		said( get, ladder, tree)))
		{
		if (rope.ladder.down)
			{
			print( 9);
			}
		else
			{
			print( 15);
			}
		}

	if ((said( look, ground) ||
		said( look, under, tree)))
		{
		print( 10);
		}

	if ((said( look, acorns) ||
		said( look, acorns, ground) ||
		said( look, acorns, ground, under, tree)))
		{
		print( 11);
		}

	if ((said( get, acorn) ||
		said( get, acorn, ground) ||
		said( get, acorn, from, ground)))
		{
		if (!near.tree)
			{
			print( 16);
			}
		else
			{
			if (obj.in.room( i.acorns, current.room) &&
				near.acorn)
				{
				print( 12);
				get( i.acorns);
				score += 1;
				}
			else
				{
				print( 13);
				}
			}
		}
	}


[*****
[on & off ladders
[*****

if (hit.special)
	{
	if (!on.ladder)
		{
		on.ladder = bottom;
		ignore.block( ego);
		current.status = climbing;
		set.view( ego, v.ego.climbing.ladder);
		start.motion( ego);

		if (ego.y == 119)
			{
			set.loop( ego, 1);
			set.priority( ego, 10);	[	backside of ladder
			}
		else
			{
			set.loop( ego, 0);
			set.priority( ego, 11);	[	frontside of ladder
			}
		fix.loop( ego);
		reposition.to (ego, 131, 117);
		}
	else
		{
		on.ladder = 0;
		reset( handsOff);
		release.priority( ego);
		observe.block( ego);
		set.view( ego, v.ego);
		current.status = normal.ego;
		start.motion(ego);

		current.loop( ego, loop);
		if (!loop)
			{
			set.loop( ego, facing.back);
			y = ground.y.2;
			}
		else
			{
			set.loop( ego, facing.front);
			y = ground.y.1;
			}
		reposition.to.v( ego, ego.x, y);
		release.loop( ego);
		}
	}


if (on.ladder)
	{
	set( handsOff);

	on.ladder = ladder.bottom;
	if (ego.y < 100)
		{
		on.ladder = ladder.middle;
		}

	if (ego.y < 70)
		{
		on.ladder = ladder.top;
		}


	if (!posn( ego, 129, 0, 133, 122))	[	leaving the ladder
		{
		fall = on.ladder;
		on.ladder = 0;
		set( ignore.special);
		current.status = falling;
		
		if (fall == ladder.bottom)
			{
			set.view( ego, v.ego);
			}
		else
			{
			set.view( ego, v.ego.falling);
			set( keep.cycling);
			}

		current.loop( ego, loop);
		if (loop == 1)
			{
			y = ground.y.1;
			}
		else
			{
			y = ground.y.2;
			}
		release.loop( ego);
		step = falling.step.size;
		move.obj.v( ego, ego.x, y, step, hit.ground);
		}
	}



if (hit.ground)
	{
	reset( hit.ground);
	reset( ignore.special);
	observe.blocks( ego);
	observe.horizon( ego);
	release.priority( ego);

	if (fall == ladder.bottom)
		{
		current.status = normal.ego;
		start.motion( ego);
		reset( keep.cycling);
		reset( handsOff);
		}
	else
		{
		if (fall == ladder.middle)
			{
			set.view( ego, v.ego.stunned);
			program.control();
			prevent.input();
			stop.motion( ego);
			current.status = stunned;
			set( sound.done);
			stunned.seconds = ego.stunned.time;
			reset( handsOff);
			}
		else
			{
			set(fell.from.treehouse);
			}
		}
	
	fall = 0;
	}


if (fell.from.treehouse)
	{
	reset( fell.from.treehouse);
	set.view( ego, v.ego.dead);
	program.control();
	prevent.input();
	stop.motion( ego);
	stop.cycling( ego);
	set( certain.death);
	}


if (aSecondPassed)
	{
	--stunned.seconds;
	if (stunned.seconds == 1)
		{
		player.control();
		accept.input();
		reset( handsOff);
		reset( keep.cycling);
		reset( sound.done);
		stop.sound();
		start.motion( ego);
		current.status = normal.ego;
		set.view( ego, v.ego);
		observe.blocks( ego);
		}
	}

if (sound.done && current.status == stunned)
	{
	sound( s.ego.stunned, sound.done);
	}




[*****
[kneel down in front of hole
[*****

if (aSecondPassed)
	{
	--kneel.seconds;
	if (kneel.seconds == 1)
		{
		set( next.kneel.script);
		}
	}

if (next.kneel.script)
	{
	reset( next.kneel.script);
	++kneel.script;
	program.control();
	prevent.input();
	set( handsOff);

	if (kneel.script == 1)
		{
		set( keep.cycling);
		if (ego.y > 126)			[	Clear of the tree root.
			{
			kneel.script = 2;		[	Skip first move; go directly.
			}
		else
			{
			y = 127;
			step = 1;
			move.obj.v( ego, ego.x, y, step, next.kneel.script);
			}
		}

	if (kneel.script == 2)
		{
		move.obj( ego, 114, 135, 1, next.kneel.script);
		}

	if (kneel.script == 3)
		{
		stop.motion( ego);
		set.view( ego, v.ego.looking.under);
		set.loop( ego, 1);
		set.cel( ego, 0);
		work = 4;
		cycle.time( ego, work);
		end.of.loop( ego, next.kneel.script);
		}
	
	if (kneel.script == 4)
		{
		reset( keep.cycling);
		kneel.seconds = 3;
		}

	if (kneel.script == 5)
		{
		print.v( message);
		kneel.seconds = 3;

		if (lower.ladder)
			{
			reset( lower.ladder);
			set( rope.ladder.down);
			if (!found.rope)
				{
				set(found.rope);
				score += 3;
				}
			load.view( v.ego.falling);
			load.view( v.ego.climbing.ladder);
			load.view( v.ego.dead);

			load.pic( rope.pic);
			overlay.pic( rope.pic);
			discard.pic( rope.pic);
			show.pic();
			}
		}

	if (kneel.script == 6)
		{
		set( keep.cycling);
		reverse.loop( ego, next.kneel.script);
		}

	if (kneel.script == 7)
		{
		kneel.script = 0;
		set.view( ego, v.ego);
		player.control();
		accept.input();
		reset( handsOff);
		cycle.time( ego, ego.cycle.time);
		reset( keep.cycling);
		start.motion( ego);
		}
	}



[*****
[exit							[	test for leaving the room
[*****

call( lgc.near.desert);
call( lgc.forest);

if (bandits.loaded)
	{
	call( lgc.bandits.exterior);
	}

if (edge.ego.hit == bottom)			{new.room( 27);}
if (edge.ego.hit == left)			{new.room( 21);}
if (edge.ego.hit == right)			{new.room( 23);}

if (edge.ego.hit == top)
	{
	if (current.status == climbing)
		{
		new.room( 37);			 	[	treehouse
		}
	else
		{
		new.room( 17);
		}
	}

if (current.status == fly && in.hole)
	{
	if (!got.it.in.the.hole)
		{
		set( got.it.in.the.hole);
		score += 5;
		}
	print( 17);
	new.room( 35);
	}

