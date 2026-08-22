class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // Return early if empty input
        vector<double> res;
        if (!root) return res;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            double total = 0; // Total of vals for current level
            int noOfNodes = q.size(); // Number of nodes on current level

            // Go through nodes on each level
            for (int i = 0; i < noOfNodes; ++i) {
                TreeNode* popped = q.front(); q.pop(); // Pop leftmost val form queue
                total += popped->val; // Add its val to a total

                // If node has children add it to queue
                if (popped->left) q.push(popped->left);
                if (popped->right) q.push(popped->right);
            }

            // To result append an avarage
            res.push_back(total / noOfNodes);
        }

        return res;
    }
};
