#include "LayerCake.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

LayerCake::LayerCake(string cakeFlavor, string frosting, int layers, double price, double discount) : Cake(cakeFlavor, frosting, price, discount)
{
	this->numOfLayers = layers;
	CalcAdditionalLayersCost();
	CalcCreamCheeseCost();
}

void LayerCake::CalcAdditionalLayersCost()
{
	double additionalCost = 0.00;
	
	if (this->numOfLayers > 1)
	{
		additionalCost = ((this->numOfLayers - 1) * ADDITIONAL_COST_PER_LAYER_OVER_ONE);
	}
	this->basePrice += additionalCost;
}

void LayerCake::CalcCreamCheeseCost()
{
	double additionalCost = 0.00;
	if (this->flavorOfFrosting == "cream-cheese")
	{
		additionalCost = this->numOfLayers * ADDITIONAL_COST_PER_CREAM_CHEESE_PER_LAYER;
	}
	this->basePrice += additionalCost;
}

string LayerCake::ToStr() const
{
	ostringstream theString;
	theString << this->numOfLayers << "-layer " << this->flavorOfCake << " cake with " << this->flavorOfFrosting << " frosting " << BakedGood::ToStr();
	return theString.str();
}

double LayerCake::CalcDiscount(int numOfItems)
{
	if (numOfItems >= 3)
	{
		this->discount = 2.00 * numOfItems;
	}
	return (this->basePrice * static_cast<double>(numOfItems)) - this->discount;
}

LayerCake::~LayerCake()
{
}
