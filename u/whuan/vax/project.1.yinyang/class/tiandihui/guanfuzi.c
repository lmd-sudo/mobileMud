// guanfuzi.c 关安基

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void do_decide();

void create()
{
	set_name("关安基", ({ "guan anji", "guan" }));
	set("title", HIR "天地会"HIG"青木堂"NOR"会众");
	set("nickname", "关夫子");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 35);
	set("long",
		"\n只见他长长的胡子飘在胸前，模样甚是威严。因此人称关夫子。\n");

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("max_neili", 1000);
	set("neili", 1000);
	set("max_jingli", 500);
	set("jingli", 500);

	set("jiali", 100);

	set("shen_type", 1);

	set_skill("hand", 80);
        set_skill("claw", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("force", 80);
	set_skill("blade", 120);
	set_skill("literate", 80);

	set_skill("yunlong-xinfa", 80);
	set_skill("yunlong-shou", 80);
	set_skill("yunlong-zhua", 80);
	set_skill("wuhu-duanmendao", 120);
	set_skill("yunlong-shenfa",100);
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "wuhu-duanmendao");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("force", "yunlong-xinfa");
	map_skill("hand", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");

	prepare_skill("hand", "yunlong-shou");
	prepare_skill("claw", "yunlong-zhua");

	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 25);

	set("combat_exp", 500000);
	set("attitude", "peaceful");

	create_family("天地会", 4, "弟子");

	set("chat_chance", 1);
	set("chat_msg", ({
	"关安基忽然说：本堂的香主谁来当，还轮不到我说话。\n",
	"关安基忽然说：唉，我的脾气不大好，大家可要小心了。\n",
	}));

	set("chat_chance_combat", 100);  
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),		
		(: perform_action, "blade.duan" :),
                      }) );

        set("inquiry", ([
		"陈近南" :  "\n为人不识陈近南，便称英雄也枉然。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
                "反清复明" : "去屠宰场和天桥仔细瞧瞧吧！\n",
       ]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
       if((string)ob->query("family/master_id") == "chen jinnan")
       {
	   command ("say 这位" + RANK_D->query_respect(ob) + "既已得到总舵主真传，又何必来找我呢?");
           return;
	}
		if((string)ob->query("gender")=="无性")

           {

 		command("say 云龙门顶天立地，怎会收你这样的废人？！");

		return;

	   }
	if ( ob->query("class")=="bonze" ) {
             if (ob->query("gender")=="女性")
		command ("say 师太还是先还俗了再来吧。");
	     else
		command ("say 大师傅还是先还俗了再来吧。");
	     return;
	}

      if((int)ob->query("betrayer")>=2)
   {
   command("say 你多次判师，我怎么能够收你!\n");
   return;
    }
   if((int)ob->query("shen") < 0)
   {
    command("say 你多行不义，如果收你岂不堕了天地会的名声？\n");
   return;
      }
		if ((string)ob->query("family/family_name") == "灵鹫宫"
			&& ob->query("lingjiu/xiulian"))
		{
			ob->set_temp("bai/ask",1);
        		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(decide)");

		}
		else
		{
       command("say 好吧，既然"+RANK_D->query_respect(ob)+"有意加入我天地会！我就收下你了！\n");
       command("recruit "+ob->query("id"));
		}
}
void do_decide()
{
	object me=this_player();
	if (!me->query_temp("bai/ask")) return;
        	command("say 好吧，"+RANK_D->query_respect(me)+"，我就收下你了！");
		me->set("mud_age",me->query("lingjiu/mud_age"));
		me->set("age",14+me->query("mud_age")/3600/24);
		me->delete("lingjiu/skill_status");
		me->delete("lingjiu/qi");
		me->delete("lingjiu/eff_qi");
		me->delete("lingjiu/max_qi");
		me->delete("lingjiu/jing");
		me->delete("lingjiu/eff_jing");
		me->delete("lingjiu/max_jing");
		me->delete("lingjiu/jingli");
		me->delete("lingjiu/neili");
		me->delete("lingjiu/max_jingli");
		me->delete("lingjiu/max_neili");
		me->delete("lingjiu/combat_exp");
		me->delete("lingjiu/need_xiulian");
		me->delete("lingjiu/mud_age");
		me->delete("lingjiu/xiulian");
		me->delete("lingjiu/last_xiulian_time");
		me->delete_temp("bai/ask");
	       command("recruit "+me->query("id"));

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("title", HIR "天地会"HIG"青木堂"NOR"小兄弟");

}
void re_rank(object student)
{
	if( ::recruit_apprentice(student) )
        student->set("title", HIR "天地会"HIG"青木堂"NOR"小兄弟");
}


void die()
{
message_vision("\n$N大怒道：“你敢砍老子！兄弟们会替我报仇的！”说完倒地死了。\n", this_object());
::die();
}
