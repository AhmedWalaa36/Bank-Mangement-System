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
vector <ClientsData> AddNewClient();