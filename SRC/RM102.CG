[logics for room 102 -- lgc.help

%include	"rm102.msg"
%include	"gamedefs.al"
%include	"colors.h"



[	When debugging is set, all the messages are displayed.  If not, there
[are holes where the "undefined" function keys are.



prevent.input();
status.line.off();
set.text.attribute( blue, white);
text.screen();
last.char = 0;
reset( have.match);



[						blank	   
[						blank	   
				 display(  2, 12,  1);
				 display(  3, 18,  2);
[						blank	   
[						blank    
if (machine.type != ST)
				{display(  6,  3,  3);}
else	
				{display(  6,  3,  16);}
				 display(  7,  3,  4);
				 display(  8,  3,  5);
				 display(  9,  3,  6);
				 display( 10,  3,  7);
[if (debugging)	{display( 11,  3,  8);}
				 display( 12,  3,  9);
[if (debugging)	{display( 13,  3, 10);}
				 display( 14,  3, 11);
				 display( 15,  2, 12);
[						blank	   
[						blank	   
				 display( 18,  2, 13);
if (machine.type != ST)
				{display( 19,  2, 14);}
[						blank	   
[						blank	   
[						blank	   
else				{display( 19,  2, 17);
				 display( 20,	6, 18);
				 display( 21,  6, 19);}
[						blank	   
				 display( 23,  1, 15);
[						blank	   






:check.kb
if (!have.key())
	{
	goto	check.kb;
	}

accept.input();
status.line.on();
set.text.attribute( text.color, bg.color);
graphics();
set( have.match);

