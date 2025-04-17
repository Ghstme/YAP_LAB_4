#include "Rational.h"

int Rational::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        denominator = 1;
    }
    reduce();
}

void Rational::reduce() {
    if (denominator == 0) {
        return;
    }

    int gcdValue = gcd(numerator, denominator);
    numerator /= gcdValue;
    denominator /= gcdValue;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

int Rational::Numerator() const {
    return numerator;
}

int Rational::Denominator() const {
    return denominator;
}

Rational Rational::operator+(const Rational &other) const {
    return Rational(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
}

Rational Rational::operator+(int value) const {
    return *this + Rational(value);
}

Rational Rational::operator-(const Rational &other) const {
    return Rational(numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator);
}

Rational Rational::operator-(int value) const {
    return *this - Rational(value);
}

Rational Rational::operator*(const Rational &other) const {
    return Rational(numerator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator*(int value) const {
    return *this * Rational(value);
}

Rational Rational::operator/(const Rational &other) const {
    if (other.numerator == 0) {
        return Rational(numerator, 1);
    }
    return Rational(numerator * other.denominator, denominator * other.numerator);
}

Rational Rational::operator/(int value) const {
    if (value == 0) {
        return *this;
    }
    return *this / Rational(value);
}

Rational Rational::operator+() const {
    return *this;
}

Rational Rational::operator-() const {
    return Rational(-numerator, denominator);
}

Rational &Rational::operator+=(const Rational &other) {
    *this = *this + other;
    return *this;
}

Rational &Rational::operator-=(const Rational &other) {
    *this = *this - other;
    return *this;
}

Rational &Rational::operator*=(const Rational &other) {
    *this = *this * other;
    return *this;
}

Rational &Rational::operator/=(const Rational &other) {
    if (other.numerator == 0) {
        return *this;
    }
    *this = *this / other;
    return *this;
}

bool Rational::operator==(const Rational &other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Rational::operator!=(const Rational &other) const {
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &os, const Rational &r) {
    os << r.numerator << "/" << r.denominator;
    return os;
}

std::istream &operator>>(std::istream &is, Rational &r) {
    char slash;
    is >> r.numerator >> slash >> r.denominator;

    if (r.denominator == 0) {
        r.denominator = 1;
    }

    r.reduce();
    return is;
}
