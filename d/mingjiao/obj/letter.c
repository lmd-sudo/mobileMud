// paper.c
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("遗书", ({"letter", "paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long","一封火漆的书信，封皮上写着 '夫人亲启' 四字，好象还没"+ZJURL("cmds:chai letter")+HIG"拆(chai)开。\n");
		set("material", "paper");
        }
}

void init()
{
        add_action("do_chai", "chai");
}

int do_chai(string arg)
{

        if ( arg=="letter" || arg=="遗书" )
	{
		tell_object(this_player(),@LONG
你轻轻拆开封皮，抽出一副极薄的白绫来，只见绫上写道：

夫人妆次：
    夫人自归阳门，日夕郁郁。余粗鄙寡德，无足为欢，甚可歉疚，兹当永别，
唯夫人谅之。
    本教虽发源于波斯，然在中华生根，开枝散叶，已数百年于兹，今鞑子占
我中土，本教誓与周旋到底，决不可遵波斯总教无理命令，而奉蒙古人为主。
    余神功第四层初成，即悉成昆之事，血气翻涌不能自制，真力将散，行将
大归，天也命也，复何如耶？
    今余命在旦夕，盼夫人持余亲笔遗书，颁余遗命：令谢逊暂摄副教主之位，
处分本教重务，乾坤大挪移心法暂由其接掌，日后转奉新教主，光大我教，驱
逐胡虏，行善去恶，持正除奸，令我明尊圣火普惠天下世人，新教主其勉之。
    余将以身上残余功力，掩石门而和成昆共处，夫人可依密道全图脱困。当
世无第二人有乾坤大挪移之功，即无第二人能推动此 '无妄' 位石门，待后世
豪杰练成，余及成昆骸骨朽矣。
    焚我残躯，熊熊圣火，生亦何欢，死亦何苦？为善除恶，惟光明故，喜怒
悲苦，皆归尘土。怜我世人，忧患甚多！怜我世人，忧患甚多！

                                                         顶天谨白
LONG
		);
	}
	else
	{
	        return notify_fail("什么？\n");
	}

	return 1;

}
