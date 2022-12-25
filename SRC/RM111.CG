[logics for room 111 -- lgc.forest

%include "gamedefs.al"
%include "rm111.msg"



[	Called by Rooms 12, 13, 14, 17, 22, & 27.  
[			Rooms 12, 13,     17,     & 27 have talking animals.
[			Rooms 	    14, 	& 22 	 just use the messages.  



%define	l.gray.right			0	[	squirrel loops
%define	l.gray.left			1
%define	l.brown.right			2
%define	l.brown.left			3

%define	l.blue.right			0	[	bird loops
%define	l.blue.left			1
%define	l.black.left			2
%define	l.black.right			3
 

%define	birds.here			df8	[	This dynamic gets 8-13.
%define	squirrels.here			df7
%define	animal.1.cycling		df10
%define	animal.2.cycling		df11


%define	animal.start			dv8
%define	animal.stop			dv9
%define	talk.seconds			dv10
%define	cycle.timer.1			dv11
%define	cycle.timer.2			dv12
%define	flag.to.set			dv13


%object	a.animal.1			12
%object	a.animal.2			13



if (init.log)
	{
	random( 1, 4, work);
	if ((work > 2 ||				[	no animals this time.
		current.status == eagle ||
		current.status == fly))
		{
		return();
		}

	if  (current.room != 12 &&
		current.room != 13 &&
		current.room != 17 &&
		current.room != 27)
		{
		return();					[	no animals in this room
		}


	if (work == 1)					[	The birds are here.
		{
		set( birds.here);
		load.view( v.bird);

		animate.obj( a.animal.1);
		set.view( a.animal.1, v.bird);
		ignore.horizon( a.animal.1);
		ignore.obj( a.animal.1);
		set.priority( a.animal.1, 15);
		stop.cycling( a.animal.1);

		animate.obj( a.animal.2);
		set.view( a.animal.2, v.bird);
		ignore.horizon( a.animal.2);
		ignore.obj( a.animal.2);
		set.priority( a.animal.2, 15);
		stop.cycling( a.animal.2);

		if (current.room == 12)
			{
			set.loop( a.animal.1, l.black.right);
			set.loop( a.animal.2, l.black.left);
			position( a.animal.1, 116, 51);
			position( a.animal.2, 93, 50);
			}	

		if (current.room == 13)
			{
			set.loop( a.animal.1, l.blue.right);
			set.loop( a.animal.2, l.blue.left);
			position( a.animal.1, 5, 113);
			position( a.animal.2, 34, 114);
			}	

		if (current.room == 17)
			{
			set.loop( a.animal.1, l.blue.right);
			set.loop( a.animal.2, l.blue.left);
			position( a.animal.1, 89, 58);
			position( a.animal.2, 103, 54);
			}	

		if (current.room == 27)
			{
			set.loop( a.animal.1, l.blue.right);
			set.loop( a.animal.2, l.blue.left);
			position( a.animal.1, 58, 65);
			position( a.animal.2, 71, 89);
			}	

		random( 1, animal.talk.odds, work);
		if  (has( i.dough.balls) &&
			work == 1 &&
		    (!heardB1 ||
			!heardB2 ||
			!heardB3 ||
			!heardB4))
			{

			:which.bird.message

			random( 1, 4, work);
			if (work == 1)
				{
				if (heardB1)
					{
					goto which.bird.message;
					}
				else
					{
					flag.to.set = 131;
					animal.start = 21;
					animal.stop  = 23;
					}
				}

			if (work == 2)
				{
				if (heardB2)
					{
					goto which.bird.message;
					}
				else
					{
					flag.to.set = 132;
					animal.start = 24;
					animal.stop  = 26;
					}
				}

			if (work == 3)
				{
				if (heardB3)
					{
					goto which.bird.message;
					}
				else
					{
					flag.to.set = 133;
					animal.start = 27;
					animal.stop  = 29;
					}
				}

			if (work == 4)
				{
				if (heardB4)
					{
					goto which.bird.message;
					}
				else
					{
					flag.to.set = 134;
					animal.start = 30;
					animal.stop  = 31;
					}
				}

			random( 3, 10, talk.seconds);
			}
		}
	else							[	if (work != 1, thus birds !here)
		{
		set(squirrels.here);
		load.view( v.squirrel);

		animate.obj( a.animal.1);
		set.view( a.animal.1, v.squirrel);
		ignore.horizon( a.animal.1);
		ignore.obj( a.animal.1);
		set.priority( a.animal.1, 15);
		stop.cycling( a.animal.1);

		animate.obj( a.animal.2);
		set.view( a.animal.2, v.squirrel);
		ignore.horizon( a.animal.2);
		ignore.obj( a.animal.2);
		set.priority( a.animal.2, 15);
		stop.cycling( a.animal.2);


		if (current.room == 12)
			{
			set.loop( a.animal.1, l.brown.right);
			set.loop( a.animal.2, l.brown.left);
			position( a.animal.1, 139, 134);
			position( a.animal.2, 150, 116);
			}	

		if (current.room == 13)
			{
			set.loop( a.animal.1, l.brown.right);
			set.loop( a.animal.2, l.brown.left);
			position( a.animal.1,   0, 118);
			position( a.animal.2,  31, 122);
			}	

		if (current.room == 17)
			{
			set.loop( a.animal.1, l.gray.right);
			set.loop( a.animal.2, l.gray.left);
			position( a.animal.1,  34,  41);
			position( a.animal.2,  59,  30);
			}	

		if (current.room == 27)
			{
			set.loop( a.animal.1, l.gray.right);
			set.loop( a.animal.2, l.gray.left);
			position( a.animal.1,  50, 118);
			position( a.animal.2,  74, 107);
			}	


		random( 1, animal.talk.odds, work);

		if (has( i.dough.balls) &&
			work == 1 &&
		    (!heardS1 ||
			!heardS2 ||
			!heardS3 ||
			!heardS4))
			{

			:which.squirrel.message

			random( 1, 4, work);
			if (work == 1)
				{
				if (heardS1)
					{
					goto which.squirrel.message;
					}
				else
					{
					flag.to.set = 139;
					animal.start = 32;
					animal.stop  = 36;
					}
				}

			if (work == 2)
				{
				if (heardS2)
					{
					goto which.squirrel.message;
					}
				else
					{
					flag.to.set = 140;
					animal.start = 37;
					animal.stop  = 39;
					}
				}

			if (work == 3)
				{
				if (heardS3)
					{
					goto which.squirrel.message;
					}
				else
					{
					flag.to.set = 141;
					animal.start = 40;
					animal.stop  = 41;
					}
				}

			if (work == 4)
				{
				if (heardS4)
					{
					goto which.squirrel.message;
					}
				else
					{
					flag.to.set = 142;
					animal.start = 42;
					animal.stop  = 44;
					}
				}

			random( 3, 10, talk.seconds);
			}
		}


	draw( a.animal.1);
	draw( a.animal.2);

	cycle.timer.1 = 2;
	cycle.timer.2 = 12;
	}							[	end INIT.LOG



[*****
:handle.input
[*****

if (have.input)
	{
	if ((said( look, plants) ||
		said( look, ground)))
		{
		print( 1);
		}

	if ((said( look, trees) || 
		said( look, tree) || 
		said( look)))
		{
		print( 2);
		}

	if (said( look, desert))
		{
		print( 3);
		}

	if (said( look, flowers))
		{
		print( 4);
		}

	if (said( look, sky))
		{
		print( 6);
		}

	if ((said( pick, flowers) || said( get, flowers)))
		{
		print( 7);
		}

	if ((said( climb, trees) || 
		said( climb, tree)))
		{
		print( 8);
		}

	if (said( look, rocks))
		{
		print( 9);
		}

	if (said( look, bird))
		{
		if (birds.here)
			{
			print( 10);
			}
		else
			{
			print( 13);
			}
		}

	if (said( look, squirrel))
		{
		if (squirrels.here)
			{
			print( 11);
			}
		else
			{
			print( 13);
			}
		}

	if (said( get, squirrel))
		{
		if (squirrels.here)
			{
			print( 12);
			}
		else
			{
			print( 13);
			}
		}

	if (said( get, bird))
		{
		if (birds.here)
			{
			print( 12);
			}
		else
			{
			print( 13);
			}
		}

	if (birds.here &&
		has( i.dough.balls) &&
		said( listen, bird))
		{
		print( 14);
		}

	if (squirrels.here &&
		has( i.dough.balls) &&
		said( listen, animal))
		{
		print( 14);
		}

	if (!near.cactus)
		{
		if (said( anyword, cactus))
			{
			print( 16);
			}
		}
	else
		{
		if (said (get, cactus))
			{
			print( 15);
			}
		
		if (said (anyword, cactus))
			{
			print( 17);
			}
		}
	}


[*****
[Conversation pit (this conversation IS the pits!)
[*****

--cycle.timer.1;
if (cycle.timer.1 == 1)
	{
	toggle( animal.1.cycling);

	if (animal.1.cycling)
		{
		start.cycling( a.animal.1);
		random( 9, 22, cycle.timer.1);
		}
	else
		{
		stop.cycling( a.animal.1);
		random( 9, 44, cycle.timer.1);
		}
	}

--cycle.timer.2;
if (cycle.timer.2 == 1)
	{
	toggle( animal.2.cycling);

	if (animal.2.cycling)
		{
		start.cycling( a.animal.2);
		random( 9, 22, cycle.timer.2);
		}
	else
		{
		stop.cycling( a.animal.2);
		random( 9, 44, cycle.timer.2);
		}
	}


if (aSecondPassed && 
	animal.start &&
	current.status == normal.ego &&
	seconds.in.room == talk.seconds)	[	start jabbering
	{
	talk.seconds = 0;
	set.v( flag.to.set);

	:animal.talk
	print.v( animal.start);
	if (animal.start < animal.stop)
		{
		++animal.start;
		goto animal.talk;
		}
	}


[*****
:exit
[*****

