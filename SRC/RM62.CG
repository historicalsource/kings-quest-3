[ rm62.cg
[ base of the stairs of the cave

#include	"gamedefs.reh"
#include	"rm62.msg"

#define	egoFalling	lf0
#define	hitBottom	lf1


if (init.log){
	map.area = map.clouds;
	set(beenIn62);
	set(interiorRoom);

	landing.x = 2;
	landing.y = 156;

	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	load.view(v.ego);
	load.view(v.ego.falling);
	load.view.f(current.ego);
	set.view.f(ego,current.ego);

[ sound stuff
	load.sound(s.ego.falling);
	load.sound(s.ego.stunned);

	if (positionEgo){
		if (previous.room == 61){
			start.motion(ego);
			position(ego,2,156);
		}
		if (previous.room == 63){
			position(ego, 117, 43);
		}
	}
	
	if (drawEgo){
		draw(ego);
	}

	if (girlSaved){
		load.logics(lgc.princess);
		call(lgc.princess);
	}

	show.pic();
	return();
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
	reset(handsOff);
	erase(ego);
	set(certain.death);
	print(5);
}


[ princess dynamic
if (girlSaved){
	call(lgc.princess);
}



[******** SAID STUFF ********]

if ((said(look, up) || said(look, down) || said(look) || said(look, cave))){
	print(1);
}
if ((said(look,up,stairs) || said(look,down, stairs) || said(look, stairs))){
	print( 2);
}
if (said(look, ground)){
	print(3);
}

if ((said(look, out) || said(look, out, cave))){
	print( 4);
}


[ ****** PAINLESS ROOM EXITS ******

if (ego.y < 40){
	new.room( 63);
}

if (edge.ego.hit == 4){
	new.room(61);
}


