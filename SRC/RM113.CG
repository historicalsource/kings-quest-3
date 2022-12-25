[Logics for room 113 -- lgc.ocean.swim

%include	"gamedefs.al"
%include	"rm113.msg"


[	Transitions ego from walking, to wade.shallow, to wade.deep, 
[to swim, and back again.  Ego walks when on.land, swims when 
[on.water && in swim box, wades.deep when on.water && in wade.deep box, 
[and wades.shallow when on.water and not in either of the other two boxes.



if (init.log)
	{
	load.view( v.ego.wading.shallow);
	load.view( v.ego.wading.deep);
	load.view( v.ego.swimming);
	}

if ((handsOff || invisibleEgo))
	{
	return();
	}

if (!on.water)
	{
	reset( keep.cycling);
	waterView = walkingEgo;
	}
else
	{
	reset( keep.cycling);
	if (!waterView)
		{
		waterView = swimmingEgo;
		}
	}

set.view.v( ego, waterView);

if (waterView == walkingEgo)
	{
	current.status = normal.ego;
	}

if ((waterView == wadingDeep ||
	waterView == wadingShallow))
	{
	current.status = wading;
	}

if (waterView == swimmingEgo)
	{
	current.status = swimming;
	set( keep.cycling);
	}


[*****
:exit
[*****

if (current.status != swimming &&
	said( swim))
	{
	print( 1);
	}

