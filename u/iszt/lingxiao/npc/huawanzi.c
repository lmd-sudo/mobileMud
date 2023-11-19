// File		: huawanzi.c
// Created By	: iszt@pkuxkx, 2007-03-07

#include "setdizi.h"

void create()
{
        setcreate(240);

	set_name("花万紫", ({ "hua wanzi", "hua", "wanzi", }));
	set("long", "这就是花万紫。\n");
	set("age", 41);
	set("gender", "女性");
	set("nick_name",HIM"寒梅女侠"NOR);
	set("str", 15);
	set("dex", 30);
	set("con", 20);
	set("int", 25);
	set("per", 22);

	add("inquiry", ([
		"name" : "在下花万紫。",
	]));

	create_family("雪山派", 6, "长门弟子");

	setup();
	setequip();
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping fam = ob->query("family");

	if(fam && ob->query("betrayer")>1 && fam["family_name"] != "雪山派")
	{
		command("say 你屡次叛师，将师门之义一手抹煞，在外早已是臭名昭著。"
			"本门信义为先，岂能容你！\n");
		return;
	}
	if(fam && fam["generation"] == me->query("family/generation"))
	{
		command("say " + (ob->query("gender")=="男性" ? "师弟" : "师妹") +
			"说笑了，有什么疑难之处可以和我切磋切磋，拜师哪谈得上！");
		return;
	}
	if(fam && fam["generation"] < me->query("family/generation"))
	{
		command("say 师叔说笑了，晚辈怎敢收您为徒？");
		return;
	}
	if(ob->query("gender") != "女性")
	{
		command("say " + RANK_D->query_respect(ob) + "去找我的师兄们拜师罢。");
		return;
	}

	command("nod "+ ob->query("id"));
	command("recruit "+ ob->query("id"));
	ob->set("title", "雪山派第七代长门弟子");
}