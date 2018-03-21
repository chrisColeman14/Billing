#include <iostream>
#include <string>


using namespace std;
#pragma once
#ifndef BILL_H
#define BILL_H
#include "Account.h"

class Bill
{
public:
	Bill();
	double getAmountPaid();
	string getDate();
	string getReasonOfBill();
	string getName();
	//void payBill(Account acc);
	void setNameOfBusiness(string name);
	void setReasonOfBill(string reason);
	void setDate(string date);
private:
	string nameOfBusiness;
	string reasonOfBill;
	string date;
	double amountPaid;
};

#endif