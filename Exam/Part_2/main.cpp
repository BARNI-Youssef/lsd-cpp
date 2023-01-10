#include "library.cpp"
#include <cstdlib>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    Library lib;
    string input;
    cout << "Welcome to your libray, please type \"ADD\" to add a book \"SEARCH\" to display all books and look for a specific one and \"EXIT\" to quit the program.\n\n";
    while (1) {
        cin >> input;
        if (input.compare("ADD") == 0) {
            Book B;
            B.get_info();
            lib.add_book(B);
            cout << "Book sucessfully added\n\n";
        }
        if (input.compare("SEARCH") == 0) {
            lib.show();
            cout << "Please give a index to display all infos\n\n";
            string a;
            int k;
            cin >> a;
            k = stoi(a);
            if (lib.books[k-1].readable == false) {
                lib.show_book(k-1);
                cout << "\n";
            }
            else {
                lib.books[k-1].display_content();
            }
        }
        if (input.compare("EXIT") == 0) {
           cout << "\nbye !\n";
           return 0;
        }
    }
    return 0;
}
