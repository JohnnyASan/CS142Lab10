#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"

using namespace std;

void GetLineNotWS(string& inpString)
{
	getline(cin, inpString);
	if (inpString.find_first_not_of(" \t") == std::string::npos)
	{
		getline(cin, inpString);
	}
}

int main()
{
	string goodType;
	string breadType;
	string frosting;
	string cakeType;
	string sprinklesColor;
	string insideComp;
	string outsideComp;

	double endPriceTotal = 0.00;

	int layers;
	int quantity;

	int invoiceCounter = 0;
	vector<int> foundLocations;

	vector<BakedGood*> userOrder;
	vector<BakedGood*> tempVector;

	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	do
	{
		cout << "Sub-order: " << endl;
		cin >> goodType;

		if (goodType == "Bread")
		{
			cin >> breadType;
			cin >> quantity;
			for (int i = 0; i < quantity; i++)
			{
				userOrder.push_back(new Bread(breadType));
			}
		}
		else if (goodType == "Cupcake")
		{
			cin >> cakeType;
			cin >> frosting;
			cin >> sprinklesColor;
			cin >> quantity;
			for (int i = 0; i < quantity; i++)
			{
				userOrder.push_back(new CupCake(cakeType, frosting, sprinklesColor));
			}
		}
		else if (goodType == "Layer-cake")
		{
			cin >> cakeType;
			cin >> frosting;
			cin >> layers;
			cin >> quantity;
			for (int i = 0; i < quantity; i++)
			{
				userOrder.push_back(new LayerCake(cakeType, frosting, layers));
			}
		}
	} while (goodType != "done");

	cout << "Order Confirmations: " << endl;
	for (unsigned int i = 0; i < userOrder.size(); i++)
	{
		cout << userOrder.at(i)->ToStr() << endl;
	}
	cout << endl;

	cout << "Invoice: " << endl;
	cout << setw(75) << left << "Baked Good" << setw(9) << right << "Quantity" << setw(9) << right << "Total" << endl;

	tempVector = userOrder;
	while (tempVector.size() != 0)
	{
		outsideComp = tempVector.at(0)->ToStr();
		for (unsigned int j = 0; j < tempVector.size(); j++)
		{
			insideComp = tempVector.at(j)->ToStr();
			if (outsideComp == insideComp)
			{
				invoiceCounter++;
				foundLocations.push_back(j);
			}
		}

		cout << fixed << setprecision(2) << setw(75) << left << tempVector.at(0)->ToStr();
		cout << setw(9) << right << invoiceCounter << setw(9) << right << tempVector.at(0)->CalcDiscount(invoiceCounter) << endl;
		endPriceTotal += tempVector.at(0)->CalcDiscount(invoiceCounter);

		while (invoiceCounter != 0)
		{
			tempVector.erase(tempVector.begin() + foundLocations.at(--invoiceCounter));
		}
		invoiceCounter = 0;
		foundLocations.clear();
	}
	cout << fixed << setprecision(2) << setw(75) << left << "Totals" << setw(9) << right << userOrder.size() << setw(9) << right << endPriceTotal << endl;
	cout << "Good Bye";
	//system("pause");

	for (unsigned int i = 0; i < userOrder.size(); i++)
	{
		delete userOrder.at(i); //clearing memory
	}
	userOrder.clear();

	return 0;
}
