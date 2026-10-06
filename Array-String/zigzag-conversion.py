class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # Return early if special case
        if numRows == 1 or numRows >= len(s):
            return s

        idx, d = 0, 1  # index to put value, direction (1 -> and -1 <-)
        rows = [[] for _ in range(numRows)]  # Same no of rows as numRows

        # Iterate over each char
        for char in s:
            rows[idx].append(char)  # append the char to corresponding row

            # If we got the the first index then ->
            if idx == 0:
                d = 1
            # if we got to the last index the <-
            elif idx == numRows - 1:
                d = -1

            idx += d  # Increment/Decrement index by corresponding direction

        # Join each row into a string
        for i in range(numRows):
            rows[i] = "".join(rows[i])

        # Concat strings
        return "".join(rows)
