//
// Created by Ali on 6/9/2021.
//

#include "Address.h"

#include <iostream>

using namespace std;

Address::Address(const std::string &country, const std::string &city, const std::string &street) :
    country(country), city(city), street(street) {}

const std::string &Address::getCountry() const {

    return country;
}

const std::string &Address::getCity() const {

    return city;
}

const std::string &Address::getStreet() const {

    return street;
}

void Address::setCountry(const std::string &country) {

    Address::country = country;
}

void Address::setCity(const std::string &city) {

    Address::city = city;
}

void Address::setStreet(const std::string &street) {

    Address::street = street;
}

ostream& operator <<(ostream& o, const Address& a) {

    o << "country: " << a.getCountry() << ", city: " << a.getCity() << ", street: " << a.getStreet();
    return o;
}

istream& operator >>(istream& i, Address& a) {

    string country1, city1, street1;
    cout << "Enter country: ";
    i >> country1;
    cout << "Enter city: ";
    i >> city1;
    cout << "Enter street: ";
    i >> street1;
    a.setCountry(country1);
    a.setCity(city1);
    a.setStreet(street1);
    return i;
}