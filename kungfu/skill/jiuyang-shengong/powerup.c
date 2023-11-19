// powerup.c 九阳神功加力

#include <ansi.h>

inherit F_CLEAN_UP;
 string query_name() { return "九阳"ZJBR"战气"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能用九阳神功来提升自己的战斗力。\n");

        if( (int)me->query("neili") < 100  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
              return notify_fail("你已经在运功中了。\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 40)
                return notify_fail("你的九阳神功等级不够，不能提升战斗力。\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_vision(
        HIR "$N运起九阳神功，真气从丹田处绵然不绝地流入四肢百骸，让身体每一处都真气鼓荡，充沛盎然之极却丝毫不显霸道。\n" NOR, me
);

//增强九阴和九阳
        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->set_temp("powerup", 1);

        me->set_temp("active_force_buffer/jiuyang-shengong.powerup/name", "加力");                              //buff名称
        me->set_temp("active_force_buffer/jiuyang-shengong.powerup/last_time", time() + skill );                //持续时间
        me->set_temp("active_force_buffer/jiuyang-shengong.powerup/effect1", "攻击命中+"+(skill/3)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/jiuyang-shengong.powerup/effect2", "轻功技能+"+(skill/3)+"级");       //效果描述2

        me->start_call_out(__FILE__, "remove_effect", skill, me, skill/3);

          if( me->is_fighting() ) me->start_busy(1)
;

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/jiuyang-shengong.powerup");
        tell_object(me, "你的九阳神功运行完毕，将内力收回丹田。\n");
}

