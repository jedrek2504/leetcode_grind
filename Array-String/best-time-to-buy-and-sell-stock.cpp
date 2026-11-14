class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;

        // Iterate through the prices
        for (int price : prices) {
            min_price = min(min_price, price); // Keep track of the minimal price SO FAR
            // At any given point a current profit is current (price - minimal price) we have found so far.
            max_profit = max(max_profit, price - min_price); // Update max_profit
        }

        return max_profit;
    }
};
