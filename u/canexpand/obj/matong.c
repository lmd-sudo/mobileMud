//Created by ldjt
inherit ITEM;
#include <ansi.h>

void create()
{
/*ITEM_NAME*/set_name("抽水马桶"
, ({
"ma tong", 
 }));
		set("value",random(10));//为防止玩家以此牟利，不能价值太高．
/*CANEXPAND*/ set("canexpand",1);
         
		if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", ""
/*LONG*/+"tong\n"
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//OVERLONG
);
                set("unit", 
/*SET_UNIT*/"只"
);
        }
        setup();
}