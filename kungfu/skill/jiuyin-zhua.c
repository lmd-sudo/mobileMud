// jiuyin-zhua.c -九阴白骨爪
// Modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([  "action" : "$N身形微晃，一招「相思深入骨」，十指如戟，插向$n的双肩锁骨",
    "force" : 200,
    "dodge" : 10,
    "damage_type" : "内伤",
    "lvl"   : 0,
    "skill_name" : "相思深入骨" ,
]),
([  "action" : "$N出手如风，十指微微抖动，一招「素手裂红裳」抓向$n的前胸",  
    "force" : 220,
    "dodge" : 20,
    "damage_type" : "内伤",
    "lvl"   : 10,
    "skill_name" : "素手裂红裳" ,
]),
([  "action" : "$N双手忽隐忽现，一招「铁指破残阳」，鬼魅般地抓向$n的肩头",  
    "force" : 250,
    "dodge" : 30,
    "damage_type" : "内伤",
    "lvl"   : 20,
    "skill_name" : "铁指破残阳" ,
]),
([  "action" : "$N左手当胸画弧，右手疾出，一招「明月当空照」，猛地抓向$n的额
头",
    "force" : 290,
    "dodge" : 25,
    "damage_type" : "内伤",
    "lvl"   : 31,
    "skill_name" : "明月当空照" ,
]),
([  "action" : "$N使一招「阴气动四方」，激起漫天的劲风，撞向$n",
    "force" : 340,
    "dodge" : 40,
    "damage_type" : "内伤",
    "lvl"   : 43,
    "skill_name" : "阴气动四方" ,
]),
([  "action" : "$N突然双手平举，$n一呆，正在猜测间，便见$N嗖的一下将双手    
收回胸前，接着一招「森然见白骨」，五指如钩，直抓向$n的腰间",
    "force" : 400,
    "dodge" : 35,
    "damage_type" : "内伤",
    "lvl"   : 56,
    "skill_name" : "森然见白骨" ,
]),
([  "action" : "$N使出「阴魂仍不散」，蓦然游身而上，绕着$n疾转数圈，$n正眼  
花缭乱间，$N已悄然停在$n身后，右手划出一道光圈，接着右手冲出光圈猛抓$n的后背",  
    "force" : 430,
    "parry" : 20,
    "dodge" : 20,
    "damage_type" : "内伤",
    "lvl"   : 71,
    "skill_name" : "阴魂仍不散" ,
]),
([  "action" : "$N面无表情，双臂忽左忽右地疾挥，使出「九阴搜魂手」，十指    
忽伸忽缩，迅猛无比地袭向$n全身各处大穴",
    "force" : 460,
    "parry" : 5,
    "dodge" : 30,
    "damage_type" : "内伤",
    "lvl"   : 87,
    "skill_name" : "九阴搜魂手" ,
]),
([  "action" : "$N左手轻挥，荡起阵阵阴风，一道青光闪过，$N的右手已变成青白  
色，接着集中精神施展出「爪现鬼神亡」祭出九道爪影击向$n的头顶",
    "force" : 520,
    "parry" : 10,
    "dodge" : 20,
    "damage_type" : "内伤",
    "lvl"   : 110,
    "skill_name" : "爪现鬼神亡" ,
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }  

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练九阴白骨爪必须空手。\n");
    if ((int)me->query_skill("force", 1) < 50)
   return notify_fail("你的内功心法火候不够，练九阴白骨爪会走火入魔
。\n");
    if ((int)me->query("max_neili") < 300)
   return notify_fail("你的内力太弱，无法练九阴白骨爪。\n");
    return 1;
}


string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
   if(level >= action[i-1]["lvl"])
   return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int)me->query_skill("jiuyin-zhua",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
   return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 8)
   return notify_fail("你的内力不够练九阴白骨爪。\n");
    if (me->query_skill("jiuyin-zhua", 1) < 60)
   me->receive_damage("qi", 15);
    else
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"jiuyin-zhua/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    if( random(me->query_skill("jiuyin-zhua",1)) > 50) {
    victim->apply_condition("jy_poison", random(2) + 1 +
   victim->query_condition("jy_poison"));
    }
}
