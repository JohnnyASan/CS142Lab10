#pragma once
#include "Cake.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class CupCake : public Cake
{
public:
	CupCake(string cakeFlavor = "vanilla", string frosting = "nothing", string sprinkles = "none", double price = 1.95, double discount = 0.00);
	virtual string ToStr() const;
	virtual double CalcDiscount(int numOfItems);
	~CupCake();
private:
	string colorOfSprinkles;
	const double ADDITIONAL_COST_FOR_CREAM_CHEESE_FROSTING = 0.20;
};

