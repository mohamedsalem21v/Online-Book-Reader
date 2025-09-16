#include <bits/stdc++.h>
#include "books.h"
#include "SafeInput.h"
#define sp " "
using namespace std;

set<string> all_usernames;
class user
{
private:
    string username;
    string password;
    string email;
    string name;
    vector<tuple<string,int,string>> sessions;
    unordered_map<string, int> book_current_page;
    bool taken;

public:
    user()
    {
        username = "";
        password = "";
        email = "";
        name = "";
        taken = false;
    }

    void set_username(string s)
    {
        username = s;
    }
    void set_password(string s)
    {
        password = s;
    }
    void set_email(string s)
    {
        email = s;
    }
    void set_name(string s)
    {
        name = s;
    }

    string get_username()
    {
        return username;
    }
    string get_password()
    {
        return password;
    }
    string get_email()
    {
        return email;
    }
    string get_name()
    {
        return name;
    }
    string get_current_time_date() 
    {
	    // src: https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono
        auto now = std::chrono::system_clock::now();
	    auto in_time_t = std::chrono::system_clock::to_time_t(now);
	    std::stringstream ss;
	    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
        return ss.str();
    }
    
    void read()
    {
        cin.ignore();
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
            taken = true;
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
    }
    
    void pages_menu(book bk)
    {
        string book_id = bk.get_title();
        int& curr = book_current_page[book_id];
        if(curr == 0)
            curr = 1;
        cout << "Menu:\n";
        cout << "1: Next page\n";
        cout << "2: Previous page\n";
        cout << "3: Stop reading\n";
        cout << "Enter number in rage(1-3): ";
        int choice = safe_input_int(1,3);  
        
        if(choice == 1)
        {
            if(curr == bk.get_cnt_of_pages())
            {
                cout << "You are already in the last page.\n";
                print_current_page(bk);
            }
            else
            {
                curr++;
                print_current_page(bk);
            }
        }
        else if(choice == 2)
        {
            if(curr == 1)
            {
                cout << "You are already in the first page.\n\n";
                print_current_page(bk);
            }
            else
            {
                curr--;
                print_current_page(bk);
            }
        }
        else
        {
            cout << "Stopping reading " << bk.get_title() << ".\n";
            sessions.push_back({bk.get_title(), bk.get_cnt_of_pages(), get_current_time_date()});
            return;
        }
    }

    void print_current_page(book bk)
    {
        string book_id = bk.get_title();
        int curr = book_current_page[book_id];
        if(curr == 0)
            curr = 1;

        cout << "\nCurrent Page: " << curr << "\\" << bk.get_cnt_of_pages() << endl;
        cout << bk.get_pages()[curr-1] << "\n\n";
        pages_menu(bk);
    }
    
    book b;
    void books_form_the_system()
    {
        cout << "\nOur current book collection:\n";
        for (int i = 1; i <= all_books.size(); i++)
        {
            cout << "  " << i << ") " << all_books[i - 1].get_title() << endl;
        }
        cout << "\nWhich Book you want to read?\n";
        cout << "Enter number in range (1-" << all_books.size() << "): ";
        int choice = safe_input_int(1, all_books.size());
        b = all_books[choice - 1];
        print_current_page(b);
    }

    void books_form_my_history()
    {
        if (sessions.size() == 0)
        {
            return void(cout << "You have no reading history yet, please read a book from the system first.\n\n");
        }
        for (int i = 1; i <= sessions.size(); i++)
        {
            int curr = book_current_page[get<0>(sessions[i - 1])];
            if (curr == 0)
                curr = 1;
            cout << i << ") " << get<0>(sessions[i - 1])
                 << " (" << curr << "\\" << get<1>(sessions[i - 1])
                 << ") | Last read at: " << get<2>(sessions[i - 1]) << endl;
        }

        cout << "\nWhich session you want to open?\n";
        cout << "Enter number in range (1-" << sessions.size() << "): ";

        int choice = safe_input_int(1, sessions.size());
        bool found = false;
        for (int i = 0; i < all_books.size(); i++)
        {
            if (get<0>(sessions[choice - 1]) == all_books[i].get_title())
            {
                b = all_books[i];
                found = true;
                print_current_page(b);
                break;
            }
        }
        if (!found)
        {
            cout << "Book from this session not found in library.\n";
        }
    }

    void menu()
    {
        if(taken)
            return;
        cout << "\nHello " << get_name() << " | User view";
        while(true)
        {
            cout << "\nMenu:\n";
            cout << "1: View profile\n";
            cout << "2: List & Select from My Reading History\n";
            cout << "3: List & Select from Available Books\n";
            cout << "4: Logout\n";
            cout << "\nEnter a number in range (1-4): ";
            int choice = safe_input_int(1,4);
            // cin.ignore();
            if(choice == 1)
            {
                view_profile();
            }
            else if(choice == 2)
            {
                books_form_my_history();
            }
            else if(choice == 3)
            {
                books_form_the_system();
            }
            else if(choice == 4)
            {
                cout << "Exiting the online book reader system.\n" << endl;
                break;
            }
        }
    }
};

vector<user> all_users;