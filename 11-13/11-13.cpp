// 11-13.cpp : �������̨Ӧ�ó������ڵ㡣
//ʹ��vector����ģ�������������

#include "stdafx.h"
#include "vector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));//������ӷ�����
	double direction;
	Vector step;
	Vector result(0, 0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit):";//����Ŀ�����
	while (cin >> target)
	{
		cout << "Enter step length:";//���벽��
		if (!(cin >> dstep))
		{
			break;
		}
		while (result.magval() < target)
		{
			direction = rand() % 360;//360��һ�ܣ�����������ߣ���ʵ�ǽǶȣ�������������ýǶȱȽϷ���
			step.reset(dstep, direction, Vector::POL);//���¼���λ�ƣ����¶�Ӧ��ֵ
			result = result + step;//result��ֱ���������͵�
			steps++;//��¼һ�����˶��ٲ�
		}
		cout << "After " << steps << " steps,the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();//����Ϊ������ģʽ
		cout << "or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0,0);
		cout << "Enter target distance (q to quit):";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')//�ȴ����س�����
	{
		continue;
	}
    return 0;
}

