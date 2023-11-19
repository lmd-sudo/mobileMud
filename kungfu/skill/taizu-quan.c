// taizu-quan 太祖长拳

inherit SKILL;
string  *msg = ({
"$N一招『双抄封天』，下半身右脚撇步上前，双手化掌，向前双抄上击$n的$l",
"$N身体向前冲出，一式『冲步双掌』，双手先抱回腰际後，再向前以双撑掌直推而出",
"$N全身原步右转，右手向右刁出，左手顺势护肩，『回首双刁』抓向$n的$l",
"$N提起左腿　升直右腿成独立步站定，『魁星踢斗』左腿顺势向前直蹬而出",
"$N一招『进步冲捶』，上右步至左脚旁，双手以双冲拳向$n直击而出",
"$N出一式『弓步冲打』，左脚向左跨出，身体尽量压低，拉回左手，右拳向前直击而出",
"$N一式『拍案齐掌』，全身微向下坐，产生後拉之势，收左手，右手化掌向前直压而出",
"$N保持原弓箭步站定不动，『燕子抄水』右掌原地翻掌，左手以反掌由右掌上方直穿而出",
"$N出『扭步断肘』，右步跟前，成玉环步蹲定，顺势收回左手，右手向前以平肘直扣而出",
"$N步法先右後左，连续上步，一式『双采冲捶』右拳向$n的$l直击而出",
"$N拉回右手，左手化拳向前直击而出，同时『左冲右踢』右腿向前平踢而出",
"$N右脚向前落步，成马步坐定，『马式挑打』在左手收回腰际，右拳向右直击而出",
"$N一式『英雄独立』，右拳原地翻掌，左掌化刁手斜刁身後，全式一气呵成，瞬间完成",
"$N一招『猛虎伏案』，右腿向前直铲而出，成伏虎步坐定，双手以反刁手刁定$n",
"$N一招『魁星独立』伸直右腿，将重心坐於左脚上，随著拔起之势，右掌向$n直挑而出",
"$N原势不动，一招『窜步偷心』快速窜前，提起右腿向前快踢，同时左掌向前平推而出",
"$N向前一招『双龙探爪』，双手变掌为爪，先右後左，连续向$n的$l击出",
"$N向前一窜，『猛虎出洞』将左刁手向後回勾，与右刁手同置身后再刁撇而出",
"$N身体保持後刁手姿势不变，『朝天一蹬』右腿伸直，向前以腿式直踢$n$l",
"$N来了个『虚步断肘』，轻点地面成虚步坐定，右拳顺势向前反冲而上",
"$N右手化掌，『采手冲捶』向前圈采而出，又顺势拉回右手，将左拳向$n击出",
"$N向前冲出三步，一式『三步行拳』双拳先右後左，连续向$n直击而出",
"$N一式『马式挑打』，右脚向前落步成马步坐定，左手收回腰际，右拳直击而出",
"$N一招『斜步插花』微向右转，成独立步站定，同时右手化掌向$n探抓",
"$N左手由右掌上方直穿而出，这招『左穿云手』直插$n的$l",
"$N右手由左掌上方直穿而出，一招『右穿云手』插向$n的$l",
"$N向左后方跳出，一式『跳步断肘』，右手化肘，向左面$n横扣而出",
"$N出『截步双崩』，右腿落步坐定，双拳挑起，藉著击胸之力向两侧崩击而出",
"$N成丁字步，『落步盘花』 左拳极力向上反穿而出，接著收回右掌，向下击落",
"$N出一招『翻身平掌』，全身向左转正，左手化刁手，右手以横切掌向$n直切而出",
"$N一招『走马活挟』，左右手同时以穿云手向$n穿出，连环三式",
"$N一式『回马横擂』，左腿向前踢出双飞腿，同时左手回勾，右手前穿拍向$n",
"$N双手右甩左手护肩，一式『回挑冲拳』右手曲肘上架，左拳向$n$l直击而出",
"$N保持原弓箭步站定不动，一招『顺步采手』，双手以小缠手向上圈采",
"$N撑直左腿步法下压，『窝肚冲捶』双手顺势以窝肚捶向$n$l直推而出",
"$N左手圈封而回护住右肩，一招『翻天劈地』右手以钻拳向$n穿打而出",
"$N身体向上挑起，出『马式挑捶』在右手收回腰际之时左拳向$n直击而出",
"$N右腿向前以小扫腿向前扫出，双手握拳『泰山压顶』直压向$n的$l",
"$N右掌由後向前反挑而上，然后出『翻江走海』双手向两侧以双抄掌压落",
"$N出『回步双切』，身体後仰，双手同时向前双抄而上，打向$n的$l",
"$N身体右倾，一招『反身插花』，左掌不动，右掌向右下方反切$n$l",
"$N一式『翻天双风』，双手以双抄掌向前反切而出，於面前硬碰，发出声音",
"$N右腿向前直踢而出，『翻手箭弹』接着双掌内翻，右手化掌，左手刁扣$n",
"$N左刁手不动，右掌收回胸前续劲，『顺势推山』以立掌向$n直推而出",
"$N收回双手，以十字手封住胸前，『拗步听风』接着双掌向$n平撑而出",
"$N一招『拐子腿法』，全身向上撑起，左腿顺势向左横踢$n的$l",
"$N伸直右腿，将重心坐於左脚上，『魁星独立』随著拔起之势，右掌向前直挑而出",
"$N一式『走回马枪』，双手右甩，左手护肩，右手极力下甩又直挑而上",
});

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="cuff" || usage=="parry";
}
int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练长拳必须空手。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage_type":random(2)?"内伤":"瘀伤",
                "dodge":-5+random(15),
                "force":100+random(350)
        ]);
}
int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练长拳必须空手。\n");
   if( (int)me->query("jing") < 30)
     return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
   if( (int)me->query("qi") < 30 )
     return notify_fail("你现在手足酸软，休息一下再练吧。\n");
   if( (int)me->query("neili") < 10 )
     return notify_fail("你的内力不够了。\n");

   me->receive_damage("qi", 20);
   me->add("neili", -5);

   return 1;
}