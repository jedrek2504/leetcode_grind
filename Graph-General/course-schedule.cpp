class Solution {
public:
    bool dfs(int crs, std::unordered_map<int, vector<int>>& preMap, std::unordered_set<int>& visited) {
        // If course doesn't have any prerequisites LEFT (because might have been marked along the way) - it can be completed
        if (preMap[crs].empty()) {
            return true;
        }

        // If a course has been visited -> cycle detected and all courses cannot be completed
        if (visited.count(crs)) {
            return false;
        }

        visited.insert(crs); // Mark course visited

        // Traverse each prerequisite
        for (int pre : preMap[crs]) {
            // Call dfs and see if all prerequisites can be completed - if not (returns false) then return false.
            if (!dfs(pre, preMap, visited)) {
                return false;
            }
        }
        // If we got here:
        preMap[crs].clear(); // All prerequisites are fulfilled so we mark it as empty list
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, vector<int>> preMap; // Maps {crs: [pre1, pre2 ...]}
        std::unordered_set<int> visited; // Keeps track of visited courses to detect cycle

        // Create adjacency list
        for (const vector<int>& p : prerequisites) {
            preMap[p[0]].push_back(p[1]);
        }

        // Important! We have to call dfs on every course because we don't have a clear root
        for (int crs = 0; crs < numCourses; ++crs) {
            // If any of them return false -> the courses cannot be completed
            if (!dfs(crs, preMap, visited)) {
                return false;
            }
        }

        // If we got here then all courses could be completed
        return true;
    }
};
