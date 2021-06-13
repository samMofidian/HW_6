//
// Created by Ali on 6/11/2021.
//

#ifndef MAIN_CPP_COMPANY_H
#define MAIN_CPP_COMPANY_H

#include "Boss.h"

class Company {

private:

    int budget;
    Boss *boss;
    Employee **employee;

public:

    //constructor
    Company(int budget, Boss boss, Employee employee);

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
    Employee maxEfficiency(int NOB); //NOB -> Number Of Bosses

    double averageEfficiency(int NOB);

    void payForService(int NOB);

    void gift(int NOB);

    bool isEnoughBudget(int NOB);

};


#endif //MAIN_CPP_COMPANY_H
