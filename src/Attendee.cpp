#include "../include/Attendee.h"
#include <sstream>

Attendee::Attendee(int id, string name, string email, string org)
    : Person(id, name, email), organization(org) {}

void Attendee::display() const {
    cout << *this << " | Role: Attendee | Org: " << organization << " | Fee: $150" << endl;
}

string Attendee::getRole() const {
    return "Attendee";
}

double Attendee::calculateFee() const {
    return 150.00;
}

string Attendee::toFileString() const {
    stringstream ss;
    ss << "A," << id << "," << name << "," << email << "," << organization;
    return ss.str();
}