#pragma once
#include "BakedGood.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Cake : public BakedGood
{
public:
	Cake(string cakeFlavor = "vanilla", string frosting = "nothing", double price = 0.00, double discount = 0.00);
	virtual string ToStr() const = 0;
	virtual ~Cake();
protected:
	string flavorOfCake;
	string flavorOfFrosting;
};

