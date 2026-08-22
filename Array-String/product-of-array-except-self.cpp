class Solution {
public:
    // nums = [1,2,3,4]
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        // From the front to the back -> res = [1, 1, 2, 6]
        int prefix = 1;
        for (int i = 0; i < (int)nums.size(); ++i) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        // From the back to the front -> res = [24 * 1, 12 * 1 ,4 * 2 ,1 * 6]
        int postfix = 1;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};
