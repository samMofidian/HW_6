//
// Created by Ali on 6/9/2021.
//

#ifndef HW6_EMPLOYEE_H
#define HW6_EMPLOYEE_H

#include "Person.h"

#include <iostream>

class Employee : public Person {

private:

    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;

    //validate (utility function)
    virtual bool validate(const std::string &id);

public:

    //constructor
    Employee(const std::string &name, const std::string &id, const Address &address, int hourWork, int salaryPerHour, int workToDo, int workDone);

    //copy constructor
    Employee(const Person &person, Address address, const Employee &employee);

    //extraction and insertion operator
    friend std::ostream& operator <<(std::ostream& o, const Employee& e);

    friend std::istream& operator >>(std::istream& i, Employee& e);

    //getters and setters
    int getHourWork() const;

    void setHourWork(int hourWork);

    int getSalaryPerHour() const;

    void setSalaryPerHour(int salaryPerHour);

    int getWorkToDo() const;

    void setWorkToDo(int workToDo);

    int getWorkDone() const;

    void setWorkDone(int workDone);

    //assignment operator
    Employee& operator =(const Employee& e);

    //functions
    double calculateSalary();

    double efficiency();

    //binary bool operator
    friend bool operator ==(const Employee& e1, const Employee& e2);

};


#endif //HW6_EMPLOYEE_H
