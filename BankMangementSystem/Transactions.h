#pragma once
#include <vector>
#include "Clients.h"

using namespace std;

void Deposite(vector<ClientsData>& vClients);
void Withdraw(vector<ClientsData>& vClients);
void ShowClientBalance(vector<ClientsData>& vClients);
void ShowTransactionMenue();
void PerformTransactionOperation();