#include "stdafx.h"
#include "vector.h"
#include <cmath>

#include <iostream>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);
	//���ø���ֵ��˽�к�����Ҫ��������ģʽ�µ�ֵͬ������
	void Vector::set_mag()
	{
		mag = sqrt(x*x + y*y);
	}
	void Vector::set_ang()
	{
		if (x == 0 && y == 0)
		{
			ang = 0;
		}
		else
		{
			ang = atan2(y, x);
		}
	}
	void Vector::set_x()
	{
		x = mag*cos(ang);
	}
	void Vector::set_y()
	{
		y = mag*sin(ang);
	}
	//���к���
	Vector::Vector()
	{
		x = y = mag = ang = 0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (mode == RECT)
		{
			x = n1;
			y = n2;
			mag = sqrt(n1*n1 + n2*n2);
			ang = atan2(n2, n1);
		}
		else if (mode == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() - -";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0;
			mode = RECT;//��������Ĭ����ʽ
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (mode == RECT)//����Ĳ����Ƿ�������ʽ�ģ�ͬ��ת���ɼ�������ʽ
		{
			x = n1;
			y = n2;
			mag = sqrt(n1*n1 + n2*n2);
			ang = atan2(n2, n1);
		}
		else if (mode == POL)//����Ĳ����Ǽ�������ʽ�ģ�ͬ��ת���ɷ�������ʽ
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() - -";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0;
			mode = RECT;//��������Ĭ����ʽ
		}
	}
	Vector::~Vector()
	{

	}
	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}
	Vector Vector::operator+(const Vector & b)const
	{
		return Vector(x + b.x, y + b.y);//����ʾ���캯��������һ���µ�Vector�������丱����
	}
	Vector Vector::operator-(const Vector & b)const
	{
		return Vector(x - b.x, y - b.y);//����ʾ���캯��������һ���µ�Vector��
	}
	Vector Vector::operator-()const  //��������������Ǽ�������ȡ����
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n)const
	{
		return Vector(n*x, n*y);
	}
	//��Ԫ����
	Vector operator*(double n, const Vector & a)
	{
		return a*n;
	}
	std::ostream & operator<<(std::ostream & os, const Vector & v)
	{
		if (v.mode == Vector::RECT)
		{
			os << "(x,y) = (" << v.x << "," << v.y << ")\n";
		}
		if (v.mode == Vector::POL)
		{
			os << "(mag,ang) = (" << v.mag << "," << v.ang << ")\n";
		}
		else
		{
			os << "Vector object mode is invalid.\n";
		}
		return os;
	}
}