#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidation.h"
#include "ClsDepositScreen.h"
#include "ClsWithdrawScreen.h"
#include "ClsTotalBalanceScreen.h"
#include "ClsTransferScreen.h"
#include "ClsTransfersList.h"
//#include "ClsMainMenu.h"

using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eMoneyTransfer = 4,eTransfersList=5, Bcak = 6
    };


    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do?: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 4? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        ClsDepositScreen::DepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        ClsWithdrawScreen::WithdrawSceen();
    }

    static void _ShowTotalBalancesScreen()
    {
        ClsTotalBalanceScreen::TotalBalanceScreen();
    }
    static void _ShowTransferScreen()
    {
        ClsTransferScreen::TransferScreen();
    }
    static void _ShowTransfersList()
    {
        ClsTransfersList::TransfersListScreen();
    }
    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }


    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }



        case enTransactionsMenueOptions::eMoneyTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransfersList:
        {
            system("cls");
            _ShowTransfersList();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::Bcak:
        {
            //do no thing
        }
        }


    }



public:


    static void ShowTransactionsMenue()
    {


        system("cls");
       _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfers List.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};



