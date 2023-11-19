// yinfeng.c 阴风刀

#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#include "/kungfu/skill/shenghuo.h"
string query_name() { return " 圣火令法"ZJBR"阴风刀 "; }
int valid_target_arg(string target)
{
    if (target == "version")
        return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    int damage, p, force, lvl, bt, fails;
    string msg;
    object weapon, my_weapon;

    if (!target) target = offensive_target(me);

    if ( !objectp(target) || !me->is_fighting(target) || !living(target) || environment(target) != environment(me) )
        return notify_fail("阴风刀只能在战斗中对对手使用。\n");

//        if (!objectp(weapon = me->query_temp("weapon"))|| (string)weapon->query("id") != "shenghuo ling")

    if (!objectp(my_weapon = me->query_temp("weapon")) || (string)my_weapon->query("skill_type") != "dagger")
/*        if (!objectp(my_weapon = me->query_temp("secondary_weapon")) || (string)my_weapon->query("skill_type") != "dagger") */
        return notify_fail("你右手没有匕首类武器,不能使出圣火令法的阴风刀。\n");

    if (!present("shenghuo ling", me) && me->query_skill("shenghuo-lingfa", 1) < 800)
        return notify_fail("你必须使用圣火令来传递阴风刀内劲！\n");

    if ((int)me->query_skill("shenghuo-lingfa", 1) < 200)
        return notify_fail("你的圣火令法等级不够，不能施展阴风刀内劲！\n");

    if ((int)me->query_skill("force", 1) < 200)
        return notify_fail("你的基本内功等级不够，不能施展阴风刀内劲！\n");

    if ((int)me->query_skill("guangming-shenghuogong", 1) < 200)
        return notify_fail("你的光明圣火功等级不够，不能施展阴风刀内劲！\n");

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
         me->query_skill_mapped("force") != "guangming-shenghuogong")
        return notify_fail("阴风刀需要光明圣火功驱动内力！\n");

    if ((int)me->query("neili") < 1500)
        return notify_fail("你的内力不足，不能施展阴风刀内劲！\n");

    if ((int)me->query("max_neili") < 3000)
        return notify_fail("你的内力修为不足，不能施展阴风刀内劲！\n");
    if (me->query("combat_exp") / 200 > target->query("combat_exp") / 100)
        return notify_fail("对方比你差远了，施展阴风刀简直是浪费！\n");

    bt = me->query("betrayer");
    force = me->query_skill("force", "guangming-shenghuogong") + me->query_skill("guangming-shenghuogong", 1) / 2;
    lvl = me->query_skill("guangming-shenghuogong", 1);
    fails = me->query_temp("yinfeng/time");

    tell_object(me, HIW"\n你悄悄使出"BLU"阴风刀"HIW"，运起一股无形无质的阴寒之气，直插" + target->name() + "胸口玉堂要穴！\n"NOR);
//无失败次数未作新手任务，命中率是C-|C-=B+级别，无失败次数作新手任务，命中率是C-|C-|B-=A+级别
    if (F_KUNGFU->hit_rate(force, target->query_skill("force"), 9 - fails * 3, me, target)
        || F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 9 - fails * 3, me, target)
        || (me->query("family/family_name") == "明教" && me->query("mingjiaonewbiejobdone") &&
            !F_KUNGFU->hit_rate(target->query("combat_exp"), me->query("combat_exp"), 12, me, target)  //D-
           ))
    {
        me->delete_temp("yinfeng/time");
        damage = me->query_skill("shenghuo-lingfa", 1) / 3 + me->query_skill("guangming-shenghuogong", 1) / 2;
        damage += random(damage);
        if (me->query("neili") + lvl * 2 > target->query("neili") * 2)
            damage *= 2;
        else if (me->query("neili") + lvl * 2 > target->query("neili"))
            damage += random(damage / 2);
        else if (target->query("neili") > me->query("neili") * 2 + lvl * 4)
            damage /= 2;
        damage += me->query_skill("force", "guangming-shenghuogong") + random(me->query_skill("force", "guangming-shenghuogong"));
        damage += (int)me->query("mingjiaonewbiejobdone") * random(me->query_skill("force", 1));
        if (damage > 2000)
        {
            tell_object(target, HIB"\n突然之间，一股无形无质、利如钢刃的阴寒之气直插入你胸口的“玉堂穴”中！\n" +
                        HIR"你霎时之间闭气窒息，全身动弹不得！\n"NOR);
            if (!target->is_busy())
                F_KUNGFU->hit_busy("jiemai", lvl / 100 + random(2), target);
        } else if (damage <= 50)
        {
            damage = 10;
            tell_object(target, HIY"\n突然之间，一股利如钢刃般的阴寒之气直插你胸口的玉堂穴！\n" +
                        "幸好你护体神功遍护全身，这股阴风刀虽利，却也伤你不得！\n"NOR);
            tell_object(me, HIY"你连运阴风刀的内劲，但见对方竟是毫不费力的抵挡了下来！\n"NOR);
        } else
        {
            tell_object(target, HIB"\n突然之间，一股阴劲如刀、如剑、如匕、如凿，直插入你胸口的“玉堂穴”中！\n" +
                        HIR"你霎时之间闭气窒息，全身冰冷！\n"NOR);
            if (!target->is_busy())
                F_KUNGFU->hit_busy("jiemai", lvl / 200 + random(2), target);
        }
        F_KUNGFU->hit_wound("qi", damage / (bt + 1), damage / (bt + 3), me, target);
        target->add("neili", -damage / (bt + 3));

        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
        tell_room(environment(target), HIR + target->name() + "突然全身猛地一震，面如金纸，震退了数步，彷佛被什么人在胸口处猛击了一下似的！\n" NOR, (
        { target }));
        msg = damage_msg(damage, "内伤");
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        if (wizardp(me))
            tell_object(me, "yinfeng damage: " + damage + "。\n\n");
        me->add("neili", -lvl / 2);
    }
    else
    {
        me->add_temp("yinfeng/time", 1);
        if (me->query_temp("yinfeng/time") > 3)
            me->set_temp("yinfeng/time", 3);
        me->add("neili", -100);
        tell_object(me, HIY"结果阴风刀内劲还没触到" + target->name() + "的身体便已经散了。\n"NOR);
    }
    me->start_busy(2 + random(3));

    return 1;
}


