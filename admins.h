#include <bits/stdc++.h>
#include "users.h"
#define sp " "
using namespace std;

class admin : public user
{
private:
    string username;
    string password;
    string email;
    string name;

public:
    admin(): user(){}

    void read()
    {
        cout << "Enter username: ";
        string username;
        getline(cin,username);

        cout << "Enter password: ";
        string password;
        getline(cin,password);

        cout << "Enter name: ";
        string name;
        getline(cin,name);

        cout << "Enter email: ";
        string email;
        getline(cin,email);
        if(all_usernames.count(username))
        {
            return void(cout << "This username is already taken, please try another one.\n\n");
        }

        set_username(username);
        set_password(password);
        set_name(name);
        set_email(email);
    }

    void view_profile()
    {
        cout << endl;
        cout << "Name: " << get_name() << endl;
        cout << "Email: " << get_email() << endl;
        cout << "Username: " << get_username() << endl;
        cout << "Password: " << get_password() << "\n\n";
    }

    void add_book()
    {
        book b;
        b.add_book();
        all_books.push_back(b);
        ofstream fout("books_in_the_system.txt", ios::app);
        fout << b.get_title() << "," << b.get_ISBN() << "," << b.get_author_name() << "," << b.get_cnt_of_pages();
        for(int i = 0; i < b.get_cnt_of_pages(); i++)
        {
            fout << "," << b.get_pages()[i];
        }
        fout << "\n";
        fout.close();
    }

    void remove_user()
    {
        cout << "Enter Username: ";
        // cin.ignore();
        string str;
        getline(cin, str);
        for (auto it = all_users.begin(); it != all_users.end(); ++it)
        {
            if (it->get_username() == str)
            {
                all_users.erase(it);
                all_usernames.erase(str);
                cout << "User '" << str << "' removed successfully.\n\n";
                return;
            }
        }
        cout << "User '" << str << "' not found.\n\n";
    }

    bool remove_book_by_title(const string& title_to_remove) 
    {
        ifstream fin("books_in_the_system.txt");
        if (!fin)
        {
            cerr << "Error opening file for reading!" << endl;
            return false;
        }

        vector<string> lines;
        string line;

        bool found = false;
        while (getline(fin, line))
        {
            string current_title = line.substr(0, line.find(','));

            if (current_title != title_to_remove)
            {
                lines.push_back(line);
            }
            else
            {
                found = true; 
            }
        }
        fin.close();

        if (!found)
        {
            cout << "Book with title \"" << title_to_remove << "\" not found.\n\n";
            return false;
        }

        ofstream fout("books_in_the_system.txt");
        if (!fout)
        {
            cerr << "Error opening file for writing!\n\n";
            return false;
        }

        for (const string &remaining_line : lines)
        {
            fout << remaining_line << endl;
        }
        fout.close();
        for (auto it = all_books.begin(); it != all_books.end(); it++)
        {
            if (it->get_title() == title_to_remove)
            {
                all_books.erase(it);
                break; 
            }
        }
        cout << "Book with title \"" << title_to_remove << "\" successfully removed.\n\n";
        return true;
    }
    
    void show_all_users()
    {
        cout << string(80, '-') << endl;
        cout << left << setw(18) << "Name"
             << setw(18) << "Username"
             << setw(30) << "Email"
             << setw(20) << "Password" << endl;
        cout << string(80, '-') << endl;

        // Print table rows
        for (auto &u : all_users)
        {
            cout << left << setw(18) << u.get_name()
                 << setw(18) << u.get_username()
                 << setw(30) << u.get_email()
                 << setw(20) << u.get_password() << endl;
        }
        cout << string(80, '-') << endl;
        cout << endl;
    }
    
    void show_all_books()
    {
        cout << string(80, '-') << endl;
        cout << left << setw(30) << "Title"
             << setw(20) << "Author"
             << setw(15) << "ISBN"
             << setw(10) << "Pages" << endl;
        cout << string(80, '-') << endl;

        for (auto &b : all_books)
        {
            cout << left << setw(30) << b.get_title()
                 << setw(20) << b.get_author_name()
                 << setw(15) << b.get_ISBN()
                 << setw(10) << b.get_cnt_of_pages() << endl;
        }
        cout << string(80, '-') << endl;
        cout << endl;
    }

};

vector<admin> all_admins;

void admins_in_the_system()
{
    string line;
    ifstream fin("admins_in_the_system.txt");
    while(getline(fin,line))
    {
        admin ad;
        stringstream ss(line);

        string name, password, email, username;

        getline(ss, name, ',');
        getline(ss, password, ',');
        getline(ss, email, ',');
        getline(ss, username, ',');

        ad.set_name(name);
        ad.set_password(password);
        ad.set_email(email);
        ad.set_username(username);

        all_admins.push_back(ad);
        all_usernames.insert(username);
    }
    fin.close();
}

void admin_menu(admin ad)
{
    cout << "\nHello " << ad.get_name() << " | Admin view\n";
    while(true)
    {
        cout << "Menu:\n";
        cout << "1: View profile\n";
        cout << "2: Add a book\n";
        cout << "3: Add an admin\n";
        cout << "4: Remove a book\n";
        cout << "5: Remove a user\n";
        cout << "6: Show all users\n";
        cout << "7: Show all books\n";
        cout << "8: Show all admins\n";
        cout << "9: Logout\n";
        cout << "Enter a number in range (1-9): ";
        int choice = safe_input_int(1,9);
        cin.ignore();
        if(choice == 1)
        {
            ad.view_profile();
        }
        else if(choice == 2)
        {
            ad.add_book(); 
        }
        else if(choice == 3)
        {
            admin new_admin;
            new_admin.read();
            all_admins.push_back(new_admin);
            all_usernames.insert(new_admin.get_username());
            ofstream fout("admins_in_the_system.txt", ios::app);
            fout << new_admin.get_name() << "," << new_admin.get_password() 
            << "," << new_admin.get_email() << "," << new_admin.get_username() << "\n";

            fout.close();
            cout << "Admin added successfully.\n\n";
        }
        else if(choice == 4)
        {
            cout << "Enter the title of the book to remove: ";
            string title_to_remove;
            getline(cin, title_to_remove);
            ad.remove_book_by_title(title_to_remove);
        }
        else if(choice == 5)
        {
            ad.remove_user();
        }
        else if(choice == 6)
        {
            ad.show_all_users();
        }
        else if(choice == 7)
        {
            ad.show_all_books();
        }
        else if(choice == 8)
        {
            cout << string(80, '-') << endl;
            cout << left << setw(18) << "Name"
                 << setw(18) << "Username"
                 << setw(30) << "Email"
                 << setw(20) << "Password" << endl;
            cout << string(80, '-') << endl;

            for (auto &a : all_admins)
            {
                cout << left << setw(18) << a.get_name()
                     << setw(18) << a.get_username()
                     << setw(30) << a.get_email()
                     << setw(20) << a.get_password() << endl;
            }
            cout << string(80, '-') << endl;
            cout << endl;
        }
        
        else if(choice == 9)
        {
            cout << "Logged out.\n\n";
            break;
        }
    }
}