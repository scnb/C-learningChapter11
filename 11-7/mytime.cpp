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

Time Time::operator+(const Time & t)const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes = sum.minutes % 60;
	return sum;
}

Time Time::operator-(const Time & t)const
{
	Time diff;
	int tot1, tot2;
	tot1 = hours * 60 + minutes;
	tot2 = t.hours * 60 + t.minutes;
	diff.minutes = tot1 - tot2;
	diff.hours = diff.minutes / 60;
	diff.minutes = diff.minutes - diff.hours * 60;
	return diff;

}

Time Time::operator*(double mult)const
{
	Time result;
	long totalminutes = hours * 60 * mult + minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

Time operator*(double mult, const Time & t)
{
	Time result;
	long totalminutes = t.hours * 60 * mult + t.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
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