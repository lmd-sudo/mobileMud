// guiyunzhuang/shulin2 树林
// Made By:pingpang
inherit ROOM;

void create()
{
        set("short", "树林");
       set("long", @LONG 
这是归云庄前的太湖边上的树林子，里面看起来阴森森的，让人不禁心寒！
LONG);
       set("exits", ([ /* sizeof() ==4 */
        "north" : __DIR__"shulin1",
        "south" : __DIR__"shulin3",
	"west"  : __DIR__"shulin6",
	"east"  : __DIR__"shulin4",
        ]));
	set("outdoors","guiyunzhuang"),
	setup();
	replace_program(ROOM);
}