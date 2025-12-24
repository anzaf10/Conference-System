#include "../include/Person.h"

Person::Person(int id, string name, string email) 
    : id(id), name(name), email(email) {}

int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

ostream& operator<<(ostream& os, const Person& p) {
    os << "ID: " << p.id << " | Name: " << p.name << " | Email: " << p.email;
    return os;
}

bool Person::operator==(const Person& other) const {
    return this->id == other.id;
}