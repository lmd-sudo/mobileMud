//Cracked by Roath
// group bwdh/room kantai_w4
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "kantai.h"

void create() {
    set("short", "西看台四");
    set("long", @LONG
这里是比武场的西看台四。现在已经是人声鼎
沸，群雄议论纷纷，都在猜测哪个团队能折桂。四
周有些桌子(desk)。
LONG
    );
    set("exits", ([
        "east"  : __DIR__"kantai_n",
        "southwest" : __DIR__"kantai_w2",
    ]));
    create_kantai();
    setup();
}

void init() {
    init_kantai();
}
