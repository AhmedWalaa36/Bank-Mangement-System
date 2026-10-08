#include "Clients.h"
#include <iostream> 
#include <iomanip>
#include "File&StringManager.h"
using namespace std;

ClientsData sClient;


bool IsExistAccountNumber(string AccountNumber, vector <ClientsData> &vClients){

	for (ClientsData &client: vClients)
	{
		if (client.AccountNumber== AccountNumber)
		{
			cout << "Account Number " << AccountNumber << " Is Already Exist.";
			return true;
		}
	}
	return false;
}

void AddNewClient(vector<ClientsData> &vClients) {

	cout << "Please Enter Client Information. \n\n";
	char AddNewClient = 'n';

	do
	{
		cout << "Enter Client Account Number : ";
		cin >> sClient.AccountNumber;
		while (IsExistAccountNumber(sClient.AccountNumber, vClients))
		{
			cout << "Enter another Account Number: ";
			cin >> sClient.AccountNumber;
		}
		cout << "Enter Client Pin Code : ";
		cin >> sClient.PinCode;

		cout << "Enter Client Name : ";
		cin.ignore();
		getline(cin, sClient.Name);

		cout << "Enter Client Phone Number : ";
		cin >> sClient.PhoneNumber;

		cout << "Enter Client Balance : ";
		cin >> sClient.Balance;

		cout << endl;

		vClients.push_back(sClient);

		cout << "Do You Want To Add Another Client (Y|N) ? ";
		cin >> AddNewClient;

	} while (AddNewClient=='y'|| AddNewClient=='Y');
}

void PrintClientData(ClientsData client) {

	cout << left
		<< "| " << setw(30) << client.AccountNumber
		<< "| " << setw(15) << client.PinCode
		<< "| " << setw(30) << client.Name
		<< "| " << setw(15) << client.PhoneNumber
		<< "| " << setw(10) << client.Balance
		<< "|"
		<< endl;
}

void ShowClientList(vector<ClientsData> vClients) {

	cout << "\t\t\t\t\tClient List " << "(" << vClients.size() << ")" << " Clients" << endl
		 <<"------------------------------------------------------------------------------------------------------------------------\n"
		 << left
		 << "| " << setw(30) << "Account Number"
		 << "| " << setw(15) << "Pin Code"
		 << "| " << setw(30) << "Client Name"
		 << "| " << setw(15) << "Phone"
		 << "| " << setw(10) << "Balance"
		 << "|"
		 << endl
		 << "------------------------------------------------------------------------------------------------------------------------\n";
		
	for (ClientsData &client : vClients)
	{
		PrintClientData(client);
	}
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
}

void PrintClientCard(ClientsData client) {
	
	cout << "Account Number  : " << client.AccountNumber << endl;
	cout << "Pin Code        : " << client.PinCode << endl;
	cout << "Name            : " << client.Name << endl;
	cout << "Phone           : " << client.PhoneNumber << endl;
	cout << "Account Balance : " << client.Balance << endl;


}

bool FindClientByAccountNumber(string AccountNumber, ClientsData &sClient, vector<ClientsData> &vClients) {

	for (ClientsData &client : vClients)
	{
		if (client.AccountNumber==AccountNumber)
		{
			sClient = client;
			return true;
		}
	}
	return false;
}

void MarkDeletedFlagForClient(string AccountNumber,vector<ClientsData>& vClients) {

	for (ClientsData& sClient: vClients) //deals with the original vetor and data
	{
		if (sClient.AccountNumber== AccountNumber)
		{
			sClient.DeletedFalg = true;
			break;
		}
	}
	
}

void DeleteClientByAccountNumber(string AccountNumber, vector<ClientsData> &vClients) {

	ClientsData sClient;
	char choice;

	if (FindClientByAccountNumber(AccountNumber,sClient,vClients))
	{
		PrintClientCard(sClient);
		cout << "Do You Want To Delete This Client (Y|N) ? ";
			cin >> choice;
		if (choice=='y'|| choice=='Y')
		{
			MarkDeletedFlagForClient(AccountNumber, vClients);
			SaveClientsDataToFile(vClients);
			cout << "Client Deleted Successfuyl \n";
		}
	}
	else
	{
		cout << "Client Not Found!\n";
	}
}

void UpdateClientByAccountNumber(string AccountNumber , vector<ClientsData> &vClients){

	ClientsData sClient;
	char choice;

	if (FindClientByAccountNumber(AccountNumber, sClient, vClients))
	{
		PrintClientCard(sClient);
		cout << "Do You Want To Update This Client (Y|N) ? ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			for (ClientsData& client : vClients)
			{
				if (client.AccountNumber == AccountNumber)
				{
					cout << "Enter Client Pin Code : ";
					cin >> client.PinCode;

					cout << "Enter Client Name : ";
					cin.ignore();
					getline(cin, client.Name);

					cout << "Enter Client Phone Number : ";
					cin >> client.PhoneNumber;

					cout << "Enter Client Balance : ";
					cin >> client.Balance;
					cout << endl;
				}
			}
			SaveClientsDataToFile(vClients);
			cout << "client updated successfuly\n";
		}
	}
	else
	{
		cout << "Client Not Found!/n";
	}
}

