#include "Address.h"
#include "Person.h"
#include "Employee.h"

#include <iostream>

using namespace std;

int main() {

    Address b("t", "q", "f");

    Employee e("s", "92*wc22439", b , 1, 1, 1, 1);

    cin >> e;
    cout << e;

    return 0;
}
