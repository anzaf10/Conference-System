#include "../include/Speaker.h"
#include <sstream>

Speaker::Speaker(int id, string name, string email, string topic)
    : Person(id, name, email), topic(topic) {}

void Speaker::display() const {
    cout << *this << " | Role: Speaker | Topic: " << topic << " | Fee: $0 (Waived)" << endl;
}

string Speaker::getRole() const {
    return "Speaker";
}

double Speaker::calculateFee() const {
    return 0.00;
}

string Speaker::toFileString() const {
    stringstream ss;
    ss << "S," << id << "," << name << "," << email << "," << topic;
    return ss.str();
}