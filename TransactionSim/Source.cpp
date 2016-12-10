/*************************************************************************************************************************************************************/
//Title: Assignment - 4
//Author : Matthew Bell
//
//Objective : The Objective is to createa bank simulation where a user can do and report transactions of 
//different types useing virual functions and polymorphism.
//
//Object Description 
//
//class Transaction: This class is going to be inherited by Withdraw, class Deposite, class Transfer. All of these classes are types of transactions
//	int UserID: So that the functions know which user it is performing the operations for.
//	int Amount: This is the amount of money entered by thge user that will be used in the transaction.
//	virtual void Report(): is empty in this class but will call on the report functions from other classes and print out the array of previouse transactions.
//
//class Withdraw, class Deposite, class Transfer: All of these classes are essentially identical.
//	void Report(): displays the user, type of transaction and amount when called upon.
//	
//class User: This class creates a user with containing the information about the bank account and their transaction history array.
//	int ID: This number represents any specific user.
//	int numTrans: The number of transactions that have been made by a specific user.
//	Transaction* t[100]:  This is a pointer to an array of the class transaction where members get added everytime the user makes a transaction.
//	void addWithdraw, addDeposit, addTransfer(): these funnctions perform the actuall tasks of Withdraw, Deposit and Transfer.
//	
/*************************************************************************************************************************************************************/


#include "iostream"
using namespace std;

class Transaction
{
public:
	int UserID;
	int Amount;
	Transaction()
	{
	}
	virtual void Report()
	{
	}
};

class Withdraw : public Transaction
{
public:
	Withdraw()
	{
	}
	void Report()
	{
		cout << "User " << UserID << " has withdrawn $" << Amount << "\n";
	}
};

class Deposit : public Transaction
{
public:
	Deposit()
	{
	}
	void Report()
	{
		cout << "User " << UserID << " has deposited $" << Amount << "\n";
	}
};

class Transfer : public Transaction
{
public:
	Transfer()
	{
	}
	void Report()
	{
		cout << "User " << UserID << " has Transfered $" << Amount << "\n";
	}
};

class User
{
public:
	int ID;
	int numTrans;
	Transaction* t[100];

	void addWithdraw()
	{
		t[numTrans] = new Withdraw();
		cout << "Enter the amount you want to withdraw \n";
		cin >> t[numTrans]->Amount;
		t[numTrans]->UserID = ID;
		numTrans++;
	}
	void addDeposit()
	{
		t[numTrans] = new Deposit();
		cout << "Enter the amount you want to Deposit. \n";
		cin >> t[numTrans]->Amount;
		t[numTrans]->UserID = ID;
		numTrans++;
	}
	void addTransfer()
	{
		t[numTrans] = new Transfer();
		cout << "Enter the amount you want to Transfer. \n";
		cin >> t[numTrans]->Amount;
		t[numTrans]->UserID = ID;
		numTrans++;
	}
};

void main()
{
	Withdraw wit;
	Deposit dep;
	Transfer tra;
	User* u[100];
	u[0] = new User();
	bool exit = false;
	int count = 0;

	while (true)
	{
		int tempID;		
		bool existing = false;
		int usedN;

		cout << "Please enter your user ID \n";
		cin >> tempID;

		for (int i = 0; i < count; i++)
		{
			if (u[i]->ID == tempID)
			{
				existing = true;
				usedN = i;
			}
		}

		if (existing == false)
		{
			u[count] = new User();
			u[count]->ID = tempID;
			usedN = count;
			count++;
		}

		while(true)
		{
			int option = 0;
			int subOption = 0;
			cout << "\nEnter the number corresponding to what you would like to do. \n";
			cout << "1 to do a transaction \n";
			cout << "2 to get a report of all your transactions \n";
			cout << "3 to switch users \n";
			cout << "4 to exit program\n";
			cout << "5 to view all user IDs\n";
			cin >> option;
			cout << "\n";

			if (option == 1)
			{
				cout << "1 to Do a Withdraw \n";
				cout << "2 to Do a Deposit \n";
				cout << "3 to Do a Transfer \n";
				cin >> subOption;
				cout << "\n";

				if (subOption == 1)
				{
					u[usedN]->addWithdraw();
				}

				if (subOption == 2)
				{
					u[usedN]->addDeposit();
				}

				if (subOption == 3)
				{
					u[usedN]->addTransfer();
				}
			}

			if (option == 2)
			{
				cout << "There are " << u[usedN]->numTrans << " Transactions.\n";
				for (int i = 0; i < u[usedN]->numTrans; i++)
				{
					u[usedN]->t[i]->Report();
				}
			}

			if (option == 3)
				break;
			if (option == 4)
			{
				exit = true;
				break;
			}

			if (option == 5)
			{
				cout << "List of all registered users. \n";
				for (int i = 0; i < count; i++)
				{
					cout << "User " << u[i]->ID << "\n";
				}
			}
		}	

		if (exit)
			break;
	}
}