class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None

        curr=root
        dummy=Node(0)
        head=root

        while head:
            curr=head # initialize current level's head
            prev=dummy # init prev for next level linked list traversal
            # iterate through the linked-list of the current level and connect all the siblings in the next level
            while curr:
                if curr.left:
                    prev.next=curr.left
                    prev=prev.next
                if curr.right:
                    prev.next=curr.right
                    prev=prev.next
                curr=curr.next # If the next node is None the inner loop is terminated
            head=dummy.next # update head to the linked list of next level
            dummy.next=None # reset dummy node
        return root
