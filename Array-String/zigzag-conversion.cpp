class Solution {
public:
    string convert(string s, int numRows) {
        // Return early if special case
        if (numRows == 1 || numRows >= (int)s.size()) return s;

        int idx = 0, d = 1; // index to put value, direction (1 -> and -1 <-)
        vector<string> rows(numRows); // Same no of rows as numRows

        // Iterate over each char
        for (char c : s) {
            rows[idx] += c; // append the char to corresponding row

            // If we got the the first index then ->
            if (idx == 0) {
                d = 1;
            // if we got to the last index the <-
            } else if (idx == numRows - 1) {
                d = -1;
            }

            idx += d; // Increment/Decrement index by corresponding direction
        }

        // Concat strings
        string res;
        for (int i = 0; i < numRows; ++i) res += rows[i];
        return res;
    }
};
