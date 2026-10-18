class LetterNode {
public:
    std::unordered_map<char, LetterNode*> children; // {letter : LetterNode, ...}
    bool isEnd;

    LetterNode() {
        isEnd = false;
    }

    ~LetterNode() {
        // Free the child Nodes, otherwise the Trie leaks memory
        for (auto& entry : children) {
            delete entry.second;
        }
    }
};


class WordDictionary {
public:
    LetterNode* root;

    WordDictionary() {
        root = new LetterNode();
    }

    ~WordDictionary() {
        delete root;
    }

    // Usual Trie addWord
    void addWord(string word) {
        LetterNode* curr = root; // Set the curr pointer to Trie root initially

        // Iterate through each letter in word
        for (char ch : word) {
            // If the child does not already exist
            if (!curr->children.count(ch)) {
                curr->children[ch] = new LetterNode(); // Create it
            }
            curr = curr->children[ch]; // Set the current pointer to current letter
        }

        curr->isEnd = true; // Mark the last letter the end of a word
    }

    // Search function with a twist - if we encounter a "." we need to call this function recursively on the next letter.
    bool search(string word) {
        return dfs(0, root, word);
    }

private:
    bool dfs(int j, LetterNode* node, const string& word) {
        LetterNode* cur = node; // Set the current Node

        // Iterate through each letter of a word starting from j (Initially 0 but can also be called from whatever index we encountered a ".")
        for (int i = j; i < (int)word.size(); i++) {
            char ch = word[i];
            // If current letter is a ".":
            if (ch == '.') {
                // We iterate through every child (LetterNode part)
                for (auto& entry : cur->children) {
                    // We run dfs on each child
                    if (dfs(i + 1, entry.second, word)) {
                        return true; // If at any point we find matching path - return True
                    }
                }
                // If we got here (we went through all children and didn't find a path):
                return false; // Return False
            } else { // If it's a normal letter
                if (!cur->children.count(ch)) {
                    return false;
                }
                // If we got here (there is a corresponding letter in children dict):
                cur = cur->children[ch]; // We set the current pointer to cur letter
            }
        }

        // If we got here - we've iterated through the word we're searching:
        return cur->isEnd; // Check if the Node is marked as end of word.
    }
};
