#include "complex.h"
#include <cmath>
#include <iostream>


Complex::Complex() : re(0), im(0) {
}

Complex::Complex(double x, double y) : re(x), im(y) {
}

Complex::Complex(const Complex &other) : re(other.re), im(other.im) {
}

Complex &Complex::operator=(const Complex &other) {
    if (this != &other) {
        re = other.re;
        im = other.im;
    }
    return *this;
}

Complex Complex::operator+(const Complex &other) const {
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex &other) const {
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex &other) const {
    return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
}

Complex Complex::operator/(const Complex &other) const {
    double denominator = other.re * other.re + other.im * other.im;
    if (denominator == 0) {
        // Вместо выбрасывания исключения, возвращаем нулевой комплексный номер
        return Complex(0, 0);
    }
    return Complex((re * other.re + im * other.im) / denominator,
                   (im * other.re - re * other.im) / denominator);
}

Complex &Complex::operator++() {
    ++re;
    ++im;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    ++(*this);
    return temp;
}

Complex &Complex::operator--() {
    --re;
    --im;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    --(*this);
    return temp;
}

bool Complex::operator>(const Complex &other) const {
    return modulus() > other.modulus();
}

bool Complex::operator<(const Complex &other) const {
    return modulus() < other.modulus();
}

bool Complex::operator==(const Complex &other) const {
    return re == other.re && im == other.im;
}

bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

double Complex::modulus() const {
    return sqrt(re * re + im * im);
}

std::ostream &operator<<(std::ostream &os, const Complex &c) {
    os << c.re;
    if (c.im >= 0) {
        os << " + " << c.im << "*i";
    } else {
        os << " - " << -c.im << "*i";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Complex &c) {
    is >> c.re >> c.im;

    if (is.fail()) {
        char sign, i;
        is >> c.re >> sign >> c.im >> i;

        if (is.fail()) {
            is.setstate(std::ios::failbit);
            return is;
        }

        if (sign == '-') {
            c.im = -c.im;
        }
    }
    return is;
}
