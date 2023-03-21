#include <iostream>
#include <map>
#include "login.h"
#include "journal.h"
using namespace std;
int main() {
    int LoginOptions=0;
    LoginClass studentA;
    JournalDetails studentJournal;
    string loginUsername = "admin";
    string loginPassword = "admin";
    bool checklogin;
    checklogin = studentA.userLogin(loginUsername,loginPassword);
    while (LoginOptions != 3) {
        cout << "Login CI:\n"
                "1. Login\n"
                "2. Print\n"
                "3. Sign Out\n";
        cout << "Please enter your options: ";
        cin >> LoginOptions;
        if(LoginOptions == 1)
            if(checklogin){
                cin.ignore();
                cout << "Create new Journal\n Please enter Journal ID: ";
                cin >> studentJournal.journalID;
                cout << "Please enter what you want to write today:";
                cin.ignore();
                getline (cin, studentJournal.journalData);
                studentJournal.createNewJournal(studentJournal.journalID,studentJournal.journalData);
            }
            else{
                cout << "Login Failed";
            }
        else if(LoginOptions == 2){
            for (auto& data: studentJournal.journal)
            {
                cout << data.first << " "
                     << data.second << "\n";
            }
        }
    }

}
