#include <ansi.h>
int give_gift();
mixed *story =
({
   HIW"ｌｏｎｇ　ｌｏｎｇ　ａｇｏ....."NOR,
   "祝融：共工，你和我连战三天，累战累败，前面就是不周之山，",
   "你已无走投无路，快快投降，尚能让你苟且一命。",
   "共工：呸，我共工氏败将只有死没有降。来来来，你我再斗三百回合！",
   "......................",
   HIR"远处的天际突然响起了一阵震人心魄的可怕巨响，听声音正是来自天庭的方向。"NOR,
   "天空的颜色渐渐变得纷乱起来。",
   "祝融：共工，你好狠毒！败则败，死则死，为何要撞倒不周之山，祸害天下苍生。",
   "共工：哈哈哈哈....天柱已断，天火将泻，四极废，九州绝，",
   "饶你祝融火中之神，一样万劫不复。哈.....",
   "......................",
   "女娲：祝融！你速往蓬莱仙岛，取驮岛神龟来，我来补天！",
   ".....................",
   "祝融：娘娘，神龟在此。",
   "女娲断龟四足，取龟甲，：祝融！你我以万年的修为炼补天之石，拯救天下苍生。",
   "祝融化为一团冲天火焰投入龟甲之中",
   "在熊熊的火光之中，女娲慢慢地将的五色彩石一把一把地丢进火中，",
   "彩石越来越亮，火光渐渐转弱。",
   "女娲缓缓地环视四周，彷佛露出悲悯的神情，仰望不周之山，",
   "突然举起一片尖锐的巨石，往胸口重重划下去。",
   "女娲的胸口随着巨石的划过便出现一道长长的伤口，",
   "从伤口之中，像是汨汨流下鲜红的血液，全洒在龟甲中五色彩石之上",
   "而随着那奇异汁液溅在五色石上，有几小滴反弹掉在地上，",
   "立刻长出茂盛的各类花草，有的还落地化成蹦蹦跳跳的活物。",
   "龟甲中的火光立刻像是复活一般，“轰”的一声重又燃起，直直冲入云霄。",
   "在火光中，女娲将双臂深深地探入火堆之中，捧了满怀的灼亮五色石出来。",
   "女娲巨大的蛇身慢慢蜿蜒而行，曲曲绕绕地爬上不周之山，",
   "到了山顶之后，再将手上的五色石补在残破的天空之上。",
   ".......................",
   "在不周之山前，那盆龟甲和五色石烧成的火明了又暗，暗了又明",
   "大神女娲的胸腹之间，早已布满了无数的伤痕，随着生命汁液的流出，",
   "她的形貌也越发干枯，连行动都开始举步维艰。",
   "而这时候，不周之山上的破碎天空也已经快要补好。",
   "女娲的脸上彷佛露出了满足的微笑，在火光中，她的唇际映出满漾笑意的阴影",
   "也许是想再一次抱着五色石入怀吧？但是，她的气力却在此刻用尽，",
   "整个身子失去支撑，便往那龟甲盆中直趴了下去。",
   "“轰”的一声龟甲盆被打翻，烧炙的五色石满天飞舞。",
   "...................................",
   HIM"补天神石落凡间。"NOR,
    (: give_gift :),
});
string prompt() { return HIG "【天界传说】" NOR; }
void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/obj/gem/gem", 1,
        HIM "“啪”的一声一颗宝石掉在你面前。\n\n" NOR);
        return 1;               
}       

