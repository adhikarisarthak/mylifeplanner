#include <string>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>

using namespace std;

class LoginClass {
private:
    string username;
    string password;
    vector<pair<string,string>> users; // store username and password as a pair
    nlohmann::json users_json; // json object to store users

public:
    bool user_login(string username, string password); // function to check login credentials
    void create_account(string username, string password); // function to create an account
    void save_as_json(); // function to save users to a JSON file
    void load_users_json();
    string encrypt(string str); // function to encrypt a string
    string decrypt(string str); // function to decrypt a string
};

// Function to check if user's login credentials are valid
bool LoginClass::user_login(string username, string password) {
    ifstream ifs("users.json");
    nlohmann::json users_temp;
    ifs >> users_temp;

    // iterate through the users and check if the username and password match
    for (auto user : users_temp["users"]) {
        if (username == user["username"] && password == decrypt(user["password"])) {
            return true;
        }
    }
    return false;
}

// Function to create an account
void LoginClass::create_account(string username, string password) {
    users.push_back(make_pair(username,password)); // add the username and password pair to the users vector
}

// Function to save users to a JSON file
void LoginClass::save_as_json() {
    if (filesystem::exists("users.json"))
        filesystem::remove("users.json"); // delete the file if it exists

    // add each user as an object to the "users" array in the JSON object
    for (auto &user: users) {
        users_json["users"].push_back({{"username", user.first}, {"password", user.second}});
    }

    ofstream json_file("users.json", ios::app);
    json_file << setw(4) << users_json << endl; // write the JSON object to the file with proper indentation
}

// Function to encrypt a string
string encrypt(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = str[i] + 2; // add 2 to the ASCII value of each character
    }
    return str;
}

// Function to decrypt a string
string LoginClass::decrypt(string str) {
    for (int i = 0; (i < str.length()); i++) {
        str[i] = str[i] - 2; // subtract 2 from the ASCII value of each character
    }
    return str;
}
