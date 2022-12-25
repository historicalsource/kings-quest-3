[ rm68.cg
[ The room with the well of souls


#include	"gamedefs.reh"
#include	"rm68.msg"

#define	hitBottom		lf0
#define	egoFalling	lf1


if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	set.horizon(48);
	map.area = map.daventry;
	set(beenIn68);

	landing.x = 99;
	landing.y = 89;
[ sounds
	load.sound(s.ego.falling);


	load.view(v.ego);
	load.view(v.ego.falling);

	load.view.f(current.ego);
	set.view.f(ego,current.ego);
	if (positionEgo){
		if (previous.room == 69){
			position(ego, 73, 55);
		}
	}

	if (drawEgo){
		draw(ego);
	}

	ignore.blocks(ego);		[ anti-princess block at edge of chasm

	if (girlSaved){
		load.logics(lgc.princess);
		call(lgc.princess);
	}

	show.pic();
	return();
}

[ princess dynamic
if (girlSaved){
	call(lgc.princess);
}


if (ego.poofing.done){
	ignore.blocks(ego);
}


[****** PICTURE LOGIC ******]

[ egoFalling in the chasm
if (!handsOff && hit.special && !egoFalling){
	set(handsOff);
	prevent.input();
	set(egoFalling);
	ignore.blocks(ego);
	get.priority(ego,work);
	set.priority.f(ego,work);
	set.view(ego,v.ego.falling);
	work = 4;
	cycle.time(ego,work);
	x = ego.x;
	y = 164;
	work = 4;
	move.obj.f(ego,x,y,work,hitBottom);
	sound(s.ego.falling, sound.done);
}

if (hitBottom){
	reset(hitBottom);
	erase(ego);
	set(certain.death);
	print(12);
	reset(handsOff);
	return();
}



[******** SAID STUFF ********]

if ((said(look, room) || said(look))){
	print(1);
}

if ((said(look, plant) || said(look,tree))){
	print(2);
}

if ( (said(look, flower) || said(get,flower))){
	print(3);
}

if (said(look, ground)){
	print(4);
}

if (said(look, sky)){
	print(5);
}
if (said(climb, tree)){
	print(6);
}
if ((said(look, well) || said(look$in, well) || said(climb, well))){
	print(7);
}
if ((said(look$in, chasm) || said(look, chasm) || said(look, over, chasm))){
	print(8);
}
if ((said(look, fence) || said(look, over, fence))){
	print(9);
}
if ((said(climb, fence) || said(climb, over, fence)
	|| said(jump, fence) || said(jump, over, fence))){
	print(10);
}
if ((said(jump, over, chasm) || 
	said(climb, chasm) || 
	said(climb, down, chasm) || 
	said(jump, down, chasm) || 
	said(go, across, chasm) || 
	said(jump, chasm))){
	print(11);
}


[ ****** PAINLESS ROOM EXITS ******

if (edge.ego.hit == top){	
	new.room(69);
}

if (edge.ego.hit == right){	
	new.room(61);
}

