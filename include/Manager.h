#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include "Person.h"
#include "Attendee.h"
#include "Speaker.h"

class ConferenceManager {
private:
    vector<Person*> participants;
    const string filename = "data/registrations.txt";

public:
    ConferenceManager();
    ~ConferenceManager();

    void registerAttendee();
    void registerSpeaker();
    void showAllParticipants() const;
    void showTotalFees() const;
    
    void saveToFile();
    void loadFromFile();
};

#endif