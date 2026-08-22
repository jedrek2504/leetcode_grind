class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Initialize all values to 1

        // Go from left to right starting with 1 and check if the value is bigger then left neighbour
        for (int i = 1; i < n; ++i) {
            if (ratings[i - 1] < ratings[i]) {
                candies[i] = candies[i - 1] + 1; // If so -> set the value to +1 than neighbour
            }
        }

        // Go from right to left starting with (n - 1) pos and check if the value is bigger then right neighbour
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1); // We want to avoid setting smaller value then what has already been set in the first loop so we take the max
            }
        }

        return std::accumulate(candies.begin(), candies.end(), 0); // Return the sum of candies
    }
};
