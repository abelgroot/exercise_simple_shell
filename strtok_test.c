#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world! This is strtok example.";
    char *token;

    // Get the first token
    token = strtok(str, " ,.!");

    // Walk through other tokens
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ,.!"); // Continue tokenizing the same string
    }

    return 0;
}
