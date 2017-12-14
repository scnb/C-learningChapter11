#pragma once
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };//每英石有14磅
	int stone;
	double pds_left;//英石的小数部分，只不过是转换成磅的形式
	double pounds;//磅整个值
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;
};

#endif