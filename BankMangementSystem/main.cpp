#include<iostream>
#include"Clients.h"
#include"File&StringManager.h"
using namespace std;

int main() {

	string AccountNumber;
	struct ClientsData sClient;
	vector<ClientsData> vClients = LoadClientsDataFromFile(FileName);
	char EndProgram;
	int Choice;

	do
	{
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

		cout << "Chose What Do You Want From [1 to 6] ? ";
			cin >> Choice;
			//system("cls");

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
		case 3 :
			 cout << "Please Enter Account Number :";
			 cin >> AccountNumber;
			 DeleteClientByAccountNumber(AccountNumber, vClients);
			 break;
		case 4:
			cout << "Please Enter Account Number :";
			cin >> AccountNumber;
			UpdateClientByAccountNumber(AccountNumber, vClients);
			break;
		case 5 :
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
		case 6 :
			cout << "\n\t\t\t\t\t################ Program Ends #################\n";
			return 0;

		default:
			cout << "Please Enter A Correct Choice :";
			break;
		}

	} while (true);


}