#include "RunBankSys.h"
#include"File&StringManager.h"
#include<iostream>


using namespace std;


void ShowMainMenu(){

	
	cout << "\n=========================================\n"
		<< "\tBank Main Menue\n"
		<< "=========================================\n"
		<< "[1] Show Clients List.\n"
		<< "[2] Add New Client.\n"
		<< "[3] Delete Client.\n"
		<< "[4] Update Client Info.\n"
		<< "[5] Find Client.\n"
		<< "[6] Exit.\n"
		<< "=========================================\n";
}

int GetChoiceFromUser() {

	int choice;
	cout << "Chose What Do You Want From [1 to 6] ? ";
	cin >> choice;
	return choice;
}

void PerformOperation(int Choice, vector<ClientsData> &vClients) {

	string AccountNumber;
	struct ClientsData sClient;
	
	switch (Choice)
	{
	case 1:
		ShowClientList(vClients);
		break;
	case 2:
		AddNewClient(vClients);
		SaveClientsDataToFile(vClients);
		cout << "Client Saved Successfuly....\n";
		break;
	case 3:
		cout << "Please Enter Account Number :";
		cin >> AccountNumber;
		DeleteClientByAccountNumber(AccountNumber, vClients);
		break;
	case 4:
		cout << "Please Enter Account Number :";
		cin >> AccountNumber;
		UpdateClientByAccountNumber(AccountNumber, vClients);
		break;
	case 5:
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
		

	default:
		cout << "Please Enter A Correct Choice :";
		break;
	}
}

void RunBankSystem() {


	vector<ClientsData> vClients = LoadClientsDataFromFile(FileName);
	int Choice;
	bool EndProgram = false;

	do
	{

		ShowMainMenu();
		Choice = GetChoiceFromUser();
		if (Choice == 6)
		{
			cout << "\n\t\t\t\t\t################ Program Ends #################\n";
			EndProgram = true;
		}
		else
		{
			PerformOperation(Choice, vClients);
		}


	} while (!EndProgram);
}