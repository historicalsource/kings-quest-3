[logics for room 107 -- checking for bad things in ego's pants

%include	"gamedefs.al"
%include	"iv-names.h"



[	This dynamic checks ego for illegal objects, and takes them from him
[if he has them.  It always checks all the way through inventory.

[	These are the things it's ok for ego to carry around.
[
[	object == dough.balls		||	[	FREEBIES!
[	object == porridge			||
[	object == porridge.poisoned	||
[	object == knife			||
[	object == bowl				||
[	object == spoon			||
[	object == cup				||
[	object == bread			||
[	object == fruit			||
[	object == mutton			||
[	object == shovel			||
[	object == treasure.chest))



%define	location			view		[	reuse some cheap vars.
%define	object			work
%define	limbo			message



limbo = 0;						[	since we don't have a "drop.v()"
object = 1;						[	"object" is the object to check


:mr.looper.1
get.room.v( object, location);
if (location == inventory)
	{

	[	These give the message "up to No Good" as he removes the objects.

	if ((object == thimble			||	[	UP TO NO GOOD = DEATH!
		object == empty.pouch		||
		object == fish.jar			||
		object == lard.jar			||
		object == magic.wand		||
		object == key				||
		object == mirror			||
		object == purse.empty		||
		object == purse.with.coins	||
		object == magic.map))
		{
		make.wiz.come = has.bad.inventory;
		if (!PO'd.wiz.init'd)
			{
			set( force.wiz.come);
			}
		if (take.his.stuff)
			{
			put.v( object, limbo);
			}
		}
	}

++object;
if (object < size.of.inventory)
	{
	goto mr.looper.1;
	}


object = 1;						[	"object" is the object to check

:mr.looper.2
get.room.v( object, location);
if (location == inventory)
	{

	[	These give the message "removes the offending ingredients!"

	if ((object == chicken.feather	||	[	MAGIC INGREDIENTS = DEATH!
		object == cat.hair			||
		object == dog.hair			||
		object == snakeskin			||
		object == fish.bone			||
		object == dew				||
		object == eagle.feather		||
		object == fly.wings			||
		object == saffron			||
		object == rose.essence		||
		object == salt				||
		object == amber.stone		||
		object == mistletoe			||
		object == nightshade.juice	||
		object == acorns			||
		object == mandrake.root		||
		object == fish.oil			||
		object == ocean.water		||
		object == mud				||
		object == toadstool.powder	||
		object == toad.spit			||
		object == lard				||
		object == cactus))
		{
		make.wiz.come = has.ingredients;
		if (!PO'd.wiz.init'd)
			{
			set( force.wiz.come);
			}
		if (take.his.stuff)
			{
			put.v( object, limbo);
			}
		}
	}

++object;
if (object < size.of.inventory)
	{
	goto mr.looper.2;
	}



object = 1;						[	"object" is the object to check

:mr.looper.3
get.room.v( object, location);
if (location == inventory)
	{

	[	These give the message "you've used Sorcery of Old to make magic!"

	if ((object == magic.stone		||	[	HE'S MADE MAGIC = DEATH!
		object == sleep.powder		||
		object == cat.cookie		||
		object == storm.brew		||
		object == invisible.ointment	||
		object == magic.essence))
		{
		make.wiz.come = has.magic.inventory;
		if (!PO'd.wiz.init'd)
			{
			set( force.wiz.come);
			}
		if (take.his.stuff)
			{
			put.v( object, limbo);
			}
		}
	}

++object;
if (object < size.of.inventory)
	{
	goto mr.looper.3;
	}

