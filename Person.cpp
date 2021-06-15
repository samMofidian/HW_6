//
// Created by Ali on 6/9/2021.
//

#include "Person.h"

#include <iostream>
#include <regex>

using namespace std;

Person::Person(const string &name, const string &id, const Address &address) : address(address) {

    if (!validate(id))
    {
        cout << "invalid id";
        exit(1);
    }
    else
    {
       this->name = name;
       this->id = id;
    }

}


Person::Person(const Person &person, Address address) : address(address) {

    this->name = person.name;
    this->id = person.id;
}

const string &Person::getName() const {

    return name;
}

void Person::setName(const string &name) {

    Person::name = name;
}

const string &Person::getId() const {

    return id;
}

void Person::setId(const string &id) {

    if (!validate(id))
    {
        cout << "invalid id";
        exit(1);
    }
    else
    {
        Person::id = id;
    }

}

const Address &Person::getAddress() const {

    return address;
}

void Person::setAddress(const Address &address) {

    Person::address = address;
}

Person &Person::operator=(const Person &p) {

    name = p.name;
    id = p.id;
    address = p.address;
    return *this;
}

ostream& operator <<(ostream& o, const Person& p) {

    o << "name-> " << p.getName() << ", id-> " << p.getId() << ", address-> " << p.getAddress();
    return o;
}

istream& operator >>(istream& i, Person& p) {

    string name1, id1;
    Address a("", "", "");
    cout << "Enter name: ";
    i >> name1;
    cout << "Enter id: ";
    i >> id1;
    cout << "Enter address: " << endl;
    i >> a;
    p.setName(name1);
    p.setId(id1);
    p.setAddress(a);
    return i;
}

bool Person::validate(const string &id) {

    const string &pattern0 = "[8]{1}[4-9]{1}[\\D]{1,3}[0-37-9]{5}";
    const string &pattern1 = "[9]{1}[0-9]{1}[\\D]{1,3}[0-37-9]{5}";
    regex regPattern0(pattern0);
    regex regPattern1(pattern1);
    bool flag = false;
    if (strcmp(reinterpret_cast<const char *>(id[0]), "8") == 0)
    {
        flag = regex_match(id, regPattern0);
    }
    else if (strcmp(reinterpret_cast<const char *>(id[0]), "8") == 0)
    {
        flag = regex_match(id, regPattern1);
    }
    if (flag == 1)
        flag = true;
    return flag;
}


