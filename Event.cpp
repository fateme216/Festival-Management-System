#include "Event.h"
using namespace std;

Event::Event(string id, string name, string type, int cap)
    : eventID(id), eventName(name), eventType(type), capacity(cap) {}

string Event::getEventID() const { return eventID; }

string Event::getEventName() const { return eventName; }

string Event::getEventType() const { return eventType; }
int Event::getCapacity() const { return capacity; }

int Event::getParticipantCount() const { return participantIDs.size(); }

bool Event::isFull() const { return participantIDs.size() >= capacity; }

void Event::addParticipant(const string& participantID) {
    participantIDs.push_back(participantID);
}

const vector<string>& Event::getParticipantIDs() const {
    return participantIDs;
}