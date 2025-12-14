#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>
using namespace std;

class ParticipantNotFoundException : public runtime_error {
public:
    explicit ParticipantNotFoundException(const string& id)
        : runtime_error("Participant not found: " + id) {}
};

class EventNotFoundException : public runtime_error {
public:
    explicit EventNotFoundException(const string& id)
        : runtime_error("Event not found: " + id) {}
};

class EventFullException : public runtime_error {
public:
    explicit EventFullException(const string& id)
        : runtime_error("Event is full: " + id) {}
};

class AlreadyRegisteredException : public runtime_error {
public:
    explicit AlreadyRegisteredException(const string& pid, const string& eid)
        : runtime_error("Already registered: " + pid + " in " + eid) {}
};

#endif