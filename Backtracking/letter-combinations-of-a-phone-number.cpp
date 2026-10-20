class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // To not return [""] if input is empty
        if (digits.empty()) {
            return {};
        }

        // Dict to map buttons to the letters
        std::unordered_map<int, string> buttons = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        vector<string> res; // Store the letter combinations as str's ["ad", "ae", ...]
        string combination; // Stores combination of letters ["a", "e"]

        backtrack(0, digits, buttons, combination, res); // Call backtrack on first index
        return res;
    }

private:
    void backtrack(int i, const string& digits, std::unordered_map<int, string>& buttons, string& combination, vector<string>& res) {
        // If combination is of desired length
        if (i == (int)digits.size()) {
            res.push_back(combination); // Add a combination to res.
            return; // Return to caller
        }

        // For each letter in current button
        for (char letter : buttons[digits[i] - '0']) {
            combination.push_back(letter); // Add the letter to decision tree
            backtrack(i + 1, digits, buttons, combination, res); // Call recursive function
            combination.pop_back(); // Once we've visited the letter pop
        }
    }
};
