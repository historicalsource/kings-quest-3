[ rm61.cg
[ outside the cave of the steps

#include	"gamedefs.reh"
#include	"rm61.msg"


#define	hitBottom		lf0
#define	egoFalling	lf1

#define	egoLoc		lv0
	#define	toSteps	1
	#define	toDeath	2
	#define	isStunned	3

#define	stunTimer		lv1

if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	landing.x = 14;
	landing.y = 123;

	map.area = map.clouds;

	load.view(v.ego.stunned);
	load.view(v.ego.falling);
	load.view(v.ego);

	load.view.f(current.ego);
	set.view.f(ego,current.ego);

[ sound stuff
	load.sound(s.ego.falling);
	load.sound(s.ego.stunned);


	if (positionEgo){
		get.posn(ego, ego.x, ego.y);
		if (previous.room == 59){
			position(ego, 103, 40);	
		}
		if (previous.room == 62){
			position(ego, 108, 79);
		}
		if (previous.room == 68){
			ego.x = 2;
			position.f(ego, ego.x, ego.y);
		}
	}
	if (drawEgo){
		draw(ego);
	}

	if (girlSaved){
		load.logics(lgc.princess);
		call(lgc.princess);
	}

	show.pic();

[ this is a new map area so we must clear the last areas beenIn flags
	if (!beenIn61){
		set(beenIn61);
		work = firstIn61;		[ start at end of range
:clrFlags
		if (work > lastIn61){		[ equal to this rooms beenIn flag
			reset.v(work);
			--work;
			goto clrFlags;
		}
	}

	return();
}



[ falling in chasm
[ egoFalling in the chasm
if (!handsOff && hit.special && !egoFalling){
	set(handsOff);
	current.status = falling;
	sound(s.ego.falling, sound.done);
	set(egoFalling);
	ignore.blocks(ego);
	ignore.objs(ego);
	get.priority(ego,work);
	set.priority.f(ego,work);
	set.view(ego,v.ego.falling);
	if (posn(ego, 86, 32, 120, 71)){	[ top screen
		egoLoc = toSteps;
		y = 94;
		x = 101;
		work = 3;
		set.priority(ego,15);
	} else {
		egoLoc = toDeath;
		x = ego.x;
		y = 164;
		work = 4;
	}
	move.obj.f(ego,x,y,work,hitBottom);
}

if (hitBottom){
	stop.sound();
	reset(hitBottom);
	reset(egoFalling);
	reset(handsOff);
	if (egoLoc == toDeath){
		erase(ego);
		set(certain.death);
		print(10);
	} else {
		print(11);
		program.control();
		current.status = stunned;
		sound(s.ego.stunned, sound.done);
		stunTimer = ego.stunned.time;
		set.view(ego, v.ego.stunned);
		set(keep.cycling);
		set.scan.start();
		if (aSecondPassed) {
			--stunTimer;
		}
		if (!stunTimer) {
			reset(keep.cycling);
			player.control();
			set.view(ego,v.ego);
			observe.blocks(ego);
			observe.objs(ego);
			release.priority(ego);
			release.loop(ego);
			current.status = normal.ego;
			work = 1;
			cycle.time(ego, work);
			reset.scan.start();
		}
		if (stunTimer && sound.done) {
			sound(s.ego.stunned, sound.done);
		}
		return();
	}
}

[ princess dynamic
if (girlSaved){
	call(lgc.princess);
}



[****** SAID STUFF ******]

if ((said(look, room) || said(look, mountain) || said(look))){
	print(1);
}

if ((said(look$in, cave) || said(look, cave))){
	print(2);
}

if ((said(look$in, chasm) || said(look, chasm) || said(look, over, chasm))){
	print(3);
}

if ((said(jump, over, chasm) || 
	said(climb, chasm) || 
	said(climb, down, chasm) || 
	said(jump, down, chasm) || 
	said(go, across, chasm) || 
	said(jump, chasm))){
	print(12);
}


if ((said(look, plants) ||
	said(look, trees))){
		print(4);
}

if (said(look, ground)){
	print(5);
}

if (said(look,sky)){
	print(6);
}

if ((said(look,flowers) ||
	said(get,flowers))){
	print(7);
}

if (said(look,steps)){
	print(8);
}

if (said(climb,tree)){
	print(9);
}

if ((said(jump, over, chasm) || said(climb, down) || said(jump, chasm))){
	print( 12);
}


[ ****** PAINLESS ROOM EXITS ******

if (current.status == normal.ego && obj.in.box(ego,118,59,133,68)){
	new.room(62);
}

if (edge.ego.hit == left){
	new.room(68);
}


