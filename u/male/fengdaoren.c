//疯道人
// mudy
inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIR"疯道人"NOR, ({ "feng daoren","daoren" }) );
        set("gender", "男性" );
        set("age", 48);
        set("times", 50);
        set("long", 
            "他疯疯癫癫的,口中不停地念叨着算术之类的话语,偶尔还抓住过路的人问一些稀奇古怪的问题\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);
        set_skill("unarmed", 60);
        set_skill("dodge", 85);
        set_temp("apply/attack", 55);
        set_temp("apply/defense", 45);
        set("combat_exp", 12500);
        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "我是谁?我是谁?......\n",
            "名字" : "我是谁?我是谁?......\n",
            "你叫什么" : "我是谁?我是谁?......\n",
            "武当" : "武当?咦? 我好想去过,....不对,不对,.....没去过,没去过!\n",
            "全真" : "全真?不算道家,武当才是正宗!嘻嘻哈哈\n",
            "张三丰" : "呜呜,他要我下山的,师父不要我了.....呵呵,不过我现在更自在!\n咦?张三丰?张三丰是谁?不知道不知道!\n",
            "师父" : "师父....师父.....呵呵,你就是我的师父,我只认聪明的人做我的师父!你聪不聪明?\n",
            "算术" : "算术!你也会算术?算术好好玩!\n",
       ]) );
        setup();
        carry_object("/clone/armor/cloth")->wear();
        set("chat_chance", 40);
        set("chat_msg", ({
             "嘻嘻.....\n",
             "哈哈.....\n",
             "呵呵.....\n",
             "唉.....\n",
             "七七之数为阴....\n",
             "九九之数为阳....\n",
             "三为勾 四为股 五为弦..呵呵..\n",
             "咦?九属阴,而九九属阳,奇哉怪也!!\n",
             "九阴真经....不通不通!!\n",
                (: random_move :),
                (: random_move :),
                (: random_move :),
                (: random_move :),
                (: random_move :),
        }) );
}
int do_follow(string arg)
{
if(arg=="feng daoren"||arg=="daoren")
if(1)
{
message_vision("$N想跟随疯道人,结果反被疯道人吐了一口唾沫!\n",this_player());
return 1;
}
return 0;
}
void unconcious()
{
        die();
}
int start_busy(int time)
{
return 1;
}
void init()
{
object me;
me=this_player();
        ::init();
        add_action("do_answer","answer");
        add_action("do_follow","follow");
        if(!query_heart_beat())
                set_heart_beat(1);
        command("open door");
        command("open men");
      if(random(4)==0&&!me->query_temp("fengdaoren/begin"))
{
me->start_busy(2);
       call_out("question",1,me);
}
}
void question(object me)
{
int number,yushu;
{
me->start_busy(1);
if(me->query_int()<40) return;
message_vision(HIW"疯道人看到$N,一把抓住$N说道:看阁下似是聪慧之人,贫道有一难题请教阁下!\n",me);
number=16+random(66);
yushu=number-number/2*2;
message_vision(HIW"疯道人说道:\n有一数,比九九之数不足, 比四四之数尤剩\n然其除二余"+chinese_number(yushu)+", ",me);
yushu=number-number/3*3;
message_vision(HIW"除三余"+chinese_number(yushu)+", ",me);
yushu=number-number/5*5;
message_vision(HIW"除五余"+chinese_number(yushu)+", ",me);
yushu=number-number/7*7;
message_vision(HIW"除七余"+chinese_number(yushu)+", ",me);
//message_vision(HIW" "+chinese_number(number)+"\n",me);
message_vision(HIW"问此数几何?\n"NOR,me);
tell_object(me,"你可以用answer 做答\n");
me->set_temp("fengdaoren/number",number);
me->set_temp("fengdaoren/begin",1);
remove_call_out("overtime");
call_out("overtime",60,me);
}
}
int overtime(object me)
{
object thisplayer;
if(!me->query_temp("fengdaoren/number")) return 1;
 if( objectp( thisplayer = present(me->query("id"), environment(this_object())) ))
message_vision(HIW"疯道人对着$N"+HIW"冷笑道:正确答案应该是"+chinese_number(me->query_temp("fengdaoren/number"))+"!罢罢罢,这都算不出来...你走罢! \n"NOR,me);
me->delete_temp("fengdaoren");
return 1;
}
int do_answer(string arg)
{
object me;
object *ob;
int i;
int answernumber;
me=this_player();
if(!me->query_temp("fengdaoren/number")) return notify_fail("你要回答什么?\n");
if(sscanf(arg,"%d",answernumber)==1&&answernumber==me->query_temp("fengdaoren/number"))
{
message_vision(HIB"疯道人大喜:$N居然答对了!佩服佩服!\n"NOR,me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i])) continue;
                ob[i]->delete_temp("guards");
         }
start_busy(0);
add("times",-1);
if(query("times")<1)
{
set("times",50);
message_vision(HIR"疯道人"NOR+HIB"突然化成一道清烟消失掉了....\n"NOR,this_object());
this_object()->move("/d/city/guangchang.c");
message_vision(HIB"不知怎么回事,你突然发现身边多了一个"+HIR"疯道人!\n",this_object());
}
else
{
random_move();
}
this_player()->start_busy(1);
//奖励
            me->improve_skill("literate", 400 );
me->delete_temp("fengdaoren");
return 1;
}
else
{
message_vision(HIW"疯道人对着$N"+HIW"冷笑道:正确答案应该是"+chinese_number(me->query_temp("fengdaoren/number"))+"!罢罢罢,这都算不出来...你走罢! \n"NOR,me);
me->delete_temp("fengdaoren");
return 1;
}
}
