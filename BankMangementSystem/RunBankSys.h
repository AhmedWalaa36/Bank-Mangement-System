#pragma once
#include"Clients.h"


using namespace std;


void ShowMainMenu();
int GetChoiceFromUser();
void PerformOperation(int Choice, vector<ClientsData> &vClients);
void RunBankSystem();