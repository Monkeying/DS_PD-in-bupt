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
	//��¼��ǰ������·����
	
	int world[51][51][51]; 
	//world[A][B][C], C�д������ӳ���A������B�Ľ�ͨ��·��id 
	//world[cityA][cityB][vehicleC]
	
	int tempMap[51][51][2];
	//tempMap[A][B][C],
	 
	int perfect[30];
	//˳���¼���·�߷�����ÿ����·��id
	 
	int perfectLength;
	//���·�߷����Ļ��˴���
	 
	bool succ;
	//·�߹滮�Ƿ�ɹ�
	 
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
