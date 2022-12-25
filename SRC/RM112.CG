[ LGC.SEAGULL - Keep two seagulls flapping away

#include	"gamedefs.reh"
#include	"rm112.msg"


#object	aGullA	12
#object	aGullB	13

#define	flyLine	35
#define	blockLine	40


if (init.log){
	load.view(v.seagull);

	animate.obj(aGullA);
	set.view(aGullA,v.seagull);
	position(aGullA,20,6);
	ignore.obj(aGullA);
	ignore.horizon(aGullA);
	wander(aGullA);
	set(gulla.wandered);
	if (work){
		set.loop(aGullA,1);
	} else {
		set.loop(aGullA,0);
	}
	fix.loop(aGullA);
	set.cel(aGullA,2);
	set.priority(aGullA, 4);
	draw(aGullA);

	animate.obj(aGullB);
	set.view(aGullB, v.seagull);
	if (work){
		set.loop(aGullB,1);
	} else {
		set.loop(aGullB,0);
	}
	fix.loop(aGullB);
	position(aGullB, 20,4);
	ignore.horizon(aGullB);
	ignore.obj(aGullB);
	wander(aGullB);
	set(gullb.wandered);
	set.priority(aGullB, 4);
	draw(aGullB);

[	work = 2;
[	step.time(aGullA, work);
[	step.time(aGullB, work);
[	work = 1;
[	cycle.time(aGullB, work);
[	cycle.time(aGullA, work);
}


get.posn(aGullA,x,y);	[ dont go below a certain point
if (y > flyLine){
	normal.motion(aGullA);
	y = 1;	[ move hime up
	set.dir(aGullA,y);
	reset(gulla.wandered);
} else {
	if (!gulla.wandered){
		wander(aGullA);
		set(gulla.wandered);
	}
}

get.posn(aGullB,x,y);	[ dont go below a certain point
if (y > flyLine){
	normal.motion(aGullB);
	y = 1;	[ move hime up
	set.dir(aGullB,y);
	reset(gullb.wandered);
} else {
	if (!gullb.wandered){
		set(gullb.wandered);
		wander(aGullB);
	}
}

[ keep seagulls looking good

get.dir(aGullA,y);
if (y > 3 && y < 7){	[ going down
	current.loop(aGullA, work);
	if (!work){
		set.cel(aGullA,4);
	} else {
		set.cel(aGullA,0);
	}
	stop.cycling(aGullA);
} else {
	start.cycling(aGullA);
}

get.dir(aGullB,y);
if (y > 3 && y < 7){	[ going down
	current.loop(aGullB, work);
	if (!work){
		set.cel(aGullB,4);
	} else {
		set.cel(aGullB,0);
	}
	stop.cycling(aGullB);
} else {
	start.cycling(aGullB);
}

[ now if ego dies, we do too. Block the birds

if (certain.death) {
	block(0,0,159,blockLine);
	
	start.cycling(aGullA);
	wander(aGullA);
	
	start.cycling(aGullB);
	wander(aGullB);
}

if (said(look, bird)){
	print(1);
}

if (said(get, bird)){
	print(2);
}

