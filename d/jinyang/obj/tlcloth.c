#include <armor.h>

inherit CLOTH;
#include <ansi.h>

void create()
{
        set_name(HIB"天蓝长袍"NOR, ({ "cloth",}) );
        set_weight(1000);
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("unit", "件");
				set("material", "cloth");
				set("armor_prop/armor", 1);
			}
        setup();
}