// $file_name.c                                                 /* COMMENT_ENTRY */
// Create by TEMPLATE_D. $time.                                 /* COMMENT_ENTRY */
// skull.c
// Written by Lonely                                            /* COMMENT_EXIT  */

#include <ansi.h>

inherit TESSERA;

void create()
{
//**    set_name("$name", ({ "$id", }));                        /* NAME_ENTRY */
        set_name(HIB "稀世蓝宝石" NOR, ({ "flawless sapphire" }) );   /* NAME_EXIT  */
        set_weight(20);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/
        {
//**            set("$dbase_key", "$dbase_value\n");            /* DBASE_ENTRY */
                set("long", HIB "一颗美得无与伦比的大蓝宝石。\n" NOR);  /* DBASE_EXIT  */
                set("value", 100000);
                set("unit", "颗");
                set("level", 3);
                set("material", "fsapphire");
                set("can_be_enchased", 1);
                set("magic/type", "water");
                set("magic/power", 200);
                set("auto_load", 1);
        }
        set("enchase/weapon_prop/add_water", 3);
        set("enchase/rings_prop/add_water", 3);
        set("enchase/armor_prop/reduce_fire", 1);
        setup();
}

