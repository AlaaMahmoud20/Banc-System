#pragma once
#include <string>
#include"ClsBankClient.h"
#include"ClsInputValidation.h"
//#include"ClsPerson.h"
#include"ClsScreen.h"
#include"ClsUser.h"
#include"ClsString.h"
//#include<iomanip>
class ClsAddUserScreen:protected clsScreen
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

    static char _Answer()
    {
        char answer;
        cin >> answer;
        return tolower(answer);
    }
    static void _GivePermission(ClsUser&User,ClsUser::enPermissons Permission)
    {
        if (_Answer() == 'y')
        {
			User.Permission |= Permission;
        }
    }
	static void _GiveAllPermissions(ClsUser &User)
	{
		User.Permission = 1023;
	}
	static void _SetPermissions(ClsUser& User)
	{
		cout << "do You Want to Give This User Full Access [y/n]? : ";

		if (_Answer() == 'y')
		{
			_GiveAllPermissions(User);
		}
		else
		{
			cout << "\n\n\t\tSet Permissions:\n\n";

			cout << "Show Clients list? [y/n]         : ";
			_GivePermission(User, ClsUser::enPermissons::show_clients_lilst);

			cout << "Add Client?        [y/n]         : ";
			_GivePermission(User, ClsUser::enPermissons::add_client);


			cout << "Delete Client?     [y/n]         : ";
			_GivePermission(User, ClsUser::enPermissons::delete_client);


			cout << "Update Client?     [y/n]         : ";
			_GivePermission(User, ClsUser::enPermissons::update_client);


			cout << "Find Client?       [y/n]         : ";
			_GivePermission(User, ClsUser::enPermissons::find_client);


			cout << "Transaction Menu?  [y/n]         : ";
			_GivePermission(User, ClsUser::enPermissons::transaction_menu);


			cout << "Mange Users ?      [y/n]         : ";
			_GivePermission(User, ClsUser::enPermissons::mange_users);

			cout << "Curreny Menu?      [y/n]         : ";
			_GivePermission(User, ClsUser::enPermissons::currency_menu);


			cout << "Clear All Clients? [y/n]         : ";
			_GivePermission(User, ClsUser::enPermissons::clear_all_Client);


			cout << "Logout ?           [y/n]         : ";
			_GivePermission(User, ClsUser::enPermissons::logout);
		}
	}
	static void _ReadUserData(ClsUser& User)
	{
		cout << "Firs name      : ";
		User.SetFirstName(clsInputValidate::ReadString());

		cout << "Last name      : ";
		User.SetLastName(clsInputValidate::ReadString());

		cout << "Email          : ";
		User.SetEmail(clsInputValidate::ReadString());

		cout << "Phone          : ";
		User.SetPhone(clsInputValidate::ReadString());

		cout << "Gender         : ";
		User.SetGender(clsInputValidate::ReadString());

		cout << "Password       : ";
		User.SetPassword(clsInputValidate::ReadString());


		_SetPermissions(User);
	
		
	}

public:

	static void AddNewUserScreen()
	{
		clsScreen::_DrawScreenHeader("Adding User Screen");
		string Username = "";
		cout << "Username      :";
		Username = clsInputValidate::ReadString();
		while (ClsUser::IsUserExist(Username))
		{
			cout << "\nInvalid Data Username ("<< Username<<") Is Allready Used!\n\n";
			Username = clsInputValidate::ReadString();
		}
		ClsUser User = ClsUser::_NewUserObject(Username);
		_ReadUserData(User);



		ClsUser::enSaveDataInFile Result;
		Result = User.Save();
		switch (Result)
		{
		case ClsUser::enSaveDataInFile::Faild:
		{
			cout << "Saved faild Empty object";
			break;
		}
		case ClsUser::enSaveDataInFile::NewDataSavedSuccessfuly:
		{
			cout << "\nNew User Saved Successfuly\n";
			_PrintUser(User);
			break;
		}
		}
	}
};

