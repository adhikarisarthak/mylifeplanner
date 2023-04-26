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
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
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
            cout << "Username: " << get<0>(data) << " | "
                 << "Timestamp: " << get<1>(data) << " | "
                 << "Entry ID: " << get<2>(data).first << " | "
                 << "Entry: " << get<2>(data).second << "\n";
        }
    }

    void save_as_json(vector<tuple<string, string, pair<int, string>>> saving_journal) {
        string json_file_name = get<0>(saving_journal[0]) + ".json";
        filesystem::path path = "my_file.json";

        // Check if the file exists
        if (filesystem::exists(json_file_name))
            filesystem::remove(json_file_name);
            // The file does not exist
        cout << "The file does not exist." << endl;
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
            string loaded_username = j[0]["username"];
            if (username == loaded_username) {
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
};
