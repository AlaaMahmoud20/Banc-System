#pragma once
#include"ClsLoginRegister.h"
#include"ClsScreen.h"
#include"ClsInputValidation.h"
#include"ClsDate.h"
#include<iomanip>

class ClsSearchByDateScreen :protected clsScreen
{
private:
	static void _PrintRegisterdUserRecordLine(ClsLoginRegister& User)
	{
		cout << setw(8) << left << "" << "| " << setw(20) << left << User.GetDate();
		cout << "| " << setw(17) << left << User.GetTime();
		cout << "| " << setw(12) << left << User.GetUsername();
		cout << "| " << setw(15) << left << User.GetPassword();
		cout << "| " << setw(15) << left << User.GetPermissions();
	}

public:

	static void LoginRegisterListScreen()
	{
		string Title = "Search By Date Screen\n";
		clsScreen::_DrawScreenHeader(Title);

		clsDate Date;
		short day, month, year;
		cout << "\tDay   : ";
		cin >> day;

		cout << "\tMonth : ";
		cin >> month;

		cout << "\tYear  : ";
		cin >> year;

		Date.Day = day;
		Date.Month = month;
		Date.Year = year;

		while(!clsDate::IsValidDate(Date))
		{
			cout << "\nInvalid Date\n\n";
			cout << "\tDay    : ";
			cin >> day;

			cout << "\tMonth  : ";
			cin >> month;

			cout << "\tYear   : ";
			cin >> year;

			Date.Day = day;
			Date.Month = month;
			Date.Year = year;
		}

		vector <ClsLoginRegister> vUsers = ClsLoginRegister::GetSearchByDateList(Date);


		cout <<
			"\n\t_______________________________________________________";
		cout << "________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(20) << left << "Date ";
		cout << "| " << left << setw(17) << "Time";
		cout << "| " << left << setw(12) << "Username";
		cout << "| " << left << setw(15) << "Password";
		cout << "| " << left << setw(15) << "Permissions";
		cout <<
			"\n\t_______________________________________________________";
		cout << "________________________________________\n" << endl;
		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Login Register Data Available In the System!";
		else
			for (auto& U : vUsers)
			{
				_PrintRegisterdUserRecordLine(U);
				cout << endl;
			}
		cout <<
			"\n\t_______________________________________________________";
		cout << "________________________________________\n\n" << endl;
	}
};

