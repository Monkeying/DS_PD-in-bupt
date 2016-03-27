#ifndef _VEHICLE_H_
#define _VEHICLE_H_

//#include "stdafx.h"
#include "time.h"
#include "city.h"
#include <iostream>
class vehicle{
/*我现在看完是认为这个类里面储存的是两点之间的交通链路，
那我们是直接将途径城市拆分成各个小的链路对象，还是会保留表示全线的对象？ 
另外，我们在算时间权值的时候，是计算一条线路的总时间，
还是拿一个城市的到达时间去看剩下链路中能到达的下一个城市 ，然后使到达的时间（最后一个链路的getLastTime())最早？ 
*/
private:
	static int id;
	//记录生成了多少交通链路类
	 
	int m_classify;
	//说明为哪种交通工具，飞机，汽车，火车
	 
	int m_id; 
	//当前这个交通链路类的特定的id号码 

	int m_cost;
	time m_time;
	time m_last;
	//该链路的耗时
	 
	city m_start, m_dest;
public:
	vehicle();
	vehicle(int classify, int cost, time s, time last, city& start, city& dest);
	int getID(){ return m_id; }
	time getStartTime() { return m_time; }
	time getLastTime() { return m_last; }
	city getStartCity() { return m_start; }
	city getDestCity() { return m_dest; }
	int getCost(){ return m_cost; }
	static int getCount() { return id; }
	friend std::ostream & operator << (std::ostream & os, const vehicle & v);
	//重载cout<<， 命令行调试用来输出到调试器······ 
};
int vehicle::id = 0;
vehicle::vehicle(int classify, int cost, time s, time last, city& start, city& dest)
{
		m_classify = classify;
		m_cost = cost;
		m_time = s;
		m_last = last;
		m_start = start;
		m_dest = dest;
		id++;
		m_id = id;
}

#endif
