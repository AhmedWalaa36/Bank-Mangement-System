#include <iostream>
#include <fstream>
#include"File&StringManager.h"

using namespace std;

string FileName = "ClientFile.txt";

string ConvertClientCardToLineString(ClientsData sClient,string Separator) {
	
	return	sClient.AccountNumber + Separator +
			sClient.PinCode + Separator +
			sClient.Name + Separator +
			sClient.PhoneNumber + Separator +
			to_string(sClient.Balance);

}
void SaveClientsDataToFile(vector <ClientsData> &vClients) {

	fstream ClientsFile;
	string Line;
	ClientsFile.open(FileName, ios::app);

	if (ClientsFile.is_open())
	{
		for (ClientsData &client: vClients)
		{
			Line = ConvertClientCardToLineString(client, "#//#");
			ClientsFile << Line << endl;
		}
	}
	cout << "Client Saved Successfuly....\n";
	ClientsFile.close();
}

vector <string> SplitString(string DataLine, string separator) {

	vector <string> vStrings;
	int SeparatorIndex;
	while (SeparatorIndex = DataLine.find(separator) != string::npos)
	{
		string RecordSplited = DataLine.substr(0, SeparatorIndex);

		if (RecordSplited!="")
		{
			vStrings.push_back(RecordSplited);
		}
		DataLine.erase(0, SeparatorIndex + separator.length());
	}
	if (DataLine != "")
	{
		vStrings.push_back(DataLine);
	}

	return vStrings;
}

ClientsData ConvertLineStringToClientStruct(string DataLine,string Separator) {

	vector <string> vStrings;
	ClientsData ClientCard;

	vStrings = SplitString(DataLine, Separator);

	ClientCard.AccountNumber = vStrings[0];
	ClientCard.PinCode = vStrings[1];
	ClientCard.Name = vStrings[2];
	ClientCard.PhoneNumber = vStrings[3];
	ClientCard.Balance = stof(vStrings[4]);

	return ClientCard;

}

vector <ClientsData> LoadClientsDataFromFile(string FileName){

	ClientsData client;
	fstream ClientsFile;
	string DataLine;
	vector <ClientsData> vClients;

	ClientsFile.open(FileName, ios::in);

	if (ClientsFile.is_open())
	{
		while (getline(ClientsFile,DataLine)) //getline(object of file, variable to store )
		{
			client = ConvertLineStringToClientStruct(DataLine, "#//#");
			vClients.push_back(client);
		}
	}
	return vClients;
}