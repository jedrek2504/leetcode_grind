class Solution:
    def validParantheses(self, s: str) -> bool:
        stck = []

        for ch in s:
            if ch == "(":
                stck.append(ch)
            elif ch == ")":
                if not stck:
                    return False
                stck.pop()

        return not stck


def main():
    sol = Solution()
    s = "lee(t)code(s))"

    print(sol.validParantheses(s))


if __name__ == "__main__":
    main()
