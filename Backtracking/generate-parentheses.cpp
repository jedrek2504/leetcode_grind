class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string comb; // "current" combination
        vector<string> res; // Stores valid parentheses combinations
        int open_count = 0; // Counts "(" occurrences
        int close_count = 0; // Counts ")" occurrences

        backtrack(0, n, comb, open_count, close_count, res);
        return res;
    }

private:
    void backtrack(int i, int n, string& comb, int& open_count, int& close_count, vector<string>& res) {
        if (i == n * 2) {
            res.push_back(comb);
            return;
        }

        // Each recursion we have two options:
        // 1. "("

        // If half of the parentheses we added are "(" -> No point in adding more
        if (open_count < n) {
            comb.push_back('(');
            open_count++;

            backtrack(i + 1, n, comb, open_count, close_count, res);

            comb.pop_back();
            open_count--;
        }

        // 2. ")"

        // Add closing parenthesis only if we have more opening parentheses.
        if (open_count > close_count) {
            comb.push_back(')');
            close_count++;

            backtrack(i + 1, n, comb, open_count, close_count, res);

            comb.pop_back();
            close_count--;
        }
    }
};
