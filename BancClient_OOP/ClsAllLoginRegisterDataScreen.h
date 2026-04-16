#pragma once
#include"ClsUtile.h"
#include<iomanip>
#include"ClsScreen.h"
#include"ClsDate.h"
#include"ClsLoginRegister.h"
class ClsAllLoginRegisterDataScreen :protected clsScreen
{
private:
	static void _PrintRegisterdUserRecordLine(ClsLoginRegister& User)
	{
		cout << setw(8) << left << "" << "| " << setw(20) << left << User.GetDate();
		cout << "| " << setw(17) << left << User.GetTime();
		cout << "| " << setw(12) << left << User.GetUsername();
		cout << "| " << setw(15) << left << User.GetPassword();
		cout << "| " << setw(15) << left << User.GetPermissions();
	}

public:

	static void LoginRegisterListScreen()
	{
		vector <ClsLoginRegister> vUsers = ClsLoginRegister::GetUsersList();
		string Title = "Login Register Screen\n";
		string SupTilel = " (" + (to_string(vUsers.size())) + ") login(s).";
		clsScreen::_DrawScreenHeader(Title, SupTilel);
	
		cout <<
			"\n\t_______________________________________________________";
		cout << "________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(20) << left << "Date ";
		cout << "| " << left << setw(17) << "Time";
		cout << "| " << left << setw(12) << "Username";
		cout << "| " << left << setw(15) << "Password";
		cout << "| " << left << setw(15) << "Permissions";
		cout <<
			"\n\t_______________________________________________________";
		cout << "________________________________________\n" << endl;
		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
			for (auto& U: vUsers)
			{
				_PrintRegisterdUserRecordLine(U);
				cout << endl;
			}
		cout <<
			"\n\t_______________________________________________________";
		cout << "________________________________________\n\n" << endl;
	}
};

