#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    nums.erase(remove_if(nums.begin(), nums.end(),
                        [](int x){ return x % 2 == 1; }), nums.end());

    transform(nums.begin(), nums.end(), nums.begin(),
            [](int x) { return x * x; });

    int sum = accumulate(nums.begin(), nums.end(), 0);

    cout << "Sum of squares of even numbers 1~10 = " << sum << "\n";

    int factor = 3;
    auto multiply_val = [=](int x){ return x * factor; };
    auto multiply_ref = [&](int x){ return x * factor; };

    cout << "multiply_val(5) = " << multiply_val(5) << "\n";
    factor = 10;
    cout << "multiply_val(5) after factor = 10 = " << multiply_val(5) << "\n";
    cout << "multiply_ref(5) after factor = 10 = " << multiply_ref(5) << "\n";

    vector<string> words{"pear", "apple", "banana", "kiwi", "strawberry"};

    sort(words.begin(), words.end(),
        [](const string& a, const string& b) {
            if (a.size() == b.size()) return a < b;
            return a.size() < b.size();
        });

    cout << "Sorted words: ";
    for (auto& w : words) cout << w << " ";
}