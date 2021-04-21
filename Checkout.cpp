#include "pch.h"
#include "Checkout.h"

Checkout::Checkout():total(0) {

}
void Checkout::addItemPrice(std::string item, int price)
{
	prices[item] = price;
}

void Checkout::addItem(std::string item) {
	map<string, int>::iterator priceItr = prices.find(item);
	if (priceItr == prices.end())
	{
		throw invalid_argument("Invalid item. No Price");
	}
}

int Checkout::calculateTotal() {
	total = 0;

	for (map<string, int>::iterator itemIter = items.begin(); itemIter != items.end(); itemIter++)
	{
		string item = itemIter->first;
		int itemCnt = itemIter->second;
		calculateItem(item, itemCnt);
	}
	return total;
}

void Checkout::addDiscount(string item, int nbrOfItems, int discountPrice) {
	Discount discount;
	discount.nbrOfItems = nbrOfItems;
	discount.discountPrice = discountPrice;
	discounts[item] = discount;
}

void Checkout::calculateItem(string item, int itemCnt) {
	map<string, Discount>::iterator discountIter;
	discountIter = discounts.find(item);
	if (discountIter != discounts.end())
	{
		Discount discount = discountIter->second;
		calculateDiscount(item, itemCnt, discount);
	}
	else
	{
		total += itemCnt * prices[item];
	}
}

void Checkout::calculateDiscount(string item, int itemCnt, Discount discount) {
	if (itemCnt >= discount.nbrOfItems)
	{
		int nbrOfDiscount = itemCnt / discount.nbrOfItems;
		total += nbrOfDiscount * discount.discountPrice;
		int remainingItems = itemCnt % discount.nbrOfItems;
		total += remainingItems * prices[item];
	}
	else
	{
		total += itemCnt * prices[item];
	}
}