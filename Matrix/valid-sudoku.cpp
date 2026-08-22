class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::set<char>> rows(9), cols(9), squares(9); // Rows/cols/squares -> set(values)

        // Iterate over every element
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char val = board[r][c];

                // If element no filled -> skip
                if (board[r][c] == '.') continue;

                int sq = (r / 3) * 3 + (c / 3);

                // If val has been seen then return False
                if (rows[r].count(val) || cols[c].count(val) || squares[sq].count(val)) {
                    return false;
                }

                // Add value to corresponding sets.
                rows[r].insert(val);
                cols[c].insert(val);
                squares[sq].insert(val); // // operator to map element to one of 9 squares for ex: board[5][8] -> 5//3 = 1, 8//3 = 2 -> squares(1, 2)
            }
        }

        return true; // If we got here then valid
    }
};
