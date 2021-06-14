//
// Created by Ali on 6/11/2021.
//

#include "Company.h"

#include <iostream>
#include <cstring>

using namespace std;

Company::Company(int budget, Boss boss, Employee e[]) : budget(budget) {

    this->boss = new Boss(boss);
    this->employee = new Employee *[boss.getNumberOfEmployee()];
    for (int i = 0; i < boss.getNumberOfEmployee(); ++i) {
        this->employee[i] = new Employee(e[i]);
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

Employee Company::maxEfficiency() {

    int maxElement = 0;
    for (int j = 0; j < boss->getNumberOfEmployee(); j++) {
        if (employee[j]->efficiency() > maxElement) {
            maxElement = employee[j]->efficiency();
        }
    }
    for (int j = 0; j < boss->getNumberOfEmployee(); j++) {
        if (employee[j]->efficiency() == maxElement) {
            return *employee[j];
        }
    }
}

double Company::averageEfficiency() {

    double sum = 0;
    for (int j = 0; j < boss->getNumberOfEmployee(); j++) {
        sum += employee[j]->efficiency();
    }
    return (sum/boss->getNumberOfEmployee());
}

void Company::payForService() {

    for (int j = 0; j < boss->getNumberOfEmployee(); j++) {
        if (employee[j]->getAddress().getCity() != "tehran") {
            employee[j]->setHourWork(7 + employee[j]->getHourWork());
        }
    }
}


void Company::gift() {

    for (int j = 0; j < boss->getNumberOfEmployee(); j++) {
        if (employee[j]->getId()[0] == 8) {
            employee[j]->setHourWork(5 + employee[j]->getHourWork());
            if ((*employee[j]) == maxEfficiency()){
                employee[j]->setHourWork(5 + employee[j]->getHourWork());
            }
        }
    }
}


bool Company::isEnoughBudget() {

    int sum = 0;
    for (int j = 0; j < boss->getNumberOfEmployee(); j++) {
        sum += employee[j]->calculateSalary();
    }
    if(sum == budget)
        return true;
    else
        return false;
}

void Company::changeBoss() {

    if(boss->efficiency() < 40)
    {
        *boss = maxEfficiency();
    }
}

ostream &operator<<(ostream &os, const Company &company) {
    os << "budget: " << company.budget << " boss: " << company.boss << endl;
    for (int i = 0; i < company.boss->getNumberOfEmployee(); ++i) {
        os << " employee: " << company.employee[i] << "\t";
    }
    return os;
}

std::istream &operator>>(istream &i, Company &c) {

    int hourWork1, salaryPerHour1, workToDo1, workDone1;
    string name1, id1;
    int n;
    Address a("", "", "");
    Person p("", "92*sa11178", a);
    Employee e("", "92*sa11178", a, 1, 1, 1, 1);
    Boss b("", "92*sa11178", a, 1, 1, 1, 1, 1);
    cout << "Enter Boss: " << endl;
    cout << "Enter name: ";
    i >> name1;
    cout << "Enter id: ";
    i >> id1;
    cout << "Enter address: " << endl;
    i >> a;
    b.setName(name1);
    b.setId(id1);
    b.setAddress(a);
    cout << "Enter hour work: ";
    i >> hourWork1;
    cout << "Enter salary per hour: ";
    i >> salaryPerHour1;
    cout << "Enter work to do: ";
    i >> workToDo1;
    cout << "Enter work done: ";
    i >> workDone1;
    b.setSalaryPerHour(salaryPerHour1);
    b.setHourWork(hourWork1);
    b.setWorkDone(workDone1);
    b.setWorkToDo(workToDo1);
    cout << "Enter number of employee: ";
    i >> n;
    b.setNumberOfEmployee(n);
    Employee *ee;
    for (int j = 0; j < c.boss->getNumberOfEmployee(); ++j) {
        cout << "Enter name: ";
        i >> name1;
        cout << "Enter id: ";
        i >> id1;
        cout << "Enter address: " << endl;
        i >> a;
        ee[j].setName(name1);
        ee[j].setId(id1);
        ee[j].setAddress(a);
        cout << "Enter hour work: ";
        i >> hourWork1;
        cout << "Enter salary per hour: ";
        i >> salaryPerHour1;
        cout << "Enter work to do: ";
        i >> workToDo1;
        cout << "Enter work done: ";
        i >> workDone1;
        ee[j].setSalaryPerHour(salaryPerHour1);
        ee[j].setHourWork(hourWork1);
        ee[j].setWorkDone(workDone1);
        ee[j].setWorkToDo(workToDo1);
    }
    return i;
}


