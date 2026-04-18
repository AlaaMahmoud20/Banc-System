#pragma once
#include<iostream>
#include<iomanip>
#include"ClsScreen.h"
#include"ClsUser.h"
#include"ClsInputValidation.h"
#include"ClsClientsListScreen.h"
#include"ClsAddClientScreen.h"
#include"ClsDeleteClientScreen.h"
#include"ClsUpdateClientScreen.h"
#include"ClsFindClientScreen.h"
#include"ClsTransactionMenuScreen.h"
#include"ClsMangeUsersMenuScreen.h"
#include"ClsClearClientsScreen.h"
#include"ClsCurrenciesScreen.h"
//class ClsLoginScreen;

using namespace std;

class ClsMainMenu :protected clsScreen
{
private:


    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eCurrency = 8, eClearClients = 9,eLogout = 10
    };
    static int _ReadMainMenueOption()
    {
        cout << "\n\t\t\t\t\tChoose what do you want to do : ";
        return clsInputValidate::ReadShortNumberBetween(1, 10);
    }
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenue();
    }
    static void _ShowClientListScreen()
    {
         ClsClientsListScreen::ClientsListScreen();
    }
    static void _ShowAddNewClientScreen()
    {
        ClsAddClientScreen::AddNewclientScreen();
    }
    static void _ShowDeleteClientScreen()
    {
        ClsDeleteClientScreen::DeleteClientScreen();
        
    }
    static void _ShowUpdateClientScreen()
    {
        ClsUpdateClientScreen::UpdateClientScreen();
    }
    static void _ShowFindClientScreen()
    {
        ClsFindClientScreen::FindClientScreen();
    }
    static void _ShowFindTransactionMenuScreen()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }
    static void _ShowMangeUsersMenuScreen()
    {
        ClsMangeUsersMenuScreen::ShowMangeUsersMenu();
    }
    static void _ShowClearClientsScreen()
    {
        ClsClearClientsScreen::ClearClientScreen();
    }
    static void _ShowCurrencyScreen()
    {
        ClsCurrenciesScreen::ShowCurrencyMenue();
    }
    //static void _ShowLoginScreen();

    
    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        ClsUser CurrentUser = ClsUser::GetCurrentUser();
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            if (CurrentUser._HasPermission(ClsUser::enPermissons::show_clients_lilst))
            {
                system("cls");
                _ShowClientListScreen();
                _GoBackToMainMenue();
            }
            else
            {
                system("cls");
                AccessDeniedMessage();
                _GoBackToMainMenue();

            }

                break;


        }
        case enMainMenueOptions::eAddNewClient:
        {

            if (CurrentUser._HasPermission(ClsUser::enPermissons::add_client))
            {
                system("cls");
                _ShowAddNewClientScreen();
                _GoBackToMainMenue();
            }
            else
            {
                system("cls");
                AccessDeniedMessage();
                _GoBackToMainMenue();

            }

                break;
        }


        case enMainMenueOptions::eDeleteClient:
        {
            if (CurrentUser._HasPermission(ClsUser::enPermissons::delete_client))
            {
                system("cls");
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();

            }
            else
            {
                system("cls");
                AccessDeniedMessage();
                _GoBackToMainMenue();

            }

                break;
        }

        case enMainMenueOptions::eUpdateClient:
        {
            if (CurrentUser._HasPermission(ClsUser::enPermissons::update_client))
            {

                system("cls");
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();

            }
            else
            {
                system("cls");
                AccessDeniedMessage();
                _GoBackToMainMenue();

            }

                break;
        }

        case enMainMenueOptions::eFindClient:
        {
            if (CurrentUser._HasPermission(ClsUser::enPermissons::find_client))
            {
                system("cls");
                _ShowFindClientScreen();
                _GoBackToMainMenue();

            }

            else
            {
                system("cls");
                AccessDeniedMessage();
                _GoBackToMainMenue();

            }

                break;
        }
        case enMainMenueOptions::eShowTransactionsMenue:
        {
            if (CurrentUser._HasPermission(ClsUser::enPermissons::transaction_menu))
            {
                system("cls");
                _ShowFindTransactionMenuScreen();
                _GoBackToMainMenue();


            }
            else
            {
                system("cls");
                AccessDeniedMessage();
                _GoBackToMainMenue();

            }

                break;
        }
        case enMainMenueOptions::eManageUsers:
        {

            if (CurrentUser._HasPermission(ClsUser::enPermissons::mange_users))
            {

                system("cls");
                _ShowMangeUsersMenuScreen();
                _GoBackToMainMenue();

            }
            else
            {
                system("cls");
                AccessDeniedMessage();
                _GoBackToMainMenue();

            }

             break;
        }
        case enMainMenueOptions::eCurrency:
        {

            if (CurrentUser._HasPermission(ClsUser::enPermissons::currency_menu))
            {

                system("cls");
                _ShowCurrencyScreen();
                _GoBackToMainMenue();

            }
            else
            {
                system("cls");
                AccessDeniedMessage();
                _GoBackToMainMenue();

            }

            break;
        }


        case enMainMenueOptions::eClearClients :
        {

            if (CurrentUser._HasPermission(ClsUser::enPermissons::clear_all_Client))
            {

                system("cls");
                _ShowClearClientsScreen();
                _GoBackToMainMenue();

            }
            else
            {
                system("cls");
                AccessDeniedMessage();
                _GoBackToMainMenue();

            }

            break;
        }



        case enMainMenueOptions::eLogout:
        {
            if (CurrentUser._HasPermission(ClsUser::enPermissons::logout))
            {

                {
                    system("cls");
                    //_ShowLoginScreen();=> From Call Stack =>(MainFunction) Because Class Login Screen Alwase 
                    // true so will still runing forever

                }

            }
            else
            {
                system("cls");
                AccessDeniedMessage();
                _GoBackToMainMenue();

            }

          break;
        }
       


        };

    }

public:
	
        static void ShowMainMenue()
        {
            ClsUser CurrentUser = ClsUser::GetCurrentUser();


            system("cls");
            _DrawScreenHeader("\tMain Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
         
            
            CurrentUser._HasPermission(ClsUser::enPermissons::show_clients_lilst) ?
                cout << setw(37) << left << "" << "\t[1] Clients List.\n" :
                cout << setw(37) << left << "" << "\t[1] Clients List.                     (X)\n";
                                                                                          
                                                                                          
                                                                                          
                                                                                          
             CurrentUser._HasPermission(ClsUser::enPermissons::add_client)?               
                 cout << setw(37) << left << "" << "\t[2] Add Client.\n" :                
                 cout << setw(37) << left << "" << "\t[2] Add Client.                      (X)\n";
                                                                                          

             CurrentUser._HasPermission(ClsUser::enPermissons::delete_client) ?
                 cout << setw(37) << left << "" << "\t[3] Delete Client.\n" :
                 cout << setw(37) << left << "" << "\t[3] Delete Client.                   (X)\n";


            

             CurrentUser._HasPermission(ClsUser::enPermissons::update_client) ?
                 cout << setw(37) << left << "" << "\t[4] Update Client Info.\n" :
                 cout << setw(37) << left << "" << "\t[4] Update Client Info.              (X)\n";



             CurrentUser._HasPermission(ClsUser::enPermissons::find_client) ?
                 cout << setw(37) << left << "" << "\t[5] Find Client.\n" :
                 cout << setw(37) << left << "" << "\t[5] Find Client.                     (X)\n";

      

            CurrentUser._HasPermission(ClsUser::enPermissons::transaction_menu)?
                cout << setw(37) << left << "" << "\t[6] Transactions.\n":
                cout << setw(37) << left << "" << "\t[6] Transactions.                     (X)\n";
             

            CurrentUser._HasPermission(ClsUser::enPermissons::mange_users)?
                cout << setw(37) << left << "" << "\t[7] Manage Users.\n":
                cout << setw(37) << left << "" << "\t[7] Manage Users.                     (X)\n";
            



            CurrentUser._HasPermission(ClsUser::enPermissons::currency_menu) ?
                cout << setw(37) << left << "" << "\t[8] Currency.\n" :
                cout << setw(37) << left << "" << "\t[8] Currency.                         (X)\n";




            CurrentUser._HasPermission(ClsUser::enPermissons::clear_all_Client) ?
                cout << setw(37) << left << "" << "\t[9] Clear.\n" :
                cout << setw(37) << left << "" << "\t[9] Clear.                            (X)\n";





            CurrentUser._HasPermission(ClsUser::enPermissons::logout)?
                cout << setw(37) << left << "" << "\t[10] Logout.\n":
                cout << setw(37) << left << "" << "\t[10] Logout.                           (X)\n";
            

            cout << setw(37) << left << "" << "===========================================\n";

             _PerfromMainMenueOption(enMainMenueOptions(_ReadMainMenueOption()));
        }
};

