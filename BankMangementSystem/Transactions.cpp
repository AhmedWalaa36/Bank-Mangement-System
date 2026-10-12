#include"Transactions.h"
#include"Clients.h"
#include "File&StringManager.h"
#include"RunBankSys.h"
#include<iostream>
using namespace std;

enum enTransaction{enDeposite = 1,enWithdraw=2,enShowTotalBalance=3,enBackToMainMenu=4};

void Deposite(vector <ClientsData>& vClients) {
	string AccountNumber;
	float DepositAmount;
	ClientsData sClient;
	bool IsFound = false;

	do
	{
		cout << "Please Enter Account Number: ";
		cin >> AccountNumber;

		IsFound = FindClientByAccountNumber(AccountNumber, sClient, vClients);

		if (!IsFound)
		{
			cout << "Invalid Account Number! Please Try Again.\n";
		}

	} while (!IsFound);

	cout << "Please Enter Amount \n";
	cin >> DepositAmount;
	for (ClientsData& client : vClients)
	{
		if (AccountNumber == client.AccountNumber)
		{
			cout << "Transaction Completed";
			client.Balance += DepositAmount;
			break;
		}
	}
	SaveClientsDataToFile(vClients);
}

void Withdraw(vector <ClientsData>& vClients) {

	string AccountNumber;
	float DepositAmount;
	ClientsData sClient;
	bool IsFound = false;

	do
	{
		cout << "Please Enter Account Number: ";
		cin >> AccountNumber;

		IsFound = FindClientByAccountNumber(AccountNumber, sClient, vClients);

		if (!IsFound)
		{
			cout << "Invalid Account Number! Please Try Again.\n";
		}

	} while (!IsFound);

	cout << "Please Enter Amount \n";
	cin >> DepositAmount;
	for (ClientsData& client : vClients)
	{
		if (AccountNumber == client.AccountNumber)
		{
			if (client.Balance< DepositAmount)
			{
				cout << "No Suficcient Balance!";
			}
			else 
			{
				cout << "Transaction Completed";
				client.Balance -= DepositAmount;
				break;
			}
			
		}
	}
	SaveClientsDataToFile(vClients);
}

void ShowClientBalance(vector <ClientsData>& vClients) {

	string AccountNumber;
	float DepositAmount;
	ClientsData sClient;
	bool IsFound = false;

	do
	{
		cout << "Please Enter Account Number: ";
		cin >> AccountNumber;

		IsFound = FindClientByAccountNumber(AccountNumber, sClient, vClients);

		if (!IsFound)
		{
			cout << "Invalid Account Number! Please Try Again.\n";
		}

	} while (!IsFound);

	cout << "The Client Balance is : " << sClient.Balance;
}

void ShowTransactionMenue() {

	cout << "\n=========================================\n"
		<< "\tTransaction Menue\n"
		<< "=========================================\n"
		<< "[1] Deposite.\n"
		<< "[2] Withdraw.\n"
		<< "[3] Show Balance.\n"
		<< "[4] Return To Main Menue.\n"
		<< "=========================================\n";
}

void PerformTransactionOperation() {

	vector<ClientsData> vClients = LoadClientsDataFromFile(FileName);

	do
	{
	
		ShowTransactionMenue();
		enTransaction enTransactionOption = enTransaction(GetChoiceFromUser());
		switch (enTransactionOption)
		{
		case enDeposite:
			Deposite(vClients);
			break;
		case enWithdraw:
			Withdraw(vClients);
			break;
		case enShowTotalBalance:
			ShowClientBalance(vClients);
			break;
		case enBackToMainMenu:
			return;
		default:
			cout << "Please Enter A Correct Choice :";
			break;
		}
	} while (true);

}



