from collections import defaultdict


def alien(words: list[str]) -> str:
    preMap = defaultdict(set)  # letter : set of letters that must come before it

    # Make sure every letter is a key, even ones that appear in no edge
    for w in words:
        for c in w:
            preMap[c]  # accessing the key creates an empty set

    for i in range(1, len(words)):
        word1 = words[i - 1]
        word2 = words[i]

        # Longer word can't come before its own prefix, e.g. "abc" before "ab"
        if len(word1) > len(word2) and word1.startswith(word2):
            return ""

        for ch1, ch2 in zip(word1, word2):
            # First differing char tells us ch1 comes before ch2
            if ch1 != ch2:
                preMap[ch2].add(ch1)
                break  # Only the first difference matters

    cycle = set()  # Nodes on the current DFS path, to detect cycles
    done = set()  # Nodes fully processed
    order = (
        []
    )  # Final order; a node is appended only after everything that must precede it

    def dfs(node: str) -> bool:
        if node in done:
            return True
        if node in cycle:
            return False
        cycle.add(node)

        # Visit everything that must come before this node first
        for pre in preMap[node]:
            if not dfs(pre):
                return False

        cycle.remove(node)
        done.add(node)
        order.append(node)
        return True

    # Call dfs on every unique letter
    for ch in preMap.keys():
        if not dfs(ch):
            return ""

    return "".join(order)
