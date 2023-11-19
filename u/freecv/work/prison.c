//Made by goodtaste

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
        set("short", "杀手帮监狱");
        set("long", @LONG
一间小小的囚室，六壁都是用铁筑成，只南边有个小窗但是也是用很粗的钢条做的，
看来这辈子你也别想出去了,东边的铁壁(wall)上好象有些字
LONG
        );
        
        set("valid_startroom", 1);
        set("exits", ([
                
                ]));
          set("objects", ([
            
           ]));
 set("sawed",1);
 set("count",4+random(4));
 set("item_desc", (["wall":"杀手三诀：\n第一：匿身藏行，精华内敛 \n第二：忠于师门，忠于朋友\n第三：苦修其身，以通武门\n"]));

        setup();
	
      
}


void init()
{  
   object me=this_player();
   object ob=this_object();
   message("vision","你隐约听见墙的那边传来一声轻轻的叹息: 怎么敲也敲不出来....\n",me);
   me->save();
   set("exits", ([
                
                ]));
   add_action("knock","qiao");
   add_action("unlock","saw");
}

int knock(string arg)
{   
   object ob;
   object me=this_player();
   if(!arg||arg==" ")
  { 
   write("你要敲什么?\n");
   return 1;
  }
   if(arg!="wall")
  {
   message("vision","你拿着拳头往头上乱敲一气，还是想不出办法出去\n",me);
   return 1;
  }
   switch(random(3))
  { 
    case 0:
           message("vision",BLU"你仔仔细细的把这屋子每一寸都敲遍了，也没发现什么特别之处\n"NOR,me);
           break;
    case 1:
           message("vision",BLU"你你仔仔细细的把这屋子每一寸都敲遍了，只是觉得这屋子有点邪门，
却看不出来到底哪里可能有出路\n",me);
           me->set_temp("flee",1);
           break;
    case 2:
           if(me->query_temp("flee"))
            {
              message("vision",BLU"你不甘心又从头找了起来，工夫不负有心人，你发现有块砖头似乎
是虚的，拿起一看，下面居然有一片锯条!!看来是以前囚于此处的人制作的.\n"NOR,me);
              me->delete_temp("flee");
              ob=new(__DIR__"obj/saw");
              ob->move(me);
            }
           else
              message("vision",BLU"你你仔仔细细的把这屋子每一寸都敲遍了，只是觉得这屋子有点邪门，
却看不出来到底哪里可能有出路\n",me);
           break;
}
  return 1;
}


int unlock()
{
   object me=this_player();
   object ob=this_object();
   if(me->query_temp("begin"))
   {
     write("你正在锯着呢!别太辛苦\n");
     return 1;
   }
     if(ob->query("exits/out")) 
    {
      write("窗户已经锯开了\n");
      return 1;
    }
   if ( present("saw", this_player()) )
   {
       me->start_busy(3);
       message("vision","你忙不叠的用锯条锯起窗户来\n",me);
       me->set_temp("begin",1);
       remove_call_out("opened");
       call_out("opened", 10, me, ob);
       return 1;
   }
   else
   {
       write("你要用牙锯钢条吗?\n");
       return 1;
   }
}
  

int opened(object me,object ob)
{
    object obb=present("saw", this_player());
  
   switch(random(2))
  {
    case 0:
            message("vision",YEL"你飞快的拉动锯条，不一会钢条就断掉了，你可以出去了!!\n"NOR,me); 
            set("exits", ([
                "out":__DIR__"houshan",
                ]));

            ob->set("sawed",0);
            me->delete_temp("begin");
            message("vision",BLU"你一时心急，把锯条给弄断了，幸好你已经用不着它了.\n"NOR,me);
            destruct(obb);
         destruct(obb); 
            break;
    case 1:
            message("vision","你好象听见外面有人在向这边走来，赶紧停了下来\n",me);
            me->start_busy(0);
            me->delete_temp("begin");
            break;
  }
return 1;
}



int valid_leave(object me, string dir)
{
   object ob=this_object();
   if(dir=="out"&&ob->query("count")>0)	
   {
   ob->add("count",-1);
   return ::valid_leave(me, dir);
   }
   else
   {
    return notify_fail("不成了，已经被发现了！老实点吧\n"); 
   }
}

