# Questions With Code

1. The Big O Notation that describes the time complexity of an algorithm that takes 4N + 16 steps is O(N). This is because it expresses the     linear search algorithm since 4N + 16 can be represented as the function y = mx + b, which is linear.

2. The Big O Notation that describes the time complexity of an algorithm that takes 2N^2 steps is O(N^2). Since O(N^2) represents the           quadratic search, it is used for quadratic algorithms such as 2N^2.

3. The Big O Notation that describes the time complexity of the function is O(N). This is because it is linear once again through the           “doubled_array << number *= 2” statement, which is equivalent to 2N, in which the coefficient "2" is ignored.

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


    
4. The Big O Notation that describes the time complexity of the function is O(N) and linear again. This is because the statements “puts         string.upcase”, “puts string.downcase”, and “puts string.capitalize” perform 3 actions for each string, represented by 3N. (constant       ignored again)


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



5. The Big O Notation that describes the time complexity of the function is O(N^2) and is quadratic. This is due to the loop first checking each number in the array, then only taking the even ones, then it goes through that selection of even values and sums the the two together. This yields (N^2)/2 which becomes N^2 since the constant ½ is ignored.


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
