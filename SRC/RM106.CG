[logics for room 106 -- lgc.PO'd.wiz

%include	"rm106.msg"
%include	"gamedefs.al"
%include	"rm-names.h"
%include	"iv-names.h"



[	Calling protocol/requirements:  
[		1) set make.wiz.come = the reason he's mad
[		2) wiz.y must have been set by the local room logic
[		3) !handsOff 
[		4) current.ego == normal.ego
[		5) do not load unless it can be immediately called and executed.

[	Rm0, or the lgc.house.wiz, or any local room can call us.  Both this
[logic and lgc.house.wiz can be in memory together, but once called, this
[room initializes itself so Rm0 continues calling it, unknown to the local 
[room, and turns off the flag indicating the house.wiz is loaded.  "handsOff" 
[prevents local room or magic spell interaction.  This room can't use any of 
[the usual dv/df dynamic vars/flags, since we never know what other dynamics 
[are in memory with it.

[	EXCEPTIONS:
[	1. If ego's had 5 punishments, instead of getting a 6th, we kill him.
[	2. If this is ego's first time in Llewdor, wiz just issues a warning 
[ticket, then poofs him to a random wiz.house room, without punishment.



[WIZ.AWAY.ASLEEP VALUES:				[	FROM GAMEDEFS.H
[	%define	home.after.bed		1
[	%define	in.town			2
[	%define	home.after.town	3
[	%define	in.bed			4

[CHORE.TO.DO VALUES:
[	%define	clean.kitchen		1
[	%define	empty.pot			2
[	%define	fix.meal			3
[	%define	dust.office		4
[	%define	feed.chickens		5

[	MAKE.WIZ.COME/FORCE.A.WIZ VALUES:
[	these were set by Rm0, because status changed. 
[They = wiz.away.asleep, after bumping by the status change:
[	%define	wsc.from.bed		1	[	"wsc" = (wiz.status.change)
[	%define	wsc.to.town		2
[	%define	wsc.from.town		3
[	%define	wsc.to.bed		4

[	these were set by the chore.timer expiration. They = chore.to.do + 7:
[	%define	skipped.chore		8
	%define	sc.clean.kitchen	9
	%define	sc.empty.pot		10
	%define	sc.fix.meal		11
	%define	sc.dust.office		12
	%define	sc.feed.chickens	13

[	this was set by a local house.wiz getting badgere
[	%define	osw.punish		15	[	"osw" = on.screen.wizard
	%define	osw.snail			16	[	snail
	%define	osw.kitchen		17	[	kitchen
	%define	osw.fonda			18	[	fonda
	%define	osw.bedroom		19	[	and stay there!

[	this is determined by rm0:
[	%define	in.wrong.place		20
	%define	iwp.first.time		21
[	%define	osw.saw.magic		22
[	%define	magic.wand.missing	24
	%define	final.solution		25
[	%define	office.awry		26
[	%define	has.bad.inventory	27
[	%define	has.ingredients	28
[	%define	has.magic.inventory	29


[	PO'd.WIZ.SCRIPT VALUES:			LOCAL TO THIS ROOM
[	The first few are the same, but then we begin to jump around, depending
[on the status of the three pertinent flags: 
["poof.ego.out" "poof.wiz.out" "fry.ego"

%define	here's.wizzie		0	[	when we draw wiz & start his poof
%define	draw.wiz			1	[
%define	wiz.poof.done		2	[	erase( poof); set speech timer
%define	tell.reason		3	[	print statement( s); set exit flags
%define	start.wiz.pointing	4	[	if punishment due
%define	pointing.done		5	[
%define	draw.zap 			6	[	if zap due
%define	erase.zap			7	[	erase zap; 
%define	start.ego.to.dust	8	[	if deemed so necessary
%define	ego.is.dust		9	[	set.cel( wiz, 0); draw wiz poof

%define	start.ego.poof		10	[	if he's leaving
%define	erase.ego.now		11	[
%define	ego.poof.done		12	[	erase ego & poof; then new.room();
%define	start.wiz.poof		13	[	if he's leaving
%define	erase.wiz			14	[
%define	wiz.poofed.out		15	[	erase wiz & wiz.poof; certain.death
%define	we're.done		16	[	we're done



if (!PO'd.wiz.init'd)
	{
	set( PO'd.wiz.init'd);
	set( handsOff);
	program.control();
	prevent.input();
	normal.motion( ego);
	stop.motion( ego);
	set( ignore.water);
	set( ignore.special);
	ignore.block( ego);

	load.view( v.wiz.zap);			[	load the world
	load.view( v.ego.to.dust);
	load.sound( s.zap);
	load.sound( s.ego.to.dust);
	load.sound( s.ego.poofing);

	load.view( v.wiz.pointing);		[	always
	load.view( v.poof);


	animate.obj( a.poof);
	set.view( a.poof, v.poof);
	set.priority( a.poof, 15);
	set.cel( a.poof, 0);
	work = 3;
	cycle.time( a.poof, work);
	ignore.obj( a.poof);
	stop.motion( a.poof);

	room.poofing.to = 0;
	reset( poof.wiz.out);
	reset( fry.ego);
	reset( poof.ego.out);

	[	trigger the start of PO'd.wiz.script, by PO'd.wiz.done
	PO'd.wiz.script = here's.wizzie;

	if (wiz.on.screen)
		{
		reset( lgc.house.wiz.loaded);
		set.view( a.wiz, v.wiz);
		reset( poof.wiz.out);
		normal.motion( a.wiz);
		stop.motion( a.wiz);
		PO'd.wiz.script = wiz.poof.done;	[	don't erase what ain't drawn
		set( PO'd.wiz.done);			[ no poof since he's already here
		}
	else
		{
		set( poof.wiz.out);				[	he wasn't here to start with
		end.of.loop( a.poof, PO'd.wiz.done);

		load.sound( m.wiz);
		animate.obj( a.wiz);
		position.v( a.wiz, wiz.x, wiz.y);
		}
	set.view( a.wiz, v.wiz.pointing);	[	if was here or not

	work = ego.x;
	if (work > 2)
		{
		work -= 3;
		}

	x = wiz.x;
	if (work < x)					[	which way should he point?
		{
		set.loop( a.wiz, facing.left);
		x += 8;
		}
	else
		{
		set.loop( a.wiz, facing.right);
		x += 4;
		}
	position.v( a.poof, x, wiz.y);
	work = wiz.cycle.time;
	cycle.time( a.wiz, work);
	set.cel( a.wiz, 0);
	stop.cycling( a.wiz);

	if (!wiz.on.screen)
		{
		set( wiz.on.screen);
		sound( m.wiz, done);
		draw( a.poof);
		}

	}							[	end PO.wiz.init'd


[*****
:no.input
[*****

if (aSecondPassed)
	{
	--PO'd.wiz.timer;
	if (PO'd.wiz.timer == 1)
		{
		set( PO'd.wiz.done);
		}
	}


if ((PO'd.wiz.script == here's.wizzie  ||
	PO'd.wiz.script == start.wiz.poof ||
	PO'd.wiz.script == start.ego.poof))
	{
	current.cel( a.poof, work);
	if (work == 3)
		{
		set( PO'd.wiz.done);
		}
	}


if (PO'd.wiz.done)
	{
	reset( PO'd.wiz.done);
	++PO'd.wiz.script;

	if (PO'd.wiz.script == draw.wiz)		[	wiz fully visible on screen
		{
		draw( a.wiz);
		}

	if (PO'd.wiz.script == wiz.poof.done)	[	wiz fully visible on screen
		{
		erase( a.poof);			[	we can't get here if !poof.drawn
		PO'd.wiz.timer = 4;			[	from 2.05 to 3 seconds
		}

	if (PO'd.wiz.script == tell.reason)
		{

		[	First, handle the situation currently in hand.

		if ((make.wiz.come == osw.punish  ||
			make.wiz.come  > osw.punish) &&
			make.wiz.come  < in.wrong.place)
			{
			reset( fry.ego);
			reset( poof.wiz.out);
			  set( poof.ego.out);

			goto poof.or.fry;
			}


		if (make.wiz.come == osw.saw.magic)
			{
			  set( fry.ego);
			  set( poof.wiz.out);
			reset( poof.ego.out);

			goto poof.or.fry;
			}



		[	Now, find all other problems. Tell only the "most-important"
		[problem. Determine the four exit flags.
		[Alter PO'd.wiz.script as we go depending on the four flags.


		if  (!wiz.minutes &&
			!wiz.seconds)
			{
			++wiz.away.asleep;

			if (wiz.away.asleep > in.bed)
				{
				wiz.away.asleep = home.after.bed;
				wiz.minutes = wiz.home.minutes;
				}

			if (wiz.away.asleep == in.town)
				{
				wiz.minutes = wiz.town.minutes;
				}

			if (wiz.away.asleep == home.after.town)
				{
				wiz.minutes = wiz.home.minutes;
				}

			if (wiz.away.asleep == in.bed)
				{
				wiz.minutes = wiz.sleep.minutes;
				}

			make.wiz.come = wiz.away.asleep;

			reset( fry.ego);
			  set( poof.wiz.out);
			reset( poof.ego.out);
			}


		[	now see if there's any other things wrong

		if   (chore.to.do &&
			!chore.minutes &&
			!chore.seconds)
			{
			make.wiz.come = skipped.chore;
			make.wiz.come += chore.to.do;
			chore.to.do = 0;

			reset( fry.ego);
			reset( poof.wiz.out);
			  set( poof.ego.out);
			}


		if  (current.room > 8 &&	 	[	Ego left the ol' "wiz-bar-H"...
			current.room < 87)	 	[		...and in a real room.
			{
			if (current.room > 10 &&	[	no freebies in lab
				map.area != map.ship &&
			    !caught.in.Llewdor)	[Gwyd, baby, this first time's on me!
				{
				set( caught.in.Llewdor);
				current.status = poofing;
				room.poofing.to = rm.dining;
				make.wiz.come = iwp.first.time; [ "get on home this time!"

				reset( fry.ego);
				reset( poof.wiz.out);
				  set( poof.ego.out);
				}
			else
				{
				if ((map.area == map.ship ||
					punishment.count > 4))	[	pre-inc'd value
					{
					make.wiz.come = final.solution;

					  set( fry.ego);
					  set( poof.wiz.out);
					reset( poof.ego.out);
					}
				else
					{
					make.wiz.come = in.wrong.place;

					reset( fry.ego);
					reset( poof.wiz.out);
					  set( poof.ego.out);
					}
				}
			}


		set( take.his.stuff);
		call( lgc.inventory.check);
		if (make.wiz.come > office.awry)	[greater than 26 catches 27-29
			{
			  set( fry.ego);
			  set( poof.wiz.out);
			reset( poof.ego.out);
			}



		if (office.status)
			{
			make.wiz.come = office.awry;
			  set( fry.ego);
			  set( poof.wiz.out);
			reset( poof.ego.out);
			}

		work = rm.wiz.office;
		if (!obj.in.room( i.magic.wand, work))
			{
			make.wiz.come = magic.wand.missing;
			  set( fry.ego);
			  set( poof.wiz.out);
			reset( poof.ego.out);
			}


		:poof.or.fry

		if ((poof.ego.out || fry.ego))
			{
			PO'd.wiz.script = start.wiz.pointing;
			}
		else
			{
			PO'd.wiz.script = start.wiz.poof;
			}


		[	Now, print only the worst news!

		if ((make.wiz.come  < osw.punish ||	[ Punishments handled below.
			make.wiz.come  > in.wrong.place ||
			make.wiz.come == in.wrong.place))
			{
			print.v( make.wiz.come);
			}


		if  (make.wiz.come == wiz.away.asleep &&
			wiz.away.asleep == home.after.town)
			{
			chore.to.do = fix.meal;
			chore.minutes = chore.init.minutes;
			}

		if  (make.wiz.come == wiz.away.asleep &&
			made.spell.5 &&
			wiz.away.asleep == home.after.bed)
			{
			chore.to.do = fix.meal;
			chore.minutes = chore.init.minutes;
			print( 23);			[	"I'm starving. Feed me COOKIE!
			}
		}


	if (PO'd.wiz.script == start.wiz.pointing)
		{
		start.cycling( a.wiz);
		end.of.loop( a.wiz, PO'd.wiz.done);

		if (poof.ego.out)
			{
			++punishment.count;
			if (punishment.count > 5)
				{
				make.wiz.come = final.solution;
				print.v( make.wiz.come);

				  set( fry.ego);
				  set( poof.wiz.out);
				reset( poof.ego.out);
				}
			}
		}


	if (PO'd.wiz.script == pointing.done)
		{
		if (poof.ego.out)
			{
			PO'd.wiz.script = start.ego.poof;
			}
		else
			{
			PO'd.wiz.script = draw.zap;
			}
		}


	if (PO'd.wiz.script == draw.zap)
		{
		set.view( a.poof, v.wiz.zap);
		x = ego.x;
		x -= 8;
		y = ego.y;
		y -= 9;
		position.v( a.poof, x, y);
		draw( a.poof);
		stop.cycling( a.poof);

		set.cel( a.poof, 0);
		sound( s.zap, done);
		shake.screen( 1);

		set.cel( a.poof, 1);
		force.update( a.poof);
		sound( s.zap, done);
		shake.screen( 1);

		set.cel( a.poof, 0);
		force.update( a.poof);
		sound( s.zap, done);
		shake.screen( 1);

		set.cel( a.poof, 1);
		force.update( a.poof);
		sound( s.zap, done);
		shake.screen( 1);

		start.cycling( a.poof);
		sound( s.zap, done);
		PO'd.wiz.timer = 2;
		}


	if (PO'd.wiz.script == erase.zap)		[	timer done, so erase zap.  
		{
		erase( a.poof);				[	really the ZAP
		PO'd.wiz.script = start.ego.to.dust;
		}


	if (PO'd.wiz.script == start.ego.to.dust)
		{
		set.view( ego, v.ego.to.dust);
		stop.motion( ego);
		set.cel( ego, 0);
		set( keep.cycling);
		work = 2;
		cycle.time( ego, work);
		end.of.loop( ego, PO'd.wiz.done);
		sound( s.ego.to.dust, done);
		}


	if (PO'd.wiz.script == ego.is.dust)
		{
		PO'd.wiz.script = start.wiz.poof;
		reset( keep.cycling);
		stop.cycling( ego);
		stop.motion( ego);
		set( poof.wiz.out);
		}




    	if (PO'd.wiz.script == start.ego.poof)		[	DoEgoPoof
		{
		x = ego.x;
		if (x > 3)
			{
			x -= 4;
			}
		position.v( a.poof, x, ego.y);
		set.view( a.poof, v.poof);
		set.cel( a.poof, 0);
		draw( a.poof);
		end.of.loop( a.poof, PO'd.wiz.done);
		sound( s.ego.poofing, done);
		}


    	if (PO'd.wiz.script == erase.ego.now)
		{
		erase( ego);
		set( erase.ego);
		}


	if (PO'd.wiz.script == ego.poof.done)
		{
		erase( a.poof);

		if (make.wiz.come == iwp.first.time)
			{
			room.poofing.to = rm.dining;
			PO'd.wiz.script = we're.done;
			load.view( v.ego);
			set.view( ego, v.ego);
			}
		else
			{
			punish.minutes = punish.init.minutes;

			if  (make.wiz.come > osw.punish &&
				make.wiz.come < in.wrong.place)
				{
				work = make.wiz.come;
				}
			else
				{
				:pick.a.room
				random( 16, 19, work); 	[	poofy messages are # 16-19
				}

			if (work == 16)
				{
				current.status = snail;
				room.poofing.to = rm.hallway;
				}

			if (work == 17)
				{
				current.status = hanging.in.kitchen;
				room.poofing.to = rm.kitchen;
				}
			
			if (work == 18)
				{
				current.status = doing.aerobics;
				room.poofing.to = rm.entry;
				}
			
			if (work == 19)
				{
				current.status = locked.in.bedroom;
				room.poofing.to = rm.ego.bedroom;
				}
			
			if (room.poofing.to == current.room)
				{
				goto pick.a.room;
				}

			print.v( work);
			PO'd.wiz.script = we're.done;
			}
		}


	if (PO'd.wiz.script == start.wiz.poof)
		{
		if (!poof.wiz.out)
			{
			PO'd.wiz.script = we're.done;
			}
		else
			{
			get.posn( a.wiz, wiz.x, wiz.y);
			current.loop( a.wiz, work);
			work = wiz.x;
			if (work == facing.left)
				{
				work += 8;
				}
			else
				{
				work += 4;
				}
			position.v( a.poof, work, wiz.y);

			set.view( a.poof, v.poof);
			set.cel( a.poof, 0);
			draw( a.poof);
			end.of.loop( a.poof, PO'd.wiz.done);
			sound( s.ego.poofing, done);
			}
		}


	if (PO'd.wiz.script == erase.wiz)
		{
		erase( a.wiz);
		}


	if (PO'd.wiz.script == wiz.poofed.out)
		{
		reset( wiz.on.screen);
		erase( a.poof);
		PO'd.wiz.script = we're.done;
		}


	if (PO'd.wiz.script == we're.done)
		{

		[	Clean up and return everything to normal, cause ego's staying
		[here, (and perhaps the wiz is staying too).

		make.wiz.come = 0;
		PO'd.wiz.script = 0;
		reset( PO'd.wiz.init'd);
		if (poof.ego.out)
			{
			current.room = lgc.PO'd.wiz;
			new.room.v( room.poofing.to);
			}

		if (fry.ego)
			{
			stop.motion( ego);
			stop.cycling( ego);
			set( certain.death);
			}

		if (!certain.death)
			{
			reset( handsOff);
			player.control();
			accept.input();
			start.motion( ego);
			reset( ignore.water);
			reset( ignore.special);
			observe.block( ego);
			}
		}
	}


[*****
:exit
[*****

