#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

long long highestProductOfTwo(const vector<int>& nums) {
    int n = nums.size();

    if (n < 2) {
        return 0;
    }

    int max1 = numeric_limits<int>::min();
    int max2 = numeric_limits<int>::min();
    int min1 = numeric_limits<int>::max();
    int min2 = numeric_limits<int>::max();

    for (int num : nums) {
        if (num > max1) {
            max2 = max1;
            max1 = num;
        }
        else if (num > max2) {
            max2 = num;
        }

        if (num < min1) {
            min2 = min1;
            min1 = num;
        }
        else if (num < min2) {
            min2 = num;
        }
    }

    long long productFromMax = static_cast<long long>(max1) * max2;
    long long productFromMin = static_cast<long long>(min1) * min2;

    return max(productFromMax, productFromMin);
}

int main() {
    vector<int> arr1 = { 5, -10, -6, 9, 4 };
    vector<int> arr2 = { 1, 2, 3, 4, 5 };
    vector<int> arr3 = { -5, -4, -3, -2, -1 };
    vector<int> arr4 = { -5, 2, -1, 3, -4 };

    cout << "Test 1: " << highestProductOfTwo(arr1) << endl;
    cout << "Test 2: " << highestProductOfTwo(arr2) << endl;
    cout << "Test 3: " << highestProductOfTwo(arr3) << endl;
    cout << "Test 4: " << highestProductOfTwo(arr4) << endl;

    return 0;
}
