#include "Bread.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

Bread::Bread(string breadType, double price, double discount) : BakedGood(price, discount)
{
	this->typeOfBread = breadType;
}

double Bread::CalcDiscount(int numOfItems)
{
	int dealValue = 3;
	int numOfFree = 0;
	for (int i = 1; i <= numOfItems; i++)
	{
		if(i == dealValue)
		{
			numOfFree++;
			dealValue += 3;
		}
	}
	return (this->basePrice * static_cast<double>(numOfItems)) - (this->discount * numOfFree);
}

string Bread::ToStr() const
{
	ostringstream theString;
	theString << this->typeOfBread << " bread " << BakedGood::ToStr();
	return theString.str();
}

string Bread::GetType() const
{
	return this->typeOfBread;
}

Bread::~Bread()
{
}
