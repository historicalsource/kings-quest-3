[ Room 80 - Aft deck of ship.  Hold and mast are visible

#include "rm80.msg"
#include "gamedefs.reh"


#define	stun.timer	lv0
#define	dest.x		lv1
#define	dest.y		lv2

#define	hitBottom		lf0		[ falling done flag
#define	onGangway		lf1		[ climbing the ladder tween decks
#define	fall.done		lf2
#define	toDeath		lf3


[ define base of ladder
#define	baseLeft		111
#define	baseTop		135
#define	baseCenter	113        
#define	baseRight		122
#define	baseBottom	147

[ left and right edges of ladder box (floor to ceiling)
#define	ladLeft		113
#define	ladRight		115



if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

[ external stuff

	map.area = map.ship;

	reset(interiorRoom);
	landing.x = 105;
	landing.y = 124;

	wiz.x = 87;
	wiz.y = 116;

	load.logics(lgc.seagulls);
	load.logics(lgc.pirates);


	load.view(v.ego);				[ get standard view
	load.view(v.ego.falling);
	load.view(v.ego.climbing.ladder);
	load.view(v.ego.dead);
	load.view(v.ego.stunned);

	load.view.f(current.ego);
	set.view.f(ego, current.ego);

[ sound stuff
	load.sound(s.ego.falling);
	load.sound(s.ego.stunned);


	if (current.status == climbing){		[ set ego to climbing and prepare to fall
		ignore.horizon(ego);
		ignore.blocks(ego);		[ ladder crosses p1 line
		if (previous.room == 78){	[ from above
			position(ego, ladLeft,31);
		} else {
			position(ego, ladLeft, 158);	[ from below
		}
		set.priority(ego,4);		[ behind ladder in this room
		set.view(ego, v.ego.climbing.ladder);
		set.loop(ego,1);			[ facing front
		fix.loop(ego);
	}
	if (current.status == normal.ego){			[ walking in
		set.view(ego,v.ego);
		if (previous.room == 0){
			position.f(ego, landing.x, landing.y);
		}
		if (previous.room == 81){
			position(ego,151,167);
		}
		if (previous.room == 79){
			start.motion(ego);
			ego.dir = 4;
			if (ego.y > 130){ 		[ down stage
				position(ego,48,127);
			} else {
				position(ego,73,117);
			}
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

	[ adjust size of seagulls
	work = 0;
	if (shipShape == underWay){
		work = 1;
	}
	call(lgc.seagulls);

	show.pic();

	return();
}

[ keep seagulls running
call(lgc.seagulls);
call(lgc.pirates);

[ force his loop on deck ladder

if (current.status == normal.ego){
	if (posn(ego,139, 128, 140, 157)){
		set.loop(ego,1);
		fix.loop(ego);
		set(onGangway);
	} else {
		if (onGangway){
			release.loop(ego);
			reset(onGangway);
		}
	}
}

[ rope ladder business

[ check for falling off ladder
if (current.status == climbing && !posn(ego, ladLeft, 0, ladRight, 167)){
	current.status = falling;
	set.view(ego, v.ego.falling);
	release.loop(ego);
	sound(s.ego.falling, sound.done);
[ Ok, he's falling, now where is going to land
	if (ego.y > 149){
		goto FallInHold;
	}
	if (ego.y > 40){	[ a stunning blow
		reset(toDeath);
		dest.x = ego.x;
		dest.y = 134;
	} else {			[ a killing blow
		set(toDeath);
		dest.x = ego.x;
		dest.y = 134;
	}
[ do a famous scan start
	work = falling.step.size;
	move.obj.f(ego, dest.x, dest.y, work, fall.done);
	set.scan.start();
	if (fall.done){
		program.control();
		reset(fall.done);
		observe.blocks(ego);
		stop.sound();
		if (toDeath){	[ he's dead now
			set.view(ego, v.ego.dead);
			current.status = dead;
			reposition.to(ego, 102, 126);
			reset.scan.start();
		} else {		[ stun the bastard
			set.view(ego, v.ego.stunned);
			reposition.to(ego, 105, 128);
			sound(s.ego.stunned, sound.done);
			stun.timer = ego.stunned.time;
			current.status = stunned;
			set(keep.cycling);
		[ re-limit the scan
			set.scan.start();
			if (aSecondPassed) {
				--stun.timer;
			}
			if (stun.timer && sound.done){
				sound(s.ego.stunned, sound.done);
			}
			if (!stun.timer) {
				stop.sound();
				reset(keep.cycling);
				player.control();
				reposition.to(ego, 109, 126);
				set.view(ego,v.ego);
				observe.blocks(ego);
				release.priority(ego);
				release.loop(ego);
				current.status = normal.ego;
				reset.scan.start();
			}
		}
	}
	return();
}



[ when ego is at base of the ladder we are faced with a few choices
[ Choices are based on direction that user is requesting
if (posn(ego, ladLeft, 136, ladRight, 150)){		[ at base
	if (current.status == climbing){
		if (ego.dir != 1 && ego.dir != 5 && ego.dir != 0) {		[ exit up right, down left
			current.status = normal.ego;
			release.loop(ego);
			observe.blocks(ego);
			observe.horizon(ego);
			release.priority(ego);		[ was 4 on ladder
			set.view(ego, v.ego);
			if (ego.dir > 5 ){ 	[ downstage
				reposition.to(ego, 110, 146);
			} else {
				reposition.to(ego, 117, 138);
			}
		}
	} else {
		if (current.status == normal.ego) {	[ put him back on the ladder
			current.status = climbing;
			start.motion(ego);		[ stop him
			ignore.horizon(ego);
			ignore.blocks(ego);		[ ladder crosses p1 line
			set.priority(ego,4);		[ behind ladder in this room
			set.view(ego, v.ego.climbing.ladder);
			set.loop(ego,1);			[ facing front
			fix.loop(ego);
			reposition.to(ego, ladLeft, 142);
		}
	}
}

[ falling in the hold
if ((hit.special || on.water) && current.status != falling){
:FallInHold
	sound(s.ego.falling, sound.done);
	current.status = falling;
	set.view(ego, v.ego.falling);
	ignore.blocks(ego);		[ ladder crosses p1 line
	set.priority(ego,4);		[ behind ladder in this room
	y = 166;
	x = 3;		[ rate of fall
	move.obj.f(ego, ego.x, y, x, hitBottom);
	goto DoFall;	[ go to falling scan
}
	

[******** SAID STUFF ********]
if ((said(look) || said(look,ship))){
	print(2);
}
if ((said(look, up, mast) || said(look, mast))){
	print(3);
}

if ((said(look, up, ladder) || said(look,ladder))){
	print(4);
}

if ((said(look, hold) || said(look$in, hold)
 || said(look$in, hole) || said(look,hole))){
	print(5);
}

if ((said(look$in, door) || said(look, door))){
	print(6);
}

if ((said(swim, ocean) || 
	said(go, ocean) || 
	said(get, ocean) || 
	said(jump) || 
	said(jump, ship) || 
	said(jump, ocean) || 
	said(swim) ||
	said(swim, water) || 
	said(go, water) || 
	said(get, water) || 
	said(jump) || 
	said(jump, ship) || 
	said(jump, water) || 
	said(swim))){
	print(7);
}

if (said(look, sky)){
	if (shipShape == underWay){
		print(12);
	} else {
		print(13);
	}
}
if ((said(look, land) || 
	said(look, water) || 
	said(look, ocean))){
	if (shipShape == nearLand){
		print(8);
	}
	if (shipShape == underWay){
		print(9);
	}
	if (shipShape == atBeach){
		print(10);
	}
}


if (shipShape == atBeach &&
   (said(look, beach) || said(look, beach))){
	print(10);
}


if (said(look, men)){
	print(11);
}



call(lgc.seagulls);


[ ******* PAINLESS ROOM EXITS **********

if (edge.ego.hit && 
	(current.status == fly || current.status == eagle)){		[ flying exits
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




[ exiting at top of ladder
if (current.status == climbing && edge.ego.hit == 1){
	new.room(78);
}


[ exit at bottom of ladder
if (current.status == climbing && edge.ego.hit == bottom){
	new.room(83);
}

[ exit at right/ bottom of room
if (edge.ego.hit == right){
	new.room(81);
}

[ going into galley at up left
if (current.status == normal.ego 
	 && (posn(ego, 68, 103, 73, 115) || posn(ego, 37, 122, 45, 131))){
	new.room(79);
}


return();


:DoFall	[ fall into the hold
set.scan.start();
if (hitBottom){
	reset.scan.start();
	erase(ego);
	new.room(83);
}
