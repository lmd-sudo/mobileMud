#include <ansi.h>
inherit NPC;
void create()
{
	set_name("蓝色天蝎",({"bluecmy npc"}));
	set("long",0);
	set("title","[1;34m全真派[2;37;0m[31m天仙[2;37;0m");
	set("age",182);
	set("str",24);
	set("con",34);
	set("int",32);
	set("spi",7);
	set("per",25);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname","[1;34m沧海[1;37m月[1;33m明[1;35m珠[1;36m有[1;37m[1;5m泪[2;37;0m[2;37;0m[2;37;0m");
	set("combat_exp",100132543);
	set("max_qi",33930);
	set("max_jing",6797);
	set("gender","男性");
	set("max_neili",13249);
	set("max_jingli",10696);
	set("jiali",0);
	set("race","人类");
	set("class","taoism");
	set("repute",1073375);
	set("score",1509);
	set("family/family_name","全真派");
	set_skill("literate",819);
	set_skill("medical-skill",469);
	set_skill("cuff",937);
	set_skill("identification",60);
	set_skill("taiji-jian",961);
	set_skill("yiyang-zhi",838);
	set_skill("iron-cloth",673);
	set_skill("taiji-dao",808);
	set_skill("taiji-quan",988);
	set_skill("tiyunzong",920);
	set_skill("taoism",1207);
	set_skill("array",156);
	set_skill("unarmed",237);
	set_skill("xiantian-gong",520);
	set_skill("daoxue-xinfa",306);
	set_skill("hujia-daofa",999);
	set_skill("quanzhen-jian",814);
	set_skill("parry",1000);
	set_skill("force",824);
	set_skill("finger",811);
	set_skill("taiji-zhao",952);
	set_skill("blade",996);
	set_skill("claw",818);
	set_skill("tiangang-beidou",127);
	set_skill("sword",928);
	set_skill("taiji-shengong",867);
	set_skill("training",19);
	set_skill("tonggui-jian",802);
	set_skill("dodge",991);
	map_skill("cuff","taiji-quan");
	map_skill("array","tiangang-beidou");
	map_skill("parry","hujia-daofa");
	map_skill("force","taiji-shengong");
	map_skill("finger","yiyang-zhi");
	map_skill("blade","hujia-daofa");
	map_skill("claw","taiji-zhao");
	map_skill("sword","taiji-jian");
	map_skill("dodge","tiyunzong");
	setup();
}