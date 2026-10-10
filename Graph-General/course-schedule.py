from collections import defaultdict

class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        preMap = defaultdict(list) # Maps {crs: [pre1, pre2 ...]}
        visited = set() # Keeps track of visited courses to detect cycle

        # Create adjacency list
        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        def dfs(crs):
            # If course doesn't have any prerequisites LEFT (because might have been marked along the way) - it can be completed
            if not preMap[crs]:
                return True

            # If a course has been visited -> cycle detected and all courses cannot be completed
            if crs in visited:
                return False

            visited.add(crs) # Mark course visited

            # Traverse each prerequisite
            for pre in preMap[crs]:
                # Call dfs and see if all prerequisites can be completed - if not (returns False) then return False.
                if not dfs(pre):
                    return False
            # If we got here:
            preMap[crs] = [] # All prerequisites are fulfilled so we mark it as empty list
            return True

        # Important! We have to call dfs on every course because we don't have a clear root
        for crs in range(numCourses):
            # If any of them return False -> the courses cannot be completed
            if not dfs(crs):
                return False

        # If we got here then all courses could be completed
        return True
