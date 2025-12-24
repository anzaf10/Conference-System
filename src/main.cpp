#include <iostream>
#include "../include/Manager.h"

using namespace std;

int main() {
    ConferenceManager cms;
    int choice;

    do {
        cout << "\n=== Conference Registration System ===\n";
        cout << "1. Register Attendee\n";
        cout << "2. Register Speaker\n";
        cout << "3. View All Participants\n";
        cout << "4. View Financial Report\n";
        cout << "5. Exit\n";
        cout << "Select option: ";
        cin >> choice;

        switch (choice) {
            case 1: cms.registerAttendee(); break;
            case 2: cms.registerSpeaker(); break;
            case 3: cms.showAllParticipants(); break;
            case 4: cms.showTotalFees(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 5);

    return 0;
}