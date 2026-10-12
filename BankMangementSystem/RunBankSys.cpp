#include "RunBankSys.h"
#include"File&StringManager.h"
#include"Transactions.h"
#include<iostream>


using namespace std;

enum enMainMenuOption { enShowClientsList=1, enAddNewClient=2, enDeleteClient=3, enUpdateClientInfo=4, enFindClient=5,enTransaction=6, enExit=7};

void ShowMainMenu(){

	
	cout << "\n=========================================\n"
		<< "\tBank Main Menue\n"
		<< "=========================================\n"
		<< "[1] Show Clients List.\n"
		<< "[2] Add New Client.\n"
		<< "[3] Delete Client.\n"
		<< "[4] Update Client Info.\n"
		<< "[5] Find Client.\n"
		<< "[6] Transaction.\n"
		<< "[7] Exit.\n"
		<< "=========================================\n";
}

int GetChoiceFromUser() {

	int choice;
	cout << "Chose What Do You Want From ? ";
	cin >> choice;
	return choice;
}

void PerformOperation(enMainMenuOption enOption, vector<ClientsData> &vClients) {

	string AccountNumber;
	struct ClientsData sClient;
	
	switch (enOption)
	{
	case enShowClientsList:
		ShowClientList(vClients);
		break;
	case enAddNewClient:
		AddNewClient(vClients);
		SaveClientsDataToFile(vClients);
		cout << "Client Saved Successfuly....\n";
		break;
	case enDeleteClient:
		cout << "Please Enter Account Number :";
		cin >> AccountNumber;
		DeleteClientByAccountNumber(AccountNumber, vClients);
		break;
	case enUpdateClientInfo:
		cout << "Please Enter Account Number :";
		cin >> AccountNumber;
		UpdateClientByAccountNumber(AccountNumber, vClients);
		break;
	case enFindClient:
		cout << "Please Enter Account Number :";
		cin >> AccountNumber;
		if (FindClientByAccountNumber(AccountNumber, sClient, vClients))
		{
			PrintClientCard(sClient);
		}
		else
		{
			cout << "Client Not Found!";
		}
		break;
	case enTransaction:
		PerformTransactionOperation();
		vClients = LoadClientsDataFromFile(FileName);
		break;
	default:
		cout << "No Correct Choice :";
		break;
	}
}

void RunBankSystem() {


	vector<ClientsData> vClients = LoadClientsDataFromFile(FileName);
	enMainMenuOption enOption;
	bool EndProgram = false;

	do
	{

		ShowMainMenu();
		enOption = enMainMenuOption(GetChoiceFromUser());
		if (enOption == enExit)
		{
			cout << "\n\t\t\t\t\t################ Program Ends #################\n";
			EndProgram = true;
		}
		else
		{
			PerformOperation(enOption, vClients);
		}


	} while (!EndProgram);
}