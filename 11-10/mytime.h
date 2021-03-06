#pragma once
#ifndef MYTIME_H_
#define MYTIME_H_
#include <iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();//默认构造函数
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time & t)const;
	Time operator-(const Time & t)const;
	Time operator*(double mult)const;
	friend Time operator*(double mult, const Time & t)
	{
		return t*mult;//其实又调用了上面那个重载运算符*
	}
	friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif // !MYTIME_H_
#pragma once
#pragma once

