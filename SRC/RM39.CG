[logics for room 39 -- GENERAL STORE

%include "gamedefs.reh"
%include "rm39.msg"



%define	near.counter			1
#define	near.dog				2

#define	counterY				109


%define	dead.time				lv0
%define	old.gold				lv1
#define	script				lv2
	#define	start.store	0
	#define	greet.ego		1
	#define	get.response	2
	#define	no.response	3
	#define	wandering		4
	#define	dusting		5
	#define	start.pick	6
	#define	pick.item		7
	#define	move.center	8
	#define	store.done	9

#define	script.timer			lv3
#define	script.msg			lv4
#define	wag.timer				lv5	[ time of cycling
#define	center.x				lv6	[ where you were
#define	buy.msg				lv7


%define	already.tried.steal		lf0
#define	next					lf1
#define	get.single			lf2	[ flag for single word response
#define	ego.there				lf3


%object	a.storekeeper			1
%object	a.store.dog			2



if (init.log){
	set(interiorRoom);

	wiz.x = 104;
	wiz.y = 134;

	landing.x = 55;
	landing.y = 141;

	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

[ sounds
	load.sound(m.store);
	reset(sound.done);


[ customize ego
	load.view(v.ego);
	load.view(v.ego.dead);
	load.view.f(current.ego);
	set.view.f(ego, current.ego);

[ man's furriest friend
	animate.obj(a.store.dog);
	load.view(v.store.dog);
	set.view(a.store.dog, v.store.dog);
	add.to.pic(v.store.dog, 0, 0, 51, 136, 1, 1);
	position(a.store.dog, 51, 136);
	work = 3;
	cycle.time(a.store.dog, work);
	stop.cycling(a.store.dog);
	ignore.blocks(a.store.dog);
	draw(a.store.dog);

[ the store keeper 
	animate.obj(a.storekeeper);
	load.view(v.storekeeper);
	set.view(a.storekeeper, v.storekeeper);
	position(a.storekeeper, 61, counterY);

[ slow him down
	work = 2;
	step.time(a.storekeeper, work);
	cycle.time(a.storekeeper, work);
	draw(a.storekeeper);

	if ((positionEgo || current.status == fly)){
		position(ego, 117, 136);
		if (current.status == normal.ego){
			set(next);				[ start the store keeper script
			move.obj(ego, 92, 136,1, ego.there);
		} else {
			script = wandering;
			set(next);
		}
	}

	if (current.status == deferred.entry){
		set(positionEgo);
		set(drawEgo);
		set(next);				[ start the store keeper script
		position(ego, 92, 136);
	}
			
	if (drawEgo){
		draw( ego);
	}

	show.pic();
	sound(m.store, sound.done);
	return();
}




[ end of move obj in

if (ego.there){
	reset(ego.there);
	start.motion(ego);
}

	
if (ego.poofing.done){
	set(next);
	if (current.status != normal.ego){
		script = wandering;
		script.timer = 0;
	}
}
	
ego.location = nowhere;

if (posn(ego, 58, 131 ,108, 133)){
	ego.location = near.counter;
}

if (posn(ego, 48, 131, 67, 140)){		[	stepping on dog
	wag.timer = 6;
	ego.location = near.dog;
}


[ Timer department

[ dog tail wag timer
if (aSecondPassed && wag.timer){
	start.cycling(a.store.dog);
	if (!handsOff){
		--wag.timer;
	}
	if (wag.timer == 0){
		set.cel(a.store.dog, 0);		[ asleep again
		stop.cycling(a.store.dog);
	}
}



[ store keeper runs on a script.  Follows, script controllers.

if (aSecondPassed && script.timer){
	if (!handsOff){
		--script.timer;
	}
	if (script.timer == 0){
		set(next);
	}
}



if (next && script == start.store){
	++script;
	script.timer = 0;
	x = 92;				[ ego after move.obj
	y = counterY;
	work = 1;
	start.cycling(a.storekeeper);
	move.obj.f(a.storekeeper, x, y, work, next);
}

if (next && script == greet.ego){
	++script;
	script.timer = 0;
	set.loop(a.storekeeper, 2);
	stop.cycling(a.storekeeper);
	reset(next);
	script.timer = 1;
}

if (next && script == get.response){
	++script;
	script.timer = 0;
	if (script.msg == 0){	[ first greeting
		print(26);
		++script.msg;
	} else {
		print(8);		[ a what to buy message
	}
	reset(next);
	script.timer = 30;		[ wait for a response for a long time
}

if (next && script == no.response){	[ if he responds, he won't get here
	++script;
	reset(get.single);
	script.timer = 0;
	print(13);			[  back to dusting
	set(next);			[ falls through this loop
}

if (next && script == wandering){
	++script;
	script.timer = 0;
	start.cycling(a.storekeeper);
	y = counterY;
	random(56, 92, x);
	work = 1;
	move.obj.f(a.storekeeper, x, y, work, next);
}

if (next && script == dusting){
	script.timer = 0;
	script = wandering;			[ repeat this sequence
	reset(next);
	set.loop(a.storekeeper, 3);	[ back view
	start.cycling(a.storekeeper);
	random(2, 3, script.timer);
}


if (next && script == start.pick){		[ buying something
	++script;
	script.timer = 0;
	y = counterY;
	center.x = ego.x;				[ save a position to return to
	random(56, 92, x);
	work = 1;
	start.cycling(a.storekeeper);
	move.obj.f(a.storekeeper, x, y, work, next);
	prevent.input();
	program.control();
}

if (next && script == pick.item){
	script.timer = 0;
	++script;
	set.loop(a.storekeeper, 3);	[ back view
	set.cel(a.storekeeper, 0);
	start.cycling(a.storekeeper);
	prevent.input();
	program.control();
	reset(next);

}

if (script == move.center) {		[ artificial end.of.loop
	current.cel(a.storekeeper, work);
	if (work == 6){
		set(next);
	}
}

if (next && script == move.center){
	script.timer = 0;
	++script;
	y = counterY;
	start.cycling(a.storekeeper);
	work = 1;
	move.obj.f(a.storekeeper, center.x, y, work, next);
	prevent.input();
	program.control();
}

if (next && script == store.done){		[ print the got message
	reset(next);
	print.f(buy.msg);
	set.loop(a.storekeeper, 2);
	print(27);					[ any thing else
	set(get.single);
	stop.cycling(a.storekeeper);
	script = no.response;
	script.timer = 10;				[ time before he wanders
	accept.input();
	player.control();
}



[ accounting department

if (old.gold != gold.coin.count){
	old.gold = gold.coin.count;	
	if (gold.coin.count == 0){
		if (has(i.purse.with.coins)){
			drop(i.purse.with.coins);
		}
		get(i.purse.empty);
	}
}


[*****
:handle.input
[*****

if (have.input){

	if (said(dog, last)){
		print(46);
	}

	if ((said(look) ||
		said(look, room) || 
		said(look, store)))					{print(2);}
	
	if ((said(look, goods) ||
		said(look, shelves)))				{print(3);}
	
	if ((said(look, clerk) ||
		said(look, store, clerk)))			{print(4);}
	
	if ((said(look, out, window) ||
		said(look, out, door) ||
		said(look, outside)))				{print(5);}


	if ((said(look, on, floor) || said(look, floor))){
		print(47);
	}

	if (said(look, door)){
		print(1);
	}
	
	if ((said(look, stove) ||
		said(look, woodstove)))				{print(6);}

	if (said(pet, dog)){
		if (ego.location != near.dog){
			print(38);
		} else {
			wag.timer = 5;
			if (!obj.in.room(i.dog.hair, current.room)){
				print(40);
			} else {
				get(i.dog.hair);
				score += 1;
				print(41);
			}
		}
   	}
		
	if ((said(get, fur) || said(get, dog, fur) || said(get, fur, dog))){
		if (!obj.in.room(i.dog.hair, current.room)){
			print(42);
		} else {
			if (ego.location != near.dog){
				print(38);
			} else {
				wag.timer = 6;
				get(i.dog.hair);
				score += 1;		[ also gotten above
				print(41);
			}
		}
	}
	
	if (said(talk, dog)){
		wag.timer = 6;
		print(43);
	}

	if (said(look, dog)){
		print(44);
	}
	
	if ((said(kick, dog) ||	said(eat, dog))){
		print(45);
	}

	if (said(get, dog)){
		print(49);
	}

	if (said(get, man)){
		print(51);
	}

	if ((said(kill, dog) || said(kill, man))){
		print(50);
	}


	if (said(get, anyword)){
		print(17);
	}

	if (said(jump)){
		print(18);
	}

	if ((said(jump, counter) || said(jump, over, counter))){
		print(28);
	}

	
	if (said(steal, anyword)){
		print(7);
	}
	
	if (said(buy)){
		print(8);
	}
	
	
	if (said(buy, anyword)){
		if (ego.location != near.counter){
			print(19);
		} else {
			if (gold.coin.count == 0){		[ he hasn't the money
				print(10);				[no tickee no laundry	  
			}else{					
				reset(have.match);			[ only charge for matches
				if (said(buy, salt)){
					if (!obj.in.room(i.salt, current.room)){
						print(30);
						goto AlreadyHasIt;
					}
					get(i.salt);
					score += 1;
				}
				if (said(buy, lard)){
					if (!obj.in.room(i.lard, current.room)){
						print(30);
						goto AlreadyHasIt;
					}
					get(i.lard);
					score += 1;
				}
				if ((said(buy, fish, oil) || 	said(buy, oil)
					 || said(buy, fish$oil))){
					if (!obj.in.room(i.fish.oil, current.room)){
						print(30);
						goto AlreadyHasIt;
					}
					get(i.fish.oil);
					score += 1;
				}
				if ((said(buy, pouch) || said(buy, leather, pouch))){
					if (!obj.in.room(i.empty.pouch, current.room)){
						print(30);
						goto AlreadyHasIt;
					}
					get(i.empty.pouch);
					score += 1;
				}
				if (have.match){			[ this costs him
					random(21, 25, buy.msg);
					--gold.coin.count;
					script.timer = 0;
					script = start.pick;
					set(next);
				}
:AlreadyHasIt
				if (said(buy, food)){
					print(11);
				}
			
				if (said(buy, supplies)){
					print(12);
				}
		
				if ((said(buy, beer) || said(buy, wine)
					 || said(buy, rum))){
					print(11);
				}



			[ catch the fallout (poorly)
				if (said(buy, anyword)){
					print(15);
				}
			}
		}
	}	[ end of buying if

	if (said(talk, storekeeper)){
		if (ego.location != near.counter){
			random(31, 37, work);			[ casual conversation
			print.f(work);
		} else {
			script = start.store;			[ show intent to purchase
			set(next);
		}
	}
}	[ end of no input

[*****
:exit							[	test for leaving the room
[*****

if (hit.special) {
	new.room(24);
} else {
	if (x > 123){
		new.room(24);
	}
}




