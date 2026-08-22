class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Terminate early if None
        if (!head) return nullptr;

        std::unordered_map<Node*, Node*> old_to_new; // Dict to store nodes

        Node* curr = head;

        // Go through whole list and map a node to a newly created node with the same value
        while (curr) {
            old_to_new[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head; // Reset curr pointer to point to the beginning

        // Once again go through evey node but this time update next and random pointers based on map values
        while (curr) {
            old_to_new[curr]->next = curr->next ? old_to_new[curr->next] : nullptr;
            old_to_new[curr]->random = curr->random ? old_to_new[curr->random] : nullptr;
            curr = curr->next;
        }

        return old_to_new[head]; // Return new list
    }
};
