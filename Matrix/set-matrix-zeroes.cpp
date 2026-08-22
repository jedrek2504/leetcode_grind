class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size(); // Extract ROWS and COLS
        bool rowZero = false; // Variable to tell if top row should be set to 0 (to avoid overlapping)

        // Iterate over every element
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0; // Set first element in c column to 0

                    // If not in the first row (first row is controlled by rowZero variable)
                    if (r > 0) {
                        matrix[r][0] = 0; // Set first element in r row to 0
                    } else {
                        rowZero = true;
                    }
                }
            }
        }

        // Zero out rows/cols excluding first row and first col
        for (int r = 1; r < ROWS; ++r) {
            for (int c = 1; c < COLS; ++c) {
                // If first element of row/col is 0 then set element to 0
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Handle first column
        if (matrix[0][0] == 0) {
            for (int r = 0; r < ROWS; ++r) matrix[r][0] = 0;
        }

        // Handle first row
        if (rowZero) {
            for (int c = 0; c < COLS; ++c) matrix[0][c] = 0;
        }
    }
};
