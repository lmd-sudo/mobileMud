#include <ansi.h>
inherit __DIR__"song_officer";
void create()
{
	call_out("npc_to_player",1,"中书令",60,-1);
	::create();
}
