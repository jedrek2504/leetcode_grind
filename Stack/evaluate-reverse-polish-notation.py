class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack = []
        # Go through each token
        for token in tokens:
            # If token is an operator
            if token in ("+", "-", "*", "/"):
                # Pop from the stack twice and remember the values
                second = stack.pop()
                first = stack.pop()
                # Based on the op append the result to a stack
                if token == "+":
                    stack.append(first + second)
                elif token == "-":
                    stack.append(first - second)
                elif token == "*":
                    stack.append(first * second)
                else:
                    stack.append(int(first / second))  # truncate toward zero, not floor
            else:
                # If a token is a number add it to the stack as an int
                stack.append(int(token))
        return stack[0]
