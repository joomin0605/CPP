#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class SafeString {
    string data;

public:
    SafeString(const string& s) : data(s) {
        cout << "Construct: " << data << "\n";
    }

    SafeString(SafeString&& other) noexcept : data(move(other.data)) {
        cout << "Move Construct: " << data << "\n";
    }

    SafeString(const SafeString& other) : data(other.data) {
        cout << "Copy Construct: " << data << "\n";
    }

    ~SafeString() {
        cout << "Destruct: " << data << "\n";
    }
};

int risky_divide(int a, int b) {
    if (b == 0) throw runtime_error("divide by zero");
    return a / b;
}

int main() {
    cout << "--- Exception Safety Demo ---\n";

    try {
        cout << risky_divide(10, 2) << "\n";
        cout << risky_divide(10, 0) << "\n";
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << "\n";
    }

    cout << "\n--- Vector and noexcept ---\n";
    vector<SafeString> v;
    v.reserve(3);
    v.emplace_back("one");
    v.emplace_back("two");
    v.emplace_back("three");
}