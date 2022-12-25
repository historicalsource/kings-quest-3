[ Room 85 - Ladder at top, box under ladder, exit at stage right
[	March 14, 1988

#include "rm85.msg"
#include	"gamedefs.reh"
#include	"iv-names.h"



#define	jumpStage	 	lv1
#define	dstX			lv2
#define	dstY			lv3
#define	dstView		lv4
#define	scratchV		lv5
#define	object		lv6
#define	hiding.room 	lv7
#define	location		lv8



#define	jumpDone		lf0		[ end of jump flag
#define	loopDone		lf1		[ end of loop flag
#define	fallDone		lf2
#define	theyTookHisShitAgain	lf3



[ top of box 
#define	boxLeft		104
#define	boxTop		119
#define	boxRight		121
#define	boxBottom		124
#define	boxCenter		111		[ for gettting on box

[ jump box for getting on
#define	jmpLeft		96
#define	jmpTop		136
#define	jmpRight		131
#define	jmpBottom		150


#define	boxBaseY		148		[ for jumping off
#define	floorRight 	125
#define	floorLeft		90
#define	floorCenter 	142	

#define	ladLeft		108
#define	ladLeftOn		110		[ on ladder, base positioning
#define	ladTop		20
#define	ladRight		118
#define	ladBottom		94

[ right exit/entrance position from to room 86
#define	rtExitX		146
#define	rtExitY		137



if (init.log){
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

[ external stuff to set up
	set(interiorRoom);

[ make wiz come before you get across the ocean
	if (previous.room == 77){
		wiz.minutes = 0;
	}

	landing.x = 60;
	landing.y = 147;
	wiz.x = 85;
	wiz.y = 148;
	map.area = map.ship;

	load.sound(s.ego.falling);

	load.logics(lgc.box);
	call(lgc.box);

	load.logics(lgc.pirates);

	load.view(v.ego.climbing.ladder);
	load.view(v.ego);
	load.view(v.ego.jumping);
	load.view(v.ego.carrying.box);
	load.view(v.ego.falling);
	load.view(v.ego.dead);

[ set up default ego
	load.view.f(current.ego);
	set.view.f(ego, current.ego);

	if (current.status == falling){	[ let the rest of the falling code take over
		set.view(ego, v.ego.falling);
		position(ego, 103, 33);
	}		  

	if (current.status == climbing){
		set.view(ego,v.ego.climbing.ladder);
		position(ego,ladLeftOn,ladTop);
		set.loop(ego,0);			[ back view
		fix.loop(ego);
	}

	if (current.status == normal.ego){
		if (positionEgo)
			{
			get.posn(ego, ego.x, ego.y);
			if ((tossed.in ||		  [ sent back to hold by pirates
				previous.room == 77)) [ only on his first time in hold
				{
			    	object = 1;
			    	hiding.room = 83;

				:takeHisShit;
				if (object < size.of.inventory)	[ last item can't be taken on purpose
					{
					if (object == dough.balls)	[ can't take dough.balls
						{
						++object;
						goto takeHisShit;
						}
				    	get.room.f(object,location)
			    		if (location == inventory)
						{
						set(dontHaveStuff);		[ flag checked in room 83
						set(theyTookHisShitAgain);
				    		put.f(object,hiding.room);
				    		}
				    	++object;
					goto takeHisShit;
					}

				if (!tossed.in)
					{
					reset( theyTookHisShitAgain);	[	skip "again" msg.
					}
				else
					{
					reset(tossed.in);

					++timesCaught;
					if (timesCaught == 2){
						plankWalk = 1;
						new.room(82);
					}
				}

				start.motion(ego);
				set.loop(ego, facing.front);
				position.f(ego, landing.x, landing.y);
			} else {
				if (previous.room == 86) {	[ forward hold
					if (ego.y > 144){
						position(ego, rtExitX, 145);
					} else {
						position(ego, rtExitX, 138);
					}
				}
			}
		}
		release.loop(ego);
	}
	if (current.status == deferred.entry){
		set(positionEgo);
		position.v(ego, landing.x, landing.y);
		set.view(ego, v.ego);
		set(drawEgo);
	}

	if (drawEgo){
		draw(ego);
	}

[ all done initing, show the picture
	show.pic();
	return();
}


if (theyTookHisShitAgain){
	reset(theyTookHisShitAgain);
	print(8);
}


if (current.status == climbing && hit.special){
	set.view(ego, v.ego.falling);
	current.status = falling;
}

if (current.status == falling && !handsOff){
	sound(s.ego.falling, sound.done);
	set(handsOff);
	get.posn(ego, ego.x, ego.y);
	ego.y = 120;
	ignore.blocks(ego);
	set.priority(ego, 13);
	work = falling.step.size;
	move.obj.f(ego, ego.x, ego.y, work, fallDone);
}

if (fallDone){
	stop.sound();
	reset(fallDone);
	set.view(ego, v.ego.dead);
	reposition.to(ego, 104,125);
	set(certain.death);
}




[ falling off the ladder
if (current.status == climbing
		 && !obj.in.box(ego, ladLeft, ladTop, ladRight, ladBottom)){
	prevent.input();
	ignore.blocks(ego);				[ float over the dotted lines
	ignore.objs(ego);
	release.loop(ego);
	start.motion(ego);
	set.view(ego, v.ego);
	set.loop(ego, facing.back);
	y = boxBottom;
	scratchV = 6;
	move.obj.f(ego,ego.x, y, scratchV, jumpDone);
	set.scan.start();
	if (jumpDone) {
		reset(jumpDone);
		current.status = on.big.box;
		set.priority(ego,13);
		observe.blocks(ego);
		observe.objs(ego);
		accept.input();
		reset.scan.start();
	}
	return();
}

call(lgc.box);

call(lgc.pirates);


[******** SAID STUFF ********]


if ((said(look,room) || said(look) || said(look, hold))){
	print(1);
}

if (said(look,hole)){
	print(3);
}

if ((said(get$out, hold) || said(climb, out, hold))){
	print( 4);
}

if ((said(look, up) || said(look, up, ladder) || said(look,ladder))){
	if (current.status == on.big.box){
		print(5);
	}
	if (current.status == climbing){
		print(6);
	}
	if ((current.status == normal.ego || current.status == on.small.box)){
		print(7);
	}
}



	
[ ******* PAINLESS ROOM EXITS **********

[ exiting at right of room
if (edge.ego.hit == 2){
	new.room(86);
}

[ climbing ladder out the top
if (current.status == climbing && edge.ego.hit == 1){
	if (!scored.for.hold){
		score += 2;
		set(scored.for.hold);
	}
	new.room(83);
}

