from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: list[str]) -> int:
        words = set(wordList) # Set gives O(1) lookups (a list would be an O(N) scan)

        # If the endWord is not in the list we can never reach it
        if endWord not in words:
            return 0

        q = deque() # (word, wordCount)
        q.append((beginWord, 1)) # We start with wordcount = 1 since beginWord is a word
        visited = set()
        visited.add(beginWord)

        while q:
            currWord, wordCount = q.popleft()

            # Instead of scanning the list, generate every word that is 1 letter away
            for i in range(len(currWord)): # Every position in the word
                for ch in "abcdefghijklmnopqrstuvwxyz": # Every possible letter
                    nextWord = currWord[:i] + ch + currWord[i + 1:] # Swap the letter at position i

                    # If it is a real word and we have not yet visited it
                    if nextWord in words and nextWord not in visited:
                        # Firstly, if this is our endWord
                        if nextWord == endWord:
                            return wordCount + 1 # Return the number of words in the sequence

                        # Otherwise:
                        q.append((nextWord, wordCount + 1)) # Add next word to the queue
                        visited.add(nextWord) # Mark word visited

        # If we got here we cannot get to the end word
        return 0
