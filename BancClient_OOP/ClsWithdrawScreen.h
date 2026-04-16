#pragma once
#include <string>
#include"ClsBankClient.h"
#include"ClsInputValidation.h"
//#include"ClsPerson.h"
#include"ClsScreen.h"
//#include"ClsUtile.h"
//#include<iomanip>
class ClsWithdrawScreen :protected  clsScreen
{
private:
	static void _Print(ClsBankClient& Client)
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
	static void WithdrawSceen()
	{
		clsScreen::_DrawScreenHeader("Withdraw Screen");
		cout << "\nEnter Account Number :";
		string 	AccountNumber = clsInputValidate::ReadString();
		double DepositingAmount;
		if (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nInvalid Data Client Whith Account Number ( " << AccountNumber << " ) Not Found!: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		ClsBankClient C = ClsBankClient::Find(AccountNumber);
		_Print(C);
		cout << "how much would U like to Withdraw?  ";
		double Amount = clsInputValidate::ReadDblNumber();
		if (C.Withdraw(Amount))
		{
			cout << "\n\nAmount Withdrawin Successfully.\n";
			cout << "New Balance = " << C.Balance << "\n";
		}
		else
		{
			cout << "\n\nCant't Withdraw,Insufficient Balance.\n";
			cout << "Amount to Withdraw = " << Amount<<"\n";
			cout << "Your Balance       = " << C.Balance;
		}
			
			




	}
};


