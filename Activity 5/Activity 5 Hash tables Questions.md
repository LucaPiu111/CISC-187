1. 

        #include <iostream>
        #include <unordered_set>
        using namespace std;
        
        
        int main() {
            int array[] = {200, 400, 100, 50, 350};
            int n = sizeof(array) / sizeof(array[0]);
            unordered_set<int> hashSet;
        
        
            for (int i = 0; i < n; ++i) {
                hashSet.insert(array[i]);
            }
        
            int key = 200;
            if (hashSet.find(key) != hashSet.end()) {
                cout << key << "found in O(1) time complexity" << endl;
            } else {
                cout << key << " not found." << endl;
            }
        
            return 0;



2.

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
        


3. The problem that occurs due to introducing a tombstone to mark a deleted cell is when there are many tombstones, the program can quickly become inefficient and searches will be slower. This signifies the importance of rehashing as it removes the tombstones from the table by putting them into a new table.
