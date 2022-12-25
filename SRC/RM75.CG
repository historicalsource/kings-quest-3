[logics for room -- 75:center pier

%include "gamedefs.reh"
%include "rm75.msg"

%define	priority.on.pier	13
%define	paid.msg.start		8
%define	paid.msg.max		10	[3 messages required
%define	unpaid.msg.start	11
%define	unpaid.msg.max		13	[3 messages required
%define	msg.timer.start	200
%define	l.right			0
%define	l.left			1

%define	msg.timer			timer.1
%define	leave.timer		timer.2


%define	msg.max			lv1
%define	pirate.msg		lv2
%define	death.watch		lv3
#define	script			lv4	[ captain script
	[ steps 0-5 are un-named
	#define	raise.plank	10
	#define	capture.ego	11
	#define	set.sail		12	[ this one leaves the room

#define	script.timer		lv5
#define	talked.to.him		lv6
#define	anger.timer		lv7


%define	on.pier			lf0
%define	fall.done			lf1
%define	sail				lf2
%define	gang.done			lf3
%define	gang.down			lf4
%define	guard.turn		lf5
%define	ego.aboard		lf6
%define	ego.caught		lf7
%define	ego.sliced		lf8
#define	script.done		lf9
#define	chasing.ego		lf10


%object	a.pirate.1		1
%object	a.pirate.guard		2
%object	a.gangplank		3
%object	a.water.1			4
%object	a.water.2			5
%object	a.water.3			6
%object	a.water.4			7
%object	a.water.5			8
#object	a.captain			9

if (init.log)
	{
[ pick a picture
	work = 75;
	if (shipShape == inPort){
		work = 175;
	}
	load.pic(work);
	draw.pic(work);
	discard.pic(work);

	load.view(v.ego);
	load.view(v.ego.falling);
	load.view(v.ego.swimming);
	load.view(v.ego.dead);
	load.view.f(current.ego);
	set.view.f(ego, current.ego);

	set.horizon(72);
	map.area = map.llewdor;
	
	wiz.x = 32;
	wiz.y = 79;

	landing.x = 119;
	landing.y = 100;

	load.logics(lgc.seagulls);
	load.logics(lgc.beach);
		

[ sound stuff
	load.sound(s.ego.falling);
	load.sound(s.splash);
	load.sound(m.badguy);
	
	load.view(v.water.piling);
	animate.obj(a.water.1);
	ignore.horizon(a.water.1);
	ignore.blocks(a.water.1);
	ignore.objs(a.water.1);
	position(a.water.1, 7,146);
	set.view(a.water.1, v.water.piling);
	set.loop(a.water.1,0);
	set.cel(a.water.1,2);
	set.priority(a.water.1, 13);
	draw(a.water.1);

	animate.obj(a.water.2);
	ignore.horizon(a.water.2);
	ignore.blocks(a.water.2);
	ignore.objs(a.water.2);
	position(a.water.2, 37,146);
	set.view(a.water.2, v.water.piling);
	set.loop(a.water.2,0);
	set.cel(a.water.2,4);
	set.priority(a.water.2, 13);
	draw(a.water.2);

	animate.obj(a.water.3);
	ignore.horizon(a.water.3);
	ignore.blocks(a.water.3);
	ignore.objs(a.water.3);
	position(a.water.3, 68,146);
	set.view(a.water.3, v.water.piling);
	set.loop(a.water.3,0);
	set.cel(a.water.3,1);
	set.priority(a.water.3, 13);
	draw(a.water.3);

	animate.obj(a.water.4);
	ignore.horizon(a.water.4);
	ignore.blocks(a.water.4);
	ignore.objs(a.water.4);
	position(a.water.4, 102,147);
	set.view(a.water.4, v.water.piling);
	set.loop(a.water.4,0);
	set.cel(a.water.4,3);
	set.priority(a.water.4, 13);
	draw(a.water.4);

	animate.obj(a.water.5);
	ignore.horizon(a.water.5);
	ignore.blocks(a.water.5);
	ignore.objs(a.water.5);
	position(a.water.5, 135,146);
	set.view(a.water.5, v.water.piling);
	set.loop(a.water.5,0);
	set.cel(a.water.5,0);
	set.priority(a.water.5, 13);
	draw(a.water.5);

	work = 2;
	cycle.time(a.water.1, work);
	work = 3;
	cycle.time(a.water.2, work);
	work = 2;
	cycle.time(a.water.3, work);
	work = 3;
	cycle.time(a.water.4, work);
	work = 2;
	cycle.time(a.water.5, work);


	if (shipShape == inPort){		[ hasn't sailed yet
		animate.obj(a.gangplank);	[ always in picture
		load.view(v.gangplank);
		set.view(a.gangplank, v.gangplank);
		set.priority(a.gangplank, 12);
		position(a.gangplank, 23, 90);
		set.cel(a.gangplank, 0);
		stop.cycling(a.gangplank);
		draw(a.gangplank);
		stop.update(a.gangplank);

		animate.obj(a.pirate.guard)	[ always here, not always agressive
		load.view(v.attacking);
		load.view(v.pirate.guard);
		set.view(a.pirate.guard, v.attacking);
		set.cel(a.pirate.guard, 0);
		if (paid.pirates){			[ not agressive (yet)
			position(a.pirate.guard, 18,73);
			ignore.objs(a.gangplank); [ let ego cross
		} else {
			position(a.pirate.guard, 23, 85);
			set.priority(a.pirate.guard, priority.on.pier);
		}	
		stop.cycling(a.pirate.guard);
		draw(a.pirate.guard);
		stop.update(a.pirate.guard);
	
			
		[ now, if the pirates have been paid we get some more

		if (paid.pirates){
			msg.max = paid.msg.max;
			pirate.msg = paid.msg.start;
			msg.timer = 100;

			reset(pirate.pissed);	[ he's friendly again
			animate.obj(a.pirate.1);			[ a sailor on deck
			load.view(v.pirate.1);
			set.view(a.pirate.1, v.pirate.1);
			position(a.pirate.1, 54, 70);
			set.priority(a.pirate.1, 12);
			stop.cycling(a.pirate.1);
			set.loop(a.pirate.1, 1);
			draw(a.pirate.1);
			stop.update(a.pirate.1);
		
			animate.obj(a.captain);			[ captain on deck
			load.view(v.pirate.captain);
			set.view(a.captain, v.pirate.captain);
			ignore.horizon(a.captain);
			position(a.captain, 130, 46);
			draw(a.captain);
			move.obj(a.captain, 65, 46, 1, script.done);		[ start the script running

		}

	}	[ end of ship shape if

	if (current.status == poofing){
		set.priority(ego, priority.on.pier);
		set(on.pier);
	}

	if (positionEgo){
		get.posn(ego, ego.x, ego.y); 			[ we may screw with it
		if (current.status == normal.ego){		[ must be walking in
			set.priority(ego, priority.on.pier);
			set(on.pier);
			if (ego.y > 114){
				ego.y = 114;
			}
			if (ego.y < 92){
				ego.y = 92;
			}
			position.v(ego, ego.x, ego.y);
		}
		if (current.status == swimming){		[ no position adjustments
			reset(on.pier);
			release.priority(ego);
			set(keep.cycling);
			if (ego.y > 138){
				observe.blocks(ego);
			} else {
				ignore.blocks(ego);
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
	
	show.pic();
	return();

}

[ keep the ship in port all the time we are on pier

if (shipShape == inPort && !voyage.minutes
 && voyage.seconds < 30 && voyage.seconds > 0){
	voyage.seconds = 30;
}

if (shipShape > inPort){
	print(26);
	stop.cycling(ego);
	set(certain.death);
}




[ captain script. Only runs when pirates paid

if (posn(ego, 28, 71, 37, 77)){	[ he made it
	if (current.status == normal.ego && !handsOff){
		set(handsOff);
		script = raise.plank;		[ skip any messages
		set(script.done);
	}
}

if (aSecondPassed && script.timer){
	if (!handsOff){
		--script.timer;
	}
	if (script.timer == 0){
		set(script.done);
	}
}

if (script.done && script == 0){	[ move obj in init log
	++script;
	reposition.to(a.captain, 62, 57);	[ time to come down stairs
	script.timer = 2;
	reset(script.done);
}

if (script.done && script == 1){		[ now on lower level
	++script;
	move.obj(a.captain, 47, 57, 1, script.done);
}

if (script.done && script == 2){				    	
	++script;
	reset(script.done);
	print(17);			[ first warning
	stop.cycling(a.captain);
	stop.update(a.captain);
	script.timer = 15;		[ seconds between messages
}

if (script.done && script == 3){
	++script;
	reset(script.done);
	print(8);	 
	script.timer = 15;		[ seconds between messages
}

if (script.done && script == 4){
	reset(script.done);
	print(9);				[ last message	 
}

if (script.done && script == raise.plank){	[ ego got on board
	++script;
	stop.motion(ego);
	set.priority(ego, 12);
	start.update(a.gangplank);
	program.control();
	work = 6;
	cycle.time(a.gangplank, work);
	end.of.loop(a.gangplank, script.done);
}

if (script.done && script == capture.ego){	[ grab him
	++script;
	print(14);
	start.update(a.pirate.guard);
	end.of.loop(a.pirate.guard, done);
	start.update(a.pirate.1);
	start.cycling(a.pirate.1);
	sound(m.badguy ,sound.done);
	move.obj(a.pirate.1, 35, 70, 1, script.done);
}

if (script.done && script == set.sail){		[ go to new.room 
	++script;
	score += 2;
	reset(script.done);
	print(10);
	player.control();
	reset(handsOff);
	new.room(77);
}


if (ego.poofing.done){
	if (current.status == normal.ego){	[ all poofs end on the pier
		set(on.pier);
		set.priority(ego, priority.on.pier);
	} else {
		if (pirate.pissed){
			normal.motion(a.pirate.guard);
			stop.motion(a.pirate.guard);
			stop.cycling(a.pirate.guard);
			reset(chasing.ego);
		}
	}
}


[ ******** Picture Logic ********

if (current.status == normal.ego){			[ must be on pier and could fall
	if (hit.special && !handsOff){
		set(handsOff);
		reset(on.pier);
   		current.status = falling;
		sound(s.ego.falling, sound.done);
		ignore.blocks(ego);
		set.view(ego, v.ego.falling);
		start.motion(ego);
		if (ego.y < 85){			[ falling at back
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
		release.priority(ego);
	} else {
		ignore.blocks(ego);
		set.priority(ego, 4);
	}
}


[*****
[ego talks too much
[*****

[ he's angry with you, don't get too close
if (!handsOff && aSecondPassed && anger.timer){
	--anger.timer;
	distance(a.pirate.guard, ego, work);
	if (anger.timer == 0){
		if (work < 30){
			set(pirate.pissed);
			print(13);
		} else {
			++anger.timer;		[ he's still angry
		}
	}
}
[ pirate will stay pissed unless pirates are paid
[ wont get angry if not human
if (pirate.pissed && !chasing.ego && current.status == normal.ego){ 
	set(chasing.ego);	[ block this from next call
	anger.timer = 0;
	start.update(a.pirate.guard);
	start.cycling(a.pirate.guard);
	set.view(a.pirate.guard, v.pirate.guard);
	ignore.blocks(a.pirate.guard);
	ignore.obj(a.pirate.guard);
	follow.ego( a.pirate.guard, 10, ego.caught);
}

[ this must be before the "ego.caught" stuff in case he starts a poof

if (!handsOff && chasing.ego && current.status != normal.ego){
	get.posn(a.pirate.guard, x, y);
	if (x == ego.x){
		stop.cycling(a.pirate.guard);
	} else {
		work = 1;
		start.cycling(a.pirate.guard);
		move.obj.f(a.pirate.guard, ego.x, y, work, ego.caught);
	}
}


if (ego.caught && current.status == normal.ego){				[ by the guard
	if (handsOff){
		reset(ego.caught);
		stop.cycling(a.pirate.guard);
		normal.motion(a.pirate.guard);
		stop.motion(a.pirate.guard);
	} else {
		set(handsOff);
		reset(ego.caught);			[ block this switch
		reset(chasing.ego);
		program.control();
		stop.motion(ego);
	[ get thee behind me satan
		get.posn(ego, ego.x, ego.y);
		get.posn(a.pirate.guard, x ,y);
		y = ego.y;
		y -= 2;
		ignore.blocks(a.pirate.guard);
		reposition.to.f(a.pirate.guard, x, y);
		prevent.input();
		set.view(a.pirate.guard, v.attacking);
		set.cel(a.pirate.guard, 0);
		work = 2;
		cycle.time(a.pirate.guard, work);
		set.priority(ego, 14);				[ show in front of ego
		end.of.loop(a.pirate.guard, ego.sliced);
		current.status = being.dragged;	[ good enough status
		death.watch = 50;
	}
}

if (ego.sliced){
	reset(ego.sliced);
	set.view(ego, v.ego.dead);
	print.at(7, 2, 2, 37);
}


--death.watch;
if (death.watch == 1)
	{
	stop.cycling(ego);
	set(certain.death);
	}

		
[*****
[handle.input
[*****

if(have.input)	{

	if ((said(look,ship) || said(look,pirate,ship))) {
		if (shipShape == inPort) {
			print(1);
		} else {
			print(2);
		}
	}

	if (shipShape == inPort && (said(board,ship) || said(jump,ship))){
		if (paid.pirates){
			print(5);
		} else {
			print(3);
		}
	}
		

	if (said(look,town)) {
		print(4);
	}

	if ((said(talk, with, man) || said(talk,man))){
		if (shipShape == inPort){
			if (!on.pier){
				print(27);
			} else {
				if (paid.pirates) {
					print(19);
				} else {
					++pirate.msg;
					if (pirate.msg == 1){
						print(11);
					}
					if (pirate.msg == 2){
						anger.timer = 8;	[ he'll get you now
						print(12);
					}
					if (pirate.msg == 3){
						anger.timer = 0;
						print(13);
						set(pirate.pissed);
					}
					if (pirate.msg > 3){
						print(25);
					}
				}
			}
		} else {
			print(21);
		}
	}

	if (said(look,pirate)) {
		if (shipShape == inPort){
			if (!paid.pirates) {
				print(6);
			} else {
				print(20);
			}
		} else {
			print(21);
		}
	}

	if (said(look, pier)){
		print(22);
	}

	if ((said(get, man) || said(kill, man))){
		if (!paid.pirates){
			print(23);
		} else {
			print(24);
		}
	} 
}

call(lgc.seagulls);
call(lgc.beach);


[*****
[exit							[	test for leaving the room
[*****
if (edge.ego.hit && chasing.ego){
	if (!handsOff){
		print(18);
	}
}

if (edge.ego.hit == bottom){
	new.room(30);
}

if (edge.ego.hit == top){
	exit.edge = edge.ego.hit;
	new.room(31);
}

if (edge.ego.hit == left){
	new.room(25);
}

if (edge.ego.hit == right){
	new.room(76);
}
