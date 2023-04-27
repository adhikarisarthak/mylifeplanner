#include <ctime>
#include <tuple>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include <utility>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json =  nlohmann::json;

class JournalDetails {
public:
    int journal_id;
    string current_time;
    string journal_data;
    vector<tuple<string, string, pair<int, string>>> journal;
    json journal_json_data;

    void journal_entry() {
        cout << "Please enter what you want to write today: ";
        cin.ignore();
        getline(cin, journal_data);
    }

    void create_new_journal(string username, string journal_data) {
        json data;
        time_t raw_time;
        struct tm *time_info;
        char buffer[80];

        time(&raw_time);
        time_info = localtime(&raw_time);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", time_info);
        string current_time = buffer;

        if (journal.size() != 0) {
            journal_id = get<2>(journal.front()).first + 1;
        } else {
            journal_id = 1;
        }
        journal.insert(journal.begin(), make_tuple(username, current_time, make_pair(journal_id, journal_data)));
    }

    void print_journal() {
        cin.ignore();
        for (const auto& data : journal) {
            if(get<2>(data).second != "")
            cout    << "Entry ID: " << get<2>(data).first << " | "
                    << "Timestamp: " << get<1>(data) << " | "
                    << "Entry: " << get<2>(data).second << "\n";
        }
    }

    void save_as_json(vector<tuple<string, string, pair<int, string>>> saving_journal) {
        string json_file_name = get<0>(saving_journal[0]) + ".json";

        if (filesystem::exists(json_file_name))
            filesystem::remove(json_file_name);
            // The file does not exist then create new
        for (const auto &element: saving_journal) {
            journal_json_data.push_back({
                                                {"username", get<0>(element)},
                                                {"journal",  {
                                                                     {"timestamp", get<1>(element)},
                                                                     {"id", get<2>(element).first},
                                                                     {"entry", get<2>(element).second}
                                                             }}
                                        });
        }
        ofstream json_file(json_file_name, ios::app);
        json_file << setw(4) << journal_json_data << endl;
    }

    void load_json_entries(string username) {
        string json_file_name = username + ".json";
        if (filesystem::exists(json_file_name)) {
            ifstream ifs(json_file_name);
            json j;
            ifs >> j;
            string stored_username = j[0]["username"];
            if (username == stored_username) {
                cout << "loading previous entries" << endl;
                vector<pair<string, pair<int, string>>> loading_journal;
                for (const auto& element : j) {
                    string loaded_username = element["username"];
                    string loaded_timestamp = element["journal"]["timestamp"];
                    int loaded_id = element["journal"]["id"];
                    string loaded_entry = element["journal"]["entry"];
                    journal.emplace_back(loaded_username, loaded_timestamp, make_pair(loaded_id, loaded_entry));
                }
                cout << "... Completed" << endl;
            }
        }
    }

    void remove_entry(int journal_id){
        for(int i = 0; i< journal.size(); i++){
            if(get<2>(journal[i]).first == journal_id){
                get<1>(journal[i])="";
                get<2>(journal[i]).second="";
            }
        }

    }
};
