class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<vector<int>, vector<string>> groups; // groups keyed by letter counts (acts like defaultdict)

        for (auto& word : strs) {
            vector<int> count(26, 0); // Letters in the alphabet

            // Increment the count of corresponding letter
            for (char ch : word) {
                count[ch - 'a'] += 1;
            }

            // Use the count vector directly as a hashable (comparable) key
            groups[count].push_back(word);
        }

        vector<vector<string>> res;
        for (auto& [key, group] : groups) res.push_back(group);
        return res; // Leetcode expects a List[List] so cast to list
    }
};
