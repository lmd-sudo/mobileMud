// created by Vast@pkuxkx
// all comments added by Vast
// modified by Whuan@pkuxkx

//这个列表用于增加在其他场景出现的物品列表，请不断更新
//请留意物品的选择，不合适的物品请不要放置在这个列表中, 比如在一些解密过程中才能拿到的物品
//总之这一部分放置最最常见的东西
//物品列表请分类明确(按出现场景或者按不同的类别来区分, 不怕重复)，但是一定要容易整理
#define MF_RATE 100 //整体调整掉落率
#include <ansi.h>
inherit F_DBASE;
object setup_item(int success);
void item_drop(object npc,object user,object item);

void create()
{
	seteuid(getuid());
	set("name", "掉宝精灵");
	set("id", "gemdropd");	
}

string *misc_item_list = ({

	// /d/city/npc/obj/下出现的物品
	"/d/city/npc/obj/baozi",
	"/d/city/npc/obj/beixin",

	// /d/beijing/npc/obj/下出现的物品
	"/d/beijing/npc/obj/kaoya",
	"/d/beijing/npc/obj/yuchandan",
        "/d/beijing/npc/obj/goldleaf.c",
        "/d/beijing/npc/obj/junfu.c",
        "/d/beijing/npc/obj/magua.c",
        "/d/beijing/npc/obj/jinduan.c",
        "/d/beijing/npc/obj/tea.c",
        "/d/beijing/npc/obj/yaodai.c",

        // /d/shenlongdao/obj下出现的物品
        "/d/shenlongdao/obj/shepi.c",
        "/d/shenlongdao/obj/sherou.c",
        "/d/shenlongdao/obj/xionghuangjiu.c",
	// 普通兵器
        "/d/shaolin/obj/fumo-dao.c",
        "/d/dalicheng/obj/yxbj.c", 
        "/d/xingxiu/obj/bingpozhang.c", 
        "/d/xiangyang/npc/obj/item/27.c", //烈火鞭
        "/d/taohuadao/npc/obj/yuxiao.c", //玉箫
	// 食物
        "/clone/food/ganliang.c",
        "/d/wudang/npc/obj/turou",

        //衣服
        "/clone/cloth/cloth.c",
        "/clone/cloth/dao-cloth.c",
        "/clone/cloth/daogu-cloth.c",
        "/clone/cloth/dao-xie.c",
        "/clone/cloth/female-shoe.c",
        "/clone/cloth/female1-cloth.c",
        "/clone/cloth/female2-cloth.c",
        "/clone/cloth/female3-cloth.c",
        "/clone/cloth/female4-cloth.c",
        "/clone/cloth/female5-cloth.c",
        "/clone/cloth/female6-cloth.c",
        "/clone/cloth/female7-cloth.c",
        "/clone/cloth/female8-cloth.c",
        "/clone/cloth/ni-cloth.c",
        "/clone/cloth/ni-xie.c",
        "/clone/cloth/seng-cloth.c",
        "/clone/cloth/seng-xie.c",


        // 灵丹妙药
        "/d/xiangyang/npc/obj/shanlw.c",
        
        //金钱
        "/clone/money/gold",
        "/clone/money/gold",
        "/clone/money/gold",
        "/clone/money/thousand-cash",
	//大家看看怎样分类比较好？
	//一些相对较好的物品可以放到/d/ludingshan/special目录下，比如菩提子，熊胆丸等等
	});
	
varargs int drop(object npc,object user)	
{
/******************************************************
1.系统掉落不仅仅跟玩家自己有关，跟npc敌人也有关系
2.决定掉落率的有玩家的福缘，掉宝率和级别
3.决定npc级别的有npc的经验
*******************************************************/
	int npc_exp,npc_level;
	int ppl_level,ppl_kar,ppl_mf;
	int success;
	object item;
	
	npc_exp=npc->query("combat_exp");
  if(!user || !objectp(user)) user=npc;
  ppl_level=user->query("level");
  ppl_kar=user->query_kar();
  ppl_mf=user->query_temp("apply/magic"); //掉落率
//计算npc等级  
	if(npc_exp/1000<15)    		    npc_level=1; 
	else if(npc_exp/1000<30)		  npc_level=2; 
	else if (npc_exp/1000<60)		  npc_level=3; 
  else if (npc_exp/1000<120)	  npc_level=4; 
  else if (npc_exp/1000<240)		npc_level=5; 
  else if (npc_exp/1000<480)		npc_level=6; 
  else if (npc_exp/1000<780)		npc_level=7; 
  else if (npc_exp/1000<1140)		npc_level=8;	
  else if (npc_exp/1000<1560)		npc_level=9;	
  else if (npc_exp/1000<2040)		npc_level=10;
  else if (npc_exp/1000<2580)		npc_level=11;
  else if (npc_exp/1000<3000)		npc_level=12;
  else if (npc_exp/1000<3500)		npc_level=13;  	
  else if (npc_exp/1000<4000)		npc_level=14; 
  else if (npc_exp/1000<5000)		npc_level=15; 
  else if (npc_exp/1000<6000)		npc_level=16; 
  else if (npc_exp/1000<7000)		npc_level=17;   	
  else if (npc_exp/1000<8000)		npc_level=18;    	 
  else if (npc_exp/1000<9000)		npc_level=19;    	 	  	  	
  else                          npc_level=20;
//计算玩家成功率
  success=ppl_kar/3 +ppl_level/2 + ppl_mf+npc_level*2;
  success=success+random(success);
	success = success*MF_RATE/100; //可以用定义的值来调节drop率，spank..
	if (success > 200)
	MONITOR_D->report_system_msg (user->name()+"("+user->query("id")+")的掉宝成功率为"+ success +"\n"); 
	//随便给了一个计算方法，by whuan
	if (random(success)<10) 
		return 1;
//  item=setup_item(obj_min, obj_max);
  item=setup_item(success);
  item_drop(npc,user,item);  	
}
void item_drop(object npc,object user,object item)
{
	object env=environment(npc);
	string msg;
	if (!env) return ;
	if (item->query("level")>5)
		{ 
		if(random(item->query("level"))>=4 && item->query("sockets/max")<=1)
				item->add("sockets/max",1);
		if(!item->move(user))
			item->move(env);
      CHANNEL_D->do_channel(this_object(),"rumor","听说"+user->query("name")+"得到一"
             +item->query("unit")+item->name()+"啦。\n");	
		}
	else
		item->move(env);
  message_vision(GRN+"从$N身上掉了出来一"+item->query("unit")+item->name()+"\n"+NOR,npc);
  if (item->is_gems() && !item->is_gem())
  	msg = user->name()+"得到一"+item->query("unit")+item->name()
  	      +"[等级："+item->query("level")+"，孔数："+item->query("sockets/max")+"]。\n";
  if (item->is_gems() && item->is_gem())
  	msg = user->name()+"得到一"+item->query("unit")+item->name()
  	      +"[等级："+item->query("level")+"]。\n";
  if (item->is_gems())	      
    MONITOR_D->report_system_msg(msg); 
  return;		
}

object setup_item(int success)
{
/************************************************************************************************
1.drop_odds参数可以省略
  缺省情况下drop几率:80% misc, 6% weapon, 6% armor, 1.5% special, 2.5% ring, 4% gems, 0% unique(根据实际情况调整)
  //普通情况下不会出现unique物品，一般boss级别npc可以设置此参数调整drop几率
2.weapon,armor,ring的不同类别稀有度在各自的文件中定义了，如果不太好控制可以考虑采取和gems级别限制的相同方法
3.npc设置参数限制gems的最高级别,和非缺省情况下的drop几率
  set("item_drop_odds", ({500, 150, 150, 100, 50, 45, 5, }));
  总和1000。分别代表7种不同类物品的drop几率
  obj_min - obj_max
  0    - 5000  1级
	5000 - 8334  2级
	8335 - 9444  3级
	9445 - 9814  4级
	9815 - 9939  5级
	9940 - 9979  6级
	9980 - 9994  7级
	9995 - 10000 8级 
  具体请看/clone/gem/gem.c  set_level()函数
4.每位npc具体能够drop多少Item, 在各自的文件中自己定义，需要drop多个item的情况，多次调用本函数即可
4.misc包括普通场景中能够得到的各种物品，也包括部分特殊药品
************************************************************************************************/

	//其实n可以直接设定为7, 这个看以后是否增加新的物品类别而定，这样写只是为了减少以后的劳动量尽量避免出错
	//如果增加新的类别，下面的if ....else if还是需要手动修改
	int i, n, sum, *layer;
	int odds;
	object item;
	string *file;
	int *drop_odds;
	int obj_min,obj_max;
	int judge=0;

	if(success>40+random(3000))      {obj_min=8500;obj_max=9999;judge=7;} //6-8
	else if(success>35+random(2000)) {obj_min=7300;obj_max=9700;judge=6;} //5-7
	else if(success>30+random(1000)) {obj_min=6100;obj_max=9300;judge=5;} //4-6
	else if(success>25+random(500))  {obj_min=4500;obj_max=8500;judge=4;} //3-5
	else if(success>20+random(200))  {obj_min=2500;obj_max=8500;judge=3;}	//2-5
	else if(success>15+random(100))  {obj_min=0;   obj_max=8500;judge=2;}	//1-5									
  else                             {obj_min=0;   obj_max=6100;judge=1;} //1-4

  if(judge<=3)
	  drop_odds = ({800, 60, 60, 15, 25, 40, 0});
  else if(judge<=5)
    drop_odds = ({600, 120, 120, 30, 50, 80, 0});
  else
    drop_odds = ({400, 180, 180, 45, 75, 120, 0});
	n = sizeof(drop_odds);
	layer = allocate(n);
	if(n != 7) error("错误：drop参数数量设置错误。请通知巫师！\n");
	for(i= 0; i < n; i++)	sum = sum + drop_odds[i];
	if( sum != 1000) error("错误：drop率总和错误。请通知巫师！\n");

	layer[0] = drop_odds[0];
	for(i= 1; i < n; i++)
	layer[i] = layer[i - 1] + drop_odds[i];

	odds = random(1000);
	if (odds < layer[0])
	{
		//这部分还需要细分为 1.misc/目录下的物品;2.misc_item_list列表中的物品;3.特殊的药品
//		file = get_dir(LDC_OBJ("misc/"));
//		item = new(file[random(sizeof(file))]);
		item = new(misc_item_list[random(sizeof(misc_item_list))]);
		if(objectp(item))
		return item;
		else error("错误：物品(misc)生成错误，请报告巫师。\n");
	}
	else if (odds < layer[1])
	{
		item = new("/obj/gem/weapon");
		if(objectp(item))
	  {
	  	item->gen_weapon(item->query("type"),obj_min,obj_max);
		  return item;
	  }
		else error("错误：物品(weapon)生成错误，请报告巫师。\n");
	}
	else if (odds < layer[2])
	{
		item = new("/obj/gem/armor");
		if(objectp(item))
	  {
	  	item->gen_armor(item->query("type"),obj_min,obj_max);
		  return item;
	  }
		else error("错误：物品(armor)生成错误，请报告巫师。\n");
	}
	else if (odds < layer[3])
	{
		file = get_dir(LDC_OBJ("special/"));
		item = new(LDC_OBJ("special/" + file[random(sizeof(file))]));
		if(objectp(item))
		return item;
		else error("错误：物品(special)生成错误，请报告巫师。\n");
	}
	else if(odds < layer[4])
	{
		item = new("/obj/gem/ring");
		if(objectp(item))
	  {
	  	item->gen_armor(item->query("type"),obj_min,obj_max);
		  return item;
	  }
		else error("错误：物品(ring)生成错误，请报告巫师。\n");
	}
	else if(odds < layer[5])
	{
		item = new("/obj/gem/gem");
		if(objectp(item))
	  {
	  	item->set_level(obj_min,obj_max,item->query("material"));
		  return item;
	  }
		else error("错误：物品(gem)生成错误，请报告巫师。\n");
	}
	else
	{
		file = get_dir(LDC_OBJ("unique/"));
		item = new(LDC_OBJ("unique/" + file[random(sizeof(file))]));
		if(objectp(item))
		return item;
		else error("错误：物品(uniqie)生成错误，请报告巫师。\n");
	}
}



