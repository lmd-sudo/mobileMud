// Rewrote by iszt@pkuxkx, 2007-02-11
#include "dong.h"
inherit ROOM;

void create()
{
	setshort();
	setlong();
    set("no_task",1);
	set("exits", ([
		"east" : __DIR__"dong45",
		"west" : __DIR__"dong04",
	]));
	setobject();

//	set("no_clean_up", 0);
	 	setup();
	replace_program(ROOM);
}