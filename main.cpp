#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int Null_ID = -1;

class Account
{
public:
	int id;
	int balance;
	int pin;

	//float pay_in();
	//float pay_out();
};


class Database
{
public:
	Database() {}				//default constructor

	static int s_idGenerator;
	int m_id;
	Database() { m_id = s_idGenerator++; }
	
	Account look_up(int id)
	{
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i].id == id)
			{
				return accounts[i];
			}
			Account nullAcct;
			nullAcct.id = Null_ID;
			return nullAcct;		
		}
	}

	void addAccount(Account a)
	{
		accounts.push_back(a);
		// m_id 
	}
	
	int getID() const { return m_id; }

	int getNumAccounts()
	{
		return accounts.size();
	}
	
private:
	vector<Account> accounts;
};

Database d;

class Interaction
{
public:
	void registerAccount(int newPin)
	{
		Account newAccount;
		newAccount.id = d.getNumAccounts() + 1;
		newAccount.pin = newPin;
		newAccount.balance = 0;

		d.addAccount(newAccount);
	}

	bool authenticate(int id, int pin)
	{
		Account lookedUp = d.look_up(id);

		if (lookedUp.id == Null_ID)
		{
			return false;
		}
		
		if (lookedUp.pin == pin)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Account login(int id, int pin)
	{
		if (authenticate(id, pin))
		{
			return d.look_up(id);
		}
		else
		{
			Account nullAcct;
			nullAcct.id = Null_ID;
			return nullAcct;
		}
	}
};


int main()
{
	Account a1;
	a1.id = d.getID();
	Account a2;
	a2.id = d.getID();
	Account a3;
	a3.id = d.getID();

	Database d;
	d.addAccount(a1);
	d.addAccount(a2);
	d.addAccount(a3);

	int userChoice = { 0 };
	int userID;
	int userPIN;
	cout << "Welcome to the ATM. Please select a number choice below:" << endl;
	cout << "\t 1. Login" << endl;
	cout << "\t 2. Create New Account" << endl;
	cout << "\t 3. Exit" << endl;
	cin >> userChoice;

	switch (userChoice)
	{
	case '1':
		cout << "Please enter your id: ";
		cin >> userID;
		
		Account user = d.look_up(userID);
		if (user.id == Null_ID)
		{
			cout << "Not Found" << endl;
		}
		else
		{
			cout << "Found" << endl;
			cout << "Please enter your PIN: ";
			cin >> userPIN;
			if (user.pin == userPIN)
			{
				cout << "Thank you." << endl;
			}
			else
				cout << "PIN Incorrect" << endl;
		}
		break;
	case '2':
		cout << "Your new account number is: ";
		cout << d.getID()

	default:
		break;
	}

	
	
	






	return 0;
}
	