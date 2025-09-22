#include <iostream>
#include <type_traits>
#include <vector>
#include <string>
#include <concepts>

using namespace std;

template <typename T>
typename enable_if<is_integral<T>::value, T>::type
square(T x) {
    return x * x;
}

template <typename T>
typename enable_if<is_floating_point<T>::value, T>::type
square(T x) {
    return x * x;
}

template <integral T>
T cube(T x) {
    return x * x * x;
}

template <floating_point T>
T cube(T x) {
    return x * x * x;
}

int main() {
    int a = 3;
    double b = 2.5;

    cout << "square(3) = " << square(a) << "\n";
    cout << "square(2.5) = " << square(b) << "\n";

    cout << "cube(3) = " << cube(a) << "\n";
    cout << "cube(2.5) = " << cube(b) << "\n";
}