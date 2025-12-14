#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <vector>
#include "Event.h"
#include "Participant.h"
using namespace std;

class Manager {
private:
    map<string, Event> events;
    map<string, Participant> participants;

public:
    void addEvent(const Event& event);

    void addParticipant(const Participant& participant);

    void registerParticipantToEvent(const string& participantID,
                                    const string& eventID);

    Event* findEvent(const string& eventID);
    Participant* findParticipant(const string& participantID);


    vector<Event> listEventsSortedByType() const;
    vector<Event> listEventsSortedByParticipantCount() const;
};

#endif