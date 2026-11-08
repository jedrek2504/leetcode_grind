class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        # Top bottom pointers to decide which row the target is in
        top = 0
        bot = len(matrix) - 1
        row = (
            -1
        )  # Row which has the target - initialize to -1 to terminate program early when no row is found.

        # Binary search on a 2d matrix to decide which row the target is in
        while top <= bot:
            mid = (top + bot) // 2  # Calculate middle row
            # If middle row contains the target
            if matrix[mid][0] <= target and target <= matrix[mid][-1]:
                row = mid  # Assign row value
                break  # Break from this loop
            if matrix[mid][0] > target:
                bot = mid - 1
            if matrix[mid][-1] < target:
                top = mid + 1

        # If we haven't updated row then there is none that our target fits in - terminate program and return False
        if row == -1:
            return False

        # Binary search on a chosen row to see if the target exist
        l = 0
        r = len(matrix[0]) - 1
        while l <= r:
            m = (l + r) // 2  # Calculate mid value in each row
            val = matrix[row][m]  # Row is fixed
            if val == target:
                return True
            if val < target:
                l = m + 1
            elif val > target:
                r = m - 1

        return False  # If we got here the value is not present
