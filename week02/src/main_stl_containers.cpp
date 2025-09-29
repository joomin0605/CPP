#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    const int N = 100000;

    cout << "--- Sequence Containers ---\n";

    {
        vector<int> v;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < N; i++) {
            v.push_back(i);
        }
        auto end = high_resolution_clock::now();
        cout << "vector push_back: " << duration_cast<milliseconds>(end-start).count() << "ms\n";
    }

    {
        list<int> l;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < N; i++) {
            l.push_back(i);
        }
        auto end = high_resolution_clock::now();
        cout << "list puch_back: " << duration_cast<milliseconds>(end-start).count() << "ms\n";
    }

    {
        deque<int> d;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < N; i++) {
            d.push_back(i);
        }
        auto end = high_resolution_clock::now();
        cout << "deque puch_back: " << duration_cast<milliseconds>(end-start).count() << "ms\n";
    }

    cout << "\n--- Associative Containers ---\n";

    {
        map<int, int>m;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < N; i++) {
            m[i] = i;
        }
        auto end = high_resolution_clock::now();
        cout << "map insert: " << duration_cast<milliseconds>(end-start).count() << "ms\n";
    }

    {
        unordered_map<int, int> um;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < N; i++) {
            um[i] = i;
        }
        auto end = high_resolution_clock::now();
        cout << "unordered_map insert: " << duration_cast<milliseconds>(end-start).count() << "ms\n";
    }
}