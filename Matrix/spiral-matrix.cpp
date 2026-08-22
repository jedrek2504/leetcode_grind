class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int l = 0, r = matrix[0].size(); // Set r pointer to be out of bounds for cleaner code
        int t = 0, b = matrix.size();    // Set b pointer to be out of bounds for cleaner code

        while (l < r && t < b) {
            // Get every value in top row (right)
            for (int i = l; i < r; ++i) {
                res.push_back(matrix[t][i]);
            }

            t += 1; // Update corresponding pointer

            // Get every value in right col (down)
            for (int i = t; i < b; ++i) {
                res.push_back(matrix[i][r - 1]); // Append to res
            }

            r -= 1;

            // Check if while condition broken (code does not work without it)
            if (!(l < r && t < b)) {
                break;
            }

            // Get every value in bottom row (left)
            for (int i = r - 1; i >= l; --i) {
                res.push_back(matrix[b - 1][i]);
            }

            b -= 1;

            // Get every value in left col (up)
            for (int i = b - 1; i >= t; --i) {
                res.push_back(matrix[i][l]);
            }

            l += 1;
        }

        return res;
    }
};
