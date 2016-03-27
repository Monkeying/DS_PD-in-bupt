// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

//#include "targetver.h"//目前不需要 

#include <stdio.h>
#include <tchar.h>


// TODO:  在此处引用程序需要的其他头文件
//#include "time.cpp"//这个没有放进来 
#include "vehicle.h"
#include "city.h"
#include "map.h"
#include <iostream>
#include <fstream>//新加的库 

class city;
class time;
class vehicle;

const int inf = 0x7fffffff;//设为infinite无穷大 
vehicle * allVehicles[100001];//所有交通链路类的指针数组 
city * allCities[51];//所有城市类的指针数组 

#define _PLANE 1
#define _BUS 2
#define _TRAIN 3
