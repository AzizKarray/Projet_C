Visualizing the solution for capacity = 2:

========================================================================================================================================
Image : IMG1.png

-First, we're gonna be using a doubly linked list to store our (key, value) pairs in Nodes.
-We want to have a solution with O(1) complexity that is what we thought of using a hashmap to "put" and "get" those pairs.
-Each element in the hashmap will have a key of a node, and the value of that element will be a pointer to the node having the same key, this allows us to have O(1) complexity. 
-Since we have "most recent" and "least recent" elements, we'll have to reorder the nodes each time we put or get a pair, that's why we used a doubly linked list a not a single linked list.
========================================================================================================================================
Images : IMG2.png AND IMG3.png
-We want to put a new pair (3,3), however the capacity of the lru cahce is 2, which means we will need to remove the least recently used element, and add the new pair as the most recently used element.


