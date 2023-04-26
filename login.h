#include <string>

using namespace std;

class LoginClass {
private:
    string username;
    string password;

public:
    bool user_login(string username, string password) {
        // cout << username << password;
        if (username == "admin" && password == "admin") {
            return true;
        } else {
            return false;
        }
    }
    // Create a entries for username and password
    // Store them in json file
    // When login, check the the entries with existing database inside json file
    // pull the data store on the variables
};
