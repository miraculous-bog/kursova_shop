#include "Distributor.h"

Distributor::Distributor(std::map<Goods, int> stock)
{
	this->stock = stock;
}

bool Distributor::sell(Goods g, int amount)
{
	auto it = stock.find(g);
	if (it != stock.end()) {
		int second = it->second;
		if (second < amount) {
			std::cout << "This distributor doesn't have enought goods" << std::endl;
			return false;
		}
		else {
			stock[g] -= amount;
			return true;
		}
	}
	else {
		std::cout << "This distributor doesn't sell these goods" << std::endl;
		return false;
	}
}
