class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int ROWS = board.size(), COLS = board[0].size(); // Extract rows and cols
        std::vector<std::pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}}; // all dirs including diagonals

        // Iterate over each element in matrix
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                int live_neighbours = 0; // Each iteration calculate live_neighbours

                // Traverse all neighbours
                for (auto& [dx, dy] : directions) {
                    // If neighbour is out of bounds - skip
                    if (!(0 <= c + dx && c + dx < COLS) || !(0 <= r + dy && r + dy < ROWS)) continue;

                    // If value is alive(1) or was alive(2)
                    if (board[r + dy][c + dx] == 1 || board[r + dy][c + dx] == 2) {
                        live_neighbours += 1;
                    }
                }

                // Legend: 2 - switch from alive(1) to dead(0) ; 3 - switch from dead(0) to alive(1)
                // Live cell
                if (board[r][c] == 1) {
                    // Underpopulation
                    if (live_neighbours < 2) {
                        board[r][c] = 2;
                    // Overpopulation
                    } else if (live_neighbours > 3) {
                        board[r][c] = 2;
                    }
                // Dead cell
                } else {
                    if (live_neighbours == 3) {
                        board[r][c] = 3;
                    }
                }
            }
        }

        // Second pass - correct 2s and 3s to corresponding values
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (board[r][c] == 2) {
                    board[r][c] = 0;
                } else if (board[r][c] == 3) {
                    board[r][c] = 1;
                }
            }
        }
    }
};
