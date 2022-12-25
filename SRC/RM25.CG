[logics for room -- 25:west pier

%include "gamedefs.reh"
%include "rm25.msg"



[ CONSTANTS
#define	wade.left		61
#define	wade.right	68



%define	stun.time				50	[misc constants
%define	priority.on.pier		13
%define	priority.on.ladder1		14

%define	loop.back				0	[ego.climbing - back view
%define	loop.front			1	[ego.climbing - front view
%define	fall.rate				5


%define	ladder				lv0
	%define	no.ladder		0
	%define	ladder1		1
	%define	ladder2		2


%define	on.pier				lf0	[ while normal.ego
%define	fall.done				lf1


%object	a.water.1				1
%object	a.water.2				2



if (init.log){
	map.area = map.llewdor;

	set(beenIn25);
	set.horizon(70);

	landing.x = 55;
	landing.y = 105;

	wiz.x = 1;
	wiz.y = 73;

	load.logics(lgc.seagulls);
	load.logics(lgc.beach);

	load.view(v.ego);
	load.view(v.ego.climbing.ladder);
	load.view(v.ego.falling);
	load.view(v.ego.swimming);
	load.view(v.ego.wading.shallow);

	load.view.f(current.ego);
	set.view.f(ego, current.ego);

[ sound stuff
	load.sound(s.ego.falling);
	load.sound(s.splash);


	work = 25;
	if (shipShape == inPort){
		work = 125;
	}
	
	load.pic(work);
	draw.pic(work);
	discard.pic(work);


	work = 0;		[ big gulls
	call(lgc.seagulls);
	call (lgc.beach);

	load.view(v.water.piling);
	animate.obj(a.water.1);
	ignore.horizon(a.water.1);
	ignore.blocks(a.water.1);
	ignore.objs(a.water.1);
	position(a.water.1, 103, 145);
	set.view(a.water.1, v.water.piling);
	set.loop(a.water.1, 0);
	set.cel(a.water.1, 2);
	set.priority(a.water.1, 13);
	draw(a.water.1);

	animate.obj(a.water.2);
	ignore.horizon(a.water.2);
	ignore.blocks(a.water.2);
	ignore.objs(a.water.2);
	position(a.water.2, 134, 145);
	set.view(a.water.2, v.water.piling);
	set.loop(a.water.2, 0);
	set.cel(a.water.2, 4);
	set.priority(a.water.2, 13);
	draw(a.water.2);

	work = 2;
	cycle.time(a.water.1, work);
	work = 3;
	cycle.time(a.water.2, work);

	set(on.pier);			[ default for poof
	if (current.status == poofing){
		set.priority(ego, priority.on.pier);
	}

	if (positionEgo){				[ pick a position
		get.posn(ego, ego.x, ego.y);

		if (previous.room == 20){
			reset(on.pier);
			current.status = normal.ego;
			position(ego, 56, 77);
			ignore.blocks(ego);
		}

		if (previous.room == 31){
			reset(on.pier);
			ego.x = 130;
			position.f(ego, ego.x, ego.y);
		}
		if (previous.room == 30){
			reset(on.pier);
			if (current.status == swimming){
				set.view(ego, v.ego.swimming);
				position(ego, 140, 164);
			}
			if (current.status == wading){
				set.view(ego, v.ego.wading.shallow);
				position(ego, 61, 164);
			}
			if (current.status == normal.ego){
				if (ego.x > 54){
					ego.x = 54;
				}
				position.f(ego, ego.x, ego.y);
			}
		}
		if (previous.room == 24){
			if (current.status == normal.ego){
				if (ego.y > 114){
					ego.y = 114;
				}
				if (ego.y < 92){
					ego.y = 92;
				}
				position.v(ego, ego.x, ego.y);
				set(on.pier);
				set.priority(ego, priority.on.pier);
			}
		}
		if (previous.room == 75){
			if (current.status == normal.ego){
				if (ego.y > 114){
					ego.y = 114;
				}
				if (ego.y < 92){
					ego.y = 92;
				}
				position.v(ego, ego.x, ego.y);
				set(on.pier);
				set.priority(ego, priority.on.pier);
				[ don't mess with it
			}
			if (current.status == swimming){
				reset(on.pier);
				[ don't mess with it
			}
		}
	}

	if (current.status == deferred.entry){
		set.view(ego, v.ego);
		set(on.pier);
		set.priority(ego, priority.on.pier);
		set(positionEgo);
		position.v(ego, landing.x, landing.y);
		set(drawEgo);
	}

	if (drawEgo){
		draw( ego);
	}

	show.pic();

		
	return();

}



if (ego.poofing.done && current.status == normal.ego){
	set.view(ego, v.ego);
	current.status = normal.ego;
	set(on.pier);
	set.priority(ego, priority.on.pier);
}

[ code to allow crossing block on pier
if (current.status == normal.ego && on.pier){
	if (posn(ego, 13, 89, 36, 113)){
		ignore.blocks(ego);
	} else {
		observe.blocks(ego);
	}
}

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





if (current.status == normal.ego){			[ must be on pier and could fall
	if (hit.special && !handsOff){
		set(handsOff);
		current.status = falling;
		sound(s.ego.falling, sound.done);
		ignore.blocks(ego);
		set.view(ego, v.ego.falling);
		start.motion(ego);
		if (ego.y < 100){			[ falling at back
			set.priority(ego, 4);
			work = 3;
			y = 135;
			move.obj.f(ego, ego.x, y, work, fall.done);
		}
		if (ego.y > 115){			[ falling off front
			set.priority(ego, 15);
			work = 3;
			y = 167;
			move.obj.f(ego, ego.x, y, work, fall.done);
		}
	}
}

[stop falling
if (current.status == falling && fall.done){
	reset(on.pier);
	reset(handsOff);
	reset(fall.done);
	release.priority(ego);
	release.priority(ego);
	set(keep.cycling);
	set.view(ego, v.ego.swimming);
	current.status = swimming;
	sound(s.splash, sound.done);
}

[ ladder stuff

[ getting on the ladder

if (current.status == normal.ego && posn(ego,8, 119, 11, 156)){	[ in the box
	set(on.pier);
	ignore.blocks(ego);
	set.priority(ego, 14);		[ climbing to 12
	set.view(ego, v.ego.climbing.ladder);
	set.loop(ego, 0);		[ facing back
	fix.loop(ego);
	work = 2;
	step.size(ego, work);
	current.status = climbing;
	reset(keep.cycling);
}


if (current.status == climbing){
	if (ego.y < 119){			[ get him off the top
		release.loop(ego);
		set.priority(ego, priority.on.pier);
		current.status = normal.ego;
		set.view(ego, v.ego);
		set.loop(ego, facing.back);
		work = 1;
		step.size(ego, work);
		observe.blocks(ego);
	}
	if (ego.y > 156){			[ get him off the bottom
		release.loop(ego);
		release.priority(ego);
		current.status = normal.ego;
		set.view(ego, v.ego);
		work = 1;
		step.size(ego, work);
		set.loop(ego, facing.back);
		reset(on.pier);
	}
}

	

[ walking in a room that was drawn slightly wrong

if (!on.pier && !handsOff){
	if (posn(ego, wade.left, 0, wade.right, 166)){	[ in wade box
		reset(keep.cycling);
		set.view(ego, v.ego.wading.shallow);
		ignore.blocks(ego);
		current.status = wading;
		set.priority(ego, 11);
		set(on.water);
	}
	if (ego.x > wade.right){
		set(keep.cycling);
		ignore.blocks(ego);
		set(on.water);
		set.view(ego, v.ego.swimming);
		current.status = swimming;
		if (ego.y < 140){
			set.priority(ego, 10);
		} else {
			release.priority(ego);
		}
	}
	if (ego.x < wade.left){
		reset(keep.cycling);
		set.view(ego, v.ego);
		current.status = normal.ego;
		observe.blocks(ego);
		release.priority(ego);
		reset(on.water);
	}
}

[ allow ego to pass block on pier but not block on bluff

if (current.status == normal.ego && !on.pier){
	if (posn(ego, 40, 86, 65, 88)){
		ignore.blocks(ego);
	} else {
		observe.blocks(ego);
	}
}

		


[*****
[handle.input
[*****


if (have.input){
	if ((said(look, boat) || said(look, ship) || said(look, pirate, ship))){
		if (shipShape == inPort)	{
			print(1);
		} else {
			print(2);
		}
	}

	if ((said(jump, on, boat) ||
		said(jump, on, ship) || 
		said(board, boat) || 
		said(board, ship) || 
		said(jump, ship)))	
		{
		if (shipShape == inPort)			{print(3);}
		else							{print(2);}
		}

	if (said(look, town))				{print(4);}

	}

	if (said(look, pier)){
		print(5);
	}

		
call (lgc.seagulls);
call (lgc.beach);


[*****
[exit							[	test for leaving the room
[*****

if (edge.ego.hit == bottom){
	new.room(30);
}
if (edge.ego.hit == left){
	new.room(24);
}
if (edge.ego.hit == right){
	new.room(75);
}
if (edge.ego.hit == top){
	if (current.status == swimming){
		exit.edge = edge.ego.hit;
		new.room(31);
	} else {
		new.room(20);
	}
}
