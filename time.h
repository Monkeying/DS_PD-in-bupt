#ifndef _TIME_H_
#define _TIME_H_
/*

*/ 
class time{
private:
	int m_hour;
	int m_min;
public:
	time(){ m_hour = 0; m_min = 0; }
	time(int hour, int min){ m_hour = hour; m_min = min; }
	void show(char *);
	void set(int hour , int min){ m_hour = hour, m_min = min; }
	int getMins(){ return 60 * m_hour + m_min; }
	time(const time &t){ m_hour = t.m_hour; m_min = t.m_min; }
	
	bool operator <(time &t);
	bool operator >(time &t);
	//重载 <号，>号。用来比较time类的时间大小 
};


#endif
