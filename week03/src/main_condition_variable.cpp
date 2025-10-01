#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

mutex m;
condition_variable cv;
queue<int> q;
bool done = false;

void producer() {
    for (int i = 1; i <= 10; i ++) {
        {
            lock_guard<mutex> lock(m);
            q.push(i);
            cout << "Produced " << i << endl;
        }
        cv.notify_one();
        this_thread::sleep_for(100ms);
    }
    {
        lock_guard<mutex> lock(m);
        done = true;
    }
    cv.notify_all();
}

void consumer(int id) {
    while (true) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [] { return !q.empty() || done; });
        if (!q.empty()) {
            int item = q.front();
            q.pop();
            cout << "Consumer " << id << " consumed" << item << endl;
        } else if (done) {
            break;
        }
    }
}

int main() {
    thread p(producer);
    thread c1(consumer, 1);
    thread c2(consumer, 2);

    p.join();
    c1.join();
    c2.join();
    cout << "All done.";
}