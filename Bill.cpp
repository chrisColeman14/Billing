#include "Bill.h"
#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

	Bill::Bill()
	{
		nameOfBusiness = " ";
		reasonOfBill = " ";
		date = " ";
		amountPaid = 0.0;
	}

	double Bill::getAmountPaid()
	{
		return amountPaid;
	}
	string Bill::getDate()
	{
		return date;
	}
	string Bill::getReasonOfBill()
	{
		return reasonOfBill;
	}
	string Bill::getName()
	{
		return nameOfBusiness;
	}
	
	void Bill::setNameOfBusiness(string name)
	{
		nameOfBusiness = name;
	}
	void Bill::setReasonOfBill(string reason)
	{
		reasonOfBill = reason;
	}
	void Bill::setDate(string date)
	{
		this->date = date;
	}