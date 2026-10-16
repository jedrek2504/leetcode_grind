class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: list[str]) -> int:
        # Helper funtion to determine if we can mutate to the gene (Exactly one character is different between genes)
        def check_mutation(firstGene: str, secondGene: str) -> bool:
            counter = 0

            # Iterate through every ch in gene 1 and 2:
            for ch1, ch2 in zip(firstGene, secondGene):
                # If the genes dont match
                if ch1 != ch2:
                    counter += 1  # Increase the counter

            return counter == 1  # If exactly one gene is different we can mutate

        q = deque()  # {gene, steps}
        q.append((startGene, 0))  # Add the startGene to the queue
        visited = set()  # To avoid revisiting genes
        visited.add(startGene)  # Mark first gene visited

        while q:
            currGene, steps = q.popleft()  # Doesn't matter if bfs/dfs, but use bfs

            # Iterate through the genes in the bank
            for nextGene in bank:
                # If we can mutate to the gene and we have not yet visited it
                if check_mutation(currGene, nextGene) and nextGene not in visited:
                    # Firstly, if this is our endGene
                    if nextGene == endGene:
                        return steps + 1  # Return the steps it took to get there

                    # Otherwise:
                    q.append((nextGene, steps + 1))  # Add next gene to the queue
                    visited.add(nextGene)  # Mark gene visited

        # If we got here we cannot get to the end gene
        return -1
