// greyrobe.c 灰色道袍
// By hacky

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("白色道袍", ({"pao", "cloth", "dao pao"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件普普通通的白色道袍。\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
