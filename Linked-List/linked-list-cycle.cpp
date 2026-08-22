class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // If current fast and next fast is not None
        while (fast && fast->next) {
            slow = slow->next;         // Slow moves by one
            fast = fast->next->next;   // Fast goes by two
            // If at any point they meet
            if (slow == fast) {
                return true; // A cycle is detected
            }
        }

        return false; // If we got here it means that we got to None and it means that we found end of linked list
    }
};
