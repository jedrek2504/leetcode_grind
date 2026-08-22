class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode() # Handle edge cases
        curr = dummy       # Curr pointer where to insert new val

        # Continue while both lists exist
        while list1 and list2:
            # Compare node vals
            if list1.val < list2.val:
                curr.next = list1   # We dont create a new node but assign existing one
                list1 = list1.next  # Update correspoding pointer
            else:
                curr.next = list2
                list2 = list2.next

            curr = curr.next    # Update curr pointer

        curr.next = list1 if list1 else list2   # Since loop goes until both lists have elements so we add the remainder after loop

        return dummy.next # To avoid using dummy head node
