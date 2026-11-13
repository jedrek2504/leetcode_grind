class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Edge case - if source and destination are the same - return True
        if (source == destination) {
            return true;
        }

        unordered_map<int, vector<int>> adj; // {node: [nei,1, nei2 ...], } - Adjecancy list
        unordered_set<int> visited; // Set to store visited nodes

        // Build an adjacancy list:
        for (const vector<int>& edge : edges) {
            int v1 = edge[0];
            int v2 = edge[1];
            // Graph is undirected so add both possibilities:
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        return dfs(source, destination, adj, visited); // Return dfs(source)
    }

private:
    // Iterative dfs
    bool dfs(int node, int destination, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
        vector<int> q; // Dfs
        q.push_back(node);

        while (!q.empty()) {
            int popped = q.back(); // Pop from the queue
            q.pop_back();
            // Go through each neighbour
            for (int nei : adj[popped]) {
                // If it already has been viisted
                if (visited.count(nei)) {
                    continue; // Skip
                }
                // If a nei is a destination
                if (nei == destination) {
                    return true; // We have reached waht we looked for in this dfs.
                }

                // Otherwise
                q.push_back(nei); // Add a nei to the queue
                visited.insert(nei); // Mark nei visited so we don't revisit it
            }
        }

        return false; // If we got here and did not return True then it's imposible to reach destination
    }
};
