[logics for room 115 -- lgc.bandits.exterior

%include	"gamedefs.al"
%include	"rm115.msg"
%include	"iv-names.h"


[	Called by rooms 17, 22, 23, 27.



%define	banditStepSize		  	2


%define	theyStoleSomething		df0	[	This dynamic gets 0-7.
%define	bandit1Here			df1
%define	bandit2Here			df2
%define	soundDone				df3
%define	nextScript			df4
%define	banditsConfused		df5
%define	theyHitEgo			df6


%define	banditSeconds			dv0
%define	banditScript			dv1


%object	aBandit1				1
%object	aBandit2				2



if (init.log)
	{
	if (handsOff)
		{
		return();
		}

	if  (current.room != 17 &&
		current.room != 22 &&
		current.room != 23 &&
		current.room != 27)
		{
		return();
		}

	load.view( v.bandit.1);
	load.view( v.bandit.2);
	load.view( v.ego.stunned);
	
	load.sound( m.badguy);
	load.sound( s.ego.stunned);
		
	animate.obj( aBandit1);
	animate.obj( aBandit2);

	set.view( aBandit1, v.bandit.1);
	set.view( aBandit2, v.bandit.2);


	if  (current.room == 17)
		{
		random( 1, 2, work);
		if (work == 1)
			{
			position( aBandit1, 113, 128);
			move.obj( aBandit1,  83, 128, banditStepSize, nextScript);
			}
		else
			{
			position( aBandit1, 137, 91);
			move.obj( aBandit1, 115, 91, banditStepSize, nextScript);
			}

		random( 1, 2, work);
		if (work == 1)
			{
			position( aBandit2, 54, 166);
			move.obj( aBandit2, 64, 156, banditStepSize, nextScript);
			}
		else
			{
			position( aBandit2, 50, 61);
			move.obj( aBandit2, 62, 73, banditStepSize, nextScript);
			}
		}

	if  (current.room == 22)
		{
		random( 1, 2, work);
		if (work == 1)
			{
			position( aBandit1, 111, 112);
			move.obj( aBandit1,  94, 112, banditStepSize, nextScript);
			}
		else
			{
			position( aBandit1, 129,  68);
			move.obj( aBandit1, 114,  68, banditStepSize, nextScript);
			}

		random( 1, 2, work);
		if (work == 1)
			{
			position( aBandit2, 42, 68);
			move.obj( aBandit2, 54, 68, banditStepSize, nextScript);
			}
		else
			{
			position( aBandit2, 25, 105);
			move.obj( aBandit2, 55, 105, banditStepSize, nextScript);
			}
		}

	if  (current.room == 23)
		{
		random( 1, 2, work);
		if (work == 1)
			{
			position( aBandit1, 145, 156);
			move.obj( aBandit1, 133, 145, banditStepSize, nextScript);
			}
		else
			{
			position( aBandit1, 34, 92);
			move.obj( aBandit1, 66, 92, banditStepSize, nextScript);
			}

		random( 1, 2, work);
		if (work == 1)
			{
			position( aBandit2, 121, 97);
			move.obj( aBandit2, 100, 97, banditStepSize, nextScript);
			}
		else
			{
			position( aBandit2,  9, 123);
			move.obj( aBandit2, 48, 123, banditStepSize, nextScript);
			}
		}

	if  (current.room == 27)
		{
		random( 1, 2, work);
		if (work == 1)
			{
			position( aBandit1, 121, 139);
			move.obj( aBandit1,  97, 139, banditStepSize, nextScript);
			}
		else
			{
			position( aBandit1, 60, 166);
			move.obj( aBandit1, 75, 151, banditStepSize, nextScript);
			}

		random( 1, 2, work);
		if (work == 1)
			{
			position( aBandit2, 31, 141);
			set.loop( aBandit2, facing.right);
			move.obj( aBandit2, 53, 141, banditStepSize, nextScript);
			}
		else
			{
			position( aBandit2, 125, 68);
			move.obj( aBandit2, 108, 68, banditStepSize, nextScript);
			}
		}


	random( 5, 11, banditSeconds);

	%message	10	"Bandits in %v240."
	if (debugging && monitor.type != mono)
		{
		set.text.attribute( 4, bg.color);
		display( 22, 0, 10);
		set.text.attribute( text.color, bg.color);
		}
	return();
	}



if (!bandit1Here && !bandit2Here)
	{
	goto no.input;
	}

if (said( look, bandit))
	{
	print( 1);
	}

if (said ( talk, bandit))
	{
	print( 6);
	}

if ((said( get, bandit) ||
	said( catch, bandit)))
	{
	print( 7);
	}

if ((said( kill, bandit) ||
	said(  hit, bandit)))
	{
	print( 8);
	}



[*****
:no.input	
[*****

if  (aSecondPassed)
	{
	if (debugging && seconds.in.room == 5 &&
		monitor.type != mono)
		{
		clear.lines( 22, 22, bg.color);
		}
	
	--banditSeconds;
	if  (banditSeconds == 1)
		{
		set( nextScript);
		}
	}


if (nextScript && !banditsConfused)
	{
	reset( nextScript);
	++banditScript;

	if (banditScript == 1)
		{
		if (handsOff)
			{
			banditScript = 0;		[	Shy it on, Al.
			}
		else
			{
			set( bandit1Here);
			set( bandit2Here);
			draw( aBandit1);
			draw( aBandit2);
			sound( m.badguy, done);
			}
		}

	if (banditScript == 2)
		{
		work = banditStepSize;
		step.size( aBandit1, work);
		step.size( aBandit2, work);

		if ((invisibleEgo ||
			handsOff ||
			current.status == eagle ||
			current.status == fly))
			{
			set( banditsConfused);
			wander( aBandit1);
			wander( aBandit2);
			}
		else
			{
			follow.ego( aBandit1, 5, nextScript);
			follow.ego( aBandit2, 5, nextScript);
			print( 2);
			}
		}

	if (banditScript == 3)			[	One of them is at ego's throat!
		{
		if ((invisibleEgo ||
			handsOff ||
			current.status == eagle ||
			current.status == fly))
			{
			set( banditsConfused);
			wander( aBandit1);
			wander( aBandit2);
			}
		else
			{
			set( theyHitEgo);
			program.control();
			stop.update( aBandit1);
			stop.update( aBandit2);
		
			prevent.input();
			stop.motion( ego);
			ignore.obj( ego);
			set.view( ego, v.ego.stunned);
			set( keep.cycling);
			current.status = stunned;
			set( soundDone);
			banditSeconds = 4;
			}
		}

	if (banditScript == 4)
		{
		banditSeconds = 15;			[defensive code, in case of entrapment

		start.update( aBandit1);
		start.update( aBandit2);
		wander( aBandit1);
		wander( aBandit2);
		work = banditStepSize;
		step.size( aBandit1, work);
		step.size( aBandit2, work);


		[	STEAL HIS ENTIRE INVENTORY.

		%define	hidingRoom			view
		%define	room					loop
		%define	object				work

	    	object = 1;
	    	hidingRoom = 38;
	    	reset( theyStoleSomething);

	    	:mr.looper
	    	get.room.v( object, room)
	    	if (room == inventory)
	    		{
	    		put.f( object, hidingRoom);
	    		set( theyStoleSomething);
	    		}
	    	++object;
		if (object == dough.balls)
			{
			++object;
			}
		if (object < size.of.inventory)
			{
			goto mr.looper;
			}
		}

	if (banditScript == 5)
		{
		erase( aBandit1);
		reset( bandit1Here);
	    	erase( aBandit2);
		reset( bandit2Here);

		player.control();
		accept.input();
		reset( handsOff);
		reset( keep.cycling);
		reset( soundDone);
		release.priority( ego);
		stop.sound();
		start.motion( ego);
		observe.objs( ego);
		current.status = normal.ego;
		set.view( ego, v.ego);

		if (theyHitEgo)
			{
			reset( theyHitEgo);
			if (theyStoleSomething)
				{
				print( 3);
			    	set( ego.been.robbed);
				}
		    	else
				{
				print( 4);
				}
			}
		}
	}


if (obj.hit.edge)
	{
	if (obj.hit.edge == aBandit1)
		{
		erase( aBandit1);
		reset( bandit1Here);
		}

	if (obj.hit.edge == aBandit2)
		{
	    	erase( aBandit2);
		reset( bandit2Here);
		}

	if (!bandit1Here && !bandit2Here && !banditsConfused)
		{
		set( nextScript);
		banditScript = 4;
	    	}
	}


if (soundDone && current.status == stunned)
	{
	sound( s.ego.stunned, soundDone);
	}

if (current.status == stunned)
	{
	edge.ego.hit = 0;
	}

[*****
:exit	
[*****
