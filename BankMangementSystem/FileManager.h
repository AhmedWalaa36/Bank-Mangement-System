#pragma once
#include <string>
#include "Clients.h"
using namespace std;

string ConvertClientCardToLineString(ClientsData sClient, string Separator);
void SaveClientDataToFile(vector <ClientsData> vClients);