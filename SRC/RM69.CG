[ rm69.cg
[ The room with the generic gnome


#include	"gamedefs.reh"
#include	"rm69.msg"

#define	script	lv0
#define	nextStep	lf0


if (init.log){

[	set(beenIn69);				[ deferred for a princess message
	map.area = map.daventry;
	set.horizon(45);

	landing.x = 50;
	landing.y = 100;

	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);
	set.horizon(64);

	load.sound(m.gnome);
	set(sound.done);

	load.view(v.ego);

	load.view.f(current.ego);
	set.view.f(ego,current.ego);
	if (positionEgo){
		if (previous.room == 71){
			position(ego, 37, 78);
		}
	}
	if (drawEgo){
		draw(ego);
	}

	if (girlSaved){
		load.logics(lgc.princess);
		call(lgc.princess);
	}

[ gnomish doings

	if (!gnomeGone){
		animate.obj(aGnome);
		load.view(v.gnome);
		set.view(aGnome, v.gnome);
		ignore.objs(aGnome);
		ignore.blocks(aGnome);
		work = 3;
		cycle.time(aGnome, work);
		set.priority(aGnome, 10);
		set.loop(aGnome, 0);		[ rocking
		position(aGnome, 81, 104);
		draw(aGnome);
		if (girlSaved){	[ start him leaving the room
			start.motion(ego);
			set.cel(aGnome, 0);
			end.of.loop(aGnome, nextStep); [ provide some delay
		}
	}

	show.pic();
	return();
}

[ princess dynamic
if (girlSaved){
	call(lgc.princess);
}

set(beenIn69);

[ gnome script

if (nextStep && script == 0){	[ get up and leave chair behind
	++script;
	start.cycling(aGnome);
	set.loop(aGnome, 1);
	fix.loop(aGnome);
	reposition.to(aGnome, 77, 105);
 	add.to.pic(v.gnome, 3, 0, 81, 104, 10, 0);	[ the chair
	work = 1;
	cycle.time(aGnome, work);
	move.obj(aGnome, 40, 124, 1, nextStep);
}

if (nextStep && script == 1){	[ walk to center of lane
	++script;
	print(19);
	set.loop(aGnome, 2);
	fix.loop(aGnome);
	move.obj(aGnome, 34, 61, 1, nextStep);
}

if (nextStep && script == 2){	[ walk out the top
	++script;
	reset(nextStep);
	erase(aGnome);
	set(gnomeGone);
}


[ erase my gnome and set gnomeGone

if (!gnomeGone && sound.done){
	sound(m.gnome, sound.done);
}


[******** SAID STUFF ********]

if ((said(look) || said(look, room) || said(look, house))){
	if (gnomeGone){
		print(2);
	} else {
		print(1);
	}
}

if ((said(look, fence) || 
	said(look, over, fence) || 
	said(climb, fence) || 
	said(jump, fence) || 
	said(jump, over, fence) || 
	said(climb, over, fence))){
	if (ego.x < 80){
		print(3);
	} else {
		print(4);
	}
}

if ((said(look, window) || said(look$in, window))){
	print(6);
}

if ((said(look, door) || said(look$in, door) || said(open, door))){
	print(7);
}

if (said(look ,castle)){
	print(8);
}
if ((said(look, porch) || said(look, man, porch))){
	if (gnomeGone){
		print(9);
	} else {
		print(10);
	}
}
if (said(look, man)){
	if (gnomeGone){
		print(11);
	} else {
		print(12);
	}
}

if (said(talk, man)){
	if (gnomeGone){
		print(13);
	} else {
		++gnomeTalk;
		if (gnomeTalk == 1){
		 	print(14);
			print(15);
			print(16);
		}
		if (gnomeTalk == 2){
			print(17);
		}
		if (gnomeTalk == 3){
			print(18);
			--gnomeTalk;
		}
	}
}


if ((said(climb, up , tree) || said(climb, tree))){
	print( 20);
}


if ((said(look, plant) || said(look,tree))){
	print(21);
}

if ( (said(look, flower) || said(get,flower))){
	print(22);
}

if (said(look, ground)){
	print(23);
}

if (said(look, sky)){
	print(24);
}

if (said(get, gnome)){
	if (gnomeGone){
		print(11);
	} else {
		print(25);
	}
}


[ ****** PAINLESS ROOM EXITS ******

if (edge.ego.hit == top){	
	new.room(71);
}

if (edge.ego.hit == 3){	
	new.room(68);
}


