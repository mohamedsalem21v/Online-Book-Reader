#include <bits/stdc++.h>
#define sp " "
using namespace std;

int safe_input_int(int min, int max)
{
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail())
        {
            cout << "Invalid input! Expected an integer.\n";
            cout << "Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice < min || choice > max)
        {
            cout << "Out of range, please try again.\n";
            cout << "Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        return choice;
    }
}

class book
{
private:
    string ISBN;
    string title;
    string author_name;
    int cnt_of_pages;
    vector<string> pages;
public:
    book()
    {
        ISBN = "";
        title = "";
        author_name = "";
        cnt_of_pages = 0;    
    }

    void set_ISBN(string s)
    {
        ISBN = s;
    }
    void set_title(string s)
    {
        title = s;
    }
    void set_author_name(string s)
    {
        author_name = s;
    }
    void set_cnt_of_pages(int n)
    {
        cnt_of_pages = n;
    }
    void set_pages(vector<string> v)
    {
        pages = v;
    }
    
    string get_ISBN()
    {
        return ISBN;
    }
    string get_title()
    {
        return title;
    }
    string get_author_name()
    {
        return author_name;
    }
    int get_cnt_of_pages()
    {
        return cnt_of_pages;
    }
    vector<string> get_pages()
    {
        return pages;
    }

    void add_book()
    {
        cin.ignore();
        cout << "Enter ISBN: ";
        string str;
        getline(cin,str);
        set_ISBN(str);
        cout << "Enter Title: ";
        getline(cin,str);
        set_title(str);
        cout << "Enter Author Name: ";
        getline(cin,str);
        set_author_name(str);
        cout << "Enter How many pages: ";
        int n;
        cin >> n;
        // cin.ignore();
        set_cnt_of_pages(n);
        vector<string> entered_pages;
        for(int i = 0; i < n; i++)
        {
            cout << "Enter page # " << i+1 << ": ";  
            getline(cin,str);
            pages.push_back(str);
        }
    }

};
vector<book> all_books;
void books_in_the_system()
{
    book b1;
    b1.set_title("C++ how to program");
    b1.set_ISBN("1221");
    b1.set_author_name("Mohamed Salem");
    b1.set_cnt_of_pages(3);
    vector<string> pages_1(3);
    pages_1[0] = "pg1";
    pages_1[1] = "pg2";
    pages_1[2] = "pg3";
    b1.set_pages(pages_1);

    book b2;
    b2.set_title("Intro to algo");
    b2.set_ISBN("123321");
    b2.set_author_name("Mohamed Ahmed");
    b2.set_cnt_of_pages(3);
    vector<string> pages_2(3);
    pages_2[0] = "pg1";
    pages_2[1] = "pg2";
    pages_2[2] = "pg3";
    b2.set_pages(pages_2);

    book b3;
    b3.set_title("Data Structures in c++");
    b3.set_ISBN("12344321");
    b3.set_author_name("Mr Solom");
    b3.set_cnt_of_pages(3);
    vector<string> pages_3(3);
    pages_3[0] = "pg1";
    pages_3[1] = "pg2";
    pages_3[2] = "pg3";
    b3.set_pages(pages_3);

    all_books.push_back(b1);
    all_books.push_back(b2);
    all_books.push_back(b3);
}


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
        for(int i = 1; i <= all_books.size(); i++){
            cout << "  " << i << ") " << all_books[i-1].get_title() << endl;
        }
        cout << "\nWhich Book you want to read?\n";
        cout << "Enter number in range (1-" << all_books.size() << "): ";
        int choice = safe_input_int(1,all_books.size());
        b = all_books[choice-1];
        print_current_page(b);
    }
    
    void books_form_my_history()
    {
        if(sessions.size() == 0)
        {
            return void(cout << "You have no reading history yet, please read a book from the system first.\n\n");
        }
        for(int i = 1; i <= sessions.size(); i++)
        {
            int curr = book_current_page[get<0>(sessions[i-1])];
            if(curr == 0)
                curr = 1;
            cout << i << ") " << get<0>(sessions[i-1])
            << " (" << curr << "\\" << get<1>(sessions[i-1])
            << ") | Last read at: " << get<2>(sessions[i-1]) << endl;
        }

        cout << "\nWhich session you want to open?\n";
        cout << "Enter number in range (1-" << sessions.size() << "): ";

        int choice = safe_input_int(1,sessions.size());
        bool found = false;
        for(int i = 0; i < all_books.size(); i++)
        {
            if(get<0>(sessions[choice-1]) == all_books[i].get_title())
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


class admin
{
private:
    string username;
    string password;
    string email;
    string name;

public:
    admin()
    {
        username = "";
        password = "";
        email = "";
        name = "";
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
    
    void read()
    {
        cout << "\nEnter username: ";
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

    void remove_book()
    {
        cout << "Enter ISBN: ";
        cin.ignore();
        string str;
        getline(cin,str);
        for(int i = 0; i < all_books.size(); i++)
        {
            if(str == all_books[i].get_ISBN())
            {
                all_books.erase(all_books.begin() + i);
                return void(cout << "Book removed successfully.\n\n");
            }
        }
        cout << "This ISBN is not exist, please try again.\n\n";
    }

    void menu()
    {
        cout << "\nHello " << get_name() << " | Admin view\n";
        while(true)
        {
            cout << "Menu:\n";
            cout << "1: View profile\n";
            cout << "2: Add a book\n";
            cout << "3: Remove a book\n";
            cout << "4: Remove a user\n";
            cout << "5: Logout\n";
            cout << "Enter a number in range (1-5): ";
            int choice = safe_input_int(1,5);
            cin.ignore();
            if(choice == 1)
            {
                view_profile();
            }
            else if(choice == 2)
            {
                add_book(); 
            }
            else if(choice == 3)
            {
                remove_book();
            }
            else if(choice == 4)
            {
                remove_user();
            }
            else if(choice == 5)
            {
                cout << "Logged out.\n\n";
                break;
            }
        }
    }
};
vector<admin> all_admins;
void admins_in_the_system()
{
    admin ad1;
    ad1.set_name("Mohammed Salem");
    ad1.set_password("msms1234");
    ad1.set_email("mohamedsalem@gmail.com");
    ad1.set_username("momosolom");
    all_admins.push_back(ad1);
    all_usernames.insert(ad1.get_username());
}


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
    cout << "\nEnter username: ";
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
        ad.menu();
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
