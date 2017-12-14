// 11-10.cpp : 定义控制台应用程序的入口点。
//

// 11-7.cpp : 定义控制台应用程序的入口点。
//
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
	cout << planning;
	cout << endl;
	cout << "Coding time：";
	cout << coding;
	cout << endl;
	cout << "Fixing time：";
	cout << fixing;
	cout << endl;
	Time total;
	total = coding + fixing;
	cout << "Total time：";
	cout << total;
	cout << endl;
	Time diff;
	diff = fixing - coding;
	cout << "diff time：";
	cout << diff;
	cout << endl;
	Time mult;
	mult = 2 * coding;
	cout << "mult time：";
	cout << mult;
	cout << endl;
	getchar();
	return 0;
}


