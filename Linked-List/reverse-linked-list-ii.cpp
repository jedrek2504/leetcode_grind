class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);   // Introduce dummy node to handle edge cases

        // Stage 1): Get to the left node:
        ListNode* prevLeft = dummy;
        ListNode* leftN = head;   // prevLeft - one node before left node, leftN - left Node

        for (int i = 0; i < left - 1; ++i) {
            prevLeft = leftN;
            leftN = leftN->next;
        }

        // Stage 2): Reverse nodes in interval (See Reverse Linked List solution)
        ListNode* rightN = nullptr;
        ListNode* nextRight = leftN;

        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* tmp_next = nextRight->next;
            nextRight->next = rightN;

            rightN = nextRight;
            nextRight = tmp_next;
        }

        // Stage 3): Reattach missing links (pointers)
        leftN->next = nextRight; // Left node points to next node AFTER right node
        prevLeft->next = rightN; // Last node before left points to a right node

        return dummy->next;
    }
};
