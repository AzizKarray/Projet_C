#ifndef CODE_H
#define CODE_H

// Structure to represent a node in the doubly linked list
typedef struct Node {
    int key, value;
    struct Node* prev;
    struct Node* next;
} Node;

// Structure to represent the LRU Cache
typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node** hashTable;
} LRUCache;

// Function declarations

// Create a new node with given key and value
Node* createNode(int key, int value);

// Create and initialize the LRU cache with a specified capacity
LRUCache* lRUCacheCreate(int capacity);

// Move the specified node to the front of the cache (most recently used)
void moveToFront(LRUCache* cache, Node* node);

// Remove the least recently used (LRU) node from the cache
Node* removeTail(LRUCache* cache);

// Get the value associated with the specified key from the cache
int lRUCacheGet(LRUCache* cache, int key);

// Insert or update a key-value pair in the cache
void lRUCachePut(LRUCache* cache, int key, int value);

// Free the memory used by the cache and its nodes
void lRUCacheFree(LRUCache* cache);

#endif // CODE_H
