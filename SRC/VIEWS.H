[
[	views.h
[
[			KING'S QUEST ]I[ SHARED GAME DEFINITIONS HEADER
[
[	11/5/86
[
[




[*************     VIEWS    ************]
%view	v.ego					0	[walking
%view	v.ego.climbing				1	[RLFB, rm50 & 57 cliffs
%view	v.ego.wading.deep			2	[RLFB, wet to calves
%view	v.ego.swimming				3	[standard swimmer
%view	v.ego.drowning				4	[V
%view	v.ego.is.arrow				5	[V, 1 cell; pointer
%view	v.ego.digging				6	[with shovel
%view	v.ego.wading.shallow		7	[knee deep
%view	v.ego.burning				8	[rm66, charred by dragon
%view	v.ego.sleeping				9	[rm4, diagonal view w/zzzzz's
%view	v.ego.sweeping				10	[RLVV, rm6
%view	v.ego.falling				11	[V, everywhere 
%view	v.ego.sleeping.l/r			12	[LR, rm42?, bear beds
%view	v.ego.to.dust				13	[V, after wiz zapped him;
%view	v.ego.turning.to.stone		14	[V, after medusa zapped him;
%view	v.ego.leaving.bed			15	[V, rm4
%view	v.ego.walking.plank			16	[AB, rm82
[	%define	l.plank			0		[
[	%define	l.ego.blindfolded	1		[
									[
%view	v.ego.breaking.bear.chair	17	[AB, rm41
[	%define	l.ego.breaking.the.chair 0	[
[	%define	l.broken.chair		1		[
									[
%view	v.ego.hanging.in.kitchen		18	[V, rm6
%view	v.ego.with.cat				19	[V, pussy in arms
%view	v.ego.with.chicken			20	[V, chick in arms
%view	v.ego.feeding.chickens		21	[ABC, 3 loops
[	%define	l.ego.throwing		0		[
[	%define	l.corn.in.air		1		[
[	%define	l.corn.on.ground	2		[
									[
[%view	________________			22
%view	v.ego.collapsing			23	[V, after drinking poison
%view	v.ego.dead				24	[V, 1 cell
%view	v.ego.fly					25	[V
%view	v.ego.eagle				26	[RL
%view	v.ego.snail				27	[RLFB
%view	v.ego.footprints			28	[RLFB
%view	v.ego.fonda				29	[ABC, 3 loops, different exercises
%view	v.ego.climbing.ladder		30	[BF <--note:  bassackwards
%view	v.ego.sitting				31	[LR <--note:  bassackwards
[	%define	l.sitting.left		0		[	check with BK; rm41
[	%define	l.sitting.right	1		[
									[
%view	v.ego.dusting				32	[
%view	v.ego.looking.under			33	[RL, rm4 & rm22
[	%define	l.looking.right	0		[rm4
[	%define	l.looking.rear		1		[rm22
									[
%view	v.ego.eating				34	[V, rm4
%view	v.ego.stunned				35	[V
%view	v.ego.jumping				36	[RL(F?B?), now under construction 
%view	v.ego.carrying.box			37	[RL, rm85-86
%view	v.gag.dead.ego.1			38	[ABCD, unrelated loops
[	38a		big ears
[	38b		fly eyes
[	38c		poofing
[	38d		sleeping ego (use a BobK's L/R loop)

%view	v.gag.dead.ego.2			39	[ABC ,     "       "
[	39a		cat (use a cat L/R loop)
[	39b		storm
[	39c		invisible

%view	v.snowman					40	[RLFF, rm55
%view	v.snowman.attacking			41	[RL, rm55
%view	v.snowman.dragging.ego		42	[RL, rm55
%view	v.oracle					43	[AB, rm36
[	%define	l.normal			0		[
[	%define	l.talking			1		[
									[
%view	v.crystal.ball.1			44	[AB, rm36
[	%define	l.colors			0		[
[	%define	l.colors.to.dragon	1		[
									[
%view	v.crystal.ball.2			45	[ABCD, rm36
[	%define	l.dragon			0		[
[	%define	l.dragon.to.girl	1		[
[	%define	l.girl			2		[
[	%define	l.girl.to.colors	3		[
									[
%view	v.dragonhead				46	[ABC, rm66 (real colors)
%view	v.dragon.flame				47	[RL, from mouth to ego
%view	v.dragon.roaring			48	[ABC, rm66 (gray only, no color)
[	%define	l.head.left		0		[
[	%define	l.head.middle		1		[
[	%define	l.head.right		2		[
									[
%view	v.snowman.bones			49	[V, rm60, 4 cels for add.to.pic's
[%view	________________			50
%view	v.squirrel				51	[RL,	  "		 "	    "    "
%view	v.bird					52	[RL,	  "		 "	    "    "
[%view	________________			53
%view	v.fish.1					54	[RL,	rm31		 "	    "    "
%view	v.spider.dead				55	[	NEW AS OF 9/11/86
%view	v.sharkfin				56	[RL, rm48, 49 baseline 5						[
%view	v.feather.falling			57 	[
%view	v.lizard					58	[RL, rm11		 "	    "    "
%view	v.snake					59	[RL, rm11		 "	    "    "
%view	v.title.stuff.1			60
[	%define	l.berta			0		[	60a	written by Roberta 
[	%define	l.programmers		1		[	60b	programmed by
[	%define	l.developers		2		[	60c	Development System by

%view	v.title.stuff.2			61
[	%define	l.artists			0		[	61a	graphics by				
[	%define	l.composer		1		[	61b	music composed by

%view	v.title.stuff.3			62
[	%define	l.numbers			0		[	62a	
[	%define	l.bolt			1		[	62b	
[	%define	l.letter.sparkles	2		[	62c	
[	%define	l.ray			3		[	62d

%view	v.mistletoe				63	[V, rm29
%view	v.wiz.head.credit.screen	    	64  	[large wizard face
%view	v.wiz.hand.credit.screen		65	[large hand
%view	v.spider					66	[V, rm14
%view	v.spider.eating.ego			67	[V
%view	v.spider.web				68	[V, cells go from ok to broken
%view	v.hugging					69	[ABCD, rm74, 4 loops
[	l.king.hugging.ego					[
[	l.queen.hugging.ego					[
[	l.king.hugging.girl					[
[	l.queen.hugging.girl				[
									[
%view	v.gnome					70	[ABC, rm69 discuss with REH
[	l.gnome.rocking					[includes chair
[	l.gnome.walking.left				[
[	l.gnome.walking.away				[
[	l.gnome.chair						[
%view	v.king					71	[RL
%view	v.queen					72	[RL
%view	v.princess				73	[RLFB
%view	v.princess.tied			74	[V
%view	v.princess.burned			75	[V
%view	v.bartender				76	[RLFB, rm40, a girl bar keep
%view	v.catching.venture.cap		77	[A = ego, B = princess;
%view	v.storekeeper				78	[RLFB, rm39
%view	v.store.dog				79	[V, rm39
%view	v.bear.papa				80	[RLFB, rm42
[%view	________________			81
%view	v.bear.mama				82	[RL, rm28
%view	v.bear.mama.kicking.ego		83	[V, rm28, 1 cell only
%view	v.bear.baby				84	[RL, rm28
%view	v.porridge				85	[V, 3 cells
[	%define	c.papa			0		[
[	%define	c.mama			1		[
[	%define	c.baby			2		[
									[
%view	v.bear.mama.in.garden		86	[V, rm28, on her knees
[%view	________________			87
%view	v.lab.stuff				88	[	c1=m&p; c2=burner; c3=book;
[%view	________________			89
%view	v.door.rm2				90	[V, closet doors with nightgowns
[%view	________________			91
%view	v.door.rm5				92	[V, cabinet in lower left corner
%view	v.trapdoor.rm5				93	[V, in floor
%view	v.door.rm24				94	[AB,	2 doors = 2 loops
[	l.tavern.door			A			[
[	l.store.door			B			[
									[
%view	v.door.rm28				95	[V, bear's house door
%view	v.doors.rm34				96	[AB
[	l.wiz.house.front.door 				[
[	l.chicken.pen.gate					[
									[
%view	v.door.castle				97	[V	from KQ1
%view	v.ship.sinking				98	[
[%view	________________			99
									
[	Views 101 - 154 reserved for "Show object" inventory views.
[See "iv-views.h"						
									
%view	v.gangplank				155	[V, rm75
%view	v.pirate.1				156	[RL, rm80, guy in red, walking
%view	v.pirate.2				157	[RL, rm80, guy in blue, walking
%view	v.pirate.cook				158	[RL, rm79
%view	v.pirate.captain			159	[RL, rm83
[	l.walking.right	0
[	l.walking.left		1

%view	v.footlocker				160	[V, rm83, end of bed
%view	v.treasure				161	[V
[	c.sand		0
[	c.open		8
[	c.hole		9

%view	v.splash                      162  [splash from ego falling from B.C 
%view	v.pirate.guard				163	[
%view	v.pirate.drinking			164	[ABC, rm40, surrounding table
[	l.captain		0					[
[	l.pirate.1	1					[
[	l.pirate.2	2					[

%view	v.attacking				165	[
%view	v.pirate.sleeping			166	[AB, rm84
[	l.bunk		0
[	l.deck		1				
	
%view	v.captain.writing			167	[V, rm83
%view	v.pirate.ship.box			168	[V must match box in view.37
%view	v.pirate.ship.shovel		169	[V, rm84, leaning against wall
%view	v.pirate.ship				170	[ABC, for dock in rm29/30/77
[	l.docked.rm29		0
[	l.docked.rm30		1
[	l.crossing.rm77	2

%view	v.pirate.ship.mouse			171	[RL, rm86
%view	v.pirate.ship.wake			172	[AB, rm82
%view	v.pirate.attacking			173	[V, rm78, in crowe's nest
%view	v.feather.duster.rm5		174	[V, 1 cell
%view	v.book.rm5				175	[V, moves right to left on shelf
%view	v.chamber.pot				176	[V, 1 cell
%view	v.tin.cup					177	[V, from Cauldron #38
%view	v.fire					178	[V, from Cauldron #115
%view	v.drawer.1.rm2				179	[V, under mirror
%view	v.drawer.2.rm2				180	[V, lower drawer of right dresser
[%view	________________			181
%view	v.drawer.rm42				182	[V, top drawer
[%view	________________			183
[%view	________________			184
%view	v.skull.and.crossbones		185	[V, rm78
%view	v.castle.banners			186	[AB, 
[	l.banner.rm71		0
[	l.banner.rm72		1

%view	v.cartoon.stuff			187	[ABC
[	%define	l.mirror.clearing	0		[
[	%define	l.mirror.sparkling	1		[
[	%define	l.venture.cap		2		[
									[
[%view	________________			188
[%view	________________			189
%view	v.wiz					190	[RLFB
%view	v.wiz.zap					191	[V, 2 cells?, word "ZAP" in caps
%view	v.wiz.at.scope				192	[V
%view	v.wiz.pointing				193	[RL
%view	v.wiz.sleeping				194	[V, with zzz's
%view	v.wiz.leaving.bed			195	[V, 3 cells
%view	v.wiz.sitting				196	[V, rm5, writing with quill pen
%view	v.wiz.eating				197	[V, rm8, eating & chewing
[%view	________________			198
%view	v.poof					199	[V, generic word to cloud
%view	v.blank.map				200	[V, blank rectangle to cover pic131
%view	v.birdseye.ship			201	[V, pic132
[%view	________________			202
%view	v.cat					203	[RLFB
%view	v.cat.wagging.tail			204	[RL
%view	v.chicken					205	[RL, rm34
%view	v.chicken.eating			206	[RL, rm34
%view	v.fly					207	[V, rm1, 2 pixels of white stuff
%view	v.kitchen.stuff			208	[V, 7 misc. cells
%view	v.bandits.drinking			209	[ABC, rm40, with holes for table
%view	v.bandit.1				210	[RLFB, rm23
%view	v.bandit.2				211	[RLFB, rm23
[%view	________________			212
[%view	________________			213
%view	v.bandit.sleeping			214	[V, rm38, with holes for chair
[%view	________________			215
%view	v.purse					216	[V, rm38, on table, with coins
%view	v.bandit.chest				217	[V, rm38, lid only
[%view	________________			218
[%view	________________			219
%view	v.signs.rm24				220	[AB
[	%define	l.tavern.sign		0		[
[	%define	l.store.sign		1		[
									[
%view	v.water.rm13				221	[ABC
[	%define	l.upper			0		[
[	%define	l.middle			1		[
[	%define	l.lower			2		[
									[
%view	v.water.rm14				222	[V
%view	v.water.rm19				223	[V
[%view	________________			224
%view	v.water.rm53				225	[V
%view	v.water.rm54				226	[V
%view	v.water.rm20				227	[V, around rock
[%view	________________			228
%view	v.water.piling				229	[V, rm25, around the posts
%view	v.candle.flame				230	[V, rm7
%view	v.torch.flame				231	[V, from Cauldron #124
%view	v.smoke					232	[ABCD
[	%define	l.smoke.rm28		0		[
[	%define	l.smoke.bg.rm24	1		[background houses; thin trail
[	%define	l.smoke.tavern.rm24	2		[
[	%define	l.smoke.rm29		3		[	and rm30
									[
[%view	________________			233
[%view	________________			234
[%view	________________			235
%view	v.lightning				236	[V, for the storm room
[%view	________________			237
[%view	________________			238
[%view	________________			239
%view	v.medusa					240	[RLFB, rm11
%view	v.medusa.turning.to.stone	241	[V, rm11
%view	v.snakeskin				242	[V, rm11
%view	v.cactii					243	[V, each cell a different kind
[	%define	c.THE.cactus		0		[
									[
%view	v.rocks					244	[V, rm32
%view	v.skulls					245	[V, rm32
%view	v.hills					246	[V, rm32
[%view	________________			247
%view	v.buzzards				248	[V, rm32
%view	v.seagull					249	[AB, rm25
[	l.big.bird		0
[	l.little.bird		1

%view	v.sparkles				250	[AB
[	l.big.sparkle		0
[	l.little.sparkle	1

%view	v.storm.wave				251 	[
