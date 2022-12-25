[logics for room -- 36:inside oracle's cave

%include "gamedefs.reh"
%include "rm36.msg"



#define	msg.delay				5	[ seconds of looping 'tween messages

%define	last.oracle.msg		6
%define	l.oracle.hazy			0
%define	l.oracle.fading		1
%define	l.oracle.speaking		1	[should be a third loop?

%define	l.colors				0
%define	l.colors.to.dragon		1

%define	l.dragon				0
%define	l.dragon.to.girl		1
%define	l.girl				2
%define	l.girl.to.colors		3

%define	rude.message.start		14
%define	rude.message.last		16


%define	oracle.msg			lv0
%define	cel.oracle			lv1
%define	rude.message.count		lv2
%define	loop.count			lv3

#define	script.timer			lv4
#define	script				lv5
	#define	floating		0
	#define	start		1
	#define	end			11

#define	cycle.dir				lv6
	#define	fwd	0
	#define	rvs	1

%define	oracle.mad			lf0
%define	oracle.speaks			lf1
%define	fade.done				lf2
%define	scene.change			lf3
%define	fade.oracle			lf4
#define	loop.done				lf5
#define	next					lf6
#define	first.msg				lf7
#define	on.screen				lf8
#define	ball.dead				lf9


%object	a.oracle				1	
%object	a.ball			2



if (init.log)
	{
	load.view.f(current.ego);
	set.view.f(ego, current.ego);

	load.view(v.oracle);
	load.view(v.crystal.ball.1);
	load.view(v.crystal.ball.2);

	load.sound(m.oracle);
	set(sound.done);

	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	oracle.msg = 1;
	rude.message.count = rude.message.start;

	wiz.x = 107;
	wiz.y = 0;			[if set to 0 prevents wiz from entering room

	landing.x = 70;
	landing.y = 140;

	set(interiorRoom);

	if (positionEgo)
		{
		position(ego, 72, 160);
		}

	if (drawEgo)					{draw( ego);}

	animate.obj(a.oracle);
	set.view(a.oracle, v.oracle);
	set.loop(a.oracle, l.oracle.hazy);
	fix.loop(a.oracle);
	position(a.oracle, 64, 82);
	work = 4;
	cycle.time(a.oracle, work);
	set.priority(a.oracle, 10);
	if (seen.oracle){
		script = 11;
		draw(a.oracle);
		set(next);
	} else {
[ oracle draw is deferred by 5 seconds
		start.motion(ego);
		set.loop(ego, facing.back);
		prevent.input();
		program.control();
		script.timer = 6;
	}


	animate.obj(a.ball);
	position(a.ball, 67, 102);
	set.view(a.ball, v.crystal.ball.1);
	work = 2;
	cycle.time(a.ball, work);
	set.loop(a.ball, l.colors);
	set.priority(a.ball, 11);


	draw(a.ball);

	show.pic();
	return();

	}


if (!first.msg){
	set(first.msg);
	print(18);
}

if (sound.done && !seen.oracle){
	sound(m.oracle, sound.done);
}


[ oracle runs on a script

if (aSecondPassed && script.timer){
	if (!handsOff){
		--script.timer;
	}
	if (script.timer == 0){
		set(next);
	}
}


if (next && script == floating){		[ floating around the room
	++script;
	set.cel(a.oracle, 0);
	draw(a.oracle);
	set(on.screen);
	end.of.loop(a.oracle, next);
}

if (next && script == start){
	reset(next);
	++script;
	script.timer = msg.delay;
	start.cycling(a.ball);
	stop.cycling(a.oracle);
	set(loop.done);			[ trigger first fade
	set.loop(a.oracle, 1);
}

if (next && script == 2){
	++script;
	reset(next);
	print.at(1,2,2,37);
	work = 5;
	cycle.time(a.ball, work);
	set.loop(a.ball, 1);
	set(next);
	start.cycling(a.oracle);
}


if (next && script == 3){
	++script;
	reset(next);
	print.at(2,2,2,37);
	set.view(a.ball, v.crystal.ball.2);
	set.loop(a.ball, 0);
	set.cel(a.ball, 0);
	end.of.loop(a.ball, next);
}

if (next && script == 4){
	++script;
	reset(next);
[	start.cycling(a.ball);
	set.loop(a.ball, 1);
	set.cel(a.ball, 0);
	end.of.loop(a.ball, next);
}

if (next && script == 5) {
	++script;
[	reset(next);
	print.at(3,2,2,37);
	loop.count = 0;
}
	
if (next && script == 6) {	[ three help me's
	++loop.count;
	if (loop.count > 3){
		++script;
	} else {
	[	start.cycling(a.ball);
		set.loop(a.ball, 2);
		set.cel(a.ball, 0);
		end.of.loop(a.ball, next);
	}
}

if (next && script == 7) {
	++script;
	reset(next);
	start.cycling(a.ball);
	set.loop(a.ball, 3);
	set.cel(a.ball, 0);
	end.of.loop(a.ball, next);
}

if (next && script == 8) {
	++script;
	reset(next);
	set.view(a.ball, v.crystal.ball.1);
	start.cycling(a.ball);
	work = 2;
	cycle.time(a.ball, work);
	set.loop(a.ball, 0);
	script.timer = msg.delay;
}

if (next && script == 9){
	++script;
	reset(next);
	print.at(5,2,2,37);
	script.timer = msg.delay);
}

if (next && script == 10){			[ this is the end of talking
	shipShape = inPort;			[ pirates come now
	++script;
	reset(next);
[	stop.cycling(a.ball);
	set.cel(a.ball, 0);
	print.at(6,2,2,37);
	set(seen.oracle);
	get(i.amber.stone);
	score += 3;
	script.timer = 2;
}

if (next && script == 11){			[ this is the end
	++script;
	set(on.screen);
	stop.cycling(a.oracle);
	set.loop(a.oracle, 0);
	last.cel(a.oracle, work);
	set.cel.f(a.oracle, work);
	set(next);
}

if (next && script == 12){
	++script;
	random(0, 1 ,work);
	work = 0;
	set.loop.f(a.ball, work);
	accept.input();
	player.control();
}

[ oracle floats around before you talk to him

[if (cycle.dir == fwd){
[	last.cel(a.oracle, work);
[	current.cel(a.oracle, x);
[	if (x == work){
[		cycle.dir = rvs;
[		reverse.cycle(a.oracle);
[	}
[} else {
[	current.cel(a.oracle, work);
[	if (work == 0){
[		cycle.dir = fwd;
[		normal.cycle(a.oracle);
[	}
[}

			

[*****
[handle.input
[*****

if (have.input) {
	if ((said(talk) || said(talk, oracle))) {
		if (!seen.oracle && !on.screen) {
			set(next);				[ start the script
		} else {
			print(8);
		}
	}

	if (said(get, oracle)){
		print(13);
	}

	if ((said(look) || said(look, cave) || said(look$in, cave))) {
		print(7);
	}

	if (said(look, oracle)) {
		if (!seen.oracle){
			print(9);
		} else {
			print(14);
		}
	}

	if ((said(look$in, crystal) || 
		said(look, crystal) || 
		said(look$in, ball) || 
		said(look, ball))) {
		print(10);
	}

	if ((said(break, ball) || 
		said(break, crystal) ||
		said(get, ball) || 
		said(get, crystal))) {
		print(11);
	}
			
	if ((said(look, outside) || said(look, outside, cave))) {
		print(12);
	}
	
	if (obj.in.room(i.knife, current.room) && said(get, knife)) {
		get(i.knife);
		print(13);
	}
}


[*****
[exit							[	test for leaving the room
[*****

if (edge.ego.hit == bottom) {
	new.room(14);
}

