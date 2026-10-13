from collections import defaultdict, deque

class Solution:
    def snakesAndLadders(self, board: list[list[int]]) -> int:
        n = len(board) # Get the board measurements
        valMap = defaultdict(tuple) # {sqr : (r, c)}

        # Define starting points
        r = n - 1
        c = 0
        d = 1   # Direction var of vals {-1(left), 1(right)}

        # Populate the valMap, go through each sqr 1-36
        for s in range(1, n*n + 1):
            valMap[s] = (r, c) # Update the valMap

            # Each n squares we hit a wall, if so:
            if s % n == 0:
                d = -d # Change direction
                r -= 1 # Go to next row
                # Notice that while hitting the wall we are not "progressing", column stays the same, look 6->7 transition
            else:
                c += d # Traverse the column in each row left(-1)/right(+1)


        visited = set() # Set to avoid visiting the same squares in decision tree
        q = deque() # (sqr, steps)
        q.append((1, 0)) # Initially add square "1" with 0 initial steps
        visited.add(1) # Add 1st square to visited

        while q:
            sqr, steps = q.popleft()
            # Next square is a result of a dice throw (1-6)
            for i in range(1, 7):
                nxtSqr = sqr + i # Get the next sqr just based on the dice
                r, c = valMap[nxtSqr] # Extract coordinates of nextSquar

                # If a val on those coordinates is a ladder/snake
                if board[r][c] != -1:
                    nxtSqr = board[r][c] # The next square is equal to whatever value is in there instead
                # If we already visited the square
                if nxtSqr in visited:
                    continue # Ignore it
                # If we can get to the end we return the steps
                if nxtSqr == n * n:
                    return steps + 1

                # If we got here
                q.append((nxtSqr, steps + 1)) # Add the square to the deque
                visited.add(nxtSqr) # Mark square as visited

        return -1 # If the board has no solution (Unlikely)
