#pragma once
#include "Cake.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class LayerCake : public Cake
{
public:
	LayerCake(string cakeFlavor = "vanilla", string frosting = "nothing", int layers = 1, double price = 9.00, double discount = 0.00);
	void CalcAdditionalLayersCost();
	void CalcCreamCheeseCost();
	virtual string ToStr() const;
	virtual double CalcDiscount(int numOfItems);
	~LayerCake();
private:
	int numOfLayers;
	const double ADDITIONAL_COST_PER_CREAM_CHEESE_PER_LAYER = 1.00;
	const double ADDITIONAL_COST_PER_LAYER_OVER_ONE = 3.00;
};

