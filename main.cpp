#include <iostream>
#include "login.h"
#include "journal.h"
using namespace std;

int main() {
    int LoginOptions=0;
    LoginClass studentA;
    JournalDetails studentJournal;
    string loginUsername;
    string loginPassword;
    bool checklogin = false;


    while (LoginOptions != 4) {
        if(checklogin == false){
            cout << "Login CI:\n"
                    "1. Login\n";
            cout << "Please enter your options: ";
            cin >> LoginOptions;
        }
        else {
            cout << "Login CI:\n"
                    "1. Login\n"
                    "2. Print\n"
                    "3. Add new journal\n"
                    "4. Sign Out\n";
            cout << "Please enter your options: ";
            cin >> LoginOptions;
        }


        if (LoginOptions == 1) {
            cout << "Please Enter your username: ";
            cin >> loginUsername;
            cout << "Please Enter your password: ";
            cin >> loginPassword;
            checklogin = studentA.userLogin(loginUsername,loginPassword);
            studentJournal.loadJSONEntries(loginUsername);


            if (checklogin) {
                cout << "Login Successful\n";
            } else {
                cout << "Login Failed!\nYou will be force to logout now";
                break;
            }
        }


        else if (LoginOptions == 2) {
            studentJournal.printJournal();
        }


        else if (LoginOptions == 3) {
            studentJournal.JournalEntry();
            studentJournal.createNewJournal(loginUsername, studentJournal.journalID, studentJournal.journalData);
            studentJournal.saveAsJson(studentJournal.journal);
        }


        else{
            cout << "Sign Out of App completed";
        }
    }
}
