#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *my_buffer;
    char *result;

    if (!(result = malloc(BUFFER_SIZE + 1)))
        return (NULL);

    return (result);
}

int main()
{
    int fd = open("h.txt", O_RDONLY);
    char *str;

    str = malloc(BUFFER_SIZE + 1);
    read(fd, str, BUFFER_SIZE);
    printf("%s", str);
}

