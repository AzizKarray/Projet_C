LRU Cache Implementation
**Functional Explanation
This project implements an LRU (Least Recently Used) Cache, a data structure that provides efficient retrieval and updates for key-value pairs. The cache stores a fixed number of key-value pairs, and once it reaches its capacity, the least recently used item is evicted to make room for new entries. This ensures that the cache always contains the most recently accessed data, and evicts older, less frequently accessed items.

Features:
Put Operation: Adds a key-value pair to the cache. If the key already exists, it updates its value.
Get Operation: Retrieves the value for a given key from the cache. If the key is not found, it returns -1.
Eviction Policy: When the cache exceeds its capacity, it evicts the least recently used item (the one furthest from the head of the doubly linked list).


-------------------------------------------------------------------------------------------------------------

Description of the Solution


Approach:
The LRU cache is implemented using a combination of a doubly linked list and a hash table:

Doubly Linked List: The list keeps track of the order of access. The most recently used items are at the front, and the least recently used items are at the end.
Hash Table: The hash table provides fast O(1) lookups by mapping keys to their corresponding nodes in the doubly linked list.


Solution Components:
Node Structure: Represents each entry in the cache, holding a key-value pair and pointers to the previous and next nodes in the list.
LRUCache Structure: Maintains the head and tail of the doubly linked list and supports the get and put operations. It also includes a hash table for quick key lookups.


Time and Space Complexity Analysis:
Time Complexity:
Get Operation: O(1) – Direct access to the node in the hash table and moving it to the front of the list (constant time operations).
Put Operation: O(1) – Inserting or updating a node in the list and hash table, and possibly evicting an old node if the cache exceeds capacity (constant time operations).

Space Complexity:
O(capacity) – The space is used by the hash table and the doubly linked list. The number of nodes in the list is limited by the cache's capacity, and each node takes up constant space.


-------------------------------------------------------------------------------------------------------------


Justification for Optimality:
The combination of the doubly linked list and hash table allows both get and put operations to be done in O(1) time, which is the most efficient possible for an LRU cache.
This solution is optimal in terms of both time and space because we ensure that:
All operations are performed in constant time.
We maintain an efficient memory usage by storing only up to capacity entries at any time.


-------------------------------------------------------------------------------------------------------------

Instructions for Cloning and Running the Code

Prerequisites:

Ensure that you have a C compiler (e.g., GCC) installed on your local machine. You can verify this by running:

gcc --version

Steps to Clone and Run:
1.Clone the Repository: To clone the repository to your local machine, use the following command:

git clone https://github.com/AzizKarray/Projet_C

2.Navigate to the Project Directory:

cd lru-cache


3.Compile the Code: Use the following command to compile the code:

gcc -o lru_cache solution.c

**This will compile the solution.c file and produce an executable called lru_cache.


4.Run the Code: To run the code, execute the following command:

./lru_cache
This will execute the program with the sample input embedded in the main function.

5.Testing with Custom Input: If you want to test the cache with your own set of operations, modify the main function inside solution.c. You can add custom calls to lRUCachePut() and lRUCacheGet() to simulate different caching scenarios.

6.Clean Up: After running the program, you can clean up by deleting the compiled output:

rm lru_cache