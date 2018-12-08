#pragma once
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class BakedGood
{
public:
	BakedGood(double startPrice = 2.00, double discountDeduction = 0.00);
	virtual string ToStr() const = 0;
	virtual double CalcDiscount(int numOfItems);
	virtual ~BakedGood();
protected:
	double basePrice;
	double discount;
};

