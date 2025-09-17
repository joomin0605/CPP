#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

template <typename T>
T add(T a, T b) { return a + b; }

template <typename T>
T my_clamp(T v, T lo, T hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

int main() {
    cout << "add<int>(3, 5) = " << add(3, 5) << "\n";
    cout << "clamp(15, 0, 10) = " << my_clamp(15, 0, 10) << "\n";

    vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    nums.erase(remove_if(nums.begin(), nums.end(), [](int x) { return x % 2 == 1; }),
                nums.end());

    sort(nums.begin(), nums.end(), [](int a, int b){ return a > b; });

    int sum = accumulate(nums.begin(), nums.end(), 0);

    cout << "Filtered & sorted: ";
    for(int n : nums) cout << n << " ";
    cout << "\nSum = " << sum << "\n";
}