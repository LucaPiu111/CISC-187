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
