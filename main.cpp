#include <iostream>
#include "login.h"
#include "journal.h"
using namespace std;

int main() {
    int login_options = 0;
    LoginClass student_a;
    JournalDetails student_journal;
    string login_username;
    string login_password;
    bool is_logged_in = false;

    while (login_options != 4) {
        if (!is_logged_in) {
            cout << "Login CI:\n"
                    "1. Login\n";
            cout << "Please enter your options: ";
            cin >> login_options;
        } else {
            cout << "Login CI:\n"
                    "1. Login (Disabled)\n"
                    "2. Print\n"
                    "3. Add new journal\n"
                    "4. Sign Out\n";
            cout << "Please enter your options: ";
            cin >> login_options;
        }

        switch (login_options) {
            case 1: {
                cout << "Please Enter your username: ";
                cin >> login_username;
                cout << "Please Enter your password: ";
                cin >> login_password;
                is_logged_in = student_a.user_login(login_username, login_password);
                student_journal.load_json_entries(login_username);

                if (is_logged_in) {
                    cout << "Login Successful\n";
                } else {
                    cout << "Login Failed!\nYou will be force to logout now";
                    break;
                }
                break;
            }
            case 2: {
                student_journal.print_journal();
                break;
            }
            case 3: {
                student_journal.journal_entry();
                student_journal.create_new_journal(login_username, student_journal.journal_data);
                break;
            }
            case 4: {
                student_journal.save_as_json(student_journal.journal);
                cout << "Log Out Completed" << endl;
                break;
            }
            default: {
                cout << "Error from Program! Terminating App" << endl;
                break;
            }
        }
    }
}
