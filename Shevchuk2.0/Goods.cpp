#include "Goods.h"

Goods::Goods(GOODS_TYPE type, int volume, double price)
{
	this->type = type;
	this->volume = volume;
	this->price = price;
}

GOODS_TYPE Goods::getType()
{
	return this->type;
}

int Goods::getVolume()
{
	return this->volume;
}

double Goods::getPrice()
{
	return this->price;
}

std::string Goods::toStr()
{
	std::string s = "\n==========\nType: ";
	switch (type)
	{
	case APPLE:
		s += "Apple;\n";
		break;
	case ORANGE:
		s += "Orange;\n";
		break;
	case BANANA:
		s += "Banana;\n";
		break;
	case WATEMELON:
		s += "Watermelon;\n";
		break;
	default:
		s += "Unknown;\n";
		break;
	}

	s += "Price: " + std::to_string(price)+"\n";
	s += "Volume: " + std::to_string(volume) + "\n";
	return s;
}

bool operator<(Goods const& a, Goods const& b) {
	return a.type < b.type;
}

bool operator>(Goods const& a, Goods const& b) {
	return a.type > b.type;
}