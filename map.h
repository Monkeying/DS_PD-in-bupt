#ifndef _MAP_H_
#define _MAP_H_

#include "city.h"
#include "vehicle.h"
#include "time.h"
#include "stdafx.h"

class map{
private:
	int cities;
	time now;
	int lines;
	//记录当前可行线路总数
	
	int world[51][51][51]; 
	//world[A][B][C], C中储存链接城市A到城市B的交通链路的id 
	//world[cityA][cityB][vehicleC]
	
	int tempMap[51][51][2];
	//tempMap[A][B][C],
	 
	int perfect[30];
	//顺序记录最佳路线方案的每条链路的id
	 
	int perfectLength;
	//最佳路线方案的换乘次数
	 
	bool succ;
	//路线规划是否成功
	 
public:
	map();
	void generate_Minimal_cost();
	void generate_Minimal_last();
	void dijkstra_cost(city&, city&);
	void show_perfect();
};
map::map()
{
	for (int i = 0; allVehicles[i] != NULL; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			if ( world [ allVehicles[i]->getStartCity().getID() ] [ allVehicles[i]->getDestCity().getID() ] [j] == 0 )
			{
					world [ allVehicles[i]->getStartCity().getID() ] [ allVehicles[i]->getDestCity().getID() ] [j] = allVehicles[i]->getID();
					break;
			}
		}
	} 
}

#endif
