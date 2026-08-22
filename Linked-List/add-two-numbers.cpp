class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();  // Dummy head node
        ListNode* curr = dummy;            // Reference to the same object as dummy
        int carry = 0;                     // Value to store addition carry for example 7+8=15 -> carry = 1

        // If l1, l2 or leftover carry exist:
        while (l1 || l2 || carry) {
            // If one list is shorter, we treat missing digits as 0
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;

            // New val
            int val = v1 + v2 + carry;

            // Compute digit and carry from val
            carry = val / 10;   // Calculate carry
            val %= 10;          // Calculate digit as remainder

            // Create new node
            curr->next = new ListNode(val);

            // Update pointers
            curr = curr->next;             // Move the curr pointer (dummy stays at the start)
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return dummy->next; // It will return values except dummy head
    }
};
