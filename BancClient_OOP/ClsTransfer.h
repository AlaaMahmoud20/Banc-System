#pragma once
#include"ClsString.h"
#include"ClsDate.h"
#include<ctime>
class ClsTransfer 
{

private:


		string _SourceAccountNumber;
		string _DestinationAccountNumber;

		float _SourceBlanceAfter;
		float _DestinationBlanceAfter;

		string _Username;     
		int _Permissions;     

		float _Amount;
		clsDate _Date;

	
	
	

	static ClsTransfer _ConvertLineToObject(string line, string Separator = "#//#")
	{
		vector<string> vTransfers = clsString::Split(line, Separator);
		return ClsTransfer(vTransfers[0], stof(vTransfers[1]), vTransfers[2], stof(vTransfers[3]), vTransfers[4], stof(vTransfers[5]), vTransfers[6], stoi(vTransfers[7]));
	}

	static string _ToLine(ClsTransfer &T,string Separator = "#//#")
	{
		clsDate Date;
		ClsUser CurrentUser = ClsUser::GetCurrentUser();
		string Line = "";

		Line += Date.GetFullCurrentDate(clsDate()) + Separator;
		Line += to_string(T.GetAmount()) + Separator;
		Line += T.GetSenderAccount() + Separator;
		Line += to_string(T.GetSenderBalanceAfter())+ Separator;
		Line += T.GetReceiverAccount() + Separator;
		Line += to_string(T.GetReciverBalanceAfter())+ Separator;
		Line += CurrentUser.GetUsername() + Separator;
		Line += to_string(CurrentUser.GetPermissions());

		return Line;
	}


   static  void _SaveDataToFile(ClsTransfer &T)
	{
		ofstream file("Transfers", ios::app);
		if (file.is_open())
		{
			file << _ToLine (T) <<endl;
			
		}
		file.close();
	}



    static vector<ClsTransfer> _LoadDataFromFile()
	{
		vector<ClsTransfer>_vTransfers;
		ifstream file("Transfers");
		if (file.is_open())
		{
			string line = "";
			while (getline(file, line))
			{
				ClsTransfer U = _ConvertLineToObject(line);
				_vTransfers.push_back(U);
			}
			file.close();
		}
		return _vTransfers;
	}

	//static vector<ClsLoginRegister> _SearchByUsername(string Username)
	//{
	//	vector<ClsLoginRegister>vAllRegisterdData = _LoadDataFromFile();
	//	vector<ClsLoginRegister>FilterdData;
	//	for (auto const& U : vAllRegisterdData)
	//	{
	//		if (Username == U._CurrentUserName)
	//		{
	//			FilterdData.push_back(U);
	//		}
	//	}
	//	return FilterdData;
	//}
	//static vector<ClsLoginRegister> _SearchByDate(clsDate Date)
	//{
	//	vector<ClsLoginRegister>vAllRegisterdData = _LoadDataFromFile();
	//	vector<ClsLoginRegister>FilterdData;

	//	for (auto const& U : vAllRegisterdData)
	//	{
	//		if (clsDate::DateToString(Date) == U._Date)
	//		{
	//			FilterdData.push_back(U);
	//		}
	//	}
	//	return FilterdData;
	//}

public:

	ClsTransfer() {};
	ClsTransfer(clsDate Date,float Amount,string SourceAcc,float SourceBlance, string DestAcc, float DestinationBlance,string Username, int Permissions)
	{
		_Date = Date;
		_Amount = Amount;

		_SourceAccountNumber = SourceAcc;
		_SourceBlanceAfter = SourceBlance;

		_DestinationAccountNumber = DestAcc;
		_DestinationBlanceAfter = DestinationBlance;


		_Username = Username;
		_Permissions = Permissions;
	}

	

	
	float GetAmount()const
	{
		return _Amount;
	}

	string GetSenderAccount() 
	{
		return _SourceAccountNumber;
	}

	float GetSenderBalanceAfter()
	{
		return _SourceBlanceAfter;
	}

	string GetReceiverAccount() 
	{
		return _DestinationAccountNumber;
	}

	float GetReciverBalanceAfter()
	{
		return _DestinationBlanceAfter;
	}

	string GetInChargeUserName() const
	{
		return _Username;
	}

	int GetPermissinos()
	{
		return _Permissions;
	}

	

	string GetDate() 
	{
		return _Date.GetDate();
	}


	//short GetPermissions()const
	//{
	//	return _UserPermissions;
	//}

  
   static void RegisterTransfer(ClsTransfer &T) // Remove 'static'
   {
	   _SaveDataToFile(T);
   }
    static vector<ClsTransfer>GetTransfersList()
	{
		return _LoadDataFromFile();
	}
	//static vector<ClsLoginRegister>GetSearchByUsernameList(string Username)
	//{
	//	return _SearchByUsername(Username);
	//}
	//static vector<ClsLoginRegister> GetSearchByDateList(clsDate Date)
	//{
	//	return _SearchByDate(Date);
	//}
};


