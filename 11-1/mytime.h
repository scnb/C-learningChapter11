#pragma once
#ifndef MYTIME_H_
#define MYTIME_H_

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();//Ĭ�Ϲ��캯��
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time sum(const Time & t)const;
	void show()const;
};

#endif // !MYTIME_H_
