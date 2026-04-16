#pragma once
#include<iostream>
#include"ClsPerson.h"
#include"ClsString.h"
#include<fstream>
#include<string>

class ClsBankClient :public clsPerson
{
private:

	string _AccountNumber;
	string _Password;
	double _Balance;
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
	static ClsBankClient _ConverLineToClientObject(string line, string Seperator="#//#")
	{
		vector<string>VClientData = clsString::Split(line, Seperator);

		return ClsBankClient(_enMode::UpdateMode, VClientData[0], VClientData[1], VClientData[2],
			VClientData[3], VClientData[4], VClientData[5], VClientData[6], stod(VClientData[7]));
	}
	static ClsBankClient _EmptyClientObject()
	{
		return ClsBankClient(_enMode::EmptyMode, " ", " ", " ", " ", " ", " ", " ", 0);
	}
	static string _ConvertClientDataToLineOfRecords(ClsBankClient &Client, string Seperator = "#//#")
	{
		string line = "";
		line += Client.FirstName + Seperator;
		line += Client.LastName + Seperator;
		line += Client.Email + Seperator;
		line += Client.Phone + Seperator;
		line += Client.Gender+ Seperator;
		line += Client._AccountNumber + Seperator;
		line += Client._Password + Seperator;
		line += to_string(Client._Balance) ;
		return line;
	}
	static void _SaveClientDataToFile(vector<ClsBankClient> &_VClients)
	{
		ofstream file("PF");
		if (file.is_open())
		{
			for (auto & C : _VClients)
			{
				if (!C.Flage)
				{
					file << _ConvertClientDataToLineOfRecords(C) << endl;
				}
			}
			file.close();
		}
	}
	static void _SaveClientDataToFile_AddNew_(string line)
	{
		ofstream file("PF",ios::app);
		if (file.is_open())
		{
			file << line << endl;
		}
			file.close();
	}
	static vector<ClsBankClient> _LoadDataFromFile()
	{
		vector<ClsBankClient>_VClients;
		ifstream file("PF");
		if (file.is_open())
		{
			string line = "";
			while (getline(file, line))
			{
				ClsBankClient C = _ConverLineToClientObject(line);
				_VClients.push_back(C);
			}
			file.close();
		}
		return _VClients;
	}
	 void _AddNew()
	 {
		_SaveClientDataToFile_AddNew_(_ConvertClientDataToLineOfRecords(*this));
	 }
	void _Delete()
	{
		vector<ClsBankClient>_VClients = _LoadDataFromFile();
		for (auto& C : _VClients)
		{
			if (C._AccountNumber == _AccountNumber)
			{
				C.Flage = true;
				break;
			}
		}
		_SaveClientDataToFile(_VClients);
		*this = _EmptyClientObject();
	}
	void _Update()
	{
		vector<ClsBankClient>_VClients = _LoadDataFromFile();
		for (auto& C : _VClients)
		{
			if (C._AccountNumber == _AccountNumber)
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_VClients);
	}
	 bool _Transfer(float Amount,ClsBankClient &DestenationClient)
	{
		if (Withdraw(Amount))
		{
			DestenationClient.Deposit(Amount);
			return true;
		}
		return false;
	}

public:

	static void SaveDataToFile(vector<ClsBankClient>&Clients)
	{
		_SaveClientDataToFile(Clients);
	
	}
	static vector<ClsBankClient>GetClientsList()
	{
		return _LoadDataFromFile();
	}
	static double GetTotalBalance()
	{
		vector<ClsBankClient>vClients = GetClientsList();
		double totalBalance = 0;
		for (auto& C : vClients)
		{
			totalBalance += C.Balance;
		}
		return totalBalance;

	}
	static ClsBankClient Find(string AccountNumber)
	{
		ifstream file("PF");
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				ClsBankClient Client = _ConverLineToClientObject(line);
				if (Client._AccountNumber == AccountNumber)
				{
					file.close();
					return Client;
				}

			}

		}
		return _EmptyClientObject();

	}
	static ClsBankClient Find(string AccountNumber, string Password)
	{
		ifstream file("PF");
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				ClsBankClient Client = _ConverLineToClientObject(line);
				if (Client._AccountNumber == AccountNumber && Client._Password == Password)
				{
					file.close();
					return Client;
				}

			}

		}
		return _EmptyClientObject();

	}
	static bool IsClientExist(string AccountNumber)
	{
		ClsBankClient C = Find(AccountNumber);
		return !(C.IsEmpty());
	}
	static ClsBankClient _NewClientObject(string AccountNumber)
	{
		return ClsBankClient(_enMode::AddNewMode, "", "", "", "", "", AccountNumber, "", 0);
	}

	ClsBankClient();
	ClsBankClient(_enMode Mode,string FirstName, string LastName, string Email,string Phone,string  Gender,
		 string Acc_Number, string Password, double Balance) :
		clsPerson(FirstName, LastName, Email, Phone, Gender)
	{
		_Mode = Mode;
		_AccountNumber = Acc_Number;
		_Password = Password;
		_Balance = Balance;
	}
	
	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string  GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	void SetBalance(double Balance)
	{
		_Balance = Balance;
	}
	double GetBalance()
	{
		return _Balance;
	}
	__declspec(property(get = GetBalance, put = SetBalance))double Balance;

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
			_Delete();
			_SetMode(_enMode::UpdateMode);

			return enSaveDataInFile::DataDeletedSuccessfuly;
		}
		}
	}
	void Deposit(double Amount)
	{
		_Balance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _Balance)return false;
		else
		{
			_Balance -= Amount;
			Save();
			return true;
		}
	}
	void MarkForDelete()
	 {
		_Mode = _enMode::DeleteMode;
	 }
    bool Transfer(float Amount, ClsBankClient& DenstenationClient)
	{
		return _Transfer(Amount,DenstenationClient);
	}

	 bool IsEmpty()
	 {
		 return (_Mode == _enMode::EmptyMode);
	 }
	static void Clear()
	 {
		 ofstream file("PF");
		 if (file.is_open())
		 {
			 file.close();
		 }
	 }

};

