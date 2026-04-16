#pragma once

#include"ClsScreen.h"
#include"ClsAllLoginRegisterDataScreen.h"
#include"ClsSearchByUsernameScreen.h"
#include"ClsSearchByDateScreen.h"
#include<iomanip>



class ClsLoginRegisterData:protected clsScreen
{
private:
    enum _enLoginRegisterOptions {
        eShowAllLoginRecords = 1, eSearchbyUsername = 2
        , eSearchbyDate = 3,   eBack = 4
    };





    static void _GoBackLoginRegisterDataScreen()
    {
        cout << "\n\nPress any key to go back ...";
        system("pause>0");
        ShowLoginRegisterDataScreen();

    }
    static short _ReadLoginRegisterDataMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do?: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowLoginRegisterDataListScreen()
    {
        ClsAllLoginRegisterDataScreen::LoginRegisterListScreen();
    }
    static void _ShowSearchByUsernameScreen()
    {
        ClsSearchByUsernameScreen::LoginRegisterListScreen();

    }
    static void _ShowSearchByDateScreen()
    {
        ClsSearchByDateScreen::LoginRegisterListScreen();
    }
  




    static void _PerforMangeUsersMenueOption(_enLoginRegisterOptions LoginDataOptions)
    {
        switch (LoginDataOptions)
        {
        case _enLoginRegisterOptions::eShowAllLoginRecords:
        {
            system("cls");
            _ShowLoginRegisterDataListScreen();
            _GoBackLoginRegisterDataScreen();
            break;
        }

        case _enLoginRegisterOptions::eSearchbyUsername:
        {
            system("cls");
            _ShowSearchByUsernameScreen();
            _GoBackLoginRegisterDataScreen();
            break;
        }

        case _enLoginRegisterOptions::eSearchbyDate:
        {
            system("cls");
            _ShowSearchByDateScreen();
            _GoBackLoginRegisterDataScreen();
            break;
        }

        case _enLoginRegisterOptions::eBack:
        {
            //system("cls");
            //_GoBackLoginRegisterDataScreen();
            break;
        }


        }
    };


public:
    static void ShowLoginRegisterDataScreen()
    {


        system("cls");
        _DrawScreenHeader("\tLogin Register Data Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tLogin Register Data Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] All Logins.\n";
        cout << setw(37) << left << "" << "\t[2] Seacrh By Username.\n";
        cout << setw(37) << left << "" << "\t[3] Seacrh By Date.\n";
        cout << setw(37) << left << "" << "\t[4] Back.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerforMangeUsersMenueOption((_enLoginRegisterOptions)_ReadLoginRegisterDataMenueOption());
    }
};

