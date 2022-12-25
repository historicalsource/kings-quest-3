[ Room 82 - Stern of ship

#include "rm82.msg"
#include "gamedefs.reh"



#define	next			lf0


[ define base of ladder
#define	baseLeft		141
#define	baseTop		127
#define	baseCenter	142        
#define	baseRight		144
#define	baseBottom	133

if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

[ external stuff to set up
	map.area = map.ship;

	landing.x = 84;
	landing.y = 68;

	wiz.x = 0;
	wiz.y = 0;

[ get the seagulls going
	load.logics(lgc.seagulls);
	load.logics(lgc.pirates);

[ add in the wakes
	if (shipShape < atBeach){
		load.view(v.pirate.ship.wake);
	
		animate.obj(wake1);
		set.view(wake1, v.pirate.ship.wake);
		set.loop(wake1, 0);
		position(wake1, 58,156);
		ignore.objs(wake1);
		work = 2;
		cycle.time(wake1, work);
		draw(wake1);
	
		animate.obj(wake2);
		set.view(wake2, v.pirate.ship.wake);
		set.loop(wake2, 1);
		position(wake2, 31,147);
		work = 2;
		cycle.time(wake2, work);
		ignore.objs(wake2);
		draw(wake2);
	}

[ generic ego
	load.view.f(current.ego);
	set.view.f(ego, current.ego);
	

	if (plankWalk){			[ he's going for a swim
		set(handsOff);
		prevent.input();
		program.control();

		load.view(v.pirate.captain);
		add.to.pic(v.pirate.captain, 1, 4, 80, 66, 13, 4);
		discard.view(v.pirate.captain);

		load.view(v.pirate.1);
		add.to.pic(v.pirate.1, 1, 0, 87, 70, 13, 4);
		discard.view(v.pirate.1);

		load.sound(s.ocean);
		load.sound(s.ego.falling);

		load.view(v.splash.big);
		load.view(v.ego.walking.plank);
		set.view(ego,v.ego.walking.plank);
		set.loop(ego,1);
		set.priority(ego, 15);
		position(ego, 78, 68);
		ignore.objs(ego);
		ignore.blocks(ego);
		draw(ego);

	[ get the plank		
		animate.obj(plank);
		set.view(plank,v.ego.walking.plank);
		set.loop(plank, 0);
		set.priority(plank,15);
		position(plank, 64, 72);
		draw(plank);

	[ the shark and his pen
		block(0,130,36,167);

		animate.obj(aShark);
		load.view(v.sharkfin);
		set.view(aShark,v.sharkfin);
		position(aShark,15,140)
		set.loop(aShark, facing.right);
		fix.loop(aShark);
		wander(aShark);
		draw(aShark);

	} else {
		load.view(v.ego);
		set.priority(ego, 13);
		if (positionEgo){
			position(ego, 87, 68);
		}
		if (current.status == deferred.entry){
			set.view(ego, v.ego);
			set(positionEgo);
			position.f(ego, landing.x, landing.y);
			set(drawEgo);
			set.priority(ego, 13);
		}

		if (drawEgo){
			draw(ego);
		}
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

if (landHo && shipShape == atBeach){
	erase(wake1);
	erase(wake2);
}

call(lgc.pirates);


[ end of poof
if (ego.poofing.done && current.status == normal.ego){
	set.priority(ego, 13);
}

[ walking plank stuff
if (plankWalk == 1){
	print(6);
	++plankWalk;
	move.obj(ego,60,68,1,next);
}

if (next){
	program.control();
}

if (plankWalk == 2 && next){
	++plankWalk;
	set(no.cycling);
	sound(s.ego.falling, sound.done);
	move.obj(ego,60,150,6,next);
}
if (plankWalk == 3 && next){
	++plankWalk;
	sound(s.ocean, sound.done);
	work = 0;
	reset(no.cycling);
	set(keep.cycling);
	set.cel(ego,0);
	set.view(ego, v.splash.big);
	get.posn(ego, x ,y);
	x -= 6;
	y -= 4;
	reposition.to.f(ego, x, y);
	end.of.loop(ego, next);
}
if (plankWalk == 4 && next){
	++plankWalk;
	get.posn(ego, ego.x , ego.y);
	erase(ego);
	unblock();
	work = 1;
	move.obj.f(aShark, ego.x, ego.y, work, next);
}

if (plankWalk == 5 && next){
	++plankWalk;
	erase(aShark);
	reset(next);
	print(5);
	stop.cycling(ego);
	set(certain.death);
}

call(lgc.seagulls);



[******* SAID STUFF ********]
if ((said(look) || said(look, ship))){
	print(1);
}
if ((said(look, up, sky) || 
	said(look,sky))){
	if (shipShape == underWay){
		print(2);
	} else {
		print(3);
	}
}


if ((said(look, land) || 
	said(look, over, ocean) || 
	said(look, ocean) ||
	said(look, over, water) || 
	said(look, water))){
	if (shipShape == underWay){
		print(4);
	}
	if (shipShape == nearLand){
		print(9);
	}
	if (shipShape == atBeach){
		print(10);
	}
}


if (shipShape == atBeach &&
   (said(look, beach) ||
	said(look, beach))){
	print(10);
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


[******** PAINLESS EXITS *********

if (edge.ego.hit && 
	(current.status == fly || current.status == eagle)){		[ flying exits
	if (edge.ego.hit != right) {
		if (shipShape != atBeach){	[ lost at sea
			new.room(31);
		} else {
			new.room(48);
		}
	} else {
		new.room(80);
	}
}


[ Just let him walk around
if (hit.special && current.status == normal.ego){
	release.priority(ego);
	new.room(83);
}


