// 11-1.cpp : �������̨Ӧ�ó������ڵ㡣
//sum��Ա��������ԭ����ͳ�ķ���

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
	cout << "Planning time��";
	planning.show();
	cout << endl;
	cout << "Coding time��";
	coding.show();
	cout << endl;
	cout << "Fixing time��";
	fixing.show();
	cout << endl;
	Time total;
	total = coding.sum(fixing);
	cout << "Total time��";
	total.show();
	cout << endl;
	getchar();
    return 0;
}

