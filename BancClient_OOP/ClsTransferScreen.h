#pragma once
#include"ClsBankClient.h"
#include"ClsScreen.h"
#include"ClsTransfer.h"

class ClsTransferScreen:protected clsScreen
{

private:
	static void _PrintClient(ClsBankClient& Client)
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
	static string _ReadAccountNumber(string Message)
	{
		string AccountNumbe = "";
		cout<<Message;
		AccountNumbe = clsInputValidate::ReadString();
		while (!ClsBankClient::IsClientExist(AccountNumbe))
		{
			cout << "\nInvalid Data Client Not Found! : ";
			AccountNumbe = clsInputValidate::ReadString();
		}
		ClsBankClient C = ClsBankClient::Find(AccountNumbe);
		return AccountNumbe;
	}

public:
	static void TransferScreen()
	{

		clsScreen::_DrawScreenHeader("Transfer Screen");
		
		ClsBankClient SourceClient = ClsBankClient::Find(_ReadAccountNumber("\nEnter Acount Number Transfer From :"));
		_PrintClient(SourceClient);


		ClsBankClient DestenationClient = ClsBankClient::Find(_ReadAccountNumber("\nEnter Acount Number Transfer To :"));
		_PrintClient(DestenationClient);
	

		cout << "\nAmount?  ";
		float Amount = clsInputValidate::ReadDblNumber();

		if (SourceClient.Transfer(Amount, DestenationClient))
		{
		
			ClsUser CurrentUser = ClsUser::GetCurrentUser();
			clsDate date;

			ClsTransfer TransferObject(date, Amount,SourceClient.GetAccountNumber(), SourceClient.Balance,
				DestenationClient.GetAccountNumber(), DestenationClient.Balance,
				CurrentUser.GetUsername(), CurrentUser.GetPermissions());

			ClsTransfer::RegisterTransfer(TransferObject);

			cout << "\nSuccessful Operation.\n";
			cout << "\nNew Balance Of(" << SourceClient.GetAccountNumber() << "):" << SourceClient.Balance << "\n";
			cout << "New Balance Of(" << DestenationClient.GetAccountNumber() << "):" << DestenationClient.Balance << "\n";
			// ... rest of your print code
		}

		else
		{
			cout << "\n\nClient Whith Account Number("<< SourceClient.GetAccountNumber() <<")Has Insufficient Balance.\n";
			
		}
	}
};

