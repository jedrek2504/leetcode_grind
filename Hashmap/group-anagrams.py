class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list) # defaultdict to avoid checking

        for word in strs:
            count = [0] * 26 # Letters in the alphabet

            # Increment the count of corresponding letter
            for ch in word:
                count[ord(ch) - ord("a")] += 1

            # Make count hashable by using touple and let it work as a key
            groups[tuple(count)].append(word)


        return list(groups.values()) # Leetcode expects a List[List] so cast to list
