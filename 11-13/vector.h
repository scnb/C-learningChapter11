#pragma once
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };//�������ֱ�ʾʸ���ķ�ʽ���ֱ��Ƿ����Ǻͼ�������ʽ
	private:
		double x;
		double y;
		double mag;//ʸ���ĳ���
		double ang;//ʸ���ĽǶ�
		Mode mode;
		//˽�к������������ø���ģʽ�µ�ֵ
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		~Vector();
		void Vector::reset(double n1, double n2, Mode form = RECT);
		double xval() const { return x; }//����x��ֵ
		double yval() const { return y; }//����y��ֵ
		double magval() const { return mag; }//����ʸ������
		double angval() const { return ang; }//����ʸ���Ƕ�
		void polar_mode();//�趨ģʽΪ������ģʽ,�����ȺͽǶ�
		void rect_mode();//�趨ģʽΪ������ģʽ�����������������
		//���������
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-()const;//ȡ����
		Vector operator*(double n)const;//�ó���n����ʸ��
		//��Ԫ����
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream & operator<<(std::ostream & os, const Vector & v);
	};
}
#endif // !VECTOR_H_
