// $file_name.c                                                 /* COMMENT_ENTRY */
// Create by TEMPLATE_D. $time.                                 /* COMMENT_ENTRY */
// skull.c
// Written by Lonely                                            /* COMMENT_EXIT  */

#include <ansi.h>

inherit TESSERA;

void create()
{
//**    set_name("$name", ({ "$id", }));                        /* NAME_ENTRY */
        set_name(HIY "细碎的黄宝石" NOR, ({ "chipped topaz" }) ); /* NAME_EXIT  */
        set_weight(20);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/
        {
//**            set("$dbase_key", "$dbase_value\n");            /* DBASE_ENTRY */
                set("long", HIY "一片黄色的黄宝石碎片。\n" NOR); /* DBASE_EXIT  */
                set("value", 20000);
                set("unit", "颗");
                set("level", 1);
                set("material", "ctopaz");
                set("can_be_enchased", 1);
                set("magic/type", "earth");
                set("magic/power", 70);
                set("auto_load", 1);
        }
        set("enchase/weapon_prop/add_earth", 1);
        set("enchase/rings_prop/add_earth", 1);
        set("enchase/armor_prop/reduce_water", 1);
        setup();
}

