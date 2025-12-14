#include "Manager.h"
#include "Exceptions.h"
#include <algorithm>

void Manager::addEvent(const Event& event) {
    events[event.getEventID()] = event;
}

void Manager::addParticipant(const Participant& participant) {
    participants[participant.getParticipantID()] = participant;
}

void Manager::registerParticipantToEvent(const std::string& participantID,
                                        const std::string& eventID) {

    auto participantIt = participants.find(participantID);
    if (participantIt == participants.end()) {
        throw ParticipantNotFoundException(participantID);
    }

    auto eventIt = events.find(eventID);
    if (eventIt == events.end()) {
        throw EventNotFoundException(eventID);
    }

    if (eventIt->second.isFull()) {
        throw EventFullException(eventID);
    }

    const auto& registeredEvents = participantIt->second.getEventIDs();
    for (const auto& eid : registeredEvents) {
        if (eid == eventID) {
            throw AlreadyRegisteredException(participantID, eventID);
        }
    }

    eventIt->second.addParticipant(participantID);
    participantIt->second.registerForEvent(eventID);
}

Event* Manager::findEvent(const std::string& eventID) {
    auto it = events.find(eventID);
    if (it != events.end()) {
        return &(it->second);
    }
    return nullptr;
}

Participant* Manager::findParticipant(const std::string& participantID) {
    auto it = participants.find(participantID);
    if (it != participants.end()) {
        return &(it->second);
    }
    return nullptr;
}

std::vector<Event> Manager::listEventsSortedByType() const {
    std::vector<Event> eventList;

    for (const auto& pair : events) {
        eventList.push_back(pair.second);
    }

    std::sort(eventList.begin(), eventList.end(),
        [](const Event& a, const Event& b) {
            return a.getEventType() < b.getEventType();
        });

    return eventList;
}

std::vector<Event> Manager::listEventsSortedByParticipantCount() const {
    std::vector<Event> eventList;

    for (const auto& pair : events) {
        eventList.push_back(pair.second);
    }

    std::sort(eventList.begin(), eventList.end(),
        [](const Event& a, const Event& b) {
            return a.getParticipantCount() > b.getParticipantCount();
        });

    return eventList;
}