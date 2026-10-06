class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        candies = [1] * n  # Initialize all values to 1

        # Go from left to right starting with 1 and check if the value is bigger then left neighbour
        for i in range(1, n):
            if ratings[i - 1] < ratings[i]:
                candies[i] = (
                    candies[i - 1] + 1
                )  # If so -> set the value to +1 than neighbour

        # Go from right to left starting with (n - 1) pos and check if the value is bigger then right neighbour
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(
                    candies[i], candies[i + 1] + 1
                )  # We want to avoid setting smaller value then what has already been set in the first loop so we take the max

        return sum(candies)  # Return the sum of candies
