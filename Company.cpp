//
// Created by Ali on 6/11/2021.
//

#include "Company.h"

#include <iostream>
#include <cstring>

using namespace std;

Company::Company(int budget, Boss boss, Employee employee) : budget(budget) {

    this->boss = new Boss(boss);
    this->employee = new Employee *(reinterpret_cast<Employee *>(boss.getNumberOfEmployee()));
    for (int i = 0; i < boss.getNumberOfEmployee(); ++i) {
        this->employee[i] = new Employee(employee);
    }

}

Company::Company(const Company &company) {

    boss = new Boss(*company.boss);
}

Company::~Company() {

    delete boss;
    for (int i = 0; i < boss->getNumberOfEmployee(); ++i) {
        delete [] employee[i];
    }
    delete [] employee;
}

int Company::getBudget() const {

    return budget;
}

void Company::setBudget(int budget) {

    Company::budget = budget;
}

Boss Company::getBoss() const {

    return *boss;
}

void Company::setBoss(Boss boss) {

    *Company::boss = boss;
}



void Company::setEmployee(Employee *employee) {

    **this->employee = *employee;
}

Employee **Company::getEmployee() const {

    return employee;
}

Employee Company::maxEfficiency(int NOB) {

    int maxElement = 0;
    for (int i = 0; i < NOB; i++) {
        for (int j = 0; j < boss[i].getNumberOfEmployee(); j++) {
            if (employee[i][j].efficiency() > maxElement) {
                maxElement = employee[i][j].efficiency();
            }
        }
    }
    for (int i = 0; i < NOB; i++) {
        for (int j = 0; j < boss[i].getNumberOfEmployee(); j++) {
            if (employee[i][j].efficiency() == maxElement) {
                return employee[i][j];
            }
        }
    }
}

double Company::averageEfficiency(int NOB) {

    double sum = 0;
    for (int i = 0; i < NOB; i++) {
        for (int j = 0; j < boss[i].getNumberOfEmployee(); j++) {
                sum += employee[i][j].efficiency();
        }
    }
    double count = 0;
    for (int i = 0; i < NOB; i++) {
        for (int j = 0; j < boss[i].getNumberOfEmployee(); j++) {
            count++;
        }
    }
    return (sum/count);
}

void Company::payForService(int NOB) {

    for (int i = 0; i < NOB; i++) {
        for (int j = 0; j < boss[i].getNumberOfEmployee(); j++) {
            if (employee[i][j].getAddress().getCity() != "tehran") {
                employee[i][j].setHourWork(7 + employee[i][j].getHourWork());
            }
        }
    }
}

void Company::gift(int NOB) {

    for (int i = 0; i < NOB; i++) {
        for (int j = 0; j < boss[i].getNumberOfEmployee(); j++) {
            if (employee[i][j].getId()[0] == 8) {
                employee[i][j].setHourWork(5 + employee[i][j].getHourWork());
                if ((employee[i][j]) == maxEfficiency(NOB)){
                    employee[i][j].setHourWork(5 + employee[i][j].getHourWork());
                }
            }
        }
    }
}

bool Company::isEnoughBudget(int NOB) {

    int sum = 0;
    for (int i = 0; i < NOB; i++) {
        sum += boss[i].calculateSalary();
        for (int j = 0; j < boss[i].getNumberOfEmployee(); j++) {
            sum += employee[i][j].calculateSalary();
        }
    }
    if(sum == budget)
        return true;
    else
        return false;
}


