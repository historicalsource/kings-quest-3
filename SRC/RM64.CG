[ rm64.cg -  top of cave stairs
[	February 29, 1988

#include	"gamedefs.reh"
#include	"rm64.msg"

#define	egoFalling	lf0
#define	hitBottom	lf1

#define	script	lv10
#define	next		lf10


if (init.log){
	set(beenIn64);
	map.area = map.clouds;
	set(interiorRoom);

	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	landing.x = 153;
	landing.y = 165;

	load.view(v.ego);
	load.view(v.ego.falling);
	load.view.f(current.ego);
	set.view.f(ego,current.ego);

[ sound stuff
	load.sound(s.ego.falling);

	if (positionEgo){
		if (previous.room == 67){
			position(ego,14,91);
		}
		if (previous.room == 63){
			position(ego, 153,165);
		}
	}

	if (drawEgo){
		draw(ego);
	}

	if (girlSaved){
		if (previous.room == 67){
			position(ego, 0, 88);
		}
		if (previous.room == 63){
			position(ego, 153,165);
		}

		load.logics(lgc.princess);
		call(lgc.princess);
	}

	show.pic();
	return();
}

if (next && script == 0){
	++script;
	program.control();
	move.obj(ego, 78, 88, 1, next);
}

if (next && script == 1){
	++script;
	program.control();
	move.obj(ego, 154, 168,1,next);
}







[******** PICTURE LOGIC ********]

[ egoFalling off the stairs
if (!handsOff && hit.special && !egoFalling){
	set(handsOff);
	prevent.input();
	set(egoFalling);
	ignore.blocks(ego);
	get.priority(ego,work);
	set.priority.f(ego,work);
	set.view(ego,v.ego.falling);
	sound(s.ego.falling, sound.done);
	work = 4;
	cycle.time(ego,work);
	x = ego.x;
	y = 164;
	work = 3;
	move.obj.f(ego,x,y,work,hitBottom);
}

if (hitBottom){
	reset(hitBottom);
	erase(ego);
	set(certain.death);
	print(5);
	reset(handsOff);
}

[ princess dynamic
if (girlSaved){
	call(lgc.princess);
}



[******** SAID STUFF ********]


if ((said(look, up) || 
	said(look, down) || 
	said(look) || 
	said(look, cave) ||
	said(look$in, cave))){
	print(1);
}
if ((said(look,up,stairs) || said(look,down, stairs) || said(look, stairs))){
	print( 2);
}

if ((said(look, out) || said(look, out, cave))){
	print( 3);
}


[ ****** PAINLESS ROOM EXITS ******

if ((edge.ego.hit == 2 || edge.ego.hit == 3)){
	new.room( 63);
}

if (edge.ego.hit == 4){
	new.room(67);
}


