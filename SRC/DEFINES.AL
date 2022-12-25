[
[	defines.al
[
[				AL'S KING'S QUEST ]I[ GAME DEFINITIONS
[
[	March 10, 1987
[





[************     FLAGS     ************]
[Only the interpreter can use	  0-29	(globals)
[		Any room can use	220-239	(lf's)
[Only dynamic logics can use	240-255	(df's)

[		   Gamedefs.h flags are  30- 89:
[			    Al's flags are  90-169:
[			   Bob's flags are 170-219:
%flag	near.mud					90
%flag	near.cactus				91
%flag	found.key					92
%flag	hid.stuff.under.bed			93
%flag	found.magic.wand			94
%flag	found.trapdoor.lever		95
%flag	got.mud					96
%flag	the.eagle.has.landed		97
%flag	lgc.house.wiz.loaded		98
%flag	wiz.on.screen				99
%flag	wiz.done					100
%flag	wiz.arrived				101
%flag	got.ocean.water			102
%flag	got.dew					103
%flag	poof.wiz.out				104	[	PO'd.wiz.logic flags; 
%flag	poof.ego.out				105	[		use only in rm106.
%flag	fry.ego					106
%flag	take.his.stuff				107
%flag	PO'd.wiz.done				108
%flag	PO'd.wiz.init'd			109
%flag	found.mud					110
%flag	medusa.stone				111
%flag	found.rope				112
%flag	got.it.in.the.hole			113
%flag	erase.ego					114
%flag	spider.dead				115
%flag	pussy.on.screen			116
%flag	cabinet.unlocked			117
%flag	stuff.under.bed			118
%flag	testing					119
%flag	oops						120
%flag	ego.death.done				121
%flag	ego.arrived				122
%flag	punishment.done			123
%flag	caught.in.Llewdor			124
%flag	my.have.match				125
%flag	clock.on					126
%flag	magic.done				127
%flag	got.cat.hair				128
%flag	openingChoreAssigned		129
%flag	force.wiz.come				130

[	Don't change these numbers; rm111 needs them as is!
%flag	heardB1					131	[	heard.bird.talk.1, etc.
%flag	heardB2					132
%flag	heardB3					133
%flag	heardB4					134
%flag	heardC1					135
%flag	heardC2					136
%flag	heardC3					137
%flag	heardC4					138
%flag	heardS1					139
%flag	heardS2					140
%flag	heardS3					141
%flag	heardS4					142
%flag	heardL1					143
%flag	heardL2					144
%flag	heardL3					145

[%flag	146
[%flag	147
[%flag	148
[%flag	149
[%flag	150
%flag	made.spell.1				151
%flag	made.spell.2				152
%flag	made.spell.3				153
%flag	made.spell.4				154
%flag	made.spell.5				155
%flag	made.spell.6				156
%flag	made.spell.7				157





[************      VARS      ************]
[Only the interpreter can use	  0-29	(globals)
[		Any room can use	220-239	(lv's)
[Only dynamic logics can use	240-255	(dv's)

[		    Gamedefs.h vars are  30- 89:
[				Al's vars are  90-169:
[			    Bob's vars are 170-219:
%var		start.a.poof				90
	%define	poof.out			1
	%define	poof.in			2
	%define	poof.change		3

%var		poof.change.view			91
%var		rose.essence.counter		92
%var		flight.count				93
%var		death.message				94

%var		office.status				95
%var		bear.tester				96
%var		medusa.statue.room			97
%var		medusa.statue.x			98
%var		medusa.statue.y			99
%var		cat.x					100
%var		cat.y					101

%var		spell.in.progress			102
%var		spell.status				103
	%define	not.started		0
	%define	spell.done		255
%var		poem.line.count			104
%var		funny.death.view			105
%var		funny.death.loop			106

[	TIMER DEPARTMENT
%var		burner.seconds				107
%var		burner.minutes				108
	%define	burner.init.minutes	 3

%var		chore.seconds				109
%var		chore.minutes				110
	%define	chore.init.minutes	 3

%var		punish.seconds				111
%var		punish.minutes				112
	%define	punish.init.minutes	 1

[%var		113
[%var		114
%var		gameSeconds				115
%var		gameMinutes 				116
%var		gameHours 				117
%var		gameDays 					118
%var		clear.status.seconds		119
%var		old.seconds				120
[%var		121
%var		old.animation.interval		122
	%define	fastest			0
	%define	fast				1
	%define	normal			2
	%define	slow				3

%var		make.wiz.come				123	[	defines are in gamedefs.h
%var		wiz.location				124
%var		wiz.entrance.time			125
%var		wiz.exit.time				126
%var		wiz.away.asleep			127	[	wiz vars
	%define	home.after.bed		1
	%define	in.town			2
	%define	home.after.town	3
	%define	in.bed			4

%var		wiz.status				128
	%define	waiting.to.appear	101		[	also all ego.status values
	%define	here				102
	%define	leaving.room		103
	%define	gone				104
	%define	pissed			105
	%define	waiting.to.eat		106

%var		wiz.temper				129
[	%define	rational			0
	%define	talked.once		1
	%define	assign.chore		2
	%define	punish			3
	%define	get.outta.here		4

%var		wiz.timer					130	[	use anywhere
%var		wiz.script				131	[	use anywhere
%var		PO'd.wiz.timer				132	[	use only in rm106
%var		PO'd.wiz.script			133	[	use only in rm106
%var		punishment.count			134
%var		room.poofing.to			135
%var		previous.chore				136
%var		chore.to.do				137
	%define	clean.kitchen		1
	%define	empty.pot			2
	%define	fix.meal			3
	%define	dust.office		4
	%define	feed.chickens		5

%var		waterView					138
	%define	walkingEgo		0		[	waterView values
	%define	wadingDeep		2		[	Used by lgc.swim
	%define	swimmingEgo		3
	%define	wadingShallow		7

[	%var		zero					140	[	Kinda Konstants.
[	%var		one					141	[	Set by StartupLogic and
[	%var		two					142	[	never changed, ever!
[	%var		three				143
[	%var		four					144
[	%var		five					145




[************* ANIMATED OBJECTS ************]
[Define here all objects shared by multiple rooms.
%object	a.cat					13




[************   MISC. CONSTANTS   ************]
%define	snail.step.time			12
%define	cycles.before.death			44
%define	wiz.cycle.time				2
