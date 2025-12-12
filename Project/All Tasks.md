# Task 1

    #include <iostream>
    #include <vector>
    #include <unordered_set>
    using namespace std;
    
    struct Player {
        string first_name;
        string last_name;
        string team;
    };
    
    vector<string> find_dual_sport_players(const vector<Player>& players1, const vector<Player>& players2) {
        unordered_set<string> names_set;
        vector<string> dual_players;
    
        for (const auto& player : players1) {
            names_set.insert(player.first_name + " " + player.last_name);
        }
    
        for (const auto& player : players2) {
            string full_name = player.first_name + " " + player.last_name;
            if (names_set.count(full_name)) {
                dual_players.push_back(full_name);
                names_set.erase(full_name);
            }
        }
    
        return dual_players;
    }
    
    int main() {
        vector<Player> basketball = {
            {"Jill", "Huang", "Gators"},
            {"Janko", "Barton", "Sharks"},
            {"Wanda", "Vakulskas", "Sharks"},
            {"Jill", "Moloney", "Gators"},
            {"Luuk", "Watkins", "Gators"}
        };
    
        vector<Player> football = {
            {"Hanzla", "Radosti", "32ers"},
            {"Tina", "Watkins", "Barleycorns"},
            {"Alex", "Patel", "32ers"},
            {"Jill", "Huang", "Barleycorns"},
            {"Wanda", "Vakulskas", "Barleycorns"}
        };
    
        vector<string> result = find_dual_sport_players(basketball, football);
    
        cout << "Players that play both basketball and football:\n";
        for (const string& name : result) {
            cout << "- " << name << "\n";
        }
    
        return 0;
    }



# Task 2

    #include <iostream>
    #include <vector>
    
    using namespace std;
    
    int missingNumber(const vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
    
        for (int num : nums) {
            actualSum += num;
        }
    
        return expectedSum - actualSum;
    }
    
    int main() {
        vector<int> arr1 = { 2, 3, 0, 6, 1, 5 };
        cout << missingNumber(arr1) << endl;
    
        vector<int> arr2 = { 8, 2, 3, 9, 4, 7, 5, 0, 6 };
        cout << missingNumber(arr2) << endl;
    
        vector<int> arr3 = { 0, 1, 2, 3, 5 };
        cout << missingNumber(arr3) << endl;
    
        return 0;
    }



# Task 3

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <climits>
    
    using namespace std;
    
    int getMaxProfit(const vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
    
        int minPrice = prices[0];
        int maxProfit = 0;
    
        for (size_t i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
    
            minPrice = min(minPrice, prices[i]);
        }
    
        return maxProfit;
    }
    
    int getMaxProfitWithLoss(const vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
    
        int minPrice = prices[0];
        int maxProfit = INT_MIN;
    
        for (size_t i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
    
        return maxProfit;
    }
    
    struct TransactionResult {
        int buyIndex;
        int sellIndex;
        int profit;
    };
    
    TransactionResult getMaxProfitWithIndices(const vector<int>& prices) {
        TransactionResult result = { -1, -1, 0 };
    
        if (prices.size() < 2) {
            return result;
        }
    
        int minPrice = prices[0];
        int minPriceIndex = 0;
    
        for (size_t i = 1; i < prices.size(); i++) {
            int currentProfit = prices[i] - minPrice;
    
            if (currentProfit > result.profit) {
                result.profit = currentProfit;
                result.buyIndex = minPriceIndex;
                result.sellIndex = i;
            }
    
            if (prices[i] < minPrice) {
                minPrice = prices[i];
                minPriceIndex = i;
            }
        }
    
        return result;
    }
    
    int main() {
        vector<int> prices = { 10, 7, 5, 8, 11, 2, 6 };
    
        cout << "Prices: ";
        for (int price : prices) {
            cout << price << " ";
        }
        cout << endl;
    
        int profit = getMaxProfit(prices);
        cout << "Maximum profit: $" << profit << endl;
    
        TransactionResult result = getMaxProfitWithIndices(prices);
        if (result.buyIndex != -1 && result.sellIndex != -1) {
            cout << "Buy at day " << result.buyIndex + 1 << " (price: $" << prices[result.buyIndex] << ")" << endl;
            cout << "Sell at day " << result.sellIndex + 1 << " (price: $" << prices[result.sellIndex] << ")" << endl;
            cout << "Profit: $" << result.profit << endl;
        }
    
        cout << "\nMore test cases:" << endl;
    
        vector<int> decreasing = { 7, 6, 5, 4, 3 };
        cout << "Decreasing prices: Profit = $" << getMaxProfit(decreasing) << endl;
    
        vector<int> increasing = { 1, 2, 3, 4, 5 };
        cout << "Increasing prices: Profit = $" << getMaxProfit(increasing) << endl;
    
        vector<int> flat = { 5, 5, 5, 5 };
        cout << "Flat prices: Profit = $" << getMaxProfit(flat) << endl;
    
        vector<int> onePrice = { 10 };
        cout << "Single price: Profit = $" << getMaxProfit(onePrice) << endl;
    
        return 0;
    }



# Task 4

    #include <iostream>
    #include <vector>
    #include <limits>
    #include <algorithm>
    using namespace std;
    
    long long highestProductOfTwo(const vector<int>& nums) {
        int n = nums.size();
    
        if (n < 2) {
            return 0;
        }
    
        int max1 = numeric_limits<int>::min();
        int max2 = numeric_limits<int>::min();
        int min1 = numeric_limits<int>::max();
        int min2 = numeric_limits<int>::max();
    
        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max2 = num;
            }
    
            if (num < min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }
        }
    
        long long productFromMax = static_cast<long long>(max1) * max2;
        long long productFromMin = static_cast<long long>(min1) * min2;
    
        return max(productFromMax, productFromMin);
    }
    
    int main() {
        vector<int> arr1 = { 5, -10, -6, 9, 4 };
        vector<int> arr2 = { 1, 2, 3, 4, 5 };
        vector<int> arr3 = { -5, -4, -3, -2, -1 };
        vector<int> arr4 = { -5, 2, -1, 3, -4 };
    
        cout << "Test 1: " << highestProductOfTwo(arr1) << endl;
        cout << "Test 2: " << highestProductOfTwo(arr2) << endl;
        cout << "Test 3: " << highestProductOfTwo(arr3) << endl;
        cout << "Test 4: " << highestProductOfTwo(arr4) << endl;
    
        return 0;
    }



# Task 5

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



# Task 6

    #include <iostream>
    #include <vector>
    #include <unordered_set>
    #include <algorithm>
    using namespace std;
    
    int longestConsecutiveSequence(const vector<int>& nums) {
        if (nums.empty()) return 0;
    
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;
    
        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
    
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
    
                longestStreak = max(longestStreak, currentStreak);
            }
        }
    
        return longestStreak;
    }
    
    int longestConsecutiveSequenceSorting(vector<int>& nums) {
        if (nums.empty()) return 0;
    
        sort(nums.begin(), nums.end());
        int longest = 1;
        int current = 1;
    
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;
    
            if (nums[i] == nums[i - 1] + 1) {
                current++;
                longest = max(longest, current);
            }
            else {
                current = 1;
            }
        }
    
        return longest;
    }
    
    void testLongestConsecutiveSequence() {
        cout << "Testing longestConsecutiveSequence function:\n" << endl;
    
        vector<int> nums1 = { 10, 5, 12, 3, 55, 30, 4, 11, 2 };
        cout << "Array: [10, 5, 12, 3, 55, 30, 4, 11, 2]" << endl;
        cout << "Expected: 4 (sequence: 2-3-4-5)" << endl;
        cout << "Result: " << longestConsecutiveSequence(nums1) << endl << endl;
    
        vector<int> nums2 = { 19, 13, 15, 12, 18, 14, 17, 11 };
        cout << "Array: [19, 13, 15, 12, 18, 14, 17, 11]" << endl;
        cout << "Expected: 5 (sequence: 11-12-13-14-15)" << endl;
        cout << "Result: " << longestConsecutiveSequence(nums2) << endl << endl;
    
        vector<int> empty = {};
        cout << "Empty array: []" << endl;
        cout << "Expected: 0" << endl;
        cout << "Result: " << longestConsecutiveSequence(empty) << endl << endl;
    
        vector<int> single = { 7 };
        cout << "Single element: [7]" << endl;
        cout << "Expected: 1" << endl;
        cout << "Result: " << longestConsecutiveSequence(single) << endl << endl;
    
        vector<int> duplicates = { 1, 2, 2, 3, 4, 4, 5 };
        cout << "Array with duplicates: [1, 2, 2, 3, 4, 4, 5]" << endl;
        cout << "Expected: 5 (sequence: 1-2-3-4-5)" << endl;
        cout << "Result: " << longestConsecutiveSequence(duplicates) << endl << endl;
    
        vector<int> noSequence = { 100, 200, 300 };
        cout << "Array with no consecutive numbers: [100, 200, 300]" << endl;
        cout << "Expected: 1" << endl;
        cout << "Result: " << longestConsecutiveSequence(noSequence) << endl << endl;
    
        vector<int> allSame = { 5, 5, 5, 5 };
        cout << "Array with all same numbers: [5, 5, 5, 5]" << endl;
        cout << "Expected: 1" << endl;
        cout << "Result: " << longestConsecutiveSequence(allSame) << endl << endl;
    
        vector<int> negativeNumbers = { -5, -4, -3, 0, 1, 2 };
        cout << "Array with negative numbers: [-5, -4, -3, 0, 1, 2]" << endl;
        cout << "Expected: 3 (sequence: 0-1-2 OR -5--4--3)" << endl;
        cout << "Result: " << longestConsecutiveSequence(negativeNumbers) << endl << endl;
    }
    
    int main() {
        testLongestConsecutiveSequence();
        return 0;
    }
