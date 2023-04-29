#include <string>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
using namespace std;

class LoginClass {
private:
    string username;
    string password;
    vector<pair<string,string>>users;
    nlohmann::json users_json;


public:
    bool user_login(string username, string password);
    void create_account(string username, string password);
    void save_as_json();
    void load_users_json();
    string encrypt(string str);
    string decrypt(string str);
    // Create a entries for username and password
    // Store them in json file
    // When login, check the the entries with existing database inside json file
    // pull the data store on the variables
    // function to encrypt strings, used for password protection
    // function to decrypt strings, used for password verification
};

bool LoginClass::user_login(string username, string password) {
    // cout << username << password;
    ifstream ifs("users.json");
    nlohmann::json users_temp;
    ifs >> users_temp;

string encrypt(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = str[i] + 2; //the key for encryption is 2 that is added to ASCII value
    }
    return str;
}

string LoginClass::decrypt(string str) {
    for (int i = 0; (i < str.length()); i++) {
        str[i] = str[i] - 2; //the key for decryption is 2 that is subtracted from ASCII value
    }
    return str;
}    

    for (auto user: users_temp["users"]) {
        if (username == user["username"] && password == decrypt(user["password"])) {
            return true;
        } else {
            return false;
        }
    }
}
void LoginClass::create_account(string username, string password) {
    users.push_back(make_pair(username,password));

}
void LoginClass::save_as_json() {
    if (filesystem::exists("users.json"))
        filesystem::remove("users.json");
    // The file does not exist then create new
    for (auto &user: users) {
        users_json["users"].push_back({{"username", user.first}, {"password", user.second}});
    }
    ofstream json_file("users.json", ios::app);
    json_file << setw(4) << users_json << endl;
}

string encrypt(string str)
{
    for (int i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 2; //the key for encryption is 3 that is added to ASCII value

    string s(str);

    return s;
}

string decrypt(string str)
{
    for (int i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value

    string s(str);

    return s;
}
