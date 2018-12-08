#include "BakedGood.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

BakedGood::BakedGood(double startPrice, double discountDeduction)
{
	this->basePrice = startPrice;
	this->discount = discountDeduction;
}

string BakedGood::ToStr() const
{
	ostringstream baseString;
	baseString << fixed << setprecision(2) << "($" << this->basePrice << ")";
	return baseString.str();
}

double BakedGood::CalcDiscount(int numOfItems)
{
	return this->discount;
}

BakedGood::~BakedGood()
{
}
