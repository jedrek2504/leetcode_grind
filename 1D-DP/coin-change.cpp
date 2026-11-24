class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // Cache stores arb values initially for indexes 0 ... a
        dp[0] = 0; // Base case: To get 0 we need 0 coins
        // Bottom-up dp - solve dp[1] ... dp[amount]
        for (int a = 1; a <= amount; a++) {
            for (int c : coins) {
                // If taking a coin results in negative val
                if ((a - c) < 0) {
                    continue; // Skip it
                }
                dp[a] = min(dp[a], 1 + dp[a - c]); // Formula
            }
        }

        return dp[amount] != amount + 1 ? dp[amount] : -1; // Edge case: If amount has not been calculated then there is no solution
    }
};
