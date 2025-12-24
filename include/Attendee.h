#ifndef ATTENDEE_H
#define ATTENDEE_H

#include "Person.h"

class Attendee : public Person {
private:
    string organization;

public:
    Attendee(int id, string name, string email, string org);

    void display() const override;
    string getRole() const override;
    double calculateFee() const override;
    string toFileString() const override;
};

#endif