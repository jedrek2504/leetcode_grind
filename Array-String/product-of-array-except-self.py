class Solution:
    # nums = [1,2,3,4]
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1] * (len(nums))

        # From the front to the back -> res = [1, 1, 2, 6]
        prefix = 1
        for i in range(len(nums)):
            res[i] = prefix
            prefix *= nums[i]

        # From the back to the front -> res = [24 * 1, 12 * 1 ,4 * 2 ,1 * 6]
        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= postfix
            postfix *= nums[i]
        return res
