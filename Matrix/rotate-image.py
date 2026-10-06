"""
90 = transpose + reverse row
180 = reverse row + reverse column
270 = transpose + reverse col
"""


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        ROWS, COLS = len(matrix), len(matrix[0])

        # Transpose matrix
        for y in range(ROWS):
            # y ensures that each value will be swapped only once, + 1 leaves diagonal untouched becuase no reason to swap ex. (1, 1)
            for x in range(y, COLS):
                matrix[y][x], matrix[x][y] = matrix[x][y], matrix[y][x]

        # Reverse rows in matrix
        for row in matrix:
            row = row.reverse()
