//taskob
//Made by jason@pkuxkx
//2001.1.3

#include <ansi.h>
#include "task_obj.h"

inherit ITEM;

void create()
{
        set_name("家谱",({"jia pu"}));
        set_weight(4000);
        if(clonep())
                set_default_object(__FILE__);
        else
        {
                set("task_owner","murong fu");
                set("task_owner_cname","慕容复");
                set("reward_point",1);
                set("unit","本");
                set("no_sell",1);
                set("no_beg",1);
//              set("value",1000);
        }
        
        setup();
        
}

