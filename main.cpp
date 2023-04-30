//Brooklyn Dressel (fm6391),
//Sarthak Adhikari(bv9292),
//Triet Nguyen(re2653)


#include <iostream>
#include "login.h"
#include "journal.h"
using namespace std;

int main() {
    int login_options = 0;
    LoginClass student_a;           // create an instance of the LoginClass
    JournalDetails student_journal; // create an instance of the JournalDetails class
    string login_username;          // variable to store the login username
    string login_password;          // variable to store the login password
    bool is_logged_in = false;      // flag to check if the user is logged in or not

    while (login_options != 7) {    // repeat until the user chooses to sign out
        if (!is_logged_in) {        // if the user is not logged in
            cout << "\t\t    *My Diary*\n"
                    "\t\tPlease Pick an Option:\n"
                    "\t\t1. Login\n"
                    "\t\t2. Create Account\n"
                    "\t\t3. Forgot Password\n";
            cout << "\t\tPlease enter your options:";
            cin >> login_options;
        } else {                    // if the user is logged in
            cout << "\t\t    *My Diary*\n"
                    "\t\t1. Login (Disabled)\n"
                    "\t\t2. Create Account (Disabled)\n"
                    "\t\t3. Forgot Password (Disabled)\n"
                    "\t\t4. Print\n"
                    "\t\t5. Add new journal\n"
                    "\t\t6. Remove journal\n"
                    "\t\t7. Sign Out\n";
            cout << "\t\tPlease enter your options:";
            cin >> login_options;
        }

        switch (login_options) {    // perform the corresponding action based on user input
            case 1: {               // case 1: login
                cout << "\n\t\tPlease Enter your username: ";
                cin >> login_username;
                cout << "\t\tPlease Enter your password: ";
                cin >> login_password;
                cout << "\n";
                is_logged_in = student_a.user_login(login_username, login_password);   // call the user_login method from the LoginClass
                student_journal.load_json_entries(login_username);                    // load the journal entries for the logged in user
                if (is_logged_in) {
                    cout << "\t\tLogin Successful\n";
                } else {
                    cout << "\t\tLogin Failed!\n\t\tYou will be force to logout now";
                    login_options = 7;
                    break;
                }
                break;
            }
            case 2:{               // case 2: create new account
                cout << "\t\tPlease Enter your desired username: ";
                cin >> login_username;
                cout << "\t\tPlease Enter your desired password: ";
                cin >> login_password;
                student_a.create_account(login_username, encrypt(login_password));     // create a new account using the create_account method from the LoginClass
                student_a.save_as_json();                                               // save the new account information as a JSON file
                break;
            }
            case 4: {               // case 4: print the journal
                student_journal.print_journal();
                break;
            }
            case 5: {               // case 5: add a new entry to the journal
                student_journal.journal_entry();
                student_journal.create_new_journal(login_username, student_journal.journal_data);    // create a new journal entry for the logged in user
                break;
            }
            case 6:{               // Prompt user to enter ID of entry to be removed, then remove and print updated journal
                int journal_id;
                student_journal.print_journal();
                cout << "\t\tEnter the journal you want to remove by it's ID: ";
                cin >> journal_id;
                student_journal.remove_entry(journal_id);
                student_journal.print_journal();
                break;
            }
            case 7: {              // Save journal as JSON and log out
                student_journal.save_as_json(student_journal.journal);
                cout << "\t\tLog Out Completed" << endl;
                break;
            }
            default: {             // Display error message if input is invalid
                cout << "\t\tError from Program! Terminating App" << endl;
                break;
            }
        }
    }
}
