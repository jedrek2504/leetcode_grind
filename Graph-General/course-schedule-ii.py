class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        preMap = defaultdict(list) # Maps {crs : [pre1, pre2], ...}
        cycle = set() # Hashset to detect cycle
        done = set() # Hashset to see if the course has already been done (to not add it to output)
        order = [] # Order of courses

        # Populate adjecency list
        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        def dfs(crs: int) -> bool:
            # If crs in done then dont append it to output
            if crs in done:
                return True
            # If cycle detected then terminate
            if crs in cycle:
                return False

            cycle.add(crs) # Add to cycle

            # See if crs in pre call chain
            for pre in preMap[crs]:
                if not dfs(pre):
                    return False

            cycle.remove(crs) # If not in pre call chain then remove it from cycle

            # If we got here:
            preMap[crs] = [] # Mark the prerequisites empty since already handled
            order.append(crs) # Append to order since we handled all pre
            done.add(crs) # Mark node as done to avoid adding the same node twice to the order
            return True

        # Run it for all nodes since we do not know the correct node
        for crs in range(numCourses):
            if not dfs(crs):
                return []

        return order
