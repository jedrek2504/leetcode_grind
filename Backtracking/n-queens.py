class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        board = [["."] * n for _ in range(n)]  # Initialize the board
        cols = set()
        anti_diag = set()  # (r + c)
        diag = set()  # (r - c)
        res = []  # Stores valid boards

        def backtrack(row: int) -> None:
            if row == n:
                res.append(
                    ["".join(r) for r in board]
                )  # Merge each row into string and make a board from it
                return

            for col in range(n):
                if col in cols or (row - col) in diag or (row + col) in anti_diag:
                    continue

                # Place a queen
                board[row][col] = "Q"
                cols.add(col)
                diag.add(row - col)
                anti_diag.add(row + col)

                backtrack(row + 1)  # Backtrack

                # Remove a queen
                board[row][col] = "."
                cols.remove(col)
                diag.remove(row - col)
                anti_diag.remove(row + col)

        backtrack(0)
        return res
