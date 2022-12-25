[logics for room 92 -- lgc.wiz.status

[%include	"rm92.msg"
%include	"gamedefs.al"
%include	"colors.h"



%message	1	"Wiz is home, after his nap."
%message	2	"Wiz is in town."
%message	3	"Wiz is home, before bed."
%message	4	"Wiz is in nappy-poo land."
%message	5	"Wiz will change in %v84:%v83|2."

%message	6	"Last wiz temper was = %v129."
%message	7	"Wiz status = %v128."
%message	8	"You have %v110:%v109|2 without him to "
%message	9	"Wiz IS on screen."
%message	10	"Wiz IS NOT on screen."
%message	11	"%m8clean the kitchen."
%message	12	"%m8dump his crap."
%message	13	"%m8fix him din-din."
%message	14	"%m8dust his office."
%message	15	"%m8feed your chicks."

%message	16	"%m21cleaning the kitchen."
%message	17	"%m21dumping his crap."
%message	18	"%m21fixing din-din."
%message	19	"%m21dusting his office."
%message	20	"%m21feeding your chicks."
%message	21	"Your last chore was "

%message	22	"Make.wiz.come = %v123."
%message	23	"This room's wiz.x/y is %v32/%v31."
%message	24	"You've been in this room %v47 seconds."
%message	25	"A Few Interesting Statistics about"
%message	26	      "YOUR LITTLE WIZZER"
%message	27	"Current.status = %v44."
%message	28	""
%message	29	""



prevent.input();
status.line.off();
set.text.attribute( red, green);
text.screen();
last.char = 0;
reset( have.match);


display(  1,  3, 25);
display(  2, 11, 26);


work = wiz.away.asleep;
y = 5;
x = 1;
display.v( y, x, work);				[	Print wiz.away.asleep

display(  7,  1,  5);				[	Wiz will return in 3:34.

display(  9,  1,  7);				[	wiz status
display( 11,  1,  6);				[	wiz temper


if (chore.to.do)
	{
	work = chore.to.do;
	work += 10;
	y = 13;
	x = 1;
	display.v(  y, x, work);
	}
else
	{
	work = previous.chore;
	work += 15;
	y = 13;
	x = 1;
	display.v(  y, x, work);			[	print previous chore
	}

if (wiz.on.screen)
	{
	display( 16,  1,  9);			[	He IS on screen
	}
else
	{
	display( 16,  1, 10);			[	He IS NOT on screen
	}

display( 18,  1, 22);				[	Make wiz come
display( 19,  1, 23);				[	Wiz.x/y
display( 21,  1, 24);				[	Seconds in room
display( 23,  1, 27);				[	Current.status



:check.kb
if (!have.key())
	{
	goto	check.kb;
	}

accept.input();
status.line.on();
set.text.attribute( text.color, bg.color);
graphics();
set( have.match);

