#include <bits/stdc++.h>
#define sp " "
using namespace std;

class session
{
private:
    string book_title;
    int last_page;
    string last_read_time;
public:
    session()
    {
        this->book_title = "";
        this->last_page = 0;
        this->last_read_time = "";
    }
    
    string set_book_title(string book_title)
    {
        this->book_title = book_title;
    }
    void set_last_page(int last_page)
    {
        this->last_page = last_page;
    }
    void set_last_read_time(string last_read_time)
    {
        this->last_read_time = last_read_time;
    }

    string get_book_title()
    {
        return book_title;
    }
    int get_last_page()
    {
        return last_page;
    }
    string get_last_read_time()
    {
        return last_read_time;
    }
};