
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIB "雷灵珠" NOR, ({"lei lingzhu", "leizhu"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("material", "crystal");
                set("value",10000);
set("no_steal",1);
                set("no_give", "这种稀世之宝怎么能轻易送人呢?\n");
                set("no_sell", "卖?这种稀世之宝谁买得起啊!\n");
                set("long","传说中的五行宝珠之一，佩之可避雷击，并可发出雷击法术。\n为祈雨所必需之物。");
                set("bb",1);
                set("replace_file", __DIR__"rose");
                set("armor_prop/armor", 100);
                set("spells/thunder", 1);
        }
        setup();
}

int init()
{
        add_action("do_wear","wear");
        add_action("do_remove", "remove");
        return 1;
}

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wear (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if (arg != "all" && arg != "leizhu" &&  arg != "lei lingzhu" )
    return notify_fail("你要佩带什么？\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

  msg = "$N戴上一颗"+name+"，不禁精神一振。\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}

  zhu->set("wear_msg",msg);
remove_call_out("leizhuconditions");
call_out("leizhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if (arg != "all" && arg != "leizhu" && arg != "lei lingzhu")
    return notify_fail("你要摘掉什么？\n");

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

  msg = "$N将"+name+"轻轻地摘下来……\n"; 
if (me->is_fighting())
{
  me->start_busy(2);
}

  zhu->set("unequip_msg",msg);
  remove_call_out("leizhuconditions");
  return 0;
}

void leizhuconditions(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;
string type;
type = ob->query("armor_type");
if (!who) return;
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
        target = offensive_target(who);
     if( who->is_fighting() &&target) //by xlwang
     {
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIC
"\n雷灵珠突发异彩，半空走出位尖头鹰鼻的雷公，左手执斧，右手提锥。
斧锥相击，在$n的头顶炸起一片响雷！\n"NOR;

                ap = 2000000+(int)this_player()->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp )
           {
                damage = random(500) + 700;
                damage -= (int)target->query("max_neili") / 20 + random((int)target->query("eff_jing") / 5);
//here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) 
                {
                msg +=  HIR "\n$n被雷声震的眼冒金星，心神不定，差点跌倒在地！\n" NOR;
//finally damage also depends on enabled spells level.
                target->receive_damage("jing", damage);
                target->receive_wound("jing", damage/3);
                }
            else 
//here, cast failed and the target's mana_factor will be added to the previous 
//damage to hurt yourself:(...note damage<0.
                msg += HIC "\n谁知$n毫无反应。\n" NOR;
                 
           } 
        else
               msg += "\n谁知$n毫无反应，依旧一心一意地和$N战斗。\n";

        message_vision(msg, who, target);
    }
call_out("leizhuconditions",7,who,ob);
}
 
void owner_is_killed()
{
       destruct(this_object());
}
