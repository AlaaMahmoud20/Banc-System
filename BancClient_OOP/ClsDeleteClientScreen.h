#pragma once
#include <string>
#include"ClsBankClient.h"
#include"ClsInputValidation.h"
#include"ClsPerson.h"
#include"ClsScreen.h"
//#include"ClsUtile.h"
//#include<iomanip>

class ClsDeleteClientScreen:protected clsScreen
{
private:
	static void _PrintClient(ClsBankClient Client)
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
static void DeleteClientScreen()
{
	clsScreen::_DrawScreenHeader("Delete Client Screen");
	string AccountNumbe = "";
	cout << "\nEnter Account Number :";
	AccountNumbe = clsInputValidate::ReadString();
	while (!ClsBankClient::IsClientExist(AccountNumbe))
	{
		cout << "\nInvalid Data Client Not Found! : ";
		AccountNumbe = clsInputValidate::ReadString();
	}
	ClsBankClient C = ClsBankClient::Find(AccountNumbe);
	_PrintClient(C);
	cout << "\nare you sure from deleting  this client [y/n]? ";
	char answer = 'n';
	cin >> answer;
	if (answer == tolower('y'))
	{
		C.MarkForDelete();
 
		ClsBankClient::enSaveDataInFile Result;
		Result = C.Save();
		switch (Result)
		{
		case ClsBankClient::enSaveDataInFile::Faild:
		{
			cout << "\nYou Can't Delete this Client";
			break;
		}
		case ClsBankClient::enSaveDataInFile::DataDeletedSuccessfuly:
		{
			cout << "\nClient Deleted Successfuly\n";
			_PrintClient(C);
			break;
		}
		}
	}
}
};

