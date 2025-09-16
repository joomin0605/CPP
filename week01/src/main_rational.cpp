#include <iostream>
#include <numeric>
#include <stdexcept>

using namespace std;

class Rational {
    long long num;
    long long den;

public:
    Rational(long long n = 0, long long d = 1) : num(n), den(d) {
        if (den == 0) throw invalid_argument("Denominator cannot be zero");
        normalize();
    }

    void normalize() {
        if (den < 0) { num = -num; den = -den; }
        long long g= gcd(num, den);
        num /= g;
        den /= g;
    }

    Rational operator+(const Rational& o) const { return Rational(num * o.den + o.num * den, den * o.den); }
    Rational operator-(const Rational& o) const { return Rational(num * o.den - o.num * den, den * o.den); }
    Rational operator*(const Rational& o) const { return Rational(num * o.num, den * o.den); }
    Rational operator/(const Rational& o) const { return Rational(num * o.den, den * o.num); }

    bool operator==(const Rational& o) const { return num == o.num && den == o.den; }
    bool operator!=(const Rational& o) const { return !(*this == o); }

    friend ostream& operator<<(ostream& os, const Rational& r) {
        return os << r.num << "/" << r.den;
    }
};

int main() {
    Rational a(2, 4);
    Rational b(1, 3);
    Rational c = a + b;
    Rational d = a * b;

    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "a + b = " << c << "\n";
    cout << "a * b = " << d << "\n";

    if (c == Rational(5, 6)) cout << "c == 5/6";
}