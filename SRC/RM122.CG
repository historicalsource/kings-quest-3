[logics for room 122 -- spell #2 -- transforming into eagle or fly

%include	"rm122.msg"
%include	"gamedefs.al"
%include	"colors.h"
%include	"iv-names.h"



[	Oops is set upon every input.  If the entry is correct, it's reset.
[Spell.status is ++ every input.  Some questionable entries --spell.status, 
[to give him a "free round."



%define	overlay.pic.text.window	143

%define	ready.for.saffron		1
%define	ready.for.spell		2
%define	ready.for.wand			3
%define	times.up				4


%define	text.window				dv0



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


if ((said( put, pinch, saffron, essence) ||
	said( put, saffron, vial, essence) ||
	said( put, pinch, saffron, vial, essence) ||
	said( put, pinch, saffron, vial) ||
	said( put, saffron, essence) ||
	said( put, saffron, vial)))
	{
	if ((!has( i.saffron) ||
		!has( i.rose.essence)))
		{
		print( 1);
		}
	else
		{
		drop( i.saffron);
		print( 2);
		if (spell.status == ready.for.saffron)
			{
			reset( oops);
			++spell.status;		[	time for a poem
			}
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
		print( 3);
		if (spell.status == ready.for.wand)
			{
			drop( i.rose.essence);
			get( i.magic.essence);
			reset( oops);
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
			open.dialogue();
			get.string( 1, 9, 16, 1, 36);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 9, 14, 1, 36);
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
			open.dialogue();
			get.string( 1, 9, 17, 1, 33);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 9, 15, 1, 33);
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
			open.dialogue();
			get.string( 1, 9, 18, 1, 37);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 9, 16, 1, 37);
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
	funny.death.view = 38;			[	view number of gag death
	funny.death.loop = 1;			[	loop number of gag death
	}

