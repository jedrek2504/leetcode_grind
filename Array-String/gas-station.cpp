class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (std::accumulate(gas.begin(), gas.end(), 0) < std::accumulate(cost.begin(), cost.end(), 0)) return -1;

        int start = 0;
        int tank = 0;
        // Iterate over each station
        for (int i = 0; i < (int)gas.size(); ++i) {
            tank += gas[i] - cost[i]; // Each iteration calculate diff needed and add to tank
            // If at any point a tank will be empty
            if (tank < 0) {
                start = i + 1; // Set new candidate to the next one
                tank = 0; // Reset the tank
            }
        }

        return start; // Since its guaranteed to get the solution - if we get here then the candidate has been chosen
    }
};
