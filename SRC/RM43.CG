[logics for room 43 -- rm.spells

%include	"rm43.msg"
%include	"gamedefs.al"
%include	"rm-names.h"



[	if makes error in order, in ingredients, or in incantation input -- set
[oops, stop spell music, say "OOPS", return to rm10, show funny dead ego, 
[ie. ego is a pair of giant ears.

[	All recipe mixing will be done only in this room.  



%define	overlay.pic.text.window	143

%define	going.back.to.lab		lf0
%define	music.done			lf1
%define	seen.music.start.message	lf2



if (init.log)
	{
	set.horizon( 1);
	reset( handsOff);
	set( interiorRoom);
	funny.death.view = 0;
	funny.death.loop = 0;
	poem.line.count = 0;
	spell.status = 0;
	reset( oops);

	load.logics.f( spell.in.progress);
	load.sound( m.spells);

	work = overlay.pic.text.window;
	load.pic( work);


	load.pic( current.room);
	draw.pic( current.room);
	[	DO NOT 	discard.pic( current.room);


	show.pic();					[	show the plain book

	call.f( spell.in.progress);

	print( 1);

	set( music.done);
	return();

	}



set( handsOff);


[*****
:handle.input
[*****

if (!have.input)				{goto no.input;}

if (said( use, burner))
	{
	print( 8);
	}

if ((said( light, burner) ||
	said( light, charcoal, burner) ||
	said( light, charcoal)))
	{
	if ((burner.seconds ||
		burner.minutes))
		{
		print( 9);
		}
	else
		{
		print( 10);
		burner.minutes = burner.init.minutes;
		}
	}

if ((said( look, burner) ||
	said( look, burner, table) ||
	said( look$in, burner)))
	{
	print( 13);
	if ((burner.seconds || burner.minutes))
		{
		print( 14);
		}
	else
		{
		print( 15);
		}
	}

if ((said( get, charcoal) ||
	said( get, charcoal, from, burner)))
	{
	print( 16);
	}

if ((said( look, charcoal) ||
	said( look, charcoal, burner)))
	{
	if ((burner.seconds || burner.minutes))
		{
		print( 17);
		}
	else
		{
		print( 15);
		}
	}

if ((said( leave, room) ||
	said( stop, anyword, spell) ||
	said( look, room) ||
	said( return, room) ||
	said( look, lab) ||
	said( return, lab) ||
	said( quit, anyword) ||
	said( stop, anyword)))
	{
	set( going.back.to.lab);
	}


[*****
:no.input
[*****

if  (aSecondPassed &&
	burner.seconds == 1 && 
    !burner.minutes)
	{
	print.at( 11, 2, 2, 36);
	}

if (oops)
	{
	stop.sound();
	reset( music.done);

	set( going.back.to.lab);
	if (!sound.on)
		{
		print( 5);
		}
	}

if (music.done)
	{
	sound( m.spells, music.done);
	if (!seen.music.start.message)
		{
		set( seen.music.start.message);
		if (!sound.on)
			{
			print( 4);
			}
		}
	}

if (spell.status == spell.done)
	{
	print( 6);
	set( going.back.to.lab);
	if (!made.spell.1 && spell.in.progress == 121)
		{
		set( made.spell.1);
		score += 10;
		}

	if (!made.spell.2 && spell.in.progress == 122)
		{
		set( made.spell.2);
		score += 10;
		}

	if (!made.spell.3 && spell.in.progress == 123)
		{
		set( made.spell.3);
		score += 10;
		}

	if (!made.spell.4 && spell.in.progress == 124)
		{
		set( made.spell.4);
		score += 10;
		}

	if (!made.spell.5 && spell.in.progress == 125)
		{
		set( made.spell.5);
		score += 10;
		}

	if (!made.spell.6 && spell.in.progress == 126)
		{
		set( made.spell.6);
		score += 10;
		}

	if (!made.spell.7 && spell.in.progress == 127)
		{
		set( made.spell.7);
		score += 10;
		}
	}


[*****
:exit							[	test for leaving the room
[*****

if (going.back.to.lab)
	{
	reset( going.back.to.lab);

	if (!spell.status)
		{
 		print( 2);
		}
	else
		{
		if (spell.status != spell.done)
			{
			set( have.match);
			set( oops);
			call.v( spell.in.progress);
			print( 3);
			}
		}

	poem.line.count = 0;
	spell.status = 0;
	spell.in.progress = 0;
	set.string( 0, 7);
	reset( handsOff);
	new.room( rm.lab);
	}


call.f( spell.in.progress);

if ((said( put, anyword, on, burner) ||
	said( put, anyword, on, top, burner) ||
	said( heat, anyword, on, burner) ||
	said( heat, anyword, on, top, burner) ||
	said( put, anyword, on, burner, heat) ||
	said( put, anyword, on, top, burner, heat)))
	{
	print( 12);
	}
