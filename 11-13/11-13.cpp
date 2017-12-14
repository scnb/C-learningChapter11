// 11-13.cpp : 定义控制台应用程序的入口点。
//使用vector类来模拟随机漫步问题

#include "stdafx.h"
#include "vector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));//随机种子发生器
	double direction;
	Vector step;
	Vector result(0, 0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit):";//输入目标距离
	while (cin >> target)
	{
		cout << "Enter step length:";//输入步长
		if (!(cin >> dstep))
		{
			break;
		}
		while (result.magval() < target)
		{
			direction = rand() % 360;//360度一周，向各个方向走，其实是角度，在这种情况下用角度比较方便
			step.reset(dstep, direction, Vector::POL);//重新计算位移，更新对应的值
			result = result + step;//result是直角坐标类型的
			steps++;//记录一共走了多少步
		}
		cout << "After " << steps << " steps,the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();//更改为极坐标模式
		cout << "or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0,0);
		cout << "Enter target distance (q to quit):";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')//等待按回车结束
	{
		continue;
	}
    return 0;
}

