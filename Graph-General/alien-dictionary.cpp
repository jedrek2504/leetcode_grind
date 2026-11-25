class Solution {
private:
    bool dfs(char node, unordered_map<char, unordered_set<char>>& preMap, unordered_set<char>& cycle,
             unordered_set<char>& done, string& order) {
        if (done.count(node)) {
            return true;
        }
        if (cycle.count(node)) {
            return false;
        }
        cycle.insert(node);

        // Visit everything that must come before this node first
        for (char pre : preMap[node]) {
            if (!dfs(pre, preMap, cycle, done, order)) {
                return false;
            }
        }

        cycle.erase(node);
        done.insert(node);
        order.push_back(node);
        return true;
    }

public:
    string alien(vector<string>& words) {
        unordered_map<char, unordered_set<char>> preMap; // letter : set of letters that must come before it

        // Make sure every letter is a key, even ones that appear in no edge
        for (const string& w : words) {
            for (char c : w) {
                preMap[c]; // accessing the key creates an empty set
            }
        }

        for (int i = 1; i < (int)words.size(); i++) {
            const string& word1 = words[i - 1];
            const string& word2 = words[i];

            // Longer word can't come before its own prefix, e.g. "abc" before "ab"
            if (word1.size() > word2.size() && word1.compare(0, word2.size(), word2) == 0) {
                return "";
            }

            for (int j = 0; j < (int)min(word1.size(), word2.size()); j++) {
                char ch1 = word1[j];
                char ch2 = word2[j];
                // First differing char tells us ch1 comes before ch2
                if (ch1 != ch2) {
                    preMap[ch2].insert(ch1);
                    break; // Only the first difference matters
                }
            }
        }

        unordered_set<char> cycle; // Nodes on the current DFS path, to detect cycles
        unordered_set<char> done;  // Nodes fully processed
        string order; // Final order; a node is appended only after everything that must precede it

        // Call dfs on every unique letter
        for (auto& [ch, pres] : preMap) {
            if (!dfs(ch, preMap, cycle, done, order)) {
                return "";
            }
        }

        return order;
    }
};
