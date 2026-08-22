class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        ROWS, COLS = len(board), len(board[0]) # Extract rows and cols
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)] # all dirs including diagonals

        # Iterate over each element in matrix
        for r in range(ROWS):
            for c in range(COLS):
                live_neighbours = 0 # Each iteration calculate live_neighbours

                # Traverse all neighbours
                for dx, dy in directions:
                    # If neighbour is out of bounds - skip
                    if not 0 <= c + dx < COLS or not 0 <= r + dy < ROWS:
                        continue

                    # If value is alive(1) or was alive(2)
                    if board[r + dy][c + dx] in (1, 2):
                        live_neighbours += 1

                # Legend: 2 - switch from alive(1) to dead(0) ; 3 - switch from dead(0) to alive(1)
                # Live cell
                if board[r][c] == 1:
                    # Underpopulation
                    if live_neighbours < 2:
                        board[r][c] = 2
                    # Overpopulation
                    elif live_neighbours > 3:
                        board[r][c] = 2
                # Dead cell
                else:
                    if live_neighbours == 3:
                        board[r][c] = 3

        # Second pass - correct 2s and 3s to corresponding values
        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == 2:
                    board[r][c] = 0
                elif board[r][c] == 3:
                    board[r][c] = 1
