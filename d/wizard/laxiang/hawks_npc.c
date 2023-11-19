#include <ansi.h>
inherit NPC;
void create()
{
	set_name("朱棣",({"hawks npc"}));
	set("long",0);
	set("title","[1;31m天下第一镖[2;37;0m");
	set("age",144);
	set("str",31);
	set("con",27);
	set("int",35);
	set("spi",5);
	set("per",35);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname","存潜能准备出师，不当公务员了[2;37;0m[2;37;0m");
	set("combat_exp",101971494);
	set("max_qi",11577);
	set("max_jing",7956);
	set("gender","男性");
	set("max_neili",14725);
	set("max_jingli",11030);
	set("jiali",0);
	set("race","人类");
	set("class","officer");
	set("repute",5351212);
	set("score",4094);
	set("family/family_name","朝廷");
	set_skill("kuihua-zhua",1004);
	set_skill("staff",1004);
	set_skill("leadership",309);
	set_skill("unarmed",95);
	set_skill("blade",1004);
	set_skill("strategy",316);
	set_skill("daoxue-xinfa",99);
	set_skill("xiake-strike",190);
	set_skill("juemen-gun",1004);
	set_skill("jiuyin-shengong",119);
	set_skill("xiake-jianfa",150);
	set_skill("claw",1004);
	set_skill("kuangfeng-dao",1004);
	set_skill("xiake-quanjiao",190);
	set_skill("kuangfeng-jian",1004);
	set_skill("sword",1004);
	set_skill("dodge",1004);
	set_skill("identification",49);
	set_skill("hujia-daofa",1004);
	set_skill("fanwen",199);
	set_skill("bixue-xinfa",915);
	set_skill("force",990);
	set_skill("literate",811);
	set_skill("medical-skill",790);
	set_skill("xiake-shengong",175);
	set_skill("xiake-daofa",153);
	set_skill("parry",1004);
	set_skill("qishang-quan",159);
	map_skill("staff","juemen-gun");
	map_skill("unarmed","xiake-quanjiao");
	map_skill("blade","kuangfeng-dao");
	map_skill("claw","kuihua-zhua");
	map_skill("sword","kuangfeng-jian");
	map_skill("dodge","juemen-gun");
	map_skill("force","bixue-xinfa");
	map_skill("parry","juemen-gun");
	setup();
}