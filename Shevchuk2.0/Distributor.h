#pragma once
#include <map>
#include "Goods.h"
#include <iostream>

class Distributor
{
	std::map<Goods, int> stock;
public:
	Distributor(std::map<Goods, int> stock);
	bool sell(Goods g, int amount);
};

