#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class File {
    string name;
public:
    File(const string& n) : name(n) {
        cout << "Open file: " << name << "\n";
    }
    ~File() {
        cout << "Close file: " << name << "\n";
    }
};

class SafeVector {
    vector<int> data;
public:
    void push_back(int x) {
        vector<int> tmp = data;
        tmp.push_back(x);
        data.swap(tmp);
    }
    void print() {
        for (auto v : data) {
            cout << v << " ";
        }
        cout << "\n";
    }
};

class NoexceptBuffer {
    int* arr;
    size_t size;
public:
    NoexceptBuffer(size_t n) : arr(new int[n]), size(n) {
        cout << "Construct buffer size " << n << endl;
    }
    ~NoexceptBuffer() {
        delete[] arr;
        cout << "Destruct buffer\n";
    }
    NoexceptBuffer(NoexceptBuffer&& other) noexcept : arr(other.arr), size(other.size) {
        other.arr = nullptr;
        other.size = 0;
        cout << "Move construct buffer\n";
    }
    NoexceptBuffer(const NoexceptBuffer& other) : arr(new int[other.size]), size(other.size) {
        cout << "Copy construct buffer\n";
    }
};

int main() {
    cout << "--- RAII demo ---\n";
    try {
        File f("data.txt");
        throw runtime_error("Something bad happend!");
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "\n--- Strong Guarantee demo ---\n";
    SafeVector sv;
    sv.push_back(1);
    sv.push_back(2);
    sv.print();

    cout << "\n--- noexcept demo with vector ---\n";
    vector<NoexceptBuffer> v;
    v.reserve(2);
    v.emplace_back(5);
    v.emplace_back(10);
    v.emplace_back(20);
}