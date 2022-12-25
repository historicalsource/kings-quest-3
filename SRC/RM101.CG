[logics for room 101 -- lgc.startup

%include	"gamedefs.al"
%include	"contrlrs.h"



%message	1	"_"
%message	2	"]"
%message	3	"KQ3"



set.cursor.char( 1);				[	cursor
set.string( 0, 2);   				[	prompt
set.game.id( 3);					[	id
trace.info( lgc.trace, 1, 6);			[	sets: room, y top, lines tall
set.text.attribute( text.color, bg.color);
max.score = 210;					[	set up the status line first
if (monitor.type != mono)
	{
	clear.lines( 22, 24, bg.color);
	}
configure.screen( 1, 23, 0);
set( enable.menu);
disable.item( c.dummy);
set( sound.on);
set( clock.on);


ego.step.size = 1;
ego.step.time = 1;
ego.cycle.time = 1;

one = 1;
two = 2;
three = 3;
four = 4;
five = 5;





[	test.room = 29;
[	if (test.room)
[		{
[		set( force.a.test);
[		reset( demo);
[		status.line.on();
[		animation.interval = fastest;
[		player.control();
[		accept.input();
[		wiz.minutes = wiz.init.minutes;
[		wiz.away.asleep = in.bed;
[		}

if (!test.room)
	{
	if (!restart.in.progress)		[	This sets up the demo loop:
		{
		set( demo);
		program.control();
		prevent.input();
		animation.interval = normal;
		reset( clock.on);
		reset( enable.menu);
		status.line.off();
		}
	else
		{
		enable.item( c.save);
		set( demo);
		status.line.on();
		return();
		}
	}


[	Assign keys to controller functions.
set.key( 0, 59, c.help);				[F1
set.key( 0, 60, c.sound.toggle);		[F2
set.key( 0, 61, c.echo.line);			[F3
set.key( 0, 62, c.show.obj);			[F4
set.key( 0, 63, c.save);				[F5
set.key( 0, 64, c.teleport);			[F6
set.key( 0, 65, c.restore);			[F7
set.key( 0, 66, c.leave.map);			[F8
set.key( 0, 67, c.restart);			[F9
set.key( 0, 68, c.speed);			[F10


[		Set control & alt keys.
if (machine.type == TANDY)
	{
	set.key( 43,  0, c.crescendo);	[+
	set.key( 61,  0, c.crescendo);	[=
	set.key( 45,  0, c.decrescendo);	[-
	}

set.key( 9,  0, c.status);			[TAB
if (machine.type == AMIGA)
	{
	set.key( 27,  0, c.pause);		[ESC
	}
else
	{
	set.key( 27,  0, c.menu);		[ESC
	}
set.key( 3,  0, c.cancel.line);		[^C
set.key( 5,  0, c.echo.line);			[^E
set.key( 10, 0, c.init.joy);			[^J
set.key( 18, 0, c.toggle.monitor);		[^R
set.key( 19, 0, c.sound.toggle);		[^S

[set.key( 0, 46, c.doit);				[@C
[set.key( 0, 32, c.debug);			[@D
[set.key( 0, 18, c.show.ego);			[@E
[set.key( 0, 23, c.obj.info);			[@I
set.key( 0, 50, c.show.mem);			[@M
[set.key( 0, 25, c.show.priority);		[@P
set.key( 0, 47, c.version);			[@V
[set.key( 0, 45, c.test);				[@X
set.key( 0, 44, c.quit);				[@Z


[		Substitute PCjr number keys as function keys.
if (machine.type == JR)				
	{
	set.key( 49, 0, c.help);			[1
	set.key( 50, 0, c.sound.toggle);	[2
	set.key( 51, 0, c.echo.line);		[3
[	set.key( 52, 0, cF4);			[4
	set.key( 53, 0, c.save);			[5
	set.key( 54, 0, c.teleport);		[6
	set.key( 55, 0, c.restore);		[7
	set.key( 56, 0, c.leave.map);		[8
	set.key( 57, 0, c.restart);		[9
	set.key( 48, 0, c.speed);		[0
	}


[	Set joystick controllers.
	if (machine.type == ST)
		{
		set.key(joystick.low.byte, button0, c.menu);
		set.key(joystick.low.byte, button0.double, c.status);
		set(enable.double.click);
		double.click.delay = 3;
		}
	else
		{
		set.key(joystick.low.byte, button0, c.menu);
		set.key(joystick.low.byte, button1, c.status);
		[set.key( joystick.low.byte, button0.double, c.doit);
		[set.key( joystick.low.byte, button1.double, c.useit);
		}

