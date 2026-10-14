class Solution {
public:
    // Helper funtion to determine if we can mutate to the gene (Exactly one character is different between genes)
    bool check_mutation(const string& firstGene, const string& secondGene) {
        int counter = 0;

        // Iterate through every ch in gene 1 and 2:
        for (size_t i = 0; i < firstGene.size() && i < secondGene.size(); ++i) {
            // If the genes dont match
            if (firstGene[i] != secondGene[i]) {
                counter += 1; // Increase the counter
            }
        }

        return counter == 1; // If exactly one gene is different we can mutate
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        std::queue<std::pair<string, int>> q; // {gene, steps}
        q.push({startGene, 0}); // Add the startGene to the queue
        std::unordered_set<string> visited; // To avoid revisiting genes
        visited.insert(startGene); // Mark first gene visited

        while (!q.empty()) {
            string currGene = q.front().first; // Doesn't matter if bfs/dfs, but use bfs
            int steps = q.front().second;
            q.pop();

            // Iterate through the genes in the bank
            for (const string& nextGene : bank) {
                // If we can mutate to the gene and we have not yet visited it
                if (check_mutation(currGene, nextGene) && !visited.count(nextGene)) {
                    // Firstly, if this is our endGene
                    if (nextGene == endGene) {
                        return steps + 1; // Return the steps it took to get there
                    }

                    // Otherwise:
                    q.push({nextGene, steps + 1}); // Add next gene to the queue
                    visited.insert(nextGene); // Mark gene visited
                }
            }
        }

        // If we got here we cannot get to the end gene
        return -1;
    }
};
