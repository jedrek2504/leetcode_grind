/*
 * Other alternatives for faster solutions:
 * 1. Modify the grid to set "seen" nodes to 0. This way using std::set is redundant.
 * 2. Use unordered_set with custom hashing technique (becasue unordered_set cant accept std::pair as a hash. Instead of that for ex. set unordered_set<int> and store (row * col) + col).
 */
class Solution {
    std::set<std::pair<int, int>> seen = {};

public:
    void bfs(const int &r, const int &c, const size_t &rows, const size_t &cols, const vector<vector<char>>& grid)
    {
        std::queue<std::pair<int, int>> q = {};
        q.push(make_pair(r, c));

        std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        seen.insert(std::make_pair(r, c));

        while(!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for(const auto& [dr, dc] : dirs)
            {
                const int new_row = row + dr;
                const int new_col = col + dc;

                if(new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols || seen.contains(make_pair(new_row, new_col)) || grid[new_row][new_col] != '1')
                    continue;

                seen.insert(std::make_pair(new_row, new_col));
                q.push({new_row, new_col});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        size_t rows = grid.size();
        size_t cols = grid[0].size();
        int islands = 0;

        for(int row = 0 ; row < rows ; ++row)
        {
            for(int col = 0 ; col < cols ; ++col)
            {
                if(grid[row][col] == '1' && !seen.contains(std::make_pair(row, col)))
                {
                    bfs(row, col, rows, cols, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};

