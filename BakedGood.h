#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BakedGood
{
public:
  BakedGood(double basePrice = 0.00);
  string ToStr();
private:
  double basePrice;
}
