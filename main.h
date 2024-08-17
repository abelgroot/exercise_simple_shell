#ifndef MAIN_H
#define MAIN_H


int realloc_buffer(char **lineptr, size_t *n, size_t size, ssize_t nread);
ssize_t _getline(char **lineptr, size_t *n, int stream);
#endif /* MAIN_H */
