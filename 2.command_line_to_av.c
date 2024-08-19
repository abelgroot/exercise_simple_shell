#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(char *str) {
    char **words = NULL;
    char *word;
    int i = 0;

    // Duplicate the string to avoid modifying the original string
    char *str_copy = strdup(str);
    if (!str_copy) {
        return NULL;
    }

    // First call to strtok
    word = strtok(str_copy, " ");
    while (word != NULL) {
        // Allocate memory for the words array
        char **temp = realloc(words, sizeof(char *) * (i + 2));
        if (!temp) {
            free(words);
            free(str_copy);
            return NULL;
        }
        words = temp;

        // Store the word in the array
        words[i] = strdup(word);
        if (!words[i]) {
            free(words);
            free(str_copy);
            return NULL;
        }
        i++;

        // Get the next word
        word = strtok(NULL, " ");
    }

    // Null-terminate the array
    words[i] = NULL;

    // Free the duplicate string copy
    free(str_copy);

    return words;
}

int main() {
    char str[] = "Hello, this is a test string.";
    char **words = split_string(str);

    if (words == NULL) {
        printf("Error splitting string\n");
        return 1;
    }

    // Print the split words
    for (int i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
        free(words[i]);  // Free each word after printing
    }

    // Free the words array
    free(words);

    return 0;
}
