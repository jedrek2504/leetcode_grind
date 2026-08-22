class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)   # Introduce dummy node to handle edge cases

        # Stage 1): Get to the left node:
        prevLeft, leftN = dummy, head   # prevLeft - one node before left node, leftN - left Node

        for i in range(left - 1):
            prevLeft, leftN = leftN, leftN.next

        # Stage 2): Reverse nodes in interval (See Reverse Linked List solution)
        rightN, nextRight = None, leftN

        for i in range(right - left + 1):
            tmp_next = nextRight.next
            nextRight.next = rightN

            rightN, nextRight = nextRight, tmp_next

        # Stage 3): Reattach missing links (pointers)
        leftN.next = nextRight # Left node points to next node AFTER right node
        prevLeft.next = rightN # Last node before left points to a right node

        return dummy.next
