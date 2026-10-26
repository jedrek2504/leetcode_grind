class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end()); // Sort candidates first in-place
        vector<vector<int>> res;
        vector<int> comb;

        backtrack(0, target, candidates, comb, res);
        return res;
    }

private:
    void backtrack(int start, int remaining, vector<int>& candidates, vector<int>& comb, vector<vector<int>>& res) {
        if (remaining == 0) {
            res.push_back(comb);
            return;
        }

        // Each level we start from previous call number and go through the candidates until end of candidates.
        for (int i = start; i < (int)candidates.size(); i++) {
            int num = candidates[i];
            // If at any point current number is bigger then remaining
            if (num > remaining) {
                break; //  There is no point of going further
            }
            comb.push_back(num);
            backtrack(i, remaining - num, candidates, comb, res); // reuse numbers, so index = i (allow for [2,2,2,2] with target = 8 even though comb.size() > candidates.size())
            comb.pop_back();
        }
    }
};
