// powerup.c
//modifid by cobra
#include <ansi.h>
inherit F_CLEAN_UP;
string query_name() { return "碧海"ZJBR"战气"; }
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill, levelskill, level;
        if( target != me )
                return notify_fail("你只能用碧海神功来提升自己的战斗力。\n");
        if( (int)me->query("neili") < 200  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
        if( (int)me->query_skill("bihai-shengong", 1)<50)
                return notify_fail("你的碧海神功等级不够，不能用来增强战斗力。\n");
 
        skill = me->query_skill("force");
        levelskill = me->query_sub_skill("music::shaw")/2 + me->query_skill("qimen-bagua", 1)/2;
        level = 5;
        if ( levelskill > 400 ) level = 3;
        else if ( levelskill > 300 ) level = 4;
        else level = 5;

        message_vision(HIR "$N凝神静气，暗运神功，顷刻间碧海神功的内力遍布全身。\n" NOR,me);
        me->add_temp("apply/attack", skill/level);
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("powerup", 1);
        me->add("neili", -100);

        me->set_temp("active_force_buffer/bihai-shengong.powerup/name", "加力");                                  //buff名称
        me->set_temp("active_force_buffer/bihai-shengong.powerup/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/bihai-shengong.powerup/effect1", "攻击命中+"+(skill/level)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/bihai-shengong.powerup/effect2", "轻功技能+"+(skill/level)+"级");       //效果描述2

        me->start_call_out(__FILE__, "remove_effect", skill/level, me, skill/level);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}
void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", -amount);
        me->add_temp("apply/dodge", -amount);
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/bihai-shengong.powerup");
        tell_object(me, "你的碧海神功运行完毕，将内力收回丹田。\n");
}

