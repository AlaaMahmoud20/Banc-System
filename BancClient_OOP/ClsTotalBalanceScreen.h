#pragma once

#include <iostream>
#include <string>
#include<iomanip>
#include"ClsBankClient.h"
#include"ClsScreen.h"
#include"ClsUtile.h"

class ClsTotalBalanceScreen : protected clsScreen
{
private:
	static void _PrintClientRecordForTotalBalance(ClsBankClient Client)
	{

		cout << setw(17) << left << "" << "| " << setw(30) << left << Client.GetAccountNumber();
		cout << "| " << setw(42) << left << Client.FullName();
		cout << "| " << setw(25) << left << Client.Balance;
	}

public:
	static void TotalBalanceScreen()
	{
		vector <ClsBankClient> vClients = ClsBankClient::GetClientsList();
		string Title = "\tBalances List Screen\n";
		string SupTilel = "\t  (" + (to_string(vClients.size())) + ") Client(s).";
		clsScreen::_DrawScreenHeader(Title, SupTilel);
		cout <<
			"\n\t\t________________________________________";
		cout << "__________________________________________________\n" << endl;


		cout << setw(17) << left << "" << "| " << setw(30) << left << "AccountNumber";
		cout << "| " << setw(42) << left << "FullName";
		cout << "| " << left << setw(25) << "Balance";
		cout <<
			"\n\t\t________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
			for (auto const& Client : vClients)
			{
				_PrintClientRecordForTotalBalance(Client);
				cout << endl;
			}
		cout <<
			"\n\t\t________________________________________";
		cout << "__________________________________________________\n" << endl;
		double TotalBalance = ClsBankClient::GetTotalBalance();
		cout << "\t\t\t\t\t Total Balances = " << TotalBalance << "\n\n";
		cout << "\t\t\t\t(" << clsUtil::NumberToText(TotalBalance)<<")\n";
	}

};

