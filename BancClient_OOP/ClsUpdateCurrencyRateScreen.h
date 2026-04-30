#pragma once
#include"ClsScreen.h"
#include"ClsInputValidation.h"
#include"ClsCurrency.h"
class ClsUpdateCurrencyRateScreen:protected clsScreen
{
private:
	static void _PrintCurrencyInfo(ClsCurrency& C)
	{
		cout << "\n\Currency Info";
		cout << "\n==============================";
		cout << "\nCountry        : " << C.GetCountry();
		cout << "\nCurrency Name  : " << C.GetCurrencyName();
		cout << "\nCurrency Code  : " << C.GetCurrencyCode();
		cout << "\nCurrency Rate  : " << C.GetCurrencyRate();
	
		cout << "\n==============================\n";

	}
	static void _ReadNewRate(ClsCurrency &C)
	{
		string NewCurrencyRate;
		cout << " New Rate:";
		C.SetCurrencyRate(clsInputValidate::ReadDblNumber());
	}
public:
	static void UpdateCurrencyRateScreen()
	{
		clsScreen::_DrawScreenHeader("Update Currency Code Screen");

		cout << " Courrency Code = 1\n";
		cout << " Country        = 2\n";

		short Choice= clsInputValidate::ReadShortNumberBetween(1,2);
		switch (Choice)
		{
		case 1:
		{
				system("cls");
				clsScreen::_DrawScreenHeader("Update Currency Rate By Currency Code Screen");

				string CurrencyCode = "";

				cout << "Currency Code    : ";
				CurrencyCode = clsInputValidate::ReadString();

				while (!ClsCurrency::SearchByCurrencyCode(CurrencyCode))
				{
					cout << "\nInvalid Data Code(" << CurrencyCode << ") Not Found!\n\n";
					cout << "Currency Code    : ";


					CurrencyCode = clsInputValidate::ReadString();
					cout << "Password    : ";


				}
				ClsCurrency C = ClsCurrency::FindByCurrencyCode(CurrencyCode);
				_PrintCurrencyInfo(C);


				cout << "\n\tUpdate Data \n";
				cout << "==============================\n";
				_ReadNewRate(C);
				cout << "==============================\n";


				ClsCurrency::enSaveDataInFile Result;
				Result = C.Save();
				switch (Result)
				{
				case ClsUser::enSaveDataInFile::Faild:
				{
					cout << "Saved faild Empty object";
					break;
				}
				case ClsUser::enSaveDataInFile::UpdatedDataSavedSuccessfuly:
				{
					cout << "\Rate Updated Successfuly\n";
					_PrintCurrencyInfo(C);
					break;
				}
				}
				break;
		}
		case 2:
		{
			system("cls");
			clsScreen::_DrawScreenHeader("Update Currency Code By Country Screen");
				string Country = "";

				cout << "Currency Code    : ";
				Country = clsInputValidate::ReadString();

				while (!ClsCurrency::SearchByCountry(Country))
				{
					cout << "\nInvalid Data Code(" << Country << ") Not Found!\n\n";
					cout << "Currency Code    : ";


					Country = clsInputValidate::ReadString();
					cout << "Password    : ";


				}
				ClsCurrency C = ClsCurrency::FindByCountry(Country);
				_PrintCurrencyInfo(C);


				cout << "\n\tUpdate Data \n";
				cout << "==============================\n";
				_ReadNewRate(C);
				cout << "==============================\n";


				ClsCurrency::enSaveDataInFile Result;
				Result = C.Save();
				switch (Result)
				{
				case ClsUser::enSaveDataInFile::Faild:
				{
					cout << "Saved faild Empty object";
					break;
				}
				case ClsUser::enSaveDataInFile::UpdatedDataSavedSuccessfuly:
				{
					cout << "\Rate Updated Successfuly\n";
					_PrintCurrencyInfo(C);
					break;
				}
				}
				break;

		}
			
		}

		
	}

};

