#include <deque>
#include <vector>

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};

        std::deque<TreeNode*> q;
        q.push_back(root);

        std::vector<int> res;

        while(!q.empty())
        {
            int level_size = q.size(); // C++: size()

            for(int i = 0 ; i < level_size ; ++i)
            {
                TreeNode* node = q.front(); // must read first
                q.pop_front();              // then remove

                if(i == level_size - 1)
                    res.push_back(node->val);

                if(node->left)
                    q.push_back(node->left);

                if(node->right)
                    q.push_back(node->right);
            }
        }

        return res;
    }
};
