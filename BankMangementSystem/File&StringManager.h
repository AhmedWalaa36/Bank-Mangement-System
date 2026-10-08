#pragma once
#include <string>
#include "Clients.h"
using namespace std;

extern string FileName;

vector <string> SplitString(string DataLine, string separator);
string ConvertClientCardToLineString(ClientsData sClient, string Separator);
void SaveClientsDataToFile(vector <ClientsData>& vClients);
ClientsData ConvertLineStringToClientStruct(string DataLine, string Separator);
vector <ClientsData> LoadClientsDataFromFile(string FileName);