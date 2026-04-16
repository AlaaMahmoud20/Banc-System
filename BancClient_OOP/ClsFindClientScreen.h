#pragma once
#include<iostream>
#include"ClsScreen.h"
#include"ClsBankClient.h"
#include"clsInputValidation.h"

class ClsFindClientScreen:protected clsScreen
{
private:
	static void _PrintClient(ClsBankClient &Client)
	{
		cout << "\n\tClient Info";

		cout << "\n==============================";
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nGender         : " << Client.Gender;
		cout << "\nAccount Number : " << Client.GetAccountNumber();
		cout << "\nPassword       : " << Client.Password;
		cout << "\nBalance        : " << Client.Balance;
		cout << "\n==============================\n";
	}

public:
	static void FindClientScreen()
	{
		clsScreen::_DrawScreenHeader("Find Client Screen");
		string AccountNumbe = "";
		cout << "\nEnter Account Number :";
		AccountNumbe = clsInputValidate::ReadString();
		while (!ClsBankClient::IsClientExist(AccountNumbe))
		{
			cout << "\nInvalid Data Client Not Found! : ";
			AccountNumbe = clsInputValidate::ReadString();
		}
		ClsBankClient C = ClsBankClient::Find(AccountNumbe);
		if (!C.IsEmpty())
		{
			_PrintClient(C);
		}
		else cout << " \nIvalid Data Client Not Found\n";
	}
};

