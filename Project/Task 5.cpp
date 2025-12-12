#include <iostream>
#include <vector>

using namespace std;

vector<double> sortTemperatures(const vector<double>& readings) {
    int count[21] = { 0 };

    for (double temp : readings) {
        int index = static_cast<int>((temp - 97.0) * 10 + 0.5);
        count[index]++;
    }

    vector<double> sorted;
    sorted.reserve(readings.size());

    for (int i = 0; i < 21; i++) {
        double temperature = 97.0 + (i * 0.1);
        for (int j = 0; j < count[i]; j++) {
            sorted.push_back(temperature);
        }
    }

    return sorted;
}

int main() {
    vector<double> readings = { 98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1 };

    vector<double> sorted = sortTemperatures(readings);

    cout << "Sorted temperatures: ";
    for (double temp : sorted) {
        cout << temp << " ";
    }
    cout << endl;

    vector<double> test2 = { 97.0, 97.0, 99.0, 99.0, 98.5, 98.5, 97.5 };
    vector<double> sorted2 = sortTemperatures(test2);

    cout << "\nTest 2 sorted: ";
    for (double temp : sorted2) {
        cout << temp << " ";
    }
    cout << endl;

    return 0;
}
