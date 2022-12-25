[ rm 116 - Logic of landHo for the pirates

[ This rooms sole function is to detect a change of state that...

#include	"gamedefs.reh"
#include	"rm116.msg"


if (landHo){
	reset(landHo);
	if (shipShape == nearLand){
		print(1);
	}
	if (shipShape == atBeach){
		print(2);
	}
}

if (aSecondPassed && shipShape == departed){
	print(3);
	stop.cycling(ego);
	set(certain.death);
}
