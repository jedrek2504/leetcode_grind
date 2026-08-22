class Solution:
    def intToRoman(self, num: int) -> str:
        # Create a mapping (also for substraction forms)
        val_to_rom = [(1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"), (90, "XC"), (50, "L"), (40, "XL"), (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")]
        res = [] # res to store answer

        # Iterate over each val and ch in mapping
        for val, ch in val_to_rom:
            # If can be divisible by val
            if num // val:
                count = num // val # How many times
                res.extend([ch] * count) # Extend list count amount of ch
                num %= val # Take the remainder and let be next num

        return "".join(res) # Join the result
