#ifndef _CITY_H_
#define _CITY_H_

#include <iostream>
#include <string>

class city{
private:
	static int id;
	//��¼һ�������˶��ٸ�city��
	
	std::string m_name;
	int m_id;
	//��ǰcity����ض���id���� 
public:
	city(){};
	city(std::string name){
		m_name = name;
		m_id = ++id;
	}
	city(const city &c){ m_id = c.m_id; m_name = c.m_name; }
	~city(){ id--; }
	std::string getName(){ return m_name; }
	int getID() { return m_id; }
	static int getCount() { return id; }
	friend std::ostream & operator<< (std::ostream & os, city &c);
	//����cout<<�� �����е������������������������������ 
};
int city::id = 0;

#endif
