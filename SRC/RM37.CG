[logics for room -- rm37:outside bandit hideout
[	February 3, 1988

%include "gamedefs.reh"
%include "rm37.msg"
#include	"rm-names.h"



%define	entering.hideout		1
%define	ladder.exit			2


%define	fall.done				lf0
#define	caught.ego			lf1

%object	a.bandit				1



if (init.log) {

	reset(handsOff);
	set(interiorRoom);

	if (!found.house){
		set(found.house);
		score +=2;
	}
[	wiz.x = 78;
[	wiz.y = 0;

	landing.x = 93;
	landing.y = 136;


	ignore.block(ego);

	load.view(v.ego);
	load.view(v.ego.falling);
	load.view(v.ego.climbing.ladder);
	load.view.f(current.ego);
	set.view.f(ego, current.ego);

	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

[ sound stuff
	load.sound(s.ego.falling);
	load.sound(s.ego.stunned);

	if (current.status == fly){
		set(positionEgo);
		set(drawEgo);
	}


	if (positionEgo) {
		if (previous.room == 38) {
			start.motion(ego);
			ego.dir = 3;
			position(ego, 83, 110);
			if (bandit.status == awake) { 	[ he's going to kill you
				animate.obj(a.bandit);
				load.view( v.bandit.1);
				set.view(a.bandit, v.bandit.1);
				ignore.blocks(a.bandit);
				ignore.objs(a.bandit);
				position(a.bandit, 70, 113);
				work = 2;
				cycle.time(a.bandit, work);
				draw(a.bandit);
				follow.ego(a.bandit,5, caught.ego);
				start.motion(ego);
				program.control();
			}
		} 
		if (previous.room == 22){			[entering from rm22
			current.status = climbing;
			position(ego, 93, 165);
			set.view(ego, v.ego.climbing.ladder);
			set.loop(ego, 0);
			fix.loop(ego);
	
		}
	}
	if (previous.room != rm.map && previous.room != 38){
	[ do the set up for the next room
		random(1, 255, work);
		if (work > 64) {
			bandit.status = awake;
		} else {
			bandit.status = asleep;
		}
	}

	if (current.status == deferred.entry){
		set(positionEgo);
		set(drawEgo);
		current.status = climbing;
		position(ego, 93, 165);
		set.view(ego, v.ego.climbing.ladder);
		set.loop(ego, 0);
		fix.loop(ego);
	}
		
	if (drawEgo){
		draw( ego);
	}

	show.pic();
	return();

	}

if (ego.poofing.done && current.status == normal.ego) {
	ignore.blocks(ego);
	current.status = climbing;
	set.view(ego, v.ego.climbing.ladder);
	set.loop(ego, 0);
	fix.loop(ego);
}


ego.location =  nowhere;
if (posn(ego, 89, 110, 91, 116))
	{
	ego.location = ladder.exit;
	}

if (posn(ego, 70, 98, 73, 114))
	{
	ego.location = entering.hideout;
	}


[*****
[Ladders pray
[*****

if (current.status == normal.ego && 	[enter top of ladder
	ego.location == ladder.exit &&
    (ego.dir == ego.right ||
	ego.dir == ego.down.right ||
	ego.dir == ego.up.right))
	{
	set.view(ego, v.ego.climbing.ladder);
	set.loop(ego, 0);
	fix.loop(ego);
	ego.x = 93;
	reposition.to.f(ego, ego.x, ego.y);
	start.motion(ego);
	current.status = climbing;
	}

if (current.status == climbing && 		[exit top of ladder
	ego.location == ladder.exit &&
    (ego.dir == ego.left ||
	ego.dir == ego.down.left ||
	ego.dir == ego.up.left))
	{
	release.loop(ego);
	set.view(ego, v.ego);
	ego.x = 87;
	reposition.to.f(ego, ego.x, ego.y);
	start.motion(ego);
	set.loop(ego, facing.left);
	current.status = normal.ego;
	}


[*****
[fall
[*****

if (current.status == falling){
	set(caught.ego);
}

if (caught.ego){
	reset(caught.ego);
	stop.motion(a.bandit);
	normal.motion(a.bandit);
	stop.cycling(a.bandit);
	set(hit.special);
}


if (current.status != falling && hit.special) {
	sound(s.ego.falling, sound.done);
	set.view(ego, v.ego.falling);
	set.priority(ego, 15);
	y = 167;
	work = 6;
	move.obj.f(ego, ego.x, y, work, fall.done);
	current.status = falling;
}

if (fall.done) {
	reset(fall.done);
	edge.ego.hit = bottom;
	erase(ego);
}




[ don't let a storm happen
if (has(i.storm.brew) && spell.cast == sc.make.storm){
	spell.cast = 0;
	print(13);
}

[*****
[handle.input
[*****

if (have.input)
	{
	if ((said(look) ||
		said(look, house) ||
		said(look, tree)))					{print(1);}

	if ((said(look$in, house) ||
		said(look$in) || 
		said(look$in, door, house) ||
		said(look, inside, room) ||
		said(look$in, door)))
		{
		if (bandit.status == awake)			{print(2);}
		else								{print(3);}
		}

	if (said(look, door))					{print(4);}

	if (said(anyword, window)) 				{print(5);}

	if ((said(look, rope, ladder) || said(look, ladder))){
		print(6);
	}

	if ((said(climb, tree) ||
		said(climb, up, tree) ||
		said(climb, down, tree)))			{print(7);}

	if ((said(look, sky) ||
		said(look, up)))					{print(8);}

	if ((said(look, ground) ||
		said(look, down)))					{print(9);}
	
	if (said(look, bandit))
		{
		if (bandit.status == awake)			{print(10);}
		else								{print(11);}
		}
	}


[*****
[exit							[	test for leaving the room
[*****

if (edge.ego.hit == bottom){
	new.room(22);
}

if (ego.location == entering.hideout && current.status == normal.ego){
	new.room(38);
}

