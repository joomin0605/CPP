#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
    cout << "--- vector capacity demo ---\n";
    vector<int> v;
    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        cout << "size = " << v.size() << ", capacity= " << v.capacity() << endl;
    }

    cout << "\n--- reserve vs resize ---\n";
    vector<int> a;
    a.reserve(5);
    cout << "reserve(5): size = " << a.size() << ", capacity = " << a.capacity() << endl;

    a.resize(5);
    cout << "resieze(5): size = " << a.size() << ", capacity = " << a.capacity() << endl;

    cout << "\n--- custom allocator demeo ---\n";
    allocator<int> alloc;

    int* p = alloc.allocate(3);

    for (int i = 0; i < 3; i++) {
        allocator_traits<allocator<int>>::construct(alloc, &p[i], i+1);
    }

    for (int i = 0; i < 3; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 3; i++) {
        allocator_traits<allocator<int>>::destroy(alloc, &p[i]);
    }
    alloc.deallocate(p, 3);
}