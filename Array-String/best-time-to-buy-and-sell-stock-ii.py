class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        total_profit = 0  # Set maximum profit to 0 to disregard negative profits

        # Go through each pair of buy-sell prices.
        for r in range(1, len(prices)):
            # If a sell price is bigger than buy price - we are making profit
            if prices[r] > prices[r - 1]:
                profit = prices[r] - prices[r - 1]  # Calculate this profit
                total_profit += profit  # Add it to total profit
            # If we are not making profit - do nothing

        return total_profit
