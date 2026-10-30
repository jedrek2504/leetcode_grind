class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); // Initialize the board
        std::unordered_set<int> cols;
        std::unordered_set<int> anti_diag; // (r + c)
        std::unordered_set<int> diag; // (r - c)
        vector<vector<string>> res; // Stores valid boards

        backtrack(0, n, board, cols, diag, anti_diag, res);
        return res;
    }

private:
    void backtrack(int row, int n, vector<string>& board, std::unordered_set<int>& cols, std::unordered_set<int>& diag, std::unordered_set<int>& anti_diag, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board); // Each row is already a string, so just copy the board
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols.count(col) || diag.count(row - col) || anti_diag.count(row + col)) {
                continue;
            }

            // Place a queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag.insert(row - col);
            anti_diag.insert(row + col);

            backtrack(row + 1, n, board, cols, diag, anti_diag, res); // Backtrack

            // Remove a queen
            board[row][col] = '.';
            cols.erase(col);
            diag.erase(row - col);
            anti_diag.erase(row + col);
        }
    }
};
