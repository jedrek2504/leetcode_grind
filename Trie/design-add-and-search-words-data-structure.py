class LetterNode:
    def __init__(self): 
        self.children = dict() # {letter : LetterNode, ...}
        self.isEnd = False


class WordDictionary:
    def __init__(self):
        self.root = LetterNode()

    # Usual Trie addWord
    def addWord(self, word: str) -> None:
        curr = self.root # Set the curr pointer to Trie root initially

        # Iterate through each letter in word
        for ch in word:
            # If the child does not already exist
            if ch not in curr.children:
                curr.children[ch] = LetterNode() # Create it
            curr = curr.children[ch] # Set the current pointer to current letter
        
        curr.isEnd = True # Mark the last letter the end of a word

    # Search function with a twist - if we encounter a "." we need to call this function recursively on the next letter.
    def search(self, word: str) -> bool:
        def dfs(j: int, node: LetterNode) -> bool:
            cur = node # Set the current Node

            # Iterate through each letter of a word starting from j (Initially 0 but can also be called from whatever index we encountered a ".")
            for i in range(j, len(word)):
                ch = word[i]
                # If current letter is a ".":
                if ch == ".":
                    # We iterate through every child (LetterNode part)
                    for child in cur.children.values():
                        # We run dfs on each child
                        if dfs(i + 1, child):
                            return True # If at any point we find matching path - return True
                    # If we got here (we went through all children and didn't find a path):
                    return False # Return False
                else: # If it's a normal letter
                    if ch not in cur.children:
                        return False
                    # If we got here (there is a corresponding letter in children dict):
                    cur = cur.children[ch] # We set the current pointer to cur letter
            
            # If we got here - we've iterated through the word we're searching:
            return cur.isEnd # Check if the Node is marked as end of word.

        return dfs(0, self.root)
