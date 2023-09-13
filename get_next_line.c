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
        n++;
    }
    res[n] = '\0';
    return (res);
}

char *get_line(char *str)
{
    char *res;
    int i;

    i = 0;
    res = malloc(BUFFER_SIZE + 1);
    while(str[i] != '\n')
    {
        res[i] = str[i];
        i++;
    }
    res[i] = '\0';
    return(res);
}

char *get_next_line(int fd)
{
    static char *my_buffer;
    static int flag;
    char *result;

    if (!(result = malloc(BUFFER_SIZE + 1)))
        return (NULL);
    if (!my_buffer)
    {
        if (!(my_buffer = malloc(BUFFER_SIZE + 1)))
            return (NULL);
        my_buffer = copy_file(fd);
    }
    result = get_line(my_buffer);
    my_buffer = ft_strnstr(my_buffer, "\n", BUFFER_SIZE + 1);
    my_buffer++;
    return (result);
}

int main()
{
    int fd = open("h.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
}

