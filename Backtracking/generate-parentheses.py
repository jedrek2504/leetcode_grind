class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        comb = []  # "current" combination
        res = []  # Stores valid parentheses combinations
        open_count = 0  # Counts "(" occurrences
        close_count = 0  # Counts ")" occurrences

        def backtrack(i: int) -> None:
            nonlocal open_count, close_count

            if i == n * 2:
                res.append("".join(comb))
                return

            # Each recursion we have two options:
            # 1. "("

            # If half of the parentheses we added are "(" -> No point in adding more
            if open_count < n:
                comb.append("(")
                open_count += 1

                backtrack(i + 1)

                comb.pop()
                open_count -= 1

            # 2. ")"

            # Add closing parenthesis only if we have more opening parentheses.
            if open_count > close_count:
                comb.append(")")
                close_count += 1

                backtrack(i + 1)

                comb.pop()
                close_count -= 1

        backtrack(0)
        return res
