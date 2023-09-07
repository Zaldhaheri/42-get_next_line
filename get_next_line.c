#include "get_next_line.h"

char *copy_file(int fd)
{
    char *str;
    char *res;
    int n;

    n = 0;
    res = malloc(BUFFER_SIZE + 1);
    str = malloc(BUFFER_SIZE + 1);
    while(read(fd, &str[n], 1) > 0)
    {
        res[n] = str[n];
        printf("%c\n", str[n++]);
    }
    res[n] = '\0';
    return (res);
}

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
    str = copy_file(fd);
    printf("%s\n", str);
}

