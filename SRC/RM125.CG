[logics for room 125 -- transforming someone into a cat

%include	"rm125.msg"
%include	"gamedefs.al"
%include	"colors.h"
%include	"iv-names.h"



[	Oops is set upon every input.  If the entry is correct, it's reset.
[Spell.status is ++ every input.  Some questionable entries --spell.status, 
[to give him a "free round."


%define	overlay.pic.text.window		143

%define	ready.for.mandrake			1
%define	ready.for.cat.hair			2
%define	ready.for.fish.oil			3
%define	ready.for.mixing			4
%define	ready.for.spreading			5
%define	ready.for.shaping			6
%define	ready.for.spell			7
%define	ready.for.wand				8
%define	times.up					9


%define	fish.oil.count				dv0
%define	text.window				dv1


if (init.log)
	{
	text.window = overlay.pic.text.window;
	return();
	}

		
[*****
:handle.input
[*****

if ((!have.input || have.match))	{goto spell.input;}

set( oops);
++spell.status;


if ((said( put, mandrake, root, powder, bowl) ||
	said( pour, mandrake, root, powder, bowl)))
	{
	if ((!has( i.mandrake.root) ||
		!has( i.bowl)))
		{
		print( 1);
		}
	else
		{
		print( 3);
		drop( i.mandrake.root);
		if (spell.status == ready.for.mandrake)
			{
			reset( oops);
			}
		}
	}

if (said( put, cat, fur, bowl))
	{
	if ((!has( i.cat.hair) ||
		!has( i.bowl)))
		{
		print( 1);
		}
	else
		{
		drop( i.cat.hair);
		print( 8);
		if (spell.status == ready.for.cat.hair)
			{
			reset( oops);
			}
		}
	}

if (said( put, two, spoon, fish$oil, bowl))
	{
	if ((!has( i.fish.oil) ||
		!has( i.bowl)))
		{
		print( 1);
		}
	else
		{
		print( 11);
		drop( i.fish.oil);
		get( i.fish.jar);
		if (spell.status == ready.for.fish.oil)
			{
			reset( oops);
			}
		}
	}

if ((said( mix, mixture, with, spoon) ||
	said( mix, mixture) ||
	said( mix, with, spoon)))
	{
	if (spell.status == ready.for.mixing)
		{
		print( 12);
		reset( oops);
		}
	else
		{
		reset( have.match);
		}
	}

if ((said( put, dough, on, table) ||
	said( pour, dough, on, table)))
	{
	if (spell.status == ready.for.spreading)
		{
		print( 13);
		reset( oops);
		}
	else
		{
		reset(have.match);
		}
	}
	
if ((said( pat, dough, cookie) ||
	said( make, dough, cookie) ||
	said( make, cookie, from, dough) ||
	said( pat, cookie, from, dough)))
	{
	if (spell.status == ready.for.shaping)
		{
		print( 14);
		reset( oops);
		++spell.status;
		}
	else
		{
		reset( have.match);
		}
	}

if ((said( wave, wand) ||
	said( wave, magic, wand)))
	{
	if (!has( i.magic.wand))
		{
		print( 1);
		}
	else
		{
		if (spell.status == ready.for.wand)
			{
			print( 15);
			reset( oops);
			get( i.cat.cookie);
			}
		else
			{
			reset( have.match);
			}
		}
	}



[*****
:spell.input
[*****

if (!oops &&
	poem.line.count < 4 &&
	spell.status == ready.for.spell)
	{
	set( oops);
	prevent.input();
	set.text.attribute( black, light.white);
	set.string( 1, 9);				[	" " default blank string
	if (poem.line.count == 0)
		{
		overlay.pic( text.window);	[	pic.143 = overlay text box
		show.pic();
		set.string( 2, 4);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 9, 15, 1, 30);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 9, 13, 1, 30);	[	string#, prompt, row, col, length
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 1)
		{
		set.string( 2, 5);
		if (monitor.type == mono)
			{
			get.string( 1, 9, 16, 1, 31);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 9, 14, 1, 31);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 2)
		{
		set.string( 2, 6);
		if (monitor.type == mono)
			{
			get.string( 1, 9, 17, 1, 30);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 9, 15, 1, 30);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 3)
		{
		set.string( 2, 7);
		if (monitor.type == mono)
			{
			get.string( 1, 9, 18, 1, 28);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 9, 16, 1, 28);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}
	set.text.attribute( text.color, bg.color);
	++poem.line.count;
	set.string( 1, 9);
	set.string( 2, 9);

	if ((oops || poem.line.count == 4))
		{
		if (monitor.type == mono)
			{
			close.dialogue();
			}

		draw.pic( current.room);
		show.pic();
		accept.input();
		}
	}


[*****
:no.input
[*****


[*****
:exit
[*****

work = spell.status;
++work;
if (work == times.up && !oops)
	{
 	spell.status = spell.done;
	}

if (oops)
	{
	funny.death.view = 39;			[	view number of gag death
	funny.death.loop = 0;			[	loop number of gag death
	}

