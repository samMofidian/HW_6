//
// Created by Ali on 6/9/2021.
//

#ifndef MAIN_CPP_BOSS_H
#define MAIN_CPP_BOSS_H

#include "Employee.h"

#include <iostream>

class Boss : public Employee {

private:

    int numberOfEmployee;

public:

    //constructor
    Boss(const std::string &name, const std::string &id, const Address &address, int hourWork, int salaryPerHour,
         int workToDo, int workDone, int numberOfEmployee);

    //copy constructor
    Boss(const Person &person, Address address, const Employee &employee, const Boss &boss);

    //setter and getter
    int getNumberOfEmployee() const;

    void setNumberOfEmployee(int numberOfEmployee);

    //assignment operator
    Boss& operator =(const Boss& b);

    //extraction and insertion operator
    friend std::ostream& operator <<(std::ostream& o, const Boss& b);

    friend std::istream& operator >>(std::istream& i, Boss& b);

    //function
    double calculateSalary();


};


#endif //MAIN_CPP_BOSS_H
