#include <ansi.h>
inherit ITEM;
#include "special_formula.h"
void create()
{
        set_name("聚精剂古方", ({"jujingji gufang", "fang","prescription"}));
        set_weight(50);
        set("long", "这是一张不知从何处流传下来的聚精剂配方。\n");
        set("unit", "张");
		set("value",85000000);
		setup();
}

