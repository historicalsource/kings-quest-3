[logics for room 120 -- Beach talk

%include	"rm120.msg"
%include	"gamedefs.al"
%include	"iv-names.h"



if (!have.input)
	{
	return();
	}


if (said( look, plants))
	{
	print( 1);
	}

if (said( look, trees))
	{
	print( 2);
	}

if (said( look, ocean))
	{
	print( 4);
	}
										
if (said( look, sky))
	{
	print( 5);
	}

if (said( look, water))
	{
	print( 4);
	}

if (said( look, birds))
	{
	print( 7);
	}

if ((said( look) ||
	said( look, cliff) ||
	said( look, ground) ||
	said( look, beach)))
	{
	print( 3);
	}

if ((said( swim) ||
	said( swim, ocean) ||
	said( swim, water)))
	{
	print( 6);
	}

if ((said( drink, water) ||
	said( drink, ocean, water) ||
	said( drink, water, ocean) ||
	said( drink, water, cup) ||
	said( drink, ocean, water, cup) ||
	said( drink, salt, water, cup) ||
	said( drink, salt, water)))
	{
	print( 11);
	}

if ((said( get, water) ||
	said( get, ocean, water) ||
	said( get, water, ocean) ||
	said( get, water, cup) ||
	said( get, ocean, water, cup) ||
	said( get, salt, water, cup) ||
	said( get, salt, water)))
	{
	if (has( i.ocean.water))
		{
		print( 12);
		}
	else
		{
		if (!on.water)
			{
			print( 10);
			}
		else	
			{
			if (!has( i.cup))
				{
				print( 9);
				}
			else
				{
				print( 8);
				get( i.ocean.water);
				drop( i.cup);
				if (!got.ocean.water)
					{
					set( got.ocean.water);
					score += 1;
					}
				}
			}
		}
	}


[*****
:exit
[*****

