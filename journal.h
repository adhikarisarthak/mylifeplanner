//
// Created by Triet Nguyen on 3/20/23.
//

#ifndef JOURNALPROJECT_JOURNAL_H
#define JOURNALPROJECT_JOURNAL_H

#endif //JOURNALPROJECT_JOURNAL_H
#include <ctime>
#include <iostream>
#include <map>
#include <string>
using namespace std;
class JournalDetails{
public:
    int journalID;
    string journalData;
    map<int, string>journal;
    void createNewJournal(int journalID, string journalData){
        journal.insert({journalID,journalData});
    }
    
};
