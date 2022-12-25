[logics for room 99 -- lgc.debug
[	February 3, 1988

%include	"gamedefs.al"
%include	"contrlrs.h"
%include	"rm-names.h"



%message	1	"New room:"
%message	2	"X coordinate:"
%message	3	"Y coordinate:"
%message	4	"Object number:"
%message	5	"Flag number:"
%message	6	"New value:"
%message	7	"Current room = %v0"
%message	8	"Variable number:"
%message	9	"Variable %v45 = %v46"
%message	10	"Flag %v45 set"
%message	11	"Flag %v45 not set"
%message	12	"New priority:"
%message	13	"Object %v46 is in room %v45."
%message	14	"%v45|3/%v46|3"
%message	15	"%v0|3"
%message	16	"He's sleeping."
%message	17	"Coming, Dear!"
%message	18	"He's dead."
%message	19	"He won't show up until you \"do chore.\""
%message	20	"Unknown wor  \""
%message	21	"%m20%w1\""
%message	22	"%m20%w2\""
%message	23	"%m20%w3\""
%message	24	"%m20%w4\""
%message	25	"%m20%w5\""
%message	26	"%m20%w6\""
%message	27	"%m20%w7\""
%message	28	"%m20%w8\""
%message	29	"H"
%message	30	" "
%message	31	"Done."
%message	32	" %v45|2 %o45"
%message	33	"(Sorry. Do the best you can!)"


if (init.log && monitor.type != mono)
	{
	display( 24, 26, 15);
	}


if (controller( c.inv.numbers))
	{
	set.text.attribute( bg.color, text.color);
	text.screen( );
	x = 0;
	y = 3;
	message = 32;
	debug.0 = 1;

	:mrLooper2;
	display.v( y, x, message);
	++debug.0;
	++y;
	if (debug.0 == 19)
		{
		x = 12;
		y = 3;
		}
	if (debug.0 == 37)
		{
		x = 26;
		y = 3;
		}
	if (debug.0 < size.of.inventory)
		{
		goto mrLooper2;
		}
	display( 23, 1, 33);

	:checkKb2;
	if (!have.key( ))
		{
		goto	checkKb2;
		}
	set.text.attribute( text.color, bg.color);
	graphics( );
	}


if (monitor.type != mono)
	{
	if (handsOff)
		{
		display( 24, 35, 29);
		}
	else
		{
		display( 24, 35, 30);
		}
	}



if (said( object, room))
	{
	get.num( 4, debug.1);
	get.room.f( debug.1, debug.0);
	print( 13);
	}

if (controller( c.show.mem))
	{
	show.mem();
	}

if ((controller( c.show.priority) ||
	said( show, priority)))
	{
	show.pri.screen();
	}

if (said( set, priority))
	{
	get.num( 12, debug.1);
	set.priority.f( ego, debug.1);
	}

if (said( release, priority))
	{
	release.priority( ego);
	}

if (said1(tp))
	{
	get.num( 1, debug.0);
	current.status = poofing;
	new.room.f( debug.0);
	}

if (said1(position))
	{
	get.num( 2, debug.0);
	get.num( 3, debug.1);
	erase( ego);
	position.f( ego, debug.0, debug.1);
	draw( ego);
	}

if ((controller( c.xy) ||
	said( show, position) || 
	said( sp)))
	{
	toggle( xy.on);
	clear.lines( 24, 24, 0);
	}

if ((controller( c.show.ego) ||
	said( where)))
	{
	debug.0 = 0;
	obj.status.f( debug.0);
	}

if ((controller( c.obj.info) ||
	said( show, object) ||
	said( object)))
	{
	get.num( 4, debug.0);
	if (debug.0 > 15)
		{
		debug.0 = 15;
		}
	obj.status.f( debug.0);
	}

if (said( get, object))
	{
	get.num( 4, debug.0);
	get.f( debug.0);
	}

if (said( show, flag))
	{
	get.num( 5, debug.0);
	if (isset.v( debug.0))
		{
		print( 10);
		}
	else {
		print( 11);
		}
	}

if (said( set, flag))
	{
	get.num( 5, debug.0);
	set.v( debug.0);
	}

if (said( reset, flag))
	{
	get.num( 5, debug.0);
	reset.v( debug.0);
	}

if (said( show, var))
     {
     get.num( 8, debug.0);
	debug.1 =@ debug.0;
	print( 9);
     }

if (said( set, var))
     {
     get.num( 8, debug.0);
     get.num( 6, debug.1);
     debug.0 @= debug.1;
     }

if ((said( room, number) ||
	said( room)))
	{
	print( 7);
	}

if (unknown.word)
	{
	if (unknown.word == 1)			{log( 21);}
	if (unknown.word == 2)			{log( 22);}
	if (unknown.word == 3)			{log( 23);}
	if (unknown.word == 4)			{log( 24);}
	if (unknown.word == 5)			{log( 25);}
	if (unknown.word == 6)			{log( 26);}
	if (unknown.word == 7)			{log( 27);}
	if (unknown.word > 7)			{log( 28);}
	}


[*****
:exit					[	the following are KQ3-exclusive patches:
[*****

if (xy.on && monitor.type != mono)
	{
	debug.0 = ego.x;
	debug.1 = ego.y;
	set.text.attribute( 6, 0);
	display( 24, 16, 14);
	set.text.attribute( text.color, bg.color);
	}


if (said( sleep, wizard))
	{
	if (monitor.type != mono)
		{
		display( 0, 0, 16);
		}
	wiz.status = sleeping;
	wiz.away.asleep = 4;
	wiz.minutes = 20;
	wiz.seconds = 0;
	}

if (said( here, wizard))
	{
	if (monitor.type != mono)
		{
		display( 0, 0, 17);
		}
	wiz.status = 0;
	wiz.minutes = 0;
	wiz.seconds = 0;
	if (chore.to.do)
		{
		print( 19);
		}
	}

if (said( do, chore))
	{
	if (monitor.type != mono)
		{
		display( 0, 0, 31);
		}
	chore.to.do = 0;
	chore.minutes = 0;
	chore.seconds = 0;
	}

if (said( bye, bye, wizard))
	{
	if (monitor.type != mono)
		{
		display( 0, 0, 18);
		}
	wiz.status = dead;
	wiz.minutes = 0;
	wiz.seconds = 0;
	}

if ((controller( c.gimme) ||
	said( gimme, gimme) ||
	said( set, up, spells)))
	{
	call( lgc.get.inventory);
	}

if (said( set, up, mountain))
	{
	call( lgc.setup.mountains);
	}

if (said( set, up, boat))
	{
	call( lgc.setup.boat);
	}

if (said( gimme, spells))
	{
	call( lgc.gimme.spells);
	}

if (said( wiz, status))
	{
	call( lgc.wiz.status);
	}

