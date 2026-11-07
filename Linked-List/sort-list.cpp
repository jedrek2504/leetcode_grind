class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case - head doesnt exist or head.next doesn't exist (So that we stop at single nodes O -> None)
        if (!head || !head->next) {
            return head;
        }

        // Get the middle node
        ListNode* mid = getMid(head);
        ListNode* tmp = mid->next;
        mid->next = nullptr;

        // Call sortlist on left nad right halves
        ListNode* l = sortList(head);
        ListNode* r = sortList(tmp);

        return mergeLists(l, r); // Return a merged list
    }

private:
    ListNode* getMid(ListNode* head) {
        // Set slow at first Node and fast at second - so that
        ListNode* slow = head;
        ListNode* fast = head->next;
        // Iterate until we move out of bounds
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeLists(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        // Go through each list at once up until one of them reaches end
        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next; // Progress curr pointer
        }

        curr->next = left ? left : right; // Attach remainder of a list
        return dummy->next;
    }
};
