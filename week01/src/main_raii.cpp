#include <iostream>
#include <memory>
#include <functional>
#include <cstdio>

using namespace std;

class ScopeGuard {
    function<void()> func;
    bool active = true;
public:
    explicit ScopeGuard(function<void()> f) : func(move(f)) {}
    ~ScopeGuard() { if (active) func(); }
    void dismiss() { active = false; }
};

struct Resource {
    Resource(const string& name) : name(name) {
        cout << "Resource " << name << " acquired\n";
    }
    ~Resource() {
        cout << "Resource " << name << " released\n";
    }
    string name;
};

int main() {
    {
        FILE* fp = fopen("temp.txt", "w");
        if (!fp) return 1;

        ScopeGuard guard([&] {
            fclose(fp);
            remove("temp.text");
            cout << "File cleaned up\n";
        });

        fputs("Hello RAII!\n", fp);
        cout << "Wrote to file\n";
    }

    {
        unique_ptr<Resource> r1 = make_unique<Resource>("A");
        shared_ptr<Resource> r2 = make_shared<Resource>("B");
        {
            shared_ptr<Resource> r3 = r2;
            cout << "use_count of r2 = " << r2.use_count() << "\n";
        }
        cout << "r2 is still alive inside scope\n";
    }
}