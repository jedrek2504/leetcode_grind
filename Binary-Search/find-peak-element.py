class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        l = 0
        r = len(nums) - 1
        n = len(nums)

        while l <= r:
            m = (l + r) // 2  # Calculate middle element and ensure it doesn't overlow
            # If right element is higher and ensure right nei in bounds
            if m < (n - 1) and nums[m] < nums[m + 1]:
                l = m + 1  # Go there
            # If left element is higher and ensure left nei in bounds
            elif m > 0 and nums[m] < nums[m - 1]:
                r = m - 1  # Go there instead
            # If none are higher - curr element is larger then neis
            else:
                return m

        # Not possible but cover all paths:
        return 0
