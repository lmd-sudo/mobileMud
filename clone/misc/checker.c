// lily_flower.c
//    debug tools of fuyo@xajh2 99-5-28 9:51
//	    add finger fuyo@xajh2 99-12-7 15:14	
// modify by shure 

#include <ansi.h>
#include <armor.h>
#include <combat.h>

inherit HEAD;

#define NPC_INHERIT "/inherit/char/npc"
#define PLAYER_INHERIT "/clone/user/user"
#define ROOM_INHERIT "/inherit/room/room"

mapping valid_types = ([
	"axe":          "斧法",     //add by fuyo@xajh 98-6-16 19:50
	"unarmed":	"拳脚",
	"sword":	"剑法",
	"blade":	"刀法",
	"stick":	"棒法",
	"staff":	"杖法",
	"club" :        "棍法",
	"throwing":	"暗器",
	"force":	"内功",
	"parry":	"招架",
	"dodge":	"轻功",
	"magic":	"法术",
	"array":        "阵法",
	"whip":    	"鞭法",
	"finger":  	"指法",
	"hand":    	"手法",
	"cuff":   	"拳法",
	"claw":   	"爪法",
	"strike": 	"掌法",
]);

int checkroom(object);
int checkobj(object);
object check_user(string id);

void create()
{
        set_name(YEL"资料查询器"NOR, ({"checker", "qi"}));
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG"巫师工具（勿与玩家）：\n\n"NOR
                            "findnpc： 输入name查找npc\n"
                            "findobj： 输入name查找object\n"
                            "findroom：输入name查找environment\n"
                            "friend：  查询好友列表\n"
                            "          添加好友列表 friend add <id>\n"
                            "lfinger： 输入id查询玩家详细资料\n");
                set("unit", "个");
                set("material", "gold");
                set("armor_prop/armor", 1);
        }
        setup();

}

void init()
{
	if (wiz_level(this_player()) > 1)
	{
		add_action("do_findn", "findnpc");   // find npc
        	add_action("do_findr", "findroom");   // find room      
        	add_action("do_findo", "findobj");   // find object
        	add_action("add_friend","friend");   // add friend list
        	add_action("do_finger","lfinger");   // finger user long info 
        }
}

void dest()
{
        destruct(this_object());
        
}

        
int do_findn(string arg)
{
        object *chn,env;
        int i,j,count=0,num=0;
        string enstr;

        mapping mm;
        mapping mtemp;
        
        mm =  ([]);
        
        if (!arg)
                return notify_fail("你必须输入想查找的人物名!\n");              
        
        chn = livings();
        
        if(sscanf(arg,"%d",num)==1 && num>0)   //find numbers>num的NPC数目
        {
                
                if (num<10)
                        return notify_fail("你查找的人物数目必须>=10!\n");              
                      
                chn = objects("checkroom");
        
                for(i=0;i<sizeof(chn);i++)
                {
                        object* inv;
                        int number=0;
                        inv = all_inventory(chn[i]);
                        for(int k=0;k<sizeof(inv);k++)
                        {       
                                if (living(inv[k]))
                                        number++;
                        }
        
                        if (number>=num)
                                printf("%d -- 场景 ：%s(%s)   %d位生物\n",++count,chn[i]->query("short"),base_name(chn[i]),number);        
                }                           
                
                printf(HIW"\n共找到数目超过%d生物的场景%d个!!\n\n"NOR,num,count);                
                return 1;

        }        

        for(i=0;i<sizeof(chn);i++)
        {
                if(clonep(chn[i]) && (member_array(arg,chn[i]->parse_command_id_list())!=-1 || 
                                strsrch(chn[i]->query("name"),arg)!=-1))
                {
                
                        count++;
//                      printf("%d -- 文件 ：%s(%s)\n",count,chn[i]->query("name"),base_name(chn[i]));
                        if ( objectp(env=environment(chn[i])) )
                                enstr = sprintf("%s(%s)\n",env->query("short"),base_name(env));
                        else    
                                enstr = sprintf("不详！\n");            
                                                        
                        for(j=0;j<sizeof(mm);j++)
                        {                       
                                mtemp = mm [j] ;
                                if (mapp(mtemp)) 
                                {
                                        if (mtemp["file_name"] == base_name(chn[i]) && mtemp["env"] == enstr )
                                        {
                                                mtemp["count"]++;
                                                break;
                                        }       
                                }
                        }
                        
                        if (j>=sizeof(mm))
                        {
                                mtemp = ([]);
                                mtemp["file_name"] = base_name(chn[i]);                         
                                mtemp["name"] = chn[i]->query("name")+"("+
                                		chn[i]->query("id")+")";
                                mtemp["count"]=1;
                                mtemp["env"] = enstr ;
                                mm[j] = mtemp;
                        }                               
                }                       
        
        }               
        
        if (count==0)
                return notify_fail("没有该人物!\n");                    
                
        printf(HIW"\n共找到%s %d次:\n\n"NOR,arg,count);

        for ( i = 0 ; i <sizeof(mm);i++)
        {
                mtemp = mm[i];
                printf("%3d -- 人物 ：%s  自  %s  %d位 \n",i+1,mtemp["name"],mtemp["file_name"],mtemp["count"]);
                printf("    -- 场景 ：%s\n",mtemp["env"]);
        }               
        return 1;
}                       
        
int do_findr(string arg)
{
        object *chn;
        int i,count=0;
        string tmp;
                
        if (!arg)
                return notify_fail("你必须输入想查找的场景名!\n");              
        chn = objects("checkroom");
        
        for(i=0;i<sizeof(chn);i++)
        {
                tmp = chn[i]->query("short");
                if(stringp(tmp) && strsrch(tmp,arg)!=-1)
                {
                        
                        printf("%d -- 场景 ：%s(%s)\n",++count,chn[i]->query("short"),base_name(chn[i]));
                }
        }                               
                                                                                                
        if (count==0)
                write("没有该场景!\n");                 
        return 1;
}               
        
        

int checkroom(object ob)
{
        if (!objectp(ob)) return 0;
        
        return inherits( ROOM_INHERIT, ob);
}       

int do_findo(string arg)
{
        object *chn,env;
        int i,j,count=0;
        string enstr;

        mapping mm;
        mapping mtemp;
        
        mm =  ([]);
                
        if (!arg)
                return notify_fail("你必须输入想查找的物品名!\n");              
        chn = objects("checkobj");
        
        for(i=0;i<sizeof(chn);i++)
        {
        	reset_eval_cost(); // add by shure
//        	printf("%O\n",chn[i]);
                if(clonep(chn[i]) && (member_array(arg,chn[i]->parse_command_id_list())!=-1 || 
                                strsrch(chn[i]->query("name"),arg)!=-1))
                {
                
                        count++;
//                      printf("%d -- 文件 ：%s(%s)\n",count,chn[i]->query("name"),base_name(chn[i]));
                        if ( objectp(env=environment(chn[i])) )
                        {
                        	if (userp(env))  //在玩家身上
                        		enstr = sprintf("%s(%s)\n",env->query("name"),env->query("id"));
				else if (living(env)) //在NPC上                       
                        		enstr = sprintf("%s(%s) - %s\n",env->query("name"),env->query("id"),base_name(env));
				else                        		
                        		enstr = sprintf("%s(%s)\n",env->query("short"),base_name(env));
			}                        	       
                        else    
                                enstr = sprintf("不详！\n");            
                                                        
                        for(j=0;j<sizeof(mm);j++)
                        {                       
                                mtemp = mm [j] ;
                                if (mapp(mtemp)) 
                                {
                                        if (mtemp["file_name"] == base_name(chn[i]) && mtemp["env"] == enstr )
                                        {
                                                mtemp["count"]++;
                                                break;
                                        }       
                                }
                        }
                        
                        if (j>=sizeof(mm))
                        {
                                mtemp = ([]);
                                mtemp["file_name"] = base_name(chn[i]);                         
                                mtemp["name"] = chn[i]->query("name");
                                mtemp["count"]=1;
                                mtemp["env"] = enstr ;
                                mm[j] = mtemp;
                        }                               
                }                       
        
        }               
        
        if (count==0)
                return notify_fail("没有该物品!\n");                    
                
        printf(HIW"\n共找到%s %d 次:\n\n"NOR,arg,count);

        for ( i = 0 ; i <sizeof(mm);i++)
        {
                mtemp = mm[i];
                printf("%3d -- 物品 ：%s(%s)  %d 个 \n",i+1,mtemp["name"],mtemp["file_name"],mtemp["count"]);
                printf("    -- 场景 ：%s\n",mtemp["env"]);
        }               
        return 1;
}               

int checkobj(object ob)
{
        if (!objectp(ob)) return 0;
        if (!clonep(ob)) return 0;
        if (living(ob)) return 0;
        if (userp(ob)) return 0;
        if (query_heart_beat(ob)) return 0;
	if (!ob->query("id")) return 0;
        if (!environment(ob)) return 0;
                
        return 1;
}       

object check_user(string id)
{
	object ob, *body;
	
	if( objectp(ob = find_player(id)) )
		return ob;

	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i])
		&&  getuid(body[i]) == id ) return body[i];

	return 0;
}
int add_friend(string arg)
{
        mapping friends;
        string* ttt;
        object ob;
        string online;
        if(!arg)
        {
                friends= this_player()->query("friends");
                if(!mapp(friends))
                        return notify_fail("你没有设定好友名单!\n");                              
                ttt= friends["list"];
                printf("你目前好友有：\n");
                
                for(int i=0;i<sizeof(ttt);i++)
                {
                        ob=find_player(ttt[i]);
                        if(objectp(ob)&& userp(ob)) online =HIM"在线" ;
                        else online = CYN"未在线";
                        printf("%d.  %10s   状态：%s\n"NOR,i+1,ttt[i],online);
                }
                                  
                return 1;
        }                        
                                
        if( sscanf(arg,"add %s",arg)== 1)
        {
                friends= this_player()->query("friends");
                if (FINGER_D->finger_user(arg)=="没有这个玩家。\n")
                        return notify_fail("没有这个玩家。\n");                              

                if (!mapp(friends)) 
                {
                        friends = ([]);           
                        ttt=({arg});
                }
                else 
                { 
                        ttt= friends["list"];
                         ttt +=({arg});
                }
                friends["list"]=ttt;
                this_player()->set("friends",friends);
                printf("您已成功将%s加入您的好友名单!\n",arg);
                return 1;
         }

        if( sscanf(arg,"del %s",arg)== 1)
        {
                friends= this_player()->query("friends");
                if(!mapp(friends))
                        return notify_fail("你没有设定好友名单!\n");                              
                ttt= friends["list"];
                
                if (member_array(arg,ttt) == -1)
                        return notify_fail("你好友名单上没有"+arg+"!\n");                              
                ttt -=({arg});
                friends["list"]=ttt;
                this_player()->set("friends",friends);
                printf("您已成功将%s从您的好友名单上删除!\n",arg);
                return 1;
         }                
        return 0;
                
}

string query_autoload() 
{
        mapping friends;
        string *ttt;
        object ob,env;
        int count=0;

	env = environment(this_object());
	if (!objectp(env)) return "嘿嘿嘿";
	if (!living(env)) return "嘿嘿嘿嘿";
	
        friends= env->query("friends");
        if(mapp(friends))
        { 
                ttt= friends["list"];
                tell_object(env,"目前在线好友有：\n");
                
                for(int i=0;i<sizeof(ttt);i++)
                {
                        ob=find_player(ttt[i]);
                        if(objectp(ob)&& userp(ob))
                   	          tell_object(env,sprintf("%d.  "HIW"%-10s  \n"NOR,++count,ttt[i]));
                }
         }       
         return "嘿嘿"; 
}

int do_finger(string arg)
{
	object ob,po;
	mapping my,map;
	object weapon;
	string skill_type;
	int online=0;
	object g_ob,t_ob;
	int g_no,t_no,i,modify;
	int attack_points, dodge_points, parry_points;
	string* skill,*aload;
	int count=0;
		
	if (!arg) return 0;

	seteuid(ROOT_UID);

	ob=find_player(arg);
	if(objectp(ob)&& userp(ob))
	{
		online=1;
		po=ob->query_temp("link_ob");
		if (objectp(g_ob = present("gold_money",ob)))
			g_no = g_ob->query_amount();
		else	g_no =0;	
       	if (objectp(t_ob = present("thousand-cash_money", ob)))
			t_no = t_ob->query_amount();
		else	t_no =0;	
	}
	else
	{
		po = new(LOGIN_OB);
		po->set("id", arg);
		if( !po->restore() )
			return notify_fail("没有这个玩家!\n");

		ob = LOGIN_D->make_body(po);
		if( !ob->restore() ) return notify_fail("没有这个玩家。\n");
		aload = ob->query_autoload();
		if (sizeof(aload) < 1) {
			g_no=0;t_no=0;
		}
		else{
		 for(i=0; i<sizeof(aload); i++) {
			write(aload[i]+"  ");
		       sscanf(aload[i], "/clone/money/thousand-cash:%d", t_no);
		       sscanf(aload[i], "/clone/money/gold:%d", g_no);
		     }
		write("\n");
		}
				
		
	}
	
	my = ob->query_entire_dbase();

	printf("\n%s(%s)的信息如下：\n",ob->query("name"),ob->query("id"));

	if( mapp(my["family"]) )
		printf("%s%s弟子\n",my["family"]["family_name"],my["family"]["master_name"]);

	

	printf("存款(%d) 金(%d) 银票(%d)\n",
		ob->query("balance")/10000,g_no,t_no);

	printf("年龄(%d) 精(%d) 气(%d) 神(%d) 内力(%d) 天赋(%d,%d,%d,%d)\n",
		ob->query("age"),ob->query("max_jing"),ob->query("max_qi"),
		ob->query("shen"),ob->query("max_neili"),
		ob->query_str(), ob->query_int(),ob->query_con(),ob->query_dex());


	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

	printf("实战经验(%d) 攻击力(%d-%d) 防守力(%d-%d)\n",		
		ob->query("combat_exp"),
		attack_points/100 + 1, ob->query_temp("apply/damage"),
		(dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));

	map = ob->query_skill_map();
	if( !mapp(map) || sizeof(map)==0 )
		printf("现没有使用任何特殊技能\n");
	else
	{
		skill = keys(valid_types);
		printf("以下是目前使用中的特殊技能");
		for (i=0; i<sizeof(skill); i++) 
		{
			if( undefinedp(valid_types[skill[i]]) ) {
				continue;
			}
			if( !ob->query_skill(skill[i]) ) continue;
			if (count++%3 == 0 ) printf("\n");
			modify = ob->query_temp("apply/" + skill[i]);
			printf("\t%-2s-%-10s(%s%3d)" NOR, 
				valid_types[skill[i]],
				undefinedp(map[skill[i]]) ? "无" : to_chinese(map[skill[i]]),
				(modify==0 ? "" : (modify>0 ? HIC : HIR)),
				ob->query_skill(skill[i]));
		}
//	if(count%3!=0)
		printf("\n");
	}
	printf("%s",online?"在线":"不在线");
	printf("\t上次连线 %s %s\n",po->query("last_from"),ctime(po->query("last_on")));
	printf("%s",ob->query("married")?"已婚":"未婚");
	printf("\n");
	if (online!=1)
	{
		destruct(ob);
		destruct(po);
	}
	
	return 1;

}	