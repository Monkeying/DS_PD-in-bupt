#ifndef _VEHICLE_H_
#define _VEHICLE_H_

//#include "stdafx.h"
#include "time.h"
#include "city.h"
#include <iostream>
class vehicle{
/*�����ڿ�������Ϊ��������洢���������֮��Ľ�ͨ��·��
��������ֱ�ӽ�;�����в�ֳɸ���С����·���󣬻��ǻᱣ����ʾȫ�ߵĶ��� 
���⣬��������ʱ��Ȩֵ��ʱ���Ǽ���һ����·����ʱ�䣬
������һ�����еĵ���ʱ��ȥ��ʣ����·���ܵ������һ������ ��Ȼ��ʹ�����ʱ�䣨���һ����·��getLastTime())���磿 
*/
private:
	static int id;
	//��¼�����˶��ٽ�ͨ��·��
	 
	int m_classify;
	//˵��Ϊ���ֽ�ͨ���ߣ��ɻ�����������
	 
	int m_id; 
	//��ǰ�����ͨ��·����ض���id���� 

	int m_cost;
	time m_time;
	time m_last;
	//����·�ĺ�ʱ
	 
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
	//����cout<<�� �����е������������������������������ 
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
