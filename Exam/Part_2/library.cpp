#include "library.h"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>

using namespace std;

string format_fields(string input){
    string out;
    int n = input.length();
    if(n > 10){
        out = input.substr(0, 9);
        out += ".";
        return out;
    }
    if(n < 10){
        out = input;
        for(int i = 0; i < 10-n; i++) out += " ";
        return out;
    }
    return input;
}

void Book::get_info(){
    cout << "Is the naive ?(y/n) : ";
    string input;
    cin >> input;
    readable = false;
    if (input.compare("y") == 0) {
        readable = true;
        cout << "Number of pages";
        cin >> nb_pg;
        content = new Page[8];
        for (size_t i = 0; i < nb_pg; i++) {
            Page p;
            p.pg_num = i+1;
            cout << "Give the title of the page :\n";
            cin >> p.title;
            cout << "Give the content of the page :\n";
            cin >> p.content;
            content[i] = p;
        }
    }
    cout << "Name   : ";
    cin >> name;
    cout << "ISBN   : ";
    cin >> ISBN;
    cout << "Author : ";
    cin >> author;
    cout << "Link   : ";
    cin >> link;
}

void Book::display_info(){ 
    cout << "Name   : " << name << "\n" << "ISBN   : " << ISBN << "\n" << "Author : " << author << "\n" << "Link   : " << link << "\n";
}

void Book::display_row(int n){
    cout << "|" << n << "         |" << format_fields(name) << "|" << format_fields(author) << "|\n";
}

void Book::display_content() {
    for (size_t i = 0; i < nb_pg; i++) {
        if (content[i].title.compare(" ") != 0) {
            cout << content[i].pg_num  << "   " << content[i].content << "\n";
        }
        cout << content[0].content << "\n";
        int k = 0;
        while(k < nb_pg-1){
            string input;
            cin >> input;
            if (input.compare("n")) {
                cout << content[k+1].content << "\n";
                k++;
            }
        }
    }
}

Library::Library(){
    current = 0;
    number = 0;
}

void Library::add_book(Book B){
    if(current > 7){
        current = 0;
        number = 8;
        books[current] = B;
        current++;
    }
    else{
        books[current] = B;
        current ++;
        if (number < 8) number++;
    }
 }

void Library::show(){
    for (size_t i = 0; i < 3 ; i++) cout << "+----------";
    cout << "+\n|Index     |Name      |Author    |\n";
    for (size_t i = 0; i < 3 ; i++) cout << "+----------";
    cout << "+\n";
    for (size_t i = 0; i < number; i++) {
        books[i].display_row(i+1);
        for (size_t i = 0; i < 3 ; i++) cout << "+----------";
        cout << "+\n";
    }
}

void Library::show_book(int k){
    if (k < 0 || k > number) {
        cout << "invalid index\n";
        return;
    }
    books[k].display_info();
}

