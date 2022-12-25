[ Room 78 - Standing on ladder to crows nest.
[ According to doco, this room has no reason to exist.
[ It will be coded as such

#include "rm78.msg"
#include "gamedefs.reh"


#define egoLoc		lv0
	#define	topOfMast		1
	#define	bottomOfMast	2

#define	snore.timer	lv1

#define hitBottom	lf0
#define attacking	lf1
[ sparkle flags

#define	sDone1	lf2
#define	sDone2	lf3
#define	sDone3	lf4
#define	sDone4	lf5

#define	swingDone	lf6
#define	slipped	lf7		[ as opposed to swatted at by pirate
#define	snore.done	lf8


if (init.log){

	map.area = map.ship;

	landing.x = 68;
	landing.y = 164;

[ nobody wizzes in this room
	wiz.x = 0;
	wiz.y = 0;

[ load in the seagulls and get them moving
	load.logics(lgc.seagulls);
	load.logics(lgc.pirates);


	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

[ sound stuff
	load.sound(s.ego.falling);
	load.sound(m.badguy);
	load.sound(s.snoring);

[ get in some sparkles
	load.view(v.sparkles);

	animate.obj(aSparkle1);
	random(0,159,x);
	random(140,164,y);
	position.f(aSparkle1,x,y);
	set.view(aSparkle1,v.sparkles);
	set.cel(aSparkle1,0);
	set.priority(aSparkle1, 4);
	draw(aSparkle1);
	end.of.loop(aSparkle1,sDone1);

	animate.obj(aSparkle2);
	random(1,159,x);
	random(140,164,y);
	position.f(aSparkle2,x,y);
	set.view(aSparkle2,v.sparkles);
	set.cel(aSparkle2,1);
	set.priority(aSparkle2, 4);
	draw(aSparkle2);
	end.of.loop(aSparkle2,sDone2);

	animate.obj(aSparkle3);
	random(0,159,x);
	random(126,140,y);
	position.f(aSparkle3,x,y);
	set.view(aSparkle3,v.sparkles);
	set.loop(aSparkle3,1);
	set.cel(aSparkle3,2);
	set.priority(aSparkle3, 4);
	draw(aSparkle3);
	end.of.loop(aSparkle3,sDone3);

	animate.obj(aSparkle4);
	random(0,159,x);
	random(126,140,y);
	position.f(aSparkle4,x,y);
	set.view(aSparkle4,v.sparkles);
	set.cel(aSparkle4,0);
	set.loop(aSparkle4,1);
	set.priority(aSparkle4, 4);
	draw(aSparkle4);
	end.of.loop(aSparkle4,sDone4);

	
[ the Jolly Roger
	load.view(v.skull.and.crossbones);
	set.view(aFlag, v.skull.and.crossbones);
	position(aFlag, 133, 89);
	animate.obj(aFlag);
	set.priority(aFlag, 5);
	draw(aFlag);
	y = 2;
	cycle.time(aFlag,y);

	animate.obj(aPirate);
	load.view(v.pirate.attacking);
	position(aPirate, 64,42);
	set.view(aPirate, v.pirate.attacking);
	set.priority(aPirate,14);
	y = 4;
	cycle.time(aPirate,y);
	if (crewAsleep){
		set.loop(aPirate, 1);
		snore.timer = SNOREDELAY;
	[ pirate for attacking
	} else {
		set.loop(aPirate, 0);
	}
	
	

[ set ego to climbing
	load.view(v.ego);
	load.view(v.ego.climbing.ladder);
	load.view(v.ego.falling);

	load.view.f(current.ego);
	set.view.f(ego, current.ego);

	set.priority(ego, 14);		[ in front of rope
	set.loop(ego,0);			[ back
	fix.loop(ego);

	if (positionEgo && current.status == climbing){
		position(ego, 68, 164);
	}

	if (current.status == deferred.entry){
		set.view(ego, v.ego.climbing.ladder);
		set(positionEgo);
		position.f(ego, landing.x, landing.y);
		set(drawEgo);
		current.status = climbing;
	}

	if (drawEgo){
		draw(ego);
	}

	[ adjust size of seagulls
	work = 0;
	if (shipShape == underWay){
		work = 1;
	}
	call(lgc.seagulls);

	show.pic();
	return();
}

call(lgc.pirates);

--snore.timer;
if (snore.timer == 1){
	sound(s.snoring, sound.done);
[	set.cel(aPirate, 0);
[	end.of.loop(aPirate, snore.done);
[}		

[if (snore.done){
	reset(snore.done);
	snore.timer = SNOREDELAY;
[	stop.cycling(aPirate);
}




if (sDone1){
	random(1,159,x);
	random(140,164,y);
	reposition.to.f(aSparkle1,x,y);
	set.cel(aSparkle1,0);
	end.of.loop(aSparkle1,sDone1);
}
if (sDone2){
	random(1,159,x);
	random(140,164,y);
	reposition.to.f(aSparkle2,x,y);
	set.cel(aSparkle2,0);
	end.of.loop(aSparkle2,sDone2);
}

if (sDone3){
	random(1,159,x);
	random(126,140,y);
	reposition.to.f(aSparkle3,x,y);
	set.cel(aSparkle3,0);
	end.of.loop(aSparkle3,sDone3);
}

if (sDone4){
	random(1,159,x);
	random(126,140,y);
	reposition.to.f(aSparkle4,x,y);
	set.cel(aSparkle4,0);
	end.of.loop(aSparkle4,sDone4);
}



if (ego.poofing.done && current.status == normal.ego){
	set.view(ego, v.ego.climbing.ladder);
	current.status = climbing;
	set.priority(ego, 14);		[ in front of rope
	set.loop(ego,0);			[ back
	fix.loop(ego);
}


[ set egoLoc
if (ego.y < 80){
	egoLoc = topOfMast;
} else {
	egoLoc = bottomOfMast;
}


[ getting attacked by the pirate at top of the mast

if (egoLoc == topOfMast && current.status == climbing && !crewAsleep){
	prevent.input();
	current.status = falling;	[ won't pass test again
	stop.motion(ego);
	set.cel(aPirate, 0);
	draw(aPirate);
	sound(m.badguy, sound.done);
	start.cycling(aPirate);
	end.of.loop(aPirate, swingDone);
}

[ end of pirate's swing
if (swingDone){
	reset(swingDone);
	goto DoTheFall;
}
		

[ check for falling off ladder

if (hit.special && current.status == climbing){
	set(slipped);				[ can also be pushed
:DoTheFall
	current.status = falling;
	sound(s.ego.falling, sound.done);
	release.loop(ego);
	set.view(ego, v.ego.falling);
	move.obj(ego, 68, 165, 4, hitBottom);
}

if (hitBottom){
	reset(hitBottom);
	erase(ego);
	set(certain.death);
	if (slipped){
		print(1);
	} else {
		print(14);
	}
}


[******** SAID STUFF ********]


if ((said(look) || 
	said(look, ship) || 
	said(look, down, ship))){
	print(2);
}

if ((said(look, land) || 
	said(look, water) || 
	said(look, ocean))){
	if (shipShape == nearLand){
		print(4);
	}
	if (shipShape == underWay){
		print(5);
	}
	if (shipShape == atBeach){
		print(6);
	}
}

if (shipShape == atBeach &&
   (said(look, beach) ||
	said(look, beach))){
	print(6);
}

	

if (said(look,mast)){
	print(7);
}


if ((said(look, up, flag) || said(look, flag))){
	print(15);
}

if ((said(look,crowsnest) || said(look$in, crowsnest))){
	if (crewAsleep){
		print(10);
	} else {
		print(9);
	}
}

if (said(look,pirate)){
	print(11);
}


if ((said(look, rope, ladder) || said(look, ladder))){
	print(3);
}

if ((said(look,sky) || said(look, up, sky))){
	if (shipShape == underWay){
		print(12);
	} else {
		print(13);
	}
}

call(lgc.seagulls);


[****** PAINLESS ROOM EXITS ********

if (edge.ego.hit && 
	(current.status == fly || current.status == eagle)){	[ flying exits
	if ((edge.ego.hit == top || edge.ego.hit == bottom)) {
		if (shipShape != atBeach){	[ lost at sea
			new.room(31);
		} else {
			new.room(48);
		}
	}
	if (edge.ego.hit == left){
		new.room(82);
	}
	if (edge.ego.hit == right){
		new.room(81);
	}
}


if (current.status == climbing && edge.ego.hit == bottom){
	new.room(80);
}
