[ rm71.cg
[ front door of castle

#include	"gamedefs.reh"
#include	"rm71.msg"

#define	egoLoc			lv0
	#define	near.door	1


#define	at.door		lf0

if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);


	landing.x = 57;
	landing.y = 153;

	map.area = map.daventry;

	set(beenIn71);
	animate.obj(aDoor);
	load.view(v.door.castle);
	set.view(aDoor, v.door.castle);
	position(aDoor,104, 120);
	if (girlSaved){
		set.cel(aDoor, 2);	[ open
	} else {
		set.cel(aDoor, 0);	[ closed
	}
	draw(aDoor);
	stop.update(aDoor);

	animate.obj(banners);
	load.view(v.castle.banners);
	set.view(banners,v.castle.banners);
	ignore.horizon(banners);
	if (girlSaved){
		position(banners, 130, 16);
	} else {
		position(banners, 130, 34);
	}
	work = 3;
	cycle.time(banners, work);
	draw(banners);

	load.view.f(current.ego);
	set.view.f(ego,current.ego);
	if (positionEgo){
 		if (previous.room == 69){
			position(ego, 89, 164);
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
	if (girlSaved){
		move.obj(ego, 110, 120, 1, at.door);
		print(2);
		prevent.input();
	}
 	return();
}

[****** picture stuff ******


ego.location = nowhere;
if (posn(ego, 102, 119, 121, 126)){
	ego.location = near.door;
}


[ princess dynamic
if (girlSaved){
	call(lgc.princess);
}




[******** SAID STUFF ********]

if ((said(look) || 
	said(look, castle))){
	if (!girlSaved){
		print(1);
	} else {
		print(2);
	}
}

if ((said(look, door, castle) || 
	said(look, door))){
	if (!girlSaved){
		print(3);
	} else {
		print(4);
	}
}

if (said(speak, rol)){
	print(13);
}


if (said(open, door)){
	if (ego.location == near.door){
		print(5);
	} else {
		print(12);
	}
}

if (!girlSaved && (said(knock, door) || said(knock, on, door))){
	if (ego.location == near.door){
		print(6);
	} else {
		print(12);
	}
}

if (said(unlock, door) && !girlSaved){
	if (ego.location == near.door){
		print(7);
	} else {
		print(12);
	}
}
if (said(break, door) && !girlSaved){
	if (ego.location == near.door){
		print(8);
	} else {
		print(12);
	}
}



if (said(look, flag)){
	if (!girlSaved){
		print(9);
	} else {
		print(10);
	}
}

if ((said(climb, moat) || 
	said(jump, moat) || 
	said(jump, over, moat) || 
	said(climb, down, moat) || 
	said(look, across, moat) || 
	said(look, moat))){
	print( 11);
}


if (said(look, tree)){
	print( 14);
}

if (said(look, plant)){
	print( 15);
}

if ((said(climb, up, tree) || said(climb, tree))){
	print( 16);
}

if ((said(look, up, sky) || said(look, sky))){
	print( 17);
}

if ((said(look, on, ground) || said(look, ground))){
	print( 18);
}


[ ****** PAINLESS ROOM EXITS ******

if (edge.ego.hit == right){
	new.room( 72);
}

if (edge.ego.hit == bottom){
	new.room( 69);
}

[ entering castle
if (girlSaved && posn(ego,105, 121, 116, 122)){
	new.room(73);
}
