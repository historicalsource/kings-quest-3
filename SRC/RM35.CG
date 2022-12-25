[logics for room -- 35: Inside hole in bandit's tree

%include "gamedefs.reh"
%include "rm35.msg"



%define	said.it			lf1



if (init.log)
	{

	load.view(v.ego);
	load.view.f(current.ego);
	set.view.f(ego, current.ego);


	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);


	wiz.y = 0;		[if set to 0 prevents wiz from entering room

	landing.x = 66;
	landing.y = 158;

[ always a fly in this room
	set(positionEgo);		[ tell room 0 we did it
	position(ego, 68, 145);
	set(keep.cycling);

	if (drawEgo){
		draw( ego);
	}

	show.pic();
	return();

	}

if (!said.it){
	set(said.it);
	print(1);
}


if (spell.cast == sc.stop.flying){
	print(2);
	shake.screen(4);
	print(5);
	spell.cast = 0;
	erase(ego);
	set(certain.death);
	return();
}


[*****
:exit							[	test for leaving the room
[*****

if (ego.dir == 5){
	new.room(22);
} else {
	ego.dir = 0;
}

