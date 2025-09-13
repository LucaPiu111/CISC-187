#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void multiple_cases(const vector<string>& array) {
    for (const string& str : array) {


        for (char c : str) {
            cout << (char)toupper(c);
        }
        cout << endl;


        for (char c : str) {
            cout << (char)tolower(c);
        }
        cout << endl;


        if (!str.empty()) {
            cout << (char)toupper(str[0]);
            for (size_t i = 1; i < str.size(); i++) {
                cout << (char)tolower(str[i]);
            }
        }
        cout << endl;
    }
}


int main() {
    vector<string> strings = { "a", "B", "c" };
    multiple_cases(strings);

    return 0;
}