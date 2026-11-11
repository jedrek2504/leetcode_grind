class Solution:
    def construct(self, grid: List[List[int]]) -> "Node":
        n = len(grid)  # Calculate n
        val = grid[0][0]  # Value is first element of a grid

        # If grid consists only of the same val then it's a leaf
        isLeaf = grid == [[val] * n for _ in range(n)]

        # Base case: uniform grid (this includes n == 1) -> leaf, no children
        if n <= 1 or isLeaf:
            return Node(val, True, None, None, None, None)

        m = n // 2  # Calculate middle index

        # Define root
        root = Node(
            val,
            isLeaf,
            # Call recursively construct on all directions:
            topLeft=self.construct([row[:m] for row in grid[:m]]),
            topRight=self.construct([row[m:] for row in grid[:m]]),
            bottomLeft=self.construct([row[:m] for row in grid[m:]]),
            bottomRight=self.construct([row[m:] for row in grid[m:]]),
        )

        return root  # Return the root we've made
