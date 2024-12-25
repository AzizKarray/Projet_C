#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include your LRUCache implementation header
#include "Code.h"

// Function to run a single test case
void runTest(char* operations[], int args[][2], int opCount, char* expected) {
    LRUCache* cache = NULL;
    char output[200] = ""; // To store the generated output
    char temp[20];

    for (int i = 0; i < opCount; i++) {
        if (strcmp(operations[i], "LRUCache") == 0) {
            cache = lRUCacheCreate(args[i][0]);
            strcat(output, "null ");
        } else if (strcmp(operations[i], "put") == 0) {
            lRUCachePut(cache, args[i][0], args[i][1]);
            strcat(output, "null ");
        } else if (strcmp(operations[i], "get") == 0) {
            int result = lRUCacheGet(cache, args[i][0]);
            sprintf(temp, "%d ", result);
            strcat(output, temp);
        }
    }

    // Trim trailing space and compare with expected
    output[strlen(output) - 1] = '\0';
    printf("Generated Output: %s\n", output);
    printf("Expected Output: %s\n", expected);

    if (strcmp(output, expected) == 0) {
        printf("Test Passed!\n");
    } else {
        printf("Test Failed!\n");
    }

    lRUCacheFree(cache);
}


// Main function to parse dataset and execute test cases
int main() {
    FILE* file = fopen("dataset.txt", "r");
    if (!file) {
        printf("Error: Unable to open dataset file.\n");
        return 1;
    }

    // Fixed-size arrays for this example. Can be made dynamic if needed.
    char operations[10][20]; // Operations for each test case
    int args[10][2];         // Arguments for the operations
    char expected[200];      // Expected output string
    int opCount;             // Number of operations in the test case

    while (fscanf(file, "%d", &opCount) != EOF) { // Read operation count first
        printf("Operation Count: %d\n", opCount); // Debugging

        // Initialize args array to avoid garbage values
        memset(args, 0, sizeof(args));

        for (int i = 0; i < opCount; i++) {
            // Parse operations and arguments
            if (fscanf(file, "%s %d %d", operations[i], &args[i][0], &args[i][1]) < 2) {
                printf("Error: Incorrect input format at operation %d.\n", i);
                fclose(file);
                return 1;
            }
            printf("Operation: %s, Args: %d, %d\n", operations[i], args[i][0], args[i][1]); // Debugging
        }

        // Read expected output, ensuring it's correctly captured
        if (fscanf(file, " %[^\n]", expected) != 1) {
            printf("Error: Failed to read expected output.\n");
            fclose(file);
            return 1;
        }
        printf("Expected Output: %s\n", expected); // Debugging

        // Prepare an array of pointers to operations
        char* opPointers[10];
        for (int i = 0; i < opCount; i++) {
            opPointers[i] = operations[i];
        }

        // Run the test case
        runTest(opPointers, args, opCount, expected);
    }

    fclose(file);
    return 0;
}

