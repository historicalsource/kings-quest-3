[ rm77.cg
[ transition between lewdor and pirate ship
[ this is where we take all of his stuff away

#include	"gamedefs.reh"
#include	"iv-names.h"
#include	"rm77.msg"

#define	replay	lf0

if (init.log){

	prevent.input();

	load.view(v.ego);

	animate.obj(aShip);
	load.view(v.pirate.ship);
	set.view(aShip, v.pirate.ship);
	set.loop(aShip, 2);
	work = 2;
	step.time(aShip, work);
	fix.loop(aShip);
	position(aShip, 0, 60);

[
	load.sound(m.ocean);
	load.sound(39);		[ no name yet
	set(replay);

	work = 31;
	load.pic(work);
	draw.pic(work);
	discard.pic(work);

	draw(aShip);
	move.obj(aShip, 160, 60, 1, done);

	map.area = map.ship;

[ this is a new map area so we must clear the last areas beenIn flags
	if (!beenIn77){
		set(beenIn77);
		work = firstIn77;		[ start at end of range
:clrFlags
	if (work > lastIn77){		[ equal to this rooms beenIn flag
			reset.v(work);
			--work;
			goto clrFlags;
		}
	}


	sound(m.ocean, sound.done);
	show.pic();

[ set shipShape to underWay. Let rm0 do the work
	shipShape = inPort;
	voyage.seconds = 2;
	voyage.minutes = 0;


	return();
}

[ playing the music

get.posn(aShip, x, y);

if (sound.done){
	if ( replay){
		if (x < 30){
			sound(m.ocean, sound.done);
		} else {
			reset(replay);
			print(1);
		}
	} else {
		print(2);
		reset(replay);
		reset(sound.done);
		sound(39, replay);
	}
}

if (obj.hit.edge){
	accept.input();
	player.control();
	new.room(85);
}

