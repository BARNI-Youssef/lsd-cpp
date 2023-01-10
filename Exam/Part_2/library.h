#include <iostream>
#include <ostream>
#include <string>

using namespace std;

string format_fields(string);

class Page {
public:
    int pg_num;
    string content;
    string title;
};

class Book {
public:
    void get_info();
    void display_info();
    void display_row(int);
    void display_content();
    bool readable;
private:
    string name;
    string ISBN;
    string author;
    string link;
    int nb_pg;
    Page* content;
};

class Library {
public:
    Library();
    void add_book(Book);
    void show();
    void show_book(int);
    Book books[8];
private:
    int current;
    int number;
    
};


