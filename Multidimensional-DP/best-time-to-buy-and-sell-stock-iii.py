class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        num_days = len(prices)
        if num_days < 2:
            return 0

        # best_before[day] = best single trade using only prices[0..day]
        best_before = [0] * num_days
        cheapest_day = 0  # day with the cheapest price so far
        best_profit = 0
        for sell_day in range(1, num_days):
            best_profit = max(best_profit, prices[sell_day] - prices[cheapest_day])
            if prices[sell_day] < prices[cheapest_day]:
                cheapest_day = sell_day
            best_before[sell_day] = best_profit  # save the running best for this day

        # best_after[day] = best single trade using only prices[day..num_days-1]
        best_after = [0] * num_days
        priciest_day = (
            num_days - 1
        )  # day with the highest price so far (walking from the right)
        best_profit = 0
        for buy_day in range(num_days - 2, -1, -1):
            best_profit = max(best_profit, prices[priciest_day] - prices[buy_day])
            if prices[buy_day] > prices[priciest_day]:
                priciest_day = buy_day
            best_after[buy_day] = best_profit

        # Split on every day: best trade up to that day + best trade from that day
        return max(best_before[day] + best_after[day] for day in range(num_days))
