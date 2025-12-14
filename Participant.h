#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
#include <vector>
using namespace std;

class Participant {
private:
    string participantID;
    string name;
    vector<string> eventIDs;

public:

    Participant(string id = "", string n = "");


    string getParticipantID() const;
    string getName() const;

    void registerForEvent(const string& eventID);
    const vector<string>& getEventIDs() const;
};

#endif