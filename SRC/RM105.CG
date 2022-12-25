[logics for room 105 -- lgc.house.wiz

%include	"rm105.msg"
%include	"gamedefs.al"



[	Wiz.temper starts at 0; talked.once == 1; assign.chore == 2; punish == 3;
[get.outta.here = 4.  Get.outta.here is used when wiz enters room 1, 2, 5
[after ego. It says, "get out in 25" or die", and sets 
[wiz.temper = assign.chore.  When wiz.temper == assign.chore, we start a 
[clock; after 25" without a new.room, dirty wiz is summonded to punish ego.  
[The local rooms can ++wiz.temper or directly set it to the proper value. 
[We detect a change in temperment here.

[	This is used only in wizard house.  Loaded and called by the local,
[which decides how it is used this trip.  To get a wiz immediately, the local
[must set wiz.entrance.time to 0, call this logic, and then set.view,
[position and draw wizzie itself.

[	When (seconds.in.room == wiz.entrance.time && !wiz.on.screen)
[we draw that sucker. Let room mainline code move him in if necessary.
[If (wiz.on.screen) we handle input not already caught by room logics.

[	We handle ego feeding wizard anything.

[	We handle wiz killing ego, if ego:  is (or tries to be) a fly, tries to 
[be eagle, rubs his rocks, throws down the sleeping powder, brews a storm, 
[or tries to be invisible.



[%var	wiz.temper			129
[%define	rational			0
[%define	talked.once		1
[%define	assign.chore		2
[%define	punish			3
[%define	get.outta.here		4

%define	temper.init.seconds		25


%define	house.wiz.done			df6	[	This room gets 6-12.


%define	house.wiz.script		dv6
%define	house.wiz.seconds		dv7
%define	bugged.wiz.count		dv8
%define	bug.wiz.timer			dv9
%define	old.wiz.temper			dv10
%define	temper.timer			dv11



if (init.log)
	{
	load.logics( lgc.inventory.check);

	load.view( v.wiz);
	load.view( v.poof);

	load.sound( s.ego.poofing);
	load.sound( m.wiz);


	animate.obj( a.poof);
	animate.obj( a.wiz);


	wiz.temper = 0;
	bug.wiz.timer = 10;
	wiz.status = waiting.to.appear;


	if (debugging && monitor.type != mono)
		{
		set.text.attribute( 2, 0);
		display( 22, 0, 8);			[	wiz.entrance.time
		set.text.attribute( text.color, bg.color);
		}

	return();

	}



[*****
:handle.input
[*****

if (!wiz.on.screen)				{goto no.input;}

if ((said( look, wizard) ||
	said( look, at, wizard)))
	{
	print( 1);
	}

if (said( kill, wizard))
	{
	print( 2);
	}

if ((said( kiss, wizard) ||
	said( rub, wizard) ||
	said( eat, wizard)))
	{
	print( 3);
	}

if ((said( get, wizard) ||
	said( catch, wizard)))
	{
	print( 4);
	}

if ((said( cast, spell) ||
	said( cast, spell, wizard) ||
	said( cast, spell, on, wizard) ||
	said( perform, magic) ||
	said( perform, magic, spell) ||
	said( perform, magic, spell, on, wizard) ||
	said( perform, magic, spell, wizard)))
	{
	print( 5);
	}


if (said( talk, wizard))
	{
	++wiz.temper;
	}


[*****
:no.input
[*****

if  (wiz.on.screen &&
    (wiz.away.asleep == home.after.bed ||
	wiz.away.asleep == home.after.town))
	{
	get.posn( a.wiz, wiz.x, wiz.y);

	reset( take.his.stuff);
	call( lgc.inventory.check);

	if ((current.status == fly ||
		invisibleEgo ||
		current.status == eagle ||
		spell.cast))
		{
		spell.cast = 0;
		print( 12);
		make.wiz.come = osw.saw.magic;
		}

	if (make.wiz.come)
		{
		set( force.wiz.come);
		goto exit;
		}

	if (aSecondPassed)
		{
		--temper.timer;
		if (temper.timer == 1 &&
			chore.to.do)
			{
			wiz.temper = punish;
			}
		}


	if (wiz.temper == get.outta.here)
		{
		wiz.temper = assign.chore;
		old.wiz.temper = 0;
		print( 22);
		}

	if (wiz.temper != old.wiz.temper)
	    	{
		old.wiz.temper = wiz.temper;
	
		if (wiz.temper == talked.once)
			{
			random( 13, 15, work);
			print.v( work);
			}
		
		if (wiz.temper == assign.chore)
			{
			if (chore.to.do)
				{
				print( 23);
				chore.minutes = chore.init.minutes;
				make.wiz.come = osw.punish;
				}
			else
				{
				:pick.a.chore;
				random( 1, 5, chore.to.do);
				if ((chore.to.do == previous.chore ||
					chore.to.do == fix.meal))
					{
					goto pick.a.chore;
					}

				if  (chore.to.do == clean.kitchen &&
					current.room == 6)
					{
					goto pick.a.chore;
					}

				if  (chore.to.do == empty.pot &&
					current.room == 2)
					{
					goto pick.a.chore;
					}

				if  (chore.to.do == dust.office &&
					current.room == 5)
					{
					goto pick.a.chore;
					}

				chore.minutes = chore.init.minutes;
				wiz.minutes   = chore.init.minutes;
				++wiz.minutes;		[	Now, he'll return after chore.

				work = chore.to.do;
				previous.chore = chore.to.do;
				work += 15;				[	messages 16 - 20
				print.v( work);
		
				temper.timer = temper.init.seconds;
				}
			}
	
		if (make.wiz.come)
			{
			set( force.wiz.come);
			goto exit;
			}

		if (wiz.temper == punish)
			{
			print( 21);
			make.wiz.come = osw.punish;
			}
		}


	if (make.wiz.come)
		{
		set( force.wiz.come);
		goto exit;
		}

	--bug.wiz.timer;
	if (!bug.wiz.timer)
		{
		distance( a.wiz, ego, work);

		if (work < 10)
			{
			++bugged.wiz.count;
			bug.wiz.timer = 30;
			if (bugged.wiz.count == 1)
				{
				print( 9);
				}

			if (bugged.wiz.count == 2)
				{
				print( 10);
				}

			if (bugged.wiz.count == 3)
				{
				print( 11); 
				make.wiz.come = osw.punish;
				}
			}
		}
	}


if (make.wiz.come)
	{
	set( force.wiz.come);
	goto exit;
	}



if (aSecondPassed)
	{
	if (debugging && seconds.in.room == 5 &&
		monitor.type != mono)
		{
		clear.lines( 22, 22, bg.color);	[	erase wiz.entrance.time
		}

	if  (seconds.in.room == wiz.entrance.time &&
	    (wiz.away.asleep == home.after.bed ||
		wiz.away.asleep == home.after.town))
		{
		if (!handsOff)
			{
			set( house.wiz.done);
			house.wiz.script = 0;
			}
		else
			{
			if (wiz.entrance.time < 200)
				{
				wiz.entrance.time += 8;	[	try again in a little while
				}
			}
		}

	--house.wiz.seconds;
	if (house.wiz.seconds == 1)
		{
		set( house.wiz.done);
		}
	}

if ((house.wiz.script == 1 || 
	house.wiz.script == 5))
	{
	current.cel( a.poof, work);
	if (work == 3)
		{
		set( house.wiz.done);
		}
	}

if (house.wiz.done)
	{
	reset( house.wiz.done);
	++house.wiz.script;

	if (house.wiz.script == 1)
		{
		prevent.input();
		program.control();
		stop.motion( ego);
		set( handsOff);
		wiz.status = here;
		sound( m.wiz, done);

		set.view( a.wiz, v.wiz);
		position.v( a.wiz, wiz.x, wiz.y);
		work = wiz.cycle.time;
		step.time( a.wiz, work);
		cycle.time( a.wiz, work);

		work = ego.x;
		if (work > 2)
			{
			work -= 3;			[	don't fly off left edge!
			}
	
 		if (work < wiz.x)			[	which way should he point?
			{
			set.loop( a.wiz, facing.left);
			}
		else
			{
			set.loop( a.wiz, facing.right);
			}

		set.view( a.poof, v.poof);
		set.cel( a.poof, 0);
		work = 3;
		cycle.time( a.poof, work);
		ignore.obj( a.poof);
		set.priority( a.poof, 15);
		position.v( a.poof, wiz.x, wiz.y);
		stop.motion( a.poof);
		start.cycling( a.poof);
		end.of.loop( a.poof, house.wiz.done);
		draw( a.poof);
		}

	if (house.wiz.script == 2)
		{
		set.cel( a.wiz, 0);
		stop.cycling( a.wiz);
		draw( a.wiz);
		}

	if (house.wiz.script == 3)
		{
		set( wiz.on.screen);
		accept.input();
		player.control();
		start.motion( ego);
		reset( handsOff);
		erase( a.poof);
		random( 3, 8, house.wiz.seconds);
		}

	if (house.wiz.script == 4)
		{
		random( 3, 8, house.wiz.seconds);
		if (!openingChoreAssigned)
			{
			set( openingChoreAssigned);
			wiz.temper = assign.chore;
			}
		else
			{
			if ((current.room == 1 ||
				current.room == 2 ||
				current.room == 5))
				{
				wiz.temper = get.outta.here;
				house.wiz.seconds = 0;	[	He's not leaving till we do.
				}
			else
				{
				random( 1, 3, work);
				if (work == 1)
					{
					random( 24, 25, work);
					print.v( work);
					}
				}
			}
		}

	if (house.wiz.script == 5)
		{
		prevent.input();
		program.control();
		stop.motion( ego);
		set( handsOff);
		reset( wiz.on.screen);
		get.posn( a.wiz, wiz.x, wiz.y);
		position.v( a.poof, wiz.x, wiz.y);
		set.view( a.poof, v.poof);
		set.cel( a.poof, 0);
		draw( a.poof);
		start.cycling( a.poof);
		end.of.loop( a.poof, house.wiz.done);
		sound( s.ego.poofing, done);
		}

	if (house.wiz.script == 6)
		{
		erase( a.wiz);
		}

	if (house.wiz.script == 7)
		{
		accept.input();
		player.control();
		start.motion( ego);		
		reset( handsOff);
		erase( a.poof);
		wiz.status = gone;
		house.wiz.script = 0;
		}
	}


[*****
:exit
[*****

