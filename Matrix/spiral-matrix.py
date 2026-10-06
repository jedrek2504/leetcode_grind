class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        l, r = 0, len(matrix[0])  # Set r pointer to be out of bounds for cleaner code
        t, b = 0, len(matrix)  # Set b pointer to be out of bounds for cleaner code

        while l < r and t < b:
            # Get every value in top row (right)
            for i in range(l, r):
                res.append(matrix[t][i])

            t += 1  # Update corresponding pointer

            # Get every value in right col (down)
            for i in range(t, b):
                res.append(matrix[i][r - 1])  # Append to res

            r -= 1

            # Check if while condition broken (code does not work without it)
            if not (l < r and t < b):
                break

            # Get every value in bottom row (left)
            for i in range(r - 1, l - 1, -1):
                res.append(matrix[b - 1][i])

            b -= 1

            # Get every value in left col (up)
            for i in range(b - 1, t - 1, -1):
                res.append(matrix[i][l])

            l += 1

        return res
