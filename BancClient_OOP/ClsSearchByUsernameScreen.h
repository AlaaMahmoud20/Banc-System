#pragma once
#include"ClsLoginRegister.h"
#include"ClsScreen.h"
#include"ClsInputValidation.h"
#include<iomanip>

class ClsSearchByUsernameScreen:protected clsScreen
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
		string Title = "Search By Username Screen\n";
		clsScreen::_DrawScreenHeader(Title);

		string Username;
		cout << "Username    : ";
		Username = clsInputValidate::ReadString();

		while (!ClsUser::IsUserExist(Username))
		{
			cout << "\nInvalid Data Username Not Found!\n\n";
			cout << "Username    : ";

			Username = clsInputValidate::ReadString();
			

		}
		vector <ClsLoginRegister> vUsers= ClsLoginRegister::GetSearchByUsernameList(Username);


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
			cout << "\t\t\t\tNo Login Register Data Available In the System!";
		else
			for (auto& U : vUsers)
			{
				_PrintRegisterdUserRecordLine(U);
				cout << endl;
			}
		cout <<
			"\n\t_______________________________________________________";
		cout << "________________________________________\n\n" << endl;
	}
};

