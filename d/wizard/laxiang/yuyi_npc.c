#include <ansi.h>
inherit NPC;
void create()
{
	set_name("羽衣",({"yuyi npc"}));
	set("long",0);
	set("title","[32m天龙寺[2;37;0m[33m使者[2;37;0m");
	set("age",36);
	set("str",38);
	set("con",36);
	set("int",29);
	set("spi",8);
	set("per",37);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname",0);
	set("combat_exp",100228960);
	set("max_qi",10013);
	set("max_jing",8067);
	set("gender","女性");
	set("max_neili",12310);
	set("max_jingli",12015);
	set("jiali",0);
	set("race","人类");
	set("class","taoist");
	set("repute",2683708);
	set("score",2000);
	set("family/family_name","天龙寺");
	set_skill("sword",802);
	set_skill("dodge",801);
	set_skill("blade",101);
	set_skill("force",801);
	set_skill("liumai-shenjian",801);
	set_skill("medical-skill",519);
	set_skill("daoxue-xinfa",100);
	set_skill("claw",802);
	set_skill("taiji-shengong",863);
	set_skill("beiming-shengong",454);
	set_skill("xiantian-gong",106);
	set_skill("taiji-quan",801);
	set_skill("lingbo-weibu",801);
	set_skill("tiyunzong",801);
	set_skill("quanzhen-jian",802);
	set_skill("cuff",53);
	set_skill("literate",800);
	set_skill("tonggui-jian",803);
	set_skill("yiyang-zhi",252);
	set_skill("finger",250);
	set_skill("parry",802);
	set_skill("taiji-jian",801);
	set_skill("taiji-zhao",800);
	set_skill("feihua-zhuyue",301);
	set_skill("taoism",101);
	set_skill("taiji-dao",127);
	map_skill("sword","liumai-shenjian");
	map_skill("dodge","tiyunzong");
	map_skill("blade","taiji-dao");
	map_skill("force","taiji-shengong");
	map_skill("claw","taiji-zhao");
	map_skill("cuff","taiji-quan");
	map_skill("finger","liumai-shenjian");
	map_skill("parry","taiji-quan");
	set("shen_type",1);set("score",500000);setup();
}