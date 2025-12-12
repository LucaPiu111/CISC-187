#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestConsecutiveSequence(const vector<int>& nums) {
    if (nums.empty()) return 0;

    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;

    for (int num : numSet) {
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentStreak++;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}

int longestConsecutiveSequenceSorting(vector<int>& nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());
    int longest = 1;
    int current = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) continue;

        if (nums[i] == nums[i - 1] + 1) {
            current++;
            longest = max(longest, current);
        }
        else {
            current = 1;
        }
    }

    return longest;
}

void testLongestConsecutiveSequence() {
    cout << "Testing longestConsecutiveSequence function:\n" << endl;

    vector<int> nums1 = { 10, 5, 12, 3, 55, 30, 4, 11, 2 };
    cout << "Array: [10, 5, 12, 3, 55, 30, 4, 11, 2]" << endl;
    cout << "Expected: 4 (sequence: 2-3-4-5)" << endl;
    cout << "Result: " << longestConsecutiveSequence(nums1) << endl << endl;

    vector<int> nums2 = { 19, 13, 15, 12, 18, 14, 17, 11 };
    cout << "Array: [19, 13, 15, 12, 18, 14, 17, 11]" << endl;
    cout << "Expected: 5 (sequence: 11-12-13-14-15)" << endl;
    cout << "Result: " << longestConsecutiveSequence(nums2) << endl << endl;

    vector<int> empty = {};
    cout << "Empty array: []" << endl;
    cout << "Expected: 0" << endl;
    cout << "Result: " << longestConsecutiveSequence(empty) << endl << endl;

    vector<int> single = { 7 };
    cout << "Single element: [7]" << endl;
    cout << "Expected: 1" << endl;
    cout << "Result: " << longestConsecutiveSequence(single) << endl << endl;

    vector<int> duplicates = { 1, 2, 2, 3, 4, 4, 5 };
    cout << "Array with duplicates: [1, 2, 2, 3, 4, 4, 5]" << endl;
    cout << "Expected: 5 (sequence: 1-2-3-4-5)" << endl;
    cout << "Result: " << longestConsecutiveSequence(duplicates) << endl << endl;

    vector<int> noSequence = { 100, 200, 300 };
    cout << "Array with no consecutive numbers: [100, 200, 300]" << endl;
    cout << "Expected: 1" << endl;
    cout << "Result: " << longestConsecutiveSequence(noSequence) << endl << endl;

    vector<int> allSame = { 5, 5, 5, 5 };
    cout << "Array with all same numbers: [5, 5, 5, 5]" << endl;
    cout << "Expected: 1" << endl;
    cout << "Result: " << longestConsecutiveSequence(allSame) << endl << endl;

    vector<int> negativeNumbers = { -5, -4, -3, 0, 1, 2 };
    cout << "Array with negative numbers: [-5, -4, -3, 0, 1, 2]" << endl;
    cout << "Expected: 3 (sequence: 0-1-2 OR -5--4--3)" << endl;
    cout << "Result: " << longestConsecutiveSequence(negativeNumbers) << endl << endl;
}

int main() {
    testLongestConsecutiveSequence();
    return 0;
}
