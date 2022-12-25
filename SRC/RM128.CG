[logics for room 128 -- lgc.desert

%include "gamedefs.al"
%include "rm128.msg"



[	Used by rooms 11, 16, 21, 26 & 32.



%define	lizard.1.moving		df9	[	This dynamic gets 9-15.
%define	lizard.2.moving		df10
%define	snake.here			df11
%define	lizards.here			df12
%define	lizard.1.on			df14
%define	lizard.2.on			df15


%define	lizard.1.timer			dv10
%define	lizard.2.timer			dv11
%define	flag.to.set			dv12
%define	animal.start			dv13
%define	animal.stop			dv14
%define	talk.seconds			dv15


%object	a.snake				10
%object	a.lizard.1			11
%object	a.lizard.2			12
	

if (init.log)
	{
	random( 1, 3, work);
	if  (current.room != 32 &&
		work == 1)
		{
		set( lizards.here);
		set( lizard.1.on);
		set( lizard.2.on);

		load.view( v.lizard);

		animate.obj( a.lizard.1);
		set.view( a.lizard.1, v.lizard);
		random( 10, 140, x);
		random( 70, 160, y);
		position.v( a.lizard.1, x, y);
		draw( a.lizard.1);
		lizard.1.timer = 2;

		animate.obj( a.lizard.2);
		set.view( a.lizard.2, v.lizard);
		random( 10, 140, x);
		random( 70, 160, y);
		position.v( a.lizard.2, x, y);
		draw( a.lizard.2);
		lizard.2.timer = 12;

		random( 1, animal.talk.odds, work);
		if   (has( i.dough.balls) &&
			 work == 1 &&
		    (!heardL1 ||
			!heardL2 ||
			!heardL3))
			{

			:which.message

			random( 1, 3, work);
			if (work == 1)
				{
				if (heardL1)
					{
					goto which.message;
					}
				else
					{
					flag.to.set = 143;
					animal.start = 14;
					animal.stop  = 17;
					}
				}

			if (work == 2)
				{
				if (heardL2)
					{
					goto which.message;
					}
				else
					{
					flag.to.set = 144;
					animal.start = 18;
					animal.stop  = 20;
					}
				}

			if (work == 3)
				{
				if (heardL3)
					{
					goto which.message;
					}
				else
					{
					flag.to.set = 145;
					animal.start = 21;
					animal.stop  = 22;
					}
				}

			random( 3, 8, talk.seconds);
			}
		}


	random( 1, 5, work)
	if (work == 1)
		{
		set( snake.here);
		load.view( v.snake);
		animate.obj( a.snake);
		set.view( a.snake, v.snake);
		random( 10, 140, x);
		random( 70, 160, y);
		position.v( a.snake, x, y);
		draw( a.snake);
		wander( a.snake);
		}

	return();
	}



[*****
:handle.input
[*****

if (!have.input)				{goto no.input;}

if ((said( look, desert) || said( look)))
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

if (said( look, trees))
	{
	print( 3);
	}

if (said( look, bones))
	{
	print( 4);
	}

if ((said( look, flowers) || 
	said( smell, flowers)))
	{
	print( 5);
	}

if (said( look, ground))
	{
	print( 6);
	}

if ((said( look, cactus) ||
	said( look, cactus, ground) ||
	said( look, ground)))
	{
	print( 7);
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

if ((lizard.1.on || lizard.2.on))
	{
	if (said ( look, lizard))
		{
		print( 8);
		}

	if (said( talk, lizard))
		{
		print( 23);
		}

	if (has( i.dough.balls) &&
		said( listen, lizard))
		{
		print( 24);
		}

	if (said( anyword, lizard))
		{
		print( 12);
		}
	}


if (snake.here && said( anyword, snake))
	{
	print( 13);
	}



[*****
:no.input
[*****

--lizard.1.timer;
if (lizard.1.timer == 1)
	{
	toggle( lizard.1.moving);
	if (lizard.1.moving)
		{
		set.view( a.lizard.1, v.lizard);
		wander( a.lizard.1);
		start.cycling( a.lizard.1);
		random( 9, 33, lizard.1.timer);
		}
	else
		{
		normal.motion( a.lizard.1);
		stop.motion( a.lizard.1);
		stop.cycling( a.lizard.1);
		random( 33, 99, lizard.1.timer);
		}
	}


--lizard.2.timer;
if (lizard.2.timer == 1)
	{
	toggle( lizard.2.moving);
	if (lizard.2.moving)
		{
		set.view( a.lizard.2, v.lizard);
		wander( a.lizard.2);
		start.cycling( a.lizard.2);
		random( 9, 33, lizard.2.timer);
		}
	else
		{
		normal.motion( a.lizard.2);
		stop.motion( a.lizard.2);
		stop.cycling( a.lizard.2);
		random( 33, 99, lizard.2.timer);
		}
	}



[*****
[Conversation pit (this conversation IS the pits!)
[*****

if  (aSecondPassed && 
	animal.start &&
	lizard.1.on &&
	lizard.2.on && 
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

if (edge.obj.hit && edge.obj.hit != top)
	{
	if (lizard.1.on && obj.hit.edge == a.lizard.1)
		{
		erase( a.lizard.1);
		reset( lizard.1.on);
		lizard.1.timer = 0;
		}

	if (lizard.2.on && obj.hit.edge == a.lizard.2)
		{
		erase( a.lizard.2);
		reset( lizard.2.on);
		lizard.2.timer = 0;
		}

	if (snake.here && obj.hit.edge == a.snake)
		{
		erase( a.snake);
		reset( snake.here);
		}
	}

