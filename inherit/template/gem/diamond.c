// $file_name.c                                                 /* COMMENT_ENTRY */
// Create by TEMPLATE_D. $time.                                 /* COMMENT_ENTRY */
// skull.c
// Written by Lonely                                            /* COMMENT_EXIT  */

#include <ansi.h>

inherit TESSERA;

void create()
{
//**    set_name("$name", ({ "$id", }));                        /* NAME_ENTRY */
        set_name(HIW "水晶钻" NOR, ({ "diamond" }) );           /* NAME_EXIT  */
        set_weight(20);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/
        {
//**            set("$dbase_key", "$dbase_value\n");            /* DBASE_ENTRY */
                set("long", HIW "一粒精光闪闪的钻石。\n" NOR);  /* DBASE_EXIT  */
                set("value", 50000);
                set("unit", "颗");
                set("level", 2);
                set("material", "diamond");
                set("can_be_enchased", 1);
                set("magic/type", "metal");
                set("magic/power", 120);
                set("auto_load", 1);
        }
        set("enchase/weapon_prop/add_metal", 2);
        set("enchase/rings_prop/add_metal", 2);
        set("enchase/armor_prop/reduce_wood", 1);
        setup();
}

