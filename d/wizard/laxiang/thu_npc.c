#include <ansi.h>
inherit NPC;
void create()
{
	set_name("大龙虾",({"thu npc"}));
	set("long",0);
	set("title","[31m武当派[2;37;0m[32m真人[2;37;0m");
	set("age",128);
	set("str",35);
	set("con",40);
	set("int",21);
	set("spi",5);
	set("per",44);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname",0);
	set("combat_exp",100008485);
	set("max_qi",23028);
	set("max_jing",8448);
	set("gender","男性");
	set("max_neili",13210);
	set("max_jingli",12844);
	set("jiali",0);
	set("race","人类");
	set("class","taoist");
	set("repute",1472855);
	set("score",505);
	set("family/family_name","武当派");
	set_skill("sword",940);
	set_skill("dodge",939);
	set_skill("hujia-daofa",945);
	set_skill("blade",946);
	set_skill("liumai-shenjian",942);
	set_skill("force",962);
	set_skill("medical-skill",828);
	set_skill("iron-cloth",659);
	set_skill("claw",602);
	set_skill("taiji-shengong",777);
	set_skill("beiming-shengong",703);
	set_skill("taiji-quan",944);
	set_skill("lingbo-weibu",939);
	set_skill("tiyunzong",905);
	set_skill("cuff",944);
	set_skill("literate",962);
	set_skill("finger",839);
	set_skill("yiyang-zhi",305);
	set_skill("parry",942);
	set_skill("taiji-zhao",605);
	set_skill("feihua-zhuyue",307);
	set_skill("taiji-jian",941);
	set_skill("taoism",693);
	set_skill("taiji-dao",409);
	map_skill("sword","liumai-shenjian");
	map_skill("dodge","lingbo-weibu");
	map_skill("blade","hujia-daofa");
	map_skill("force","beiming-shengong");
	map_skill("claw","taiji-zhao");
	map_skill("cuff","taiji-quan");
	map_skill("finger","feihua-zhuyue");
	map_skill("parry","taiji-quan");
	set("shen_type",1);set("score",500000);setup();
}