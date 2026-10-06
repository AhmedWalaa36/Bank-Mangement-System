#include <iostream>
#include <fstream>
#include"FileManager.h"

using namespace std;

string FileName = "ClientFile.txt";

string ConvertClientCardToLineString(ClientsData sClient,string Separator) {
	
	return	sClient.AccountNumber + Separator +
			sClient.PinCode + Separator +
			sClient.Name + Separator +
			sClient.PhoneNumber + Separator +
			to_string(sClient.Balance);

}
void SaveClientDataToFile(vector <ClientsData> vClients) {

	fstream ClientFile;
	string Line;
	ClientFile.open(FileName, ios::app);

	if (ClientFile.is_open())
	{
		for (ClientsData client: vClients)
		{
			Line = ConvertClientCardToLineString(client, "#//#");
			ClientFile << Line << endl;
		}
	}
	cout << "Client Saved Successfuly....\n";
	ClientFile.close();
};