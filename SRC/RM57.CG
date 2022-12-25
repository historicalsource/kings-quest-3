[logics for room 57 -- Climbing down a steep cliff. 

%include	"rm57.msg"
%include	"gamedefs.reh"


[	Ego.location is always 1 here, since all special makes him fall.
[Area is the location that sets the "on.water" flag.

[									  |
[		OFFICIAL HOLE LAYOUT		    _1 |	    _2
[			& DEFINITION:			    \__/	   |
[					   				   __5  |
[									  /	  /
[									4/  _3 |	6
[									    |__/	 \___


%define	hole.122.time			6	[	seconds between holes 1 & 2
%define	hole.324.time			4	[	seconds between holes 3 & 4
%define	hole.526.time			5	[	seconds between holes 5 & 6


%define	took.wrong.trail		lf0
%define	ignoreBlock			lf1
%define	special.tgl			lf2
%define	water.tgl				lf3
%define	seen.message			lf4

%define	debug.line.on			lf15
#define	first.pass			lf16


%define	area					lv0
%define	hole.to.leave			lv1
%define	hole.timer			lv2



if (init.log)
	{
	load.view.v( current.ego);
	set.view.v( ego, current.ego);
	load.view( v.ego);
	map.area = map.mountains;
	set( beenIn57);
	landing.x = 44;
	landing.y = 62;

	set.horizon( 34);

	set( debug.line.on);
	load.logics( lgc.climbing);
	room.bottom = 166;

	load.view( v.ego.climbing);


	load.pic( current.room);
	draw.pic( current.room);
	discard.pic( current.room);


	if (positionEgo)
		{
		set( handsOff);
		if (previous.room == 56)
			{
			start.motion( ego);
			set.view( ego, v.ego.climbing);
			if (ego.x < 60)
				{
				position( ego, 49, 35);
				}
			else
				{
				position( ego, 98, 35);
				set( took.wrong.trail);
				}
			}
		else
			{
			if (previous.room == 58)
				{
				set.view( ego, v.ego);
				position( ego, 151, 164);
				}
			}
		}

	if (drawEgo)
		{
		draw( ego);
		}


	call( lgc.climbing);

	show.pic();

	return();

	}



if (current.status == falling)		[	why fool around if already dead
	{
	goto exit;
	}

[ this is blocked on first pass so it is printed after priority set
if ( first.pass && !escaped.snowman)
	{
	set( escaped.snowman);
	score += 4;
	print( 25);
	}
set( first.pass);


[*****
:handle.input
[*****

if (!have.input)				{goto no.input;}

if ((said( look, mountain) ||
	said( look, up, mountain) ||
	said( look) ||
	said( look, up) ||
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


if ((said( look, cave) ||
	said( look$in, cave)))
	{
	print( 18);
	}

if (said( look, snow))
	{
	print( 19);
	}

if (said( play, snow))
	{
	print( 20);
	}


[*****
:no.input
[*****

area = 0;
ego.location = 1;					[	it's always 1 in this room.

if (hole.timer)					[	why fool around if off.screen?
	{
	ego.dir = old.ego.dir;
	reset( hit.special);
	set( on.water);
	}


if (aSecondPassed)
	{
	--hole.timer;					[	he's been in the hole long enough
	if (hole.timer == 1)			[	make him come out the next hole
		{
		draw( ego);
		hole.timer = 0;
		}
	}



[First, handle walking on a ledge, but with some priority instead of water.

if (posn( ego, 123, 43, 132, 47))
	{
	area = 1;
	set( on.water);
	}

if (posn( ego, 87, 138, 107, 160))
	{
	area = 2;
	set( on.water);
	}

if (posn( ego, 20, 138, 30, 154))
	{
	area = 3;
	set( on.water);
	}

if (posn( ego, 73, 86, 80, 94))
	{
	area = 4;
	set( on.water);
	}

if (posn( ego, 118, 137, 159, 167))
	{
	area = 5;
	set( on.water);
	}

if (posn( ego, 24, 51, 38, 57))
	{
	area = 6;
	set( on.water);
	}

if (posn( ego, 77, 158, 107, 163))
	{
	area = 7;
	set( on.water);
	}



[Next, ignore.block inside the caves, where we only climb and can't walk.
[Note:  this block may well be removed from the picture, but this works!

if (posn( ego, 42, 49, 46, 58))
	{
	area = 11;
	set( ignoreBlock);
	}

if (posn( ego, 110, 39, 118, 46))
	{
	area = 12;
	set( ignoreBlock);
	}

if (posn( ego, 83, 84, 90, 99))
	{
	area = 13;
	set( ignoreBlock);
	}

if (posn( ego, 75, 138, 86, 152))
	{
	area = 14;
	set( ignoreBlock);
	}

if (posn( ego, 32, 133, 39, 150))
	{
	area = 15;
	set( ignoreBlock);
	}

if (posn( ego, 37, 49, 38, 59))
	{
	area = 16;
	set( ignoreBlock);
	}

if (ignoreBlock)
	{
	reset( ignoreBlock);
	ignore.block( ego);
	}
else
	{
	observe.block( ego);
	}



[Now, if he walked into a cave, kill a little time, then redraw him coming
[out of the next cave.

if (posn( ego, 35, 51, 36, 57))
	{
	area = 21;
	erase( ego);
	position( ego, 125, 43);
	hole.timer = hole.122.time;

	if (!seen.hole.message)
		{
		set( seen.hole.message);
		print( 10);
		}
	}

if (posn( ego, 123, 43, 124, 44))
	{
	area = 22;					[	from hole 2 to hole 1
	erase( ego);
	position( ego, 34, 54);
	hole.timer = hole.122.time;
	}

if (posn( ego, 90, 140, 91, 148))
	{
	area = 23;					[	from hole 3 to hole 4
	erase( ego);
	position( ego, 27, 145);
	hole.timer = hole.324.time;
	}

if (posn( ego, 28, 141, 29, 149))
	{
	area = 24;					[	from hole 4 to hole 3
	erase( ego);
	position( ego, 92, 144);
	hole.timer = hole.324.time;
	}

if (posn( ego, 79, 86, 80, 94))
	{
	area = 25;					[	from hole 5 to hole 6
	erase( ego);
	position( ego, 129, 140);
	hole.timer = hole.526.time;
	}

if (posn( ego, 127, 138, 128, 142))
	{
	area = 26;					[	from hole 6 to hole 5
	erase( ego);
	position( ego, 78, 90);
	hole.timer = hole.526.time;
	}



[Lastly, handle the weird patches so necessary to a programmer like me.

if (posn( ego, 43, 150, 51, 161) && 	[	This compensates for ego.climbing
	!on.water)					[	being wider than ego.walking,
	{							[	otherwise, he get "launched."
	ego.x = 42;
	reposition.to.v( ego, ego.x, ego.y);
	}



[And now, the code we've all been waiting for.  Once we set up, this is easy:

if (on.water)						[	He's walking.
	{
	reset( hit.special);
	current.status = walking;
	release.priority( ego);
	set.view( ego, v.ego);
	}
else
	{
	if (!hit.special)				[	He's climbing.
		{
		current.status = climbing;
		set.view( ego, v.ego.climbing);
		set.priority( ego, 14);
		}
	else
		{
		set.priority( ego, 15);		[	His ass is history!
		}
	}


[	Handle trying to rub the magic rock while you're hanging by your toes:

if (spell.cast == sc.poof &&
	current.status == climbing)
	{
	spell.cast = 0;
	print( 21);
	set( hit.special);
	set( seen.message);
	set.priority( ego, 15);			[	His ass is history!
	set( took.wrong.trail);
	drop( i.magic.stone);
	}

if (spell.cast == sc.fly)
	{
	spell.cast = 0;
	drop( i.fly.wings);
	print( 23);
	}

if (spell.cast == sc.eagle)
	{
	spell.cast = 0;
	drop( i.eagle.feather);
	print( 24);
	}


[*****
:exit							[	test for leaving the room
[*****

set( handsOff);					[	no more funny stuff here!

call( lgc.climbing);

if (took.wrong.trail)
	{
	if (!seen.message)				[	fall if on right side of cliffs
		{
		set( seen.message);
		set( hit.special);
		print( 7);
		}

	if (current.status == falling &&
		ego.y > 162)
		{
		reset( took.wrong.trail);
		print( 8);
		}
	}	


if (debugging && debug.line.on && monitor.type != mono)
	{
	display( 22, 22, 9);
	if (!hit.special)
		{
		display( 23, 22, 11);
		}
	else
		{
		toggle( special.tgl);
		if (special.tgl)
			{
			display( 23, 22, 12);
			}
		else
			{
			display( 23, 22, 13);
			}
		}
	
	if (!on.water)
		{
		display( 23, 27, 11);
		}
	else
		{
		toggle( water.tgl);
		if (water.tgl)
			{
			display( 23, 27, 14);
			}
		else
			{
			display( 23, 27, 15);
			}
		}
	}	

if (edge.ego.hit)
	{
	reset( handsOff);
	if (edge.ego.hit == top && ego.x < 60)	{new.room( 56);}
	if (edge.ego.hit == right)			{new.room( 58);}
	if (edge.ego.hit == bottom)			{set( hit.special);}
	}

