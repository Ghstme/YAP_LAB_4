#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b);

    void reduce();

public:
    Rational(int num = 0, int denom = 1);

    int Numerator() const;

    int Denominator() const;

    Rational operator+(const Rational &other) const;

    Rational operator+(int value) const;

    Rational operator-(const Rational &other) const;

    Rational operator-(int value) const;

    Rational operator*(const Rational &other) const;

    Rational operator*(int value) const;

    Rational operator/(const Rational &other) const;

    Rational operator/(int value) const;

    Rational operator+() const;

    Rational operator-() const;

    Rational &operator+=(const Rational &other);

    Rational &operator-=(const Rational &other);

    Rational &operator*=(const Rational &other);

    Rational &operator/=(const Rational &other);

    bool operator==(const Rational &other) const;

    bool operator!=(const Rational &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Rational &r);

    friend std::istream &operator>>(std::istream &is, Rational &r);
};

#endif // RATIONAL_H
