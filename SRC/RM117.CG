[logics for room 117 -- lgc.snowman

%include	"rm117.msg"
%include	"gamedefs.reh"



[	This logic is only loaded if snowman is going to appear in this room, 
[this time.

[	Used in 4 rooms:  54-56 + 60. the snowman is random, but you MUST see
[him before you get to room 57. The snowman is bigger than Ego.  When snowman 
[comes, he MUST grab ego and drag him off towards his cave. We say ego is 
[dead, but we never see them INSIDE the cave, just the snowman dragging Ego 
[towards rm55. Also, once you encounter him in a room, he ALWAYS get you.  

[	Once you snowman enters the room, he will ALWAYS get you, UNLESS:	
[		you turn yourself into an eagle and fly over him  OR
[		you turn yourself invisible 
[		you POOF yourself out of the room before he catches you.  


[%define	no.snowman			0
[%define	lgc.snowman.loaded		1
[%define	make.snowman.come		2
[%define	snowman.init.done		3
[%define	snowman.after.ego		4
[%define	snowman.at.ego			5
[%define	snowman.dragging.ego	6
[%define	snowman.off.screen		7
[%define	exit.stage.left		101
[%define	erase.snowman			102



[	Scenario is:  if the local room decides to not load the lgc.snowman, it 
[sets snowman.script = 0 [ss == no.snowman]; if it does load it, it sets
[snowman.script = 1 [ss == lgc.snowman.loaded].  It loads it & init.logs it.  
[When the local wants him to appear, or the dynamic timer is up, either can 
[++snowman.script [ss == make.snowman.come].  The dynamic handles getting him 
[on screen and rolling, then ++snowman.script [ss == snowman.init.done].  

[	Once the local detects [ss == snowman.init.done], it starts him on his 
[path, or on a follow.ego and ++snowman.script, [ss == snowman.after.ego].
[If there is a path to follow, the local handles it with lcl.arrived,
[and lcl.location, and set snowman.x/y to the location ego is to be dragged 
[to.  The last "follow.ego" sets snowman.arrived, which tells the dynamic the 
[local room is done.  The local is then finished!  

[	The dynamic handles all the rest.  It detects snowman.arrived, 
[++snowman.script [ss = snowman.at.ego] snowman.at.ego, handles grabbing; 
[when grabbing is done, ++snowman.script [ss == snowman.dragging.ego]; 
[move.objs snowman to snowman.x/y at edge of room, and upon arrival, erases 
[snowman, sets( certain.death) ++snowman.script [ss == snowman.off.screen].        FINE.



%define	wriggle.tgl			df0


%define	snowman.time			dv0
%define	grab.timer			dv1



if (init.log)
	{
	load.view( v.snowman);
	load.view( v.snowman.attacking);
	load.view( v.snowman.dragging.ego);

	animate.obj( a.snowman);
	ignore.blocks( a.snowman);
	ignore.objs( a.snowman);
	set.view( a.snowman, v.snowman);
	work = snowman.step.size;
	step.size( a.snowman, work);
	observe.horizon( a.snowman);

	random( 12, 25, snowman.time);
	if (snowman.script == make.snowman.come)
		{
		goto no.input;
		}

	return();

	}							[	end INIT.LOG



[*****
:handle.input
[*****

if (snowman.on.screen && have.input)
	{
	if (said( look, snowman))
		{
		print( 8);
		}
	
	if (said( talk, snowman))
		{
		print( 9);
		}
	
	if ((said( get, snowman) ||
		said( catch, snowman)))
		{
		print( 10);
		}
	
	if ((said( kill, snowman) ||
		said( hit, snowman)))
		{
		print( 11);
		}
	
	if ((said( kiss, snowman) ||
		said( rub, snowman) ||
		said( pet, snowman)))
		{
		print( 12);
		}
	}
	

[*****
:no.input
[*****

if (aSecondPassed)
	{
	--snowman.time;
	if (snowman.time == 1)
		{
		snowman.script = make.snowman.come;
		}
	}


if (snowman.script == make.snowman.come)
	{
	snowman.time = 0;
	set( snowman.on.screen);
	reset( snowman.arrived);
	draw( a.snowman);
	if (!init.log && current.room != 60)
		{
		print( 1);
		}
	++snowman.script; 				[	now ss = snowman.init.done;
	}


if  (snowman.script == snowman.after.ego &&
	current.status == normal.ego &&
	ego.poofing.done)
	{
	start.motion( a.snowman);
	start.cycling( a.snowman);
	follow.ego( a.snowman, snowman.grab.distance, snowman.arrived);
	observe.blocks( a.snowman);
	}


if (snowman.on.screen)
	{
	if (snowman.arrived)
		{
		reset( snowman.arrived);
		++snowman.script;

		if (snowman.script == snowman.at.ego && !grab.timer)
			{
			work = 1;
			cycle.time( a.snowman, work);
			step.size( a.snowman, work);

			if (!handsOff && !invisibleEgo)
				{
				stop.motion( a.snowman);
				normal.motion(a.snowman);
				stop.cycling( a.snowman);
				grab.timer = 1;	[	start the death scene
				}
			else
				{
				snowman.script = exit.stage.left;
				}
			}
			
		if (snowman.script == snowman.dragging.ego)
			{
			set.view( a.snowman, v.snowman.dragging.ego);
			start.motion( a.snowman);
			start.cycling( a.snowman);
			current.status = being.dragged;
			print(3);
			ignore.block( a.snowman);

			if (current.room == 60)
				{
				erase( a.snowman);
				print( 5);
				set( certain.death);
				}
			else
				{
		move.obj.v( a.snowman, snowman.x, snowman.y, work, snowman.arrived);
				}
		   	}

		if (snowman.script == snowman.off.screen)
			{
			erase( a.snowman);
			print( 4);
			set( certain.death);
			}

		if (snowman.script == exit.stage.left)
			{
			print( 2);

			ignore.blocks( a.snowman);
			set.priority( a.snowman, 15);
			normal.motion( a.snowman);
		move.obj.v( a.snowman, snowman.x, snowman.y, work, snowman.arrived);
			}

		if (snowman.script == erase.snowman)
			{
			erase( a.snowman);
			}
		}	
	}	

if (snowman.script == snowman.dragging.ego)
	{
	set.priority(a.snowman, 15);
	}

if (grab.timer)					[	a little pawin', a little feelin'
	{
	++grab.timer;
		
	if (grab.timer == 2)
		{
		set( handsOff);
		program.control();
		prevent.input();
		ignore.blocks( a.snowman);
		set.view( a.snowman, v.snowman.attacking);
		set.cel( a.snowman, 0);

		stop.motion( ego);
		reset( keep.cycling);
		set( no.cycling);
		current.loop( a.snowman, work);
		if (work == facing.right)
			{
			set.loop( ego, facing.left);
			set.loop( a.snowman, facing.right);
			if (ego.x > 16)
				{
				x = ego.x;
				x -= 17;
				}
			else
				{
				x = 0;
				}
			reposition.to.v( a.snowman, x, ego.y);
			}
		else
			{
			set.loop( ego, facing.right);
			set.loop( a.snowman, facing.left);
			reposition.to.v( a.snowman, ego.x, ego.y);
			}
		}

	if (grab.timer == 7)
		{
		set.cel( a.snowman, 1);
		}

	if (grab.timer == 12)
		{
		set.cel( a.snowman, 2);
		}

	if (grab.timer == 17)
		{
		set.cel( a.snowman, 3);
		erase( ego);
		}

	if (grab.timer > 22)
		{
		toggle( wriggle.tgl);
		if (wriggle.tgl)
			{
			set.cel( a.snowman, 4);
			}
		else
			{
			set.cel( a.snowman, 5);
			}
		}

	if (grab.timer > 66)
		{
		set( snowman.arrived);
		grab.timer = 0;
		}
	}


[*****
:exit
[*****

if  (snowman.script > snowman.after.ego &&
	snowman.script < exit.stage.left)
	{
	edge.ego.hit = 0;
	}

if  (grab.timer)
	{
	edge.ego.hit = 0;
	}

