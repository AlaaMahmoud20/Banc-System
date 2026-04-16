#pragma once
//#include <string>
//#include <string>
#include"ClsBankClient.h"
//#include"ClsInputValidation.h"
//#include"ClsPerson.h"
#include"ClsScreen.h"
//#include"ClsUser.h"
//#include<iomanip>

class ClsClearClientsScreen:protected clsScreen
{
private:
	static char _Answer()
	{
		char answer;
		cin >> answer;
		return tolower(answer);
	}

public:
	static void ClearClientScreen()
	{
		clsScreen::_DrawScreenHeader("Clear Clients Screen");
		cout << "\nAre You Sure To Delete All Clients In The System?\n ";
		if (_Answer() == 'y')
		{
			ClsBankClient::Clear();
			cout << "\nAll Clients Deleted Sucessfully.\n";

		}

	}

};

