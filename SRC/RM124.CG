[logics for room 124 -- Spell 4.  Putting others into a deep sleep. 

%include	"rm124.msg"
%include	"gamedefs.al"
%include	"colors.h"
%include	"iv-names.h"



[	Oops is set upon every input.  If the entry is correct, it's reset.
[Spell.status is ++ every input.  Some questionable entries --spell.status, 
[to give him a "free round."



%define	overlay.pic.text.window	143

%define	ready.for.grinding		1
%define	ready.for.acorns		2
%define	ready.for.juice		3
%define	ready.for.mixing		4
%define	ready.for.boiling		5
%define	ready.for.drying		6
%define	ready.for.spell		7
%define	ready.for.wand			8
%define	ready.for.pouch		9
%define	times.up				10


%define	text.window			dv1



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


if ((said( grind, acorns, mortar) ||
	said( grind, three, acorns, mortar)))
	{
	if (!has( i.acorns))
		{
		print( 1);
		}
	else
		{
		if (spell.status == ready.for.grinding)
			{
			print( 9);
			drop( i.acorns);
			reset( oops);
			}
		else
			{
			reset( have.match);
			}
		}
	}

if ((said( put, acorn, powder, bowl) ||
	said( pour, acorn, powder, bowl)))
	{
	if (!has( i.bowl))
		{
		print( 25);
		}
	else
		{
		if (spell.status == ready.for.acorns)
			{
			print( 10);
			reset( oops);
			}
		else
			{
			reset( have.match);
			}
		}
	}

if ((said( put, cup, nightshade, bowl) ||
	said( put, cup, nightshade, juice, bowl) ||
	said( put, one, cup, nightshade, juice, bowl) ||
	said( put, one, cup, nightshade, bowl) ||
	said( put, nightshade, bowl) ||
	said( put, nightshade, juice, bowl) ||
	said( pour, cup, juice, bowl) ||
	said( pour, cup, nightshade, bowl) ||
	said( pour, cup, nightshade, juice, bowl) ||
	said( pour, one, cup, nightshade, juice, bowl) ||
	said( pour, one, cup, nightshade, bowl) ||
	said( pour, nightshade, juice, bowl)))
	{
	if (!has( i.nightshade.juice))
		{
		print( 1);
		}
	else
		{
		if (spell.status == ready.for.juice)
			{
			print( 11);
			print( 12);
			drop( i.nightshade.juice);
			reset( oops);
			}
		else
			{
			reset( have.match);
			}
		}
	}

if ((said( mix, mixture, spoon) ||
	said( mix, with, spoon) ||
	said( mix, mixture, with, spoon) ||
	said( mix, mixture)))
	{
	if (spell.status == ready.for.mixing)
		{
		print( 15);
		reset( oops);
		}
	else
		{
		reset( have.match);
		}
	}

if ((said( heat, mixture, burner) ||
	said( heat, mixture, over, burner) ||
	said( heat, mixture, on, burner) ||
	said( heat, bowl, on, burner) ||
	said( heat, bowl, burner) ||
	said( heat, bowl, over, burner) ||
	said( put, bowl, burner) ||
	said( put, bowl, over, burner) ||
	said( put, bowl, on, burner) ||
	said( put, bowl, on, burner, heat)))
	{
	if (!has( i.bowl))
		{
		print( 1);
		}
	else
		{
		print( 16);
	
		if (!burner.seconds && !burner.minutes)
			{
			print( 17);
			}
		else
			{
			if (spell.status == ready.for.boiling)
				{
				print( 18);
				print( 19);
				reset( oops);
				}
			else
				{
				reset( have.match);
				}
			}
		}
	}

if ((said( spread, mixture, table) ||
	said( spread, mixture, on, table)))
	{
	if (spell.status == ready.for.drying)
		{
		print( 20);
		reset( oops);
		++spell.status;		[	bring on the poem
		}
	else
		{
		reset( have.match);
		}
	}

if (said( get, sleep, powder))
	{
	if (spell.status == ready.for.pouch)
		{
		print( 23);
		}
	else
		{
		reset( have.match);
		}
	}	

if ((said( put, sleep, powder, pouch) ||
	said( pour, sleep, powder, pouch)))
	{
	if (!has( i.empty.pouch))
		{
		print( 1);
		}
	else
		{
		if (spell.status == ready.for.pouch) 
			{
			print( 22);
			reset( oops);
			drop( i.empty.pouch);
			get( i.sleep.powder);
			}
		else
			{
			reset( have.match);
			}
		}
	}

if ((said( wave, wand) ||
	said( wave, magic, wand)))
	{
	if (!has( i.magic.wand))
		{
		print( 1);
		drop( i.sleep.powder);
		}
	else
		{
		if (spell.status == ready.for.wand)
			{
			print( 8);
			reset( oops);
			}
		else
			{
			drop( i.sleep.powder);
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
	set.string( 1, 6);				[	" " default blank string
	if (poem.line.count == 0)
		{
		overlay.pic( text.window);	[	pic.143 = overlay text box
		show.pic();
		set.string( 2, 2);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 6, 15, 1, 28);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 6, 13, 1, 28);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 1)
		{
		set.string( 2, 3);
		if (monitor.type == mono)
			{
			get.string( 1, 6, 16, 1, 35);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 6, 14, 1, 35);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 2)
		{
		set.string( 2, 4);
		if (monitor.type == mono)
			{
			get.string( 1, 6, 17, 1, 31);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 6, 15, 1, 31);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 3)
		{
		set.string( 2, 5);
		if (monitor.type == mono)
			{
			get.string( 1, 6, 18, 1, 27);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 6, 16, 1, 27);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}
	set.text.attribute( text.color, bg.color);
	++poem.line.count;
	set.string( 1, 6);				[	" " default blank string
	set.string( 2, 6);				[	" " default blank string

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
	funny.death.view = 38;			[	view number of gag death
	funny.death.loop = 3;			[	loop number of gag death
	}

