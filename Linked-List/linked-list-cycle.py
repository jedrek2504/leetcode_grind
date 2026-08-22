class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head

        # If current fast and next fast is not None
        while fast and fast.next:
            slow = slow.next        # Slow moves by one
            fast = fast.next.next   # Fast goes by two
            # If at any point they meet
            if slow == fast:
                return True # A cycle is detected

        return False # If we got here it means that we got to None and it means that we found end of linked list
