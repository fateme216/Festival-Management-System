#include "Participant.h"
using namespace std;

Participant::Participant(string id, string n)
    : participantID(id), name(n) {}

string Participant::getParticipantID() const { return participantID; }
string Participant::getName() const { return name; }

void Participant::registerForEvent(const string& eventID) {
    eventIDs.push_back(eventID);
}

const vector<string>& Participant::getEventIDs() const {
    return eventIDs;
}