class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        # To not return [""] if input is empty
        if not digits:
            return []

        # Dict to map buttons to the letters
        buttons = {
            2 : "abc",
            3 : "def",
            4 : "ghi",
            5 : "jkl",
            6 : "mno",
            7 : "pqrs",
            8 : "tuv",
            9 : "wxyz"
        }
        res = [] # Store the letter combinations as str's ["ad", "ae", ...]
        combination = [] # Stores combination of letters ["a", "e"]
        
        def backtrack(i: int) -> None:
            # If combination is of desired length
            if i == len(digits):
                res.append("".join(combination)) # Add a combination to res. 
                return # Return to caller

            # For each letter in current button
            for letter in buttons[int(digits[i])]:
                combination.append(letter) # Add the letter to decision tree
                backtrack(i + 1) # Call recursive function
                combination.pop() # Once we've visited the letter pop


        backtrack(0) # Call backtrack on first index
        return res        
        
