# Linked List Node with key and val
class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.next, self.prev = None, None


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}  # {key : Node()}

        # left - LRU, right - MRU
        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = (
            self.right,
            self.left,
        )  # Initially those point at eachother

    # Removes a node from list
    def remove(self, node):
        prev, next = node.prev, node.next  # Access prev and next node
        prev.next, next.prev = (
            next,
            prev,
        )  # Update pointers of those nodes so that they point to each other (Excluding the one we "removed")

    # Inserts a node rightmost (since recently used)
    def insert(self, node):
        prev, next = self.right.prev, self.right  #
        prev.next = next.prev = node  # Update pointers to node
        node.next, node.prev = (
            next,
            prev,
        )  # Since doubly linked list then update those as well

    def get(self, key: int) -> int:
        if key in self.cache:
            # Update MRU since we are currently using it
            self.remove(self.cache[key])
            self.insert(self.cache[key])

            return self.cache[key].val

        return -1  # If key not found return -1

    def put(self, key: int, value: int) -> None:
        # If a node is already in the list
        if key in self.cache:
            self.remove(self.cache[key])  # Remove it

        # Create a new node and mark as MRU
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        # Check if capacity is exceeded
        if len(self.cache) > self.capacity:
            # Delete LRU from the list and cache
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
