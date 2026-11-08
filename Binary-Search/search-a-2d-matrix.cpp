class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Top bottom pointers to decide which row the target is in
        int top = 0;
        int bot = (int)matrix.size() - 1;
        int row = -1; // Row which has the target - initialize to -1 to terminate program early when no row is found.

        // Binary search on a 2d matrix to decide which row the target is in
        while (top <= bot) {
            int mid = top + (bot - top) / 2; // Calculate middle row
            // If middle row contains the target
            if (matrix[mid][0] <= target && target <= matrix[mid].back()) {
                row = mid; // Assign row value
                break;     // Break from this loop
            }
            if (matrix[mid][0] > target) {
                bot = mid - 1;
            }
            if (matrix[mid].back() < target) {
                top = mid + 1;
            }
        }

        // If we haven't updated row then there is none that our target fits in - terminate program and return false
        if (row == -1) {
            return false;
        }

        // Binary search on a chosen row to see if the target exist
        int l = 0;
        int r = (int)matrix[0].size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2; // Calculate mid value in each row
            int val = matrix[row][m]; // Row is fixed
            if (val == target) {
                return true;
            }
            if (val < target) {
                l = m + 1;
            } else if (val > target) {
                r = m - 1;
            }
        }

        return false; // If we got here the value is not present
    }
};
