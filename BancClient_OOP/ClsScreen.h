#pragma once

#include"ClsUser.h"
#include"ClsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\n________________________________________________________________________________________________________________________";
        cout << "\n\n\t\t\t\t\t " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n________________________________________________________________________________________________________________________";

        cout << "\n\t\t\t\t\t_______________________________\n\n";

        ClsUser CurrentUser = ClsUser::GetCurrentUser();
        clsDate CurrentDate = clsDate::GetSystemDate();
        cout << "\t\t\t\t\t\tUser: " << CurrentUser.GetUsername() << "\n";
        cout << "\t\t\t\t\t\tDate: " << clsDate::DateToString(CurrentDate);
        cout << "\n\t\t\t\t\t_______________________________\n\n";

    }
   
    static void AccessDeniedMessage()
    {
        cout << "\t\t\n-----------------------------------------\n";
        cout << "\t\tAccess Denied \n\tplease conact your admin\n";
        cout << "\t\t\n-----------------------------------------\n";
    }


};



