[ rm67.cg
[ standing outside the cave at the top

#include	"gamedefs.reh"
#include	"rm67.msg"

#define	hitTimer	lv0

#define	script	lv10
#define	next		lf10


if (init.log){
	map.area = map.clouds;

	set.horizon(55);

	landing.x = 30;
	landing.y = 90;

	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

[ sound stuff
	load.sound(s.ego.falling);


	load.view.f(current.ego);
	set.view.f(ego,current.ego);
	if (positionEgo){
		if (previous.room == 64){
			position(ego, 123,102);
		}
	}
	if (drawEgo){
		draw(ego);
	}

	if (girlSaved){
		position(ego, 0, 105);
[		set(next);
		load.logics(lgc.princess);
		call(lgc.princess);
	}

	show.pic();
	return();
}

if (next && script == 0){
	++script;
	program.control();
	move.obj(ego, 160,105,1,next);
}




if (!beenIn67){
	set(beenIn67){
	print(8);
}


[ princess dynamic
if (girlSaved){
	call(lgc.princess);
}


if (spell.cast == sc.map){
	spell.cast = 0;
	drop(i.magic.map);
	print(12);
}


[****** PICTURE LOGIC ******]

if  (current.status == normal.ego && 	[	falling off the edge
    (ego.y > 162 ||
	edge.ego.hit == right ||
	edge.ego.hit == top))
	{
	print(10);
	sound(s.ego.falling, sound.done);
	erase(ego);
	hitTimer = 2;
	set.scan.start();
	if (aSecondPassed){
		--hitTimer;
	}
	if (!hitTimer){
		print(11);
		reset.scan.start();
		set(certain.death);
	}
	return();
}




[******** SAID STUFF ********]

if ((said(look) || said(look, cloud))){
	print(1);
}

if ((said(look,plant)	||
	said(look, tree)	||
	said(look, flower)	||
	said(pick, flower)	||
	said(climb,tree))){
		print(2);
}

if (said(look, ground)){
	print(3);
}

if (said(look, sky)){
	print(4);
}

if (said(look,ground)){
	print(5);
}

if (said(look, mountain)){
	print(6);
}

if (said(climb, mountain)){
	print(7);
}

if ((said(look, cave) || said(look$in, cave))){
	print(9);
}

[ ****** PAINLESS ROOM EXITS ******

if (hit.special){	[ inside cave mouth
	new.room( 64);
}

if (edge.ego.hit == 4){	[ left
	new.room( 66);
}


