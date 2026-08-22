class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* curr = root;
        Node* dummy = new Node(0);
        Node* head = root;

        while (head) {
            curr = head; // initialize current level's head
            Node* prev = dummy; // init prev for next level linked list traversal
            // iterate through the linked-list of the current level and connect all the siblings in the next level
            while (curr) {
                if (curr->left) {
                    prev->next = curr->left;
                    prev = prev->next;
                }
                if (curr->right) {
                    prev->next = curr->right;
                    prev = prev->next;
                }
                curr = curr->next; // If the next node is None the inner loop is terminated
            }
            head = dummy->next; // update head to the linked list of next level
            dummy->next = nullptr; // reset dummy node
        }
        return root;
    }
};
