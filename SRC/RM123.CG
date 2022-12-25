[logics for room 123 -- spell #3 -- protection through poofing

%include	"rm123.msg"
%include	"gamedefs.al"
%include	"colors.h"
%include	"iv-names.h"

	
	
[	Oops is set upon every input.  If the entry is correct, it's reset.
[Spell.status is ++ every input.  Some questionable entries --spell.status, 
[to give him a "free round."



%define	overlay.pic.text.window		143

%define	ready.for.salt			1
%define	ready.for.mistletoe		2
%define	ready.for.amber.stone	3
%define	ready.for.kiss			4
%define	ready.for.spell		5
%define	ready.for.wand			6
%define	times.up				7


%define	put.salt.in			df0


%define	text.window			dv0



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


if ((said( put, salt, spoon) ||
	said( put, salt, mortar) ||
	said( pour, salt, mortar) ||
	said( grind, salt, mortar) ||
	said( put, spoon, salt, mortar) ||
	said( pour, spoon, salt, mortar) ||
	said( put, spoon, salt, mortar) ||
	said( grind, spoon, salt, mortar)))
	{
	if (spell.status == ready.for.salt)
		{
		set( put.salt.in);
		}
	else
		{
		reset( have.match);
		}
	}


if (said( grind, mistletoe, mortar))
	{
	if (!has( i.mistletoe))
		{
		print( 1);
		}
	else
		{
		drop( i.mistletoe);
		print( 5);
		if (spell.status == ready.for.mistletoe)
			{
			reset( oops);
			print( 6);
			}
		}
	}

if ((said( rub, amber, stone, mixture) ||
	said( rub, amber, stone, mortar) ||
	said( rub, stone, mixture) ||
	said( rub, stone, mortar)))
	{
	if (!has( i.amber.stone))
		{
		print( 1);
		}
	else
		{
		print( 7);
		if (spell.status == ready.for.amber.stone)
			{
			reset( oops);
			print( 8);
			}
		}
	}

if ((said( kiss, amber, stone) ||
	said( kiss, stone)))
	{
	if (spell.status == ready.for.kiss)
		{
		print( 9);
		reset( oops);
		++spell.status;		[	bring on the poem
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
		print( 14);
		if (spell.status == ready.for.wand)
			{
			reset( oops);
			drop( i.amber.stone);
			get( i.magic.stone);
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
	set.string( 1, 17);				[	" " default blank string
	if (poem.line.count == 0)
		{
		overlay.pic( text.window);	[	pic.143 = overlay text box
		show.pic();
		set.string( 2, 10);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 17, 15, 1, 30);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 17, 13, 1, 30);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 1)
		{
		set.string( 2, 11);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 17, 16, 1, 28);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 17, 14, 1, 28);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 2)
		{
		set.string( 2, 12);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 17, 17, 1, 35);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 17, 15, 1, 35);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 3)
		{
		set.string( 2, 13);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 17, 18, 1, 29);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 17, 16, 1, 29);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}
	set.text.attribute( text.color, bg.color);
	++poem.line.count;
	set.string( 1, 17);				[	" " default blank string
	set.string( 2, 17);				[	" " default blank string

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

if (put.salt.in)
	{
	reset( put.salt.in);
	if (!has( i.salt))
		{
		print( 1);
		}
	else
		{
		drop( i.salt);
		print( 3);
		if (spell.status == ready.for.salt)
			{
			reset( oops);
			}
		}
	}


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
	funny.death.view = 38;			[	view number of gag death
	funny.death.loop = 2;			[	loop number of gag death
	}

