#include "Address.h"
#include "Person.h"
#include "Employee.h"
#include "Boss.h"
#include "Company.h"

#include <iostream>

using namespace std;

int main() {

    /*
    Address a0("", "", "");
    cin >> a0;
    cout << a0 << endl;
    Person p0("e", "91qef12389", a0);
    cin >> p0;
    cout << p0 << endl;
    p0.setName("ali");
    cout << p0.getName() << endl;
    Employee e0("sma", "98*ab11789", a0, 8,30,4,1);
    cout << e0.calculateSalary() << endl;
    cout << e0.efficiency() << endl;
    cout << e0;
     */
    //and ... (other functions & ...)

    //Company build
    Address a("iran", "babol", "meraj");
    Address a1("iran", "tehran", "valiasr");
    Person p("e", "97qef12389", a);
    Employee e1("s", "98*ab11789", a, 2,10,4,2);
    Employee e2("d", "99*ab11789", a1, 2,10,4,2);
    Employee e3("f", "91*ab11789", a, 2,10,4,2);
    Employee e4("g", "97*ab23789", a, 2,10,4,3);
    Employee e5("j", "91*sd11789", a, 2,10,4,2);
    Employee e6("r", "91*a11789", a, 2,10,4,2);
    Employee e7("k", "95*we01789", a, 2,10,4,2);
    Employee e8("a", "94*ab11989", a, 2,10,4,2);
    Employee e9("c", "94*ab11189", a, 2,10,4,2);
    Employee e10("x", "92*a11789", a1, 2,10,4,2);
    Boss b("sam", "89*ab11789", a, 2,10,4,2,3);
    Employee *e;
    e[0] = e1;
    e[1] = e2;
    e[2] = e3;
    e[3] = e4;
    e[4] = e5;
    e[5] = e6;
    e[6] = e7;
    e[7] = e8;
    e[8] = e9;
    e[9] = e10;
    Company c(789,b,e);
    cout << c.getBudget() << endl;
    c.setBudget(897);
    cout << c.getBudget() << endl;
    cout << c.maxEfficiency() << endl;
    cout << c.averageEfficiency() << endl;
    c.gift();
    cout << e[1].getHourWork() << "\t" << e[9].getHourWork() << "\t" << e[3].getHourWork() << "\t" << endl;
    c.payForService();
    cout << e[1].getHourWork() << "\t" << e[9].getHourWork() << "\t" << e[3].getHourWork() << "\t" << endl;
    cout << boolalpha << c.isEnoughBudget();


    return 0;
}
