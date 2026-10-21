class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res; // [[1, 2], [1, 3], [1, 4]], [2, 3], ...] - Store combs
        vector<int> comb; // Represents combination of length k

        backtrack(1, n, k, comb, res); // Call backtrack starting from 1
        return res;
    }

private:
    // Backtrack function, start - where to start iterating from
    void backtrack(int start, int n, int k, vector<int>& comb, vector<vector<int>>& res) {
        // Important, not start == k but actually if comb reaches length of k is our base case
        if ((int)comb.size() == k) {
            res.push_back(comb);
            return;
        }

        // Iterate through the nums starting from start.
        for (int num = start; num <= n; num++) {
            comb.push_back(num); // Add a num
            backtrack(num + 1, n, k, comb, res); // Start next recursive call with num + 1 to avoid duplciates
            comb.pop_back(); // Backtrack when visited the node
        }
    }
};
