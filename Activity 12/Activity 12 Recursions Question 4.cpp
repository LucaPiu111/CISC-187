#include <iostream>
#include <vector>
#include <any>

using namespace std;

void printAllNumbers(const any& element) {
    if (element.type() == typeid(int)) {
        cout << any_cast<int>(element) << endl;
    } else if (element.type() == typeid(vector<any>)) {
        const auto& vec = any_cast<const vector<any>&>(element);
        for (const auto& item : vec) {
            printAllNumbers(item);
        }
    }
}

int main() {
    vector<any> array = {
        1,
        2,
        3,
        vector<any>{4, 5, 6},
        7,
        vector<any>{
            8,
            vector<any>{
                9, 10, 11,
                vector<any>{12, 13, 14}
            }
        },
        vector<any>{
            15, 16, 17, 18, 19,
            vector<any>{
                20, 21, 22,
                vector<any>{
                    23, 24, 25,
                    vector<any>{26, 27, 29}
                }, 30, 31
            }, 32
        }, 33
    };

    cout << "All numbers in nested array:" << endl;
    printAllNumbers(array);
    
    return 0;
}
