#pragma once
#include"ClsUtile.h"
#include<iomanip>
#include"ClsScreen.h"
#include"ClsDate.h"
#include"ClsTransfer.h"
class ClsTransfersList :protected clsScreen
{
private:
	static void _PrintRecordLine(ClsTransfer& T)
	{
		cout << setw(1) << left << "" << "| " << setw(20) << left << T.GetDate();
		//cout << "| " << setw(10) << left << T.GetTime();
		cout << "| " << setw(9) << left << T.GetAmount();
		cout << "| " << setw(10) << left <<T.GetSenderAccount();
		cout << "| " << setw(10) << left << T.GetSenderBalanceAfter();
		cout << "| " << setw(10) << left << T.GetReceiverAccount();
		cout << "| " << setw(10) << left << T.GetReciverBalanceAfter();
		cout << "| " << setw(8) << left << T.GetInChargeUserName();
		cout << "| " << setw(15) << left << T.GetPermissinos();
	}

public:

	static void TransfersListScreen()
	{
		
		vector <ClsTransfer> vUsers =  ClsTransfer::GetTransfersList();
		string Title = "Transfers List\n";
		string SupTilel = " (" + (to_string(vUsers.size())) + ") Transfer(s).";
		clsScreen::_DrawScreenHeader(Title, SupTilel);

		cout <<
			"\n________________________________________________";
		cout << "_______________________________________________________________________\n" << endl;
		cout << setw(1) << left << "" << "| " << setw(20) << left << "Date";
		cout << "| " << setw(9) << left << "Amount";
		cout << "| " << setw(10) << left << "(S_Acc)";
		cout << "| " << setw(10) << left << "(Balance)";
		cout << "| " << setw(10) << left << "(D_Acc) ";
		cout << "| " << setw(10) << left << "(Balance)";
		cout << "| " << setw(8) << left << "User";
		cout << "| " << setw(11) << left << "Permissions";
		cout <<
			"\n_________________________________________________";
		cout << "_______________________________________________________________________\n" << endl;
		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
			for (auto& U : vUsers)
			{
				_PrintRecordLine(U);
				cout << endl;
			}
		cout <<
			"\n_________________________________________________";
		cout << "_______________________________________________________________________\n\n" << endl;
	}
};

