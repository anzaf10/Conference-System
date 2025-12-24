#ifndef SPEAKER_H
#define SPEAKER_H

#include "Person.h"

class Speaker : public Person {
private:
    string topic;

public:
    Speaker(int id, string name, string email, string topic);

    void display() const override;
    string getRole() const override;
    double calculateFee() const override;
    string toFileString() const override;
};

#endif