[logics for room 89 -- rm.map

%include	"rm89.msg"
%include	"gamedefs.al"
%include	"contrlrs.h"



%define	map.1			131
%define	map.2			132
%define	map.3			133
%define	map.4			134

%define	x1L				3		[	area 1, leftmost x
%define	x2L				34
%define	x3L				65
%define	x4L				96
%define	x5L				127
%define	x1R				33		[	area 1, rightmost x
%define	x2R				64
%define	x3R				95
%define	x4R				126
%define	x5R				155

%define	y1				48		[	y of add.to.pic's
%define	y2				81
%define	y3				114
%define	y4				147

%define	cy1B				54		[	y for bottom of cursor
%define	cy2B				87
%define	cy3B				120
%define	cy4B				153
%define	cy1T				23		[	y for top of cursor
%define	cy2T				55
%define	cy3T				88
%define	cy4T				121


%define	ready.to.leave		lf0
%define	map.darkened		lf1


%define	map				lv0
%define	area				lv1
%define	old.area			lv2
%define	old.ego.view		lv3


%object	a.ship			1



if (init.log)
	{
	load.view.v( current.ego);		[	because I change ego back at end of room
	current.view( ego, old.ego.view);
	landing.y = 0;
	wiz.y = 0;
	set( handsOff);
	set.horizon( 1);


	load.view( v.ego.is.arrow);
	load.view( v.blank.map);

	map = map.1;					[	Llewdor
	if (beenIn77 && !beenIn48)
		{
		map = map.2;				[	blank map of ocean
		load.view( v.birdseye.ship);
		}

	if (beenIn48 && !beenIn61)
		{
		map = map.3;				[	mountain map
		}

	if (beenIn61)
		{
		map = map.4;				[	Daventry map
		}


	load.pic( map);
	draw.pic( map);
	discard.pic( map);
	

	if (map == map.1)
		{

		[
		[	11	12	13	14	15
		[	16	17	18	19	20
		[	21	22	23	24	25			MAP 1 LAYOUT
		[	26	27	28	29	30
		[

					[view, loop, cel, x, y, obj priority, box priority
		if (!beenIn11)		{add.to.pic( v.blank.map, 0, 0, x1L, y1, 4, 4);}
		if (!beenIn12)		{add.to.pic( v.blank.map, 0, 0, x2L, y1, 4, 4);}
		if (!beenIn13)		{add.to.pic( v.blank.map, 0, 0, x3L, y1, 4, 4);}
		if (!beenIn14)		{add.to.pic( v.blank.map, 0, 0, x4L, y1, 4, 4);}
		if (!beenIn15)		{add.to.pic( v.blank.map, 0, 0, x5L, y1, 4, 4);}

		if (!beenIn16)		{add.to.pic( v.blank.map, 0, 0, x1L, y2, 4, 4);}
		if (!beenIn17)		{add.to.pic( v.blank.map, 0, 0, x2L, y2, 4, 4);}
		if (!beenIn18)		{add.to.pic( v.blank.map, 0, 0, x3L, y2, 4, 4);}
		if (!beenIn19)		{add.to.pic( v.blank.map, 0, 0, x4L, y2, 4, 4);}
		if (!beenIn20)		{add.to.pic( v.blank.map, 0, 0, x5L, y2, 4, 4);}

		if (!beenIn21)		{add.to.pic( v.blank.map, 0, 0, x1L, y3, 4, 4);}
		if (!beenIn22)		{add.to.pic( v.blank.map, 0, 0, x2L, y3, 4, 4);}
		if (!beenIn23)		{add.to.pic( v.blank.map, 0, 0, x3L, y3, 4, 4);}
		if (!beenIn24)		{add.to.pic( v.blank.map, 0, 0, x4L, y3, 4, 4);}
		if (!beenIn25)		{add.to.pic( v.blank.map, 0, 0, x5L, y3, 4, 4);}

		if (!beenIn26)		{add.to.pic( v.blank.map, 0, 0, x1L, y4, 4, 4);}
		if (!beenIn27)		{add.to.pic( v.blank.map, 0, 0, x2L, y4, 4, 4);}
		if (!beenIn28)		{add.to.pic( v.blank.map, 0, 0, x3L, y4, 4, 4);}
		if (!beenIn29)		{add.to.pic( v.blank.map, 0, 0, x4L, y4, 4, 4);}
		if (!beenIn30)		{add.to.pic( v.blank.map, 0, 0, x5L, y4, 4, 4);}
		}


	if (map == map.2)
		{

		[	Compute x/y from voyage.minutes, assuming 17 minutes of travel,
		[68 Y down the map, 136 X across.  Therefore, in each minute we move
		[8x/4y.  Ending X/Y is 143/125.  Starting X/Y is 7/57.

		work  = voyage.minutes;
		work += voyage.minutes;
		work += voyage.minutes;
		work += voyage.minutes;		[	Y = minutes traveled times 4
		if (shipShape == underWay)
			{
			work += 12;			[   compensate for !nearLand (4yx3min)
			}
		y = 125;					[	125 is the ending Y
		y -= work;

		x = 143;					[	143 is our ending X
		work += work;				[	X = 2Y
		x -= work;

		if ((x > 143 ||
			shipShape == atBeach))
			{
			x = 143;
			y = 125;
			}

		animate.obj( a.ship);
		set.view( a.ship, v.birdseye.ship);
		position.v( a.ship, x, y);
		set.priority( a.ship, 4);
		ignore.objs( a.ship);
		draw( a.ship);
		}
	

	if (map == map.3)
		{

		[
		[		54	55	56
		[	52	53		57	58
		[	51				59			MAP 3 LAYOUT
		[	49				61
		[

		if (!beenIn54)		{add.to.pic( v.blank.map, 0, 0, x2L, y1, 4, 4);}
		if (!beenIn55)		{add.to.pic( v.blank.map, 0, 0, x3L, y1, 4, 4);}
		if (!beenIn56)		{add.to.pic( v.blank.map, 0, 0, x4L, y1, 4, 4);}

		if (!beenIn52)		{add.to.pic( v.blank.map, 0, 0, x1L, y2, 4, 4);}
		if (!beenIn53)		{add.to.pic( v.blank.map, 0, 0, x2L, y2, 4, 4);}
		if (!beenIn57)		{add.to.pic( v.blank.map, 0, 0, x4L, y2, 4, 4);}
		if (!beenIn58)		{add.to.pic( v.blank.map, 0, 0, x5L, y2, 4, 4);}

		if (!beenIn51)		{add.to.pic( v.blank.map, 0, 0, x1L, y3, 4, 4);}
		if (!beenIn59)		{add.to.pic( v.blank.map, 0, 0, x5L, y3, 4, 4);}

		if (!beenIn49)		{add.to.pic( v.blank.map, 0, 0, x1L, y4, 4, 4);}
		if (!beenIn61)		{add.to.pic( v.blank.map, 0, 0, x5L, y4, 4, 4);}
		}
	

	if (map == map.4)
		{

		[
		[	65	66	67	64	
		[		71	72		63
		[		69		62				MAP 4 LAYOUT
		[		68	61
		[

		if (!beenIn65)		{add.to.pic( v.blank.map, 0, 0, x1L, y1, 4, 4);}
		if (!beenIn66)		{add.to.pic( v.blank.map, 0, 0, x2L, y1, 4, 4);}
		if (!beenIn67)		{add.to.pic( v.blank.map, 0, 0, x3L, y1, 4, 4);}
		if (!beenIn64)		{add.to.pic( v.blank.map, 0, 0, x4L, y1, 4, 4);}

		if (!beenIn71)		{add.to.pic( v.blank.map, 0, 0, x2L, y2, 4, 4);}
		if (!beenIn72)		{add.to.pic( v.blank.map, 0, 0, x3L, y2, 4, 4);}
		if (!beenIn63)		{add.to.pic( v.blank.map, 0, 0, x5L, y2, 4, 4);}

		if (!beenIn69)		{add.to.pic( v.blank.map, 0, 0, x2L, y3, 4, 4);}
		if (!beenIn62)		{add.to.pic( v.blank.map, 0, 0, x4L, y3, 4, 4);}

		if (!beenIn68)		{add.to.pic( v.blank.map, 0, 0, x2L, y4, 4, 4);}
		if (!beenIn61)		{add.to.pic( v.blank.map, 0, 0, x3L, y4, 4, 4);}
		}
	

	set.view( ego, v.ego.is.arrow);
	release.priority( ego);
	position( ego, 77, 77);
	start.motion( ego);

	ego.cycle.time = 1;
	cycle.time( ego, ego.cycle.time);
	ego.step.time = 1;
	step.time( ego, ego.step.time);
	ego.step.size = 1;
	step.size( ego, ego.step.size);

	draw( ego);


	show.pic();
	if (map == map.1)
		{
		if (beenIn18)
			{
			print( 4);
			}
		else
			{
			print( 7);
			}
		}

	print( 8);

	return();

	}							[	end INIT.LOG


[*****
:wear.da.fughawee?
[*****

area = 0;

if (map == map.1)
	{

		[
		[	11	12	13	14	15
		[	16	17	18	19	20
		[	21	22	23	24	25			MAP 1 LAYOUT
		[	26	27	28	29	30
		[

	if (beenIn11 && posn( ego, x1L, cy1T, x1R, cy1B))		{area = 11;}
	if (beenIn12 && posn( ego, x2L, cy1T, x2R, cy1B))		{area = 12;}
	if (beenIn13 && posn( ego, x3L, cy1T, x3R, cy1B))		{area = 13;}
	if (beenIn14 && posn( ego, x4L, cy1T, x4R, cy1B))		{area = 14;}
	if (beenIn15 && posn( ego, x5L, cy1T, x5R, cy1B))		{area = 15;}

	if (beenIn16 && posn( ego, x1L, cy2T, x1R, cy2B))		{area = 16;}
	if (beenIn17 && posn( ego, x2L, cy2T, x2R, cy2B))		{area = 17;}
	if (beenIn18 && posn( ego, x3L, cy2T, x3R, cy2B))		{area = 18;}
	if (beenIn19 && posn( ego, x4L, cy2T, x4R, cy2B))		{area = 19;}
	if (beenIn20 && posn( ego, x5L, cy2T, x5R, cy2B))		{area = 20;}

	if (beenIn21 && posn( ego, x1L, cy3T, x1R, cy3B))		{area = 21;}
	if (beenIn22 && posn( ego, x2L, cy3T, x2R, cy3B))		{area = 22;}
	if (beenIn23 && posn( ego, x3L, cy3T, x3R, cy3B))		{area = 23;}
	if (beenIn24 && posn( ego, x4L, cy3T, x4R, cy3B))		{area = 24;}
	if (beenIn25 && posn( ego, x5L, cy3T, x5R, cy3B))		{area = 25;}

	if (beenIn26 && posn( ego, x1L, cy4T, x1R, cy4B))		{area = 26;}
	if (beenIn27 && posn( ego, x2L, cy4T, x2R, cy4B))		{area = 27;}
	if (beenIn28 && posn( ego, x3L, cy4T, x3R, cy4B))		{area = 28;}
	if (beenIn29 && posn( ego, x4L, cy4T, x4R, cy4B))		{area = 29;}
	if (beenIn30 && posn( ego, x5L, cy4T, x5R, cy4B))		{area = 30;}
	}


if (map == map.2)
	{
	distance( ego, a.ship, work);
	get.posn( a.ship, x, y);
	--x;
	if (work < 14 && ego.x > x)
		{
		random( 79, 86, area);		[	on board ship
		}
	else
		{
		area = 31;				[	splash!
		}
	}


if (map == map.3)
	{

		[
		[		54	55	56
		[	52	53		57	58
		[	51				59			MAP 3 LAYOUT
		[	49				61
		[

	if (beenIn54 && posn( ego, x2L, cy1T, x2R, cy1B))		{area = 54;}
	if (beenIn55 && posn( ego, x3L, cy1T, x3R, cy1B))		{area = 55;}
	if (beenIn56 && posn( ego, x4L, cy1T, x4R, cy1B))		{area = 56;}

	if (beenIn52 && posn( ego, x1L, cy2T, x1R, cy2B))		{area = 52;}
	if (beenIn53 && posn( ego, x2L, cy2T, x2R, cy2B))		{area = 53;}
	if (beenIn57 && posn( ego, x4L, cy2T, x4R, cy2B))		{area = 57;}
	if (beenIn58 && posn( ego, x5L, cy2T, x5R, cy2B))		{area = 58;}

	if (beenIn51 && posn( ego, x1L, cy3T, x1R, cy3B))		{area = 51;}
	if (beenIn59 && posn( ego, x5L, cy3T, x5R, cy3B))		{area = 59;}

	if (beenIn49 && posn( ego, x1L, cy4T, x1R, cy4B))		{area = 49;}
	if (beenIn61 && posn( ego, x5L, cy4T, x5R, cy4B))		{area = 61;}
	}


if (map == map.4)
	{

		[
		[	65	66	67	64	
		[		71	72		63
		[		69		62				MAP 4 LAYOUT
		[		68	61
		[

	if (beenIn65 && posn( ego, x1L, cy1T, x1R, cy1B))		{area = 65;}
	if (beenIn66 && posn( ego, x2L, cy1T, x2R, cy1B))		{area = 66;}
	if (beenIn67 && posn( ego, x3L, cy1T, x3R, cy1B))		{area = 67;}
	if (beenIn64 && posn( ego, x4L, cy1T, x4R, cy1B))		{area = 64;}

	if (beenIn71 && posn( ego, x2L, cy2T, x2R, cy2B))		{area = 71;}
	if (beenIn72 && posn( ego, x3L, cy2T, x3R, cy2B))		{area = 72;}
	if (beenIn63 && posn( ego, x5L, cy2T, x5R, cy2B))		{area = 63;}

	if (beenIn69 && posn( ego, x2L, cy3T, x2R, cy3B))		{area = 69;}
	if (beenIn62 && posn( ego, x4L, cy3T, x4R, cy3B))		{area = 62;}

	if (beenIn68 && posn( ego, x2L, cy4T, x2R, cy4B))		{area = 68;}
	if (beenIn61 && posn( ego, x3L, cy4T, x3R, cy4B))		{area = 61;}
	}


[*****
:handle.input
[*****

if ((said( take, me, there) ||
	said( take, me, here) ||
	said( magic, map, fly, me, there) ||
	said( magic, map, fly, me, here) ||
	said( fly, me, here) ||
	said( fly, me, there) ||
	said( magic, map, take, me, there) ||
	said( magic, map, take, me, here) ||
	said( go, there) ||
	said( go, here)))
	{
	set( ready.to.leave);
	}

if ((said( look, room) ||
	said( look, back, room) ||
	said( look) ||
	said( look, away) ||
	said( look, up) ||
	said( look, away, from, map) ||
	said( stop, look, map) ||
	said( stop, look, magic, map) ||
	said( stop, magic, map) ||
	said( return, room) ||
	said( go, back, room)))
	{
	set( ready.to.leave);
	area = previous.room;
	}


[*****
:no.input
[*****

if ((controller( c.show.priority) ||
	controller( c.teleport)))
	{
	set( ready.to.leave);
	}

if ((controller( c.show.mem) ||
	controller( c.leave.map)))
	{
	set( ready.to.leave);
	area = previous.room;
	}

if (controller( c.help))
	{
	print( 8);
	}


[*****
:exit
[*****

if (ready.to.leave)
	{
	reset( ready.to.leave);

	if (!area)
		{
		print( 2);
		}
	else
		{
		print( 1);
		erase( ego);
		set.view.v( ego, old.ego.view);   
		current.ego = old.ego.view;
		reset( handsOff);
		
		if (area == previous.room)
			{
			current.status = deferred.entry;
			}
		else
			{
			current.status = poofing;
			}

		if (monitor.type != mono)
			{
			clear.lines( 22, 22, bg.color);
			}
		new.room.v( area);
		}
	}

