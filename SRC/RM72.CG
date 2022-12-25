[ rm72.cg
[ standing outside the castle at right end of moat

#include	"gamedefs.reh"
#include	"rm72.msg"


if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	landing.x = 90;
	landing.y = 153;

	map.area = map.daventry;

	set(beenIn72);

	animate.obj(banners);
	load.view(v.castle.banners);
	set.view(banners,v.castle.banners);
	ignore.horizon(banners);
	if (girlSaved){
		position(banners, 5, 18);
	}else{
		position(banners, 5, 34);
	}
	draw(banners);

	load.view.f(current.ego);
	set.view.f(ego,current.ego);
	if (positionEgo){
		if (previous.room == 71){
			position(ego, 0, 153);
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

[ princess dynamic
if (girlSaved){
	call(lgc.princess);
}


[******** SAID STUFF ********]

if ((said(look) || said(look, castle))){
	if (!girlSaved){
		print(1);
	} else {
		print(2);
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

if (edge.ego.hit == left){
	new.room( 71);
}

if (edge.ego.hit == bottom){
	new.room( 69);
}


