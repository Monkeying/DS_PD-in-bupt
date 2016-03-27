#include"stdafx.h"
void allCitiesGenerating()
{
	std::ifstream file;
	file.open("城市表.txt");
	if (file == NULL)
		printf("城市表打开失败，请查证后再重启。\n");
	else
	{
		while(0 == file.eof())
		{
			std::string name;		
			getline(file, name, ' ');
			if (allCities[1] == NULL)
				allCities[1] = new city(name);
			else
			{
				allCities[allCities[1]->getCount()] = new city(name);				
			}						
		}
 	}
 	file.close();
}
void allVehiclesGenerating()
{
	std::ifstream file;
	file.open("交通链路表.txt");
	if (file == NULL)
		printf("交通链路表打开失败，请查证后再重启。\n");
	else
	{
		while(0 == file.eof())
		{		
			std::string start, dest;
			file>>start>>dest;
			std::cout<<start<<std::endl<<dest<<std::endl;
			int classify, cost;
			int hour, min;
			file>>classify>>cost>>hour>>min;
			
			time s(hour, min);
			file>>hour>>min;
			time last(hour, min);
			int destID = 0, startID = 0;
		//	printf("here\n");
			for(int i = 1; allCities[i] != NULL && i < 51; i++)
			{
		//		printf("searching\n");
				if (allCities[i]->getName() == start)
					startID = i;
				if (allCities[i]->getName() == dest)
					destID = i; 
			}
			if (startID != 0 && destID != 0)
			{
				if (allVehicles[1] == NULL)
					allVehicles[1] = new vehicle(classify, cost, s, last, *allCities[startID], *allCities[destID]);
				else
				{
					allVehicles[allVehicles[1]->getCount()] = new vehicle(classify, cost, s, last, *allCities[startID], *allCities[destID]);
				}			
			}		
		}
 	} 
 	file.close();	
} 

int main()
{
	allCitiesGenerating();
	allVehiclesGenerating();
	std::cout<<allVehicles[1]->getID()<<" "<<allVehicles[1]->getCount()<<" "<<allVehicles[1]->getCost()<<" "<<allVehicles[1]->getStartCity().getName()<<allVehicles[1]->getDestCity().getName();
	std::cout<<allVehicles[2]->getID()<<" "<<allVehicles[2]->getCount()<<" "<<allVehicles[2]->getCost()<<" "<<allVehicles[2]->getStartCity().getName()<<allVehicles[2]->getDestCity().getName();
	map m;

}
