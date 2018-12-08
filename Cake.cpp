#include "Cake.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

Cake::Cake(string cakeFlavor, string frosting, double price, double discount) : BakedGood(price, discount)
{
	this->flavorOfCake = cakeFlavor;
	this->flavorOfFrosting = frosting;
}

string Cake::ToStr() const
{
	return "nothing";
}

Cake::~Cake()
{
}
