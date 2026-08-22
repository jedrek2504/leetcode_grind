class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # Terminate early if None
        if not head:
            return None

        old_to_new = {} # Dict to store nodes

        curr = head

        # Go through whole list and map a node to a newly created node with the same value
        while curr:
            old_to_new[curr] = Node(curr.val)
            curr = curr.next

        curr = head # Reset curr pointer to point to the beginning

        # Once again go through evey node but this time update next and random pointers based on map values
        while curr:
            old_to_new[curr].next = old_to_new.get(curr.next)
            old_to_new[curr].random = old_to_new.get(curr.random)
            curr = curr.next

        return old_to_new[head] # Return new list
