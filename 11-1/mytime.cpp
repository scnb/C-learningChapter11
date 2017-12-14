#include "stdafx.h"
#include "mytime.h"
#include <iostream>

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

Time Time::sum(const Time & t)const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes = sum.minutes % 60;
	return sum;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::show()const
{
	std::cout << "Hours = " << hours << " , minutes = " << minutes << std::endl;
}