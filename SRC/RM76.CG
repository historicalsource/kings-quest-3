[logics for room 76. End of the pier


#include "gamedefs.reh"
#include "rm76.msg"

#define	priority.on.pier	14

#define	on.pier			lf0
#define	fall.done			lf1
#define	in.water			lf2

#object	a.water.1			4
#object	a.water.2			5
#object	a.water.3			6
#object	a.water.4			7


if (init.log){

	work = 76;				[ which picture do we load
	if (shipShape == inPort){
		work = 176;
	}
	load.pic(work);
	draw.pic(work);
	discard.pic(work);

	landing.x = 66;
	landing.y = 100;

	wiz.x = 131				[ no floating priority areas available
	wiz.y = 109;

[	set(beenIn76);
	map.area = map.llewdor;
	set.horizon(72);

[ sound stuff
	load.sound(s.ego.falling);
	load.sound(s.splash);

	load.view(v.ego);
	load.view(v.ego.swimming);
	load.view(v.ego.falling);
	load.view.f(current.ego);
	set.view.f(ego,current.ego);

	load.logics(lgc.seagulls);
	load.logics(lgc.beach);
		
[	load.sound(s.splash);

[ do some water on the pilings
	load.view(v.water.piling);
	animate.obj(a.water.1);
	ignore.horizon(a.water.1);
	ignore.blocks(a.water.1);
	ignore.objs(a.water.1);
	position(a.water.1, 12,146);
	set.view(a.water.1, v.water.piling);
	set.loop(a.water.1,0);
	set.cel(a.water.1,2);
	set.priority(a.water.1, 13);
	draw(a.water.1);

	animate.obj(a.water.2);
	ignore.horizon(a.water.2);
	ignore.blocks(a.water.2);
	ignore.objs(a.water.2);
	position(a.water.2, 39,146);
	set.view(a.water.2, v.water.piling);
	set.loop(a.water.2,0);
	set.cel(a.water.2,4);
	set.priority(a.water.2, 13);
	draw(a.water.2);

	animate.obj(a.water.3);
	ignore.horizon(a.water.3);
	ignore.blocks(a.water.3);
	ignore.objs(a.water.3);
	position(a.water.3, 62,145);
	set.view(a.water.3, v.water.piling);
	set.loop(a.water.3,0);
	set.cel(a.water.3,1);
	set.priority(a.water.3, 13);
	draw(a.water.3);

	animate.obj(a.water.4);
	ignore.horizon(a.water.4);
	ignore.blocks(a.water.4);
	ignore.objs(a.water.4);
	position(a.water.4, 83,146);
	set.view(a.water.4, v.water.piling);
	set.loop(a.water.4,0);
	set.cel(a.water.4,3);
	set.priority(a.water.4, 13);
	draw(a.water.4);

	work = 2;
	cycle.time(a.water.1, work);
	work = 3;
	cycle.time(a.water.2, work);
	work = 2;
	cycle.time(a.water.3, work);
	work = 3;
	cycle.time(a.water.4, work);

	if (current.status == poofing){
		set.priority(ego, priority.on.pier);
	}


	if (positionEgo){
		get.posn(ego, ego.x, ego.y); 			[ we may screw with it
		if (current.status == normal.ego){		[ must be walking in
			set.priority(ego, priority.on.pier);
			if (ego.y > 114){
				ego.y = 114;
			}
			if (ego.y < 92){
				ego.y = 92;
			}
			position.v(ego, ego.x, ego.y);
		}
		if (current.status == swimming){		[ some block adjustments
			release.priority(ego);
			if (ego.y < 105){
				ignore.blocks(ego);
			} else {
				observe.blocks(ego);
			}
		}
		position.f(ego, ego.x, ego.y);		[ set final position
	}
	if (current.status == deferred.entry){
		set(on.pier);
		set.view(ego, v.ego);
		set.priority(ego, priority.on.pier);
		set(positionEgo);
		position.f(ego, landing.x, landing.y);
		set(drawEgo);
	}


	if (drawEgo){
		draw(ego);
	}

	work = 0;		[ big gulls
	call(lgc.seagulls);
	call(lgc.beach);

	show.pic();
	return();

}

[ main()	/* linear congruential coding */

[ keep the ship in port all the time we are on pier

if (shipShape == inPort && !voyage.minutes
 && voyage.seconds < 30 && voyage.seconds > 0){
	voyage.seconds = 30;
}

if (shipShape > inPort){
	print(6);
	stop.cycling(ego);
	set(certain.death);
}



[ handle end of poofing in

if (ego.poofing.done && current.status == normal.ego){	[ all poofs end on the pier
	set.view(ego, v.ego);	
	set.priority(ego, priority.on.pier);
	current.status = normal.ego;
}


[ jugglin' blocks & priorities

if (current.status == swimming){			[ adjust priority for position
	release.priority(ego);
	if (ego.y < 138){
		ignore.blocks(ego);
	} else {
		observe.blocks(ego);
	}

}


if (current.status == normal.ego){			[ must be on pier and could fall
	if (hit.special && !handsOff){
		set(handsOff);
		sound(s.ego.falling, sound.done);
		current.status = falling;
		ignore.blocks(ego);
		set.view(ego, v.ego.falling);
		if (ego.y < 87){			[ falling at back
			set.priority(ego, 4);
			work = 3;
			y = 135;
			move.obj.f(ego, ego.x, y, work, fall.done);
		}
		if (ego.y > 114){			[ falling off front
			set.priority(ego, 15);
			work = 3;
			y = 167;
			move.obj.f(ego, ego.x, y, work, fall.done);
		}
		if (posn(ego, 106, 91 ,128, 113)){ [ falling off end
			set.priority(ego, 11);
			work = 3;
			y = ego.y;
			y += 38;
			move.obj.f( ego, ego.x, y, work, fall.done);
		}
	}
}

[stop falling
if (current.status == falling && fall.done){
	reset(handsOff);
	reset(fall.done);
	release.priority(ego);
	observe.blocks(ego);
	set(keep.cycling);
	set.view(ego, v.ego.swimming);
	current.status = swimming;
	sound(s.splash, sound.done);
}

reset(on.water);		[ default off water
if (current.status == swimming){
	set(on.water);
	if (ego.y > 138){
		observe.blocks(ego);
	} else {
		ignore.blocks(ego);
	}
}

[ handle all sorts of vacuuous input with similarly vacuuous output

if(have.input){

	if ((said(look,ship) ||
		said(look,pirate,ship)))
		{
		if (shipShape == inPort)			{print(1);}
		else							{print(2);}
		}

	if ((said(board,ship) ||
		said(jump,ship)))	
		{
		if (shipShape == inPort)			{print(3);}
		else							{print(2);}
		}
	if (said(look,town))				{print(4);}

	if (said(look, pier)){
		print(5);
	}

}

call(lgc.seagulls);
call (lgc.beach);

[*****
:exit							[	test for leaving the room
[*****

if (edge.ego.hit == bottom){
	new.room(30);
}
if (edge.ego.hit == top)	{
	exit.edge = edge.ego.hit;
	new.room(31);
}
if (edge.ego.hit == left){
	new.room(75);
}
if (edge.ego.hit == right){
	exit.edge = edge.ego.hit;
	new.room(31);
}

