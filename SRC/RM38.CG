[logics for room -- rm38:inside bandit hideout

%include "gamedefs.reh"
%include "rm38.msg"



%define	near.bin				1
#define	near.table			2



%define	cycle.count			lv0
%define	location				lv1
	#define	hiding.room	38
	%define	obj.purse		48

#define	script				lv2
	#define	inChair	0
	#define	chasing	1
	#define	caught	2
	#define	pushing	3
#define	object				lv3


%define	bandit.awake			lf0
%define	ego.caught			lf1
[%define			lf2
%define	at.door				lf3
%define	bin.open				lf4
%define	got.one				lf5
[%define			lf6
%define	lid.open				lf7
%define	lid.closed			lf8
#define	start.follow			lf9

#define	next					lf10

%object	a.bandit				1
%object	a.lid				2
%object	a.purse				3



if (init.log) {
	load.pic(current.room);
	draw.pic(current.room);
	discard.pic(current.room);

	load.sound(m.badguy);
	load.view(v.bandit.chest);

	animate.obj( a.lid);
	
	wiz.x = 45;
	wiz.y = 149;

	landing.x = 87;
	landing.y = 147;

	set(interiorRoom);

	load.view(v.ego);
	load.view(v.ego.falling);
	load.view.f(current.ego);
	set.view.f(ego, current.ego);

	if (positionEgo){
		set.view(ego, v.ego);
		position(ego, 89, 167);
		start.motion(ego);
		ego.dir = 1;
		current.status = normal.ego;
	}

	set.view( a.lid, v.bandit.chest);
	position( a.lid, 75, 108);
	set.loop(a.lid, 0);
	set.cel(a.lid, 0);
	work = 4;
	cycle.time(a.lid, work);
	draw( a.lid);
	stop.update(a.lid);

[ bandit status is determined by room 37 (for some reason)
	
	animate.obj( a.bandit);
	load.view( v.bandit.2);
	load.view(v.bandit.sleeping);

	if (bandit.status == awake && current.status == normal.ego) {
		bandit.status = awake;
		set.view( a.bandit, v.bandit.2);
		position( a.bandit, 89, 140);
		work = 1;
		cycle.time(a.bandit, work);
		script = chasing;
		prevent.input();
		set(next);
	} else {
		set.view( a.bandit, v.bandit.sleeping);
		work = 12;
		cycle.time(a.bandit, work);
		set.priority(a.bandit, 13);
		position( a.bandit, 48, 137);
		script = inChair;
	}

	draw(a.bandit);

	
	if (obj.in.room(i.purse.with.coins, current.room)){
		animate.obj(a.purse);
		load.view(v.purse);
		set.view(a.purse, v.purse);
		set.priority(a.purse, 15);		[debug
		position(a.purse, 60, 106);
		draw( a.purse);
		stop.update( a.purse);
	}

	if (drawEgo) {
		draw( ego);
	}

	show.pic();

	if (current.status != deferred.entry){
		sound(m.badguy, sound.done);
		if (bandit.status == awake) {
			print(1);
		} else {
			print(2);
		}
	}

	return();

}




ego.location = nowhere;
if (posn(ego, 70, 106, 101, 124))
	{
	ego.location = near.bin;
	}
if (posn(ego, 55, 117, 69, 139))
	{
	ego.location = near.table;
	}





if (!handsOff && bandit.status == asleep && aSecondPassed) {
	random(1, 255, x);
	if (x == 1 && current.status == normal.ego){
		bandit.status = awake;
		set(next);
	}
}


[ catching ego script 

if (script == inChair && next){	[ just woken up
	++script;
	prevent.input();		[ he's dead now
	work = 1;
	cycle.time(a.bandit, work);
	set.view(a.bandit, v.bandit.2);
	move.obj(a.bandit, 69, 137, 1, next);
	release.priority(a.bandit);
	bandit.status = awake;
	print(17);
}

if (script == chasing && next){	[ ready to chase
	++script;
	follow.ego(a.bandit, 8, next);
}

if (script == caught && next && current.status == normal.ego){	[ he got him
	if (handsOff){
		normal.motion(a.bandit);
		stop.motion(a.bandit);
		stop.cycling(a.bandit);
	} else {
		++script;
		set(handsOff);
		start.cycling(a.bandit);
		ignore.blocks(ego);
		ignore.blocks(a.bandit);
		program.control();
		get.posn(a.bandit, x, y);
		x += 2;
		y += 6;
		reposition.to.f(ego, x, y);
		set.loop(ego, 2);
		set.loop(a.bandit, 2);
		move.obj(a.bandit, 86, 163, 1, next);
		move.obj(ego, 86, 163, 1, next);
	}
}


if (script == pushing && next){	[ he got him
	++script;
	reset(next);
	set.view( ego, v.ego.falling);
 	current.status = falling;
	edge.ego.hit = bottom;
	print(24);
	player.control();
	current.room = 37;			[ make Al's logic happy
	new.room(22);
}


[ end of bandit script may be finished in next room




if (lid.open)
	{
	reset(lid.open);
	stop.update(a.lid);
	print(14);
	}

if (lid.closed)
	{
	reset(lid.closed);
	stop.update(a.lid);
	}


[*****
[Handle Input
[*****

if (have.input)
	{
	if ((said(look) ||
		said(look, house)))								{print(3);}
	
	if (said(look, man))
		{
		if (bandit.status == awake)								{print(4);}
		else											{print(5);}
		}

	if ((said(look, table) ||
		said(look, top$of, table) ||
		said(look, table, top)))
		{
		if (obj.in.room( i.purse.with.coins, current.room))	{print(6);}
		else											{print(7);}
		}

	if ((said(get, purse, from , table) || 
		said(get, purse, table) || 
		said(get, coin) || 
		said(get, purse)) ){
		if (obj.in.room( i.purse.with.coins, current.room)
			 && bandit.status == asleep) {
			if (ego.location == near.table){
				start.update(a.purse);
				erase(a.purse);
				get(i.purse.with.coins);
				if (!gotPurseOnce){
					score += 4;
					gold.coin.count = 8;
					set(gotPurseOnce);
				}
				print(8);
			} else {
				print(22);
			}
		} else {
			print(9);
		}
	}
	
	if ((said(look, chest) ||
 		said(look$in, chest) ||
		said(look$in, box) ||
		said(look, box))){
		if (bin.open) {
			if (ego.location == near.bin) {
				if (ego.been.robbed) {
					print(10);
				} else {
					print(11);
				}
			} else {
				print(22);
			}
		} else {
			print(12);
		}
	}
	
	if ((said(open, chest) || said(open, lid, chest) ||
		said(open, box) || said(open, lid, box) || said(open, lid))) {
		if (bandit.status == awake) {
			print(9);
		} else {		
			if (bin.open) {
				print(13);
			} else {
				if (ego.location == near.bin){
					start.update(a.lid);
					end.of.loop(a.lid, lid.open);
					set(bin.open);
				} else {
					print(22);
				}
			}
		}
	}
	
	if ((said(close, chest) || said(close, lid, chest) ||
		said(close, box) || said(close, lid, box) || said(close, lid))) {
		if (bandit.status == awake) {
			print(9);
		} else {		
			if (!bin.open) {
				print(21);
			} else {
				if (ego.location == near.bin){
					start.update(a.lid);
					reverse.loop(a.lid, lid.closed);
					reset(bin.open);
				} else {
					print(22);
				}
			}
		}
	}

	if (said(kill, man))
		{
		if (bandit.status == awake)								{print(15);}
		else											{print(16);}
		}
	
	if (bandit.status ==  asleep &&
	         (said(talk, man) || said(wake, man) || said(shake, man))) {
		release.priority(a.bandit);
		bandit.status = awake;
		set.view(a.bandit, v.bandit.2);
		work = 1;
		cycle.time(a.bandit, work);
		set(next);
	}
	
	if ((said (look, floor) ||
		said(look, ground) ||
		said(look, under, table) ||
		said(look, under, chair)))						{print(23);}

	if ((said(look, out, door) || said(look, door) ||
		said(look, out, window) || said(look, window) ||
		said(look, out)))							{print(18);}
	
	if (said(get, stuff, rol)){
		if (bin.open){
			reset(got.one);
			reset (ego.been.robbed);
		    	object = 1;
:misterlooper
			if (object < size.of.inventory) {		[ last item
				if (object == obj.purse){		[ must be on table
					++object;
					goto misterlooper;
				}
			    	get.room.f(object,location)
		    		if (location == hiding.room) {
			    		set(got.one);
					get.f(object);
		    		}
			    	++object;
				goto misterlooper;
			}
		    	if (got.one){
				print(19);
			} else {
				print(20);
			}
		} else {
			print(21);
		}
	}
	
} [ end of have input


[*****
[test for exit	
[*****

if (ego.x > 84 && ego.x < 98 && edge.ego.hit == bottom){
	if (current.status == falling){
		new.room(22);
	} else {
		new.room(37);
	}
}

