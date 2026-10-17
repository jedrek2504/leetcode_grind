class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode) # {ch : TrieNode, ...} -> Defaultdict to avoid check to see if a ch is present ; if it isn't it creates it automatically.
        self.endWord = False # Determines if this Node is the end of a word.

class Trie:
    def __init__(self):
        self.root = TrieNode() # Root of the Trie -> The starting point of a search
        

    def insert(self, word: str) -> None:
        curr = self.root # Set curr to root

        # Go through each letter in a given word
        for ch in word:
            curr = curr.children[ch] # Update the pointers to traverse the Trie

        curr.endWord = True # Mark the last TrieNode as endWord

    def search(self, word: str) -> bool:
        curr = self.root

        for ch in word:
            # If a ch is not in current Nodes children:
            if ch not in curr.children: 
                return False # The word is definatelly not presnt in the Trie
            curr = curr.children[ch]
        
        # If we got here
        return curr.endWord # We need to check if the last Node really is the endWord ; for ex. app will not return True if apple is in the trie because it is letter 'e' that's marked endWord and not 'p'.
        
    # Same deal as search but we don't need to check if it's the end of a word.
    def startsWith(self, prefix: str) -> bool:
        curr = self.root

        for ch in prefix:
            if ch not in curr.children:
                return False
            curr = curr.children[ch]
        
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
