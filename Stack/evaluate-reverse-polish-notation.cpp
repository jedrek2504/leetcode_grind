class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        // Go through each token
        for (const string& token : tokens) {
            // If token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop from the stack twice and remember the values
                int second = stack.back();
                stack.pop_back();
                int first = stack.back();
                stack.pop_back();
                // Based on the op append the result to a stack
                if (token == "+") {
                    stack.push_back(first + second);
                } else if (token == "-") {
                    stack.push_back(first - second);
                } else if (token == "*") {
                    stack.push_back(first * second);
                } else {
                    stack.push_back(first / second); // C++ integer division already truncates toward zero, no cast needed
                }
            } else {
                // If a token is a number add it to the stack as an int
                stack.push_back(stoi(token));
            }
        }
        return stack[0];
    }
};
