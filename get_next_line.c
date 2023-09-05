#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *my_buffer;
    char *result;
    int n;

    n = 0;
    my_buffer = NULL;
    if (!(result = malloc(BUFFER_SIZE + 1)))
        return (NULL);
    while(read(fd, &result[n], 1) > 0)
    {
        if (result[n] == '\n')
        {
            result[++n] = '\0';
            my_buffer = &result[n + 1];
            return (result);
        }
        n++;
    }
    if (n == 0)
    {
        free (result);
        return (NULL);
    }
    result[n] == '\0';
    return (result);
}

int main()
{
    int fd = open("h.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
