class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(set)  # Rows dict -> {row_number: set(values)}
        cols = defaultdict(set)  # Cols dict -> {col_number: set(values)}
        squares = defaultdict(
            set
        )  # # Rows dict -> {box_coor(r // 3, c // 3): set(values)}

        # Iterate over every element
        for r in range(9):
            for c in range(9):
                val = board[r][c]

                # If element no filled -> skip
                if board[r][c] == ".":
                    continue

                # If val has been seen then return False
                if val in rows[r] or val in cols[c] or val in squares[(r // 3, c // 3)]:
                    return False

                # Add value to corresponding sets.
                rows[r].add(val)
                cols[c].add(val)
                squares[(r // 3, c // 3)].add(
                    val
                )  # // operator to map element to one of 9 squares for ex: board[5][8] -> 5//3 = 1, 8//3 = 2 -> squares(1, 2)

        return True  # If we got here then valid
