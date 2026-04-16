#pragma once
#include<iostream>
#include <string>
#include<iomanip>
#include"ClsScreen.h"
#include"ClsBankClient.h"
#include"clsInputValidation.h"
//#include"ClsUser.h"
#include"ClsUsersListScreen.h"
#include"ClsAddUserScreen.h"
#include"ClsDeleteUserScreen.h"
#include"ClsUpdateUserScreen.h"
#include"ClsFindUserScreen.h"
#include"ClsLoginRegisterData.h"



class ClsMangeUsersMenuScreen:protected clsScreen
{
private:
    
    enum _enMangeUsersMenueOptions {
        eUsersList = 1, eAddUser = 2, eDeleteUser = 3, 
        eUpdateUser = 4,eFindUser=5, eShowLoginRegisterScreen = 6, eShowMainMenue = 7
    };

    static void _GoBackToMangeUsersMenue()
    {
        cout << "\n\nPress any key to go back to Mange Users Menue...";
        system("pause>0");
        ShowMangeUsersMenu();

    }
    static short _ReadMangeUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do?: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter Number between 1 to 6? ");
        return Choice;
    }
    
    static void _ShowUsersListScreen()
    {
        ClsUsersListScreen::UsersListScreen();
    }
    static void _ShowAddUserScreen()
    {
        ClsAddUserScreen::AddNewUserScreen();

    }
    static void _ShowDeleteUserScreen()
    {
        ClsDeletUserScreen::DeleteUserScreen();
    }
    static void _ShowUpdateUserScreen()
    {
        ClsUpdateUserScreen::UpdateUserScreen();
    }
    static void _ShowFindUserScreen()
    {
        ClsFindUserScreen::FindUserScreen();
    }
    static void _ShowLoginRegisterScreen()
    {
        ClsLoginRegisterData::ShowLoginRegisterDataScreen();
    }




    static void _PerforMangeUsersMenueOption(_enMangeUsersMenueOptions MangeUsersMenueOption)
    {
        switch (MangeUsersMenueOption)
        {
        case _enMangeUsersMenueOptions::eUsersList:
        {
            system("cls");
            _ShowUsersListScreen();
            _GoBackToMangeUsersMenue();
            break;
        }

        case _enMangeUsersMenueOptions::eAddUser:
        {
            system("cls");
            _ShowAddUserScreen();
            _GoBackToMangeUsersMenue();
            break;
        }

        case _enMangeUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToMangeUsersMenue();
            break;
        }

        case _enMangeUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToMangeUsersMenue();
            break;
        }

        case _enMangeUsersMenueOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToMangeUsersMenue();
            break;
        }


        case _enMangeUsersMenueOptions::eShowLoginRegisterScreen:
        {
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMangeUsersMenue();
            break;
        }

        case _enMangeUsersMenueOptions::eShowMainMenue:
        {
            //do no thing
        }
        }


    }



public:


    static void ShowMangeUsersMenu()
    {


        system("cls");
        _DrawScreenHeader("\t  Mange Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Mange Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Users List.\n";
        cout << setw(37) << left << "" << "\t[2] Add User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Login Register Screen.\n";
        cout << setw(37) << left << "" << "\t[7] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerforMangeUsersMenueOption((_enMangeUsersMenueOptions)_ReadMangeUsersMenueOption());
    }
};

