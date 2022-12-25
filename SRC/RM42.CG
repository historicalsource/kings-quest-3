[logics for room -- 42: Bear's bedroom

%include "gamedefs.reh"
%include "rm42.msg"


#define	script			lv0
	#define	start	0
	#define	to.bed	1
	#define	at.bed	2
	#define	wake.up	3
	#define	carried	4
	#define	tossed	5
	#define	end		6

%define	movement			lv1
%define	m.none		0
%define	m.corner		1
%define	m.bedside		2
%define	m.jumping		3
%define	m.on.bed		4
%define	m.off.bed		5
%define	m.sleeping	6
%define	m.bouncing	7
%define	m.falling		8


%define	drawer.status		lv3
	%define	closed	0
	%define	open		1

%define	drawer.timer		lv4


#define	sleep.timer		lv5
#define	waking.x			lv6
#define	waking.y			lv7

#define	script.timer		lv8
%define	the.bed			lv9
	#define	papas.bed	1
	%define	mamas.bed	2
	%define	babys.bed	3

#define	snore.timer		lv10

%define	next				lf0
%define	snore.done		lf1
%define	ego.caught		lf2
%define	bed.time			lf3
%define	drawer.done		lf4
#define	by.drawer			lf5

%object	aBear		1
%object	a.drawer			2


if (init.log) {
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	wiz.x = 58;
	wiz.y = 115;

	landing.x = 68;
	landing.y = 122;
	
	set(interiorRoom);

	load.sound(s.snoring);
	load.sound(s.ego.falling);

	load.view(v.ego.hanging.in.kitchen);
	load.view(v.ego);
	load.view(v.ego.sleeping.l/r);
	load.view( v.ego.falling);

	load.view.f(current.ego);
	set.view.f(ego, current.ego);
	

	if (positionEgo){
		position(ego, 51, 116);
		set.loop(ego, 3);
	}

	if (current.status == deferred.entry){
		set.view(ego, v.ego);
		set(positionEgo);
		position.f(ego, landing.x, landing.y);
		set(drawEgo);
	}

	if (drawEgo) {
		draw( ego);
	}

[ the drawer 
	animate.obj(a.drawer);
	load.view(v.drawer.rm42);
	set.view(a.drawer, v.drawer.rm42);
	position(a.drawer, 96, 96);
	set.loop(a.drawer, 0);
	set.cel(a.drawer, 0);
	work = 2;
	cycle.time(a.drawer, work);
	draw(a.drawer);
	stop.update(a.drawer);

[ papa bear
	animate.obj(aBear);
	load.view(v.bear.papa);
	set.view(aBear, v.bear.papa);
	position(aBear, 49, 116);
	set.loop(aBear, 0);
	set.cel(aBear, 0);
[ don't draw him

	show.pic();
	return();

}

if (current.status == normal.ego){
	ego.location = nowhere;
	if (posn(ego, 94, 109, 101, 110)) {
		set(by.drawer);
	} else {
		reset(by.drawer);
	}
	
	if (posn(ego, 86, 129, 124, 165)) {
		ego.location = papas.bed;
	}
	
	if (posn(ego, 34, 143, 54, 165)) {
		ego.location = mamas.bed;
	}
	
	if (posn(ego, 85, 108, 111, 128)) {
		ego.location = babys.bed;
	}
}

[ sleeping around stuff

if (aSecondPassed && sleep.timer){
	--sleep.timer;
}

[ go bed ambiguity

if (current.status == entranced){
	if (have.input){
		print(19);
	}
}

if (current.status == sleeping){
	if (have.input && (said(wake, up) || 
		said(get$out, bed) ||
		said(get, up, bed) || 
		said(get, up, from, bed) || 
		said(get, up))){
		print(23);
		sleep.timer = 2;
		ego.location = papas.bed;		[ fake it out
	}
}

if (current.status == normal.ego && 
    (said(go, bed) || 
	said(lie, on, bed) ||
	said(lie, bed) ||
	said(try, out, bed) ||
	said(go, sleep) ||
	said(sleep, on, bed) ||
	said(sleep, bed) ||
	said(get$in, bed) || 
	said(get, on, bed))) {
	if (ego.location == nowhere){
		print(17);
	} else { 		[ who's bed
		set(handsOff);						[ reset when he gets up
		get.posn(ego, waking.x, waking.y);
		set.view(ego, v.ego.sleeping.l/r);
		set.cel(ego, 0);
		set.priority(ego, 15);
		current.status = sleeping;
		start.motion(ego);
		program.control();
		if (ego.location == papas.bed){
			reposition.to(ego, 100, 132);
			print(2);
			set.cel(ego, 2);
			set.loop(ego, 0);
			sleep.timer = 10;
		}
		if (ego.location == mamas.bed){
			reposition.to(ego, 32, 143);
			print(1);
			set.loop(ego, 1);
			sleep.timer = 10;
		}
		if (ego.location == babys.bed){
			reposition.to(ego, 87, 107);
			print(3);
			set.loop(ego, 0);
			sleep.timer = 10;
		}
	}
}

					
if (aSecondPassed && current.status == sleeping) {
	if (sleep.timer == 5){	[ first message
		if (ego.location == papas.bed){
			print(18);
		}
		if (ego.location == mamas.bed ) {
			print(25);
		}
		if (ego.location == babys.bed ) {
			work = 3;
			cycle.time(ego, work);
			print(22);
			snore.timer = 2;
			prevent.input();
		}
	}						   
	if (sleep.timer == 1){	[ second message
		if ((ego.location == papas.bed
			 || ego.location == mamas.bed )) {
			set.view(ego, v.ego);
			reposition.to.f(ego, waking.x, waking.y);
			release.priority(ego);
			current.status = normal.ego;
			reset(handsOff);
			player.control();
			reset(keep.cycling);
		} else {
			current.status = entranced;
			script = 0;
			script.timer = 10;
		}
	}
}

--snore.timer;
if (snore.timer == 1){
	sound(s.snoring, sound.done);
	set(keep.cycling);
	set.cel(ego, 0);
	end.of.loop(ego, snore.done);
}		

if (snore.done){
	reset(snore.done);
	snore.timer = SNOREDELAY;
	reset(keep.cycling);
}


[**** the bear script ****]

if (aSecondPassed && script.timer){
	--script.timer;
	if (script.timer == 0){
		set(next);
	}
}

if (next){
	program.control();
	prevent.input();
}


if (next && script == start) {
	reset(next);
	set(handsOff);
	++script;
[	position.to(aBear, 49, 116);
	draw(aBear);
	move.obj(aBear, 55, 110, 1, next);
}

if (next && script == to.bed) {
	reset(next);
	++script;
	move.obj(aBear, 95, 110, 1, next);
}

if (next && script == at.bed) {
	reset(next);
	++script;
	set.loop(aBear, facing.front);
	script.timer = 1;
}

if (next && script == wake.up) {
	reset(next);
	++script;
	print.at(20, 2, 2, 37);
[ now we wake up ego and tuck him under bears arm
	ignore.blocks(ego);
	ignore.objs(ego);
	set.view(ego, v.ego.hanging.in.kitchen);
	reset(keep.cycling);
	snore.timer = 0;
	move.obj(aBear, 55, 110, 1, next);
	current.status = normal.ego;
}

if (script == carried){
	get.posn(aBear, x ,y);
	x -= 7;
	y += 1;
	reposition.to.f(ego, x, y);
	get.priority(aBear, work);
	set.priority.f(ego, work);
}

if (next && script == carried) {
	reset(next);
	++script;
	set.loop(aBear, facing.front);
	stop.cycling(aBear);
	set.view(ego, v.ego.falling);
	sound(s.ego.falling, sound.done);
	set.priority(ego, 6);
	work = 1;
	cycle.time(ego, work);
	move.obj(ego, 48, 167, 4, next);
}

if (next && script == tossed) {
	player.control();
	++script;
	reset(next);
	current.status = normal.ego;
	reset(handsOff);
	player.control();
	accept.input();
	new.room(28);
}


[*****
[Get in their drawers
[*****

--drawer.timer;
if (drawer.timer == 1)
	{
	stop.update(a.drawer);
	if (drawer.status == open)
		{
		if (obj.in.room(i.thimble, current.room))
			{
			print(7);
			}
		else
			{
			print(14);
			}
		}
	}


[*****
[handle.input
[*****

if (have.input){

	if (said(look, bed)){
		if (ego.location == nowhere){
			print(15);
		}
		if (ego.location == papas.bed){
			print(27);
		}
		if (ego.location == mamas.bed){
			print(28);
		}
		if (ego.location == babys.bed){
			print(29);
		}
	}


	if ((said(open, drawer) ||
		said(open, chest) ||
		said(open, dresser, drawer)))
		{
		if (by.drawer)
			{
			if (drawer.status == open)
				{
				print(12);
				}
			else
				{
				start.update(a.drawer);
				end.of.loop(a.drawer, drawer.done);
				drawer.status = open;
				drawer.timer = 30;
				}
			}
		else					 [too far away
			{
			print(17);
			}
		}
 
	if ((said(close, drawer) ||
		said(close, chest) ||
		said(close, dresser, drawer)))
		{
		if (by.drawer)
			{
			if (drawer.status == closed)
				{
				print(9);
				}
			else
				{
				start.update(a.drawer);
				reverse.loop(a.drawer, drawer.done);
				drawer.status = closed;
				drawer.timer = 30;
				}
			}
		else				[too far away
			{
			print(16);
			}

		}

	if (said(look, under, bed)){
		if (ego.location == nowhere){
			print(17);
		} else {
			print(4);
		}
	}



	if (said(get, thimble)) {
		if (!obj.in.room(i.thimble, current.room)) {
			print(13);
		} else {
			if (!by.drawer){
				print(17);
			} else {
				if (drawer.status == closed){
					print(5);
				} else {
					print(8);
				}
				get(i.thimble);
				score += 1;
			}
		}
	}


	if (said(get, clothes)){
		print(26);
	}

	if ((said(look$in, drawer) || said(look, drawer))){
		if (by.drawer){
			if (drawer.status == closed) {
				print(21);
			} else {
				if (!obj.in.room(i.thimble, current.room)){
					print(11);
				} else {
					print(10);
				}
			}
		} else {
			print(17);
		}
	}

	if ((said(look) || said(look, room) ||
			said(look, bedroom) || said(look, house))){
		print(15);
	}

	if ((said(look, chest) ||
		said(look, dresser)))
		{
		print(16);
		}
	}
	

[*****
:exit							[	test for leaving the room
[*****

if (hit.special && current.status == normal.ego) {
	new.room(41);
}

