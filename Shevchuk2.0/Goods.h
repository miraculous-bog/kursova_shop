#pragma once
#include <string>

enum GOODS_TYPE {
	APPLE, ORANGE, BANANA, WATEMELON
};

class Goods
{
private:
	GOODS_TYPE type;
	int volume;
	double price;
	Goods();
public:
	Goods(GOODS_TYPE type, int volume, double price);
	GOODS_TYPE getType();
	int getVolume();
	double getPrice();
	std::string toStr();

	friend bool operator<(Goods const& a, Goods const& b);
	friend bool operator>(Goods const& a, Goods const& b);
};

