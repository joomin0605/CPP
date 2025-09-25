#include <iostream>
#include <concepts>
#include <string>

using namespace std;

template<typename T>
concept Arithmetic = integral<T> || floating_point<T>;

template<Arithmetic T>
T add(T a, T b) {
    return a + b;
}

template<typename T>
requires requires(T x) { x + x ;}
T twice(T x) {
    return x + x;
}

struct ConsoleLogger {
    static void log(const string& msg) {
        cout << "[Console] " << msg << endl;
    }
};

struct SilentLogger {
    static void log(const string& msg) { }
};

template<typename LoggerPolicy>
class Processor {
public:
    void run() {
        LoggerPolicy::log("Running process...");
        LoggerPolicy::log("Finished process.");
    }
};

int main() {
    cout << "--- Concepts ---\n";
    cout << "add(3, 4) = " << add(3, 4) << endl;
    cout << "add(2.5, 1.2) = " << add(2.5, 1.2) << endl;

    cout << "--- requires ---\n";
    cout << "twice(21) = " << twice(21) << endl;
    cout << "twice(string) = " << twice(string("Hi")) << endl;

    cout << "\n--- Policy Design ---\n";
    Processor<ConsoleLogger> p1;
    p1.run();

    Processor<SilentLogger> p2;
    p2.run();
}