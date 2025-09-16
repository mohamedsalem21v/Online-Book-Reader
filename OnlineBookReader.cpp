#include <bits/stdc++.h>
#include "admins.h"
#define sp " "
using namespace std;

void Sign_up()
{
    user new_user;
    new_user.read();
    all_users.push_back(new_user);
    all_usernames.insert(new_user.get_username());
    all_users.back().menu();
}

void Login()
{
    user* us_ptr = nullptr;
    admin ad;
    cout << "Enter username: ";
    cin.ignore();
    string username;
    getline(cin,username);

    cout << "Enter password: ";
    string password;
    getline(cin,password);
    bool user_or_not = false;
    bool found = false;
    for(int i = 0; i < all_admins.size(); i++)
    {
        if(all_admins[i].get_username() == username && all_admins[i].get_password() == password)
        {
            found = true;
            ad = all_admins[i];
        }
        else if(all_admins[i].get_username() == username && all_admins[i].get_password() != password)
        {
            return void(cout << "Wrong password, please try again.\n\n");
        }
    }
    if(!found)
    {
        for(int i = 0; i < all_users.size(); i++)
        {
            if(all_users[i].get_username() == username && all_users[i].get_password() == password)
            {
                found = true;
                user_or_not = true;
                us_ptr = &all_users[i];
            }
            else if(all_users[i].get_username() == username && all_users[i].get_password() != password)
            {
                return void(cout << "Wrong password, please try again.\n");
            }
        }
    }
    if(!found)
    {
        return void(cout << "This username is not exist in the system.\n\n");
    }
    if(user_or_not)
    {
        us_ptr->menu();
    }
    else
    {
        admin_menu(ad);
    }

}

void online_book()
{
    admins_in_the_system();
    books_in_the_system();
    while(true)
    {
        cout << "Menu: \n";
        cout << "1: Login\n2: Sign up\n3: Exit program\n\n";
        cout << "Enter a number in range (1-3): ";
        int choice = safe_input_int(1,3);
        if(choice == 1)
        {
            Login();
        }
        else if(choice == 2)
        {
            Sign_up();
        }
        else if(choice == 3)
        {
            cout << "Exiting the online book reader system.\n";
            break;
        }
    }
}

int main()
{
    online_book();
    return 0;
}