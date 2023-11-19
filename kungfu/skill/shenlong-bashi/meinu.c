#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
  string query_name() { return " 美人"ZJBR"三招 "; }
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("shenlong-bashi",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「美人三招」只能在战斗中使用。\n");
 
	if (me->query("gender") != "女性")
		return notify_fail("你不是纯阴之体，不能用美人三招！\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「美人三招」只能空手使用。\n");		
       
	 if( (int)me->query("neili") < 200 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("shenlong-bashi",1) < 70 )
                return notify_fail("你的神龙八式火候不够，无法使用「美人三招」！\n");

        if( (int)me->query_skill("force",1) < 60 )
                return notify_fail("你的内功修为不够，无法使用「美人三招」！\n");
	me->add_temp("apply/attack",2*extra);
	me->add_temp("apply/damage",2*extra);
	me->add_temp("apply/dexerity",extra);
	me->add_temp("apply/dodge",extra);
	weapon = me->query_temp("weapon");

        msg = CYN "$N动作抚媚，朝$n微微一笑"HIY"[美人三招]"CYN"！" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------贵妃回眸！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
            msg = HIW "第一道毒气"+HIR+"击中$n右身，！\n"NOR;   
            message_vision(msg, me, target);
            //target->set_temp("death_cond_origin/snake_poison", me);
			F_POISON->poison_attack(me,target,"snake_poison",10);
        }
        msg = GRN   "-------------------飞燕回翔！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
            msg = HIC "第二道毒气"+HIM+"扫中$n的左身！\n"NOR;   
            message_vision(msg, me, target);
            //target->set_temp("death_cond_origin/wugong_poison", me);
            F_POISON->poison_attack(me,target,"wugong_poison",10);
        }
        msg =  MAG  "-------------------------小怜横陈！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
            msg = MAG "最后一道毒气"+HIB+"扫中$n的上身!\n"NOR;   
            message_vision(msg, me, target);
            //target->set_temp("death_cond_origin/chanchu_poison", me);
            F_POISON->poison_attack(me,target,"chanchu_poison",10);;
        }
        me->add_temp("apply/attack",-2*extra);
        me->add_temp("apply/damage",-2*extra);
        me->add_temp("apply/dexerity",-extra);
        me->add_temp("apply/dodge",-extra);
        me->add("neili", -150);
        me->start_busy(3);

        return 1;
}

