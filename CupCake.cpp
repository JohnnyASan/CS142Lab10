#include "CupCake.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

CupCake::CupCake(string cakeFlavor, string frosting, string sprinkles, double price, double discount) : Cake(cakeFlavor, frosting, price, discount)
{
	this->colorOfSprinkles = sprinkles;
	if (this->flavorOfFrosting == "cream-cheese")
	{
		this->basePrice += ADDITIONAL_COST_FOR_CREAM_CHEESE_FROSTING;
	}
}

string CupCake::ToStr() const
{
	ostringstream theString;
	theString << this->flavorOfCake << " cupcake with " << this->flavorOfFrosting << " frosting and " << this->colorOfSprinkles << " sprinkles " << BakedGood::ToStr();
	return theString.str();
}

double CupCake::CalcDiscount(int numOfItems)
{
	if (numOfItems >= 4)
	{
		this->discount = 0.40 * numOfItems;
	}
	else if (numOfItems >= 2)
	{
		this->discount = 0.30 * numOfItems;
	}
	else
	{
		this->discount = 0.00;
	}
	return (this->basePrice * static_cast<double>(numOfItems)) - this->discount;
}

CupCake::~CupCake()
{
}
