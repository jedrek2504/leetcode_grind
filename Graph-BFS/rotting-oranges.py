from collections import deque

class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        # Extract grid dimensions
        ROWS = len(grid)
        COLS = len(grid[0])

        q = deque() # [(r, c), ...] - Stores rotten orange coors
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)] # Directions to explore adjacent fields
        minutes = 0 
        fresh = 0 # Count of fresh oranges - if it drops to 0 we can return minutes
        
        # 1. Iterate through the grid and append rotten orange coors to the queue
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 2:
                    q.append((r, c))
                if grid[r][c] == 1:
                    fresh += 1

        # 2. Perform bfs
        while q and fresh > 0:
            minutes += 1 # For each level increment the minutes

            # Iterate through each rotten orange in the queue at the time
            for _ in range(len(q)):
                row, col = q.popleft()

                # Explore the adjacent fields (up, down, left, right)
                for dr, dc in dirs:
                    new_row, new_col = row + dr, col + dc # Coors of adjacent field
                    
                    # If field is not in bounds or the field is not a fresh orange
                    if not(0 <= new_row < ROWS) or not(0 <= new_col < COLS) or grid[new_row][new_col] != 1:
                        continue # Skip

                    # If we got here
                    grid[new_row][new_col] = 2 # Mark orange rotten
                    fresh -= 1 # Decrement the count of fresh oranges
                    q.append((new_row, new_col)) # Add it to the queue

        return minutes if fresh == 0 else -1 # If there are no more fresh oranges return the minutes else its impossible to get to all of them
