#include <iostream>
#include "complex.h"
#include <windows.h>

using namespace std;

void clearInput() {
    while (cin.get() != '\n') {
        continue;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Complex a, b;

    cout << "Программа для работы с комплексными числами\n";
    cout << "Формат ввода: действительная_часть мнимая_часть (через пробел)\n";
    cout << "Или: действительная_часть + мнимая_часть * i\n\n";

    while (true) {
        cout << "Введите первое комплексное число: ";
        if (cin >> a) {
            break;
        }
        cout << "Ошибка ввода! Пожалуйста, введите в правильном формате.\n";
        clearInput();
    }

    while (true) {
        cout << "Введите второе комплексное число: ";
        if (cin >> b) {
            break;
        }
        cout << "Ошибка ввода! Пожалуйста, введите в правильном формате.\n";
        clearInput();
    }

    cout << "\nРезультаты операций:\n";
    cout << "--------------------------------\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl << endl;

    cout << "Арифметические операции:\n";
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;

    try {
        cout << "a / b = " << a / b << endl;
    } catch (const runtime_error &e) {
        cout << "a / b = Ошибка: " << e.what() << endl;
    }

    cout << "\nИнкремент и декремент:\n";
    Complex a_inc = a, b_inc = b;
    cout << "++a = " << ++a_inc << " (исходное: " << a << ")\n";
    cout << "a++ = " << a_inc++ << " (после: " << a_inc << ")\n";

    Complex a_dec = a, b_dec = b;
    cout << "--b = " << --b_dec << " (исходное: " << b << ")\n";
    cout << "b-- = " << b_dec-- << " (после: " << b_dec << ")\n";

    cout << "\nСравнение по модулю:\n";
    cout << "|a| = " << a.modulus() << ", |b| = " << b.modulus() << endl;
    cout << "a > b? " << (a > b ? "Да" : "Нет") << endl;
    cout << "a < b? " << (a < b ? "Да" : "Нет") << endl;
    cout << "a == b? " << (a == b ? "Да" : "Нет") << endl;
    cout << "a != b? " << (a != b ? "Да" : "Нет") << endl;

    Complex c = a;
    cout << "\nТест копирования:\n";
    cout << "c (копия a) = " << c << endl;

    return 0;
}
