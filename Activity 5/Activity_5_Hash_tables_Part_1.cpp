#include <iostream>
#include <unordered_set>
using namespace std;


int main() {
    int array[] = { 200, 400, 100, 50, 350 };
    int n = sizeof(array) / sizeof(array[0]);
    unordered_set<int> hashSet;


    for (int i = 0; i < n; ++i) {
        hashSet.insert(array[i]);
    }

    int key = 200;
    if (hashSet.find(key) != hashSet.end()) {
        cout << key << " found in O(1) time complexity" << endl;
    }
    else {
        cout << key << " not found." << endl;
    }

    return 0;
}
