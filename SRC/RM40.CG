[logics for room -- 40:inside tavern

%include "gamedefs.reh"
%include "rm40.msg"

#define	inPort.init.minutes		15
#define	allAboard				5


%define	near.table			1
%define	near.bar				2

%define	drunk.time			50
%define	pirate.msg.start		28
%define	pirate.msg.end			31



%define	customers				lv1
	%define	none			0
	%define	pirates		1
	%define	bandits		2

%define	msg.count				lv2
%define	old.gold				lv3
%define	msg					lv4

#define	script				lv5
	#define	behind.bar	0
	#define	to.stove		1
	#define	to.table		2
	#define	at.table		3
	#define	back.to.stove	4
	#define	back.to.bar	5
	#define	back.at.bar	6

#define	script.timer			lv6
#define	sober.up				lv7
#define	drunk.timer			lv8
#define	how.drunk.to.get		lv9
#define	fly.timer				lv10	[ provides delay to hear bandits

%define	money.to.burn			lf0	[ has money with him
%define	heard.bandits			lf1
%define	talking.to.pirates		lf2
%define	serve.bar				lf3
%define	captain.pissed			lf4
#define	next					lf5
#define	talked.bandits			lf6
#define	staggering			lf7
#define	free.booze			lf8


%object	a.pirate.1			1
%object	a.bandit.1			1	[ XOR in room
%object	a.pirate.2			2
%object	a.bandit.2			2	[ XOR in room
%object	a.captain				3
%object	a.bartender			4



if (init.log) {
	wiz.x = 89;
	wiz.y = 154;

	landing.x = 91;
	landing.y = 153;

	set(interiorRoom);
		
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	load.view(v.ego);
	load.view.f(current.ego);
	set.view.f(ego, current.ego);
	if ((positionEgo || current.status == fly)) {
		position(ego, 72, 165);
	}


	if (current.status == fly){
		fly.timer = 7;
	}

	block(59, 128, 62, 131);			[ who knows what this is blocking

[ the bartender is a broad
	animate.obj(a.bartender);
	load.view(v.bartender);
	set.view(a.bartender, v.bartender);
	position(a.bartender, 78, 121);
	draw(a.bartender);
	stop.cycling(a.bartender);
	set.loop(a.bartender, facing.front);

	how.drunk.to.get = 5;		[ increases geometricaly with each drink

[ select some patrons 	(customers)

	if (shipShape == inPort) {		[ pirates are highest priority
		customers = pirates;
		load.view(v.pirate.drinking);	[ all pirates are loops in this view

	[ captain
		animate.obj(a.captain);
		set.view(a.captain, v.pirate.drinking);
		position(a.captain, 58, 149);
		set.loop(a.captain, 2);
		set.cel(a.captain, 3);
		stop.cycling(a.captain);
		draw(a.captain);
	
	[ first mate
		animate.obj(a.pirate.1);
		set.view(a.pirate.1, v.pirate.drinking);
		position(a.pirate.1, 43, 154);
		set.loop(a.pirate.1, 0);
		set.cel(a.pirate.1, 0);
		stop.cycling(a.pirate.1);
		draw(a.pirate.1);

	[ check mate
		animate.obj(a.pirate.2);
		set.view(a.pirate.2, v.pirate.drinking);
		position(a.pirate.2, 52, 152);
		set.loop(a.pirate.2, 1);
		set.cel(a.pirate.2, 2);
		stop.cycling(a.pirate.2);
		draw(a.pirate.2);
	} else {
		random(1, 3, work);
		if (work < 2) {					[ bandits are in town
			customers = none;
		} else {
			customers = bandits;
			load.view(v.bandits.drinking);	[ both bandits look like podlings
			
		[ a bandit
			animate.obj(a.bandit.1);
			set.view(a.bandit.1, v.bandits.drinking);
			position(a.bandit.1, 41, 143);
			set.loop(a.bandit.1, 1);
			set.cel(a.bandit.1, 0);
			set.priority(a.bandit.1, 13);
			stop.cycling(a.bandit.1);
			ignore.objs(a.bandit.1);
			draw(a.bandit.1);

		[ a misunderstood kind of guy	
			animate.obj(a.bandit.2);
			set.view(a.bandit.2, v.bandits.drinking);
			position(a.bandit.2, 52, 152);
			set.loop(a.bandit.2, 0);
			set.cel(a.bandit.2, 0);
			set.priority(a.bandit.2, 14);
			stop.cycling(a.bandit.2);
			draw(a.bandit.2);
		}
	}

	if (drawEgo){
		draw( ego);
	}

	script = to.stove;
	if (customers != none){	[ order some drinks
		random(3,7, script.timer);
	}
[ pick some sounds
	if (customers == pirates){
		load.sound(m.pirate);
		sound(m.pirate, sound.done);
	}
	if (customers == bandits){
		load.sound(m.badguy);
		sound(m.badguy, sound.done);
	}
	if (customers == none){
		load.sound(m.tavern);
		sound(m.tavern, sound.done);
	}

	show.pic();
	return();

}



[ keep ship in port
if (shipShape == inPort && !voyage.minutes
 && voyage.seconds < 30 && voyage.seconds > 0){
	voyage.seconds = 30;
}

ego.location = nowhere;
if (posn(ego, 40, 134, 73, 162))
	{
	ego.location = near.table;
	}

if (posn(ego, 56, 124, 114, 133))
	{
	ego.location = near.bar;
	}


[ bartender script area.  Runs on next flag

if (aSecondPassed && script.timer){
	if (!handsOff){
		--script.timer;
	}
	if (script.timer == 0){
		set(next);
	}
}

if (next && script == behind.bar){		[ this is where we wait to serve
	++script;
	stop.cycling(a.bartender);
	set.loop(a.bartender, facing.front);
	reset(next);
}

if (next && script == to.stove){		[ go to stove
	if (!free.booze){	[ ego is NOT buying
		if (customers == pirates){
			print(1);
		} else {
			print(50);
		}
	}
	reset(free.booze);
	++script;
	start.cycling(a.bartender);
	move.obj(a.bartender, 49, 125, 1, next);
}

if (next && script == to.table){
	++script;
	start.cycling(a.bartender);
	move.obj(a.bartender, 49, 140, 1, next);
}

if (next && script == at.table){		[ timed wait at table
 	++script;
	stop.cycling(a.bartender);
	reset(next);
	script.timer = 3;
}

if (next && script == back.to.stove){
	++script;
	start.cycling(a.bartender);
	move.obj(a.bartender, 49, 125, 1, next);
}

if (next && script == back.to.bar){
	++script;
	start.cycling(a.bartender);
	move.obj(a.bartender, 77, 125, 1, next);
}


if (next && script == back.at.bar){	[ all done, set up for next
	script = behind.bar;			[ goes to start next
	stop.cycling(a.bartender);
	move.obj(a.bartender, 77, 121, 1, next);
	random(30, 120, script.timer);
}

[*****
[ make customers drink
[*****

random(1, 20, work);
if (customers == pirates) {
	if (work == 1)	{
		last.cel(a.captain, x);
		current.cel(a.captain, y);
		++y;
		if (y > x) {
			y = 0;
		}
		if (talking.to.pirates){
			y = 0;
		}
		set.cel.f(a.captain, y);
	}

	if (work == 2)	{
		last.cel(a.pirate.1, x);
		current.cel(a.pirate.1, y);
		++y;
		if (y > x) {
			y = 0;
		}
		set.cel.f(a.pirate.1, y);
	}

	if (work == 3) {
		last.cel(a.pirate.2, x);
		current.cel(a.pirate.2, y);
		++y;
		if (y > x) {
			y = 0;
		}
		set.cel.f(a.pirate.2, y);
	}
}


if (customers == bandits) {
	if (work == 1) {
		last.cel(a.bandit.1, x);
		current.cel(a.bandit.1, y);
		++y;
		if (y > x) {
			y = 0;
		}
		set.cel.f(a.bandit.1, y);
	}

	if (work == 2) {
		last.cel(a.bandit.2, x);
		current.cel(a.bandit.2, y);
		++y;
		if (y > x) {
			y = 0;
		}
		set.cel.f(a.bandit.2, y);
	}
}	


[ don't let him sit down if customers are here
if (customers != none && posn(ego, 33, 138, 70, 154) &&
	(current.status == normal.ego || current.status == drunk)) {	[table
	start.motion(ego);
	reposition.to.f(ego, old.ego.x, old.ego.y);
}




if (aSecondPassed && sober.up){
	--sober.up;
	if (sober.up == 0){
		reset(staggering);
		player.control();
		release.loop(ego);
		current.status = normal.ego;
	}
}

[ Scott Murphy's drinking problem

if (current.status == drunk && ego.dir != 0) {
	--drunk.timer
	if (drunk.timer == 1) {
		if (staggering) {
			reset(staggering);
			player.control();
			release.loop(ego);
			drunk.timer = 6;
		} else {
			set(staggering);
			program.control();
			fix.loop(ego);
:zz
			random(1,8,work);
			if (work == ego.dir) {
				goto zz;
			}
			ego.dir = work;
			drunk.timer = 5;
		}
	}
}


if (ego.poofing.done && current.status == fly){
	fly.timer = 7;
}

if (aSecondPassed){
	--fly.timer;
	if (fly.timer == 1 && current.status == fly &&
	 	posn(ego, 0, 0, 160, 160)
		   && customers == bandits && !heard.bandits) {
		print(11);
		set(heard.bandits);
		score += 3;
	}
}


if (talking.to.pirates && !captain.pissed) {
	--timer.2;
	if (timer.2 == 0) {
		print.f(msg.count);
		++msg.count;
		timer.2 = 200;
		if (msg.count == pirate.msg.end) {
			set(captain.pissed);
		}
	}
}


[*****
[accounting dept
[*****

if (old.gold != gold.coin.count)
	{
	old.gold = gold.coin.count;	
	if (gold.coin.count == 0)
		{
		if (has(i.purse.with.coins))
			{
			drop(i.purse.with.coins);
			}
		get(i.purse.empty);
		}
	}


[ does he have money on him?
if (has(i.purse.with.coins) && gold.coin.count > 0){
	set(money.to.burn);
} else {
	reset(money.to.burn);
}

[*****
[handle.input
[*****

if (have.input){	[ /* a real time saver */



	if ((said(sit, table) || said(sit, down, table))){
		if (customers == none){
			print(44);
		} else {
			print(45);
		}
	}




	work = customers;
	if ((said(look) || said(look, room) || said(look, tavern) ||
		said(look$in, bar)))
		{
		addn(work, 3);			[msgs 2 + 3, 4, 5
		print.f(work);
		}
	
	if ((said(look, kegs) ||  said(look$in, kegs))){
		print(46);
	}

	if (said(look, table)){
		if (customers == none){
			print(49);
		} else {
			addn(work, 7);			[msgs  7, 8, 9
			print.f(work);
		}
	}


	if ((said(look, customers) ||
		said(look, men)))			[syn. to bandit & sailor
		{
		addn(work, 7);			[msgs  7, 8, 9
		print.f(work);
		}

	if (said(look, barmaid))					{print(10);}

	if ((said(look, out, window) || said(look, window) ||
		said(look, door) ||
		said(look, outside)))				{print(12);}

	if (said(open, window)){
		print(53);
	}


	if ((said(get, men) || said(touch, stove) ||
		said(get, stove) ||
		said(kill, anyword))) 				{print(13);}

	if (said(look, stove))					{print(14);}

	if (said(look, bar))					{print(15);}

	if ((said(look, swords) ||
		said(look, tapestry) ||
		said(look, wall)))					{print(16);}

	if ((said(get, swords) ||
		said(get, tapestry))){
		print(17);
	}

	if (said(look, under, tapestry)){
		print(18);
	}

	if (said(get, beer)){
		print(47);
	}
	
	if ((said(look, shelf) || said(look, bottle))){
		print(2);
	}

	if (said(look, beer)){
		print(54);
	}
		 
	if ((said(get, girl) || said(kiss, girl))){
		print(48);
	}
		

	if (customers == none){
		if ((said(talk) ||
			said(talk, barmaid)))			{print(19);}

		if ((said(talk, men) ||
			said(look, men)))				{print(23);}	[m none
	}

[ buying a round
	if ((said(order, drinks) || said(order, drinks, men))){
		if (customers == none){
			print(7);
		} else {
			if (!money.to.burn){
				print(20);	[ no money
			} else {
				--gold.coin.count;
				if (script == to.stove){	[ ready to serve
					print(51);
					script.timer = 2;	[ force the serve
					set(free.booze);
				} else {
					print(52);
				}
			}
		}
	}

	if ((said(buy, drink) || said(buy, beer) || 
		said(buy, liquor))) {
		if (script != to.stove){
				print(27);
		} else {
			if (ego.location == near.bar) {
				if (!money.to.burn){
					print(20);
				} else {
					--gold.coin.count;
					if (how.drunk.to.get < 120){
						how.drunk.to.get += how.drunk.to.get;
					}
					sober.up = how.drunk.to.get;
					drunk.timer = 10;
					if (current.status != drunk) {
						current.status = drunk;
						print(21);
[						shake.screen(1);
					} else {
						print(22);
					}
				}
			} else {			[ not near bar message
				print(37);
			}
		}
	}

	if (customers == pirates) {
		if ((said(talk) || said(talk, barmaid))) {
			print(34);
		}

		if (said(talk)) {
			print(24);
		}
		
		if (said(talk, men)) {
			if (!talking.to.pirates) {
				if (!voyage.minutes && !voyage.seconds){
					voyage.minutes = inPort.init.minutes;	[ 15 minutes
				} else {
					if (voyage.minutes < 5){
						voyage.minutes = 5;		[ give him a few minutes
					}
				}
				msg.count = pirate.msg.start;
				set(talking.to.pirates);
				script.timer = 0;			[ cancel a start of serve
			} else {
				timer.2 = 2;
			}

			if (captain.pissed) {
				print(25);
			}
		}

	[ this is showing gold to pirates
		if (talking.to.pirates && 
		    (said(give, gold, rol) || 
			said(give, purse, rol))){
			if (captain.pissed) {
				print(25);
			} else {
				reset(talking.to.pirates);
				if (money.to.burn){		[ purse and coins
					score += 3;
					drop(i.purse.with.coins);
					gold.coin.count = 0;
					customers = none;
					erase(a.pirate.1);
					erase(a.pirate.2);
					erase(a.captain);
					set(paid.pirates);
					print(32);
				} else {
					set(captain.pissed);
					if (has(i.purse.empty)) {
						drop(i.purse.empty);
					    print(42);
					} else {
						print(33);
					}
				}
			}
		}
	}
		
	if (customers == bandits){
		if ((said(talk) || said(talk, barmaid))){
			print(35);
		}
		if (said(talk)){
			print(24);
		}
		if (said(talk, men)){
			if (!talked.bandits){
				set(talked.bandits);
				print(26);
			} else {
				print(43);
			}
		}
		if (said(look, men)) {
			print(38);
		}
		if ((said(kill, men) || said(rob, men))){
			print(13);
		}

	}
}

[*****
[exit							[	test for leaving the room
[*****

if (edge.ego.hit == bottom && ego.x > 63 && ego.x < 75) {
	if (current.status == drunk){
		current.status = normal.ego;
	}
	new.room(24);
}

