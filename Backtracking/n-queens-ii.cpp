class Solution {
public:
    int totalNQueens(int n) {
        int solutions = 0;
        /*
        Funny thing here - we don't even need a board! It's dead weight, we don't ever read it and actually the sets take care of the whole logic just fine
        */

        // Sets for lookup if queen can be put or not
        std::unordered_set<int> cols;
        std::unordered_set<int> diag; // (r + c) values
        std::unordered_set<int> anti_diag; // (r - c) values

        backtrack(0, n, solutions, cols, diag, anti_diag);
        return solutions;
    }

private:
    void backtrack(int row, int n, int& solutions, std::unordered_set<int>& cols, std::unordered_set<int>& diag, std::unordered_set<int>& anti_diag) {
        // We need to go 1 row "over" the board to add a solution and return to previous caller backtrack(3)
        if (row == n) {
            solutions++;
            return;
        }

        for (int col = 0; col < n; col++) {
            // If other queen can reach us
            if (cols.count(col) || diag.count(row + col) || anti_diag.count(row - col)) {
                continue; // We skip
            }

            // Add it to the lookup sets so future queen placements will be limited only to valid squares
            cols.insert(col);
            diag.insert(row + col);
            anti_diag.insert(row - col);

            backtrack(row + 1, n, solutions, cols, diag, anti_diag); // Call backtrack

            // Once the queen is removed reflect it in the set
            cols.erase(col);
            diag.erase(row + col);
            anti_diag.erase(row - col);
        }
    }
};
