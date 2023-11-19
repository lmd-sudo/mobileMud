// heal.c

#include <ansi.h>
string query_name() { return "运功"ZJBR"疗伤"; }
int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if ((int)me->query_skill("cangming-gong", 1) < 20)
		return notify_fail("你的浩气苍冥功修为还不够。\n");
	if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	write( HIW "你坐下来，慢慢运起浩气苍冥功开始疗伤。\n" NOR);
	message("exert",
		HIW + me->name() + "全身有条若隐若现的黑龙游走，伤势逐渐平复。\n" NOR,
		environment(me), me);

	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(2);

	return 1;
}
