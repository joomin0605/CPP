#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1, m2;

void task1() {
    lock_guard<mutex> lock1(m1);
    this_thread::sleep_for(100ms);
    lock_guard<mutex> lock2(m2);
    cout << "Task1 finished\n";
}

void task2() {
    lock_guard<mutex> lock2(m2);
    this_thread::sleep_for(100ms);
    lock_guard<mutex> lock1(m1);
    cout << "Task2 finished\n";
}

void safe_task1() {
    lock(m1, m2);
    lock_guard<mutex> lock1(m1, adopt_lock);
    lock_guard<mutex> lock2(m2, adopt_lock);
    cout << "Safe Task1 finished\n";
}

void safe_task2() {
    lock(m1, m2);
    lock_guard<mutex> lock1(m1, adopt_lock);
    lock_guard<mutex> lock2(m2, adopt_lock);
    cout << "Safe Task2 finished\n";
}

int main() {
    cout << "--- Deadlock demo (may hang!) ---\n";
    {
        thread t1(task1);
        thread t2(task2);
        t1.join();
        t2.join();
    }

    cout << "\n--- Deadlock-free demo ---\n";
    {
        thread t3(safe_task1);
        thread t4(safe_task2);
        t3.join();
        t4.join();
    }
}