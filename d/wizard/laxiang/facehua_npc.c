#include <ansi.h>
inherit NPC;
void create()
{
	set_name("独孤飘飘",({"facehua npc"}));
	set("long",0);
	set("title","[31m武当派[2;37;0m[32m真人[2;37;0m");
	set("age",237);
	set("str",27);
	set("con",25);
	set("int",37);
	set("spi",10);
	set("per",41);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname","[1;35m独孤山庄[1;36m--之--[1;33m[1;5m大少爷[2;37;0m[2;37;0m");
	set("combat_exp",100056884);
	set("max_qi",12997);
	set("max_jing",7408);
	set("gender","男性");
	set("max_neili",13853);
	set("max_jingli",13346);
	set("jiali",0);
	set("race","人类");
	set("class","taoist");
	set("repute",3257238);
	set("score",505);
	set("family/family_name","武当派");
	set_skill("claw",830);
	set_skill("cuff",602);
	set_skill("xiake-shengong",889);
	set_skill("taiji-jian",866);
	set_skill("dodge",890);
	set_skill("poyu-quan",600);
	set_skill("xiake-daofa",846);
	set_skill("huashan-neigong",482);
	set_skill("taoism",514);
	set_skill("tiyunzong",890);
	set_skill("literate",913);
	set_skill("medical-skill",725);
	set_skill("xiantian-gong",206);
	set_skill("taiji-shengong",362);
	set_skill("xiake-quanjiao",890);
	set_skill("zixia-shengong",201);
	set_skill("xiake-jianfa",846);
	set_skill("unarmed",890);
	set_skill("xiake-strike",890);
	set_skill("parry",890);
	set_skill("sword",891);
	set_skill("force",890);
	set_skill("yijin-jing",700);
	set_skill("blade",889);
	set_skill("tonggui-jian",700);
	set_skill("dugu-jiujian",890);
	set_skill("taiji-zhao",830);
	set_skill("strike",841);
	set_skill("quanzhen-jian",890);
	set_skill("qishang-quan",400);
	set_skill("hunyuan-zhang",670);
	set_skill("iron-cloth",754);
	set_skill("taiji-quan",890);
	set_skill("daoxue-xinfa",101);
	set_skill("huashan-jianfa",891);
	map_skill("claw","taiji-zhao");
	map_skill("cuff","taiji-quan");
	map_skill("dodge","tiyunzong");
	map_skill("unarmed","xiake-quanjiao");
	map_skill("parry","dugu-jiujian");
	map_skill("sword","xiake-jianfa");
	map_skill("force","xiake-shengong");
	map_skill("blade","xiake-daofa");
	map_skill("strike","xiake-strike");
	set("shen_type",1);set("score",500000);setup();
}