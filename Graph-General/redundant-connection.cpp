class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // len(edges) == n (problem statement)

        vector<int> par(n + 1); // Stores parent of i-th node. Initially every node is each own parent ; n + 1 beacuse array is 1 indexed.
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
        vector<int> rank(n + 1, 1); // Stores how many nodes point to ith node

        // Main loop - go through each pair in edges
        for (const vector<int>& edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            // If the nodes are already pointing to the same parent then the edge is redundant
            if (unionSets(n1, n2, par, rank) == 0) {
                return {n1, n2}; // Return a redundant edge (From the problem description we can assume it's the first one that we find)
            }
        }

        return {}; // Never reached - the problem guarantees one redundant edge
    }

private:
    // Find node's parent
    int find(int n, vector<int>& par) {
        int p = n;

        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }

        return p;
    }

    // Union two nodes, return a if union was needed (1/0)  ("union" is a C++ keyword, hence unionSets)
    int unionSets(int n1, int n2, vector<int>& par, vector<int>& rank) {
        int p1 = find(n1, par);
        int p2 = find(n2, par);

        if (p1 == p2) {
            return 0;
        }
        if (rank[p1] < rank[p2]) {
            par[p1] = par[p2]; // Smaller tree gets asigned a bigger tree
            rank[p2] += rank[p1]; // Bigger tree's size increases by smaller tree's size
        } else {
            par[p2] = par[p1];
            rank[p1] += rank[p2];
        }

        return 1;
    }
};
