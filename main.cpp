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

    while (login_options != 7) {
        if (!is_logged_in) {
            cout << "Login CI:\n"
                    "1. Login\n"
                    "2. Create Account\n"
                    "3. Forgot Password\n";
            cout << "Please enter your options:";
            cin >> login_options;
        } else {
            cout << "Login CI:\n"
                    "1. Login (Disabled)\n"
                    "2. Create Account (Disabled)\n"
                    "3. Forgot Password (Disabled)\n"
                    "4. Print\n"
                    "5. Add new journal\n"
                    "6. Remove journal\n"
                    "7. Sign Out\n";
            cout << "Please enter your options:";
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
                    login_options = 7;
                    break;
                }
                break;
            }
            case 2:{
                cout << "Please Enter your desired username: ";
                cin >> login_username;
                cout << "Please Enter your desired password: ";
                cin >> login_password;
                student_a.create_account(login_username,login_password);
                student_a.save_as_json();
                break;
            }
            case 4: {
                student_journal.print_journal();
                break;
            }
            case 5: {
                student_journal.journal_entry();
                student_journal.create_new_journal(login_username, student_journal.journal_data);
                break;
            }
            case 6:{
                int journal_id;
                student_journal.print_journal();
                cout << "Enter the journal you want to remove by it's ID: ";
                cin >> journal_id;
                student_journal.remove_entry(journal_id);
                student_journal.print_journal();
                break;
            }
            case 7: {
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
