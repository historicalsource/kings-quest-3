[logics for room 129 -- lgc.near.desert

%include "gamedefs.al"
%include "rm129.msg"



[	Used by rooms 12, 17, 22, & 27.



if ((init.log || !have.input))
	{
	return();
	}



[*****
:handle.input
[*****

if ((said( look, room) || said( look)))
	{
	print( 1);
	}

if (said( look, flower))
	{
	print( 2);
	}

if (said( look, trees))
	{
	print( 3);
	}

if ((said( look, flowers) || 
	said( smell, flowers)))
	{
	print( 5);
	}

if (said( look, ground))
	{
	print( 1);
	}

if (said( look, sky))
	{
	print( 9);
	}

if ((said( pick, flowers) || 
	said( get, flowers)))
	{
	print( 10);
	}

if (said( climb, trees))
	{
	print( 11);
	}
