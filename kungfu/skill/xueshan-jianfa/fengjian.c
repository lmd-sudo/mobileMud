// File		: fengjian.c
// Created By	: iszt, 2006-09-03

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define Menpai "雪山派"
string query_name() { return " 风  剑 "; }
string perform_name(){ return HIC" 风  剑 "NOR; }

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
	object weapon;
	string msg;
	
	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) 
	|| !living(target))
		return notify_fail("「风剑」只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("xueshan-jianfa", 1) < 90 )
		return notify_fail("你的雪山剑法功力太浅。\n");

	if( (int)me->query_skill("xueshan-jianfa", 1) < 150 )
		return notify_fail("你的雪山剑法功力不够，使不出「风剑」。\n");

	if( (int)me->query_skill("sword", 1) < 120 )
		return notify_fail("你的基本剑法还要多加练习才是！\n");
	if( (int)me->query_skill("xueshan-neigong", 1) < 120 )
		return notify_fail("你的雪山内功功力太浅，使不出「风剑」。\n");
		
	if( (int)me->query("max_neili") < 1200 )
		return notify_fail("你的内力修为太浅，使不出「风剑」。\n");
	if( (int)me->query("neili") < 800 )
		return notify_fail("你的真气不够，使不出「风剑」。\n");
    	if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        	&& !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        	&& me->query_skill_mapped("force") != "xueshan-neigong" )
		return notify_fail("你真气运转方式不对，使不出「风剑」。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword")
//	    || me->query_skill_mapped("sword") != "xueshan-jianfa")
		return notify_fail("你不装备一把剑，使不出剑法「风剑」。\n");

	if( me->query_temp("fengjian") )
		return notify_fail("你正在使用「风剑」！\n");
	
	msg="\n";
	if( me->query_temp("meijian")) {
		me->delete_temp("meijian");
		me->add_temp("apply/dodge",-me->query_skill("xueshan-jianfa",1)/2);
		me->delete_temp("active_buffer/xueshan-jianfa.meijian");
		msg=MAG"\n$N「梅剑」剑法使毕，红梅摇曳之景也随之消失。\n";
	}
	
	if( me->query_temp("shuangjian")) {
		me->delete_temp("shuangjian");
		me->add_temp("apply/damage",-me->query_skill("xueshan-jianfa",1)/4);
		me->delete_temp("active_buffer/xueshan-jianfa.shuangjian");
		msg=YEL"\n$N「霜剑」剑法使毕，冷霜铺地之态也随之消失。\n";
	}
	
	if( me->query_temp("xuejian")) {
		me->delete_temp("xuejian");
		me->add_temp("apply/parry",-me->query_skill("xueshan-jianfa",1)/2);
		me->delete_temp("active_buffer/xueshan-jianfa.xuejian");
		msg=WHT"\n$N「雪剑」剑法使毕，雪花飞舞之姿也随之消失。\n";
	}
	
	me->set_temp("fengjian",1);
	me->add("neili", -me->query_skill("xueshan-jianfa",1)/5*4);
	
	me->add_temp("apply/attack",me->query_skill("xueshan-jianfa",1)/2);
  me->set_temp("active_buffer/family","雪山派");
  me->set_temp("active_buffer/xueshan-jianfa.fengjian/name", "风剑");                          //buff名称
  me->set_temp("active_buffer/xueshan-jianfa.fengjian/last_time", time() + me->query_skill("xueshan-jianfa",1)/4 );                //持续时间
  me->set_temp("active_buffer/xueshan-jianfa.fengjian/effect1", "攻击命中+"+(me->query_skill("xueshan-jianfa",1)/2)+"级");         //效果描述1
	msg += HIC"\n$N剑法一转，便见朔风呼号之势，正是雪山剑法之「风剑」！\n"NOR;
	message_vision(msg,me,target);
	
	call_out("remove_effect", me->query_skill("xueshan-jianfa",1)/4 , me);
	return 1;
}

void remove_effect(object me)
{
	if (!me) return;
	if( me->query_temp("fengjian") ){		
		me->delete_temp("fengjian");
		me->add_temp("apply/attack",-me->query_skill("xueshan-jianfa",1)/2);
    me->delete_temp("active_buffer/xueshan-jianfa.fengjian");
    if ( sizeof(me->query_temp("active_buffer"))==1 )
      me->delete_temp("active_buffer");
		message_vision(CYN"\n$N「风剑」剑法使毕，朔风呼号之势也随之消失。\n" NOR,me);
		return;
	}
}

int help(object me)
{
        write(WHT"\n雪山剑法「风剑」："NOR"\n");
        write(@HELP
	雪山剑法有四种变化：梅、雪、风、霜，这「风剑」便是其中之一。红梅摇
	曳之景，雪花飞舞之姿，朔风呼号之势，冷霜铺地之态，均可分别在这四种
	剑法中找到。「风剑」可以在与敌作战时，提高自己的攻击能力。
	
        要求：  内力 800 以上；      
                最大内力 1200 以上；  
                基本剑法等级 120 以上；
                雪山剑法等级 150 以上；
                雪山内功等级 120 以上；    
                且使用雪山剑法。
HELP
        );
        return 1;
}
