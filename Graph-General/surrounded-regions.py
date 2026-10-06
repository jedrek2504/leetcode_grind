from collections import deque


class Solution:
    def solve(self, board: list[list[str]]) -> None:
        ROWS = len(board)
        COLS = len(board[0])
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Directions

        def bfs(r: int, c: int) -> None:
            q = deque()  # Deque for bfs regular queue for dfs
            q.append((r, c))
            board[r][c] = "."  # Mark as NOT eligable for removal (mark as "X")

            while q:
                row, col = q.popleft()
                for dr, dc in dirs:
                    nr, nc = row + dr, col + dc

                    # Check if in bounds and of "O" type and not already marked "."
                    if (
                        not (0 <= nr < ROWS)
                        or not (0 <= nc < COLS)
                        or board[nr][nc] != "O"
                        or board[nr][nc] == "."
                    ):
                        continue  # Skip iteration

                    # If we got here - none of the above triggered continue
                    q.append((nr, nc))
                    board[nr][nc] = "."

        # First loop - go on the borders and perform bfs if "O" is present and mark "." those which are not eligable for removal
        for r in range(ROWS):
            for c in range(COLS):
                # Ensure its borders only - AND - de morgan
                if not (r == 0 or r == ROWS - 1) and not (c == 0 or c == COLS - 1):
                    continue

                # If we got here
                if board[r][c] == "O":
                    bfs(r, c)

        # Second pass - If still "O" - doesnt connect to border so replace, if "." - make it "O" as before
        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == "O":
                    board[r][c] = "X"
                elif board[r][c] == ".":
                    board[r][c] = "O"
