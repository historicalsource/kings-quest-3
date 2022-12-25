[ Room 86 - Forward hold.  Exit at stage left

#include "rm86.msg"
#include "gamedefs.reh"


#define	jumpDone		lf0
#define	mice.here		lf1
#define	mice.talked	lf2

#define	mice.timer	lv0
#define	start.msg		lv1
#define	end.msg		lv2

[ mice message constants
#define	start.1		10
#define	start.2		13
#define	start.3		17
#define	start.4		21
#define	start.5		24
#define	start.6		27		[ this is a dummy to end the logic


if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

[ external stuff to set up
	map.area = map.ship;
	set(interiorRoom);

	landing.x = 120;
	landing.y = 145;

	wiz.x = 54;
	wiz.y = 151;

	load.logics(lgc.pirates);

	load.logics(lgc.box);
	call(lgc.box);

	load.view(v.ego.jumping);
	load.view(v.ego);
	load.view(v.ego.carrying.box);
	load.view.f(current.ego);
	set.view.f(ego, current.ego);

	if (positionEgo){
		x = 10;
		position.f(ego,x, ego.y);
	}

	if (drawEgo){
		draw(ego);
	}

	[ maybe add some mice
	random(2, 3, work);
	if (work == 3){
		set(mice.here);
		mice.timer = 5;		[ don't talk right away
		load.view(v.pirate.ship.mouse);

		animate.obj(aMouse1);
		set.view(aMouse1, v.pirate.ship.mouse);
[		ignore.objs(aMouse1);
		work = 2;
		step.size(aMouse1, work);
		y = 145;
		random(1, 130, x);
		position.f(aMouse1, x, y);
		wander(aMouse1);
		draw(aMouse1);

		animate.obj(aMouse2);
		set.view(aMouse2, v.pirate.ship.mouse);
[		ignore.objs(aMouse2);
		work = 2;
		step.size(aMouse2, work);
		y = 145;
		random(1, 130, x);
		position.f(aMouse2, x, y);
		wander(aMouse2);
		draw(aMouse2);
	}




[ all done initing, show the picture
	show.pic();
	return();
}

call(lgc.pirates);

[ the stupid box

call(lgc.box);		[ needs first shot at most of the logic

if (aSecondPassed && mice.timer){
	--mice.timer;
}


[ let the mice speak (if they will)
distance(aMouse1, aMouse2, work);
if (mice.here && !mice.timer && has(i.dough.balls) && work < 15){
	mice.timer = 5;		[ give them time to separate
	random(1, 5, work);
	start.msg = 0;
	end.msg = 0;
	if (work == 1 && !mice.1){
		set(mice.1);
		start.msg = start.1;
		end.msg = start.2;
	}
	if (work == 2 && !mice.2){
		set(mice.2);
		start.msg = start.2;
		end.msg = start.3;
	}
	if (work == 3 && !mice.3){
		set(mice.3);
		start.msg = start.3;
		end.msg = start.4;
	}
	if (work == 4 && !mice.4){
		set(mice.4);
		start.msg = start.4;
		end.msg = start.5;
	}
	if (work == 5 && !mice.5){
		set(mice.5);
		start.msg = start.5;
		end.msg = start.6;
	}
:retalk
	if (start.msg < end.msg){
		mice.timer = 120;		[ if he's patient they'll talk again
		print.at.v(start.msg,2,2,37);
		++start.msg;
		goto retalk;
	}
}
										


[******* SHOW SAID *******]

if ((said(look,room) || said(look) || said(look, hold))){
	print(1);
}

if ((said(look, up ,ceiling) || said(look, ceiling))){
	print(3);
}


if (said(look, mice)){
	if (mice.here){
		print(6);
	} else {
		print(5);
	}
}

if (said(listen, mice)){
	print(2);
}

if (said(talk, mice)){
	if (mice.here){
		print(7);
	} else {
		print(5);
	}
}

if (said(get, mice)){
	if (mice.here){
		print(8);
	} else {
		print(5);
	}
}

if (said(kill, mice)){
	if (mice.here){
		print(9);
	} else {
		print(5);
	}
}

if ((said(get$out, hold) || said(climb, out, hold))){
	print( 4);
}




[********** PAINLESS ROOM EXITS ************

if (edge.ego.hit == 4){
	new.room(85);
}


