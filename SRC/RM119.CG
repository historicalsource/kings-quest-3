[ Princess Rosella dynamic logic

#include 	"rm119.msg"
#include	"gamedefs.reh"




if (init.log){
	animate.obj(aPrincess);
	load.view(v.princess);

	load.sound(m.princess);

	if (!girlSaved){
		load.view(v.princess.tied);
		load.view(v.princess.burned);
		position(aPrincess, 8, 108);
		set.view(aPrincess,v.princess.tied);
		work = 3;
		cycle.time(aPrincess, work);
	} else {
		set.view(aPrincess,v.princess);
		get.posn(ego, x, y);
		if ((ego.dir == 1 || ego.dir == 8 || ego.dir == 2)){
			y += 1;
		}
		if ((ego.dir == 4 || ego.dir == 5 || ego.dir == 6)){
			y -= 1;
		}
		position.f(aPrincess, x, y);
		follow.ego(aPrincess,8,withEgo);
	}
	draw(aPrincess);
	return();
}

if (current.room == 69 && !beenIn69){
	print(14);
}

if (girlSaved && spell.cast){	[ don't let magic work 
	print(7);
	spell.cast = 0;
}

if (certain.death) {
	normal.motion(aPrincess);
	stop.motion(aPrincess);
	stop.cycling(aPrincess);
	return();
}

if (said(untie,girl)){
	if (!girlSaved){
		distance(ego,aPrincess,work);
		if (work > 16){
			print(15);
		} else {
			score += 3;
			set(girlSaved);
			if (dragonDead){
				print(16);
				print(18);
				stop.sound();
				sound(m.princess, sound.done);
				set.view(aPrincess,v.princess);
				work = 1;
				cycle.time(aPrincess, work);	
				follow.ego(aPrincess,6,withEgo);	[ start following
			}
		}
	} else {
		print(17);
	}
}


distance(ego, aPrincess, work);
if (girlSaved && withEgo){
	if (work > 12){
		start.cycling(aPrincess);
		follow.ego(aPrincess, 6, withEgo);
	} else {
		stop.cycling(aPrincess);
	}
}



[ doing things with rosella

#define MAXSAID 	5			[ messages 1-6 in order

if ((said(talk, with, girl) || said(talk, girl))){
	if (!dragonDead){
		print(12);
	} else {
		if (!girlSaved){
			print(13);
		} else {
			++girlTalk;
			print.v(girlTalk);
			if (girlTalk > MAXSAID){
				--girlTalk;
			}
		}
	}
}

if (said(get,girl)){
	if (girlSaved){
		print(8);
	} else {
		print(20);
	}
}


if (said(kill,girl)){
	print(9);
}

if (said(kiss,girl)){
	if (girlSaved){
		print(10);
	} else {
		print(21);
	}
}

if (said(touch,girl)){
	if (girlSaved){
		print(11);
	} else {
		print(21);
	}
}

if (said(look,girl)){
	if (!girlSaved){
		print(20);
	} else {
		print(19);
	}
}

