[logics for room 98 -- disk-based error handling

#include	"sysdefs"


%message	1	"discard.view(%v18):%m30";
%message	2	"set.view(%v18,_):%m26";
%message	3	"set.view(_,%v18):%m30";
%message	4	"set.loop(%v18,_):%m26";
%message	5	"set.loop(%v18,_):\nBad loop #.%m25";
%message	6	"set.loop(%v18,_):%m31";
%message	7	"set.cel(%v18,_):%m26";
%message	8	"set.cel(%v18,_):\nBad cel #.%m25";
%message	9	"sound(%v18):\nSound not loaded.%m25";
%message	10	"set.cel(%v18,_):%m31";
%message	11	"Script buffer overflow.\nMaximum size = %v18%m25";
%message	12	"erase(%v18):%m26";
%message	13	"animate.obj(%v18):%m26";
%message	14	"print(%v18): no message%m25";
%message	15	"Bad test: %v18%m25";
%message	16	"Bad action: %v18%m25";
%message	17	"start.update(%v18):%m28";
%message	18	"draw.pic(%v18):%m32";
%message	19	"draw(%v18):%m26";
%message	20	"draw(%v18):%m31";
%message	21	"discard.pic(%v18):%m32";
%message	22	"set.scan.start() already active\nin logic %v18.%m25";
%message	23	"get(%v18) or put(%v18):%m26";

%message	24	""

%message	25	"\nPress ESC to quit.";
%message	26	"%m27.%m25";					[Bad object number
%message	27	"\nBad object number";
%message	28	"%m27 or object not drawn.%m25"	[ " " " or object not drawn
%message	29	"\nView not ";
%message	30	"%m29loaded.%m25";				[View not loaded
%message	31	"%m29set.%m25";				[View not set
%message	32	"Picture not loaded.%m25";


print.f( error.number);
quit(1);
