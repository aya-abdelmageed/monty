#include "monty.h"
size_t _getline(char **lineptr, size_t *n, FILE *stream) {
  char *buffer;
  size_t len;
  int c;

  if (lineptr == NULL || n == NULL) {
    errno = EINVAL;
    return -1;
  }

  buffer = *lineptr;
  len = *n;

  c = getc(stream);
  while (c != EOF && c != '\n') {
    if (len <= 1) {
      buffer = realloc(buffer, len + 1);
      if (buffer == NULL) {
        return -1;
      }
      len++;
    }
    buffer[len - 1] = c;
    c = getc(stream);
  }

  if (c == '\n') {
    buffer[len - 1] = '\0';
    len++;
  } else {
    buffer[len - 1] = '\0';
  }

  *lineptr = buffer;
  *n = len;

  return len;
}
