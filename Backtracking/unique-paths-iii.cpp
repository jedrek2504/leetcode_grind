class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        set<pair<int, int>> seen; // Visited coords in curr path
        int to_visit = 0; // How many non obstacle cells are there in a grid
        pair<int, int> start = {0, 0};

        // Find the start coords and count to_visit cells
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                // For every non obstacle cell
                if (grid[r][c] != -1) {
                    if (grid[r][c] == 1) {
                        start = {r, c}; // Remember the starting value
                    }
                    to_visit++; // Increment to_visit
                }
            }
        }

        return backtrack(grid, start.first, start.second, seen, to_visit); // Run backtrack on unpacked row, col starting position
    }

private:
    int backtrack(vector<vector<int>>& grid, int r, int c, set<pair<int, int>>& seen, int to_visit) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Bounds and seen first
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || seen.count(make_pair(r, c))) {
            return 0;
        }
        // If cell is an obstacle
        if (grid[r][c] == -1) {
            return 0; // Return nothing
        }
        // BASE CASE: If a cell is a destination and we've visited every non obstacle cell
        if (grid[r][c] == 2) {
            return (int)seen.size() == to_visit - 1 ? 1 : 0; // seen never adds destination cell so to_visit - 1.
        }

        seen.insert(make_pair(r, c)); // Add to seen

        int paths = 0; // Declare paths
        // Go through every direction on a given node
        for (const auto& d : dirs) {
            paths += backtrack(grid, r + d[0], c + d[1], seen, to_visit); // Call recursively
        }

        seen.erase(make_pair(r, c)); // After we went through all neis we can remove it from the current path

        return paths;
    }
};
