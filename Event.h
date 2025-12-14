#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <vector>
using namespace std;

class Event {
private:
    string eventID;
    string eventName;
    string eventType;
    int capacity;
    vector<string> participantIDs;

public:

    Event(string id = "", string name = "", string type = "", int cap = 0);

    string getEventID() const;
    string getEventName() const;
    string getEventType() const;
    int getCapacity() const;
    int getParticipantCount() const;
    bool isFull() const;
    void addParticipant(const string& participantID);
    const vector<string>& getParticipantIDs() const;
};

#endif