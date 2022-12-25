[ Eagle feather room rm114.cg

[ Odds of flying through 1/5
[ Odds of dropping 1/3
[ rooms in 12, 13, 19, 29

#include	"gamedefs.reh"
#include	"rm114.msg"
#include	"iv-names.h"


#define	EAGLEY	30


work = 114;
if (!eagleHere && !obj.in.room(i.eagle.feather, work)){
	return();
}

if (init.log){
	reset(bombsAway);
	reset(featherHere);
	eagleTimer = 0;
	random(1, 4, work);
	if (debugging){
		work = 1;
	}
	if (work == 1){
		random( 3, 15, eagleTimer);	[ time before entrance

		animate.obj(anEagle);		[ eagle 
		load.view(v.ego.eagle);
		set.view(anEagle, v.ego.eagle);
		ignore.blocks(anEagle);
		ignore.horizon(anEagle);
		set.priority(anEagle, 15);
		position(anEagle, 1, EAGLEY);

		animate.obj(aFeather);		[ feather shows up if dropped
		load.view(v.feather.falling);
		set.view(aFeather, v.feather.falling);
		ignore.blocks(aFeather);
		ignore.horizon(aFeather);
		ignore.objs(aFeather);
		set.priority(aFeather, 15);
	}
	return();

}

[ run the timer down

if (aSecondPassed && eagleTimer) {
	if (eagleTimer == 1) {
		set(eagleHere);
		draw(anEagle);
		move.obj(anEagle, 140, EAGLEY, 1, eagleGone);
		random(1, 2, work);
		if (debugging){
			work = 2;
		}
		if (work == 2){		[ we will drop it at landing.x, landing.y
			set(bombsAway);
		}
	}
	-- eagleTimer;
}

if (eagleGone){
	reset(eagleHere);
	reset(eagleGone);
	erase(anEagle);
}


[ drop the bomb
get.position(anEagle, x, y);
if (x == landing.x && bombsAway) {	[ only good once
	reset(bombsAway);
	position.f(aFeather,x,y);
	draw(aFeather);
	work = 2;
	move.obj.f(aFeather, landing.x, landing.y, work, featherHere);
}

if (featherHere){
	release.priority(aFeather);
	set.cel(aFeather, 1);
	stop.cycling(aFeather);
}

[ talking to the feather

if ((said(look, bird, feather) || said(look, eagle, feather) || said(look, feather))){
	if (featherHere){
		print(1);
	} else {
		print(2);
	}
}

if ((said(get, bird, feather) || said(get, eagle, feather) || said(get, feather))){
	if (featherHere){
		distance(ego, aFeather, work);
		if (work > 25){
			print(3);
		} else {
			print(4);
			reset(featherHere);
			erase(aFeather);
			get(i.eagle.feather);
			score += 2;
		}
	} else {
		print(2);
	}
}

if ((said(look,up,eagle) || said(look,up, bird) || 
	said(look, bird) || said(look, eagle))){
	if (eagleHere){
		print(5);
	} else {
		reset(have.match);
	}
}

if ((said(get, bird) || said(get, eagle))){
	if (eagleHere){
		print(3);
	} else {
		print(6);
	}
}
													
if ((said(talk, bird) || said(talk, eagle))){
	if (eagleHere){
		print(3);
	} else {
		print(6);
	}
}


if ((said(look, on, ground) || said(look, ground))){
	if (!featherHere){
		reset(have.match);
	} else {
		print(8);
	}
}

	
