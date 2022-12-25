[ Room 79 - Galley at aft of ship.  Cook will be in here

#include "rm79.msg"
#include "gamedefs.reh"


#define	caughtEgo		lf0
#define	snore.done	lf1

#define	snore.timer	lv1


if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);
	load.logics(lgc.pirates);


[ external stuff
	set(interiorRoom);
	landing.x = 107;
	landing.y = 150;
	wiz.x = 70;
	wiz.y = 150;
	map.area = map.ship;


	load.sound(m.badguy);
	load.sound(s.snoring);

	load.view(v.ego);				[ get standard view
	set.view(ego,v.ego);
	load.view.f(current.ego);
	set.view.f(ego, current.ego);
	if (positionEgo){
		start.motion(ego);
		ego.dir = 7;
		if (ego.y > 120){
			position(ego,120,150);		[ down stage
		} else {
			position(ego,86,125);		[ upstage
		}
		get.posn(ego, ego.x, ego.y);
	} else {
		ego.y = landing.y;
	}


	if (drawEgo){
		draw(ego);
	}

	if (current.status == poofing){
		ego.y = landing.y;
	}


[ set a cook to wandering or sleeping
	animate.obj(aPirate);
	load.view(v.pirate.cook);
	load.view(v.pirate.sleeping);
	if (crewAsleep){
		snore.timer = SNOREDELAY;
		set.view(aPirate, v.pirate.sleeping);
		set.loop(aPirate, 2);
		work = 6;
		cycle.time(aPirate, work);
		set.priority(aPirate, 14);
		position(aPirate, 20, 152);
	} else {
		set(tooBusyForMap);
		work = 40;
		position.f(aPirate, work, ego.y);
		set.view(aPirate,v.pirate.cook);
		sound(m.badguy, sound.done);
		if (current.status == normal.ego) {
			follow.ego(aPirate, 10, caughtEgo);
		} else {
			stop.cycling(aPirate);
		}
	}
	draw(aPirate);

	show.pic();
	return();
}

--snore.timer;
if (snore.timer == 1){
	sound(s.snoring, sound.done);
	set.cel(aPirate, 0);
	end.of.loop(aPirate, snore.done);
}		

if (snore.done){
	reset(snore.done);
	snore.timer = SNOREDELAY;
	stop.cycling(aPirate);
}





call(lgc.pirates);

if (ego.poofing.done && !crewAsleep){
	if (current.status != normal.ego) {
		reset(caughtEgo);
		stop.cycling(aPirate);
		normal.motion(aPirate);
		stop.motion(aPirate);
	} else {
		start.cycling(aPirate);
		follow.ego(aPirate, 10, caughtEgo);
	}
}


[ catching ego (routines are order dependent)
if (caughtEgo){
	if (handsOff){
		stop.cycling(aPirate);
		normal.motion(aPirate);
		stop.motion(aPirate);
	} else {
		reset(caughtEgo);
		print(11);
		set(tossed.in);
		new.room(85);
	}
}




[******* SAID STUFF *******]

if ((said(look) || said(look,room) || said(look,ship))){
	print(1);
}

if (said(look, man)){
	if (!crewAsleep){
		print(3);
	} else {
		print(2);
	}
}

if (said(look, stove)){
	print(4);
}

if (said(look, pots)){
	print(5);
}
if (said(look, barrel)){
	print(6);
}
if (said(look, table)){
	print(7);
}
if (said(look, under,table)){
	print(8);
}
if ((said(sit, down) || said(sit, table)
	 || said(sit, down, table) || said(sit))){
	print(9);
}
if ((said(look, door) || said(look, out, door))){
	print(10);
}


[ position set in 80
if (hit.special){
	new.room(80);
}


