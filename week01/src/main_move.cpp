#include <iostream>
#include <utility>
#include <string>

using namespace std;

class Buffer {
    size_t size;
    char* data;
public:
    Buffer(size_t n = 0) : size(n), data(n ? new char[n] : nullptr) {
        cout << "Construct " << size << " bytes\n";
    }

    ~Buffer() {
        delete[] data;
        cout << "Destruct " << size << " bytes\n";
    }

    Buffer(const Buffer& other) : size(other.size), data(other.size ? new char[other.size] : nullptr) {
        if (data) copy(other.data, other.data + size, data);
        cout << "Copy Construct " << size << " bytes\n";
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = size ? new char[size] : nullptr;
            if (data) copy(other.data, other.data + size, data);
            cout << "Copy Assign " << size << " bytes\n";
        }
        return *this;
    }

    Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr;
        cout << "Move Construct " << size << " bytes\n";
    }

    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = other.data;
            other.size = 0;
            other.data = nullptr;
            cout << "Move Assign " << size << " bytes\n";
        }
        return *this;
    }
};

int main() {
    cout << "------- Copy Example -------\n";
    Buffer a(10);
    Buffer b = a;
    Buffer c;
    c = a;

    cout << "\n------- Move Example -------\n";
    Buffer d = Buffer(20);
    Buffer e;
    e = Buffer(30);
}