#include <iostream>
#include <vector>

using namespace std;

int missingNumber(const vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int num : nums) {
        actualSum += num;
    }

    return expectedSum - actualSum;
}

int main() {
    vector<int> arr1 = { 2, 3, 0, 6, 1, 5 };
    cout << missingNumber(arr1) << endl;

    vector<int> arr2 = { 8, 2, 3, 9, 4, 7, 5, 0, 6 };
    cout << missingNumber(arr2) << endl;

    vector<int> arr3 = { 0, 1, 2, 3, 5 };
    cout << missingNumber(arr3) << endl;

    return 0;
}
