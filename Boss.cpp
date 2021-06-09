//
// Created by Ali on 6/9/2021.
//

#include "Boss.h"

#include <iostream>

using namespace std;

Boss::Boss(const string &name, const string &id, const Address &address, int hourWork, int salaryPerHour, int workToDo,
           int workDone, int numberOfEmployee) : Employee(name, id, address, hourWork, salaryPerHour, workToDo,
           workDone), numberOfEmployee(numberOfEmployee) {}

Boss::Boss(const Person &person, Address address, const Employee &employee, const Boss &boss) : Employee(person, address, employee) {

    this->numberOfEmployee = boss.numberOfEmployee;
}

int Boss::getNumberOfEmployee() const {

    return numberOfEmployee;
}

void Boss::setNumberOfEmployee(int numberOfEmployee) {

    Boss::numberOfEmployee = numberOfEmployee;
}

Boss &Boss::operator=(const Boss &b) {

    this->setName(b.getName());
    this->setId(b.getId());
    this->setAddress(b.getAddress());
    this->setHourWork(b.getHourWork());
    this->setSalaryPerHour(b.getSalaryPerHour());
    this->setWorkToDo(b.getWorkToDo());
    this->setWorkDone(b.getWorkDone());
    numberOfEmployee = b.numberOfEmployee;
    return *this;
}

std::ostream &operator<<(ostream &o, const Boss &b) {
    o << "name-> " << b.getName() << ", id-> " << b.getId() << ", address-> " << b.getAddress() << endl
      << "hour work= " << b.getHourWork() << ", salary per hour= " << b.getSalaryPerHour() << ", work to do= " << b.getWorkToDo() << ", work done= " << b.getWorkDone() << "," << endl
      << "number of employee=> " << b.getNumberOfEmployee();
    return o;
}

std::istream &operator>>(istream &i, Boss &b) {

    int hourWork1, salaryPerHour1, workToDo1, workDone1;
    string name1, id1;
    int n;
    Address a("", "", "");
    Person p("", "92*sa11178", a);
    Employee e("", "92*sa11178", a, 1, 1, 1, 1);
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
    cout << "Enter number of employee: ";
    i >> n;
    b.setNumberOfEmployee(n);
    return i;

}

double Boss::calculateSalary() {

    double pay = getHourWork()*getSalaryPerHour();
    double cal = (double) (getWorkDone() / getWorkToDo());
    double res = (double) pay*cal*(115/100);
    return res;
}
