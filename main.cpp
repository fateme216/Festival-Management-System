#include <iostream>
#include <iomanip>
#include "Manager.h"
#include "Exceptions.h"
using namespace std;

void printHeader(const string& title) {
    cout << "\n" << string(50, '=') << "\n";
    cout << "  " << title << "\n";
    cout << string(50, '=') << "\n";
}

int main() {
    Manager manager;

    cout << " Festival Management System\n";

    printHeader("Adding Events");

    Event events[] = {
        Event("E1", "Classical Music Concert", "Cultural", 100),
        Event("E2", "Art Workshop", "Educational", 30),
        Event("E3", "Handicraft Exhibition", "Cultural", 200),
        Event("E4", "Sustainable Development Talk", "Social", 150)
    };

    for (const auto& event : events) {
        manager.addEvent(event);
        cout << " " << event.getEventName()
                  << " (Capacity: " << event.getCapacity() << ")\n";
    }

    printHeader("Adding Participants");

    Participant participants[] = {
        Participant("P1", "Fateme Hosseini"),
        Participant("P2", "Maryam Mohammadi"),
        Participant("P3", "Zainab Merzaie"),
        Participant("P4", "Sara Ahmadi")
    };

    for (const auto& participant : participants) {
        manager.addParticipant(participant);
        cout << " " << participant.getName()
                  << " (ID: " << participant.getParticipantID() << ")\n";
    }

    printHeader("Event Registration");

    struct Registration {
        string participantID;
        string eventID;
    };

    Registration registrations[] = {
        {"P1", "E1"}, {"P2", "E1"}, {"P3", "E1"},
        {"P1", "E2"}, {"P4", "E2"},
        {"P2", "E3"}, {"P3", "E3"}, {"P4", "E3"},
        {"P1", "E4"}
    };

    int successCount = 0;
    int errorCount = 0;

    for (const auto& reg : registrations) {
        try {
            manager.registerParticipantToEvent(reg.participantID, reg.eventID);
            cout << " Registered " << reg.participantID
                      << " in " << reg.eventID << "\n";
            successCount++;
        } catch (const exception& e) {
            cout << "✗ Error: " << e.what() << "\n";
            errorCount++;
        }
    }

    cout << "\n Result: " << successCount << " successful, "
              << errorCount << " errors\n";


    printHeader("Search");

    if (auto event = manager.findEvent("E1")) {
        cout << "Event E1 found: " << event->getEventName()
                  << " (" << event->getParticipantCount()
                  << "/" << event->getCapacity() << ")\n";
    }

    if (auto participant = manager.findParticipant("P1")) {
        cout << " Participant P1 found: "
                  << participant->getName() << "\n";
    }

    printHeader("Events Sorted by Type");

    auto byType = manager.listEventsSortedByType();
    cout << left << setw(30) << "Event Name"
              << setw(15) << "Type"
              << setw(15) << "Participants"
              << "Status\n";
    cout << string(75, '-') << "\n";

    for (const auto& event : byType) {
        string status = event.isFull() ? "Full" : "Available";
        cout << left << setw(30) << event.getEventName()
                  << setw(15) << event.getEventType()
                  << setw(15) << (to_string(event.getParticipantCount()) + "/" + to_string(event.getCapacity()))
                  << status << "\n";
    }


    printHeader("Events Sorted by Participant Count");

    auto byCount = manager.listEventsSortedByParticipantCount();
    cout << left << setw(35) << "Event Name"
              << "Participant Count\n";
    cout << string(50, '-') << "\n";

    for (const auto& event : byCount) {
        cout << left << setw(35) << event.getEventName()
                  << event.getParticipantCount() << "\n";
    }

    printHeader("Error Testing");

    try {
        cout << "Test 1: Non-existent participant...\n";
        manager.registerParticipantToEvent("P999", "E1");
    } catch (const ParticipantNotFoundException& e) {
        cout << " Expected error: " << e.what() << "\n";
    }

    try {
        cout << "\nTest 2: Non-existent event...\n";
        manager.registerParticipantToEvent("P1", "E999");
    } catch (const EventNotFoundException& e) {
        cout << " Expected error: " << e.what() << "\n";
    }

    try {
        cout << "\nTest 3: Duplicate registration...\n";
        manager.registerParticipantToEvent("P1", "E1");
    } catch (const AlreadyRegisteredException& e) {
        cout << " Expected error: " << e.what() << "\n";
    }

    cout << "\n" << string(50, '=') << "\n";
    cout << "Program completed successfully!\n";

    return 0;
}