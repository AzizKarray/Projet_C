#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node** hashTable;
} LRUCache;

Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = node->next = NULL;
    return node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = createNode(0, 0);
    cache->tail = createNode(0, 0);
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;
    cache->hashTable = (Node**)calloc(10001, sizeof(Node*));
    return cache;
}

void moveToFront(LRUCache* cache, Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = cache->head->next;
    node->prev = cache->head;
    cache->head->next->prev = node;
    cache->head->next = node;
}

Node* removeTail(LRUCache* cache) {
    Node* lru = cache->tail->prev;
    lru->prev->next = cache->tail;
    cache->tail->prev = lru->prev;
    return lru;
}

int lRUCacheGet(LRUCache* cache, int key) {
    Node* node = cache->hashTable[key];
    if (node == NULL) {
        return -1;
    }
    moveToFront(cache, node);
    return node->value;
}

void lRUCachePut(LRUCache* cache, int key, int value) {
    Node* node = cache->hashTable[key];
    if (node) {
        node->value = value;
        moveToFront(cache, node);
    } else {
        Node* newNode = createNode(key, value);
        cache->hashTable[key] = newNode;
        newNode->next = cache->head->next;
        newNode->prev = cache->head;
        cache->head->next->prev = newNode;
        cache->head->next = newNode;
        cache->size++;

        if (cache->size > cache->capacity) {
            Node* lru = removeTail(cache);
            cache->hashTable[lru->key] = NULL;
            free(lru);
            cache->size--;
        }
    }
}

void lRUCacheFree(LRUCache* cache) {
    Node* curr = cache->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(cache->hashTable);
    free(cache);
}

int main() {
    LRUCache* cache = lRUCacheCreate(2);
    printf("null\n");  // For the LRUCache initialization step
    
    lRUCachePut(cache, 1, 1);  // put(1, 1)
    printf("null\n");  // For the put method
    
    lRUCachePut(cache, 2, 2);  // put(2, 2)
    printf("null\n");  // For the put method
    
    printf("%d\n", lRUCacheGet(cache, 1));  // get(1)
    
    lRUCachePut(cache, 3, 3);  // put(3, 3)
    printf("null\n");  // For the put method
    
    printf("%d\n", lRUCacheGet(cache, 2));  // get(2)
    
    lRUCachePut(cache, 4, 4);  // put(4, 4)
    printf("null\n");  // For the put method
    
    printf("%d\n", lRUCacheGet(cache, 1));  // get(1)
    printf("%d\n", lRUCacheGet(cache, 3));  // get(3)
    printf("%d\n", lRUCacheGet(cache, 4));  // get(4)
    
    lRUCacheFree(cache);  // Free the cache
    return 0;
}