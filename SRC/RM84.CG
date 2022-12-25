[ Room 84 - Forward crew compartment and lifeboat storage

#include "rm84.msg"
#include "gamedefs.reh"
#include	"iv-views.h"




#define	egoLoc		lv0
	#define	boatRoom	1
	#define	bunkRoom	2

#define	nearEgo		lv1
#define	entry.timer	lv2
#define	snore.timer	lv3

#define	pirate.here	lf0		[ visible
#define	snore.done	lf1
#define	fall.done		lf2
#define	chasing		lf3
#define	start.chase	lf4
#define	chase.ego		lf5
#define	caught.ego	lf6
#define	pirate.hiding	lf7


if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

[ external stuff to set up
	set(interiorRoom);
	map.area = map.ship;

	landing.x = 17;
	landing.y = 147;

	wiz.x = 0;
	wiz.y = 0;


	load.sound(s.ego.falling);
	load.sound(m.badguy);
	load.sound(s.snoring);


[ what about the shovel
if ((hasShovel || obj.in.room(i.shovel,current.room))){
	load.logics(lgc.shovel);		[ needs no init call
}

	load.logics(lgc.pirates);

if (obj.in.room(i.shovel,current.room)){
	animate.obj(aShovel);
	load.view(v.pirate.ship.shovel);
	set.view(aShovel, v.pirate.ship.shovel);
	stop.cycling(aShovel);
	ignore.blocks(aShovel);
	position(aShovel, 9, 131);
	draw(aShovel);
	stop.update(aShovel);
}


[ take care of ego
	load.view(v.ego);
	load.view(v.ego.falling);
	load.view(v.ego.dead);

	load.view.f(current.ego);
	set.view.f(ego, current.ego);


	if (current.status == poofing){
		ego.y = landing.y;
	}

	if (positionEgo){
		if (current.status == normal.ego){
	 		get.posn(ego, ego.x, ego.y);
			if (previous.room == 84) {
				if (ego.y > 128){
					ego.y = 150;
				} else {
					ego.y = 114;
				}
				position.f(ego, ego.x, ego.y);
	 		}
		}
		if (current.status == falling){
			set(handsOff);
			set.priority(ego, 13);
			ignore.blocks(ego);
			ignore.objs(ego);
			position(ego, 52, 75);
			move.obj(ego, 52, 155, falling.step.size, fall.done);
			sound(s.ego.falling, sound.done);
		}
	}
	if (current.status == deferred.entry){
		set.view(ego, v.ego);
		set(positionEgo);
		position.f(ego, landing.x, landing.y);
		set(drawEgo);
	}


	if (drawEgo){
		draw(ego);
	}

[ RULES FOR BEHAVIOR
[	1. A sleeping pirate cannot chase ego
[	2. No pirates in room when handsOff during init.log
[	3. A hiding pirate will not appear while handsOff
[	4. You cannot be caught while handsOff
[	5. A end.of.poof to fly freezes the pirate
 
[ the pirate
	animate.obj(aPirate);
	if (crewAsleep){
		set(pirate.here);
		snore.timer = SNOREDELAY;
		load.view(v.pirate.sleeping);
		set.view(aPirate, v.pirate.sleeping);
		set.priority(aPirate, 14);
		set.loop(aPirate, 0);
		work = 6;
		cycle.time(aPirate, work);
		position(aPirate, 95, 133);
		draw(aPirate);
	} else {
		set(tooBusyForMap);
		if (shipShape != atBeach){	[ he goes ashore with captain
			load.view(v.pirate.2);
			set.view(aPirate, v.pirate.2);
	 		random(1, 4, work);
			if (work > 2 && !handsOff){ 	[ here and now
				set(pirate.here);
				set(start.chase);
				x = 50;
				position.f(aPirate, x, ego.y);
				draw(aPirate);
			}
			if (work == 2 && !handsOff){			[ coming in later
				set(pirate.hiding);
				stop.cycling(aPirate);
				position(aPirate, 78,127);
			}
		}
	}

[ all done initing, show the picture
	show.pic();
	return();
}

[ set egoLoc to proper side of room

if (ego.x > 88){
	egoLoc = bunkRoom;
} else {
	egoLoc = boatRoom;
}

call(lgc.pirates);



[ sleeping pirate stuff
--snore.timer;
if (snore.timer == 1){
	sound(s.snoring, sound.done);
	set.cel(aPirate, 0);
	end.of.loop(aPirate, snore.done);
}		
if (snore.done){
	reset(snore.done);
	snore.timer = SNOREDELAY;
	set.cel(aPirate, 0);
	stop.cycling(aPirate);
}

[ RULES FOR BEHAVIOR (reprise)
[	1. A sleeping pirate cannot chase ego
[	2. No pirates in room when handsOff during init.log
[	3. A hiding pirate will not appear while handsOff
[	4. You cannot be caught while handsOff
[	5. A end.of.poof to fly freezes the pirate
 

[ starting the deferred pirate

distance(ego, aPirate, work);
if (!handsOff && pirate.hiding && work < 50){
	reset(pirate.hiding);
	set(pirate.here);
	set(start.chase);
	draw(aPirate);
	start.cycling(aPirate);
}

if (start.chase){
	reset(start.chase);
	set(chase.ego);
	print(14);
	sound(m.badguy, sound.done);
}

[ we are here and we should be trying to catch him
[ these are all the things that can go wrong

if (chase.ego){	
	if (ego.poofing.done){
		if (current.status == fly){
			print(18);
			stop.cycling(aPirate);
			normal.motion(aPirate);
			stop.motion(aPirate);
			reset(caught.ego);
		} else {
			reset(chasing);	[ let him start again
		}
	}
	if (!chasing && !handsOff){
		set(chasing);
		start.cycling(aPirate);
		follow.ego(aPirate, 8, caught.ego);
	}
}

[ This code must account for handsOff being set
if (caught.ego){
	reset(caught.ego);
	stop.cycling(aPirate);
	reset(chasing);
	if (!handsOff){
		print(7);
		set(tossed.in);
		new.room(85);
	}
}

[ falling stuff
if (fall.done){
	reset(fall.done);
	set.view(ego, v.ego.dead);
	reposition.to(ego, 52, 143);
	program.control();
	set(certain.death);
}



[ shovel loaded?  Yes, call it
if ((hasShovel || obj.in.room(i.shovel,current.room))){
	call(lgc.shovel);
}


[******** SAID STUFF ********]

if (said(look, pirate)){
	if (pirate.here){
		if (crewAsleep){
			if (egoLoc == bunkRoom){
				print(11);
			} else {
				print(8);
			}
		} else {
			print(9);
		}			
	} else {
		print(10);
	}
}

if ((said(look) || said(look, room))){
	if (egoLoc == bunkRoom){
		print(1);
	} else {		
		if (!obj.in.room(i.shovel,current.room)){
			print(2);
		} else {
			print(15);
		}
	}
}
if ((said(look, under) || said(look$in, boat) || said(look,boat))){
	if (egoLoc == bunkRoom){
		print(8);
	} else {		
		if (!obj.in.room(i.shovel,current.room)){
			print(3);
		} else {
			print(16);
		}
	}
}

if ((said(look$in, door) || said(look,out, door) || said(look, door)) ){
	if (egoLoc == bunkRoom) {
		print(12);
	} else {
		print(13);
	}
}


if ((said(look$in, bed) || said(look, on, bed) || said(look, bed))){
	if (egoLoc == bunkRoom){
		print(4);
	} else {		
		print(8);
	}
}

if ((said (lie, on, bed) || said (get, on, bed)
 || said(sleep, on, bed) || said(lie, bed)) ){
	if (egoLoc == bunkRoom){
		print(5);
	} else {		
		print(8);
	}
}





[******** PAINLESS ROOM EXITS **********]

if (edge.ego.hit == 4){
	new.room(83);
}


