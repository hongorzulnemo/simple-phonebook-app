#include <iostream>
#include <regex>
#include <unordered_map>
#include <string>
#include "phonebook.h"


using namespace std;


void printer(phonebook contacts);
bool phone_not_valid(string tel);
void readTel();
void readUsername();

string username; string tel;



int main()
{
    /*pb.addContact("tom", "+36202662025");
    pb.addContact("sam", "+36202662000");
    pb.addContact("tom", "+36202662020");

    pb.printer();*/

    int choice = 1;
    phonebook pb;

    do
    {
        string welcome_text =
            ".........................................\n"
            "       Welcome to phonebook system!      \n"
            "                                         \n"
            ":::::::::::::::::: MENU :::::::::::::::::\n"
            "                                         \n"
            "0. Exit                                  \n"
            "1. Add new contact                       \n"
            "2. Search user by phone                  \n"
            "3. Search user by username               \n"
            "4. Delete contact                        \n";

        cout << welcome_text << "Enter Your choice: " << endl;

        cin >> choice;

        switch(choice) {

            case 1:

                readUsername();
                readTel();

                if (phone_not_valid(tel)) {
                    cout << "Invalid phone number. We couldn't update contacts.";
                } else {
                    pb.addContact(username, tel);
                    cout << "Success!" << endl;
                };

                break;

            case 2:

                readTel();

                if(pb.searchByPhone(tel) != "") {
                    cout << "user found: " << pb.searchByPhone(tel) << endl;
                } else {
                    cout << "user not found :/" << endl;
                }

                break;


            case 3:

                readUsername();

                if(pb.searchByName(username).empty()) {
                    cout << "user not found :/" << endl;
                } else {
                    cout << "user found: " << username << endl;
                    pb.printTel(username);
                }

                break;

            case 4:

                readUsername();
                readTel();

                pb.deleteContact(username, tel);

                break;
            }

        } while(choice);


    return 0;

}


bool phone_not_valid(string tel) {

    regex format (R"(((?:\+?3|0)6)(?:-|\()?(\d{1,2})(?:-|\))?(\d{3})-?(\d{3,4}))");

    if(regex_match(tel, format)) {

        return false;
    }

    return true;
}


void readUsername() {

    cout << "Enter username: ";
    cin >> username;
}


void readTel() {

    cout << endl << "Enter hungarian phone number: " ;
    cin >> tel;

}


