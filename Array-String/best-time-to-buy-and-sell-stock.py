class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_price = float("inf")
        max_profit = 0

        # Iterate through the prices
        for price in prices:
            min_price = min(min_price, price)  # Keep track of the minimal price SO FAR
            # At any given point a current profit is current (price - minimal price) we have found so far.
            max_profit = max(max_profit, price - min_price)  # Update max_profit

        return max_profit
