"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        # Handle edge cases
        if not node:
            return None

        old_to_new = {}  # Maps old node to it's copy

        def dfs(node):
            # If a node is already present in hashmap the return its copy
            if node in old_to_new.keys():
                return old_to_new[node]

            copy = Node(
                node.val
            )  # Create a copy of a node with it's original value passed in constructor
            old_to_new[node] = copy  # Assign a copy to the node

            # Handle neighbours
            for nei in node.neighbors:
                copy.neighbors.append(dfs(nei))

            return copy

        return dfs(node)
