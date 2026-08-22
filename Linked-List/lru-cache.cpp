// Linked List Node with key and val
struct Node {
    int key, val;
    Node* next;
    Node* prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        // left - LRU, right - MRU
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left; // Initially those point at eachother
    }

    int get(int key) {
        if (cache.count(key)) {
            // Update MRU since we are currently using it
            remove(cache[key]);
            insert(cache[key]);

            return cache[key]->val;
        }

        return -1; // If key not found return -1
    }

    void put(int key, int value) {
        // If a node is already in the list
        if (cache.count(key)) {
            remove(cache[key]); // Remove it
        }

        // Create a new node and mark as MRU
        cache[key] = new Node(key, value);
        insert(cache[key]);

        // Check if capacity is exceeded
        if ((int)cache.size() > capacity) {
            // Delete LRU from the list and cache
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }

private:
    int capacity;
    std::unordered_map<int, Node*> cache; // {key : Node()}
    Node* left;
    Node* right;

    // Removes a node from list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next; // Access prev and next node
        prev->next = next;
        next->prev = prev; // Update pointers of those nodes so that they point to each other (Excluding the one we "removed")
    }

    // Inserts a node rightmost (since recently used)
    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;
        prev->next = node;
        next->prev = node;    // Update pointers to node
        node->next = next;
        node->prev = prev; // Since doubly linked list then update those as well
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
