#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

int main()
{	
	string command = " ";
	bool running = true;
	Account account;

	do
	{
		cin.clear();
		cout << "--------------------------------------------------------------------\n" << "Enter command: ";
		cin >> command;
		cout << '\n';

		if(command == "quit")
			running = false;
		else
			account.completeCommand(command);

	} while (running == true);


	cout << "Thanks for using Billing 1.0.0!!!\n";
	system("pause");
	return 0;
}