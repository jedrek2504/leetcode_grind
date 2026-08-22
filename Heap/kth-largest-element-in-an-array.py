class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # Convert k-th largest to index in sorted array (ascending)
        k = len(nums) - k

        def quickSelect(l, r):
            pivot = nums[r]          # Choose last element as pivot
            p = l                    # Pointer for elements <= pivot

            # Partition the array
            for i in range(l, r):
                if nums[i] <= pivot:
                    nums[p], nums[i] = nums[i], nums[p]
                    p += 1

            # Place pivot in its correct position
            nums[p], nums[r] = nums[r], nums[p]

            # Recurse only into the part that contains k
            if p > k:
                return quickSelect(l, p - 1)
            elif p < k:
                return quickSelect(p + 1, r)
            else:
                return nums[p]       # Found k-th largest

        return quickSelect(0, len(nums) - 1)
