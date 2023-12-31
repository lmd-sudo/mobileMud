// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit WEAPONTYPE;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("WEAPON_SWORD", ({ "WEAPON_ID", "IDTYPE" }));
	set_weight(weighttext);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "unittext");
		set("long", @LONG
LONG_TITLE
LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ownertext");
		set("ownername", "ownernametext");
		set("value", valuetext);
 set("forge/max", damagetext);
  set("forge/times_max", damagetext);
  set("level", damagetext);
if(query("weapon_prop/damage"))
     set("weapon_prop/damage", damagetext);
     set("weapon_prop/attack", attacktest);
     set("weapon_prop/defense", defensetext);
     set("weapon_prop/armor", armortext);
     set("weapon_prop/magic", magictest);
     
     
 //先天类    
		set("weapon_prop/intelligence",inttext);
		set("weapon_prop/strength",strtext);
		set("weapon_prop/personality",pertext);
    set("weapon_prop/spirituality", kartext);
		set("weapon_prop/dexerity",dextext);
		set("weapon_prop/constitution",context);
    //技能类
  //  set("weapon_prop/claw", clawtext);
   // set("weapon_prop/cuff", cufftest);
   // set("weapon_prop/dodge", dodgetext);
    //set("weapon_prop/finger", fingertest);
    //set("weapon_prop/hand", handtest);
   // set("weapon_prop/parry", parrytest);
    //set("weapon_prop/strike", striketest);
    //set("weapon_prop/unarmed", unarmedtest);
    //set("weapon_prop/blade", bladetest);
    //set("weapon_prop/whip", whiptest);
    //set("weapon_prop/staff", stafftest);
  //  set("weapon_prop/force", forcetest);
  //  set("weapon_prop/dagge", daggetest);
    //set("weapon_prop/hammer", hammertest);
    //set("weapon_prop/spear", speartest);
    //set("weapon_prop/throwing", throwingtest);
    
    
   
//特效数值
       set("weapon_prop/kf_def_wound", atext);
    set("weapon_prop/kf_wound", btext);
    set("weapon_prop/cant_all_busy", ctext);
    set("weapon_prop/weapon_effect_jing", dtext);
    set("weapon_prop/weapon_effect_poison", etext);
    set("weapon_prop/weapon_effect_suck", ftext);
  //  set("weapon_prop/cant_busy_confuse", gtext);
  //  set("weapon_prop/cant_busy_body", htext);
    set("weapon_prop/max_all_busy", gtext);
  //  set("weapon_prop/max_busy_dianxue", jtext);
    //set("weapon_prop/max_busy_jiemai", ktext);
   // set("weapon_prop/max_busy_fenjin", ltext);
   // set("weapon_prop/max_busy_confuse", mtext);
   // set("weapon_prop/max_busy_body", ntext);
   // set("weapon_prop/AllPoisonsImmune", otext);
  //  set("weapon_prop/PoisonAttack", ptext);
    set("weapon_prop/kf_hit_rate", htext);
    set("weapon_prop/kf_anti_hr", itext);
//伤害防御类
    set("weapon_prop/deep_injure", stext);
    set("weapon_prop/week_injure", ttext);
    set("weapon_prop/abs_week_injure", utext);
    set("weapon_prop/defense_attack", vtext);
    set("weapon_prop/armor_vs_force", wtext);
    set("weapon_prop/armor_effect_armor_vs_force", xtext);
    set("weapon_prop/attack_speed", ytext);
     set("weapon_prop/attack_factor", ztext);
     set("weapon_prop/parry_factor", btest);
     set("weapon_prop/dodge_factor", atest);
//气血恢复治疗类
    set("weapon_prop/max_qi", qitext);
    set("weapon_prop/max_jing", jingtext);
    set("weapon_prop/neili_recover", neilitext);
    set("weapon_prop/qi_recover", qitext);
    set("weapon_prop/jing_recover", jinglitext);
    set("weapon_prop/jingli_recover", jinglitext);
    set("weapon_prop/qi_cure", qitext);
    set("weapon_prop/jing_cure", jingtext);

    set("wtypeA",wtypeAtext);
    set("wtypeB",wtypeBtext);
    set("wtypeC",wtypeCtext);
    set("wtypeD",wtypeDtext);
    set("wtypeE",wtypeEtext);
    set("wtypeF",wtypeFtext);
    set("wtypeG",wtypeGtext);
    set("wtypeH",wtypeHtext);
    set("wtypeI",wtypeItext);
    set("wtypeJ",wtypeJtext);
    set("wtypeK",wtypeKtext);
    set("wtypeL",wtypeLtext);
    

                set("skill", ([
                        "name": "skillnametext",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": skilllevtext,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", sharpnesstext);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	set_amount(weaponamount);
	init_TYPEDM(weilitext);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";