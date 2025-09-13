#include <iostream>
#include <vector>

using namespace std;

void every_other(const vector<int>& array) {
    for (size_t index = 0; index < array.size(); index++) {
        if (index % 2 == 0) {
            int number = array[index];
            for (int other_number : array) {
                cout << number + other_number << endl;
            }
        }
    }
}

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    every_other(numbers);

    return 0;
}