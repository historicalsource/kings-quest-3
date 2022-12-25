[ Room 81 - Foredeck of ship.  Open hold in middle
[	February 19, 1988

#include "rm81.msg"
#include "gamedefs.reh"


#define	nearEgo		lv0
#define	dest.room		lv1
#define	entry.timer	lv2
#define	snore.timer	lv3

#define	caughtEgo		lf0
#define	fall.done		lf1
#define	pirate.here	lf2
#define	chasing		lf3
#define	snore.done	lf4



if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	load.sound(s.ego.falling);
	load.sound(m.badguy);
	load.sound(s.snoring);

	load.logics(lgc.seagulls);
	load.logics(lgc.pirates);

	reset(interiorRoom);
	map.area = map.ship;

	landing.x = 37;
	landing.y = 125;

	wiz.x = 95;
	wiz.y = 127;

	animate.obj(aPirate);
	load.view(v.pirate.sleeping);
	load.view(v.pirate.1);

[ how do we handle this pirate

	if (crewAsleep){
		snore.timer = SNOREDELAY;
		set.view(aPirate, v.pirate.sleeping);
		position(aPirate, 49, 114);
		set.loop(aPirate, 1);
		work = 6;
		cycle.time(aPirate, work);
		set(pirate.here);
		draw(aPirate);
	} else {
		set.view(aPirate, v.pirate.1);
 		random(1, 3, work);
		if (handsOff){	[ don't want to handle this
			work = 1;
		}
		if (work == 1){	[ not here
			reset(pirate.here);
		}
		if (work == 2){	[ here and now
			set(pirate.here);
			position(aPirate, 49, 112);
			follow.ego(aPirate, 5, caughtEgo);
		}
		if (work == 3){	[ coming in later
			reset(pirate.here);
			position(aPirate, 1, 158);
			random(5, 15, entry.timer);
		}
		if (pirate.here){
			draw(aPirate);
			sound(m.badguy, sound.done);
		}
	}

[ take care of ego
	load.view(v.ego);
	load.view(v.ego.falling);

	load.view.f(current.ego);
	set.view.f(ego, current.ego);

	ignore.blocks(ego);

	if (positionEgo){
		position(ego,1,145);
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
call(lgc.pirates);

[ handle an end of poof to human
if (ego.poofing.done && current.status == normal.ego){
	ignore.blocks(ego);
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





if (ego.poofing.done && !crewAsleep){
	if (pirate.here){
		if (current.status != normal.ego) {
			reset(caughtEgo);
			stop.cycling(aPirate);
			normal.motion(aPirate);
			stop.motion(aPirate);
			print(13);
		} else {
			ignore.blocks(ego);
			start.cycling(aPirate);
			follow.ego(aPirate, 5, caughtEgo);
		}
	} else {
		entry.timer = 0;
	}
}

if (ego.y < 114 && entry.timer){	[ force the entrance
	entry.timer = 1;
}


[ starting a pirate following
if (aSecondPassed && entry.timer){
	--entry.timer;
	if (entry.timer == 0){
		set(pirate.here);
		draw(aPirate);
		sound(m.badguy, sound.done);
	}
}


if (!crewAsleep && pirate.here && current.status == normal.ego && !chasing){
	set(chasing);
	follow.ego(aPirate, 5, caughtEgo);
}



[ let pirate catch ego if he can
if (caughtEgo){
	reset(caughtEgo);
	normal.motion(aPirate);
	stop.motion(aPirate);
	stop.cycling(aPirate);

	if (!handsOff){
		print( 1);
		set( tossed.in);
		new.room( 85);
	}
}


[******** PICTURE LOGIC

if (current.status == normal.ego && hit.special) {
	if (handsOff) {	[ can't do it
		stop.motion(ego);
	} else {
		if (pirate.here){
			stop.motion(aPirate);
			stop.cycling(aPirate);
			normal.motion(aPirate);
		}
		sound(s.ego.falling, sound.done);
		ignore.objs( ego);
		set(handsOff);
		reset(fall.done);

	
		[ find out where he hit it

		if ((posn( ego, 99, 108, 159, 152) ||	[ falling off the front
			posn( ego, 85, 153, 159, 167)))
		{
			current.status = falling;
			fix.loop(ego);
			set.priority(ego, 14);
			ego.x += 3;
			ego.y += 3;
			if (ego.y > 165)
				{
				ego.y = 165;
				}
			reposition.to.v( ego, ego.x, ego.y);
			y = 167;
			work = 4;
			move.obj.f( ego, ego.x, y, work, fall.done);
			dest.room = 48;
			}

		if (posn( ego, 0, 0, 59, 115)) [ back of ship
		{
			current.status = falling;
			set.priority(ego, 4);
			fix.loop(ego);
			ego.x -= 3;
			ego.y += 3;
			reposition.to.v( ego, ego.x, ego.y);
			y = ego.y;
			y += 25;
			if (y > 167)
				{
				y = 167;
				}
			work = 4;
			move.obj.f( ego, ego.x, y, work, fall.done);
			dest.room = 48;
			}

		if (current.status != falling)[ default to hold in center
		{
			current.status = falling;
			set.priority( ego, 6);
			set.view(ego, v.ego.falling);
			ego.x -= 3;
			ego.y += 3;
			reposition.to.v( ego, ego.x, ego.y);
			y = 167;
			work = 4;
			move.obj.f( ego, ego.x, y, work, fall.done);
			dest.room = 84;
		}			  
	}
}

if (current.status == falling && fall.done) 
{
	reset( fall.done);
	erase(ego);
	reset(handsOff);
	if (dest.room == 84)
	{
		new.room.f(dest.room);
	}
	else
	{
		current.status = normal.ego;
		
		if (shipShape != atBeach)
		{						[ lost at sea
			new.room(31);
		}
		else 
		{
			new.room(48);
		}
	}
}

[******** SAID STUFF ********]
if ((said(look) || said(look,ship))){
	print(2);
}
if (said(look, mast)){
	print(3);
}
if (said(look,ladder )){
	print(4);
}
if ((said(look$in, hold) || said(look,hold))){
	print(5);
}

if ((said(look, land) || 
	said(look, ocean) || 
	said(look, water) || 
	said(look,sky))){
	if (shipShape == underWay){
		print(6);
	}
	if (shipShape == nearLand){
		print(7);
	}
	if (shipShape == atBeach){
		print(11);
	}
}


if (shipShape == atBeach &&
   (said(look, beach) ||
	said(look, beach))){
	print(11);
}


if (said(look, pirate)){
	if (pirate.here){
		if (crewAsleep){
			print(8);
		} else {
			print(9);
		}
	} else {
		print(12);
	}
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
	print(10);
}


call(lgc.seagulls);


[ ******* PAINLESS ROOM EXITS **********


if (edge.ego.hit && (current.status == fly || current.status == eagle)){		[ flying exits
	if (edge.ego.hit != left) {
		if (shipShape != atBeach){	[ lost at sea
			new.room(31);
		} else {
			new.room(48);
		}
	}
}

[ exiting at left of room
if (edge.ego.hit == left){
	new.room(80);
}

