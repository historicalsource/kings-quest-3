[logics for room 100 -- init.log for room 0

%include	"gamedefs.al"



if (monitor.type != mono)
	{
	clear.lines( 22, 22, bg.color);
	clear.lines( 24, 24, bg.color);
	}

if (!force.a.test)
	{
	reset( debugging);
	reset( enable.trace);
	}

if (demo)
	{
	prevent.input();
	}

animate.obj( ego);
step.size( ego, ego.step.size);
step.time( ego, ego.step.time);
cycle.time( ego, ego.cycle.time);
get.posn( ego, ego.x, ego.y);

wait.1 = 0;						[	no global timers
wait.2 = 0;
timer.1 = 0;
timer.2 = 0;
ego.location = 0;
seconds.in.room = 0;
reset( out.of.memory);
reset( ego.poofing.done);
reset( survivable.fall);
reset( interiorRoom);
reset( ego.arrived);
reset( tooBusyForMap);

spell.cast = 0;					[	No carryover Rm0 special requests

reset( wiz.done);					[	wiz stuff
reset( erase.ego);
reset( wiz.arrived);
reset( wiz.on.screen);
reset( lgc.house.wiz.loaded);
reset( PO'd.wiz.init'd);
reset( force.wiz.come);
wiz.entrance.time = 0;
room.poofing.to = 0;
make.wiz.come = 0;
wiz.script = 0;
wiz.timer = 0;
wiz.y = 0;

work = 255;
:mr.looper						[All that remains of "reset the world"
if (work > 219)
	{
	reset.v( work);
	work @= 0;
	--work;
	goto mr.looper;
	}

set( drawEgo);						[	the default entry mode
set( positionEgo);

if (current.status == poofing)
	{
	reset( drawEgo);
	reset( positionEgo);
	set( handsOff);
	set( erase.ego);
	}

if (current.status == deferred.entry)
	{
	set( drawEgo);
	reset( positionEgo);
	position.v( ego, deferred.x, deferred.y);
	}

if ((current.status == eagle || current.status == fly))
	{
	reset( drawEgo);
	reset( positionEgo);
	set( handsOff);
	}

