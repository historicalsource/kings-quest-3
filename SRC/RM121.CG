[logics for room 121 -- Spell 1.  Understanding the language of creatures. 

%include	"rm121.msg"
%include	"gamedefs.al"
%include	"colors.h"
%include	"iv-names.h"



[	Oops is set upon every input.  If the entry is correct, it's reset.
[Spell.status is ++ every input.  Some questionable entries --spell.status, 
[to give him a "free round."



%define	overlay.pic.text.window		143

%define	ready.for.feather			1
%define	ready.for.hair				2
%define	ready.for.snake			3
%define	ready.for.fish.bone			4
%define	ready.for.dew				5
%define	ready.for.mixing			6
%define	ready.for.separation		7
%define	ready.for.balls.in.ears		8
%define	ready.for.spell			9
%define	ready.for.wand				10
%define	times.up					11


%define	put.eagle.feather			df1
%define	put.chicken.feather			df2
%define	which.hair				df3
%define	put.cat.hair				df4
%define	put.dog.hair				df5


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


if ((said( put, chicken, feather, bowl) ||
	said( put, one, chicken, feather, bowl)))
	{
	set( put.chicken.feather);
	}

if ((said( put, eagle, feather, bowl) ||
	said( put, one, eagle, feather, bowl)))
	{
	set( put.eagle.feather);
	}

if (said( put, feather, bowl))
	{
	if ((!has( i.chicken.feather) ||
		!has( i.bowl)))
		{
		print( 18);
		}
	else
		{
		if  (has( i.chicken.feather))
			{
			set( put.chicken.feather);
			}
		else
			{
			if (has( i.eagle.feather))
				{
				set( put.eagle.feather);
				}
			}
		}
	}
	
if (which.hair)
	{
	reset( which.hair);

	if ((said( cat) ||
		said( cat, hair)))
		{
		set( put.cat.hair);
		}

	if ((said( dog) ||
		said( dog, hair)))
		{
		set( put.dog.hair);
		}
	}

if (said( put, hair, bowl))
	{
	if  (!has( i.cat.hair) &&
		!has( i.dog.hair))
		{
		print( 18);
		}
	else
		{
		if  (has( i.cat.hair) &&
			has( i.dog.hair))
			{
			set( which.hair);
			reset( oops);
			--spell.status;		[	a freebie
			print( 22);
			}

		if (!which.hair)
			{
			if (has( i.dog.hair))
				{
				set( put.dog.hair);
				}

			if (has( i.cat.hair))
				{
				set( put.cat.hair);
				}
			}
		}
	}

if (said( put, cat, hair, bowl))
	{
	set( put.cat.hair);
	}

if (said( put, dog, hair, bowl))
	{
	set( put.dog.hair);
	}

if ((said( put, snake, skin, bowl) ||
	said( put, snake, bowl) ||
	said( put, snake$skin, bowl)))
   	{
	if (!has( i.snakeskin))
		{
		print( 29);
		}
	else
		{
		if (!has( i.bowl))
			{
			print( 18);
			}
		else
			{
			drop( i.snakeskin);
			print( 13);
			if (spell.status == ready.for.snake)
				{
				reset( oops);
				}
			}
		}
	}

if ((said( add, spoon, bone) ||
	said( add, bone, bowl) ||
	said( add, spoon, bone) ||
	said( add, spoon, bone, bowl) ||
	said( add, spoon, bone, bowl)))
	{
	if ((!has( i.fish.bone) ||
		!has( i.bowl)))
		{
		print( 18);
		}
	else
		{
		print( 16);
		drop( i.fish.bone);
		if (spell.status == ready.for.fish.bone)
			{
			reset( oops);
			}
		}
	}

if ((said( put, one, thimble, dew, bowl) ||
	said( put, thimble, dew, bowl) ||
	said( put, dew, bowl)))
	{
	if (!has( i.dew))
		{
		print( 18);
		}
	else
		{
		drop( i.dew);
		get( i.thimble);
		print( 19);
		if (spell.status == ready.for.dew)
			{
			reset( oops);
			}
		}
	}

if ((said( mix, hands) ||
	said( mix, mixture, hands) ||
	said( mix, mixture, bowl, hands) ||
	said( mix, with, hands) ||
	said( mix, mixture, with, hands) ||
	said( mix, mixture, bowl, with, hands)))
	{
	if (spell.status == ready.for.mixing)
		{
		print( 20);
		reset( oops);
		}
	else
		{
		reset( have.match);
		}
	}

if ((said( separate, mixture, two, pieces) ||
	said( separate, two, pieces) ||
	said( make, two, pieces) ||
	said( make, two, pieces, from, mixture) ||
	said( make, mixture, two, pieces) ||
	said( pull, mixture, two, pieces)))
	{
	if (spell.status == ready.for.separation)
		{
		print( 21);
		reset( oops);
		}
	else
		{
		reset( have.match);
		}
	}

if ((said( put, two, pieces, dough, ears) ||
	said( put, two, dough, pieces, ears) ||
	said( put, dough, pieces, ears) ||
	said( put, dough, ears) ||
	said( put, pieces, ears) ||
	said( put, pieces, dough, ears)))
	{
	if (spell.status == ready.for.balls.in.ears)
		{
		print( 23);
		reset( oops);
		++spell.status;			[	so cursor goes to graphics screen
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
		print( 18);
		}
	else
		{
		if (spell.status == ready.for.wand)
			{
			print( 25);
			reset( oops);
			get( i.dough.balls);
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
	set.string( 1, 27);				[	" " default blank string
	if (poem.line.count == 0)
		{
		overlay.pic( text.window);	[	pic.143 = overlay text box
		show.pic();
		set.string( 2, 5);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 27, 15, 1, 33);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 27, 13, 1, 33);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 1)
		{
		set.string( 2, 6);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 27, 16, 1, 29);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 27, 14, 1, 29);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 2)
		{
		set.string( 2, 7);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 27, 17, 1, 28);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 27, 15, 1, 28);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}

	if (poem.line.count == 3)
		{
		set.string( 2, 8);
		if (monitor.type == mono)
			{
			open.dialogue();
			get.string( 1, 27, 18, 1, 31);
				[string#, prompt, row, col, max length
			}
		else
			{
			get.string( 1, 27, 16, 1, 31);
			}

		if (compare.strings( 1, 2))
			{
			reset( oops);
			}
		}
	set.text.attribute( text.color, bg.color);
	++poem.line.count;
	set.string( 1, 27);				[	" " default blank string
	set.string( 2, 27);				[	" " default blank string

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

if (put.chicken.feather)
	{
	reset( put.chicken.feather);
	if ((!has( i.chicken.feather) ||
		!has( i.bowl)))
		{
		print( 18);
		}
	else
		{
		drop( i.chicken.feather);
		print( 4);
		if (spell.status == ready.for.feather)
			{
			reset( oops);
			}
		}
	}

if (put.eagle.feather)
	{
	reset( put.eagle.feather);
	if (!has( i.eagle.feather))
		{
		print( 18);
		}
	else
		{
		print( 3);
		}
	}

if (put.cat.hair)
	{
	reset( put.cat.hair);
	if (!has( i.cat.hair))
		{
		print( 18);
		}
	else
		{
		drop( i.cat.hair);
		print( 11);
		if (spell.status == ready.for.hair)
			{
			reset( oops);
			}
		}
	}	

if (put.dog.hair)
	{
	reset( put.dog.hair);
	if (!has( i.dog.hair))
		{
		print( 18);
		}
	else
		{
		drop( i.dog.hair);
		print( 12);
		if (spell.status == ready.for.hair)
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
	funny.death.loop = 0;			[	loop number of gag death
	}
