#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include your LRUCache implementation header (which contains declarations)
#include "Code.h"

// Function to run a single test case
void runTest(char* operations[], int args[][2], int opCount, char* expected) {
    LRUCache* cache = NULL;
    char actual[200] = ""; // Buffer to store the actual output
    int actualIndex = 0;   // Index for writing to the actual output buffer

    printf("Running Test:\n");

    for (int i = 0; i < opCount; i++) {
        if (strcmp(operations[i], "LRUCache") == 0) {
            cache = lRUCacheCreate(args[i][0]);
            // Add "null " to the actual output since LRUCache creates and returns no value
            actualIndex += sprintf(actual + actualIndex, "null ");
        } else if (strcmp(operations[i], "put") == 0) {
            lRUCachePut(cache, args[i][0], args[i][1]);
            // Add "null " to the actual output since put returns no value
            actualIndex += sprintf(actual + actualIndex, "null ");
        } else if (strcmp(operations[i], "get") == 0) {
            int result = lRUCacheGet(cache, args[i][0]);
            // Add the result to the actual output
            actualIndex += sprintf(actual + actualIndex, "%d ", result);
        }
    }

    printf("Actual Output: %s\n", actual);
    printf("Expected Output: %s\n", expected);

    // Compare actual and expected output
    if (strcmp(actual, expected) == 0) {
        printf("Test Passed!\n");
    } else {
        printf("Test Failed!\n");
    }

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

    char operations[10][20]; // Fixed-size array for operations
    int args[10][2];         // Arguments for the operations
    char expected[200];      // Expected output string
    int opCount;             // Number of operations in the test case

    while (fscanf(file, "%d", &opCount) != EOF) { // Read operation count first
        printf("Operation Count: %d\n", opCount); // Debugging

        for (int i = 0; i < opCount; i++) {
            if (fscanf(file, "%s %d %d", operations[i], &args[i][0], &args[i][1]) != 3) {
                printf("Error: Failed to read operation and arguments at index %d.\n", i);
                return 1;
            }
            printf("Operation: %s, Args: %d, %d\n", operations[i], args[i][0], args[i][1]); // Debugging
        }

        if (fscanf(file, " %[^\n]", expected) != 1) {
            printf("Error: Failed to read expected output.\n");
            return 1;
        }
        printf("Expected Output: %s\n", expected); // Debugging

        char* opPointers[10]; // Array of pointers to pass to runTest
        for (int i = 0; i < opCount; i++) {
            opPointers[i] = operations[i];
        }

        runTest(opPointers, args, opCount, expected);
    }

    fclose(file);
    return 0;
}
