#pragma once

#include <iostream>
#include <string>
#include"ClsBankClient.h"
#include"ClsUtile.h"
#include<iomanip>

using namespace std;
class ClsClientsListScreen :protected clsScreen
{
private:
	static void _PrintClientRecordLine(ClsBankClient&Client)
	{
		// << "| " << setw(15) << left << Client.AccountNumber();
		cout << setw(8) << left << ""<< "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(17) << left << Client.Email;
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(7) << left << Client.Gender;
		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(12) << left << Client.Password;
		cout << "| " << setw(8) << left << Client.Balance;
	}

public:
	
	static void ClientsListScreen()
	{
		vector <ClsBankClient> vClients = ClsBankClient::GetClientsList();
		string Title = "\tClients List Screen\n";
		string SupTilel = "\t  (" + (to_string(vClients.size()))+") Client(s).";
		clsScreen::_DrawScreenHeader(Title, SupTilel);
		//cout << setw(8) << left << "" << "\n\t_______________________________________________________";

		cout <<
			"\n\t_______________________________________________________";
		cout << "__________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(20) << left << "Full Name";
		cout << "| " << left << setw(17) << "Email";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(7) << "Gender";
		cout << "| " << left << setw(15) << "Account number";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(8) << "Balance";
		cout <<
			"\n\t_______________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
			for (auto & Client : vClients)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}
		cout <<
			"\n\t_______________________________________________________";
		cout << "__________________________________________________\n" << endl;
	}
};

