[logics for room 49 -- treasure island
[ Logic:
[	if crewAsleep 
[		we are unhindered in efforts to get treasure
[	else
[		we always have company

%include "rm49.msg"
%include "gamedefs.reh"
#include	"iv-names.h"

#define	caughtEgo	lf0
#define	egoDead	lf2
#define	following	lf3
#define	pirateCaughtEgo	lf4
#define	ego.dead	lf5		[ killed by guard
#define	someoneHere	lf6
#define	first.said	lf7


if (init.log)
	{
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	load.sound(m.shark);
	reset(sound.done);

	load.logics(lgc.seagulls);
	load.logics(lgc.beach);
	load.logics(lgc.shovel);

[ misc
	set.horizon(70);
	map.area = map.mountains;
	set(beenIn49);
	landing.x = 20;
	landing.y = 74;

[ ego
	load.view(v.ego);
	load.view(v.ego.dead);
	load.view(v.ego.wading.deep);
	load.view(v.ego.swimming);
	load.view(v.ego.drowning);

	load.view.v(current.ego);
	set.view.f(ego, current.ego);

	if (positionEgo) {
		if (previous.room == 31) {
			[ the trap
		}
		if (previous.room == 48) {
			[ might need adjustment
		}
		if (previous.room == 51){
			ego.x = 114;
			position.f(ego, ego.x, ego.y);
		}
		if (previous.room == 50){
			ego.x = 24;
			position.f(ego, ego.x, ego.y);
		}
	}
	if (drawEgo) {
		draw(ego);
	}

[ the shark
	animate.obj(aShark);
	load.view(v.sharkfin);
	set.view(aShark,v.sharkfin);
	position(aShark,150,150)
	object.on.water(aShark);
	draw(aShark);
	wander(aShark);
[	set(following);

	if (shipShape == atBeach){
		set(tooBusyForMap);
		set(someoneHere);
		animate.obj(aPirate);
		load.view(v.pirate.guard);
		load.view(v.attacking);
		set.view(aPirate, v.pirate.guard);
		position(aPirate, 80, 120);
		object.on.land(aPirate);
		if ((invisibleEgo || current.status != normal.ego)) {
			wander(aPirate);
		} else {
			follow.ego(aPirate, 5, pirateCaughtEgo);
		}
		draw(aPirate);
		obj.on.land(aPirate);
	}




	work = 0;
	call(lgc.seagulls);
	call(lgc.beach);
	call(lgc.shovel);

	show.pic();
	sound(m.shark, sound.done);
	return();

}							[	end INIT.LOG




if (said(look, shark)){
	print(4);
}

if (said(get, shark)){
	print(3);
}

if (said(kill, shark)){
	print(9);
}
if (said(talk, shark)){
	print(5);
}


if (someoneHere && (said(get, man) || said(kill, man))){
	print(16);
}


if (someoneHere && said(look, man)){
	print(14);
}

if (someoneHere && said(talk, man)){
	print(15);
}





if (said(climb, tree)){
	print(10);
}

if ((said(look) || said(look, beach))){
	print(6);
}

if (said(look, mountain)){
	print(7);
}

if (said(look, tree)){
	print(11);
}


if (said(look, ground)){
	print(8);
}



if (ego.poofing.done && someoneHere) {		[ handle a state change
	if (current.status != normal.ego) {
		start.cycling(aPirate);
		wander(aPirate);
	} else {
		start.cycling(aPirate);
		follow.ego(aPirate, 5, pirateCaughtEgo);
	}
}
	
if (someoneHere && !first.said){
	set(first.said);
	print(1);
}



[ pirate business
if (pirateCaughtEgo){
	reset(pirateCaughtEgo);
	if (!handsOff){
		print(12);
		set(handsOff);
		program.control();
		set.view(aPirate, v.attacking);
		set.cel(aPirate,0);
		end.of.loop(aPirate,ego.dead);
	} else {
		stop.cycling(aPirate);
	}
}

if (ego.dead){
	reset(ego.dead);
	set.view(ego, v.ego.dead);
	set(certain.death);
	reset(handsOff);
}


[ shark business 
if (caughtEgo && (current.status == swimming || current.status == wading)) {
	reset(caughtEgo);
	if (!handsOff) {
		set(handsOff);
		erase(aShark);
		stop.motion(ego);
		set(keep.cycling);
		current.status = drowning;
		set.view(ego, v.ego.drowning);
		set.cel(ego, 0);
		work = 4;
		cycle.time(ego, work);
		end.of.loop(ego, egoDead);
	}
}

if (egoDead){
	reset(egoDead);
	erase(ego);
	set(certain.death);
	print(2);
}

if (( current.status == wading || current.status == swimming)){
	if (!following){
		set(following);
		follow.ego(aShark,8, caughtEgo);
	}
} else {
	reset(caughtEgo);		[ just in case
	if (following){
		reset(following);
		wander(aShark);
	}
}

[ try to keep shark looking good

if (obj.hit.edge == 4){	[ must change if obj number changes
	get.dir(aShark, work);
	if (edge.obj.hit == right){
		if (work == 2){
			work = 1;
		}
		if (work == 4){
			work = 5);
		}
		set.dir(aShark, work);
	}
	if (edge.obj.hit == left){
		if (work == 8){
			work = 1;
		}
		if (work == 6){
			work = 5);
		}
		set.dir(aShark, work);
	}
}



[ swimming/wading/walking stuff

if (hit.special){					[ surf line
	set(on.water);
	if (current.status == swimming){
		current.status = wading;
		set.view(ego, v.ego.wading.deep);
		reset(keep.cycling);
	}
	if (current.status == normal.ego){
		current.status = wading;
		set.view(ego, v.ego.wading.deep);
	}
}

if (current.status == wading && !on.water && !hit.special){	[ get him out
	current.status = normal.ego;
	set.view(ego, v.ego);
}

if (on.water && current.status == wading 
		&& (posn(ego, 118, 140, 160, 167) || posn(ego, 138, 84, 160, 167))){
	current.status = swimming;
	set.view(ego, v.ego.swimming);
	set(keep.cycling);
}

call(lgc.seagulls);
call(lgc.beach);
call(lgc.shovel);



[*****
:exit							[	test for leaving the room
[*****

if (edge.ego.hit == top){
	if ((current.status == swimming || current.status == wading)){
		set.view(ego, v.ego);
		current.view(ego, current.ego);
		reset(keep.cycling);
		current.status = normal.ego;
	}
	shipShape = departed;
	set(crewAsleep);
	if (ego.x > 76){
		new.room(51);
	}else {
		new.room(50);
	}
}


if (edge.ego.hit == left){
	new.room(48);
}


if ((edge.ego.hit == bottom || edge.ego.hit == right)){
	if ((current.status == swimming || current.status == wading)){
		set.view(ego, v.ego.swimming);
		current.view(ego, current.ego);
	}
	exit.edge = edge.ego.hit;
	new.room(31);
}
