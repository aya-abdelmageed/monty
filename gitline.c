#include "monty.h"

/**
 * getline - Read a line from a file stream
 * @lineptr: Pointer to the buffer storing the line
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * This function reads a line from the specified file stream and stores it in the
 * buffer pointed to by @lineptr. The buffer size is provided through @n, and it
 * will be resized if necessary to accommodate the entire line. The newline
 * character ('\n') is included in the line, and a null-terminator ('\0') is
 * added at the end.
 *
 * Return: The number of characters read, including the newline character, but
 *         excluding the null-terminator. On error or end-of-file, -1 is returned.
 */

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
    

    
    ssize_t bufsize = (ssize_t)(*n);  
    ssize_t pos = 0;                  
    int c;                            

    
    if (*lineptr == NULL) {
        *lineptr = malloc((size_t)bufsize);
        if (*lineptr == NULL)
            return -1;  
    }

    while (1) {
        
        c = fgetc(stream);

        
        if (c == EOF) {
            
            
            if (pos == 0)
                return -1;  
            else
                break;  
        }

        
        if (pos >= bufsize - 1) {
            bufsize += (ssize_t)(*n);  
            *lineptr = realloc(*lineptr, (size_t)bufsize);
            if (*lineptr == NULL)
                return -1;  
        }

        
        (*lineptr)[pos++] = (char)c;

        
        if (c == '\n')
            break;  
    }

    
    (*lineptr)[pos] = '\0';

    return pos;
}
