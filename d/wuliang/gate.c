// by paladin

inherit ROOM;

void create()
{
set("short","洞中小道");
        set("long", @LONG
洞中无丝毫光亮, 脚下平整，便似走在石板路上一般.
LONG
        );
set("outdoors", "dali");

        set("exits", ([
"north" : __DIR__"gate1",
"east" : __DIR__"droad1",
        ]));

// set("objects",([
//      __DIR__"npc/qingshe" : random(2),
//      __DIR__"npc/jinshe" : random(2),
//     ]));

        setup();
        replace_program(ROOM);
}
