#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account 
{
public:
	int ID;
	float beginningBalance{ 0.0f };

private:
	float currentBalance{ 0.0f };
};

Account addAccount(int& lastID);
//float getBalance(const Account& account);
int findAccount(int ID, const vector<Account>& accounts);



int main()
{
	int choice;
	vector<Account> accounts;
	int lastID{ 0 };
	int userID;

	cout << "Welcome to the ATM. Please select an option." << endl;
	cout << "1. Login to an existing account" << endl;
	cout << "2. Create new account" << endl;
	cout << "3. Exit the ATM" << endl;
	cout << "Enter selection: ";
	cin >> choice;

	while (choice != '3')
	{
		switch (choice)
		{
		case 1:
			cout << "Please enter your ID: ";
			cin >> userID;
			int findAccount(int ID, const vector<Account> & accounts);
			if (findAccount(userID, accounts) != -1) //infinite loop help?
			{
				//logged in menu maybe?
			}
			else
			{
				cout << "Sorry, that is not a valid ID" << endl;
			}
			break;
		case 2:
			addAccount(lastID);
			break;
		case 3:
			break;
		default:
			cout << endl << "Please choose a valid option." << endl;
		}
	}
	return 0;
}

Account addAccount(int& lastID)
{
	Account newAccount;
	lastID++;
	newAccount.ID = lastID;
	cout << "Your account ID is: " << lastID << endl;
	cout << "What is your beginning balance?" << endl;
	cin >> newAccount.beginningBalance;
	return newAccount;
}

int findAccount(int ID, const vector<Account>& accounts)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i].ID == ID)
		{
			return i;
		}
	}
	return -1;					// returns if account is not found.
}

