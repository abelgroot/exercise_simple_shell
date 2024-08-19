#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_delimiter(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

char **split_string(char *str) {
    char **words = NULL;
    int i = 0, word_start = 0, word_end = 0, word_len = 0;
    int num_words = 0;

    // Loop through the string to count words and allocate memory
    while (str[word_end] != '\0') {
        // Skip delimiters
        while (is_delimiter(str[word_end])) {
            word_end++;
        }

        word_start = word_end;  // Start of a word

        // Find the end of the word
        while (str[word_end] != '\0' && !is_delimiter(str[word_end])) {
            word_end++;
        }

        word_len = word_end - word_start;  // Length of the word

        if (word_len > 0) {
            // Allocate memory for the words array
            char **temp = realloc(words, sizeof(char *) * (num_words + 2));
            if (!temp) {
                // Free allocated memory in case of failure
                for (i = 0; i < num_words; i++) {
                    free(words[i]);
                }
                free(words);
                return NULL;
            }
            words = temp;

            // Allocate memory for the current word and copy it
            words[num_words] = malloc(sizeof(char) * (word_len + 1));
            if (!words[num_words]) {
                for (i = 0; i < num_words; i++) {
                    free(words[i]);
                }
                free(words);
                return NULL;
            }
            strncpy(words[num_words], &str[word_start], word_len);
            words[num_words][word_len] = '\0';  // Null-terminate the word
            num_words++;
        }
    }

    // Null-terminate the array of words
    if (words) {
        words[num_words] = NULL;
    }

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
