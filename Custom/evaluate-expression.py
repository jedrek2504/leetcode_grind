class Solution:
    # Gets string -> Returns [op, left, right]
    def extract(self, s: str) -> list[str]:
        op = s[:3]
        inner = s[4:-1]
        left = right = ""

        for i, ch in enumerate(inner):
            # We assume the left value cannot be an expression
            if ch == ",":
                left = inner[:i]
                right = inner[(i + 1) :]
                return [op, left, right]

    # Takes [op, l, r] and calulates res
    def calculate(self, op: str, l: int, r: int) -> int:
        if op == "add":
            return l + r
        if op == "sub":
            return l - r
        if op == "mul":
            return l * r
        if op == "pow":
            return pow(l, r)

        raise ValueError("No fitting op type")

    # add(5,mul(2,pow(5,2)))
    def evaluate(self, s: str) -> int:
        s = s.replace(" ", "")  # Get rid of whitespaces in-place

        if s.isdigit():
            return int(s)

        [op, l, r] = self.extract(s)  # ["add", "5", "mul(2,pow(5,2))"]

        left = self.evaluate(l)  # "5" -> 5
        right = self.evaluate(r)  # "mul(2, pow(5,2))" -> ?

        return self.calculate(op, left, right)


def main():
    s = Solution()
    print(s.evaluate("add(5,mul(2,pow(5,2)))"))


if __name__ == "__main__":
    main()
