#pragma once
#include <string>
#include "ClsString.h"
#include "ClsUtile.h"
#include"ClsBankClient.h"
#include"ClsInputValidation.h"
//#include"ClsPerson.h"
//#include"ClsScreen.h"
#include"ClsPerson.h"
//#include<iomanip>
class ClsUser:public clsPerson
{

private:

		string _Username;
		string _Password;
		int _Permissions;
		bool Flage = false;
		enum _enMode {
			EmptyMode = 0, UpdateMode = 1,
			AddNewMode = 2, DeleteMode = 3
		};
		_enMode _Mode;
		void _SetMode(_enMode Mode)
		{
			_Mode = Mode;
		}
		_enMode GetMode()
		{
			return _Mode;
		}
		static ClsUser _ConverLineToUserObject(string line, string Seperator = "#//#")
		{
			vector<string>vUsersData = clsString::Split(line, Seperator);

			return ClsUser(_enMode::UpdateMode, vUsersData[0], vUsersData[1], vUsersData[2], vUsersData[3],
				vUsersData[4], vUsersData[5], clsUtil::DecryptText( vUsersData[6]), stoi(vUsersData[7]));
		}

		static ClsUser _EmptyUserObject()
		{
			return ClsUser(_enMode::EmptyMode, " ",  " ", " ", " ", " ", " ", " ",0);
		}
		static string _ConvertUserDataToLineOfRecords(ClsUser& User, string Seperator = "#//#")
		{
			string line = "";
			line += User.FirstName + Seperator;
			line += User.LastName + Seperator;
			line += User.Phone + Seperator;
			line += User.Email + Seperator;
			line += User.Gender + Seperator;
			line += User._Username+ Seperator;
			line += clsUtil::EncryptText(User.Password) + Seperator;
			line += to_string(User._Permissions);
			return line;
		}
		static void _SaveUserDataToFile(vector<ClsUser>& _vUsers)
		{
			ofstream file("UF");
			if (file.is_open())
			{
				for (auto& U : _vUsers)
				{
					if (!U.Flage)
					{
						/*if (!_enMode::DeleteMode)
						{
							U.Password = clsUtil::EncryptWord(U.Password);
						}*/
						file << _ConvertUserDataToLineOfRecords(U) << endl;
					}
				}
				file.close();
			}
		}
		static void _SaveUserDataToFile_AddNew_(string line)
		{
			ofstream file("UF", ios::app);
			if (file.is_open())
			{
				file << line << endl;
			}
			file.close();
		}
		static vector<ClsUser> _LoadDataFromFile()
		{
			vector<ClsUser>_vUsers;
			ifstream file("UF");
			if (file.is_open())
			{
				string line = "";
				while (getline(file, line))
				{
					ClsUser U = _ConverLineToUserObject(line);
					//U.Password = clsUtil::DecryptWord(U.Password);
					_vUsers.push_back(U);
				}
				file.close();
			}
			return _vUsers;
		}
		void _AddNew()
		{
			//this->Password = clsUtil::EncryptWord(this->Password);

			_SaveUserDataToFile_AddNew_(_ConvertUserDataToLineOfRecords(*this));
		}
		void _Delete()
		{
			vector<ClsUser>_VClients = _LoadDataFromFile();
			for (auto& U : _VClients)
			{
				if (U._Username == _Username && U._Password == _Password)
				{
					U.Flage = true;
					break;
				}
			}
			_SaveUserDataToFile(_VClients);
			*this = _EmptyUserObject();
		}
		void _Update()
		{
			vector<ClsUser>_vUsers= _LoadDataFromFile();
			for (auto& U : _vUsers)
			{
				if (U._Username == _Username )
				{
					U = *this;
					break;
				}
			}
			_SaveUserDataToFile(_vUsers);
		}
		static ClsUser _CurrentUser;
		bool _IsActiveUser()const
		{
			ClsUser CurrentUser = ClsUser::GetCurrentUser();
			return (this-> GetUsername() == CurrentUser.GetUsername());


		}
		bool _IsAdmin()const
		{
			return (this->_HasPermission(ClsUser::enPermissons::mange_users));
		}
		int _CountAdmins()const
		{
			int Admins = 0;
			vector<ClsUser>Users = _LoadDataFromFile();
			for (const auto& User : Users)
			{
				if (_IsAdmin())
				{
					Admins += 1;
				}
			}
			return Admins;
		}
		bool _IsLastAdminInSystem()const
		{
			return	(_IsAdmin() && _CountAdmins() == 1);
		}
		bool _IsUserLastUserInSystem()const
		{
			return GetNumberOfUsersInSystem() == 1;
		}


public:

		static void SaveDataToFile(vector<ClsUser>& User)
		{
			_SaveUserDataToFile(User);

		}
		static vector<ClsUser>GetUsersList()
		{
			return _LoadDataFromFile();
		}
		static int GetNumberOfUsersInSystem()
		{
			vector<ClsUser>Users = GetUsersList();
			return Users.size();
		}
		static ClsUser Find(string Username,string Password)
		{
			ifstream file("UF");
			if (file.is_open())
			{
				string line;
				while (getline(file, line))
				{
					ClsUser U = _ConverLineToUserObject(line);
					//U.Password = clsUtil::DecryptWord(U.Password);

					if (U._Username == Username && U._Password == Password)
					{
						file.close();
						return U;
					}

				}

			}
			return _EmptyUserObject();

		}
		static ClsUser Find(string Username)
		{
			ifstream file("UF");
			if (file.is_open())
			{
				string line;
				while (getline(file, line))
				{
					ClsUser User = _ConverLineToUserObject(line);

					if (User._Username == Username )
					{
						file.close();
						return User;
					}

				}

			}
			return _EmptyUserObject();

		}
		static ClsUser _NewUserObject(string Username)
		{
			return ClsUser(_enMode::AddNewMode,"","", "", "", "", Username, "", 0);
		}

	

		ClsUser():
		clsPerson("", "", "", "", "")
		{
			_Permissions = 0;
		}

		ClsUser(_enMode Mode, string FirstName, string LastName,  string Phone ,string Email,
			string  Gender,string Username,string Password,int Permissions )
			:clsPerson(FirstName, LastName, Email, Phone, Gender)
		{
			_Mode = Mode;
			_Username = Username;
			_Password = Password;
			_Permissions = Permissions;
		}
		string GetUsername()const
		{
			return _Username;
		}
		void SetPermissions(int Permission)
		{
			_Permissions = Permission;
		}
		int GetPermissions()
		{
			return _Permissions;
		}
		__declspec(property(get = GetPermissions, put = SetPermissions))int Permission;
		void SetPassword(string Password)
		{
			_Password = Password;
		}
		string GetPassword()
		{
			return _Password;
		}
	    bool UserCanBeDeleted()const
		{
			if (_IsActiveUser())
				return false;
			
			if (_IsUserLastUserInSystem() && _IsAdmin())
				return false;

			if (_IsLastAdminInSystem())
				return false;

			return true;
		}

		
		__declspec(property(get = GetPassword, put = SetPassword))string Password;
		enum enSaveDataInFile {
			UpdatedDataSavedSuccessfuly = 0, Faild = 1,
			NewDataSavedSuccessfuly = 2, DataDeletedSuccessfuly
		};
		enSaveDataInFile Save()
		{
			switch (_Mode)
			{
			case _enMode::EmptyMode:
			{
				return enSaveDataInFile::Faild;
				break;
			}
			case _enMode::UpdateMode:
			{
				_Update();
				return enSaveDataInFile::UpdatedDataSavedSuccessfuly;
			}
			case _enMode::AddNewMode:
			{
				_AddNew();
				_SetMode(_enMode::UpdateMode);
				return enSaveDataInFile::NewDataSavedSuccessfuly;
			}
			case _enMode::DeleteMode: 
			{
				if (UserCanBeDeleted())
				{
					_Delete();
					_SetMode(_enMode::UpdateMode);

					return enSaveDataInFile::DataDeletedSuccessfuly;
				}
				else
				{
					_SetMode(_enMode::UpdateMode);
					return enSaveDataInFile::Faild;
				}


			}
			}
		}
		void MarkForDelete()
		{
			_SetMode(_enMode::DeleteMode);
		}
		bool IsEmpty()
		{
			return (_Mode == _enMode::EmptyMode);
		}
		enum enPermissons
		{
			show_clients_lilst = 1 << 0,
			add_client = 1 << 1,
			delete_client = 1 << 2,
			update_client = 1 << 3,
			find_client = 1 << 4,
			transaction_menu = 1 << 5,
			mange_users = 1 << 6,
			clear_all_Client = 1 << 7, 
			logout = 1 << 8


		};
		bool _HasPermission(enPermissons permission)const
		{
			return (_Permissions & permission) == permission;
		}
		static bool IsUserExist(string Username)
		{
		    ClsUser User = Find(Username);
			return !(User.IsEmpty());
		}
		static bool IsUserExist(string Username, string Password)
		{
			ClsUser User = Find(Username, Password);
			return !(User.IsEmpty());
		}
		void Clear()
		{
			ofstream file("UF");
			if (file.is_open())
			{
				file.close();
			}
		}
		void ClearOldPermissions()
		{
			Permission = 0;
		}
		static void SetCurrentUser(ClsUser& User)
		{
			_CurrentUser = User;
		}
		static ClsUser GetCurrentUser()
		{
			return _CurrentUser;
		}




};

