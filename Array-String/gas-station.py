class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost): return -1

        start = 0
        tank = 0
        # Iterate over each station
        for i in range(len(gas)):
            tank += gas[i] - cost[i] # Each iteration calculate diff needed and add to tank
            # If at any point a tank will be empty
            if tank < 0:
                start = i + 1 # Set new candidate to the next one
                tank = 0 # Reset the tank

        return start # Since its guaranteed to get the solution - if we get here then the candidate has been chosen
