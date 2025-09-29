#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

template <typename T>
class ThreadSafeVector {
    vector<T> data;
    mutable mutex m;
public:
    void push_back(const T& value) {
        lock_guard<mutex> lock(m);
        data.push_back(value);
    }

    size_t size() const {
        lock_guard<mutex> lock(m);
        return data.size();
    }
    
    T get(size_t idx) const {
        lock_guard<mutex> lock(m);
        return data.at(idx);
    }
};

int main() {
    ThreadSafeVector<int> ts_vec;

    auto writer = [&]() {
        for(int i = 0; i < 1000; i++) {
            ts_vec.push_back(i);
        }
    };

    thread t1(writer);
    thread t2(writer);

    t1.join();
    t2.join();

    cout << "Final size = " << ts_vec.size() << endl;
    cout << "Element[500] = " << ts_vec.get(500) << endl;
}