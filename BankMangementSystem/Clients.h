#pragma once
#include <string>
#include <vector>
using namespace std;

struct ClientsData {
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	float Balance;

};
bool IsExistAccountNumber(string AccountNumber, vector <ClientsData>& vClients);
vector <ClientsData> AddNewClient();