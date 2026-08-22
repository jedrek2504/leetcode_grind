class Solution {
public:
    string intToRoman(int num) {
        // Create a mapping (also for substraction forms)
        std::vector<std::pair<int, string>> val_to_rom = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
            {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string res; // res to store answer

        // Iterate over each val and ch in mapping
        for (auto& [val, ch] : val_to_rom) {
            // If can be divisible by val
            if (num / val) {
                int count = num / val; // How many times
                for (int i = 0; i < count; ++i) res += ch; // Extend list count amount of ch
                num %= val; // Take the remainder and let be next num
            }
        }

        return res; // Join the result
    }
};
