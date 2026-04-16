#pragma once
#include <iostream>
#include <string>
#include"ClsBankClient.h"
//#include"ClsInputValidation.h"
//#include"ClsPerson.h"
#include"ClsScreen.h"
//#include"ClsUtile.h"
//#include<iomanip>

using namespace std;
class ClsAddClientScreen:protected clsScreen
{
private:
	static void _ReadClientData(ClsBankClient& Client)
	{
		cout << "Firs name      : ";
		Client.SetFirstName(clsInputValidate::ReadString());

		cout << "Last name      : ";
		Client.SetLastName(clsInputValidate::ReadString());

		cout << "Email          : ";
		Client.SetEmail(clsInputValidate::ReadString());

		cout << "Phone          : ";
		Client.SetPhone(clsInputValidate::ReadString());

		cout << "Gender         : ";
		Client.SetGender(clsInputValidate::ReadString());
	 
		cout << "Password       : ";
		Client.SetPassword(clsInputValidate::ReadString());

		cout << "Balance        : ";
		Client.SetBalance(stod(clsInputValidate::ReadString()));	
	}
	static void _PrintClient(ClsBankClient &Client)
	{
		cout << "\n\tClient Info";

		cout << "\n==============================";
		cout << "\nFull Name      : " <<Client. FullName();
		cout << "\nEmail          : " << Client. Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nGender         : " << Client.Gender;
		cout << "\nAccount Number : " << Client.GetAccountNumber();
		cout << "\nPassword       : " << Client.Password;
		cout << "\nBalance        : " << Client.Balance;
		cout << "\n==============================\n";
	}


public:

	static void AddNewclientScreen()
	{
		clsScreen::_DrawScreenHeader("Adding Clients Screen");
		string AccountNumbe = "";
		cout << "Account Number :";
		AccountNumbe = clsInputValidate::ReadString();
		while (ClsBankClient::IsClientExist(AccountNumbe))
		{
			cout << "\nInvalid Data Account Number Allready Exist!\n\n";
			//cout << "Account Number :";

			AccountNumbe = clsInputValidate::ReadString();
		}

		ClsBankClient C = ClsBankClient::_NewClientObject(AccountNumbe);
		_ReadClientData(C);


		ClsBankClient::enSaveDataInFile Result;
		Result = C.Save();
		switch (Result)
		{
		case ClsBankClient::enSaveDataInFile::Faild:
		{
			cout << "Saved faild Empty object";
			break;
		}
		case ClsBankClient::enSaveDataInFile::NewDataSavedSuccessfuly:
		{
			cout << "\nNew Client Saved Successfuly\n";
			_PrintClient(C);
			break;
		}
		}
	}
};

