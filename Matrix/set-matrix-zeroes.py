class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        ROWS, COLS = len(matrix), len(matrix[0])  # Extract ROWS and COLS
        rowZero = False  # Variable to tell if top row should be set to 0 (to avoid overlapping)

        # Iterate over every element
        for r in range(ROWS):
            for c in range(COLS):
                if matrix[r][c] == 0:
                    matrix[0][c] = 0  # Set first element in c column to 0

                    # If not in the first row (first row is controlled by rowZero variable)
                    if r > 0:
                        matrix[r][0] = 0  # Set first element in r row to 0
                    else:
                        rowZero = True

        # Zero out rows/cols excluding first row and first col
        for r in range(1, ROWS):
            for c in range(1, COLS):
                # If first element of row/col is 0 then set element to 0
                if matrix[0][c] == 0 or matrix[r][0] == 0:
                    matrix[r][c] = 0

        # Handle first column
        if matrix[0][0] == 0:
            for r in range(ROWS):
                matrix[r][0] = 0

        # Handle first row
        if rowZero:
            for c in range(COLS):
                matrix[0][c] = 0
