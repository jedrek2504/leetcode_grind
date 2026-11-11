class Solution:
    def get_mid(self, head):
        # Set slow at first Node and fast at second - so that
        slow = head
        fast = head.next
        # Iterate until we move out of bounds
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

    def merge_lists(self, left, right):
        dummy = ListNode()
        curr = dummy

        # Go through each list at once up until one of them reaches end
        while left and right:
            if left.val < right.val:
                curr.next = left
                left = left.next
            else:
                curr.next = right
                right = right.next
            curr = curr.next  # Progress curr pointer

        curr.next = left or right  # Attach remainder of a list
        return dummy.next

    def sortList(self, head: ListNode | None) -> ListNode | None:
        # Base case - head doesnt exist or head.next doesn't exist (So that we stop at single nodes O -> None)
        if not head or not head.next:
            return head

        # Get the middle node
        mid = self.get_mid(head)
        tmp = mid.next
        mid.next = None

        # Call sortlist on left nad right halves
        l = self.sortList(head)
        r = self.sortList(tmp)

        return self.merge_lists(l, r)  # Return a merged list
