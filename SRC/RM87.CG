[logics for room 87 -- generic storm room

%include "rm87.msg"
%include "gamedefs.reh"

[ logic of room:
[ generic outdoor storm room,  A storm while out of doors has you
[ walking aimlessly until the storm subsides.  You will end up in 
[ a random room in the same map area



[ Al said something about "sc.poof" for desired exit.
[ maybe some code exists to pick the room?

[messages for room 87 -- generic storm room



#define	bolt.done		lf0
#define	first.msg		lf1
#define	leave.room	lf2


#define	bolt.timer	lv0





if (init.log){
	load.pic(current.room);
	draw.pic(current.room);

	set.horizon(80);

	load.sound(s.thunder);
	load.sound(s.lightning);

	load.view(v.ego);

	load.view.v(current.ego);
	set.view(ego, v.ego);

	set(handsOff);
	landing.x = 76;		[ and I don't position
	landing.y = 100;

	position.v(ego, landing.x, landing.y);

	draw(ego);

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

if (!first.msg){
	set(first.msg);
	print(1);
}

[ lightning flashes

if (bolt.timer > 8) {
	stop.cycling(aBolt);
}
if (bolt.timer == 8) {
	sound(s.lightning, sound.done);
	start.cycling(aBolt);
}

if (!bolt.timer) {
	sound(s.thunder, sound.done);
	shake.screen(1);
	random(15, 40, bolt.timer);
	random(1, 144, x);
	y = 35;
	reposition.to.f(aBolt, x, y);
	random(0,1,loop);
	set.loop.f(aBolt, loop);
	set.cel(aBolt, 1);
	stop.cycling(aBolt);
}

--bolt.timer;





if (spell.cast == sc.stop.storm){
	set(leave.room);
}

if (!storm.minutes && !storm.seconds){
	set(leave.room);
}


[*****
:exit							[	test for leaving the room
[*****

if (leave.room){
	current.status = deferred.entry;
	if (pre.previous.room){		[ we intercepted a new room during storm
		current.room = pre.previous.room;
		current.status = normal.ego;
	}

[ clean up on the way out
	storm.minutes = 0;
	storm.seconds = 0;
	pre.previous.room = 0;
	reset(handsOff);
	new.room.f(previous.room);
}

