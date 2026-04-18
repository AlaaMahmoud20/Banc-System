#pragma once
#include <string>
#include "ClsString.h"
#include "ClsUtile.h"
#include"ClsBankClient.h"
#include"ClsInputValidation.h""

using namespace std;

class ClsCurrency
{
private:
	string _Country;
	string _CurrencyName;
	string _CurrencyCode;
	float _Rate;
	enum _eMode { Empty = 0, Update=1 };

	_eMode _Mode;



	static ClsCurrency _CurrencyDataToObject(string line, string Seperator = "#//#")
	{
		vector<string>vCurrencesData = clsString::Split(line, Seperator);

		return ClsCurrency(_eMode::Update, vCurrencesData[0], vCurrencesData[1], vCurrencesData[2],stof(vCurrencesData[3]));
	}
	static ClsCurrency _EmptyObject()
	{
		return ClsCurrency(_eMode::Empty, " ", " ", " ", 0);
	}

	static string ToLine(ClsCurrency& C, string Seperator = "#//#")
	{
		string line = "";
		line += C._Country + Seperator;
		line += C._CurrencyCode + Seperator;
		line += C._CurrencyName + Seperator;
		line += to_string(C._Rate) + Seperator;
		
		return line;
	}
	static void _SaveUserDataToFile(vector<ClsCurrency>& _vCurrences)
	{
		ofstream file("Currencies.txt");
		if (file.is_open())
		{
			for (auto& C : _vCurrences)
			{
				file << ToLine(C) << endl;
			
			}
			file.close();
		}
	}

	static vector<ClsCurrency> _LoadDataFromFile()
	{
		vector<ClsCurrency>vCurrences;
		ifstream file("Currencies.txt");
		if (file.is_open())
		{
			string line = "";
			while (getline(file, line))
			{
				ClsCurrency C = _CurrencyDataToObject(line);
				vCurrences.push_back(C);
			}
			file.close();
		}
		return vCurrences;
	}

	void _Update()
	{
		vector<ClsCurrency>_vCurrences = _LoadDataFromFile();
		for (auto& C : _vCurrences)
		{
			if (C._CurrencyName == GetCurrencyName())
			{
				C = *this;
				break;
			}
		}
		_SaveUserDataToFile(_vCurrences);
	}



public:

	ClsCurrency(_eMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	static ClsCurrency Find(string CurrencyCode)
	{
		ifstream file("UF");
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				ClsCurrency C = _CurrencyDataToObject(line);

				if (C.GetCurrencyCode() == CurrencyCode)
				{
					file.close();
					return C;
				}

			}

		}
		return _EmptyObject();

	}

	string GetCountry()const
	{
		return _Country;
	}
	string GetCurrencyName()const
	{
		return _CurrencyName;
	}
	string GetCurrencyCode()const
	{
		return _CurrencyCode;
	}
	void SetCurrencyRate(float Rate)
	{
		_Rate = Rate;
	}
	float GetCurrencyRate()
	{
		return _Rate;
	}
	__declspec(property(get = GetCurrencyRate, put = SetCurrencyRate))float Rate;

	static vector<ClsCurrency>GetCurrencesList()
	{
		return _LoadDataFromFile();
	}

	enum enSaveDataInFile { UpdatedDataSavedSuccessfuly = 0, Faild = 1, };
	enSaveDataInFile Save()
	{
		switch (_Mode)
		{
		case _eMode::Empty:
		{
			return enSaveDataInFile::Faild;
			break;
		}
		case _eMode::Update:
		{
			_Update();
			return enSaveDataInFile::UpdatedDataSavedSuccessfuly;
			break;

		}
		/*case _enMode::AddNewMode:
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
			}*/


		}

	};


};
