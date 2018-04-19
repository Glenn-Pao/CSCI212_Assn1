#include "Sales.h"

using namespace std;

Sales::Sales()
{
	SetDescription("");
	SetUnitPrice(0);
	SetQtyPurchased(0);
	SetDatePurchased("1Jan00");
}
Sales::Sales(string description, int unitPrice, int quantityPurchased, string dataPurchased)
{
	SetDescription(description);
	SetUnitPrice(unitPrice);
	SetQtyPurchased(quantityPurchased);
	SetDatePurchased(dataPurchased);
}
Sales::~Sales()
{
}

void Sales::SetDescription(string description)
{
	this->description = description;
}
string Sales::GetDescription()
{
	return description;
}

void Sales::SetUnitPrice(int unitPrice)
{
	this->unitPrice = unitPrice;
}
int Sales::GetUnitPrice()
{
	return unitPrice;
}	

void Sales::SetQtyPurchased(int quantityPurchased)
{
	this->quantityPurchased = quantityPurchased;
}
int Sales::GetQtyPurchased()
{
	return quantityPurchased;
}

void Sales::SetDatePurchased(string datePurchased)
{
	this->datePurchased = datePurchased;
}
string Sales::GetDatePurchased()
{
	return datePurchased;
}

string Sales::ToString()
{
	string temp, itemDes, price, qty, date;
	
	//string stream the non-string variables
	stringstream priceToS, qtyToS;
	
	//into their own respective variables, then convert them into string form
	priceToS << unitPrice;
	qtyToS << quantityPurchased;
	
	//define the various strings and prepare them for displaying of data
	itemDes = description + ":";
	price   = priceToS.str() + ":";
	qty     = qtyToS.str() + ":";
	date    = datePurchased + '\n';

	//chain the data together into a string that can be read by the console
	temp =  itemDes + price + qty + date;

	return temp;
}
