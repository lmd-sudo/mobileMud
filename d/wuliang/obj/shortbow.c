//Cracked by Roath
// bow.c

#include <ansi.h>
#include <weapon.h>

inherit ITEM;

void create()
{
	set_name("短弩", ({ "short bow", "bow"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("value", 500);
		set("bow_power", 22);
		set("str_requirement", 20);
		set("material", "wood");
		set("long", "这是一张普通的木制短弩。\n");
		set("wield_msg", "$N从背后抽出一张$n挽在手中。\n");
		set("unwield_msg", "$N将手中的$n插回背后。\n");
		set("unequip_msg", "$N将手中的$n插回背后。\n");
		
	}	
	setup();
}
