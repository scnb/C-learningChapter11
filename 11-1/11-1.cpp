// 11-1.cpp : 定义控制台应用程序的入口点。
//sum成员函数还是原来传统的方法

#include "stdafx.h"
#include "mytime.h"
#include <iostream>

int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	cout << "Planning time：";
	planning.show();
	cout << endl;
	cout << "Coding time：";
	coding.show();
	cout << endl;
	cout << "Fixing time：";
	fixing.show();
	cout << endl;
	Time total;
	total = coding.sum(fixing);
	cout << "Total time：";
	total.show();
	cout << endl;
	getchar();
    return 0;
}

