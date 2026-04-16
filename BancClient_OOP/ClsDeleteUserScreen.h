#pragma once
#include"ClsUser.h"
#include"ClsInputValidation.h"
#include"ClsScreen.h"
class ClsDeletUserScreen:protected clsScreen
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
	static void DeleteUserScreen()
	{
		clsScreen::_DrawScreenHeader("\tDelete User Screen");
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
		ClsUser UserToDelete = ClsUser::Find(Username, Password);
		_PrintUser(UserToDelete);


		cout << "\nAre You Sure From Deleting  This User [y/n]? ";
		char answer = 'n';
		cin >> answer;

		if (answer == tolower('y'))
		{
			UserToDelete.MarkForDelete();

			ClsUser::enSaveDataInFile Result;
			Result = UserToDelete.Save();
			switch (Result)
			{
			case ClsUser::enSaveDataInFile::Faild:
			{
				cout << "\nYou Can't Delete this User";
				break;
			}
			case ClsUser::enSaveDataInFile::DataDeletedSuccessfuly:
			{
				cout << "\User Deleted Successfuly\n";
				_PrintUser(UserToDelete);
				break;
			}
			}
		}
	}
};

