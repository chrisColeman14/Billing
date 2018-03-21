#include "Account.h"
#include <fstream>
#include <sstream>

using namespace std;

Account::Account()
{
	balance = 0;
	loadAccount();
	
	balanceInAccount[0] = '0';
	istringstream (balanceInAccount) >> balance;
	
	displayOptions();
}

void Account::setBalance()
{
	double newBalance = 0.0;
	char overrideBalance = 'n';

	cout << "There is already a balance of $" << getBalance() << " in this account!\n";
	cout << "What would you like to set the balance of this account to?: ";
	cin >> newBalance;

	if(balance == balance)
	{
		cout << "You already have a balance in this account.\n"
			<< "Do you want to change the balance to $" << newBalance << " <y/n>: ";
		cin >> overrideBalance;
		if(overrideBalance == 'y' || overrideBalance == 'Y')
		{
			balance = newBalance;
			string line;
			int numberOfNumSigns = 0;
			string pound = "#";
			fstream file;
			file.open("Accounts.txt");
			
			while(file >> pound)
			{
				if(pound.size() != 52)
				{
					for(int i = 0; i < pound.size(); i++)
					{
						if(pound[i] == '<' && numberOfNumSigns == 0)
						{
							;
						}
						else if(pound[i] != '#' && numberOfNumSigns == 0)
						{
							;
						}
						else if(pound[i] != '#' && numberOfNumSigns == 2)
						{
							for(int j = 1; j < balanceInAccount.size(); j++)
							{
								file << balanceInAccount[j] + '0';
							}
							i = pound.size();
						}
						else
							numberOfNumSigns++;
					}
				}
			}
			
			cout << "\nThe account now has a balance of $"<< getBalance() << ".\n";
		}
	}
}


double Account::getBalance()
{
	return balance;
}

void Account::displayOptions()
{
	cout << "Welcome to Billing software 1.0.0\n\n"
		<< "Clear the screen enter (c).\n"
		<< "Check the balance of the account enter (balance).\n"
		<< "Change the balance of the account enter (change).\n"
		<< "Charge a bill to the account enter (bill).\n"
		<< "Check the 10 previous bills enter (check billing).\n"
		<< "Deposit money into the account by entering (deposit).\n"
		<< "Quit the Billing program then enter (quit).\n";
}

void Account::deposit()
{
	char choice = ' ';
	double deposit = 0.0;
	cout << "How much would you like to deposit?: $";
	cin >> deposit;
	cout << "Are you sure you would like to deposit $" << deposit << "? <y/n>: ";
	cin >> choice;
	if(choice == 'y')
	{
		balance += deposit;
		cout << "The new account balance is: $" << getBalance() << '\n';
	}
	else
		cout << "You chose not to deposit any money.\n";
}

void Account::billAccount()
{
	Bill bill;
	double amountToBill;
	string name, reason, date;

	cout << "\nWho is the bill being paid to?: ";
	cin.ignore();
	getline(cin, name);
	bill.setNameOfBusiness(name);
	
	cout << "\nWhy is this bill being paid?: ";
	//cin.ignore('\n');
	getline(cin, reason);
	bill.setReasonOfBill(reason);
	
	cout << "\nWhat is the date this bill is being paid? XX/XX/XX: ";
	//cin.ignore();
	getline(cin, date);
	bill.setDate(date);
	
	cout << "How much is the bill from " << bill.getName() << "?: $";
	cin >> amountToBill;
	balance -= amountToBill;
	
	
	cout << "\nThe account balance is now $" << balance << ".\n";
	cout << "Name: " << bill.getName() << "\nReason: " << bill.getReasonOfBill() << "\nDate: " << bill.getDate() << '\n';
}

void Account::completeCommand(string command)
{
	if(command == "balance")
		cout << "The account balance is: $" << getBalance() << '\n';
	else if(command == "change")
		setBalance();
	else if(command == "bill")
		billAccount();
	else if(command == "check billing")
		;
	else if (command == "deposit")
		deposit();
	else if(command == "c")
	{
		system("CLS");
		displayOptions();
	}
	else
		cout << "You have not entered a valid command!!\n";
}

void Account::openAccount()
{
	
	string filename = "Accounts.txt";
	inFile.open(filename);
	while (!inFile.is_open())
	{
		cin.clear();
		try{
			inFile.open(filename);

			if(inFile.fail())
				throw runtime_error("Cannot open the file.");
		} catch (runtime_error& e)
			{
					cout << "Error: Could not open the file " << endl << endl;	
			}

			cout << "File could not open, retry with new file: ";
			cin.clear();
			filename = "";
			getline(cin, filename);
			inFile.open(filename);
		}

}

void Account::loadAccount()
{
	string filename = "Accounts.txt";
	ifstream inFile;
	inFile.open(filename);
	while (!inFile.is_open())
	{
		cin.clear();
		try{
			inFile.open(filename);

			if(inFile.fail())
				throw runtime_error("Cannot open the file.");
		} catch (runtime_error& e)
			{
					cout << "Error: Could not open the file " << endl << endl;	
			}

			cout << "File could not open, retry with new file: ";
			cin.clear();
			filename = "";
			getline(cin, filename);
			inFile.open(filename);
		}
	
	
	string line;
	int numberOfNumSigns = 0;
	while(getline(inFile,line)) //reading from inFile object
	{
		for(int i = 0; i < line.size(); i++)
		{
			if(line[i] == '<' && numberOfNumSigns == 0)
			{
				i += line.size();
			}
			else if(line[i] != '#' && numberOfNumSigns == 0)
			{
				nameOfAccount += line[i];
				//numberOfNumSigns++;
			}
			else if(line[i] != '#' && numberOfNumSigns == 1)
			{
				balanceInAccount += line[i];
				//numberOfNumSigns++;
			}
			else if(line[i] != '#' && numberOfNumSigns == 2)
			{
				ownerOfAccount += line[i];
				//numberOfNumSigns++;
			}
			else
			{
				numberOfNumSigns++;
			}
		}
	}

	inFile.close();
}