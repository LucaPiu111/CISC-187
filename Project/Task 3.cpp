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
