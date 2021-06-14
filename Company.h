//
// Created by Ali on 6/11/2021.
//

#ifndef MAIN_CPP_COMPANY_H
#define MAIN_CPP_COMPANY_H

#include <ostream>
#include "Boss.h"

class Company {

private:

    int budget;
    Boss *boss;
    Employee **employee;

public:

    //constructor
    Company(int budget, Boss boss, Employee e[]);

    //copy constructor
    Company(const Company &company);

    //destructor
    virtual ~Company();

    //getters and setters
    int getBudget() const;

    void setBudget(int budget);

    Boss getBoss() const;

    void setBoss(Boss boss);

    Employee **getEmployee() const;

    void setEmployee(Employee *employee);

    //functions
    Employee maxEfficiency();

    double averageEfficiency();

    void payForService();

    void gift();

    bool isEnoughBudget();

    void changeBoss();

    //io stream
    friend std::ostream &operator<<(std::ostream &os, const Company &company);

    friend std::istream& operator>>(std::istream &is, Company &company);

};


#endif //MAIN_CPP_COMPANY_H
