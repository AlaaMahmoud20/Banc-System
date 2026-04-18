#pragma once
#include <string>
#include"ClsCurrency.h"
#include"ClsUtile.h"
#include"ClsScreen.h"
#include<iomanip>
class ClsCurrenciesList:protected clsScreen
{
private:
	static void _PrintUserRecordLine(ClsCurrency& C)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << C.GetCountry();
		cout << "| " << setw(20) << left << C.GetCurrencyCode();
		cout << "| " << setw(40) << left << C.GetCurrencyName();
		cout << "| " << setw(10) << left << C.Rate;
	}
public:
	static void CurrencesListScreen()
	{
		vector <ClsCurrency> Currencies = ClsCurrency::GetCurrencesList();
		string Title = "\tCurrencies List Screen\n";
		string SupTilel = "\t  (" + (to_string(Currencies.size())) + ") Currency(ies).";
		clsScreen::_DrawScreenHeader(Title, SupTilel);

		cout <<
			"\n\t_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
		cout << "| " << left << setw(20) << "CCode";
		cout << "| " << left << setw(40) << "CName";
		cout << "| " << left << setw(10) << "CRate";


		cout <<
			"\n\t__________________________________________________________";
		cout << "_____________________________________________________\n" << endl;
		if (Currencies.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else
			for (auto& C : Currencies)
			{
				_PrintUserRecordLine(C);
				cout << endl;
			}
		cout <<
			"\n\t__________________________________________________________";
		cout << "_____________________________________________________\n" << endl;
	}
};
	
	


