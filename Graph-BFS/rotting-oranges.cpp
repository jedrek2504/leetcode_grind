class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Extract grid dimensions
        int ROWS = grid.size();
        int COLS = grid[0].size();

        std::queue<std::pair<int, int>> q; // [(r, c), ...] - Stores rotten orange coors
        vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Directions to explore adjacent fields
        int minutes = 0;
        int fresh = 0; // Count of fresh oranges - if it drops to 0 we can return minutes

        // 1. Iterate through the grid and append rotten orange coors to the queue
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                if (grid[r][c] == 1) {
                    fresh += 1;
                }
            }
        }

        // 2. Perform bfs
        while (!q.empty() && fresh > 0) {
            minutes += 1; // For each level increment the minutes

            // Iterate through each rotten orange in the queue at the time
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // Explore the adjacent fields (up, down, left, right)
                for (const std::pair<int, int>& d : dirs) {
                    int new_row = row + d.first;
                    int new_col = col + d.second; // Coors of adjacent field

                    // If field is not in bounds or the field is not a fresh orange
                    if (!(0 <= new_row && new_row < ROWS) || !(0 <= new_col && new_col < COLS) || grid[new_row][new_col] != 1) {
                        continue; // Skip
                    }

                    // If we got here
                    grid[new_row][new_col] = 2; // Mark orange rotten
                    fresh -= 1; // Decrement the count of fresh oranges
                    q.push({new_row, new_col}); // Add it to the queue
                }
            }
        }

        return fresh == 0 ? minutes : -1; // If there are no more fresh oranges return the minutes else its impossible to get to all of them
    }
};
