#include <iostream>
#include <ostream>
#include <string>

using namespace std;

string format_fields(string);

class Book {
public:
    void get_info();
    void display_info();
    void display_row(int);
private:
    string name;
    string ISBN;
    string author;
    string link;
};

class Library {
public:
    Library();
    void add_book(Book);
    void show();
    void show_book(int);
private:
    int current;
    int number;
    Book books[8];
};


