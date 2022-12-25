[ Rom 70 - Ship storm room.  Put up a fancy little script of the ship sinking

#include	"gamedefs.reh"
#include	"rm70.msg"




#define	bolt.done		lf0
#define	wave.done		lf1

#define	bolt.timer	lv0






if (init.log){

	load.sound(s.thunder);
	load.sound(s.lightning);

	work = 70;

	load.pic(work);
	draw.pic(work);

	set.horizon(80);

	set(handsOff);
	landing.x = 76;		[ and I don't position
	landing.y = 100;

	prevent.input();
	program.control();

	load.view.f(current.ego);
	set.view.f(ego, current.ego);

	animate.obj(aShip);
	load.view(v.ship.sinking);
	set.view(aShip, v.ship.sinking);
	ignore.horizon(aShip);
	set.cel(aShip, 0);
	work = 7;
	cycle.time(aShip, work);
	position(aShip, 63, 99);
	draw(aShip);

	animate.obj(aWave);
	load.view(v.storm.wave);
	set.view(aWave, v.storm.wave);
	ignore.horizon(aWave);
	ignore.objects(aWave);
	set.cel(aWave, 0);
[	work = 6;
[	cycle.time(aWave, work);
	position(aWave, 80, 98);
	set.priority(aWave, 14);
	draw(aWave);
	end.of.loop(aWave, wave.done);

	animate.obj(aBolt);
	load.view(v.lightning);
	set.view(aBolt, v.lightning);
	ignore.horizon(aBolt);
	set.cel(aBolt, 1);
	position(aBolt, 30, 35);
	draw(aBolt);
	set(bolt.done);

	show.pic();
	return();

}							[	end INIT.LOG

[ ship sinking

if (wave.done) {
	start.cycling(aWave);
	reset(wave.done);
	y = 4;
	x = 0;
	reposition(aShip, x, y);
	get.posn(aShip, x, y);
	if (y > 130) {
		erase(aShip);
		print.at(2, 2, 2, 37);
		set(certain.death);
		erase(aWave);
		erase(aBolt);
	} else {
		set.cel(aWave, 0);
		end.of.loop(aWave, wave.done);
	}
}

	



[ lightning flashes

if (bolt.timer > 8) {
	stop.cycling(aBolt);
} else {
	if (bolt.timer == 8){
		sound(s.lightning, sound.done);
	}
	start.cycling(aBolt);
}

if (!bolt.timer) {
	random(15, 40, bolt.timer);
	random(1, 144, x);
	y = 35;
	reposition.to.f(aBolt, x, y);
	random(0,1,loop);
	set.loop.f(aBolt, loop);
	set.cel(aBolt, 1);
	stop.cycling(aBolt);
	sound(s.thunder, sound.done);
	shake.screen(1);
}

--bolt.timer;

