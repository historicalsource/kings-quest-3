[ rm66.cg
[ in the dragon's demense

#include	"gamedefs.reh"
#include	"rm66.msg"



#define	storm.length		10		[ seconds of storming

#define	bolt.done			lf0
#define	blow.1			lf1
#define	blow.2			lf2
#define	done.1			lf3
#define	done.2			lf4
#define	ego.in			lf5		[ ego in range of fire
#define	head.done			lf6
#define	crisp.ego			lf7
#define	charred			lf8
#define	crisp.girl		lf9
#define	charred.girl		lf10
#define	girlFreed			lf11
#define	will.be.burned		lf12
						
#define	bolt.timer		lv0
#define	storm.timer		lv1
#define	head.timer		lv2
#define	live.head			lv3
#define	move.x			lv4
#define	hitTimer			lv5



if (init.log){

	set(beenIn66);
	map.area = map.clouds;

	set.horizon(55);

	landing.x = 18;
	landing.y = 101;


	[ sounds
	load.sound(s.ego.falling);
	load.sound(s.dragon.fire);
	load.sound(s.lightning);
	load.sound(s.thunder);

	animate.obj(aBolt);
	load.view(v.lightning);
	set.view(aBolt, v.lightning);
	set.priority(aBolt, 9);			[ in front of heads
	ignore.horizon(aBolt);
	ignore.objs(aBolt);
	set.cel(aBolt, 1);
	position(aBolt, 30, 35);
	stop.cycling(aBolt);
	draw(aBolt);					[ every thing but the draw


	[ do the dragons heads
	if (!dragonDead){
		load.pic(current.room);
		draw.pic(current.room);
		discard.pic(current.room);

		load.view(v.dragonhead);
[			load.view(v.dragon.roaring);

		animate.obj(aHead1);
		set.priority(aHead1,8);
		ignore.horizon(aHead1);
		ignore.blocks(aHead1);
		ignore.objs(aHead1);
		set.view(aHead1, v.dragonhead);
		set.loop(aHead1, 0);
		work = 3;
		cycle.time(aHead1, work);
		position(aHead1, 52,64);
		set.cel(aHead1, 3);
		draw(aHead1);

		animate.obj(aHead2);
		set.priority(aHead2,8);
		ignore.horizon(aHead2);
		ignore.blocks(aHead2);
		ignore.objs(aHead2);
		set.view(aHead2, v.dragonhead);
		set.loop(aHead2, 1);
		work = 2;
		cycle.time(aHead2, work);
		position(aHead2, 67, 30);
		draw(aHead2);

		animate.obj(aHead3);
		set.priority(aHead3,8);
		ignore.horizon(aHead3);
		ignore.blocks(aHead3);
		ignore.objs(aHead3);
		set.view(aHead3, v.dragonhead);
		set.loop(aHead3, 2);
		work = 3;
		cycle.time(aHead3, work);
		position(aHead3, 107, 52);
		draw(aHead3);

		set(head.done);

		[ flames don't go all the time
		load.view(v.dragon.flame);

		animate.obj(aFlame1);
		set.view(aFlame1, v.dragon.flame);
		set.loop(aFlame1, 1);
		fix.loop(aFlame1);
		set.priority(aFlame1, 11);
		ignore.objs(aFlame1);
		ignore.horizon(aFlame1);
		ignore.blocks(aFlame1);
		work = 2;
		cycle.time(aFlame1, work);

		animate.obj(aFlame2);
		set.view(aFlame2, v.dragon.flame);
		set.loop(aFlame2, 0);
		fix.loop(aFlame2);
		set.priority(aFlame2, 11);
		ignore.objs(aFlame2);
		ignore.horizon(aFlame2);
		ignore.blocks(aFlame2);
		work = 2;
		cycle.time(aFlame2, work);

	} else {
		work = 166;
		load.pic(work);
		draw.pic(work);
		discard.pic(work);
	}


	[ get the princess logic in
	load.logics(lgc.princess);
	call(lgc.princess);

	[ ego stuff
	load.view(v.ego);
	load.view(v.ego.falling);
	load.view(v.ego.burning);

	load.view.f(current.ego);
	set.view.f(ego,current.ego);
	get.posn(ego, ego.x, ego.y);
	if (positionEgo){
		ego.y = 106;				[ make his feet visible
		if (previous.room == 67){	[ to the right
			ego.x = 152;
			move.x = -10;
		}
		if (previous.room == 65) {	[ to the left
			ego.x = 0;
			move.x = 18;
		}

		position.f(ego, ego.x, ego.y);
		if (!dragonDead &&			[ get ready to char him!
			current.status == normal.ego &&
		    !invisibleEgo)
			{
			prevent.input();
			ego.x +=	move.x;
			move.obj.f(ego, ego.x, ego.y, one, ego.in);
			set(will.be.burned);
		}
	}

	if (drawEgo){
		draw(ego);
	}

	show.pic();
	return();
}

if (!dragonDead && spell.cast == sc.visible) {
	spell.cast = 0;
	magic.minutes = 0;
	magic.seconds = 30;
}

if (!dragonDead && invisibleEgo){
	if (magic.minutes == 0 && magic.seconds < 40){
		magic.seconds = 40;
	}
}


if (!dragonDead &&
	ego.poofing.done &&
	current.status == normal.ego)
	{
	set(ego.in);
	reset(will.be.burned);
	}

if (girlSaved && !dragonDead){
	reset(girlSaved);
	set(crisp.girl);
	set(ego.in);
	reset(will.be.burned);
}

if (ego.in) {				[ initial move.obj to be toasted or bad move
	reset(will.be.burned);
	stop.motion(ego);
	program.control();
	if (head.done && !blow.1 && !blow.2) {	[ free to start a new one
		reset(ego.in);
		head.timer = 0;
		if (ego.x > 80){
			live.head = 3;
		} else {
			live.head = 1;
		}
		if (crisp.girl){
			print.at(5, 14, 2, 37);
		} else {
			print.at(4, 14, 2, 37);
		}
		set(crisp.ego);	[ flag to flame code
		goto giveHead;
	}
}

if (!dragonDead) [ instead of finding what's still running I will skip it all
	{
	[ Dragon head control
	if (head.done && !head.timer) {	[ time to pick a new head
		random(1, 3, live.head);
	
	:giveHead
		reset(head.done);
		if (live.head == 1) {
			stop.update(aHead2);		
			stop.update(aHead3);
			start.update(aHead1);
			set.cel(aHead1, 0);
			end.of.loop(aHead1, head.done);
		}
		if (live.head == 2) {
			stop.update(aHead1);		
			stop.update(aHead3);
			start.update(aHead2);
			current.cel(aHead2, work);
			last.cel(aHead2, cell);
			start.cycling(aHead2);
			if (work == cell){		[ must be at end of loop?
				reverse.loop(aHead2, head.done);
			} else {
				end.of.loop(aHead2, head.done);
			}
		}
		if (live.head == 3) {
			stop.update(aHead1);		
			stop.update(aHead2);
			start.update(aHead3);
			set.cel(aHead3, 0);
			end.of.loop(aHead3, head.done);
		}
	}
	
	if (head.timer) {
		--head.timer;
	}
	
	
	[ blow some flames
	
	current.cel(aHead1, work);
	if (!will.be.burned && work == 2 && !blow.1 && !dragonDead) {
		++work;
		set.cel.f (aHead1, work);
		set(blow.1);
		position(aFlame1, 22, 83);
		set.cel(aFlame1, 0);
		draw(aFlame1);
		if (sound.done){
			sound(s.dragon.fire, sound.done);
		}
		start.cycling(aFlame1);
	[ move flame closer to girl
		if (crisp.girl){
			move.obj(aFlame1, 0, 166, 1, done.1);
		}
		stop.update(aHead1);
	}
	
	
	current.cel(aHead3, work);
	if (!will.be.burned && work == 2 && !blow.2 && !dragonDead) {
		++work;
		set.cel.f (aHead3, work);
		set(blow.2);
		position(aFlame2, 118, 80);
		set.cel(aFlame2, 0);
		draw(aFlame2);
		start.cycling(aFlame2);
		if (sound.done){
			sound(s.dragon.fire, sound.done);
		}
	[	move.obj(aFlame2, 126, 82, 1, done.2);
		start.update(aHead3);
	}
	
	current.cel(aFlame1, work);
	if (blow.1 && work == 5){
		erase(aFlame1);
		reset(blow.1);
		normal.motion(aFlame1);
		start.update(aHead1);
		goto crispChk;
	}
	
	current.cel(aFlame2, work);
	if (blow.2 && work == 5){
		erase(aFlame2);
		reset(blow.2);
		normal.motion(aFlame2);
		start.update(aHead3);
	
	:crispChk
		if (crisp.ego) {
			reset(crisp.ego);
			set(handsOff);
			set.view(ego, v.ego.burning);
			set.cel(ego, 0);
			set(keep.cycling);
			work = 4;
			cycle.time(ego, work);
			end.of.loop(ego, charred);
			current.status = normal.ego;
			if (crisp.girl){
				reset(crisp.girl);
				set.view(aPrincess, v.princess.burned);
				set.cel(aPrincess, 0);
				start.cycling(aPrincess);
				end.of.loop(aPrincess, charred.girl);
			}
		}
	}
	
	if (charred.girl){
		reset(charred.girl);
		stop.motion(aPrincess);
		stop.cycling(aPrincess);
	}
	
	
	if (charred) {		[ burnt by dragon
		reset(charred);
		reset(keep.cycling);
		program.control();
		stop.cycling(ego);
		erase(aFlame1);
		erase(aFlame2);
		start.update(aHead2);
		start.update(aHead1);
		start.update(aHead3);
		stop.cycling(ego);
		set(certain.death);
		stop.cycling(ego);
	}
} [ end of live dragon animation 

	
call(lgc.princess);					[ she may be charred too

[****** SAID STUFF ******]

if (spell.cast == sc.map){
	spell.cast = 0;
	drop(i.magic.map);
	print(22);
}

[ do a mini-cartoon to kill dragon
	
if (spell.cast == sc.start.storm){
	stop.motion(ego);
	program.control();
	prevent.input();
	set(handsOff);
	spell.cast = 0;				[ 	I'll handle this one...
	erase(aFlame1);
	erase(aFlame2);
	score += 7;

	work = 88;
	load.pic(work);
	draw.pic(work);
	discard.pic(work);

	load.view(v.dragon.roaring);
	set.view(aHead1, v.dragon.roaring);
	set.loop(aHead1, 0);
	set.view(aHead2, v.dragon.roaring);
	set.loop(aHead2, 1);
	set.view(aHead3, v.dragon.roaring);
	set.loop(aHead3, 2);
	show.pic();
	force.update(aHead1);
	force.update(aHead2);
	force.update(aHead3);
	
	[ here is where we pause the game for some really neat stuff
	stop.update(ego);
	stop.update(aPrincess);
	storm.timer = storm.length;
	
	
	
	set.scan.start();				[ the show begins


	if (bolt.timer > 8)
		{
		stop.cycling(aBolt);
		}
	else
		{
		if (bolt.timer == 8)
			{
			stop.update(aHead1);
			stop.update(aHead2);
			stop.update(aHead3);
			}
		start.cycling(aBolt);
		sound(s.lightning, sound.done);
		}
	
	if (!bolt.timer)
		{
		sound(s.thunder, sound.done);
		shake.screen(1);
		random(10, 15, bolt.timer);
		random(47, 115, x);
		random(32,40, y);
		reposition.to.f(aBolt, x, y);
		random(0,1,loop);
		set.loop.f(aBolt, loop);
		set.cel(aBolt, 1);
		stop.cycling(aBolt);
		start.update(aHead1);
		start.update(aHead2);
		start.update(aHead3);
		}
	
	--bolt.timer;
	
	if (aSecondPassed)
		{
		--storm.timer;
		if (storm.timer == 1)
			{
			print(9);
			}
		}

	if (storm.timer)
		{
		return();
		}
	else
		{
		reset(handsOff);
		erase( aBolt);

		set(dragonDead);
		stop.update(aHead1);
		stop.update(aHead2);
		stop.update(aHead3);
		set.priority(aHead1,0);
		set.priority(aHead2,0);
		set.priority(aHead3,0);
		set.view(aHead1, v.dragonhead);
		set.view(aHead2, v.dragonhead);
		set.view(aHead3, v.dragonhead);

		discard.view(v.dragon.roaring);
		
		work = 166;
		load.pic(work);
		draw.pic(work);
		discard.pic(work);
		show.pic();

		magic.minutes = 0;			[ make ego visible in a short while
		magic.seconds = 5;
		start.update(ego);
		start.update(aPrincess);
		player.control();
		start.motion(ego);



		reset.scan.start();
		}
	}


	
if (said(kill, dragon))
	{
	if (!dragonDead)
		{
		print(12);
		}
	else
		{
		print(13);
		}
	}

if ((said(throw, knife) || 
	said(throw, knife, dragon) || 
	said(kill, dragon, with, knife))){
	if (!has(i.knife)){
		print(19);
	} else {
		if (dragonDead){
			print(21);
		} else {
			print(20);
		}
	}
}



if ((said(look) || said(look,cloud))){
	print(1);
}

if (said(look,dragon)){
	if (!dragonDead){
		print(2);
	} else {
		print(3);
	}
}

if (said(talk,dragon)){
	if (!dragonDead){
		print(10);
	} else {
		print(11);
	}
}

if (said(look, tree)){
	print( 14);
}

if (said(look, plant)){
	print( 15);
}

if ((said(climb, up, tree) ||
	said(climb, tree))){
	print( 16);
}

if ((said(look, up, sky) ||
	said(look, sky))){
	print( 17);
}

if ((said(look, on, ground) ||
	said(look, ground))){
	print( 18);
}

if  (current.status == normal.ego &&	[	falling off the edge
    (ego.y > 162 ||
	edge.ego.hit == top))
	{
	if (invisibleEgo)
		{
		print(7);
		}
	else
		{
		print( 23);
		}

	sound(s.ego.falling, sound.done);
	erase(ego);
	hitTimer = 2;
	set.scan.start();
	if (aSecondPassed){
		--hitTimer;
	}
	if (!hitTimer){
		if (invisibleEgo)
			{
			print(8);
			}
		else
			{
			print( 24);
			}

		reset.scan.start();
		erase(aFlame1);
		erase(aFlame2);
		start.update(aHead1);
		start.update(aHead2);
		start.update(aHead3);
		erase(aBolt);
		stop.cycling(ego);
		set(certain.death);
	}
	return();
}




[ ****** PAINLESS ROOM EXITS ******

if (edge.ego.hit == 2){				[ right
	new.room( 67);
}

if (edge.ego.hit == 4){				[ left
	new.room( 65);
}

