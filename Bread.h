#pragma once
#include "BakedGood.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;
class Bread : public BakedGood
{
public:
	Bread(string breadType = "bagel", double price = 4.50, double discount = 4.50);
	virtual string ToStr() const;
	virtual double CalcDiscount(int numOfItems);
	string GetType() const;
	~Bread();
private:
	string typeOfBread;
};

