#include <iostream>
#include <cmath>

using namespace std;

class Vector3 {
    public:
    double x{}, y{}, z{};
    constexpr Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
    [[nodiscard]] double length() const { return sqrt(x*x + y*y + z*z); }
    [[nodiscard]] double dot(const Vector3& o) const { return x*o.x + y*o.y + z*o.z; }
    [[nodiscard]] Vector3 cross(const Vector3& o) const {
        return Vector3(
            y*o.z - z*o.y,
            z*o.x - x*o.z,
            x*o.y - y*o.x
        );
    }
};

int main() {
    Vector3 a{3, 4, 5}, b{1, 0, 2};
    cout << "len(a) = " << a.length() << endl;
    cout << "a.b = " << a.dot(b) << endl;
    Vector3 c = a.cross(b);
    cout << "axb = (" << c.x << "," << c.y << "," << c.z << ")" << endl;
}