#include <iostream>
#include <string>

using namespace std;

template <typename T>
void printType(T x) {
    cout << "Generic print: " << x << "\n";
}

template <>
void printType<int>(int x) {
    cout << "Specialized print for int: " << x << endl;
}

template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    void print() { cout << "Generic Box: " << value << endl; }
};

template <>
class Box<string> {
    string value;
public:
    Box(string v) : value(v){}
    void print() { cout << "Specialized Box<string>: " << value << endl; }
};

template <typename T, typename U>
class Pair {
    T first;
    U second;
public:
    Pair(T a, U b) : first(a), second(b) {}
    void print() { cout << "Generic Pair\n"; }
};

template <typename T>
class Pair<T, T> {
    T first, second;
public:
    Pair(T a, T b) : first(a), second(b) {}
    void print() { cout << "Pair of same type: " << first << ", " << second << endl; }
};

int main() {
    printType(3.14);
    printType(42);

    Box<double> b1(3.14);
    b1.print();
    Box<string> b2("Hello");
    b2.print();

    Pair<int, double> p1(1, 2.5);
    p1.print();
    Pair<int, int> p2(3, 4);
    p2.print();
}