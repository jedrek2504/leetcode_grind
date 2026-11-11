class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        ROWS = len(board)
        COLS = len(board[0])
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]  # Directions

        def backtrack(r: int, c: int, i: int) -> bool:
            # If we got to the end of a word that means there is a solution
            if i == len(word):
                return True

            if (
                not (0 <= r < ROWS)  # Row out of bounds
                or not (0 <= c < COLS)  # Col out of bounds
                or board[r][c]
                != word[
                    i
                ]  # Current cell doesn't have a target letter (visited cells are marked "#", so they never match)
            ):
                return False

            letter = board[r][c]  # Remember the letter so we can restore it
            board[r][c] = "#"  # Mark as visited in current path
            res = any(
                backtrack(r + dr, c + dc, i + 1) for dr, dc in dirs
            )  # Backtrack each adjacent cell, if any of them returns True then result is True
            board[r][c] = letter  # Once done with backtracking, restore the letter

            return res  # Return the result

        # Iterate through each cell
        for r in range(ROWS):
            for c in range(COLS):
                # Run backtrack on each cell, if it returns True at any point
                if backtrack(r, c, 0):
                    return True  # The word is present
        return False  # No matching word
