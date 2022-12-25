[logics for room 126 -- Spell Six:  Brewing a storm. 

%include	"rm126.msg"
%include	"gamedefs.al"
%include	"colors.h"
%include	"iv-names.h"



[	Oops is set upon every input.  If the entry is correct, it's reset.
[Spell.status is ++ every input.  Some questionable entries --spell.status, 
[to give him a "free round."



%define	overlay.pic.text.window		143

%define	ready.for.ocean.water		1
%define	ready.for.heat				2
%define	ready.for.mud				3
%define	ready.for.toadstool.powder	4
%define	ready.for.a.blow.job		5
%define	ready.for.spell			6
%define	ready.for.wand				7
%define	ready.for.jar				8
%define	times.up					9


%define	text.window				dv0



if (init.log)
	{
	text.window = overlay.pic.text.window;
	return();
	}


		
[*****
:handle.input
[*****

if ((!have.input || have.match))		{goto spell.input;}

set( oops);
++spell.status;


if ((said( put, ocean, water, bowl) ||
	said( put, cup, ocean, water, bowl) ||
	said( put, one, cup, ocean, water, bowl) ||
	said( pour, ocean, water, bowl) ||
	said( pour, cup, ocean, water, bowl) ||
	said( pour, one, cup, ocean, water, bowl) ||
	said( put, water, bowl) ||
	said( put, cup, water, bowl) ||
	said( put, one, cup, water, bowl) ||
	said( pour, water, bowl) ||
	said( pour, cup, water, bowl) ||
	said( pour, one, cup, water, bowl)))
	{
	if ((!has( i.bowl) ||
		!has( i.ocean.water)))
		{
		print( 1);
		}
	else
		{
		drop( i.ocean.water);
		get( i.cup);
		print( 9);
		if (spell.status == ready.for.ocean.water)
			{
			reset( oops);
			}
		}
	}

if ((said( heat, bowl, burner) ||
	said( heat, ocean, water, burner) ||
	said( heat, bowl, ocean, water, burner) ||
	said( heat, bowl, ocean, water, over, burner) ||
	said( heat, water, burner) ||
	said( heat, bowl, on, burner) ||
	said( heat, ocean, water, on, burner) ||
	said( heat, bowl, ocean, water, on, burner) ||
	said( heat, water, on, burner) ||
	said( heat, bowl, water, on, burner) ||
	said( heat, bowl, water, burner) ||
	said( heat, bowl, water, over, burner)))
	{
	if (!burner.seconds && !burner.minutes)
		{
		print( 10);
		}
	else
		{
		print( 11);
		if (spell.status == ready.for.heat)
			{
			reset( oops);
			}
		}
	}

if ((said( put, spoon, mud, bowl, water) ||
	said( put, mud, bowl, water) ||
	said( put, mud, bowl) ||
	said( mix, spoon, mud, bowl) ||
	said( mix, spoon, mud, bowl, water) ||
	said( mix, mud, bowl, water) ||
	said( put, spoon, mud, bowl, ocean, water) ||
	said( put, mud, bowl, ocean, water) ||
	said( mix, spoon, mud, bowl, ocean, water) ||
	said( mix, mud, bowl, ocean, water) ||
	said( mix, spoon, mud, bowl) ||
	said( put, spoon, mud, bowl) ||
	said( mix, mud, bowl)))
	{
	if (!has( i.mud))
		{
		print( 1);
		}
	else
		{
		print( 12);
		drop( i.mud);
		get( i.spoon);
		if (spell.status == ready.for.mud)
			{
			reset( oops);
			}
		}
	}

if ((said( put, pinch, toadstool, powder) ||
	said( put, pinch, toadstool, powder, bowl) ||
	said( put, pinch, toadstool, powder, water)))
	{
	if (!has( i.toadstool.powder))
		{
		print( 1);
		}
	else
		{
		print( 13);
		drop( i.toadstool.powder);
		if (spell.status == ready.for.toadstool.powder)
			{
			reset( oops);
			}
		}
	}

if ((said( blow, water) ||
	said( blow, brew) ||
	said( blow, ocean, water) ||
	said( blow, bowl)))
	{
	if (spell.status == ready.for.a.blow.job)
		{
		print( 14);
		reset( oops);
		++spell.status;			[	ready to say spell
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
		print( 15);
		if (spell.status == ready.for.wand)
			{
			reset( oops);
			}
		}
	}

if ((said( pour, brew, from, bowl, jar) ||
	said( pour, brew, jar) ||
	said( put, brew, from, bowl, jar) ||
	said( put, brew, jar)))
	{
	if (!has( i.fish.jar))
		{
		print( 1);
		}
	else
		{
		if (spell.status == ready.for.jar)
			{
			print( 16);
			reset( oops);
			get( i.storm.brew);
	   		drop( i.fish.jar);
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
	set.string( 1, 2);				[	" " default blank string
	if (poem.line.count == 0)
		{
		overlay.pic( text.window);	[	pic.143 = overlay text box
		show.pic();
		set.string( 2, 4);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 2, 15, 1, 32);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 2, 13, 1, 32);
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
			get.string( 1, 2, 16, 1, 32);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 2, 14, 1, 32);
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
			get.string( 1, 2, 17, 1, 28);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 2, 15, 1, 28);
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
			get.string( 1, 2, 18, 1, 30);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 2, 16, 1, 30);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}
	set.text.attribute( text.color, bg.color);
	++poem.line.count;
	set.string( 1, 2);				[	" " default blank string
	set.string( 2, 2);				[	" " default blank string

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
	funny.death.loop = 1;			[	loop number of gag death
	}

