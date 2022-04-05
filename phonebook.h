#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>


using namespace std;


class phonebook {

    private:

        unordered_map<string, vector<string>> contacts;

    public:

        phonebook() {}


        string searchByPhone(string tel) {
            for(auto &c : contacts) {
                for(string phone : c.second) {
                    if(tel == phone) return c.first;
                }
            }
            throw "Username with this phone number doesn't exist!";
        }


        vector<string> searchByName(string username) {
            if(nameExist(username)) {

                return contacts[username];
            }
            throw "Username doesn't exist!";
        }




        void addContact(string username, string tel) {

            if(sameExist(username, tel)) {
                throw "Same user exists!";
            }

            vector<string> p_numbers;

            if (nameExist(username)) {
                p_numbers = contacts[username];
            }

            p_numbers.push_back(tel);
            contacts[username] = p_numbers;

        }


        void deleteContact(string username, string tel) {

            if(sameExist(username, tel)) {

                vector<string> p_numbers = contacts[username];

                if(p_numbers.size() == 1) {

                    contacts.erase(username);

                } else {

                    p_numbers.erase(remove(p_numbers.begin(), p_numbers.end(), tel), p_numbers.end());
                    contacts[username] = p_numbers;

                }

            } else {

                throw "Can't remove non existing user!";
            }
        }


        bool sameExist(string username, string tel) {
            if(nameExist(username) && phoneInContact(searchByName(username), tel)) {
                return true;
            }
            return false;
        }


        bool nameExist(string username) {
            return contacts.find(username) != contacts.end();
        }


        bool phoneInContact(vector<string> numbers, string tel) {
            return find(numbers.begin(), numbers.end(), tel) != numbers.end();
        }


        void printer()
        {
            cout << "phone book: " << endl;

            for(auto& c : contacts) {

                cout << "username: " << c.first << endl << "numbers: ";

                for(string tel: c.second) {

                    cout << tel << ", " ;
                }

                cout << endl;
            }

            cout << endl;
        }

        void printTel(string username) {
            for(string tel: searchByName(username)) {
                cout << tel << ", " ;
            }
            cout << endl;
        }

};
