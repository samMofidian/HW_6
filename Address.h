//
// Created by Ali on 6/9/2021.
//

#ifndef HW6_ADDRESS_H
#define HW6_ADDRESS_H

#include <iostream>

class Address {

private:

    std::string country;
    std::string city;
    std::string street;

public:

    //constructor
    Address(const std::string &country, const std::string &city, const std::string &street);

    //getter and setter
    void setCountry(const std::string &country);

    void setCity(const std::string &city);

    void setStreet(const std::string &street);

    const std::string &getCountry() const;

    const std::string &getCity() const;

    const std::string &getStreet() const;

    //extraction and insertion operator
    friend std::ostream& operator <<(std::ostream& o, const Address& a);

    friend std::istream& operator >>(std::istream& i, Address& a);

};


#endif //HW6_ADDRESS_H
