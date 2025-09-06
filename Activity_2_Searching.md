# Questions

1. It would take 4 steps to perform a linear search for “8” in the array, [2, 4, 6, 8, 10, 12, 13].
  (check 2, 4, 6, and then finally 8)

2. It would take 1 step to perform a binary search for “8” in the array, [2, 4, 6, 8, 10, 12, 13].
  (starts in the middle, where the “8” already is)

3. It would take a maximum of 17 steps to perform a binary search on an array of 100,000 elements. This is because the formula for calculating the worst-case scenario for a binary search algorithm is log2N, rounded up to the nearest whole number.
  (log2(100,000) ≈ 16.6 -> 17)

# Code

4. (see Activity 2 Searching.cpp and video)

#include <iostream>
using namespace std;


int LinearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i + 1;
        }
    }
    return size;
}


int BinarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int steps = 0;

    while (left <= right) {
        steps++;
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return steps;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return steps;
}


int main() {
    int arr[] = { 2, 4, 6, 8, 10, 12, 13 };
    int size = 7;
    int target = 8;

    cout << "Linear Search Steps: " << LinearSearch(arr, size, target) << endl;
    cout << "Binary Search Steps: " << BinarySearch(arr, size, target) << endl;

    return 0;
}
