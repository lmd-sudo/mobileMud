string getname()
{
	string *first_name = ({ "白", "廖", "成", "齐",
				"赵", "钱", "孙", "李",
				"周", "吴", "郑", "王",
				"冯", "陈", "褚", "卫",
				"蒋", "沈", "韩", "杨",
				"庄", "汪", "郭", "夏",
				"徐", "黄", "崔", "虞",
				"薛", "于", "谢", "池",
				"莫", "丁", "张", "刘",
				"林", "傅", "耿", "柯", });

	string *last_name = ({  "高", "克", "飞", "我", "和", "派",
				"顺", "昌", "振", "发", "功", "有",
				"彦", "足", "志", "忠", "雄", "益",
				"添", "凌", "辉", "盛", "胜", "进",
				"安", "剑", "同", "杨", "霄", "雪",
				"龙", "隆", "祥", "栋", "城", "亿", });
	string name;

	name = first_name[random(sizeof(first_name))];
	name += "中";
	name += last_name[random(sizeof(last_name))];

	return name;
}