#include "Clients.h"
#include <iostream> 
using namespace std;

ClientsData sClient;


vector <ClientsData> AddNewClient() {

	cout << "Please Enter Client Information. \n\n";
	char AddNewClient = 'n';
	vector <ClientsData> vCleints;

	do
	{
		cout << "Enter Client Account Number : ";
		cin >> sClient.AccountNumber;
		cout << "Enter Client Pin Code : ";
		cin >> sClient.PinCode;
		cout << "Enter Client Name : ";
		cin >> sClient.Name;
		cout << "Enter Client Balance : ";
		cin >> sClient.Balance;
		cout << endl;

		vCleints.push_back(sClient);

		cout << "Do You Want To Add Another Client (Y|N) ? ";
		cin >> AddNewClient;

	} while (AddNewClient=='y'|| AddNewClient=='Y');
	
	return vCleints;

}