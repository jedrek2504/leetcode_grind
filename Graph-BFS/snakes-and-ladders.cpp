class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(); // Get the board measurements
        std::unordered_map<int, std::pair<int, int>> valMap; // {sqr : (r, c)}

        // Define starting points
        int r = n - 1;
        int c = 0;
        int d = 1; // Direction var of vals {-1(left), 1(right)}

        // Populate the valMap, go through each sqr 1-36
        for (int s = 1; s <= n * n; ++s) {
            valMap[s] = {r, c}; // Update the valMap

            // Each n squares we hit a wall, if so:
            if (s % n == 0) {
                d = -d; // Change direction
                r -= 1; // Go to next row
                // Notice that while hitting the wall we are not "progressing", column stays the same, look 6->7 transition
            } else {
                c += d; // Traverse the column in each row left(-1)/right(+1)
            }
        }

        std::unordered_set<int> visited; // Set to avoid visiting the same squares in decision tree
        std::queue<std::pair<int, int>> q; // (sqr, steps)
        q.push({1, 0}); // Initially add square "1" with 0 initial steps
        visited.insert(1); // Add 1st square to visited

        while (!q.empty()) {
            int sqr = q.front().first;
            int steps = q.front().second;
            q.pop();
            // Next square is a result of a dice throw (1-6)
            for (int i = 1; i <= 6; ++i) {
                int nxtSqr = sqr + i; // Get the next sqr just based on the dice
                r = valMap[nxtSqr].first; // Extract coordinates of nextSquar
                c = valMap[nxtSqr].second;

                // If a val on those coordinates is a ladder/snake
                if (board[r][c] != -1) {
                    nxtSqr = board[r][c]; // The next square is equal to whatever value is in there instead
                }
                // If we already visited the square
                if (visited.count(nxtSqr)) {
                    continue; // Ignore it
                }
                // If we can get to the end we return the steps
                if (nxtSqr == n * n) {
                    return steps + 1;
                }

                // If we got here
                q.push({nxtSqr, steps + 1}); // Add the square to the deque
                visited.insert(nxtSqr); // Mark square as visited
            }
        }

        return -1; // If the board has no solution (Unlikely)
    }
};
