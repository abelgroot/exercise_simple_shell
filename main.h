#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <sys/types.h>

int realloc_buffer(char **lineptr, size_t *n, size_t size, ssize_t nread);
ssize_t _getline(char **lineptr, size_t *n, int stream);
char **split_string(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /* MAIN_H */
