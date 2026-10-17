class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children; // {ch : TrieNode, ...}
    bool endWord; // Determines if this Node is the end of a word.

    TrieNode() {
        endWord = false;
    }

    ~TrieNode() {
        // Free the child Nodes, otherwise the Trie leaks memory
        for (auto& entry : children) {
            delete entry.second;
        }
    }
};

class Trie {
public:
    TrieNode* root; // Root of the Trie -> The starting point of a search

    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word) {
        TrieNode* curr = root; // Set curr to root

        // Go through each letter in a given word
        for (char ch : word) {
            // operator[] on a map would only give us a nullptr (not a defaultdict), so create the Node ourselves
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch]; // Update the pointers to traverse the Trie
        }

        curr->endWord = true; // Mark the last TrieNode as endWord
    }

    bool search(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            // If a ch is not in current Nodes children:
            if (!curr->children.count(ch)) {
                return false; // The word is definatelly not presnt in the Trie
            }
            curr = curr->children[ch];
        }

        // If we got here
        return curr->endWord; // We need to check if the last Node really is the endWord ; for ex. app will not return True if apple is in the trie because it is letter 'e' that's marked endWord and not 'p'.
    }

    // Same deal as search but we don't need to check if it's the end of a word.
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            if (!curr->children.count(ch)) {
                return false;
            }
            curr = curr->children[ch];
        }

        return true;
    }
};
