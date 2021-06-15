//
// Created by Ali on 6/9/2021.
//

#include "Employee.h"

#include <iostream>
#include <regex>

using namespace std;

Employee::Employee(const string &name, const string &id, const Address &address, int hourWork, int salaryPerHour,int workToDo, int workDone) :
    Person(name, id, address), hourWork(hourWork),salaryPerHour(salaryPerHour), workToDo(workToDo), workDone(workDone) {

    if (!validate(id))
    {
        cout << "invalid id";
        exit(1);
    }
}

Employee::Employee(const Person &person, Address address, const Employee &employee) : Person(person, address) {

    this->hourWork = employee.hourWork;
    this->salaryPerHour = employee.salaryPerHour;
    this->workToDo = employee.workToDo;
    this->workDone = employee.workDone;

}

std::ostream &operator<<(ostream &o, const Employee &e) {

    o << "name-> " << e.getName() << ", id-> " << e.getId() << ", address-> " << e.getAddress() << endl
        << "hour work= " << e.getHourWork() << ", salary per hour= " << e.getSalaryPerHour() << ", work to do= " << e.getWorkToDo() << ", work done= " << e.getWorkDone();
    return o;
}

std::istream &operator>>(istream &i, Employee &e) {

    int hourWork1, salaryPerHour1, workToDo1, workDone1;
    string name1, id1;
    Address a("", "", "");
    Person p("", "92*sa11178", a);
    cout << "Enter name: ";
    i >> name1;
    cout << "Enter id: ";
    i >> id1;
    cout << "Enter address: " << endl;
    i >> a;
    p.setName(name1);
    p.setId(id1);
    p.setAddress(a);
    cout << "Enter hour work: ";
    i >> hourWork1;
    cout << "Enter salary per hour: ";
    i >> salaryPerHour1;
    cout << "Enter work to do: ";
    i >> workToDo1;
    cout << "Enter work done: ";
    i >> workDone1;
    e.setSalaryPerHour(salaryPerHour1);
    e.setHourWork(hourWork1);
    e.setWorkDone(workDone1);
    e.setWorkToDo(workToDo1);
    return i;
}

int Employee::getHourWork() const {

    return hourWork;
}

void Employee::setHourWork(int hourWork) {

    Employee::hourWork = hourWork;
}

int Employee::getSalaryPerHour() const {

    return salaryPerHour;
}

void Employee::setSalaryPerHour(int salaryPerHour) {

    Employee::salaryPerHour = salaryPerHour;
}

int Employee::getWorkToDo() const {

    return workToDo;
}

void Employee::setWorkToDo(int workToDo) {

    Employee::workToDo = workToDo;
}

int Employee::getWorkDone() const {

    return workDone;
}

void Employee::setWorkDone(int workDone) {

    Employee::workDone = workDone;
}

bool Employee::validate(const string &id) {

    const string &pattern0 = "[8]{1}[4-9]{1}[*]{1}[\\D]{1,2}[0-37-9]{5}";
    const string &pattern1 = "[9]{1}[0-9]{1}[*]{1}[\\D]{1,2}[0-37-9]{5}";
    regex regPattern0(pattern0);
    regex regPattern1(pattern1);
    bool flag = false;
    if (strcmp(reinterpret_cast<const char *>(id[0]), "8") == 0)
    {
        flag = regex_match(id, regPattern0);
    }
    else if (strcmp(reinterpret_cast<const char *>(id[0]), "9") == 0)
    {
        flag = regex_match(id, regPattern1);
    }
    return flag;
}

Employee &Employee::operator=(const Employee &e) {

    this->setName(e.getName());
    this->setId(e.getId());
    this->setAddress(e.getAddress());
    hourWork = e.hourWork;
    salaryPerHour = e.salaryPerHour;
    workDone = e.workDone;
    workToDo = e.workToDo;
    return *this;
}

double Employee::calculateSalary() {

    double pay = hourWork*salaryPerHour;
    double cal = (double) ((double)workDone / (double)workToDo);
    double res = pay*cal;
    return res;
}

double Employee::efficiency() {

    double res = (double) ((double)(this->getWorkDone() / (double) this->getWorkToDo()) / this->getHourWork()) * 100;
    return res;
}

bool operator==(const Employee &e1, const Employee &e2) {

    if (e1.getId() == e2.getId())
        return true;
    else
        return false;
}
