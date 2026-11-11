class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        candidates.sort()  # Sort candidates first in-place
        res = []
        comb = []

        def backtrack(start: int, remaining: int) -> None:
            if remaining == 0:
                res.append(comb.copy())
                return

            # Each level we start from previous call number and go through the candidates until end of candidates.
            for i in range(start, len(candidates)):
                num = candidates[i]
                # If at any point current number is bigger then remaining
                if num > remaining:
                    break  #  There is no point of going further
                comb.append(num)
                backtrack(
                    i, remaining - num
                )  # reuse numbers, so index = i (allow for [2,2,2,2] with target = 8 even though len(comb) > len(candidates))
                comb.pop()

        backtrack(0, target)
        return res
