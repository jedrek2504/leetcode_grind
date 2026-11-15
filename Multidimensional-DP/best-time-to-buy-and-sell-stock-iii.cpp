class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num_days = prices.size();
        if (num_days < 2) {
            return 0;
        }

        // best_before[day] = best single trade using only prices[0..day]
        vector<int> best_before(num_days, 0);
        int cheapest_day = 0; // day with the cheapest price so far
        int best_profit = 0;
        for (int sell_day = 1; sell_day < num_days; sell_day++) {
            best_profit = max(best_profit, prices[sell_day] - prices[cheapest_day]);
            if (prices[sell_day] < prices[cheapest_day]) {
                cheapest_day = sell_day;
            }
            best_before[sell_day] = best_profit; // save the running best for this day
        }

        // best_after[day] = best single trade using only prices[day..num_days-1]
        vector<int> best_after(num_days, 0);
        int priciest_day = num_days - 1; // day with the highest price so far (walking from the right)
        best_profit = 0;
        for (int buy_day = num_days - 2; buy_day >= 0; buy_day--) {
            best_profit = max(best_profit, prices[priciest_day] - prices[buy_day]);
            if (prices[buy_day] > prices[priciest_day]) {
                priciest_day = buy_day;
            }
            best_after[buy_day] = best_profit;
        }

        // Split on every day: best trade up to that day + best trade from that day
        int best_total = 0;
        for (int day = 0; day < num_days; day++) {
            best_total = max(best_total, best_before[day] + best_after[day]);
        }
        return best_total;
    }
};
