#include <iostream>
#include <type_traits>

using namespace std;

template<int N>
struct Fib {
    static constexpr int value = Fib<N-1>::value + Fib<N-2>::value;
};

template<>
struct Fib<0> { static constexpr int value = 0; };

template<>
struct Fib<1> { static constexpr int value = 1; };

template<typename T>
void printTypeInfo(T x) {
    if constexpr (is_integral<T>::value) {
        cout << x << " is an integral type\n";
    } else if constexpr (is_floating_point<T>::value) {
        cout << x << " is a floating-point type\n";
    } else {
        cout << "Unknown type\n";
    }
}

constexpr int factorial(int n) {
    return (n <= 1) ? 1: (n * factorial(n-1));
}

int main() {
    cout << "--- Complie-time Fibonacci ---\n";
    cout << "Fib<10>::value = " << Fib<10>::value << endl;

    cout << "\n--- Type traits demo ---\n";
    printTypeInfo(42);
    printTypeInfo(3.14);
    printTypeInfo("hello");

    cout << "\n--- Constexpr factorial ---\n";
    constexpr int fact5 = factorial(5);
    cout << "factorial(5) = " << fact5 << endl;
}