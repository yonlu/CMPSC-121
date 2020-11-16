#include <iostream>
#include <string>
#include <iomanip>

struct EmployeePay {
    std::string name;
    int empNum;
    double payRate;
    double hours;
    double grossPay;
};

int main() {
    EmployeePay employee1 = {"Betty Ross", 141, 18.75};
    EmployeePay employee2 = {"Jill Sandburg", 142, 17.50};

    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << "Name: " << employee1.name << std::endl;
    std::cout << "Employee Number: " << employee1.empNum << std::endl;
    std::cout << "Enter the number of hours worked by this employee: ";
    std::cin >> employee1.hours;
    employee1.grossPay = employee1.hours * employee1.payRate;
    std::cout << "Gross Pay: " << employee1.grossPay << std::endl;

    std::cout << std::endl;

    std::cout << "Name: " << employee2.name << std::endl;
    std::cout << "Employee Number: " << employee2.empNum << std::endl;
    std::cout << "Enter the number of hours worked by this employee: ";
    std::cin >> employee2.hours;
    employee2.grossPay = employee2.hours * employee2.payRate;
    std::cout << "Gross Pay: " << employee2.grossPay << std::endl;

    return 0;
}
