#include <bits/stdc++.h>
#define sp " "
using namespace std;

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

    void set_ISBN(string ISBN)
    {
        this->ISBN = ISBN;
    }
    void set_title(string title)
    {
        this->title = title;
    }
    void set_author_name(string author_name)
    {
        this->author_name = author_name;
    }
    void set_cnt_of_pages(int cnt_of_pages)
    {
        this->cnt_of_pages = cnt_of_pages;
    }
    void set_pages(vector<string> pages)
    {
        this->pages = pages;
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
        // cin.ignore();
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
        cin.ignore();
        set_cnt_of_pages(n);
        vector<string> entered_pages;
        for(int i = 0; i < n; i++)
        {
            cout << "Enter page # " << i+1 << ": ";  
            getline(cin,str);
            pages.push_back(str);
        }
        cout << "Book added successfully.\n\n";
    }
};
vector<book> all_books;

void books_in_the_system()
{
    book b;
    ifstream fin("books_in_the_system.csv");
    string line;
    bool header = true;
    while(getline(fin,line))
    {
        if(header)
        {
            header = false;
            continue;
        }
        
        book b;
        stringstream ss(line);

        string title, isbn, author;
        string pages_count_str;
        int pages_count;

        getline(ss, title, ',');
        getline(ss, isbn, ',');
        getline(ss, author, ',');
        getline(ss, pages_count_str, ','); 
        
        pages_count = stoi(pages_count_str);

        b.set_title(title);
        b.set_ISBN(isbn);
        b.set_author_name(author);
        b.set_cnt_of_pages(pages_count);
        
        vector<string> book_pages;
        string page;
        for (int i = 0; i < pages_count; i++)
        {
            if (i < pages_count - 1)
            {
                getline(ss, page, ',');
            }
            else
            {
                getline(ss, page);
            }
            book_pages.push_back(page);
        }

        b.set_pages(book_pages);        
        all_books.push_back(b);

    }
}