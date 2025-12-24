#include "../include/Manager.h"
#include <fstream>
#include <sstream>

ConferenceManager::ConferenceManager() {
    loadFromFile();
}

ConferenceManager::~ConferenceManager() {
    for (Person* p : participants) {
        delete p;
    }
    participants.clear();
}

void ConferenceManager::registerAttendee() {
    int id;
    string name, email, org;
    cout << "\nEnter ID: "; cin >> id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, name);
    cout << "Enter Email: "; cin >> email;
    cin.ignore();
    cout << "Enter Organization: "; getline(cin, org);

    participants.push_back(new Attendee(id, name, email, org));
    cout << "Attendee registered successfully.\n";
    saveToFile();
}

void ConferenceManager::registerSpeaker() {
    int id;
    string name, email, topic;
    cout << "\nEnter ID: "; cin >> id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, name);
    cout << "Enter Email: "; cin >> email;
    cin.ignore();
    cout << "Enter Topic: "; getline(cin, topic);

    participants.push_back(new Speaker(id, name, email, topic));
    cout << "Speaker registered successfully.\n";
    saveToFile();
}

void ConferenceManager::showAllParticipants() const {
    if (participants.empty()) {
        cout << "No registrations found.\n";
        return;
    }
    cout << "\n--- Registration List ---\n";
    for (const auto& p : participants) {
        p->display();
    }
    cout << "-------------------------\n";
}

void ConferenceManager::showTotalFees() const {
    double total = 0;
    for (const auto& p : participants) {
        total += p->calculateFee();
    }
    cout << "\nTotal Revenue from Registrations: $" << total << endl;
}

void ConferenceManager::saveToFile() {
    ofstream outFile(filename);
    if (!outFile) return;

    for (const auto& p : participants) {
        outFile << p->toFileString() << endl;
    }
    outFile.close();
}

void ConferenceManager::loadFromFile() {
    ifstream inFile(filename);
    if (!inFile) return;

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string typeStr, idStr, name, email, extra;
        
        getline(ss, typeStr, ',');
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, extra, ',');

        if (typeStr == "A") {
            participants.push_back(new Attendee(stoi(idStr), name, email, extra));
        } else if (typeStr == "S") {
            participants.push_back(new Speaker(stoi(idStr), name, email, extra));
        }
    }
    inFile.close();
}