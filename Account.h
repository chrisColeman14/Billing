#include <iostream>
#include <string>
#include <fstream>
#include "Bill.h"

using namespace std;

#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
public:
	Account();
	void deposit();
	void setBalance();
	double getBalance();
	void billAccount();
	void displayOptions();
	void completeCommand(string command);
	void loadAccount();
	void Account::openAccount();
private:
	string nameOfAccount;
	string balanceInAccount;
	string ownerOfAccount;
	double balance;
	string file, accountName;
	fstream inFile;
};

#endif ACCOUNT _H