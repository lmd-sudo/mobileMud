#include <ansi.h>
inherit NPC;
void create()
{
	set_name("渡毅",({"bjddy npc"}));
	set("long",0);
	set("title","[31m少林[2;37;0m[32m长老[2;37;0m");
	set("age",233);
	set("str",28);
	set("con",39);
	set("int",30);
	set("spi",11);
	set("per",34);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname",0);
	set("combat_exp",100099624);
	set("max_qi",12319);
	set("max_jing",40900);
	set("gender","男性");
	set("max_neili",15450);
	set("max_jingli",13476);
	set("jiali",0);
	set("race","人类");
	set("class","bonze");
	set("repute",11405635);
	set("score",2003);
	set("family/family_name","少林派");
	set_skill("buddhism",1346);
	set_skill("flatter",1002);
	set_skill("yizhi-chan",1002);
	set_skill("iron-cloth",916);
	set_skill("zui-gun",1002);
	set_skill("dodge",1002);
	set_skill("cuff",1002);
	set_skill("whip",1002);
	set_skill("parry",1002);
	set_skill("daweituo-chu",1002);
	set_skill("staff",1002);
	set_skill("hunyuan-yiqi",630);
	set_skill("panguan-bifa",644);
	set_skill("literate",1001);
	set_skill("qishang-quan",400);
	set_skill("shaolin-shenfa",1002);
	set_skill("luohan-quan",1002);
	set_skill("jingang-buhuai",499);
	set_skill("medical-skill",1001);
	set_skill("yijin-jing",983);
	set_skill("riyue-bian",629);
	set_skill("nianhua-zhi",612);
	set_skill("finger",1002);
	set_skill("force",1001);
	map_skill("iron-cloth","jingang-buhuai");
	map_skill("dodge","shaolin-shenfa");
	map_skill("cuff","luohan-quan");
	map_skill("whip","riyue-bian");
	map_skill("parry","riyue-bian");
	map_skill("staff","daweituo-chu");
	map_skill("finger","yizhi-chan");
	map_skill("force","yijin-jing");
	setup();
}