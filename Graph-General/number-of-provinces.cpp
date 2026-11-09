class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n); // [0, 1, 2, 3, ... , n] - parents pointers
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        vector<int> rank(n, 1); // [1, 1, 1, ... , 1] - initial rank for each city (every city is it's own parent)
        int res = n; // Number of provinces - initially set to individual cities, each union will -1 it.

        // Extract edges from 2d matrix
        for (int r = 0; r < n; r++) {
            // Iterate over top half - no reason to search the bottom since dupliacted info
            for (int c = r + 1; c < n; c++) {
                // If a pair of cities (edge) is not connected to each other (excluding the same cities)
                if (r == c || isConnected[r][c] == 0) {
                    continue; // Skip
                }
                // Else union cities
                res -= unionSets(r, c, parent, rank); // Union returns 0 or 1, if 1 then it's succesful so overall number of not connected cities decreases.
            }
        }

        return res;
    }

private:
    // Find a node's parent
    int find(int node, vector<int>& parent) {
        int par = node;

        // While curr node is not it's parent
        while (par != parent[par]) {
            parent[par] = parent[parent[par]]; // Optimisation: set parent to grandparent if possible
            par = parent[par]; // Set the curr node to it's parent
        }

        return par; // Return parent (noide that search ends up)
    }

    // Union 2 provinces based on their size (rank)  ("union" is a C++ keyword, hence unionSets)
    int unionSets(int n1, int n2, vector<int>& parent, vector<int>& rank) {
        int p1 = find(n1, parent); // Find parents of n1 and n2
        int p2 = find(n2, parent);

        // If parents match
        if (p1 == p2) {
            return 0; // They're already in the same province
        }

        // Else union them

        // If first node rank is bigger
        if (rank[p1] > rank[p2]) {
            parent[p2] = parent[p1]; // Union second node to first one.
            rank[p1] += rank[p2]; // Update the rank
        } else {
            parent[p1] = parent[p2];
            rank[p2] += rank[p1];
        }

        return 1; // If we got here we performed an union
    }
};
