#pragma once
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };//定义两种表示矢量的方式，分别是反三角和极坐标形式
	private:
		double x;
		double y;
		double mag;//矢量的长度
		double ang;//矢量的角度
		Mode mode;
		//私有函数，用来设置各个模式下的值
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		~Vector();
		void Vector::reset(double n1, double n2, Mode form = RECT);
		double xval() const { return x; }//返回x的值
		double yval() const { return y; }//返回y的值
		double magval() const { return mag; }//返回矢量长度
		double angval() const { return ang; }//返回矢量角度
		void polar_mode();//设定模式为极坐标模式,即长度和角度
		void rect_mode();//设定模式为反三角模式，即横坐标和纵坐标
		//运算符重载
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-()const;//取负数
		Vector operator*(double n)const;//用常数n乘以矢量
		//友元函数
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream & operator<<(std::ostream & os, const Vector & v);
	};
}
#endif // !VECTOR_H_
