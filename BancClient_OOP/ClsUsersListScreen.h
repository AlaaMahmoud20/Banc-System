#pragma once
#include <string>
#include"ClsUser.h"
#include"ClsUtile.h"
#include<iomanip>
class ClsUsersListScreen:protected clsScreen,ClsUser
{
private:
	static void _PrintUserRecordLine(ClsUser &User)
	{
		cout << setw(8) << left << "" << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(17) << left << User.Email;
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(7) << left << User.Gender;
		cout << "| " << setw(15) << left << User.GetUsername();
		cout << "| " << setw(12) << left << clsUtil::MaskText(User.Password);
		cout << "| " << setw(8) << left << User.Permission;
		
	}

public:

	static void UsersListScreen()
	{
		vector <ClsUser> vUsers = ClsUser::GetUsersList();
		string Title = "\tUsers List Screen\n";
		string SupTilel = "\t  (" + (to_string(vUsers.size())) + ") User(s).";
		clsScreen::_DrawScreenHeader(Title, SupTilel);
		//cout << setw(8) << left << "" << "\n\t_______________________________________________________";

		cout <<
			"\n\t_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(20) << left << "Full Name";
		cout << "| " << left << setw(17) << "Email";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(7) << "Gender";
		cout << "| " << left << setw(15) << "Username";
		cout << "| " << left << setw(12) <<  "Password";
		cout << "| " << left << setw(8) << "Permissions";
		
		cout <<
			"\n\t__________________________________________________________";
		cout << "_____________________________________________________\n" << endl;
		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else
			for (auto & User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}
		cout <<
			"\n\t__________________________________________________________";
		cout << "_____________________________________________________\n" << endl;
	}


};

