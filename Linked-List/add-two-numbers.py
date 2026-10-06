class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()  # Dummy head node
        curr = dummy  # Reference to the same object as dummy
        carry = 0  # Value to store addition carry for example 7+8=15 -> carry = 1

        # If l1, l2 or leftover carry exist:
        while l1 or l2 or carry:
            # If one list is shorter, we treat missing digits as 0
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            # New val
            val = v1 + v2 + carry

            # Compute digit and carry from val
            carry = val // 10  # Calculate carry
            val %= 10  # Calculate digit as remainder

            # Create new node
            curr.next = ListNode(val)

            # Update pointers
            curr = curr.next  # Move the curr pointer (dummy stays at the start)
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return dummy.next  # It will return values except dummy head
