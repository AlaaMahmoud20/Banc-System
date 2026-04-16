#pragma once

#include <iostream>
#include <string>
#include"ClsUser.h"
#include"ClsUtile.h"
#include"ClsScreen.h"
#include"ClsMainMenu.h"
#include"ClsloginRegister.h"
#include<iomanip>

class ClsLoginScreen:protected clsScreen
{

private:
	static bool _Login()
	{
		short _Counter = 0;
		clsScreen::_DrawScreenHeader("\tLogin Screen");
		string Username = "";
		string Password = "";
		cout << "Username    : ";
		Username = clsInputValidate::ReadString();

		cout << "Password    : ";
		Password = clsInputValidate::ReadString();
		while (!ClsUser::IsUserExist(Username, Password))
		{
			cout << "\nInvalid Data Username/Password Not Found!\n\n";
			
			_Counter++;
			if (_Counter == 3)
			{
				cout << "\nYou Have no trail(s) Please conact your admin";
				return false;
			}
			cout << "Username    : ";

			Username = clsInputValidate::ReadString();
			cout << "Password    : ";

			Password = clsInputValidate::ReadString(); 
		}
		ClsUser User = ClsUser::Find(Username, Password);
		ClsUser::SetCurrentUser(User);
		ClsLoginRegister::AddRegesterdDataToFile();

 		ClsMainMenu::ShowMainMenue();

	}
public:
	static bool LoginScreen()
	{
		bool IsLoginSuccessful = _Login();
		
		return IsLoginSuccessful;
	}
};

