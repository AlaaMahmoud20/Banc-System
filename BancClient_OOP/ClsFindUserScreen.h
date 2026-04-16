#pragma once
#include"ClsScreen.h"
#include"ClsUser.h"
#include"clsInputValidation.h"

class ClsFindUserScreen:protected clsScreen
{
private:
	static void _PrintUser(ClsUser& User)
	{
		cout << "\n\User Info";
		cout << "\n==============================";
		cout << "\nFull Name    : " << User.FullName();
		cout << "\nEmail        : " << User.Email;
		cout << "\nPhone        : " << User.Phone;
		cout << "\nGender       : " << User.Gender;
		cout << "\nUsername     : " << User.GetUsername();
		cout << "\nPassword     : " << User.Password;
		cout << "\nPermissions  : " << User.Permission;
		cout << "\n==============================\n";


	}

public:
	static void FindUserScreen()
	{
		clsScreen::_DrawScreenHeader("Find User Screen");
		string Username = "";
		string Password = "";
		cout << "Username    : ";
		Username = clsInputValidate::ReadString();
		cout << "Password    : ";
		Password = clsInputValidate::ReadString();
		while (!ClsUser::IsUserExist(Username, Password))
		{
			cout << "\nInvalid Data Username/Password Not Found!\n\n";
			cout << "Username    : ";

			Username = clsInputValidate::ReadString();
			cout << "Password    : ";

			Password = clsInputValidate::ReadString();

		}
		ClsUser U = ClsUser::Find(Username,Password);
		if (!U.IsEmpty())
		{
			_PrintUser(U);
		}
		else cout << " \nIvalid Data User Not Found\n";
	}
};

