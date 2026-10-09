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
	bool DeletedFalg = false;
};
bool IsExistAccountNumber(string AccountNumber, vector <ClientsData>& vClients);
void AddNewClient(vector <ClientsData>& vClients);
void PrintClientData(ClientsData &client);
void ShowClientList(vector<ClientsData> &vClients);
void PrintClientCard(ClientsData &client);
void MarkDeletedFlagForClient(string AccountNumber, vector<ClientsData>& vClients);
bool FindClientByAccountNumber(string AccountNumber, ClientsData& sClient, vector<ClientsData> &vClients);
void DeleteClientByAccountNumber(string AccountNumber, vector<ClientsData> &vClients);
void UpdateClientByAccountNumber(string AccountNumber, vector<ClientsData> &vClients);
