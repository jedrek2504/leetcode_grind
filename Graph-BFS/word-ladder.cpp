class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<string> words(wordList.begin(), wordList.end()); // Set gives O(1) lookups (a list would be an O(N) scan)

        // If the endWord is not in the list we can never reach it
        if (!words.count(endWord)) {
            return 0;
        }

        std::queue<std::pair<string, int>> q; // (word, wordCount)
        q.push({beginWord, 1}); // We start with wordcount = 1 since beginWord is a word
        std::unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            string currWord = q.front().first;
            int wordCount = q.front().second;
            q.pop();

            // Instead of scanning the list, generate every word that is 1 letter away
            for (size_t i = 0; i < currWord.size(); ++i) { // Every position in the word
                for (char ch = 'a'; ch <= 'z'; ++ch) { // Every possible letter
                    string nextWord = currWord;
                    nextWord[i] = ch; // Swap the letter at position i

                    // If it is a real word and we have not yet visited it
                    if (words.count(nextWord) && !visited.count(nextWord)) {
                        // Firstly, if this is our endWord
                        if (nextWord == endWord) {
                            return wordCount + 1; // Return the number of words in the sequence
                        }

                        // Otherwise:
                        q.push({nextWord, wordCount + 1}); // Add next word to the queue
                        visited.insert(nextWord); // Mark word visited
                    }
                }
            }
        }

        // If we got here we cannot get to the end word
        return 0;
    }
};
