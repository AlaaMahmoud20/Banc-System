#pragma once
#include"ClsString.h"
#include"ClsDate.h"
#include"ClsUser.h"
#include<ctime>
class ClsLoginRegister
{
	
private:

	string _Date;
	string _Time;
	string _CurrentUserName  ;
	string _CurrentUserPassword  ;
	short _CurrentUserpermissions  ;
	

	
	static ClsLoginRegister _ConverLineToRegisterdDataObject(string line, string Seperator = "#//#")
	{
		vector<string>vUsersData = clsString::Split(line, Seperator);

		return ClsLoginRegister(vUsersData[0], vUsersData[1], vUsersData[2], vUsersData[3], stoi(vUsersData[4]));
	}
	
	static string _ConvertRegisterdDataToLineOfRecords(string Seperator = "#//#")
	{
		ClsUser CurrentUser = ClsUser::GetCurrentUser();


		string line = "";
		line += clsDate::DateToString(clsDate()) + Seperator;
		line += clsDate::GetCurrentTime() + Seperator;
		line += CurrentUser.GetUsername() + Seperator;
		line += CurrentUser.Password + Seperator;
		line += to_string(CurrentUser.Permission);
		
		return line;
	}
	
	static void _SaveDataToFile()
	{
		ofstream file("LoginRegester", ios::app);
		if (file.is_open())
		{
			file << _ConvertRegisterdDataToLineOfRecords() << endl;
		}
		file.close();
	}

	

	static vector<ClsLoginRegister> _LoadDataFromFile()
	{
		vector<ClsLoginRegister>_vUsers;
		ifstream file("LoginRegester");
		if (file.is_open())
		{
			string line = "";
			while (getline(file, line))
			{
				ClsLoginRegister U = _ConverLineToRegisterdDataObject(line);
				_vUsers.push_back(U);
			}
			file.close();
		}
		return _vUsers;
	}
	
	static vector<ClsLoginRegister> _SearchByUsername(string Username)
	{
		vector<ClsLoginRegister>vAllRegisterdData = _LoadDataFromFile();
		vector<ClsLoginRegister>FilterdData;
		for (auto const& U : vAllRegisterdData)
		{
			if (Username == U._CurrentUserName)
			{
				FilterdData.push_back(U);
			}
		}
		return FilterdData;
	}
	static vector<ClsLoginRegister> _SearchByDate(clsDate Date)
	{
		vector<ClsLoginRegister>vAllRegisterdData = _LoadDataFromFile();
		vector<ClsLoginRegister>FilterdData;

		for (auto const& U : vAllRegisterdData)
		{
			if (clsDate::DateToString(Date) == U._Date)
			{
				FilterdData.push_back(U);
			}
		}
		return FilterdData;
	}
	
public:
	ClsLoginRegister(string Date, string Time, string Username, string Password, short Permissions)
	{

		_Date=Date ;
		_Time=Time ;
		_CurrentUserName=Username ;
		_CurrentUserPassword= Password ;
		_CurrentUserpermissions = Permissions;

	}
	string GetDate()const
	{
		return _Date;
	}
	string GetTime()const
	{
		return _Time;
	}	
	string GetUsername()const
	{
		return _CurrentUserName;
	}

	 
	string GetPassword()const
	{
		return _CurrentUserPassword;
	}

	short GetPermissions()const
	{
		return _CurrentUserpermissions;
	}

	static void AddRegesterdDataToFile()
	{
		_SaveDataToFile();
	}
	static vector<ClsLoginRegister>GetUsersList()
	{
		return _LoadDataFromFile();
	}
	static vector<ClsLoginRegister>GetSearchByUsernameList(string Username)
	{
		return _SearchByUsername(Username);
	}
	static vector<ClsLoginRegister> GetSearchByDateList(clsDate Date)
	{
		return _SearchByDate(Date);
	}
};

