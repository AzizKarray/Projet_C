#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include your LRUCache implementation header
#include "Code.h"

// Function to run a single test case
void runTest(char* operations[], int args[][2], int opCount, char* expected) {
    LRUCache* cache = NULL;
    printf("Running Test:\n");
    
    for (int i = 0; i < opCount; i++) {
        if (strcmp(operations[i], "LRUCache") == 0) {
            cache = lRUCacheCreate(args[i][0]);
            printf("null ");
        } else if (strcmp(operations[i], "put") == 0) {
            lRUCachePut(cache, args[i][0], args[i][1]);
            printf("null ");
        } else if (strcmp(operations[i], "get") == 0) {
            int result = lRUCacheGet(cache, args[i][0]);
            printf("%d ", result);
        }
    }

    printf("\nExpected Output: %s\n", expected);
    // Free the cache
    lRUCacheFree(cache);
}

// Main function to parse dataset and execute test cases
int main() {
    FILE* file = fopen("dataset.txt", "r");
    if (!file) {
        printf("Error: Unable to open dataset file.\n");
        return 1;
    }

    char operations[10][20];
    int args[10][2];
    char expected[200];

    while (fscanf(file, "%s %d %d %[^\n]", operations, &args[0][0], &args[0][1], expected) != EOF) {
        runTest(operations, args, 10, expected);
    }

    fclose(file);
    return 0;
}
