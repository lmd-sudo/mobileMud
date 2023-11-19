// jiuyin-zhenjing1.c
#include <ansi.h>
inherit ITEM;
int do_study(string arj);

void create()
{
     set_name(MAG "九阴真经" NOR, ({ "jiuyin zhenjing", "zhenjing" }));
        set_weight(200);
        set("unit", "本");
        set("long", "这是道家武学之总纲「九阴真经」的上册，最后一篇好象文理不通，不只值不值的钻研(zuanyan).\n");
        set("value", 500);
	set("no_drop",1);
        set("no_get",1);
        set("material", "paper");
        set("skill", ([
                        "name": "jiuyin-shengong",      	// name of the skill
                        "exp_required": 100000,  	// minimum combat experience required
                        "jing_cost": 30+random(30),	// jing cost every time study this skill
                        "difficulty":   80,     	// the base int to learn this skill
                        "max_skill":    100      // the maximum level you can learn
        ]) );
setup();
}

void init()
{
add_action("do_study","study");
}

int do_study(string arg)
    {
        object me;
me = this_player();
if(arg == "zhenjing")
{
if( (int)me->query_skill("fanwen",80)<1)
    {
            write("你看了半天，还是看不出头绪，只隐隐觉的好象自己梵文水平不够。\n");
                return 1;
}
if ( (int)me->query_skill("literate", 1) < 100)
        {
                write("你看了半天，还是看不出头绪，只隐隐觉的好象自己读书写字水平不够。\n");
                return 1;
        }
if ( (int)me->query_skill("daoxue-xinfa", 1) < 100)
        {
                write("你看了半天，觉的上面写的很深奥，很难理会其中含义。\n");
                return 1;
        }

if((int)me->query("jing")>100)
{
me->add("jing",-80);
if ( (int)me->query_skill("jiuyin-shengong", 1) < 100)
{
      write ("你的九阴神功的级别太低了，领悟不了上面的文字. \n");
      return 1;
   }
if ( (int)me->query_skill("jiuyin-shengong", 1) < ((int)me->query_skill("fanwen")) )
{
 message_vision("$N正专心研读九阴真经的最后一篇. \n", me);
 me->improve_skill("jiuyin-shengong", (int)(((int)me->query_skill("fanwen", 1)+(int)me->query_skill("literate")+(int)me->query_skill("daoxue-xinfa"))/30+(int)me->query("int")/7));
write("你对九阴真经的最后一篇研读了一会,似乎有些心得, \n");
}
else
{
write("你对九阴真经的最后一篇琢磨了一会，发现上面的太过浅薄,
对你来说已毫无意义了.  \n");
}
}
else 
{
  write("你现在有些疲倦，无法专心下来研读新知. \n");
}
}
 return 1;
}
