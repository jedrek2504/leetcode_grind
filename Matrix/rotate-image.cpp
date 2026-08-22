/*
90 = transpose + reverse row
180 = reverse row + reverse column
270 = transpose + reverse col
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();

        // Transpose matrix
        for (int y = 0; y < ROWS; ++y) {
            // y ensures that each value will be swapped only once, + 1 leaves diagonal untouched becuase no reason to swap ex. (1, 1)
            for (int x = y; x < COLS; ++x) {
                std::swap(matrix[y][x], matrix[x][y]);
            }
        }

        // Reverse rows in matrix
        for (auto& row : matrix) {
            std::reverse(row.begin(), row.end());
        }
    }
};
