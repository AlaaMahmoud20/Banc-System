#include<iostream>
#include<iomanip>
#include"ClsString.h"
#include"ClsBankClient.h"
#include"ClsInputValidation.h"
#include"ClsUtile.h"
#include"ClsMainMenu.h"
#include "ClsUser.h"
#include "ClsLoginScreen.h"
ClsUser ClsUser::_CurrentUser;


using namespace std;
/*


struct Users {
	string UserName;
	string Password;
	int Permissons = 0;
	bool Mark = false;

	string ToLine(Users U, string Delimiter)const
	{
		return U.UserName + Delimiter + U.Password + Delimiter + to_string(U.Permissons);
	}
	Users GetRecords(string line)
	{
		Users user;
		vector<string>UserRecords = clsString::Split(line, "#//#");
		user.UserName = UserRecords[0];
		user.Password = UserRecords[1];
		user.Permissons = stoi(UserRecords[2]);
		return user;
	}
};

void ShowMangeUserMenue(Users& user);
void login();
void ShowMainMenue( Users& user);
void ShowTransactionMenue(Users& user);


static string fileName = "PF";
static string USersFile= "UF_New";
struct BankClient {
	string AcountNumber;
	string PinCode;
	string Name;
	string Phone;
	string Email;
	float AccountBalance;
	bool Mark = false;

	string ToLine(BankClient C,string Delimiter)const
	{

		return C.Name + Delimiter + C.Phone + Delimiter +
			C.Email + Delimiter+ C.PinCode + Delimiter+
			C.AcountNumber + Delimiter + to_string(C.AccountBalance);
	}

	BankClient GetRecords(string line)
	{
		BankClient Client;
		vector<string>ClientRecords = clsString::Split(line, "#//#");
		Client.Name = ClientRecords[0];
		Client.Phone = ClientRecords[1];
		Client.Email = ClientRecords[2];
		Client.PinCode = ClientRecords[3];
		Client.AcountNumber = ClientRecords[4];
		Client.AccountBalance = stod(ClientRecords[5]);
		return Client;
	}

};

void AccessDeniedMessage()
{
	cout << "\n-----------------------------------------\n";
	cout << " U have no permission to do that \nplease conact your admin\n";
	cout << "\n-----------------------------------------\n";
}
enum enMainManuChoices {
	ShowClientList = 1, AddNewClient = 2, deleteClient = 3, updateClient = 4,
	findClient = 5, transaction = 6, mangeusers = 7, clear_all_clients = 8, logut = 9
};
enum enTransacionManuChoices
{
	withdraw = 1, deposite = 2,
	totalBalance = 3, main_menu = 4

};
enum enMangeUsersMenu
{
	show_users_screen = 1, adduser = 2, deletuser = 3, udateuser = 4, maninmenu = 5

};
enum enPermissons
{
	show_clients_lilst = 1 << 0,
	add_client = 1 << 1,
	delete_client = 1 << 2,
	update_client = 1 << 3,
	find_client = 1 << 4,
	transaction_menu = 1 << 5,
	mange_users = 1 << 6,
	clear_all_Client = 1 << 7

};


void GivePermission(Users & user, enPermissons Permission)
{

	if (Answer() == 'y')
	{
		user.Permissons|= Permission;
	}
}

bool HasPermission(Users& user, enPermissons permission)
{
	return (user.Permissons & permission) == permission;
}


string GetAccountNumber()
{
	string AccountNumber;
	cout << "Account Number :  ";
	cin >> AccountNumber;
	return AccountNumber;
}


string GetUserName()
{
	string username;
	cout << "Username :  ";
	cin >> username;


	return username;
}
string GetPassword()
{
	string pssword;
	cout << "Pssword  :  ";
	cin >> pssword;


	return pssword;
}

short GetMainMenuChoice()
{
	cout << "\tChoose What do U Want To Do:  ";
	return clsInputValidate::ReadIntNumberBetween(1, 9);
}
short GetTransactionMenuChoice()
{
	cout << "\tChoose What do U Want To Do:  ";
	return clsInputValidate::ReadIntNumberBetween(1, 4);
}
short GetMangeUsersMenuChoice()
{
	cout << "\tChoose What do U Want To Do:  ";
	return clsInputValidate::ReadIntNumberBetween(1, 5);
}
void GoBackToMainMenue(Users &user)
{

	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenue(user);
}
void GoBackToTransacionMenue(Users& user)
{

	cout << "\n\nPress any key to go back to transacion Menue...";
	system("pause>0");
	ShowTransactionMenue(user);
}
void GoBackToMangeUsersMenue(Users& user)
{

	cout << "\n\nPress any key to go back to transacion Menue...";
	system("pause>0");
	ShowMangeUserMenue(user);
}



BankClient FillClientDate()
{
	BankClient ClientData;
	cout << "\n\nFull Name   :";
	getline(cin >> ws, ClientData.Name);

	cout << "Phone           :";
	getline(cin, ClientData.Phone);

	cout << "Email           :";
	getline(cin, ClientData.Email);

	cout << "Pin code        :";
	getline(cin, ClientData.PinCode);

	cout << "Account Number  :";
	getline(cin, ClientData.AcountNumber);

	cout << "Account Balance :";
	cin >> ClientData.AccountBalance;

	return ClientData;
}
Users FillUserDate()
{
	Users user;
	cout << "\n\nUser name :";
	getline(cin>>ws, user.UserName);

	cout << " Password       :";
	getline(cin, user.Password);

	cout << "do U want to allow this user to have full access? [y/n] ";
	if (Answer() == 'y')
	{
		user.Permissons = 255;

	}
	else
	{
		cout << "\n\n\t\tSet permissions:\n\n ";

		cout << "Show Clients list? [y/n]: ";
		GivePermission(user, enPermissons::show_clients_lilst);

		cout << "Add Client? [y/n]        : ";
		GivePermission(user, enPermissons::add_client);


		cout << "Delete Client? [y/n]     : ";
		GivePermission(user, enPermissons::delete_client);


		cout << "Update Client? [y/n]     : ";
		GivePermission(user, enPermissons::update_client);


		cout << "Find Client? [y/n]       : ";
		GivePermission(user, enPermissons::find_client);


		cout << "Transaction Menu? [y/n]  : ";
		GivePermission(user, enPermissons::transaction_menu);


		cout << "Mange Users Client? [y/n]: ";
		GivePermission(user, enPermissons::mange_users);


		cout << "Clear All Clients? [y/n] : ";
		GivePermission(user, enPermissons::clear_all_Client);

	}

	return user;
}
vector<BankClient> AddClientData()
{
	vector< BankClient>items;
	do
	{
		items.push_back(FillClientDate());
		cout << "\nClient Added Successfully.\n";

		cout << "\ndo U want to add another Client? [y/n]: ";
	} while (Answer()=='y');

	return items;
}
vector<Users> AddUserData()
{
	vector< Users>items;
	do
	{

		items.push_back(FillUserDate());
		cout << "\nClient Added Successfully.\n";

		cout << "\ndo U want to add another Client? [y/n]: ";
	} while (Answer() == 'y');

	return items;
}

template<typename T>
void SaveDataToFileAfterAdding(const vector<T>& items,string FN)
{

	ofstream file(FN,ios::app);
	if (file.is_open())
	{
		for (const auto& item : items)
		{
			file << item.ToLine(item, "#//#") << "\n";
		}
		file.close();
	}

}
template<typename T>
void SaveDataToFile(const vector<T>& items,string FN)
{

	ofstream file(FN);
	if (file.is_open())
	{
		for (const auto& item : items)
		{
			file << item.ToLine(item, "#//#") << "\n";
		}
		file.close();
	}

}

vector<BankClient>LoadClientDataFromFile()
{
	vector<BankClient>ClientsData;
	ifstream file(fileName);
	if (file.is_open())
	{
		BankClient client;
		string line;
		while (getline(file, line))
		{
			ClientsData.push_back(client.GetRecords(line));
		}
		file.close();
	}
	return ClientsData;
}
vector<Users>LoadUserDataFromFile()
{
	vector<Users>items;
	ifstream file(USersFile);
	if (file.is_open())
	{
		Users user;
		string line;
		while (getline(file, line))
		{
			items.push_back(user.GetRecords(line));
		}
		file.close();
	}
	return items;
}
void PrintClientRecordLine(BankClient Client)
{
	cout << "| " << setw(20) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(20) << left << Client.Email;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(15) << left << Client.AcountNumber;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}
void PrintUserRecordLine(Users &user)
{
	cout << "| " << setw(20) << left << user.UserName;
	cout << "| " << setw(20) << left << user.Password;
	cout << "| " << setw(5) << left << user.Permissons;

}
void ShowAllClientsScreen()
{
	vector <BankClient> vClients = LoadClientDataFromFile();
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")	Client(s).";
		cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else
		for (BankClient Client : vClients)
		{
			PrintClientRecordLine(Client);
			cout << endl;
		}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}
void ShowAllUsersScreen()
{
	vector <Users> vUsers = LoadUserDataFromFile();
	cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ")	User(s).";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(20) << "Username";
	cout << "| " << left << setw(20) << "Password";
	cout << "| " << left << setw(5) << "Permissions";

	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	if (vUsers.size() == 0)
		cout << "\t\t\t\tNo Users Available In the System!";
	else
		for ( auto &U : vUsers)
		{
			PrintUserRecordLine(U);
			cout << endl;
		}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}
void PrintClientCard(BankClient Client)
{
	cout << "\n\nclient details:\n";
	cout << "-----------------------------------";
	cout << "\nName           : " << Client.Name;
	cout << "\nPhone          : " << Client.Phone;
	cout << "\nEmail          : " << Client.Email;
	cout << "\nPin Code       : " << Client.PinCode;
	cout << "\nAccout Number  : " << Client.AcountNumber;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n-----------------------------------\n";
}
void PrintUserCard(Users U)
{
	cout << "\n\nUser details\n";
	cout << "-----------------------------------";
	cout << "\nUsername        : " << U.UserName;
	cout << "\nPassword        : " <<U .Password;
	cout << "\nPermissons      : " << U.Permissons;

	cout << "\n-----------------------------------\n";
}
bool FindClient(string &AccountNumber,BankClient &Client)
{

	vector<BankClient>Clients = LoadClientDataFromFile();
	for (const auto& C : Clients)
	{
		if (C.AcountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}
bool FindUser(string& Username,string&password, Users& user)
{

	vector<Users>items= LoadUserDataFromFile();
	for (const auto& User : items)
	{
		if (User.UserName == Username && User.Password==password)
		{
			user= User;
			return true;
		}
	}
	return false;
}



template <typename T, typename Predicate>
vector<T> MarkForDeleting(vector<T> items, Predicate condition)
{
	for (auto& item : items)
	{
		if (condition(item))
		{
			item.Mark = true;
			break;
		}
	}
	return items;
}

void DeleteClient(string AccountNumber)
{
	vector<BankClient>Clients = LoadClientDataFromFile();
	Clients = MarkForDeleting(Clients, [&](const BankClient& c)
		{
			return c.AcountNumber == AccountNumber;
		});
	ofstream file(fileName);
	if (file.is_open())
	{
		for (auto& Client : Clients)
		{
			if (!Client.Mark)
			{
				file << Client.ToLine(Client, "#//#") << "\n";

			}
		}
	}
}

void DeleteUser(string username,string password)
{
	vector<Users>User= LoadUserDataFromFile();
	User = MarkForDeleting(User, [&](const Users& U)
		{
			return U.UserName == username && U.Password == password;
		});
	ofstream file(USersFile);
	if (file.is_open())
	{
		for (auto& U : User)
		{
			if (!U.Mark)
			{
				file << U.ToLine(U, "#//#") << "\n";

			}
		}
	}
}
void ClientListScreen()
{
	ShowAllClientsScreen();
}
void UserstListScreen()
{
	ShowAllUsersScreen();
}
void AddNewClientScreen()
{
	cout << "\t\t\tAdd New Client Screen\n";
	SaveDataToFileAfterAdding(AddClientData(),fileName);
}
void DeleteClientScreen()
{
	cout << "\n\n\t\tDelete Client Screen\n\n";
	string AccountNumber;
	char Again;
	bool ClientDeleted ;

	do
	{

		BankClient Client;
		AccountNumber = GetAccountNumber();
		ClientDeleted = false;

		if (FindClient(AccountNumber, Client))
		{
			PrintClientCard(Client);
			cout << "\nAre you sure you want to delete this client? [y/n]: ";

			if (Answer() == 'y')
			{
				DeleteClient(AccountNumber);
				cout << "\nClient Deleted Successfully.\n";
				ClientDeleted = true;
			}
		}
		else
		{
			cout << "\nClient Not Found!\n";
		}

		if (ClientDeleted)
		{
			cout << "\nDo you want to delete another client? [y/n]: ";
			Again = Answer();
		}
		else
		{
			Again = 'n';
		}

	} while (Again == 'y' || Again == 'Y');
}
void DeleteUserScreen()
{
	cout << "\n\n\t\tDelete User Screen\n\n";
	string username;
	string password;
	char Again;
	bool UserDeleted;

	do
	{

		Users user;
		username = GetUserName();
		password = GetPassword();
		UserDeleted = false;

		if (FindUser(username,password, user))
		{
			PrintUserCard(user);
			cout << "\nAre you sure you want to delete this user? [y/n]: ";

			if (Answer() == 'y')
			{
				DeleteUser(username, password);
				cout << "\nUser Deleted Successfully.\n";
				UserDeleted = true;
			}
		}
		else
		{
			cout << "\nUser Not Found!\n";
		}

		if (UserDeleted)
		{
			cout << "\nDo you want to delete another usre? [y/n]: ";
			Again = Answer();
		}
		else
		{
			Again = 'n';
		}

	} while (Again == 'y' || Again == 'Y');

}
void UpdateClient(string &AccountNumber,vector<BankClient>&Clients)
{
	Clients = LoadClientDataFromFile();
	BankClient Client = FillClientDate();
	for (auto& C : Clients)
	{
		if (C.AcountNumber == AccountNumber)
		{
			C = Client;
			break;
		}
	}

}
void UpdateUser(string& username,string password, vector<Users>& users)
{
	users = LoadUserDataFromFile();
	Users UpdateUserData = FillUserDate();
	for (auto& U : users)
	{
		if (U.UserName == username && U.Password == password)
		{
			U = UpdateUserData;
			break;
		}
	}

}
void UpdateClientScreen()
{
	cout << "\n\n\t\tDelete Client Screen\n\n";

	vector<BankClient>Clients;
	string AccountNumber;
	bool ClientUpdated;
	char Again;
	do
	{
		ClientUpdated = false;
		BankClient Client;
		AccountNumber = GetAccountNumber();
		if (FindClient(AccountNumber, Client))
		{
			PrintClientCard(Client);
			cout << "\nAre you sure you want to update this client? [y/n]: ";
			if (Answer() == 'y')
			{
				UpdateClient(AccountNumber, Clients);
				SaveDataToFile(Clients,fileName);
				ClientUpdated = true;
				cout << "\nClient Updatedd Successfully.\n";

			}

		}
		else cout << "\nClient Not Found!\n";
		if (ClientUpdated)
		{
			cout << "\nDo you want to udate another client? [y/n]: ";
			Again = Answer();
		}
		else Again = 'n';


	} while (tolower(Again)=='y');
}
void UpdateUserScreen()
{
	cout << "\n\n\t\tDelete User Screen\n\n";

	vector<Users>users;
	string username;
	string password;
	bool UserUpdated;
	char Again;
	do
	{
		UserUpdated = false;
		Users user;
		username = GetUserName();
		password = GetPassword();
		if (FindUser(username, password,user))
		{
			PrintUserCard(user);
			cout << "\nAre you sure you want to update this user? [y/n]: ";
			if (Answer() == 'y')
			{
				UpdateUser(username,password, users);
				SaveDataToFile(users, USersFile);
				UserUpdated = true;
				cout << "\nUser Updatedd Successfully.\n";

			}

		}
		else cout << "\User Not Found!\n";
		if (UserUpdated)
		{
			cout << "\nDo you want to udate another user? [y/n]: ";
			Again = Answer();
		}
		else Again = 'n';


	} while (tolower(Again) == 'y');
}
void FindClientScreen()
{
	cout << "\n\n\t\Find Client Screen\n\n";

	string AccountNumber;
	do
	{
		AccountNumber = GetAccountNumber();
		BankClient Client;

		if (FindClient(AccountNumber, Client))
		{
			PrintClientCard(Client);
			cout << "\nDo you want to Find another client? [y/n]: ";

		}
		else
		{
			cout << "\nAccount Not Found!\n\n";
			return ;
		}
	} while (Answer() == 'y');

}
void ClearAllClientsDataScreen()
{
	cout << "\n\n\t\Clear All Clients Screen\n\n";

	cout << "\nAre you sure you want to Delete all clients? [y/n]: ";
	if (Answer() == 'y')
	{
		ofstream file(fileName);
		if (file.is_open())
		{
			file.close();
		}
		cout << "\nClients Deleted Successfully.\n";


	}
}
float Withdraw(string &AccountNumber, vector<BankClient>&Clients,float WithdrawingAmount)
{
	Clients = LoadClientDataFromFile();
	for (auto& C : Clients)
	{
		if (C.AcountNumber == AccountNumber)
		{
			C.AccountBalance -= WithdrawingAmount;
			SaveDataToFile(Clients, fileName);
			return C.AccountBalance;
		}
	}
}
void WithdrawScreen()
{
	cout << "\n\n\t\tWithdraw Screen\n\n";
	vector<BankClient>Clients;
	BankClient Client;
	string AccountNumber = GetAccountNumber();
	float WithdrawinAmount;
	float newBalance;
	if (FindClient(AccountNumber, Client))
	{
		PrintClientCard(Client);
		cout << "how much would u like to withdraw?  ";
		cin >> WithdrawinAmount;
		if (WithdrawinAmount < Client.AccountBalance)
		{
			newBalance = Withdraw(AccountNumber, Clients, WithdrawinAmount);
			cout << "\n\nSuccessfull Operation.\n";
			cout << "new Balance = " << newBalance<<"\n";

		}
		else cout << "\n\nThe operation failed because the withdrawn amount is greater than the available balance. \n\n";


	}
	else
	{
		cout << "\nAccount Not Found!\n\n";

	}

}

float GetTotalBalance()
{
	float TotalBalance = 0;
	vector<BankClient>Clients = LoadClientDataFromFile();
	for (const auto& C : Clients)
	{
		TotalBalance += C.AccountBalance;
	}
	return TotalBalance;
}
void TotalBalaceScreen()
{
	float totlBalace = GetTotalBalance();
	ShowAllClientsScreen();
	cout << "\n\t\t\t Total Balace = " << totlBalace << "\n\n";
}
void AddUserScreen()
{
	cout << "\t\t\tAdd New User Screen\n";
	SaveDataToFileAfterAdding(AddUserData(), USersFile);
}

void PerfomeceTransactionMenuChoices(enTransacionManuChoices Choice, Users& user)
{
	switch (Choice)
	{
	case enTransacionManuChoices::withdraw:
	{
		system("cls");
		WithdrawScreen();
		GoBackToTransacionMenue(user);
		break;
	}
	case enTransacionManuChoices::deposite:
	{
		system("cls");
		DepositScreen();
		GoBackToTransacionMenue(user);
		break;
	}
	case enTransacionManuChoices::totalBalance:
	{
		system("cls");
		TotalBalaceScreen();
		GoBackToTransacionMenue(user);
		break;
	}
	case enTransacionManuChoices::main_menu:
	{
		system("cls");
		ShowMainMenue(user);
		break;
	}
	}
}
void PerfomeceMangeUsersChoices(enMangeUsersMenu Choice,Users&user)
{
	switch (Choice)
	{
	case enMangeUsersMenu::show_users_screen:
	{
		system("cls");
		UserstListScreen();
		GoBackToMangeUsersMenue(user);
		break;
	}
	case enMangeUsersMenu::adduser:
	{
		system("cls");
		AddUserScreen();
		GoBackToMangeUsersMenue(user);
		break;
	}

	case enMangeUsersMenu::deletuser:
	{
		system("cls");
		DeleteUserScreen();
		GoBackToMangeUsersMenue(user);
		break;
	}
	case enMangeUsersMenu::udateuser:
	{
		system("cls");
		UpdateUserScreen();
		GoBackToMangeUsersMenue(user);
		break;
	}
	case enMangeUsersMenu::maninmenu:
	{
		system("cls");
		ShowMainMenue(user);
		break;
	}
	}
}

void ShowTransactionMenue(Users& user )
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tTransaction Menu Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Withdraw.\n";
	cout << "\t[2] Deposite.\n";
	cout << "\t[3] Total Balance.\n";
	cout << "\t[4] Main Menu.\n";
	cout << "===========================================\n";
	PerfomeceTransactionMenuChoices(enTransacionManuChoices(GetTransactionMenuChoice()),user);

}

void PerfomeceMainMenuChoices(enMainManuChoices Choice,Users &user)
{
	switch (Choice)
	{
	case enMainManuChoices::ShowClientList:
	{
		if (HasPermission(user, enPermissons::show_clients_lilst))
		{
			system("cls");
			ClientListScreen();

		}
		else
		{
			system("cls");
			cout << "\nAccess is not allowed\n";

			AccessDeniedMessage();
		}
			GoBackToMainMenue(user);
		break;
	}
	case enMainManuChoices::AddNewClient:
	{
		if (HasPermission(user, enPermissons::add_client))
		{

			system("cls");
			AddNewClientScreen();

		}
		else
		{
			system("cls");
			cout << "\nAccess is not allowed\n";
			AccessDeniedMessage();

		}

		GoBackToMainMenue(user);
		break;

	}
	case enMainManuChoices::deleteClient:
	{
		if (HasPermission(user, enPermissons::delete_client))
		{
			system("cls");
			DeleteClientScreen();

		}
		else
		{
			system("cls");
			cout << "\nAccess is not allowed\n";
			AccessDeniedMessage();

		}

		GoBackToMainMenue(user);
		break;

	}
	case enMainManuChoices::updateClient:
	{
		if (HasPermission(user, enPermissons::update_client))
		{
			system("cls");
			UpdateClientScreen();

		}
		else
		{
			system("cls");
			cout << "\nAccess is not allowed\n";
			AccessDeniedMessage();

		}


		GoBackToMainMenue(user);
		break;

	}
	case enMainManuChoices::findClient:
	{
		if (HasPermission(user, enPermissons::find_client))
		{
			system("cls");
			FindClientScreen();

		}
		else
		{
			system("cls");
			cout << "\nAccess is not allowed\n";
			AccessDeniedMessage();

		}

		GoBackToMainMenue(user);
		break;

	}
	case enMainManuChoices::transaction:
	{
		if (HasPermission(user, enPermissons::transaction_menu))
		{
			system("cls");
			ShowTransactionMenue(user);

		}
		else
		{
			system("cls");
			cout << "\nAccess is not allowed\n";
			AccessDeniedMessage();

		}


		GoBackToMainMenue(user);
		break;

	}
	case enMainManuChoices::mangeusers:
	{
		if (HasPermission(user, enPermissons::mange_users))
		{
			system("cls");
			ShowMangeUserMenue(user);

		}
		else
		{
			system("cls");
			cout << "\nAccess is not allowed\n";
			AccessDeniedMessage();

		}

		GoBackToMainMenue(user);
		break;
	}
	case enMainManuChoices::clear_all_clients:
	{
		if (HasPermission(user, enPermissons::clear_all_Client))
		{
			system("cls");
			ClearAllClientsDataScreen();

		}
		else
		{
			system("cls");
			cout << "\nAccess is not allowed\n";
			AccessDeniedMessage();

		}

		GoBackToMainMenue(user);
		break;

	}


	case enMainManuChoices::logut:
	{
		system("cls");
		login();
		break;

	}
	}
}
void ShowMainMenue(Users &user)
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tMain Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transaction.\n";
	cout << "\t[7] Mange Users.\n";
	cout << "\t[8] Clear.\n";
	cout << "\t[9] Logut.\n";
	cout << "===========================================\n";
	PerfomeceMainMenuChoices(enMainManuChoices(GetMainMenuChoice()),user);
}
void ShowMangeUserMenue(Users& user)
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\Mange Users Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Show Users Screen.\n";
	cout << "\t[2] Add User .\n";
	cout << "\t[3] Delete User .\n";
	cout << "\t[4] Update User .\n";
	cout << "\t[5] Main Menu .\n";
	cout << "===========================================\n";

	PerfomeceMangeUsersChoices(enMangeUsersMenu((GetMangeUsersMenuChoice())),user);
}
void login()
{
	cout << "\n\n\t\tlogin Screen\n\n";
	string username = GetUserName();
	string password = GetPassword();
	system("cls");
	Users user;

	while (!FindUser(username, password,user))
	{
		cout << "\n\n\t\tlogin Screen\n\n";
		cout << "\nInvalid Username/Password\n\n";
		username = GetUserName();
		password = GetPassword();
		system("cls");

	}
		ShowMainMenue(user);

}


*/


//void ClsMainMenu::_ShowLoginScreen()
//{
//	ClsLoginScreen::LoginScreen();
//}

int main() { 

	while (true)
	{
		if (!ClsLoginScreen::LoginScreen())break;
	}
	

	//hello baby
	system("pause>0");
	

}