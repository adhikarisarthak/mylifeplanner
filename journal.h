//
// Created by Triet Nguyen on 3/20/23.
//

#ifndef JOURNALPROJECT_JOURNAL_H
#define JOURNALPROJECT_JOURNAL_H

#endif //JOURNALPROJECT_JOURNAL_H
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json =  nlohmann::json;
class JournalDetails{
public:
    int journalID;
    string journalData;
    vector<pair<string,pair<int,string>>> journal;
    json journalJSONData;
    void JournalEntry(){
        cin.ignore();
        cout << "Create new Journal\n Please enter Journal ID: ";
        cin >> journalID;
        cout << "Please enter what you want to write today:";
        cin.ignore();
        getline (cin, journalData);
    }
    void createNewJournal(string username, int journalID, string journalData)
    {
        journal.emplace_back(username, make_pair(journalID,journalData));
    }

    void printJournal()
    {
        for (auto &data: journal) {
            cout << data.first << " "
                 << data.second.first << " "
                 << data.second.second << "\n";
        }
    }

    void saveAsJson(vector<pair<string, pair<int,string>>> savingJournal){
        for (const auto& element : savingJournal) {
            journalJSONData.push_back({
                {"username", element.first},
                {"journal",
                    {
                        {"ID", element.second.first},
                        {"Entry", element.second.second}
                    }
                }
            });
        }
        string fileName = savingJournal[0].first + ".json";
        ofstream jsonFile(fileName,std::ios::trunc);
        jsonFile << setw(4) << journalJSONData << endl;
    }

    void loadJSONEntries(string username)
    {
        string jsonFileName = username+".json";
        if(filesystem::exists(jsonFileName)){
            ifstream ifs(jsonFileName);
            json j;
            ifs >> j;
            string loadedUsername = j[0]["username"];
            if(username == loadedUsername){
                cout << "loading previous entries" <<  endl;
                vector<pair<string, pair<int, string>>> loadingJournal;
                for (const auto& element : j) {
                    string loaded_username = element["username"];
                    int loaded_ID = element["journal"]["ID"];
                    string loaded_entry = element["journal"]["Entry"];
                    journal.emplace_back(loaded_username, make_pair(loaded_ID,loaded_entry));
                    // cout << "loading entry" << " " << loaded_ID<< endl; Debug line
                }
                cout << "... Completed" << endl;
            }
        }
    }
};
