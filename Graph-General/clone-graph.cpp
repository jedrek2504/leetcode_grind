class Solution {
public:
    Node* dfs(Node* node, std::unordered_map<Node*, Node*>& old_to_new) {
        // If a node is already present in hashmap the return its copy
        if (old_to_new.count(node)) {
            return old_to_new[node];
        }

        Node* copy = new Node(node->val); // Create a copy of a node with it's original value passed in constructor
        old_to_new[node] = copy; // Assign a copy to the node

        // Handle neighbours
        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei, old_to_new));
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        // Handle edge cases
        if (!node) {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> old_to_new; // Maps old node to it's copy

        return dfs(node, old_to_new);
    }
};
