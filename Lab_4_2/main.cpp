#include <iostream>
#include "Rational.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Rational r1, r2;

    std::cout << "Введите первую дробь (числитель/знаменатель): ";
    std::cin >> r1;

    std::cout << "Введите вторую дробь (числитель/знаменатель): ";
    std::cin >> r2;

    Rational r3 = r1 + r2;
    std::cout << "r1 + r2 = " << r3 << std::endl;

    Rational r4 = r1 - r2;
    std::cout << "r1 - r2 = " << r4 << std::endl;

    Rational r5 = r1 * r2;
    std::cout << "r1 * r2 = " << r5 << std::endl;

    Rational r6 = r1 / r2;
    std::cout << "r1 / r2 = " << r6 << std::endl;

    return 0;
}
