class Solution:
    def totalNQueens(self, n: int) -> int:
        solutions = 0
        """
        Funny thing here - we don't even need a board! It's dead weight, we don't ever read it and actually the sets() take care of the whole logic just fine
        """
        ## board = [[False] * n for _ in range(n)] # Initialize n x n board and fill with Fasle ; False - empty, True - queen

        # Sets for lookup if queen can be put or not
        cols = set()
        diag = set() # (r + c) values
        anti_diag = set() # (r - c) values

        def backtrack(row : int) -> None:
            nonlocal solutions
            # We need to go 1 row "over" the board to add a solution and return to previous caller bactrack(3)
            if row == n:
                solutions += 1
                return

            for col in range(n):
                # If other queen can reach us
                if col in cols or (row + col) in diag or (row - col) in anti_diag:
                    continue # We skip

                ## board[row][col] = True # Place a Queen

                # Add it to the lookup sets so future queen placements will be limited only to valid squares
                cols.add(col)
                diag.add(row + col)
                anti_diag.add(row - col)

                backtrack(row + 1) # Call backtrack

                ## board[row][col] = False # Remove a queen
                # Once the queen is removed reflect it in the set
                cols.remove(col)
                diag.remove(row + col)
                anti_diag.remove(row - col)

        backtrack(0)
        return solutions
