class Solution {
public:
    bool dfs(int crs, std::unordered_map<int, vector<int>>& preMap, std::unordered_set<int>& cycle, std::unordered_set<int>& done, vector<int>& order) {
        // If crs in done then dont append it to output
        if (done.count(crs)) {
            return true;
        }
        // If cycle detected then terminate
        if (cycle.count(crs)) {
            return false;
        }

        cycle.insert(crs); // Add to cycle

        // See if crs in pre call chain
        for (int pre : preMap[crs]) {
            if (!dfs(pre, preMap, cycle, done, order)) {
                return false;
            }
        }

        cycle.erase(crs); // If not in pre call chain then remove it from cycle

        // If we got here:
        preMap[crs].clear(); // Mark the prerequisites empty since already handled
        order.push_back(crs); // Append to order since we handled all pre
        done.insert(crs); // Mark node as done to avoid adding the same node twice to the order
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, vector<int>> preMap; // Maps {crs : [pre1, pre2], ...}
        std::unordered_set<int> cycle; // Hashset to detect cycle
        std::unordered_set<int> done; // Hashset to see if the course has already been done (to not add it to output)
        vector<int> order; // Order of courses

        // Populate adjecency list
        for (const vector<int>& p : prerequisites) {
            preMap[p[0]].push_back(p[1]);
        }

        // Run it for all nodes since we do not know the correct node
        for (int crs = 0; crs < numCourses; ++crs) {
            if (!dfs(crs, preMap, cycle, done, order)) {
                return {};
            }
        }

        return order;
    }
};
