[ rm65.cg
[ standing outside the cave at the top

#include	"gamedefs.reh"
#include	"rm65.msg"

#define	egoFalling	lf0
#define	hitTimer		lv0


if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	set(beenIn65);
	map.area = map.clouds;

	set.horizon(37);

	landing.x = 30;
	landing.y = 90;

	if (girlSaved){
		load.logics(lgc.princess);
	}

	load.view(v.ego);
	load.view(v.ego.falling);
	load.view.f(current.ego);
	set.view.f(ego,current.ego);

[ sound stuff
	load.sound(s.ego.falling);


	if (positionEgo){
	}

	if (drawEgo){
		draw(ego);
	}

	show.pic();
	if (girlSaved){
		call(lgc.princess);
	}
}


[****** PICTURE LOGIC ******]

if (current.status == normal.ego && edge.ego.hit == top){
	set(hit.special);
}

if (hit.special){	[falling off the edge
	print(5);
	erase(ego);
	hitTimer = 5;
	sound(s.ego.falling, sound.done);
	set.scan.start();
	if (aSecondPassed){
		--hitTimer;
	}
	if (!hitTimer){
		stop.sound();
		print(6);
		reset.scan.start();
		set(certain.death);
	}
	return();
}


[ princess dynamic
if (girlSaved){
	call(lgc.princess);
}


if (spell.cast == sc.map){
	spell.cast = 0;
	drop(i.magic.map);
	print(7);
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

if ((said(look, up) || 
	said(look, up, sky) || 
	said(look, sky))){
	print(4);
}

[ ****** PAINLESS ROOM EXITS ******

if (edge.ego.hit == 2){	[ right
	new.room( 66);
}


