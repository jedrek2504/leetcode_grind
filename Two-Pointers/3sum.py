class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()  # Sort the array to introduce two pointers
        ans = []

        # Because two pointers must fit to the right of the a
        for a in range(len(nums) - 2):
            # Do not use the same a value as before
            if a > 0 and nums[a] == nums[a - 1]:
                continue

            l, r = a + 1, len(nums) - 1  # Initiate l, r pointers

            while l < r:
                triplets = [nums[a], nums[l], nums[r]]  # Declare triplets
                s = sum(triplets)  # s - sum of triplets

                # If sum is greater then 0 it means that we need to decrease the value -> shift right pointer
                if s > 0:
                    r -= 1
                elif s < 0:
                    l += 1
                # If sum == 0 we have one of the results
                else:
                    ans.append(triplets)

                    # We only need to shift one of the pointers the other one will be shifted by the code above
                    l += 1
                    # Shift it until value is different to avoid duplicates
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1

        return ans
