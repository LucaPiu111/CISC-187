#include <iostream>
#include <functional>
#include <string>

using namespace std;

int main() {
    string name = "Luca_Piu";

    hash<string> hasher;

    size_t hashValue = hasher(name);

    cout << "Hash value of \"" << name << "\" is: " << hashValue << endl;

    return 0;
}
