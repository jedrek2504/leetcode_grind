class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        std::queue<TreeNode*> q = {};
        q.push(root);
        vector<vector<int>> res = {};

        while(!q.empty())
        {
            size_t level_size = q.size();
            vector<int> temp = {};

            for(size_t i = 0; i < level_size; ++i)
            {
                TreeNode* popped = q.front();
                q.pop();
                temp.push_back(popped->val);

                if(popped->left)  q.push(popped->left);
                if(popped->right) q.push(popped->right);
            }

            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};
