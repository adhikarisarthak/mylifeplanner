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

// JournalDetails class for storing journal entries and their details
class JournalDetails {
public:
    int journal_id; // ID of the journal entry
    string current_time; // Current timestamp of the entry
    string journal_data; // Data for the journal entry
    vector<tuple<string, string, pair<int, string>>> journal; // Vector of tuples containing journal entry data
    json journal_json_data; // JSON object for storing journal data

    // Function for taking user input for the journal entry
    void journal_entry() {
        cout << "Please enter what you want to write today: ";
        cin.ignore();
        getline(cin, journal_data);
    }

    // Function for creating a new journal entry and adding it to the journal vector
    void create_new_journal(string username, string journal_data) {
        // Get current time
        time_t raw_time;
        struct tm *time_info;
        char buffer[80];

        time(&raw_time);
        time_info = localtime(&raw_time);

        strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", time_info);
        current_time = buffer;

        // Set journal ID
        if (journal.size() != 0) {
            journal_id = get<2>(journal.front()).first + 1;
        } else {
            journal_id = 1;
        }

        // Add journal entry to vector
        journal.insert(journal.begin(), make_tuple(username, current_time, make_pair(journal_id, journal_data)));
    }

    // Function for printing all journal entries
    void print_journal() {
        cin.ignore(); // Ignore any extra input
        for (const auto& data : journal) {
            // Only print non-empty entries
            if(get<2>(data).second != "")
                cout << "Entry ID: " << get<2>(data).first << " | "
                     << "Timestamp: " << get<1>(data) << " | "
                     << "Entry: " << get<2>(data).second << "\n";
        }
    }

    // Function for saving the journal data as a JSON file
    void save_as_json(vector<tuple<string, string, pair<int, string>>> saving_journal) {
        // Set JSON file name to username.json
        string json_file_name = get<0>(saving_journal[0]) + ".json";

        if (filesystem::exists(json_file_name)) {
            // If the file already exists, remove it
            filesystem::remove(json_file_name);
        }

        // Add journal entries to JSON object
        for (const auto &element: saving_journal) {
            journal_json_data.push_back({
                                                {"username", get<0>(element)},
                                                {"journal", {
                                                                     {"timestamp", get<1>(element)},
                                                                     {"id", get<2>(element).first},
                                                                     {"entry", get<2>(element).second}
                                                             }}
                                        });
        }

        // Write JSON object to file
        ofstream json_file(json_file_name, ios::app);
        json_file << setw(4) << journal_json_data << endl;
    }

// Function for loading journal data from a JSON file
    void load_json_entries(string username) {
        // Set JSON file name to username.json
        string json_file_name = username + ".json";

        if (filesystem::exists(json_file_name)) {
            // If the file exists,
            // open the file for reading
            ifstream ifs(json_file_name);

            // Load the contents of the file as JSON
            json j;
            ifs >> j;

            // Get the stored username from the file
            string stored_username = j[0]["username"];

            // If the stored username matches the given username,
            if (username == stored_username) {
                // Print a message to indicate loading of previous entries
                cout << "loading previous entries" << endl;

                // Create a vector to store the loaded journal entries
                vector<pair<string, pair<int, string>>> loading_journal;

                // Iterate over each element in the JSON
                for (const auto& element : j) {
                    // Get the username, timestamp, ID and entry from the element
                    string loaded_username = element["username"];
                    string loaded_timestamp = element["journal"]["timestamp"];
                    int loaded_id = element["journal"]["id"];
                    string loaded_entry = element["journal"]["entry"];

                    // Add the journal entry to the loading_journal vector
                    journal.emplace_back(loaded_username, loaded_timestamp, make_pair(loaded_id, loaded_entry));
                }

                // Print a message to indicate completion of loading
                cout << "... Completed" << endl;
            }
        }
    }

// Function to remove a journal entry by ID
    void remove_entry(int journal_id) {
        // Iterate over each journal entry
        for (int i = 0; i < journal.size(); i++) {
            // If the ID of the current entry matches the given ID,
            if (get<2>(journal[i]).first == journal_id) {
                // Clear the timestamp and entry of the current entry
                get<1>(journal[i]) = "";
                get<2>(journal[i]).second = "";
            }
        }
    }

};
