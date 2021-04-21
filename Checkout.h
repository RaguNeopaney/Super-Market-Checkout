#pragma once
#include <string>
#include <map>

using namespace std;

class Checkout
{
public:
	Checkout();
	//virtual ~Checkout();

	void addItemPrice(std::string item, int price);
	void addItem(std::string item);
	int calculateTotal();
	void addDiscount(string item, int nbrOfItems, int discountPrice);

protected:
	struct Discount
	{
		int nbrOfItems;
		int discountPrice;
	};
	map<string, int> prices;
	map<string, Discount> discounts;
	map<string, int> items;
	int total;

	void calculateItem(string item, int itemCnt);
	void calculateDiscount(string item, int itemCnt, Discount discount);
};

