#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person {
protected:
    int id;
    string name;
    string email;

public:
    Person(int id, string name, string email);
    virtual ~Person() {}

    int getId() const;
    string getName() const;

    virtual void display() const = 0;
    virtual string getRole() const = 0;
    virtual double calculateFee() const = 0;
    virtual string toFileString() const = 0;

    friend ostream& operator<<(ostream& os, const Person& p);
    bool operator==(const Person& other) const;
};

#endif