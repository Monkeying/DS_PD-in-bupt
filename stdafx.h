// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

//#include "targetver.h"//Ŀǰ����Ҫ 

#include <stdio.h>
#include <tchar.h>


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
//#include "time.cpp"//���û�зŽ��� 
#include "vehicle.h"
#include "city.h"
#include "map.h"
#include <iostream>
#include <fstream>//�¼ӵĿ� 

class city;
class time;
class vehicle;

const int inf = 0x7fffffff;//��Ϊinfinite����� 
vehicle * allVehicles[100001];//���н�ͨ��·���ָ������ 
city * allCities[51];//���г������ָ������ 

#define _PLANE 1
#define _BUS 2
#define _TRAIN 3
