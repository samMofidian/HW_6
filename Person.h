//
// Created by Ali on 6/9/2021.
//

#ifndef HW6_PERSON_H
#define HW6_PERSON_H

#include "Address.h"

#include <iostream>

class Person {

private:

    std::string name;
    std::string id;
    Address address;

    //validate (utility function)
    bool validate(const std::string &id, const std::string &pattern0, const std::string &pattern1);

public:

    //constructor
    Person(const std::string &name, const std::string &id, const Address &address);

    //copy constructor
    Person(const Person &person, Address address);

    //assignment operator
    Person& operator =(const Person& p);

    //getters and setters
    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getId() const;

    void setId(const std::string &id);

    const Address &getAddress() const;

    void setAddress(const Address &address);

    //extraction and insertion operator
    friend std::ostream& operator <<(std::ostream& o, const Person& p);

    friend std::istream& operator >>(std::istream& i, Person& p);

};


#endif //HW6_PERSON_H
