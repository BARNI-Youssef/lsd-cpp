#include <iostream>
#include <string>

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

class contact{
private:
    string name;
    string f_name;
    string nickname;
    string number;
public:
    void get_info(){
        cout << "first name  : ";
        cin >> name;
        cout << "family name : ";
        cin >> f_name;
        cout << "nickname    : ";
        cin >> nickname;
        cout << "number      : ";
        cin >> number;        
    }
    void display_info(){
        cout << "First name: " << name << "\n";
        cout << "Last name : " << f_name << "\n";
        cout << "Nickname  : " << nickname << "\n";
        cout << "Phone no  : " << number << "\n";
    }
    void display_row(int k){
        cout << "|" << k  << "         |" << format_fields(name) << "|" << format_fields(f_name) << "|" << format_fields(nickname) << "|\n";
    }
};


class phone_book
{
private:
    int counter;
    int current;
    contact* data;
public:
    void add_contact(contact A){
        if(current > 7){
            current = 0;
            counter = 8;
            data[current] = A;
        }
        else{
            data[current] = A;
            counter ++;
            current ++;
        }
    }
    void show(){
        for(int j = 0; j < 4; j++) cout << "+----------";
        cout << "+\n";
        cout << "|Index     |First name|Last name |Nickname  |\n";
        for(int k = 0; k < counter; k++){
            for(int j = 0; j < 4; j++) cout << "+----------";
            cout << "+\n";
            data[k].display_row(k+1);    
        }
        for(int j = 0; j < 4; j++) cout << "+----------";
        cout << "+\n";
    }
    void get_contact(int k){
        if(k > counter) cout << "No contact with that index\n";
        else data[k-1].display_info();
    }
    phone_book();
    ~phone_book();
};

phone_book::phone_book(){
    counter = 0;
    current = 0;
    data = new contact[8];
}

phone_book::~phone_book(){
    delete[] data;
}


int main(){
    phone_book TheFB;
    string input;
    char ind[1];
    int k;
    cout << "Welcome to your phone book. Type 'ADD' to add a contact, 'SEARCH' to look for an existing contact and 'QUIT' to quit the program.\n";
    while(1){
        cin >> input;
        if(input.compare("ADD") == 0){
            contact A;
            A.get_info();
            TheFB.add_contact(A);
            cout << "Contact succefuly added\n\n";
        }
        if(input.compare("SEARCH") == 0){
            TheFB.show();
            cout << "Type the index of the contact to display full info.\n";
            cin >> ind;
            k = atoi(ind);
            if(k < 0 || k > 7) cout << "invalid index\n";
            else TheFB.get_contact(k);
    }
        if(input.compare("QUIT") == 0){
            cout << "\nbye !\n";
            return 0;
        }
    }
}
