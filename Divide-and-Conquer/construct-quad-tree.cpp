class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size(); // Calculate n
        int val = grid[0][0]; // Value is first element of a grid

        // If grid consists only of the same val then it's a leaf
        bool isLeaf = grid == vector<vector<int>>(n, vector<int>(n, val));

        // Base case: uniform grid (this includes n == 1) -> leaf, no children
        if (n <= 1 || isLeaf) {
            return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
        }

        int m = n / 2; // Calculate middle index

        // Rows first, then columns inside each row
        vector<vector<int>> topLeft = subGrid(grid, 0, m, 0, m);
        vector<vector<int>> topRight = subGrid(grid, 0, m, m, n);
        vector<vector<int>> bottomLeft = subGrid(grid, m, n, 0, m);
        vector<vector<int>> bottomRight = subGrid(grid, m, n, m, n);

        // Define root
        Node* root = new Node(
            val,
            isLeaf,
            // Call recursively construct on all directions:
            construct(topLeft),
            construct(topRight),
            construct(bottomLeft),
            construct(bottomRight)
        );

        return root; // Return the root we've made
    }

private:
    // Copy of grid[r0:r1][c0:c1] - the C++ version of [row[c0:c1] for row in grid[r0:r1]]
    vector<vector<int>> subGrid(vector<vector<int>>& grid, int r0, int r1, int c0, int c1) {
        vector<vector<int>> res;
        for (int r = r0; r < r1; r++) {
            res.push_back(vector<int>(grid[r].begin() + c0, grid[r].begin() + c1));
        }
        return res;
    }
};
