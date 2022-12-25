[logics for room 110 -- lgc.stream.mud

%include "gamedefs.al"
%include "rm110.msg"



[	Used by rooms 13, 14 & 19.



if (init.log)
	{
	return();
	}


if (!handsOff)
	{
	if (on.water && !ignore.water && waterView != wading)
		{
		set.view( ego, v.ego.wading.shallow);
		waterView = wadingShallow;
		}

	if (!on.water && waterView != normal.ego)
		{
		set.view( ego, v.ego);
		waterView = normal.ego;
		}
	}



if (!have.input)					{goto exit;}

if ((said( look) ||
	said( look, ground)))
	{
	print( 1);
	}

if ((said( look, stream) ||
	said( look, water)))
	{
	print( 3);
	}

if ((said( get, mud) || 
	said( get, mud, stream) || 
	said( get, mud, from, stream) || 
	said( get, mud, from, stream, with, spoon) || 
	said( get, mud, with, spoon)))
	{
	if (has( i.mud))
		{
		print( 9);
		}
	else
		{
		if (!near.mud)
			{
			print( 10);
			}
		else
			{
			if (!has( i.spoon))
				{
				print( 4);
				}
			else
				{
				print( 5);
				get( i.mud);
				drop( i.spoon);
				if (!found.mud)
					{
					set( found.mud);
					score += 1;
					}
				}
			}
		}
	}


if ((said( get, water, stream) ||
	said( get, water) ||
	said( get, water, cup)))
	{
	print( 7);
	}

if ((said( get, drink, water, stream) ||
	said( stream, get, drink, water) ||
	said( get, drink, water) ||
	said( get, drink) ||
	said( drink, water) ||
	said( drink)))
	{
	if (near.water)
		{
		print( 8);
		}
	else
		{
		print( 11);
		}
	}



[*****
:exit
[*****

