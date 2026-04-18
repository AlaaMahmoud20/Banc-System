#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidation.h"
#include "ClsCurrenciesList.h"

class ClsCurrenciesScreen:protected clsScreen
{
private:
    enum enCurrencyMenueOptions {
        eCurrenciesList = 1, eBcak = 2
    };

    static short _ReadCurrencyMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do?: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 4? ");
        return Choice;
    }
    static void _GoBackToCurrencyMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowCurrencyMenue();

    }

    static void _ShowCurrenciesListScreen()
    {
        ClsCurrenciesList::CurrencesListScreen();
    }


    static void _PerformCurrencyMenueOption(enCurrencyMenueOptions CurrencyMenuOptions)
    {
        switch (CurrencyMenuOptions)
        {
            case enCurrencyMenueOptions::eCurrenciesList:
            {
                system("cls");
                _ShowCurrenciesListScreen();
                _GoBackToCurrencyMenue();
                break;
            }
            case enCurrencyMenueOptions::eBcak:
            {
                
              
            }

        //case enTransactionsMenueOptions::eWithdraw:
        //{
        //    system("cls");
        //    _ShowWithdrawScreen();
        //    _GoBackToTransactionsMenue();
        //    break;
        //}

        //case enTransactionsMenueOptions::eShowTotalBalance:
        //{
        //    system("cls");
        //    _ShowTotalBalancesScreen();
        //    _GoBackToTransactionsMenue();
        //    break;
        //}



        //case enTransactionsMenueOptions::eMoneyTransfer:
        //{
        //    system("cls");
        //    _ShowTransferScreen();
        //    _GoBackToTransactionsMenue();
        //    break;
        //}

        //case enTransactionsMenueOptions::eTransfersList:
        //{
        //    system("cls");
        //    _ShowTransfersList();
        //    _GoBackToTransactionsMenue();
        //    break;
        //}

        //case enTransactionsMenueOptions::Bcak:
        //{
        //    //do no thing
        //}
        }


    }
public:
    static void ShowCurrencyMenue()
    {


        system("cls");
        _DrawScreenHeader("\t Currency Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Currencies List.\n";
        cout << setw(37) << left << "" << "\t[2] Back.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyMenueOption((enCurrencyMenueOptions)_ReadCurrencyMenueOption());
    }

};
