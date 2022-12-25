[
[	gamedefs.h
[
[			KING'S QUEST ]I[ SHARED GAME DEFINITIONS HEADER
[
[	March 10, 1987
[
[
[	Doug	MacNeil	 206 371-2797		 7038 Karber Road, Blaine WA 98230
[	Al Lowe			255-8551		 5815 E. Parkside, Fresno    93727
[	Bob Heitman		683-2230	    49760 Pierce Drive, Oakhurst  93644
[	Bob Kernaghan		683-4524  [HS 683-4667] Box 2103, Oakhurst  93644 
[	Dale Carlson		683-2828 			44488 Hwy 49, Ahwahnee  93601		
[	Roberta Williams	683-8039		   40367 Goldside, Oakhurst  93644
[



%tokens	"..\\words.tok"
%include	"sysdefs"
%include	"sysdefs.al"


[************      FLAGS    ************]
[			    Common flags are 30-79:
[		   Gamedefs.h flags are  30- 89:
[			    Al's flags are  90-169:
[			   Bob's flags are 170-219:
%flag	force.a.test				30	[	Generic test flag.
%flag	debugging					31
%flag	survivable.fall			32
%flag	ego.poofing.done			33
%flag	interiorRoom				34
%flag	keep.cycling				35
%flag	no.cycling				36
%flag	ignore.special				37
%flag	ignore.water				38
%flag	next.frame				39
%flag	doit			 			40
%flag	done						41
%flag	demo						42
%flag	out.of.memory				43
%flag	certain.death				44
%flag	aSecondPassed				45
%flag	handsOff					46
%flag	drawEgo					47
%flag	positionEgo				48
%flag	invisibleEgo				49
%flag	xy.on					50

[	Reusable BEENIN flags -- 
%flag	beenIn77					51
%flag	beenIn48					52
%flag	beenIn61					53

[	This set is used only before he's "beenIn77".
%flag	beenIn11					54
%flag	beenIn12					55
%flag	beenIn13					56
%flag	beenIn14					57
%flag	beenIn15					58
%flag	beenIn16					59
%flag	beenIn17					60
%flag	beenIn18					61
%flag	beenIn19					62
%flag	beenIn20					63
%flag	beenIn21					64
%flag	beenIn22					65
%flag	beenIn23					66
%flag	beenIn24					67
%flag	beenIn25					68
%flag	beenIn26					69
%flag	beenIn27					70
%flag	beenIn28					71
%flag	beenIn29					72
%flag	beenIn30					73

[	This set is used after he's beenIn48.
%define	beenIn49				beenIn11
[define	beenIn50				beenIn12
%define	beenIn51				beenIn13
%define	beenIn52				beenIn14
%define	beenIn53				beenIn15
%define	beenIn54				beenIn16
%define	beenIn55				beenIn17
%define	beenIn56				beenIn18
%define	beenIn57				beenIn19
%define	beenIn58				beenIn20
%define	beenIn59				beenIn21

[	This set is used after he's beenIn61.
%define	beenIn62				beenIn11
%define	beenIn63				beenIn12
%define	beenIn64				beenIn13
%define	beenIn65				beenIn14
%define	beenIn66				beenIn15
%define	beenIn67				beenIn16
%define	beenIn68				beenIn17
%define	beenIn69				beenIn18
[define	beenIn70				beenIn19
%define	beenIn71				beenIn20
%define	beenIn72				beenIn21


%flag	make.ego.fall				74
%flag	near.water				75
%flag	update.clock				76
%flag	landHo					77
%flag	ego.been.robbed			78
%flag	paid.pirates				79
%flag	prevent.new.room			80
%flag	tooBusyForMap				81



[	LOCAL FLAGS 	(use only in room logics; reset by room 0 init.logs)
%flag	lf0						220
%flag	lf1						221
%flag	lf2						222
%flag	lf3						223
%flag	lf4						224
%flag	lf5						225
%flag	lf6						226
%flag	lf7						227
%flag	lf8						228
%flag	lf9						229
%flag	lf10						230
%flag	lf11						231
%flag	lf12						232
%flag	lf13						233
%flag	lf14						234
%flag	lf15						235
%flag	lf16						236
%flag	lf17						237
%flag	lf18						238
%flag	lf19						239


[	TEMP FLAGS	(use only in dynamic logics; reset by room 0 init.log)
%flag	df0						240
%flag	df1						241
%flag	df2						242
%flag	df3						243
%flag	df4						244
%flag	df5						245
%flag	df6						246
%flag	df7						247
%flag	df8						248
%flag	df9						249
%flag	df10						250
%flag	df11						251
%flag	df12						252
%flag	df13						253
%flag	df14						254
%flag	df15						255



[************       VARS     ************]
[			     Common vars are 30-79:
[		   Gamedefs.h vars are  30- 89:
[			    Al's vars are  90-169:
[			   Bob's vars are 170-219:
%var		force.a.wiz				30
	%define	wsc.from.bed		1	[	"wsc" = (wiz.status.change)
	%define	wsc.to.town		2
	%define	wsc.from.town		3
	%define	wsc.to.bed		4

	%define	skipped.chore		8
	%define	osw.punish		15	[	"osw" = on.screen.wizard
	%define	in.wrong.place		20
	%define	osw.saw.magic		22
	%define	magic.wand.missing	24
	%define	office.awry		26
	%define	has.bad.inventory	27
	%define	has.ingredients	28
	%define	has.magic.inventory	29

%var		wiz.y					31
%var		wiz.x					32
%var		start.climbing				33
%var		room.bottom				34
%var		current.location			35
%var		work						36	[		"
%var		x						37	[		"
%var		y						38	[		"
%var		ego.location				39	[		"
%var		ego.x					40	[This group is reset every frame.
%var		ego.y					41	[		"
%var		old.ego.x					42	[		"
%var		old.ego.y					43	[		"

%var		current.status				44
	%define	normal.ego		0
	%define	starting			1
	%define	walking			2
	%define	sliding			3
	%define	jumping			4
	%define	flying			5
	%define	falling			6
	%define	sleeping			7
	%define	waking.up			8
	%define	eating			9
	%define	sitting			10
	%define	swimming			11
	%define	sweeping			12
	%define	drowning			13
	%define	poofing			14
	%define	climbing			15
	%define	climbing.ladder	16
	%define	entranced			17
	%define	stunned			18
	%define	drunk			19
	%define	dead				20
	%define	hanging.in.kitchen	21
	%define	locked.in.bedroom	22
	%define	doing.aerobics		23
	%define	fly				25	[	These numbers = ego's view #'s.
	%define	eagle			26	[			"
	%define	snail			27	[			"
	%define	invisible			28	[			"
	%define	being.dragged		29
	%define	deferred.entry		30

	%define	fly.landing		125
	%define	eagle.landing		126
	%define	lcl.eagle.control	127

	%define	on.small.box		200
	%define	on.big.box		201
	%define	carrying.box		202
	%define	ate.cat.cookie		204	[	same as cat view #
	%define	wading			224

%var		debug.0					45
%var		debug.1					46
%var		seconds.in.room			47	
%var		wait.1			 		48	[	Always reset by new room.
%var		wait.2			 		49	[		"
%var		timer.1			 		50	[		"
%var		timer.2			 		51	[		"
%var		voyage.seconds				52
%var		voyage.minutes				53
	%define	underWay.init.minutes 14
	%define	nearLand.init.minutes  3
	%define	atBeach.init.minutes   3

%var		magic.seconds				54
%var		magic.minutes				55
	%define	magic.init.minutes	2

%var		map.area					56	[	where to teleport to
	%define	map.wiz.house		1		[	1-10 + 34
	%define	map.llewdor		2		[	11-32
	%define	map.beach			3		[	48-55
	%define	map.mountains		4		[	55-59
	%define	map.clouds		5		[	61-67
	%define	map.daventry		6		[	68-72
	%define	map.ship			7		[	78-86 + 31

%var		landing.x					57
%var		landing.y					58
%var		ego.cycle.time				59
%var		ego.step.time				60
%var		ego.step.size				61
%var		shipShape					62
[	%define	outAtSea			0		[	boat not yet landed
	%define	inPort			1
	%define	underWay			2
	%define	nearLand			3
	%define	atBeach			4
	%define	departed			5
	
%var		gold.coin.count			63
%var		loop						64	[This group is here to prevent 
%var		cell						65	[	redefining in every room.
%var		priority					66	[	Expect these to be garbage.
%var		view						67	[		"
%var		message					68	[		"
%var		step						69	[		"
%var		test.room					70
%var		spell.cast				71
	%define	sc.map			1
	%define	sc.poof			2
	%define	sc.fly			3
	%define	sc.eagle			4
	%define	sc.stop.flying		5
	%define	sc.visible		6
	%define	sc.invisible		7
	%define	sc.make.storm		8		[	must "make" first, then...
	%define	sc.start.storm		9		[	...we "start" the storm.
	%define	sc.stop.storm		10
	%define	sc.make.sleep		11
	%define	sc.start.sleep		12
	%define	sc.stop.sleep		13

%var		pre.previous.room			72
%var		deferred.x				73
%var		deferred.y				74
%var		storm.seconds				75
%var		storm.minutes				76
	%define	storm.init.minutes	 2

%var		source.x					78	[		"
%var		source.y					79	[		"
%var		target.x					80	[		"
%var		target.y					81	[		"
#var		old.ego.dir				82
%var		wiz.seconds				83
%var		wiz.minutes				84
	%define	wiz.init.minutes	 5
	%define	wiz.town.minutes	25
	%define	wiz.sleep.minutes	25
	%define	wiz.home.minutes	 5


[	Borrowed from Al's var numbers.

%var		zero						140	[	Kinda Konstants.
%var		one						141	[	Set by StartupLogic and
%var		two						142	[	never changed, ever!
%var		three					143
%var		four						144
%var		five						145




[	LOCAL VARS 	(use only in room logics; reset by room 0 init.logs)
%var		lv0						220
%var		lv1						221
%var		lv2						222
%var		lv3						223
%var		lv4						224
%var		lv5						225
%var		lv6						226
%var		lv7						227
%var		lv8						228
%var		lv9						229
%var		lv10						230
%var		lv11						231
%var		lv12						232
%var		lv13						233
%var		lv14						234
%var		lv15						235
%var		lv16						236
%var		lv17						237
%var		lv18						238
%var		lv19						239

					  
[	TEMP VARS	(use only in dynamic logics; reset by room 0 init.log)
%var		dv0						240
%var		dv1						241
%var		dv2						242
%var		dv3						243
%var		dv4						244
%var		dv5						245
%var		dv6						246
%var		dv7						247
%var		dv8						248
%var		dv9						249
%var		dv10						250
%var		dv11						251
%var		dv12						252
%var		dv13						253
%var		dv14						254
%var		dv15						255



[********** ANIMATED OBJECTS ************]
%object	ego						 0
%object	aGull1					12
%object	aGull2					13
	%define	smallGull			1		[	passed by "work" parameter
%object	a.poof					14
%object	a.wiz					15



[********* INVENTORY OBJECTS **********]
%define	inventory				   255
%define	size.of.inventory		    55	[	1 more than actual

%object	i.chicken.feather			1
%object	i.cat.hair				2
%object	i.dog.hair				3
%object	i.snakeskin				4
%object	i.fish.bone				5
%object	i.thimble					6
%object	i.dew					7
%object	i.dough.balls				8
%object	i.eagle.feather			9 
%object	i.fly.wings				10
%object	i.saffron					11
%object	i.rose.essence				12
%object	i.salt					13
%object	i.amber.stone				14
%object	i.mistletoe				15
%object	i.magic.stone				16
%object	i.nightshade.juice			17
%object	i.acorns					18
%object	i.empty.pouch				19
%object	i.sleep.powder				20
%object	i.mandrake.root			21
%object	i.fish.oil				22
%object	i.cat.cookie				23
%object	i.porridge				24
%object	i.porridge.poisoned			25
%object	i.ocean.water				26
%object	i.mud					27
%object	i.toadstool.powder			28
%object	i.fish.jar				29
%object	i.storm.brew				30
%object	i.toad.spit				31
%object	i.lard					32
%object	i.knife					33
%object	i.cactus					34
%object	i.lard.jar				35
%object	i.invisible.ointment		36
%object	i.magic.wand				37
%object	i.key					38
%object	i.magic.essence			39	
%object	i.bowl					40
%object	i.spoon					41
%object	i.cup					42
%object	i.mirror					43
[%object	44
[%object	45
[%object	46
%object	i.purse.empty				47
%object	i.purse.with.coins			48
%object	i.bread					49
%object	i.fruit					50
%object	i.mutton					51
%object	i.shovel					52
%object	i.treasure.chest			53
%object	i.magic.map				54



[********** MISC. CONSTANTS ************]
%define	text.color				15
%define	bg.color					0
%define	normal.step.size			1
%define	falling.step.size			3
%define	ego.stunned.time			5
%define	animal.talk.odds			2
%define	ego.falling.limit			145	[right-most ego.x for falling
%define	nowhere					0



[**********   DYNAMIC LOGICS   **********]
%define	lgc.wiz.status				92
%define	lgc.gimme.spells			93
%define	lgc.setup.boat				94
%define	lgc.setup.mountains			95
%define	lgc.trace					96 
%define	lgc.get.inventory			97
%define	lgc.error					98
%define	lgc.debug					99
%define	lgc.last					100
%define	lgc.startup				101
%define	lgc.help					102
%define	lgc.climbing				103
%define	lgc.wiz.house				104
%define	lgc.house.wiz				105
%define	lgc.PO'd.wiz				106
%define	lgc.inventory.check			107
%define	lgc.shovel				108 
%define	lgc.box					109
%define	lgc.stream.mud				110
%define	lgc.forest				111
%define	lgc.seagulls				112
%define	lgc.swim					113
%define	lgc.eagle.feather			114
%define	lgc.bandits.exterior		115
%define	lgc.pirates				116
%define	lgc.snowman				117
%define	lgc.medusa				118
%define	lgc.princess				119
%define	lgc.beach					120
[%define	lgc.spell.1				121
[%define	lgc.spell.2				122
[%define	lgc.spell.3				123
[%define	lgc.spell.4				124
[%define	lgc.spell.5				125
[%define	lgc.spell.6				126
[%define	lgc.spell.7				127
%define	lgc.desert				128
%define	lgc.near.desert			129
%define	lgc.daventry				130



[*********    SOUND EFFECTS    *********]
%define	s.ego.falling				1
%define	s.ego.poofing				2
%define	s.snoring					3
%define	s.zap					4
%define	s.ego.to.dust				5
%define	s.ego.stunned				6
%define	s.ocean					7
%define	s.dragon.fire				8
%define	s.thunder					9
%define	s.medusa.zapping			10
%define	s.splash					11
%define	s.growl					12
%define	s.screech					13
%define	s.eagle					14
%define	s.lightning				15



[************     MUSIC     ************]
%define	m.title					21
%define	m.credits					22
%define	m.cartoon					23
%define	m.winner					24
%define	m.whoops					25
%define	m.badguy					26
%define	m.wiz					27
%define	m.tavern					28
%define	m.pirate					29
%define	m.ocean					30
%define	m.gnome					31
%define	m.store					32
%define	m.princess				33
%define	m.bears					34
%define	m.spells 					35
%define	m.workout					36
%define	m.oracle					37
%define	m.shark					38
%define	m.shanghai				39
