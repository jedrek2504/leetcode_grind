class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Directions

        // Iterate through each cell
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                // Run backtrack on each cell, if it returns true at any point
                if (backtrack(r, c, 0, ROWS, COLS, dirs, board, word)) {
                    return true; // The word is present
                }
            }
        }
        return false; // No matching word
    }

private:
    bool backtrack(int r, int c, int i, int ROWS, int COLS, vector<vector<int>>& dirs, vector<vector<char>>& board, const string& word) {
        // If we got to the end of a word that means there is a solution
        if (i == (int)word.size()) {
            return true;
        }

        if (
            r < 0 || r >= ROWS // Row out of bounds
            || c < 0 || c >= COLS // Col out of bounds
            || board[r][c] != word[i] // Current cell doesn't have a target letter (visited cells are marked '#', so they never match)
        ) {
            return false;
        }

        char letter = board[r][c]; // Remember the letter so we can restore it
        board[r][c] = '#'; // Mark as visited in current path

        // Backtrack each adjacent cell, if any of them returns true then result is true
        bool res = false;
        for (auto& dir : dirs) {
            if (backtrack(r + dir[0], c + dir[1], i + 1, ROWS, COLS, dirs, board, word)) {
                res = true;
                break;
            }
        }
        board[r][c] = letter; // Once done with backtracking, restore the letter

        return res; // Return the result
    }
};
