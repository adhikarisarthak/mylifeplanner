//
// Created by Triet Nguyen on 3/20/23.
//

#ifndef JOURNALPROJECT_LOGIN_H
#define JOURNALPROJECT_LOGIN_H

#endif //JOURNALPROJECT_LOGIN_H
#include <string>
using namespace std;
class LoginClass{
private:
    string username;
    string password;
public:
    bool userLogin(string username, string password) {
        if (username.compare("admin") == 0 and password.compare("admin") == 0) {
            return true;
        }
        else
            cout << username << password;
            return false;
    }
};
