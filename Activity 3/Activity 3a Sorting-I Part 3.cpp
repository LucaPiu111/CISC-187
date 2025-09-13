#include <iostream>
#include <vector>

using namespace std;

int double_then_sum(const vector<int>& array) {
    vector<int> doubled_array;

    for (int number : array) {
        doubled_array.push_back(number * 2);
    }

    int sum = 0;
    for (int number : doubled_array) {
        sum += number;
    }
    return sum;
}

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    int result = double_then_sum(numbers);

    cout << "Result: " << result << endl;

    return 0;
}