[ SHOVEL - logics for anytime ego has shovel in inventory
[		 or he is in rm84 and shovel is there

#include	"gamedefs.reh"
#include	"rm108.msg"
#include	"iv-views.h"

#define	chest.here	df0
#define	dugOne		df1
#define	wants.to.dig	df2
#define	can.dig.it	df3

#define	where		dv0
#define	script		dv1
#define	holeX		dv2
#define	holeY		dv3
#define	vis			dv4
#define	box			dv5


[ the real location of the chest 
#define 	chestLeft		48
#define	chestTop		80
#define	chestRight	63
#define	chestBottom	88
[ the lucky digger will find it here
	[#define	luckyLeft		55
	[#define	luckyTop		82			OLD VALUES
	[#define	luckyRight	56
	[#define	luckyBottom	83
#define	luckyLeft		53			[	Al increased to these 2/19/88.
#define	luckyTop		82
#define	luckyRight	58
#define	luckyBottom	85


if (init.log) {	[ we get our selves a chest in rooms we can dig in
	reset(chest.here);
	if ((current.room == 48 || current.room == 49)){
	[ the hole in the sand
		load.view(v.ego.digging);
		animate.obj(aChest);
		load.view(v.treasure);
		set.view(aChest, v.treasure);
		set.cel(aChest, 0);
		set.priority(aChest, 4);
		ignore.horizon(aChest);
		ignore.blocks(aChest);
		set(chest.here);
	}
}


if (said(look, shovel)){
	if (has(i.shovel)){
		show.obj(iv.shovel);
	} else {
		print(1);
	}
}

if (said(get, shovel)){
	if (hasShovel){
		print(2);
	} else {
		distance(ego, aShovel, where);
		if (where > 12){
			print(3);
		} else {
			get(i.shovel);
			set(hasShovel);
			erase(aShovel);
			score += 1;
		}
	}
}
 


if ((said(use, shovel) || 
	said(dig, hole, use, shovel) || 
	said(dig, hole) || 
	said(dig) || 
	said(dig, hole, ground, with, shovel) || 
	said(dig, beach) || 
	said(dig, treasure) || 
	said(dig, ground) || 
	said(dig, hole, ground))){
	set(wants.to.dig);
}

if (wants.to.dig){			[ all the reasons in the world not to let him
	if (current.room != 48 && current.room != 49){
		print(9);
		goto cant;
	}
	
	if (!has(i.shovel)){
		print(6);
		goto cant;
	}
	if (current.room == 48 && !posn(ego, 120,81, 153,138)){
		print(7);
		goto cant;
	}
	if (current.room == 49 && !posn(ego, 0,67, 75, 118)){
		print(7);
		goto cant;
	}
	if (current.status != normal.ego) {
		print(8);
		goto cant;
	}
	if (handsOff){
		print(9);
		goto cant;
	}
[ if we got here we are going to dig
	if (!has(i.treasure.chest) && posn(ego, luckyLeft, luckyTop, luckyRight, luckyBottom)){
		goto luckyDig;
	}
	if (knows.location && !has(i.treasure.chest)
		 && posn(ego, chestLeft, chestTop, chestRight, chestBottom)){
:luckyDig
		set(can.dig.it);
		set.loop(aChest, 0);
	} else {
		reset(can.dig.it);
		set.loop(aChest, 1);
	}
	if (!crewAsleep){	[ only if pirates aren't awake
		reset(can.dig.it);
		set.loop(aChest, 1);
	}

	stop.motion(ego);
	normal.motion(ego);
	fix.loop(aChest);
	script = 1;
	get.posn(ego, holeX, holeY);
	holeX += 4;
	holeY -= 1;
	position.f(aChest, holeX, holeY);
	set(dugOne);
	
:cant
	reset(wants.to.dig);	[ we won't let him
}


if (dugOne && script == 1){
	++script;
	program.control();
	set.view(ego, v.ego.digging);
	set.cel(ego, 0);
	set(keep.cycling);
	work = 2;
	cycle.time(ego, work);
	end.of.loop(ego, dugOne);	[ one scoop of shovel
}	

if (dugOne && script == 2){
	++script;
	set.cel(aChest,0);
	draw(aChest);
	stop.cycling(aChest);
	set.cel(ego, 0);
	end.of.loop(ego, dugOne);
}
if (dugOne && script == 3){
	current.cel(aChest, work);	[ we print on next to last
	if (work == 6){
		++script;
	} else {
		++work;
		set.cel.v(aChest, work);
		set.cel(ego, 0);
		end.of.loop(ego, dugOne);
	}
}
if (dugOne && script == 4){		[ the chest is exposed
	reset(dugOne);
	if (can.dig.it){
		get(i.treasure.chest);
		if (!scoredForChest)
			{
			set( scoredForChest);
			score += 7;
			}
		print.at(4,2,2,37);
	} else {
		print.at(5,2,2,37);
	}
	current.loop(aChest, loop);
	cell = 7;
	box = 4;
	current.view(aChest, view);
	set(no.script);
	add.to.pic.f(view, loop, cell, holeX, holeY, box, box);
	reset(no.script);
	erase(aChest);
	work = 1;
	cycle.time(ego, work);
	set.view(ego, v.ego);
	reset(keep.cycling);
	player.control();
}	

