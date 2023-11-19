// qiangdao.c 强盗
// lag.2000/3/17

inherit NPC;
#include <ansi.h>
void move();

void create()
{
    string weapon;
    set_name(HIC "姑苏慕容叛徒" NOR, ({"murong pantu", "pantu"}));
    set("gender", "男性");
    set("age", 28);
    set("long", "他是一个姑苏慕容叛徒。\n");

    set("attitude", "peaceful");
    set_skill("force", 50);
    set_skill("sword", 50);
    set_skill("finger",  50);
    set_skill("strike",  50);
    set_skill("blade", 50);
    set_skill("dodge", 50);
    set_skill("parry", 50);

    set_skill("murong-jianfa", 50);
    set_skill("yanling-shenfa", 50);
    set_skill("xingyi-zhang", 50);
    set_skill("shenyuan-gong", 50);
    set_skill("canhe-zhi", 50);
    set_skill("murong-daofa", 50);
    set_skill("douzhuan-xingyi", 50);

    map_skill("parry","douzhuan-xingyi");
    map_skill("finger","canhe-zhi");
    map_skill("sword","murong-jianfa");
    map_skill("blade","murong-daofa");
    map_skill("force","shenyuan-gong");
    map_skill("dodge","yanling-shenfa");
    map_skill("strike","xingyi-zhang");

    prepare_skill("finger","canhe-zhi");
    prepare_skill("strike","xingyi-zhang");

    // 加下面5句是让强盗自动走，增添玩家做机器人的困难！-糖圆SMILE
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.liuxing" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "blade.daoying" :),
                (: perform_action, "blade.daoying" :),
                (: perform_action, "strike.xingdian" :),
                (: perform_action, "strike.xingdian" :),
                }));
    set("chat_chance", 5);
    set("chat_msg", ({
                (: random_move :)
                }) );

    set_temp("apply/attack", 100);
    set_temp("apply/defense", 100);
    set_temp("apply/armor", 100);

    weapon = random(2)?"/clone/weapon/changjian":"/clone/weapon/gangdao";
    setup();

    carry_object(weapon)->wield();
    carry_object("/clone/misc/cloth")->wear();

}

void init()
{
    if(this_player()->query("id") == this_object()->query("killer"))
        kill_ob(this_player());
    remove_call_out("leave");
    call_out("leave",15);
}

void leave()
{
    object ob = this_object();
    object me = find_player(ob->query("killer"));
    if (!ob->is_fighting() && ob->query("murong/pin")!=me->query("murong/pin")) {
        message_vision(HIC "姑苏慕容叛徒一闪身就不见了。\n" NOR,this_object());
        destruct(this_object());
    }
    else call_out("leave",30);
}

int do_copy(object me,int skill)
{
    int i,j;
    object ob;
    ob = this_object();

    ob->set("uni_target", me);
    ob->set("str", me->query("str"));
    ob->set("dex", me->query("dex"));
    ob->set("con", me->query("con"));
    ob->set("per", me->query("per"));

    if(me->query("combat_exp") > 1000000)
    {
        ob->set_name(HIC "姑苏慕容叛徒首领" NOR, ({"murong pantu", "pantu"}));
        ob->set("combat_exp", (me->query("combat_exp")* 3 / 4));
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 300);
    }
    else
        ob->set("combat_exp", (me->query("combat_exp")* 2 / 3));
    ob->set_skill("force", skill);
    ob->set_skill("sword", skill);
    ob->set_skill("finger",  skill);
    ob->set_skill("strike",  skill);
    ob->set_skill("blade", skill);
    ob->set_skill("dodge", skill);
    ob->set_skill("parry", skill);

    ob->set_skill("murong-jianfa", skill);
    ob->set_skill("yanling-shenfa", skill);
    ob->set_skill("xingyi-zhang", skill);
    ob->set_skill("shenyuan-gong", skill);
    ob->set_skill("canhe-zhi", skill);
    ob->set_skill("murong-daofa", skill);
    ob->set_skill("douzhuan-xingyi", skill);

    ob->set("jing",me->query("max_jing"));
    ob->set("eff_jing",me->query("max_jing"));
    ob->set("max_jing",me->query("max_jing"));
    ob->set("jingli",me->query("max_jingli"));
    ob->set("max_jingli",me->query("max_jingli"));
    ob->set("qi",me->query("max_qi"));
    ob->set("eff_qi",me->query("max_qi"));
    ob->set("max_qi",me->query("max_qi"));
    ob->set("neili",me->query("max_neili"));
    ob->set("max_neili",me->query("max_neili"));

    map_skill("parry","douzhuan-xingyi");
    map_skill("finger","canhe-zhi");
    map_skill("sword","murong-jianfa");
    map_skill("blade","murong-daofa");
    map_skill("force","shenyuan-gong");
    map_skill("dodge","yanling-shenfa");
    map_skill("strike","xingyi-zhang");

    prepare_skill("finger","canhe-zhi");
    prepare_skill("strike","xingyi-zhang");

    ob->set("jiali", skill/6);

    return 1;
}
//死亡管理
void die()
{
    object killer, yuxi;

    //如果找不到杀手，就暂时不死
    if(!objectp(killer = query_temp("last_damage_from")))
    {
        message_vision(HIY+this_object()->name()+"说道：君子报仇十年不晚，咱们后会有期。\n"NOR,this_object());
        destruct(this_object());
        return;
    }

    if(killer->query("murong/yuxi"))
    {
        yuxi = new("/d/murong/npc/obj/yuxi");
        yuxi->set_temp("owner/id", killer->query("id"));
        yuxi->move(this_object());
    }
    ::die();
}
void unconcious() { die();}
