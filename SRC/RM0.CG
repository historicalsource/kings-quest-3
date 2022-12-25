[logics for room 0 -- executed before room logics
[	March 14, 1988

%include	"rm0.msg"
%include	"defines.al"
%include	"gamedefs.h"
%include	"iv-names.h"
%include	"iv-views.h"
%include	"contrlrs.h"



%view	v.ego				  0
%view	v.ego.collapsing		 23
%view	v.ego.fly				 25
%view	v.ego.eagle			 26
%view	v.ego.footprints		 28
%view	v.gag.dead.ego.2		 39
%view	v.poof				199
%view	v.cat.wagging.tail		204



if (error.number)
	{
	call( lgc.error);
	}

if (restore.in.progress)
	{
	set( enable.menu);
	disable.item( c.dummy);
	}

if (!current.room)	
	{
[		set( debugging);
	if (!restart.in.progress)
		{
		script.size( 127);

		set.menu( 	121);					[	"Sierra
		set.menu.item( 122, c.about)				[	"About BC
		set.menu.item( 123, c.help)				[	"Help

		set.menu(  	124);					[	"File
		set.menu.item( 125, c.save)				[	"Save"
		set.menu.item( 126, c.restore)			[	"Restore"
		set.menu.item( 127, c.dummy);				[	"--------
		set.menu.item( 128, c.restart)			[	"Restart"
		set.menu.item( 127, c.dummy);				[	"--------
		set.menu.item( 129, c.quit)				[	"Quit"
										
		set.menu(  	130);					[	"Action
		set.menu.item( 131, c.status);			[	"Inventory"
		set.menu.item( 132, c.show.obj)			[	"Look at object
										
		set.menu(  	133);					[	"Game
		set.menu.item( 134, c.sound.toggle);		[	"Sound"
		if  (machine.type == PC &&
			monitor.type != mono &&
			monitor.type != ega)
			{
			set.menu.item( 135, c.toggle.monitor); 	[	"RGB Monitor
			}
		if (machine.type == ST)
			{
			set.menu.item( 111, c.init.joy);		[	"Joystick/Mouse"
			}
		else
			{
			set.menu.item( 136, c.init.joy);		[	"Joystick"
			}
		set.menu.item( 137, c.clock)				[	"Clock
		set.menu.item( 138, c.pause)				[	"Pause"

		if (machine.type != AMIGA)
			{
			set.menu(      139);				[	"Speed
			set.menu.item( 140, c.speed.normal); 	[	"Normal
			set.menu.item( 141, c.speed.slow);		[	"Slow
			set.menu.item( 142, c.speed.fast);		[	"Fast
			set.menu.item( 143, c.speed.fastest);	[	"Fastest
			set.menu.item( 127, c.dummy);			[	"--------
			set.menu.item( 144, c.speed)			[	"Speed
			}
	
[			if (debugging)
[				{
[				set.menu(  	145);				[	"Debug
[				set.menu.item( 146, c.show.ego); 		[	"Ego Information
[				set.menu.item( 147, c.show.priority); 	[	"Priority Screen
[				set.menu.item( 148, c.show.mem);		[	"Memory Usage
[				set.menu.item( 149, c.obj.info);		[	"Obj info
[				set.menu.item( 150, c.xy); 			[	"X/Y Display
[				set.menu.item( 151, c.inv.numbers);	[	"inventory Numbers
[				set.menu.item( 152, c.gimme);			[	"Get All Objs.
[				}

		submit.menu( );
		}

	call( lgc.startup);

	if (test.room)
		{
		new.room.v( test.room);
		}

	if (restart.in.progress)
		{
		new.room( 7);
		}

	new.room( 45);
	}



if  (clock.on &&
    (update.clock || init.log))
	{
	reset( update.clock);
	set.text.attribute( 0, 15);
	display(  0, 20, 30);
	set.text.attribute( text.color, bg.color);
	}


	
if (init.log)
	{
	call( 100);					[	call and toss init.log resets

	if (debugging)
		{
		load.logics( lgc.debug);
		load.logics( lgc.trace);
		set( enable.trace);
		}

	call.v( current.room);

	if (current.status == deferred.entry)
		{
		current.status = normal.ego;	[	local room "couldn't bother"
		}

	if (!positionEgo && !drawEgo && 
		current.status != eagle &&
		current.status != fly)
		{
		position.v( ego, landing.x, landing.y);
		}

	if (current.status == poofing)
		{
		current.status = normal.ego;
		start.a.poof = poof.in;
		load.view( v.ego);
		set.view( ego, v.ego);
		set( drawEgo);
		}

	if (!drawEgo)
		{
		draw( ego);				[	interesting, no?
		}

	[	DO NOT return(); here. Start.a.poof (and others) need the init pass.

	}							[	end init.logs



[*****
[	FIRST, A LITTLE HOUSEKEEPING
[*****

get.posn( ego, ego.x, ego.y);
reset( doit);

if (ignore.special)
	{
	reset( hit.special);
	}

if (ignore.water)
	{
	reset( on.water);
	}

if (prevent.new.room)
	{
	edge.ego.hit = 0;
	}

[*****
[	CONTROLLER STUFF
[*****

if (controller( c.menu))				{menu.input( );}
if (controller( c.doit))				{set( doit);}
if (controller( c.test))				{set( doit);}
if (controller( c.pause))			{pause( );}
if (controller( c.echo.line))			{echo.line( );}
if (controller( c.cancel.line))		{cancel.line( );}
if (controller( c.init.joy))			{init.joy( );}

if (machine.type == TANDY)
	{
	if (attenuation < 15 &&
	    controller( c.decrescendo))		{++attenuation;}
	if (controller( c.crescendo))			{--attenuation;}
	}

if ((said( restart, game) || 
	said( restart) || 
	said( start, over) ||
	controller( c.restart)))
	{
	restart.game();
	}

if ((said( restore, game) ||
	said( restore) || 
	controller( c.restore)))	
	{
	restore.game();
	}

if ((controller( c.quit) ||
	said( quit)))
	{
	if (debugging)
		{
		quit( 1);
		}
	else
		{
		quit( 0);
		}
	}

if (controller( c.about))			[	also give length of game play.
	{
	if (gameDays)
		{
		print( 87);
		}
	else
		{
		if (gameHours)
			{
			print( 88);
			}
		else
			{
			print( 89);
			}
		}
	}

if (controller( c.clock))
	{
	toggle( clock.on);
	if (clock.on)
		{
		set( update.clock);
		}
	else
		{
		status.line.off( );
		status.line.on( );
		}
	}


if  (current.status != dead &&
    (said( save, game) || 
	said( save) || 
	controller( c.save)))
	{
	save.game( );
	}


if (controller( c.show.obj))
	{
	set( enable.obj.select);
	status( );
	set( update.clock);
	if  (selected.object &&
		selected.object != error)
		{
		if (selected.object == i.magic.map)
			{
			spell.cast = sc.map;
			}
		else
			{
			work = selected.object;
			work += 100;
			show.obj.v( work);
			}
		reset( enable.obj.select);
		}
	}

if (controller( c.sound.toggle))
	{
	toggle( sound.on);
	set( update.clock);
	}

if ((said( show, status) || 
	said( status) || 
	said( inventory) || 
	controller( c.status)))
	{
	status();
	set( update.clock);
	}

if ((controller( c.debug) ||
	said( rat, shit)))
	{
	toggle( debugging);
	if (!debugging)
		{
		reset( enable.trace);
		}
	else
		{
		load.logics( lgc.debug);
		load.logics( lgc.trace);
		set( enable.trace);
		set( xy.on);
		print( 11);
		version();
		accept.input();
		player.control();
		}
	}

if (controller( c.version))
	{
	print( 11);
	version();
	}

if ((controller( c.help) ||
	said( help) ||
	said( help, me)))
	{
	if (out.of.memory)
		{
		print( 12);
		}
	else
		{
		call( lgc.help);
		}
	}

if (controller( c.toggle.monitor))
	{
	toggle.monitor();
	}


reset( my.have.match);				[	speed stuff
if (controller( c.speed))
	{
	set( my.have.match);
	++animation.interval;
	if (animation.interval > slow)
		{
		animation.interval = fastest;
		}
	}

if ((controller( c.speed.slow) ||
	said( slow)))
	{
	set( my.have.match);
	animation.interval = slow;
	}

if ((controller( c.speed.normal) ||
	said( normal)))
	{
	set( my.have.match);
	animation.interval = normal;
	}

if ((controller( c.speed.fast) ||
	said( fast)))
	{
	set( my.have.match);
	animation.interval = fast;
	}

if ((controller( c.speed.fastest) ||
	said( fastest)))
	{
	set( my.have.match);
	animation.interval = fastest;
	}

if (my.have.match)
	{
	reset( my.have.match);
	if (monitor.type != mono)
		{
		work = 114;
		work += animation.interval;
		clear.lines( 24, 24, bg.color);
		y = 24;
		x = 0;
		display.v( y, x, work);
		clear.status.seconds = 6;
		}
	}



[*****
[	DEAD EGO
[*****

if (certain.death)
	{
	reset( certain.death);
	disable.item( c.save);
	current.status = dead;
	load.sound( m.whoops);
	stop.motion( ego);
	accept.input();
	wait.1 = cycles.before.death;
	}

if (current.status == dead)
	{
	--wait.1;
	if (wait.1 == 1)
		{
		stop.sound();
		sound( m.whoops, done);
		print( 13);
		}

	if (have.input && !have.match)
		{
		print( 14);
		}

	if (debugging)
		{
		call( lgc.debug);
		}
	return();
 	}


[*****
[	EGO CYCLING
[*****

if  (ego.dir == old.ego.dir &&
	ego.x == old.ego.x &&
	ego.y == old.ego.y)
	{
	stop.cycling( ego);
	}
else	
	{
	start.cycling( ego);
	}

if ((!ego.dir || no.cycling))
	{
	stop.cycling( ego);
	}

if (keep.cycling)
	{
	start.cycling( ego);
	}


[*****
[	TIMERS
[*****

if (elapsed.seconds != old.seconds)
	{
	old.seconds = elapsed.seconds;
	set( aSecondPassed);	[Inform other logics that one second has passed.
	set( update.clock);

	++seconds.in.room;
	--wiz.seconds;
	--chore.seconds;
	--punish.seconds;
	--magic.seconds;
	--burner.seconds;
	--voyage.seconds;
	--storm.seconds;
	--clear.status.seconds;


	if (current.room != 74)
		{
		++gameSeconds;
		}
	if (gameSeconds == 60)
		{
		gameSeconds = 0;
		++gameMinutes;
		if (gameMinutes == 60)
			{
			gameMinutes = 0;
			++gameHours;
			if (gameHours == 25)
				{
				gameHours = 0;
				++gameDays;
				}
			}
		}


	if (clear.status.seconds == 1)	[	Can't get here if MONO monitor.
		{
		clear.lines( 24, 24, bg.color);
		}


	if (wiz.minutes && !wiz.seconds)
		{
		--wiz.minutes;
		wiz.seconds = 60;
		}
	
	
	if (chore.minutes && !chore.seconds)
		{
		--chore.minutes;
		chore.seconds = 60;
		}
	

	if (punish.minutes && !punish.seconds)
		{
		--punish.minutes;
		punish.seconds = 60;
		}

	if (punish.seconds == 1 && !punish.minutes)
		{
		if (current.status != snail)
			{
			set( punishment.done);
			}
		else
			{
			reset( handsOff);
			current.status = normal.ego;
			start.a.poof = poof.change;
			poof.change.view = current.status;
			}
		}
	

	if (magic.minutes && !magic.seconds)
		{
		--magic.minutes;
		magic.seconds = 60;
		}
	
	if (magic.seconds == 1 && !magic.minutes)
		{
		set( magic.done);
		if ((current.status == eagle ||
			current.status == fly))
			{
			spell.cast = sc.stop.flying;
			}

		if (invisibleEgo)
			{
			spell.cast = sc.visible;
			}

		if  (current.status != eagle.landing &&
			current.status != fly.landing)
			{
			print( 20);
			set( prevent.new.room);
			}
		}
	
	
	if (burner.minutes && !burner.seconds)
		{
		--burner.minutes;
		burner.seconds = 60;
		}
	
	
	if (voyage.minutes && !voyage.seconds)
		{
		--voyage.minutes;
		voyage.seconds = 60;
		}
	
	if (voyage.seconds == 1 && !voyage.minutes)
		{
		++shipShape;
		if (shipShape == underWay)
			{
			voyage.minutes = underWay.init.minutes;
			}

		if (shipShape == nearLand)
			{
			set( landHo);
			voyage.minutes = nearLand.init.minutes;
			}

		if (shipShape == atBeach)
			{
			set( landHo);
			voyage.minutes = atBeach.init.minutes;
			}
		}


	if (storm.minutes && !storm.seconds)
		{
		--storm.minutes;
		storm.seconds = 60;
		}
	
	if (storm.seconds == 1 && !storm.minutes)
		{
		spell.cast = sc.stop.storm;
		}

	}							[	end of "aSecondPassed"


[*****
[	HANDLE PRELIMINARY INPUT
[*****

if (!have.input)
	{
	goto no.input;
	}

if (unknown.word)
	{
	reset( have.input);
	set( have.match);
	print.v( unknown.word);			[	prints messages #1 - 9
	}


if (said( who, wrote, game))
	{
	print( 16);
	}

if (said( thanks, rol))
	{
	print( 28);
	}

if ((said( bye, anyword) ||
	said( anyword, bye)))
	{
	print( 113);
	}

if (said( hi, rol))
	{
	print( 26);
	}

if ((said( dirty$word, rol) ||
	said( anyword, dirty$word, rol) ||
	said( anyword, anyword, dirty$word, rol) ||
	said( anyword, anyword, anyword, dirty$word, rol)))
	{
	print( 29);
	}
	
if ((said( how, long, game) ||	
	said( how, long, playing, game) ||	
	said( how, long, playing) ||
	said( length, game) ||
	said( game, length) ||
	said( game, time)))
	{
	if (elapsed.days)
		{
		print( 17);
		}
	else
		{
		if (elapsed.hours)
			{
			print( 18);
			}
		else
			{
			print( 19);
			}
		}
	}

if ((said( anyword, clock, rol) ||
	said( clock, rol)))
	{
	toggle( clock.on);
	if (clock.on)
		{
		set( update.clock);
		}
	else
		{
		status.line.off();
		status.line.on();
		}
	}



[*****
[	MAGIC SPELLS	[	NOTE:  Much of this next block is sequence dependent.
[*****

if (has( i.cat.cookie))
	{
	if ((said( give, cat, cookie, rol) ||
		said( give, cookie, rol)))
		{
		print( 70);
		}

	if  (has( i.porridge) &&
	    (said( put, cat, cookie, porridge) ||
	     said( put, cookie, porridge) ||
		said( put, cat, cookie, bowl, porridge) ||
		said( put, cookie, bowl, porridge) ||
		said( crumble, cat, cookie, porridge) ||
		said( crumble, cookie, porridge) ||
		said( crumble, cat, cookie, bowl, porridge) ||
		said( crumble, cookie, bowl, porridge)))
		{
		drop( i.cat.cookie);
		drop( i.porridge);
		get( i.porridge.poisoned);
		print( 35);
		}
	}



if (current.status == snail)
	{
	print( 15);
	set( have.match);
	}



if (spell.cast == sc.make.sleep && 
	said( slumber, henceforth))
	{
	spell.cast = sc.start.sleep;
	}
if (spell.cast == sc.make.sleep)
	{
	spell.cast = 0;
	}
if (said( pour, sleep, powder, on, ground))
	{
	if (has( i.sleep.powder))
	    	{
		spell.cast = sc.make.sleep;
		print( 9);
		drop( i.sleep.powder);
		}
	else
		{
		print( 45);
		}
	}



if ((said( rub, magic, stone) ||
	said( rub, stone) ||
	said( rub, amber, stone)))
	{
	if (has( i.magic.stone))
		{
		spell.cast = sc.poof;
		}
	else
		{
		print( 45);
		}
	}



if (current.status == eagle)
	{
	if (said( eagle, begone, myself, return))
		{
		spell.cast = sc.stop.flying;
		}
	else
		{
		print( 32);
    		set( have.match);
		}
	}
if ((said( dip, eagle, feather, essence) || 
	said( dip, eagle, feather, magic, essence)))
	{
	if  (has( i.magic.essence) && 
		has( i.eagle.feather))
		{
		spell.cast = sc.eagle;
		}
	else
		{
	    	print( 45);
		}
	}



if (current.status == fly)
	{
	if (said( fly, begone, myself, return))
		{
		spell.cast = sc.stop.flying;
		}
	else
		{
		print( 33);
		set( have.match);
		}
	}
if ((said( dip, fly, essence) || said( dip, fly, magic, essence)))
	{
	if  (has( i.magic.essence) && 
		has( i.fly.wings))
		{
		spell.cast = sc.fly;
		}
	else
	    	{
		print( 45);
		}
	}



if ((said( look, magic, map) ||
     said( look, map)))
	{
	if (has( i.magic.map))
		{
		spell.cast = sc.map;
		}
	else
		{
		print( 45);
		}
	}



if  (invisibleEgo &&
    (said( wipe, ointment, off) ||
	said( wipe, off, ointment)))
	{
	spell.cast = sc.visible;
	}
if ((said( rub, ointment, on, me) ||
	said( rub, ointment, on) ||
	said( rub, on, ointment) ||
	said( rub, ointment, on, body)))
	{
	if (has( i.invisible.ointment))
		{
		spell.cast = sc.invisible;
		}
	else
		{
		print( 45);
		}
	}




[	Next block is sequence dependent:
if (spell.cast == sc.make.storm && 
	said( brew, storms, churn, up))
	{
	spell.cast = sc.start.storm;
	}
if (spell.cast == sc.make.storm)
	{
	spell.cast = 0;
	}
if (said( stir, brew, with, finger))
	{
	if (has( i.storm.brew))
		{
		spell.cast = sc.make.storm;
		print( 9);
		}
	else
		{
		print( 45);
		}
	}
if ((storm.minutes || storm.seconds) &&
	said( brew, storms, clear, up))
	{
	spell.cast = sc.stop.storm;
	}



[*****
[	STUPID EGO DEATHS
[*****

if  (has( i.nightshade.juice) && 
    (said( drink, juice) ||
	said( drink, nightshade, juice) ||
	said( drink, nightshade) ||
	said( drink, juice, jar) ||
	said( drink, nightshade, juice, jar) ||
	said( drink, juice, from, jar) ||
	said( drink, nightshade, juice, from, jar)))
	{
	drop( i.nightshade.juice);
	death.message = 36;
	}

if  (has( i.mandrake.root) && 
    (said( eat, mandrake, powder) || said( eat, mandrake, root, powder) || 
	said( eat, root) || said( eat, mandrake, powder, from, jar) ||
	said( eat, mandrake) || said( eat, mandrake, root) || 
	said( eat, mandrake, root, powder, from, jar)))
	{
	drop( i.mandrake.root);
	death.message = 38;
	}

if  (has( i.toadstool.powder) && 
    (said( eat, toadstool) || said( eat, toadstool, powder) || 
	said( eat, toadstool, powder, from, jar)))
	{
	drop( i.toadstool.powder);
	death.message = 39;
	}

if  (has( i.porridge.poisoned) && has( i.spoon) &&
    (said( eat, porridge, with, spoon) ||
	said( eat, porridge, spoon) ||
	said( use, spoon, eat, porridge)))	[	fix so turn in to cat
	{
	drop( i.porridge.poisoned);
	death.message = 37;
	}

if (has( i.porridge.poisoned) && 
    said( eat, porridge))
	{
	drop( i.porridge.poisoned);
	death.message = 37;
	}

if  (has( i.cat.cookie) && 
    (said( eat, cat, cookie) || said( eat, cookie)))
	{
	set( handsOff);
	print( 9);
	start.a.poof = poof.change;
	current.status = ate.cat.cookie;
	poof.change.view = ate.cat.cookie;
	}



[*****
[	HANDLE "SHOWING" THINGS
[*****

if ((has( i.chicken.feather) || has( i.eagle.feather)) && said( show, feather))
	{
	if (has( i.chicken.feather))
		{
		show.obj( iv.chicken.feather);
		}

	if (has( i.eagle.feather))
		{
		show.obj( iv.eagle.feather);
		}
	}


if (has( i.chicken.feather) && said( show, chicken, feather))
	{
	show.obj( iv.chicken.feather);
	}

if ((has( i.dog.hair) || has( i.cat.hair)) && said( show, hair))
	{
	if (has( i.cat.hair))
		{
		show.obj( iv.cat.hair);
		}

	if (has( i.dog.hair))
		{
		show.obj( iv.dog.hair);
		}
	 }

if (has( i.cat.hair) && said( show, cat, hair))	
	{
	show.obj( iv.cat.hair);
	}

if (has( i.dog.hair) && said( show, dog, hair))	
	{
	show.obj( iv.dog.hair);
	}

if (has( i.snakeskin) && said( show, skin))
	{
	show.obj( iv.snakeskin);
	}

if (has( i.fish.bone) &&	said( show, bone))	
	{
	show.obj( iv.fish.bone);
	}

if (has( i.thimble) && said( show, thimble))	
	{
	show.obj( iv.thimble);
	}

if  (has( i.dew) && 
    (said( show, dew) || said( show, dew, thimble) || 
	said( show, thimble, dew) || said( show, thimble)))
	{
	show.obj( iv.dew);
	}

if (has( i.dough.balls) && said( show, dough, balls))
	{
	show.obj( iv.dough.balls);
	}

if (has( i.eagle.feather) && said( show, eagle, feather))
	{
	show.obj( iv.eagle.feather);
	}

if (has( i.fly.wings) && said( show, fly))
	{
	show.obj( iv.fly.wings);
	}

if (has( i.saffron) && said( show, saffron))
	{
	show.obj( iv.saffron);
	}

if (has( i.rose.essence) && said( show, essence))
	{
	show.obj( iv.rose.essence);
	}

if (has( i.magic.essence) && 
    (said( show, essence) || said( show, magic, essence)))
	{
	show.obj( iv.magic.essence);
	}

if (has( i.salt) && said( show, salt))		
	{
	show.obj( iv.salt);
	}

if (has( i.amber.stone) && said( show, amber, stone))
	{
	show.obj( iv.amber.stone);
	}
	
if  (has( i.magic.stone) && 
    (said( show, magic, stone) || 
	said( show, amber, stone)))
	{
	show.obj( iv.magic.stone);
	}

if (has( i.mistletoe) && said( show, mistletoe))	
	{
	show.obj( iv.mistletoe);
	}

if (has( i.nightshade.juice) && 
	(said( show, nightshade, juice) || said( show, juice)))
	{
	show.obj( iv.nightshade.juice);
	}

if (has( i.acorns) &&
	said( show, acorns))
	{
	show.obj( iv.acorns);
	}

if (has( i.mandrake.root) && (said( show, mandrake, root) || 
	said( show, mandrake, root, powder) || said( show, mandrake)))
	{
	show.obj( iv.mandrake.root);
	}

if (has( i.fish.oil) && (said( show, fish, oil) ||said( show, oil)))	
	{
	show.obj( iv.fish.oil);
	}

if (has( i.cat.cookie) && (said( show, cookie) || said( show, cat, cookie)))
	{
	show.obj( iv.cat.cookie);
	}

if (has( i.porridge) && said( show, porridge))
	{
	show.obj( iv.porridge);
	}

if (has( i.porridge.poisoned) && said( show, porridge))
	{
	show.obj( iv.porridge.poisoned);
	}

if (has( i.porridge.poisoned) && said( show, poison, porridge))
	{
	show.obj( iv.porridge.poisoned);
	}

if  (has( i.ocean.water) && 
    (said( show, cup) ||
	said( show, water) || 
	said( show, cup, water) || 
	said( show, cup, ocean, water) || 
	said( show, ocean, water)))
	{
	show.obj( iv.ocean.water);
	}

if  (has( i.mud) && 
    (said( show, mud) || said( show, spoon, mud) || said( show, spoon)))
	{
	show.obj( iv.mud);
	}

if (has( i.toadstool.powder) &&
	(said( show, toad, powder) || said( show, toadstool, powder)))
	{
	show.obj( iv.toadstool.powder);
	}

if (has( i.fish.jar) && (said( show, jar) || said( show, empty$jar)))
	{
	show.obj( iv.fish.jar);
	}

if (has( i.storm.brew) && said( show, brew))
	{
	show.obj( iv.storm.brew);
	}

if (has( i.toad.spit) && (said( show, toad, spit) || said( show, spit)))
	{
	show.obj( iv.toad.spit);
	}

if (has( i.lard) && said( show, lard))		
	{
	show.obj( iv.lard);
	}

if (has( i.knife) && said( show, knife))		
	{
	show.obj( iv.knife);
	}

if (has( i.cactus) && said( show, cactus))		
	{
	show.obj( iv.cactus);
	}

if (has( i.invisible.ointment) && said( show, ointment))
	{
	show.obj( iv.invisible.ointment);
	}

if (has( i.magic.wand) && (said( show, wand) || said( show, magic, wand)))
	{
	show.obj( iv.magic.wand);
	}

if (has( i.key) && said( show, key))			
	{
	show.obj( iv.key);
	}

if (has( i.bowl) && said( show, bowl))		
	{
	show.obj( iv.bowl);
	}

if (has( i.spoon) && said( show, spoon))		
	{
	show.obj( iv.spoon);
	}

if (has( i.mirror) && (said( show, mirror) || said( show, hand, mirror)))
	{
	show.obj( iv.mirror);
	}

if  (has( i.purse.with.coins) &&
    (said( show, purse, rol) || said( open, purse, rol) ||
	said( look$in, purse) || said( show, coins, rol)))
	{
	show.obj( iv.purse.with.coins);
	}

if  (has( i.purse.empty) &&
    (said( show, purse, rol) || said( open, purse, rol) || 
	said( look$in, purse) || said( show, empty, purse, rol)))
	{
	show.obj( iv.purse.empty);
	}

if  (has( i.empty.pouch) && 
    (said( show, empty, pouch) || said( show, pouch)))
	{
	show.obj( iv.empty.pouch);
	}


if  (has( i.sleep.powder) &&
    (said( show, powder) || said( show, pouch) ||
	said( show, bag) || said( show, sleep, powder)))
	{
	show.obj( iv.sleep.powder);
	}

if (has( i.bread) && said( show, bread))		
	{
	show.obj( iv.bread);
	}

if (has( i.fruit) && said( show, fruit))		
	{
	show.obj( iv.fruit);
	}

if (has( i.mutton) && said( show, meat))
	{
	show.obj( iv.mutton);
	}

if (has( i.shovel) && said( show, shovel))		
	{
	show.obj( iv.shovel);
	}

if (has( i.treasure.chest) &&
    (said( show, chest) || said( show, treasure) ||
	said( open, chest) || said( open, treasure) ||
	said( open, lid, chest) || said( open, lid, treasure)))
	{
	show.obj( iv.treasure.chest);
	}

if (said( show, food))
	{
	if (has( i.bread))
		{
		show.obj( iv.bread);
		reset( have.match);
		}

	if (has( i.fruit))
		{
		show.obj( iv.fruit);
		reset( have.match);
		}

	if (has( i.porridge))
		{
		show.obj( iv.porridge);
		reset( have.match);
		}

	if (has( i.porridge.poisoned))
		{
		show.obj( iv.porridge.poisoned);
		reset( have.match);
		}

	if (has( i.mutton))
		{
		show.obj( iv.mutton);
		reset( have.match);
		}

	if (have.match)
		{
		print( 66);
		}
	}

if ((has( i.ocean.water) || has( i.cup)) && said( show, cup))			
	{
	if (has( i.ocean.water))
		{
		show.obj( iv.ocean.water);
		}

	if (has( i.cup))
		{
		show.obj( iv.cup);
		}
	}



[*****
:no.input
[*****

if (death.message && !handsOff)
	{
	set( handsOff);
	program.control();
	stop.motion( ego);
	prevent.input();
	load.view( v.ego.collapsing);
	set.view( ego, v.ego.collapsing);
	set.cel( ego, 0);
	work = 3;
	cycle.time( ego, work);
	set( keep.cycling);
	end.of.loop( ego, ego.death.done);
	}

if (ego.death.done)
	{
	reset( ego.death.done);
	stop.cycling( ego);
	print.v( death.message);			[	%m36 through 39
	set( certain.death);
	}


if (demo && have.key())
	{
	gameDays = 0;
	gameHours = 0;
	gameMinutes = 0;
	gameSeconds = 0;
	set( enable.menu);
	set( clock.on);
	status.line.on();
	current.room = 34; 				[	so rm7 knows where we came from
	new.room( 7);
	}


if (current.status == eagle)
	{
	if (!edge.ego.hit && ego.y < 20)	[	sweep up after Jeff's bugs
		{
		edge.ego.hit = top;
		}

	if (!old.ego.dir && ego.dir)
		{
		if (ego.dir == ego.up)
			{
			ego.dir = ego.up.left;
			}

		if (ego.dir == ego.down)
			{
			ego.dir = ego.down.left;
			}
		}

	if ((old.ego.dir == ego.right ||
		old.ego.dir == ego.up.right ||
		old.ego.dir == ego.down.right))
		{
		if (ego.dir == ego.up)
			{
			ego.dir = ego.up.right;
			}

		if ((!ego.dir || ego.dir == ego.down))
			{
			ego.dir = ego.down.right;
			}
		}

	if ((old.ego.dir == ego.left ||
		old.ego.dir == ego.up.left ||
		old.ego.dir == ego.down.left))
		{
		if (ego.dir == ego.up)
			{
			ego.dir = ego.up.left;
			}

		if ((!ego.dir || ego.dir == ego.down))
			{
			ego.dir = ego.down.left;
			}
		}

	if ((ego.dir == ego.down.left ||
		ego.dir == ego.down.right))
		{
		if (ego.dir == ego.down.left)
			{
			set.loop( ego, facing.left);
			}

		if (ego.dir == ego.down.right)
			{
			set.loop( ego, facing.right);
			}

		stop.cycling( ego);
		reset( keep.cycling);
		set.cel( ego, 2);
		}
	else
		{
		start.cycling( ego);
		set( keep.cycling);
		}
	}

 
if (ego.poofing.done)
	{
	[	DO NOT reset( ego.poofing.done); here.  Others may be waiting for it.
	erase( a.poof);
	reset( prevent.new.room);

	if (current.status == poofing)
		{
		if (room.poofing.to)
			{
			new.room.v( room.poofing.to);
			}
		else
			{
			current.status = normal.ego;
			}
		}

	if ((current.status == fly ||
		current.status == eagle))
		{
		set( handsOff);
		set( ignore.special);
		set( ignore.water);
		ignore.horizon( ego);
		magic.minutes = magic.init.minutes;
		set.priority( ego, 15);

		if (current.status == eagle)
			{
			ego.cycle.time	= 2;
			ego.step.time	= 2;
			ego.step.size	= 2;
			start.motion( ego);
			}
		else	
			{
			set( keep.cycling);
			ego.cycle.time	= 1;
			ego.step.time	= 1;
			ego.step.size	= 1;
			}
		}
		
	if (current.status == normal.ego)
		{
		normal.motion( ego);
		start.motion( ego);
		observe.block( ego);
		observe.objs( ego);
		observe.horizon( ego);
		release.priority( ego);
		reset( keep.cycling);
		reset( no.cycling);
		reset( ignore.special);
		reset( ignore.water);
		ego.step.size	= 1;
		ego.step.time	= 1;
		ego.cycle.time	= 1;
		reset( handsOff);
		}

	if (current.status == ate.cat.cookie)
		{
		print( 23);
		work = 3;
		cycle.time( ego, work);
		start.cycling( ego);
		set( certain.death);
		}
	else
		{
		player.control();
		accept.input();
		cycle.time( ego, ego.cycle.time);
		step.time( ego, ego.step.time);
		step.size( ego, ego.step.size);
		}
	}



[*****
[	BRING IN THE IMPROMTU WIZARD?
[*****

[	Be sure the wiz can enter this room, right now.

if  (seconds.in.room > 7 &&			[	no abrupt entrances
	wiz.status != dead &&			[	no dead wizzing
	wiz.y &&						[	no wizzing allowed in this room
    !PO'd.wiz.init'd &&				[	no restarts
	current.ego == normal.ego &&		[	no wierd-o's
    !handsOff)						[	no wizzing if no toucha
	{
	if (!make.wiz.come)				[	If no room forced us here.
		{
		if (!wiz.minutes && !wiz.seconds)
			{
			make.wiz.come = wiz.away.asleep;
			}
	
		if ((wiz.away.asleep == home.after.bed ||
			wiz.away.asleep == home.after.town))
			{
			if (chore.to.do)
				{
				make.wiz.come = 0;		[Wiz won't come to tell ego he's
									[leaving if still chore assigned.
				if (!chore.minutes &&	[	He skipped his chore.
				    !chore.seconds)
					{
					make.wiz.come = skipped.chore;
					}
				}
	
			if (office.status)
				{
				make.wiz.come = office.awry;
				}
	
			work = 5;
			if (!obj.in.room( i.magic.wand, work))
				{
				make.wiz.come = magic.wand.missing;
				}
		
			if  (current.room > 8 &&		[	Ego left the ol' "wiz-bar-H"...
				current.room < 87) 		[	...and is in a real room.
				{
				make.wiz.come = in.wrong.place;
				}
			}
		}

	if (make.wiz.come)				[	It's a hit!
		{
		load.logics( lgc.PO'd.wiz);	[	Bring on that little wizzer!
		call( lgc.PO'd.wiz);		[	logic called repeatedly below
		}
	}


if  (wiz.y && 
	wiz.status != dead &&
	force.wiz.come)
	{
	reset( force.wiz.come);
	edge.ego.hit = 0;
	current.status = normal.ego;
	current.ego    = normal.ego;

	load.logics( lgc.PO'd.wiz);		[	Bring on that little wizzer!
	call( lgc.PO'd.wiz);			[	logic called repeatedly below
	}



[****************************************************************************]
[********************	PREPARE TO CALL LOCAL ROOMS	**********************]
[****************************************************************************]



get.posn( ego, ego.x, ego.y);
current.view( ego, current.ego);


if (PO'd.wiz.init'd)
	{
	call( lgc.PO'd.wiz);
	}

if (!init.log)
	{
	call.v( current.room);
	}

if (debugging)
	{
	call( lgc.debug);
	}



[****************************************************************************]
[********************	AFTER CALLING LOCAL ROOMS	**********************]
[****************************************************************************]


if ((current.status == fly || current.status == eagle ||
	current.status == fly.landing || current.status == eagle.landing))
   	{
	set( handsOff);
	set.priority( ego, 15);
	set( ignore.special);
	set( ignore.water);
	ignore.blocks( ego);
	ignore.horizon( ego);
	ignore.objs( ego);
	if ((current.status == fly || current.status == fly.landing))
		{
		set.view( ego, v.ego.fly);
		set( keep.cycling);
		start.cycling( ego);
		}
	if ((current.status == eagle || current.status == eagle.landing))
		{
		set.view( ego, v.ego.eagle);
		}
	}

 

[*****
[	FIRST, HANDLE ANY MAGIC ATTEMPTS THAT MAKE IT THROUGH THE LOCAL ROOM:
[*****

if (spell.cast == sc.start.sleep)
	{
	spell.cast = 0;
	print( 83);
	}


if (spell.cast == sc.start.storm)
	{
	spell.cast = 0;
	if (handsOff)
		{
		print( 27);
		}
	else
		{
		set( handsOff);
		storm.minutes = storm.init.minutes;
		if (map.area == map.ship)
		    	{
			new.room( 70);
			}
		else
			{
			if (interiorRoom)
				{
				program.control();
				prevent.input();
				stop.motion( ego);
				load.view( v.gag.dead.ego.2);
				set.view( ego, v.gag.dead.ego.2);
				set.loop( ego, 1);
				force.update( ego);
				print.at( 74, 2, 2, 37);
				start.cycling( ego);
				set( keep.cycling);
				set( certain.death);
				}
			else
				{
				deferred.x = ego.x;
				deferred.y = ego.y;
				new.room( 87);
				}
			}
		}
 	}

if (spell.cast == sc.stop.storm)
	{
	if ((current.ego != normal.ego || 
		current.status != normal.ego))
		{
		storm.seconds = 4;
		}
	else
		{
		reset( handsOff);
		spell.cast = 0;
		storm.minutes = 0;
		storm.seconds = 0;
		}
	}


if (spell.cast == sc.map)
	{
	spell.cast = 0;
	if ((handsOff ||
		current.status == swimming ||
		tooBusyForMap))
		{
		print( 27);
		}
	else
		{
		deferred.x = ego.x;
		deferred.y = ego.y;
		new.room( 89);
		}
	}


if (spell.cast == sc.fly)
	{
	spell.cast = 0;
	if (handsOff)
		{
		print( 27);
		}
	else
		{
		current.status = fly;
		start.a.poof = poof.change;
		poof.change.view = fly;
		release.priority( ego);
		print( 9);
		}
	}
			

if (spell.cast == sc.eagle)
	{
	spell.cast = 0;
	if (handsOff)
		{
		print( 27);
		}
	else
		{
		if (interiorRoom)
			{
			print( 103);
			}
		else
			{
			current.status = eagle;
			start.a.poof = poof.change;
			poof.change.view = eagle;
			set.priority( ego, 14);
			set( ignore.special);
			set( ignore.water);
			print( 9);
			}
		}
	}
	

if (spell.cast == sc.stop.flying)
	{
	spell.cast = 0;
	magic.minutes = 0;
	magic.seconds = 0;
	prevent.input();
	set.priority( ego, 15);			[	prevent hangups
	move.obj.v( ego,landing.x,landing.y, ego.step.size, the.eagle.has.landed);

	if (current.status == eagle)
		{
		current.status = eagle.landing;
		if (!magic.done)
			{
			print( 107);
			}
		}

	if (current.status == fly)
		{
		current.status = fly.landing;
		if (!magic.done)
			{
			print( 109);
			}
		}
	}


if (the.eagle.has.landed)
	{
	reset( the.eagle.has.landed);
	magic.minutes = 0;
	magic.seconds = 0;
	++flight.count;
	if (flight.count > 2)
		{
		drop( i.magic.essence);
		print( 112);
		}

	start.a.poof = poof.change;
	poof.change.view = normal.ego;
	current.status = normal.ego;
	reset( keep.cycling);
	}


if (spell.cast == sc.invisible)
	{
	spell.cast = 0;
	if ((handsOff || current.status != normal.ego))
		{
		print( 27);
		}
	else
		{
		if  (current.room != 65 &&
			current.room != 67)
			{
			drop( i.invisible.ointment);
			print( 83);
			}
		else
			{
			set( invisibleEgo);
			drop( i.invisible.ointment);
			start.a.poof = poof.change;
			poof.change.view = invisible;
			release.priority( ego);
			print( 9);
			}
		}
	}

	
if (spell.cast == sc.visible)
	{
	spell.cast = 0;
	current.status = normal.ego;
	reset( invisibleEgo);
	start.a.poof = poof.change;
	poof.change.view = normal.ego;
	magic.minutes = 0;
	magic.seconds = 0;
	if (!magic.done)
		{
		print( 9);
		}
	}


if (spell.cast == sc.poof)
	{
	spell.cast = 0;
	if (handsOff)
		{
		print( 27);
		}
	else
		{
		if (map.area == map.llewdor)
			{
			random( 11, 32, room.poofing.to);
			}

		if (map.area == map.mountains)
			{
			random( 48, 57, room.poofing.to);
			}

		if (map.area == map.clouds)
			{
			random( 61, 67, room.poofing.to);
			}

		if (map.area == map.daventry)
			{
			:memorial.pick.a.room
			random( 68, 72, room.poofing.to);
			if (room.poofing.to == 70)	[	sinking ship not in Daventry
				{
				goto memorial.pick.a.room;
				}
			}

		if (map.area == map.wiz.house)
			{
			random(  1, 11, room.poofing.to);
			if (room.poofing.to == 11)
				{
				room.poofing.to = 34;
				}
			}

		if (map.area == map.ship)
			{
			random( 78, 87, room.poofing.to);
			if (room.poofing.to == 87)
				{
				room.poofing.to = 31;
				}
			}

		if (room.poofing.to)
			{
			current.status = poofing;
			start.a.poof = poof.out;
			}
		else
			{
			print( 22);
			}
		}
	}


if (start.a.poof)
	{
	set( handsOff);
	load.view( v.poof);
	load.sound( s.ego.poofing);
	set( prevent.new.room);

	if (start.a.poof == poof.change)
		{
		load.view.v( poof.change.view);
		}

	stop.motion( ego);
	program.control();
	prevent.input();

	animate.obj( a.poof);
	set.view( a.poof, v.poof);
	set.priority( a.poof, 15);
	ignore.obj( a.poof);
	x = ego.x;
	if (x > 3)
		{
		x -= 4;
		}
	position.v( a.poof, x, ego.y);
	set.cel( a.poof, 0);
	draw( a.poof);
	work = 3;
	cycle.time( a.poof, work);
	end.of.loop( a.poof, ego.poofing.done);
	sound( s.ego.poofing, done);


	set.scan.start();

	current.cel( a.poof, work);
	if (work != 3)
		{
		return();
		}
	else
		{
		release.loop( ego);
		if (start.a.poof == poof.in)
			{
			draw( ego);
			reset( erase.ego);
			}

		if (start.a.poof == poof.out)
			{
			erase( ego);
			set( erase.ego);
			}

		if (start.a.poof == poof.change)
			{
			set.view.v( ego, poof.change.view);
			}

		reset.scan.start();
		}

	start.a.poof = 0;
	}


if (invisibleEgo)
	{
	current.view( ego, view);
	if (view != invisible)
		{
		magic.minutes = 0;
		magic.seconds = 0;
		reset( invisibleEgo);
		print( 24);
		}
	}


[*****
[	LAST CHANCE, CLEAN UP, INPUT
[*****

if ((have.match || 
    !have.input ||
	current.room	== 43 ||			[	spell room
	current.status == sleeping ||
	current.status == stunned ||
	current.status == dead))
	{
	goto exit;
	}

if ((has( i.porridge) || has(i.porridge.poisoned)) &&
    	said( give, porridge, rol))
	{
	print( 34);
	}

if (has( i.saffron) && said( eat, saffron))
	{
	print( 56);
	}

if (has( i.invisible.ointment) && said( eat, ointment))
	{
	print( 78);
	}


if (has( i.sleep.powder) && said( eat, sleep, powder))
	{
	print( 80);
	drop( i.sleep.powder);
	}

if (has( i.bread) && said( eat, bread))
	{
	print( 9);
	drop( i.bread);
	}

if (has( i.fruit) && said( eat, fruit))
	{
	print( 9);
	drop( i.fruit);
	}

if (has( i.mutton) && said( eat, mutton))
	{
	print( 9);
	drop( i.mutton);
	}

if (has( i.porridge) && said( eat, porridge))
	{
	print( 9);
	drop( i.porridge);
	}

if (has( i.mistletoe) && said( eat, mistletoe))
	{
	print( 78);
	drop( i.mistletoe);
	}

if (has( i.acorns) && said( eat, acorn))
	{
	print( 78);
	drop( i.acorns);
	}

if (has( i.salt) && said( eat, salt))
	{
	print( 96);
	}

if (has( i.fish.bone) && 
	said( eat, bone, rol))
	{
	print( 78);
	}


if  (has( i.cactus) && has( i.knife) &&
    (said( use, knife, cut, cactus) || said( cut, cactus, rol)))
	{
	print( 40);
	}

if  (has( i.bread) && has( i.knife) &&
    (said( use, knife, cut, bread) || said( cut, bread, rol)))
	{
	print( 61);
	}

if  (has( i.fruit) && has( i.knife) &&
    (said( use, knife, cut, fruit) || said( cut, fruit, rol)))
	{
	print( 60);
	}

if  (has( i.mutton) && has( i.knife) &&
    (said( use, knife, cut, mutton) || said( cut, mutton, rol)))
	{
	print( 59);
	}

if (has( i.lard) && said( eat, lard))
	{
	print( 78);
	}

if (has( i.toad.spit) && said( drink, toad, spit))
	{
	print( 71);
	}

if (has( i.rose.essence) && said( drink, essence))
	{
	print( 86);
	drop( i.rose.essence);
	}

if (has( i.magic.essence) && 
	(said( drink, essence) || said( drink, magic, essence)))
	{
	print( 86);
	drop( i.magic.essence);
	}

if ((has( i.ocean.water) || has( i.cup)) &&
    (said( drink, out, cup) || said( drink, cup) || said( drink, anyword, cup)))
	{
	if (has( i.cup))
		{
		print( 73);
		}

	if  (has( i.ocean.water))
		{
		print( 78);
		drop( i.ocean.water);
		get( i.cup);
		}
	}

if  (has( i.ocean.water) && 
    (said( drink, ocean, water) || said( drink, water)))
	{
	print( 78);
	drop( i.ocean.water);
	get( i.cup);
	}

if (has( i.fish.oil) && said( drink, fish, oil))
	{
	print( 78);
	drop( i.fish.oil);
	}

if (has( i.dew) && (said( drink, dew) || 
	said( drink, dew, thimble) || said( drink, thimble, dew)))
	{
	print( 90);
	drop( i.dew);
	get( i.thimble);
	}


[*****
[	HANDLE "USING" STUFF
[*****

if ((has( i.eagle.feather) || has( i.chicken.feather)) && said( use, feather))
	{
	print( 51);
	}

if (has( i.chicken.feather) && said( use, chicken, feather))
	{
	print( 52);
	}

if ((has( i.cat.hair) || has( i.dog.hair)) && said( use, hair))
	{
	print( 51);
	}

if (has( i.cat.hair) && said( use, cat, hair))
	{
	print( 52);
	}

if (has( i.dog.hair) && said( use, dog, hair))
	{
	print( 52);
	}

if (has( i.snakeskin) && said( use, snake, skin))
	{
	print( 52);
	}

if (has( i.fish.bone) && said( use, bone))
	{
	print( 52);
	}

if (has( i.thimble) && said( use, thimble))
	{
	print( 51);
	}

if (has( i.dew) && 
	(said( use, dew) || said( use, thimble)))
	{
	print( 51);
	}

if (has( i.eagle.feather) && said( use, eagle, feather))
	{
	print( 52);
	}

if (has( i.fly.wings) && said( use, fly))
	{
	print( 51);
	}

if (has( i.saffron) && said( use, saffron))
	{
	print( 51);
	}

if (has( i.salt) && said( use, salt))
	{
	print( 51);
	}

if (has( i.mistletoe) && said( use, mistletoe))
	{
	print( 51);
	}

if (has( i.nightshade.juice))
	{
	if (said( use, nightshade, juice))
		{
		print( 52);
		}
	else
		{
		if (said( use, juice))
			{
			print( 51);
			}
		}
	}

if (has( i.acorns) && said( use, acorns))
	{
	print( 51);
	}

if (has( i.empty.pouch))
	{
	if (said( use, empty, pouch))
		{
		print( 52);
		}
	else
		{
		if (said( use, pouch))
			{
			print( 51);
			}
		}
	}

if (has( i.mandrake.root))
	{
	if (said( use, mandrake, root))
		{
		print( 52);
		}
	else
		{
		if (said( use, root))
			{
			print( 51);
			}
		}
	}

if (has( i.fish.oil) && said( use, fish, oil))
	{
	print( 52);
	}

if (has( i.cat.cookie))
	{
	if (said( use, cookie))
		{
		print( 51);
		}
	else
		{
		if (said( use, cat, cookie))
			{
			print( 52);
			}
		}
	}

if (has( i.ocean.water))
	{
	if (said( use, ocean, water))
		{
		print( 52);
		}
	else
		{
		if (said( use, water))
			{
			print( 51);
			}
		}
	}

if (has( i.mud) && (said( use, mud) || said( use, spoon)))
	{
	print( 51);
	}

if (has( i.toadstool.powder) && said( use, toadstool, powder))
	{
	print( 52);
	}

if (has( i.fish.jar) && said( use, jar))
	{
	print( 51);
	}

if (has( i.toad.spit))
	{
	if (said( use, toad, spit))
		{
		print( 52);
		}
	else
		{
		if (said( use, spit))
			{
			print( 51);
			}
		}
	}

if (has( i.lard) && said( use, lard))
	{
	print( 51);
	}

if (has( i.knife) && said( use, knife))
	{
	print( 51);
	}

if (has( i.cactus) && said( use, cactus))
	{
	print( 51);
	}

if  (has( i.magic.wand) && (said( use, magic, wand)  || said( use, wand) ||
	said( wave, magic, wand) || said( wave, wand)))
	{
	print( 82);
	}

if (has( i.key) && said( use, key))
	{
	print( 58);
	}

if (has( i.bowl) && said( use, bowl))
	{
	print( 51);
	}

if (has( i.spoon) && said( use, spoon))
	{
	print( 51);
	}

if (has( i.cup) && said( use, cup))
	{
	print( 51);
	}

if (has( i.mirror) && (said( use, mirror) || said( use, hand, mirror)))
	{
	print( 85);
	}

if ((has( i.purse.with.coins) || has( i.purse.empty)) && said( use, purse))
	{
	print( 51);
	}

if (has( i.bread) && said( use, bread))
	{
	print( 51);
	}

if (has( i.fruit) && said( use, fruit))
	{
	print( 51);
	}

if (has( i.mutton) && said( use, mutton))
	{
	print( 51);
	}

if (has( i.shovel) && said( use, shovel))
	{
	print( 51);
	}

if (has( i.treasure.chest) && said( use, chest))
	{
	print( 51);
	}

if ((has( i.porridge.poisoned) || has( i.porridge)) && said( use, porridge))
	{
	print( 51);
	}


[*****
[	HANDLE WHATEVER'S LEFT
[*****

if (has( i.dough.balls) && (said( get, dough, from, ears) ||
	said( remove, dough, from, ears) || said( remove, dough, ears)))
	{
	drop( i.dough.balls);
	print( 101);
	}

if  (has( i.amber.stone) &&
	said( throw, amber, stone, rol))
	{
	print( 92);
	drop( i.amber.stone);
	}

if (has( i.purse.with.coins))
	{
	if ((said( count, coins) ||
		said( count, coins, purse) ||
		said( count, gold, coins)))
		{
		print( 93);
		}

	if ((said( buy, rol) || 
		said( buy, anyword, coin)))
		{
		print( 94);
		}
	}

if (has( i.bowl) && (said( put, anyword, bowl)))
	{
	print( 57);
	}

if  (has( i.fish.jar) &&
    (said( look$in, jar) || said( open, jar) || said( take, lid, off, jar)))
	{
	print( 100);
	}

if (has( i.cup) && said( put, anyword, cup))
	{
	print( 75);
	}

if  (has( i.shovel) &&
    (said( dig, rol) || said( use, shovel, rol)))
	{
	print( 69);
	}

if (has( i.ocean.water) && said( empty$cup))
	{
	drop( i.ocean.water);
	get( i.cup);
	print( 84);
	}

if ((said( look, wizard)	||	said( look, spider)	||	
	said( look, boy)	||	said( look, medusa)	||	
	said( look, man)	||	said( look, queen)	||	
	said( look, dragon)	||	said( look, eagle)	||	
	said( look, girl)	||	said( look, chicken)))
	{
	print( 72);
	}

if (current.status == swimming &&
	said( swim))
	{
	print( 79);
	}

if ((said( talk, squirrel) ||
	said( talk, lizard) ||
	said( talk, snake) ||
	said( talk, spider) ||
	said( talk, man) ||
	said( talk, woman) ||
	said( talk, bird)))
	{
	print( 41);
	}

if (said( look, rock, rol))
	{
	print( 31);
	}

if (said( look, bush, rol))
	{
	print( 81);
	}

if (said( look, rol))
	{
	random( 42, 44, work);
	print.v( work);
	}

if (said( take, rol))
	{
	random( 46, 48, work);
	print.v( work);
	}

if (said( go, rol))
	{
	print( 49);
	}

if (said( use, rol))
	{
	print( 54);
	}

if (said( get, rol))
	{
	print( 76);
	}

if (said( eat, rol))
	{
	print( 67);
	}

if (said( kill, rol))
	{
	print( 50);
	}

if (said( find, rol))
	{
	print( 99);
	}

if (said( drop, rol))
	{
	print( 25);
	}


[*****
:exit
[*****

if (!have.match && have.input)
	{
	print( 45);
[		if (debugging && !unknown.word)
[			{
[			log( 21);
[			}
	}

get.posn( ego, old.ego.x, old.ego.y);	[	Clean up, fix up for next pass.
old.ego.dir = ego.dir;
reset( ego.poofing.done);
reset( aSecondPassed);
reset( magic.done);

